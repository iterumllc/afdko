
#include "FeatVisitor.h"
#include "otl.h"
#include "GPOS.h"
#include "GSUB.h"

FeatVisitor::~FeatVisitor() {
    free(pathname);
    free(dirname);
    // The tree pointer is managed by the parser
    delete parser;
    delete tokens;
    delete lexer;
    delete input;
}

bool FeatVisitor::ParseAndRegister(bool toplevel) {
    std::ifstream stream;
    FeatParser::IncludeContext *ic = nullptr;
    if ( toplevel ) {
        stream.open(pathname, std::ios_base::in);
        if ( ! stream.is_open() ) {
            hotMsg(fc->g, hotFATAL, "Specified feature file not found: %s \n", pathname);
            return false;
        }
    } else
        return false;

    input = new antlr4::ANTLRInputStream(stream);
    lexer = new FeatLexer(input);
    tokens = new antlr4::CommonTokenStream(lexer);
    parser = new FeatParser(tokens);
    if ( ep == Top ) {
        tree = parser->featureFile();
    }
    if (tree != nullptr) {
        fc->visitors.emplace(ic, this);
        return true;
    }
    return false;
}

bool FeatVisitor::Translate() {
    tree->accept(this);
    return true;
}

Tag FeatVisitor::checkTag(TagCtx *start, TagCtx *end) {
    assert ( start != nullptr && end != nullptr );
    std::string st_str = start->getText();
    std::string et_str = end->getText();
    Tag stag = fc->str2tag(st_str), etag = fc->str2tag(et_str);

    if ( stag != etag )
        hotMsg(fc->g, hotWARNING, "Start tag %s does not match end tag %s.", st_str.c_str(), et_str.c_str());

    return stag;
}

GID FeatVisitor::getGlyph(FeatParser::GlyphContext *ctx, bool allowNotDef) {
    if ( ctx->CID() != nullptr )
        return fc->cid2gid(ctx->CID()->getText());
    else {
        assert( ctx->glyphName() != nullptr );
        return fc->mapGName2GID(ctx->glyphName()->getText(), allowNotDef);
    }
}

void FeatVisitor::addGcLiteralToCurrentGC(FeatParser::GcLiteralContext *ctx) {
    for (auto &gcle : ctx->gcLiteralElement() ) {
        if ( gcle->GCLASS() != nullptr ) {
            fc->addGlyphClassToCurrentGC(gcle->GCLASS()->getText());
        } else {
            assert ( gcle->startg != nullptr );
            /* The tokenizing stage doesn't separate a hyphen from a glyph
             * name if there are no spaces. So startg could be something like
             * "a-r". If it is then "a-r - z" is an error, so if endg is 
             * defined we just assume startg is a normal glyphname and let
             * the calls handle any errors.
             *
             * XXX The grammar doesn't currently parse "a- z" as a range. 
             */
            if ( gcle->endg != nullptr ) {
                GID sgid = getGlyph(gcle->startg, false);
                GID egid = getGlyph(gcle->endg, false);
                fc->addRangeToCurrentGC(sgid, egid, gcle->startg->getText(),
                                        gcle->endg->getText());
            } else {
                auto g = gcle->startg;
                GID gid = getGlyph(g, true);
                if ( gid == GID_UNDEF ) { // Could be a range
                    // Can't be a CID because that pattern doesn't have a hyphen
                    assert( g->CID() == nullptr && g->glyphName() != nullptr );
                    auto gn = g->glyphName()->getText();
                    auto hpos = gn.find('-');
                    if ( hpos == std::string::npos ) {
                        ; // XXX hotMsg(g, hotFATAL, "incomplete glyph range or glyph not in font");
                        return;
                    }
                    auto sgname = gn.substr(0, hpos-1);
                    auto egname = gn.substr(hpos, std::string::npos);
                    gid = fc->mapGName2GID(sgname, false);
                    GID egid = fc->mapGName2GID(egname, false);
                    // XXX Letting this call handle undefined glyphs
                    fc->addRangeToCurrentGC(gid, egid, sgname, egname);
                } else
                    fc->addGlyphToCurrentGC(gid);
            }
        }
    }
}

