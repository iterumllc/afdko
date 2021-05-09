
#include "FeatVisitor.h"
#include "otl.h"
#include "GPOS.h"
#include "GSUB.h"

extern "C" char *curdir();
extern "C" char *sep();

static const char* findDirName(const char *path)
{
    size_t i = strlen(path);
    const char* end = nullptr;
    while (i > 0)
    {
        end = strchr("/\\:", path[--i]);
        if (end != nullptr)
            break;
    }
    if (end != nullptr)
        end = &path[i];
    return end;
}

static void assignDirName(const std::string &of, std::string &to) {
    const char *p = findDirName(of.c_str());
    if ( p == nullptr ) {
        to.assign(curdir());
    } else {
        to.assign(of, 0, (size_t)(p-of.c_str()));
    }
}

FeatVisitor::~FeatVisitor() {
    for (auto i : includes)
        delete i;

    // The tree pointer itself is managed by the parser
    delete parser;
    delete tokens;
    delete lexer;
    delete input;
}

void FeatVisitor::Parse(bool do_includes) {
    std::ifstream stream;
    if ( parent == nullptr ) {
        stream.open(pathname);
        if ( ! stream.is_open() ) {
            fc->featMsg(hotFATAL, "Specified feature file '%s' not found", pathname.c_str());
            return;
        }
        assignDirName(pathname, dirname);
    } else {
        bool found = false;
        std::string &rootdir = fc->root_visitor->dirname;
        // Try relative to (potential) UFO fontinfo.plist file
        stream.open(rootdir + sep() + "fontinfo.plist");
        if ( stream.is_open() ) {
            stream.close();
            dirname = rootdir + sep() + "..";
            stream.open(dirname + sep() + pathname);
            found = stream.is_open();
        }
        // Try relative to top-level file
        if ( !found ) {
            dirname = rootdir;
            stream.open(dirname + sep() + pathname);
            found = stream.is_open();
        }
        // Try relative to including file
        if ( !found && rootdir != parent->dirname ) {
            dirname = parent->dirname;
            stream.open(dirname + sep() + pathname);
            found = stream.is_open();
        }
        // Try just the pathname
        if ( !found ) {
            stream.open(pathname);
            if ( stream.is_open() ) {
                assignDirName(pathname, dirname);
                found = true;
            }
        }
        if ( !found ) {
            fc->featMsg(hotERROR, "Included feature file '%s' not found", pathname.c_str());
            return;
        }
    }

    input = new antlr4::ANTLRInputStream(stream);
    lexer = new FeatLexer(input);
    tokens = new antlr4::CommonTokenStream(lexer);
    parser = new FeatParser(tokens);
    parser->removeErrorListeners();
    FeatErrorListener el{*this};
    parser->addErrorListener(&el);

    fc->current_visitor = this;

    if ( top_ep == epFeatureFile ) {
        tree = parser->featureFile();
    } else if ( top_ep == epFeatureStatement ) {
        tree = parser->statementFile();
    }
    parser->removeErrorListeners();

    if ( tree == nullptr || !do_includes ) {
        fc->current_visitor = nullptr;
        return;
    }

    stage = vInclude;
    include_ep = top_ep;
    tree->accept(this);

    fc->current_visitor = nullptr;
    return;
}

void FeatVisitor::Translate() {
    fc->current_visitor = this;
    stage = vExtract; // This will still parse includes if not already done
    include_ep = top_ep;
    tree->accept(this);
    fc->current_visitor = nullptr;
}

const char *FeatVisitor::currentTokStr() {
    if ( current_msg_token == nullptr )
        return nullptr;

    return current_msg_token->getText().c_str();
}

void FeatVisitor::newFileMsg(char **msg) {
    assert( msg != nullptr );
    if ( need_file_msg ) {
        *msg = (char *) MEM_NEW(fc->g, pathname.size()+30);
        sprintf(*msg, "In feature file '%s':", pathname.c_str());
        need_file_msg = false;
    } else
        *msg = nullptr;
}

