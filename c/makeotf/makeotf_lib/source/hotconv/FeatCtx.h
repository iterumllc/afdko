
#pragma once

#include "assert.h"
#include <vector>
#include <string>
#include <set>
#include <unordered_set>
#include <unordered_map>

#include "hotmap.h"
#include "feat.h"
#include "FeatParser.h"

#define kLenUnicodeList 128 // number of possible entries in list of Unicode blocks
#define kLenCodePageList 64 // number of possible entries in list of code  page numbers

class FeatVisitor;

typedef FeatParser::TagContext TagCtx;

class FeatCtx {
    friend class FeatVisitor;

    public:
        FeatCtx() = delete;
        FeatCtx(hotCtx gc);
        ~FeatCtx();

        // Implementations of external calls in feat.h
        void fill(void);
        GNode *setNewNode(GID gid) { assert(false); }
        void recycleNodes(GNode *node) { assert(false); }
        GNode **glyphClassCopy(GNode **dst, GNode *src) { assert(false); }
        void glyphDump(GID gid, int ch, int print) { assert(false); }
        void glyphClassDump(GNode *gc, int ch, int print) { assert(false); }
        void patternDump(GNode *pat, int ch, int print) { assert(false); }
        GNode **patternCopy(GNode **dst, GNode *src, int num) { assert(false); }
        void extendNodeToClass(GNode *node, int num) { assert(false); }
        int getGlyphClassCount(GNode *gc) { assert(false); }
        unsigned int getPatternLen(GNode *pat) { assert(false); }
        void glyphClassSort(GNode **list, int unique, int reportDups) { assert(false); }
        GNode ***makeCrossProduct(GNode *pat, unsigned *n) { assert(false); }
        Label getNextAnonLabel(void) { assert(false); }
        int validateGPOSChain(GNode *targ, int lookupType) { assert(false); }

        // Utility
        static Tag str2tag(std::string &tagName);
        static inline bool is_glyph(GNode *p) {
            return p!=nullptr && p->nextSeq == nullptr && p->nextCl == nullptr &&
                   !(p->flags & FEAT_GCLASS);
        }
        static inline bool is_class(GNode *p) {
            return p!=nullptr && p->nextSeq == nullptr && 
                   (p->nextCl != nullptr || (p->flags & FEAT_GCLASS));
        }
        static inline bool is_mult_class(GNode *p) {
            return p!=nullptr && p->nextSeq == nullptr && p->nextCl != nullptr;
        }
        static inline bool is_unmarked_glyph(GNode *p) {
            return is_glyph(p) && !(p->flags & FEAT_HAS_MARKED);
        }
        static inline bool is_unmarked_class(GNode *p) {
            return is_class(p) && !(p->flags & FEAT_HAS_MARKED);
        }

    private:
        void setUnicodeRange(short unicodeList[kLenUnicodeList]);
        void setCodePageRange(short codePageList[kLenCodePageList]);

        // GNode memory management
        struct BlockNode {
            GNode *data;
            BlockNode *next;
        };

        struct {
            BlockNode *first {nullptr};
            BlockNode *curr {nullptr}; // Current BlockNode being filled
            long cnt {0};           // Index of next free GNode, relative to curr->data 
            long intl {3000};
            long incr {6000};
        } blockList;
        GNode *freelist;
#if HOT_DEBUG
        long int nAdded2FreeList {0};
        long int nNewFromBlockList {0};
        long int nNewFromFreeList {0};
#endif
        void addBlock();
        void freeBlocks();
        GNode *newGNode();

        enum gFlagValues { gNone = 0, seenFeature = 1<<0, seenLangSys = 1<<1,
                           seenGDEFGC = 1<<2, seenIgnoreClassFlag = 1<<3,
                           seenMarkClassFlag = 1<<4,
                           seenNonDFLTScriptFlag = 1<<5 }
        gFlags {gNone};
       
        enum fFlagValues { fNone = 0, seenScriptLang = 1<<0, langSysMode = 1<<1 }
        fFlags {fNone};

        // Tag management 
        enum TagType { featureTag, scriptTag, languageTag, tableTag };
        typedef std::unordered_set<Tag> TagArray;
        TagArray script, language, feature, table;

        inline bool addTag(TagArray &a, Tag t) {
            if ( a.find(t) == a.end() )
                return false;
            a.emplace(t);
            return true;
        }