void FeatVisitor::translateGlyphClassAsCurrentGC(FeatParser::GlyphClassContext *ctx,
                                                 const std::string *gcname, bool dontcopy) {
    if ( ctx->GCLASS() != nullptr && dontcopy ) {
        fc->openAsCurrentGC(ctx->GCLASS()->getText());
        return;
    }

    if ( gcname != nullptr )
        fc->defineCurrentGC(*gcname);
    else
        fc->resetCurrentGC();

    if ( ctx->gcLiteral() != nullptr ) {
        addGcLiteralToCurrentGC(ctx->gcLiteral());
    } else {
        assert( ctx->GCLASS() != nullptr );
        fc->addGlyphClassToCurrentGC(ctx->GCLASS()->getText());
    }
    if ( fc->curGCHead != nullptr )
        fc->curGCHead->flags |= FEAT_GCLASS;
}

GNode *FeatVisitor::translateGlyphClass(FeatParser::GlyphClassContext *ctx) {
    translateGlyphClassAsCurrentGC(ctx, nullptr, false);
    return fc->finishCurrentGC();
}

GNode *FeatVisitor::translatePattern(FeatParser::PatternContext *ctx, bool markedOK) {
    GNode *ret, **insert = &ret;

    for (auto &pe : ctx->patternElement()) {
        if ( pe->glyph() != nullptr ) {
            *insert = fc->setNewNode(getGlyph(pe->glyph(), false));
        } else {
            assert( pe->glyphClass() != nullptr );
            *insert = translateGlyphClass(pe->glyphClass());
        }
        if ( pe->MARKER() != nullptr ) {
            if ( markedOK )
                (*insert)->flags |= FEAT_MARKED;
            else
                ; // XXX error cannot mark a replacement glyph pattern
        }
        insert = &(*insert)->nextSeq;
    }
    return ret;
}

antlrcpp::Any FeatVisitor::visitSubstitute(FeatParser::SubstituteContext *ctx) {
    std::cout << "Substitute ";
    GNode *targ, *repl = nullptr;
    if ( ctx->REV() != nullptr ) {
        assert( ctx->SUB() == nullptr );
        assert( ctx->startpat != nullptr );
        assert( (ctx->KNULL() != nullptr) != (ctx->endpat != nullptr) );

        targ = translatePattern(ctx->startpat, true);
        if ( ctx->endpat != nullptr )
            repl = translatePattern(ctx->endpat, false);
        fc->addSub(targ, repl, GSUBReverse);
    } else {
        assert( ctx->SUB() != nullptr );
        assert( ctx->startpat != nullptr );
        assert( (ctx->BY() != nullptr) != (ctx->FROM() != nullptr) );
        assert( (ctx->KNULL() != nullptr) != (ctx->endpat != nullptr) );

        int type = ctx->FROM() != nullptr ? GSUBAlternate : 0;
        targ = translatePattern(ctx->startpat, true);
        if ( ctx->endpat != nullptr )
            repl = translatePattern(ctx->endpat, false);
        fc->addSub(targ, repl, type);
    }
    return nullptr;
}

antlrcpp::Any FeatVisitor::visitInclude(FeatParser::IncludeContext *ctx) {
    std::cout << " Include ";
    return visitChildren(ctx);
}

antlrcpp::Any FeatVisitor::visitFeatureBlock(FeatParser::FeatureBlockContext *ctx) {
    assert ( ctx->starttag != nullptr && ctx->endtag != nullptr );
    fc->startFeature(checkTag(ctx->starttag, ctx->endtag));

    std::cout << "FeatureBlock ";

    for (const auto &i : ctx->statement())
        visitStatement(i);

    fc->endFeature();
    return nullptr;
}