void FeatVisitor::tokenPositionMsg(char **msg) {
    assert( msg != nullptr );
    if ( current_msg_token != nullptr ) {
        *msg = (char *) MEM_NEW(fc->g, 50);
        sprintf(*msg, "[line %5ld char %3ld] ", current_msg_token->getLine(),
                current_msg_token->getCharPositionInLine()+1);
    } else
        *msg = nullptr;
}

void FeatVisitor::FeatErrorListener::syntaxError(antlr4::Recognizer *,
                                                 antlr4::Token *t,
                                                 size_t, size_t,
                                                 const std::string &msg,
                                                 std::exception_ptr) {
    v.TOK(t);
    // Whatever messages the parser can produce are printed as a group
    // before processing ends if there are any errors, so here we just
    // mark them all as ERR instead of FATAL
    hotMsg(v.fc->g, hotERROR, msg.c_str());
}

Tag FeatVisitor::checkTag(FeatParser::TagContext *start,
                          FeatParser::TagContext *end) {
    Tag stag = TAG_UNDEF, etag = TAG_UNDEF;
    if ( start != NULL )
        stag = fc->str2tag(TOK(start)->getText());
    if ( end != NULL )
        etag = fc->str2tag(TOK(end)->getText());

    if ( stag != etag )
        fc->featMsg(hotERROR, "End tag %c%c%c%c does not match start tag %c%c%c%c.",
                    TAG_ARG(etag), TAG_ARG(stag));

    return stag;
}

antlrcpp::Any FeatVisitor::visitInclude(FeatParser::IncludeContext *ctx) {
    assert( ctx->IFILE() != nullptr );
    FeatVisitor *inc;
    if ( includes.size() == current_include ) {
        inc = new FeatVisitor(fc, TOK(ctx->IFILE())->getText().c_str(), this, ctx,
                              include_ep);
        inc->Parse(true);
        includes.emplace_back(inc);
        fc->current_visitor = this;
    } else {
        assert( includes.size() > current_include );
        inc = includes[current_include];
    }

    if ( stage == vExtract ) {
        inc->Translate();
        fc->current_visitor = this;
    }

    current_include++;
    return nullptr;
}

antlrcpp::Any FeatVisitor::visitLangsysAssign(FeatParser::LangsysAssignContext *ctx) {
    // std::cout << " LangsysAssign ";
    if ( stage != vExtract )
        return nullptr;

    Tag stag = fc->str2tag(TOK(ctx->script)->getText());
    Tag ltag = fc->str2tag(ctx->lang->getText());
    fc->addLangSys(stag, ltag, true, ctx->lang);
    return nullptr;
}

antlrcpp::Any FeatVisitor::visitFeatureBlock(FeatParser::FeatureBlockContext *ctx) {
    // std::cout << "FeatureBlock ";
    include_ep = epFeatureStatement;
    if ( stage == vExtract ) {
        Tag t = checkTag(ctx->starttag, ctx->endtag);
        TOK(ctx);
        fc->startFeature(t);
    }

    for (const auto &i : ctx->statement())
        visitStatement(i);

    if ( stage == vExtract ) {
        TOK(ctx->endtag);
        fc->endFeature();
    }
    include_ep = epFeatureFile;
    return nullptr;
}

antlrcpp::Any FeatVisitor::visitFeatureUse(FeatParser::FeatureUseContext *ctx) {
    // std::cout << " FeatureUse ";
    if ( stage != vExtract )
        return nullptr;

    fc->aaltAddFeatureTag(fc->str2tag(TOK(ctx->tag())->getText()));
    return nullptr;
}

