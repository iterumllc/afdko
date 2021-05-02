
#include "FeatVisitor.h"
#include "otl.h"

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
    FeatParser::IncludeContext *ic = NULL;
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
    if (tree != NULL) {
        fc->visitors.emplace(ic, this);
        return true;
    }
    return false;
}

bool FeatVisitor::Translate() {
    tree->accept(this);
    return true;
}

antlrcpp::Any FeatVisitor::visitTag(FeatParser::TagContext *ctx) {
    return visitChildren(ctx);
}

antlrcpp::Any FeatVisitor::visitGlyph(FeatParser::GlyphContext *ctx) {
    std::cout << " Glyph ";
    return visitChildren(ctx);
}

antlrcpp::Any FeatVisitor::visitGlyphclass(FeatParser::GlyphclassContext *ctx) {
    std::cout << " Glyphclass ";
    return visitChildren(ctx);
}

antlrcpp::Any FeatVisitor::visitPattern(FeatParser::PatternContext *ctx) {
    std::cout << " Pattern ";
    return visitChildren(ctx);
}

antlrcpp::Any FeatVisitor::visitSubstitute(FeatParser::SubstituteContext *ctx) {
    std::cout << " Sub ";
    return visitChildren(ctx);
}

antlrcpp::Any FeatVisitor::visitInclude(FeatParser::IncludeContext *ctx) {
    std::cout << " Include ";
    return visitChildren(ctx);
}

antlrcpp::Any FeatVisitor::visitFeatureBlock(FeatParser::FeatureBlockContext *ctx) {
    assert ( ctx->starttag != NULL && ctx->endtag != NULL );
    const char *st_txt = ctx->starttag->getText().c_str();
    const char *et_txt = ctx->endtag->getText().c_str();
    Tag stag = FeatCtx::str2tag(st_txt), etag = FeatCtx::str2tag(et_txt);

    if ( stag != etag )
        hotMsg(fc->g, hotWARNING, "Start tag %s does not match end tag %s.", st_txt, et_txt);

    std::cout << " FeatureBlock Start Tag = " << st_txt << " End Tag = " << et_txt;
    return visitChildren(ctx);
}