        Tag checkTag(TagCtx *start, TagCtx *end, TagType type);

        struct LangSys {
            Tag script {TAG_UNDEF};
            Tag lang {TAG_UNDEF};
            bool excludeDflt {false};
            bool operator<(const LangSys& b);
            //    return script<b.script || (script==b.script && lang<b.lang);
            bool operator==(const LangSys& b);
            //    return script==b.script && lang==b.lang;
        };

        struct LangSysHasher {
            inline size_t operator()(const LangSys &ls) const {
                uint64_t c = ((uint64_t)ls.script << 32) + ls.lang;
                return std::hash<uint64_t>{}(c);
            }
        };

        std::unordered_set<LangSys, LangSysHasher> LangSysSet;
        bool include_dflt = true, seenOldDFLT = false;

        struct State {
            Tag script {TAG_UNDEF};
            Tag language {TAG_UNDEF};
            Tag feature {TAG_UNDEF};
            Tag tbl {TAG_UNDEF}; // GSUB_ or GPOS_
            int lkpType {0};     // GSUBsingle, GPOSSingle, etc.
            unsigned int lkpFlag {0};
            unsigned short markSetIndex {0};
            Label label {LAB_UNDEF};
            bool operator==(const State &b);
        };
        State curr, prev;
        std::vector<State> DFLTLkps; // Maybe change to unordered_set

        void closeFeatScriptLang(State &st);

        struct LookupInfo {
            Tag tbl {TAG_UNDEF};  // GSUB_ or GPOS_
            int lkpType {0};      // GSUBsingle, GPOSSingle, etc.
            unsigned int lkpFlag {0};
            unsigned short markSetIndex {0};
            Label label {LAB_UNDEF};
            bool useExtension;
        };
        std::vector<LookupInfo> Lookups;

        struct NamedLkp {
            std::string name;
            State state;
            bool useExtension {false};
        };
        // Given that we use vector indices for named labels the first one
        // better be zero.
        static_assert( FEAT_NAMED_LKP_BEG == 0 );
        std::vector<NamedLkp> namedLkp;
        // Maintain a string map for faster string-based lookups
        std::unordered_map<std::string, int> namedLkpMap;
        Label curNamedLkp {LAB_UNDEF};
        bool endOfNamedLkpOrRef {false};

        Label namedLkpLabelCnt = FEAT_NAMED_LKP_BEG;
        Label anonLabelCnt = FEAT_ANON_LKP_BEG;

        struct AnchorDef {
            std::string name;
            short x {0};
            short y {0};
            unsigned int contourpoint {0};
            bool hasContour {false};
            bool operator<(const AnchorDef &b); // { return name < b.name; }
        };
        std::set<AnchorDef> anchorDefs;

        struct ValueDef {
            std::string name;
            short metrics[4] { 0, 0, 0, 0 };
            bool operator<(const ValueDef &b); // { return name < b.name; }
        };
        std::set<ValueDef> valueDefs;

        struct AALT {
            State state;
            short useExtension {false};
            struct FeatureRecord {
                Tag feature {TAG_UNDEF};
                bool used {false};
                bool operator==(const FeatureRecord &b); // { feature == b.feature; }
            };
            std::vector<FeatureRecord> features;
            struct RuleInfo {
                GNode *targ {nullptr};
                GNode *repl {nullptr};
            };
            std::unordered_map<GID, RuleInfo> rules;
        } aalt;

        std::unordered_map<std::string, GNode *> namedGlyphClasses;
        std::vector<GNode *> markClasses;
        std::vector<unsigned short> ligCaretValues;
        std::vector<MetricsInfo> metricsInfos;
        std::vector<AnchorMarkInfo> anchorMarkInfos;

        struct {
            unsigned short numExcept {0};
        } syntax;

        enum { cvUILabelEnum = 1, cvToolTipEnum, cvSampletextEnum,
               kCVParameterLabelEnum };

        hotCtx g;
        // Maps included files to their corresponding visitors, with
        // IncludeContext NULL being the root visitor
        std::unordered_map<FeatParser::IncludeContext*, FeatVisitor*> visitors;
        CVParameterFormat cvParameters;
        // GNode **gcInsert;
        // anonData
        // character array nameString
        GNode *ligGlyphs {nullptr};
        unsigned short featNameID {0};
};