antlrcpp::Any FeatVisitor::visitSubstitute(FeatParser::SubstituteContext *ctx) {
    // std::cout << "Substitute ";
    if ( stage != vExtract )
        return nullptr;

    GNode *targ, *repl = nullptr;
    if ( ctx->revtok() != nullptr ) {
        assert( ctx->subtok() == nullptr );
        assert( ctx->startpat != nullptr );
        assert( (ctx->KNULL() != nullptr) != (ctx->endpat != nullptr) );

        targ = translatePattern(ctx->startpat, true);
        if ( ctx->endpat != nullptr )
            repl = translatePattern(ctx->endpat, false);
        TOK(ctx);
        fc->addSub(targ, repl, GSUBReverse);
    } else {
        assert( ctx->subtok() != nullptr );
        assert( ctx->startpat != nullptr );
        assert( (ctx->BY() != nullptr) != (ctx->FROM() != nullptr) );
        assert( (ctx->KNULL() != nullptr) != (ctx->endpat != nullptr) );

        int type = ctx->FROM() != nullptr ? GSUBAlternate : 0;
        targ = translatePattern(ctx->startpat, true);
        if ( ctx->endpat != nullptr )
            repl = translatePattern(ctx->endpat, false);
        TOK(ctx);
        fc->addSub(targ, repl, type);
    }
    return nullptr;
}

GNode *FeatVisitor::translatePattern(FeatParser::PatternContext *ctx, bool markedOK) {
    GNode *ret, **insert = &ret;
    assert( stage == vExtract );

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
            else {
                TOK(pe->MARKER());
                fc->featMsg(hotERROR, "cannot mark a replacement glyph pattern");
            }
        }
        insert = &(*insert)->nextSeq;
    }
    return ret;
}

GNode *FeatVisitor::translateGlyphClass(FeatParser::GlyphClassContext *ctx) {
    assert( stage == vExtract );
    translateGlyphClassAsCurrentGC(ctx, nullptr, false);
    TOK(ctx);
    return fc->finishCurrentGC();
}

void FeatVisitor::translateGlyphClassAsCurrentGC(FeatParser::GlyphClassContext *ctx,
                                                 const std::string *gcname, bool dontcopy) {
    assert( stage == vExtract );
    if ( ctx->GCLASS() != nullptr && dontcopy ) {
        fc->openAsCurrentGC(TOK(ctx->GCLASS())->getText());
        return;
    }

    TOK(ctx);
    if ( gcname != nullptr )
        fc->defineCurrentGC(*gcname);
    else
        fc->resetCurrentGC();

    if ( ctx->gcLiteral() != nullptr ) {
        addGcLiteralToCurrentGC(ctx->gcLiteral());
    } else {
        assert( ctx->GCLASS() != nullptr );
        fc->addGlyphClassToCurrentGC(TOK(ctx->GCLASS())->getText());
    }
    if ( fc->curGCHead != nullptr )
        fc->curGCHead->flags |= FEAT_GCLASS;
}

void FeatVisitor::addGcLiteralToCurrentGC(FeatParser::GcLiteralContext *ctx) {
    assert( stage == vExtract );
    for (auto &gcle : ctx->gcLiteralElement() ) {
        if ( gcle->GCLASS() != nullptr ) {
            fc->addGlyphClassToCurrentGC(TOK(gcle->GCLASS())->getText());
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
                fc->addRangeToCurrentGC(sgid, egid, TOK(gcle->startg)->getText(),
                                        gcle->endg->getText());
            } else {
                auto g = gcle->startg;
                GID gid = getGlyph(g, true);
                if ( gid == GID_UNDEF ) { // Could be a range
                    // Can't be a CID because that pattern doesn't have a hyphen
                    assert( g->CID() == nullptr && g->glyphName() != nullptr );
                    auto gn = TOK(g->glyphName())->getText();
                    auto hpos = gn.find('-');
                    if ( hpos == std::string::npos ) {
                        fc->featMsg(hotFATAL, "incomplete glyph range or glyph not in font");
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

GID FeatVisitor::getGlyph(FeatParser::GlyphContext *ctx, bool allowNotDef) {
    assert( stage == vExtract );
    if ( ctx->CID() != nullptr )
        return fc->cid2gid(TOK(ctx->CID())->getText());
    else {
        assert( ctx->glyphName() != nullptr );
        return fc->mapGName2GID(TOK(ctx->glyphName())->getText(), allowNotDef);
    }
}
