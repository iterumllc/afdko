
#pragma once

#include "assert.h"
#include <set>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <vector>

#include "feat.h"
#include "FeatParser.h"
#include "hotmap.h"

#define kLenUnicodeList 128 // number of possible entries in list of Unicode blocks
#define kLenCodePageList 64 // number of possible entries in list of code  page numbers

class FeatVisitor;

class FeatCtx {
    friend class FeatVisitor;

    public:
        FeatCtx() = delete;
        FeatCtx(hotCtx gc);
        ~FeatCtx();

        // Implementations of external calls in feat.h
        void fill();
        GNode *setNewNode(GID gid);
        void recycleNodes(GNode *node);

        void dumpGlyph(GID gid, int ch, bool print);
        void dumpGlyphClass(GNode *gc, int ch, bool print);
        void dumpPattern(GNode *pat, int ch, bool print);

        GNode **copyGlyphClass(GNode **dst, GNode *src);
        GNode **copyPattern(GNode **dst, GNode *src, int num);
        void extendNodeToClass(GNode *node, int num);
        static int getGlyphClassCount(GNode *gc);
        static unsigned int getPatternLen(GNode *pat);
        void sortGlyphClass(GNode **list, int unique, int reportDups);
        void msgPrefix(char **premsg, char **prefix);
        GNode ***makeCrossProduct(GNode *pat, unsigned *n) { assert(false); }
        int validateGPOSChain(GNode *targ, int lookupType) { assert(false); }
        Label getNextAnonLabel();

        // Utility
        static Tag str2tag(const std::string &tagName);
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

#if HOT_DEBUG
        void nodeStats();
        void tagDump(Tag);
        void stateDump(State &st);
#endif

        static void initAnchor(AnchorMarkInfo *anchor);

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
        GNode *freelist {nullptr};
#if HOT_DEBUG
        long int nAdded2FreeList {0};
        long int nNewFromBlockList {0};
        long int nNewFromFreeList {0};
        void checkFreeNode(GNode *node);
#endif
        void addBlock();
        void freeBlocks();
        GNode *newNodeFromBlock();
        GNode *newNode();
        void recycleNode(GNode *pat);

        enum gFlagValues { gNone = 0, seenFeature = 1<<0, seenLangSys = 1<<1,
                           seenGDEFGC = 1<<2, seenIgnoreClassFlag = 1<<3,
                           seenMarkClassFlag = 1<<4,
                           seenNonDFLTScriptLang = 1<<5 };
        unsigned int gFlags {gNone};
       
        enum fFlagValues { fNone = 0, seenScriptLang = 1<<0, langSysMode = 1<<1 };
        unsigned int fFlags {fNone};

        void CDECL featMsg(int msgType, const char *fmt, ...);
        const char *tokstr();

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

        bool tagAssign(Tag tag, enum TagType type, bool checkIfDef);
        void prepRule(Tag newTbl, int newlkpType, GNode *targ, GNode *repl);

        struct LangSys {
            LangSys() = delete;
            LangSys(Tag script, Tag lang) : script(script), lang(lang), excludeDflt(false) {}
            Tag script;
            Tag lang;
            bool excludeDflt;
            bool operator<(const LangSys &b) const;
            bool operator==(const LangSys &b) const;
        };

        std::set<LangSys> langSysSet;
        void addLangSys(Tag script, Tag language, bool checkBeforeFeature,
                        FeatParser::TagContext *langctx = nullptr);
        void registerFeatureLangSys();
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
            bool operator==(const State &b) const;
        };
        State curr, prev;
        std::vector<State> DFLTLkps; // Maybe change to unordered_set

        void closeFeatScriptLang(State &st);

        struct LookupInfo {
            Tag tbl;          // GSUB_ or GPOS_
            int lkpType;      // GSUBsingle, GPOSSingle, etc.
            unsigned int lkpFlag;
            unsigned short markSetIndex;
            Label label;
            bool useExtension;
        };
        std::vector<LookupInfo> lookup;

        void setIDText();
        bool aaltCheckRule(int type, GNode *targ, GNode *repl);

        struct NamedLkp {
            std::string name;
            State state;
            bool useExtension {false};
        };
        // Given that we use vector indices for named labels the first one
        // better be zero.
        static_assert( FEAT_NAMED_LKP_BEG == 0 );
        std::vector<NamedLkp> namedLkp;
        NamedLkp *name2NamedLkp(const std::string lkpName); 
        NamedLkp *lab2NamedLkp(Label lab); 

        // Maintain a string map for faster string-based lookups
        std::unordered_map<std::string, int> namedLkpMap;
        Label currNamedLkp {LAB_UNDEF};
        bool endOfNamedLkpOrRef {false};

        Label namedLkpLabelCnt = FEAT_NAMED_LKP_BEG;
        Label anonLabelCnt = FEAT_ANON_LKP_BEG;

        struct AnchorDef {
            std::string name;
            short x {0};
            short y {0};
            unsigned int contourpoint {0};
            bool hasContour {false};
            bool operator<(const AnchorDef &b) const; // { return name < b.name; }
        };
        std::set<AnchorDef> anchorDefs;

        struct ValueDef {
            std::string name;
            short metrics[4] { 0, 0, 0, 0 };
            bool operator<(const ValueDef &b) const; // { return name < b.name; }
        };
        std::set<ValueDef> valueDefs;

        struct AALT {
            State state;
            short useExtension {false};
            struct FeatureRecord {
                Tag feature;
                bool used;
                bool operator==(const FeatureRecord &b) const;
                bool operator==(const Tag &b) const;
            };
            std::vector<FeatureRecord> features;
            struct RuleInfo {
                GNode *targ;
                GNode *repl;
            };
            std::unordered_map<GID, RuleInfo> rules;
        } aalt;

        std::unordered_map<std::string, GNode *> namedGlyphClasses;
        void resetCurrentGC();
        void defineCurrentGC(const std::string &gcname);
        void openAsCurrentGC(const std::string &gcname);
        GNode *finishCurrentGC();
        void addGlyphToCurrentGC(GID gid);
        void addGlyphClassToCurrentGC(GNode *src);
        void addGlyphClassToCurrentGC(const std::string &gcname);
        void addAlphaRangeToCurrentGC(GID first, GID last,
                                      const char *firstname, const char *p,
                                      char q);
        void addNumRangeToCurrentGC(GID first, GID last, const char *firstname,
                                    const char *p1, const char *p2,
                                    const char *q1, int numLen);
        void addRangeToCurrentGC(GID first, GID last,
                                 const std::string &firstName,
                                 const std::string &lastName);
        GNode *lookupGlyphClass(const std::string &gcname);

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
        FeatVisitor *root_visitor {nullptr}, *current_visitor {nullptr};
        CVParameterFormat cvParameters;
        // anonData
        // character array nameString
        GNode *ligGlyphs {nullptr};
        unsigned short featNameID {0};

        GID mapGName2GID(const char *gname, bool allowNotdef);
        inline GID mapGName2GID(const std::string &gname, bool allowNotdef) {
            return mapGName2GID(gname.c_str(), allowNotdef);
        }
        GID cid2gid(const std::string &cidstr);
        bool compareGlyphClassCount(GNode *targ, GNode *repl, bool isSubrule);
        void addGSUB(int lkpType, GNode *targ, GNode *repl);
        void addSub(GNode *targ, GNode *repl, int lkpType);
        void wrapUpRule();

        bool validateGSUBSingle(GNode *targ, GNode *repl, bool isSubrule);
        bool validateGSUBMultiple(GNode *targ, GNode *repl, bool isSubrule);
        bool validateGSUBAlternate(GNode *targ, GNode *repl, bool isSubrule);
        bool validateGSUBLigature(GNode *targ, GNode *repl, bool isSubrule);
        bool validateGSUBReverseChain(GNode *targ, GNode *repl);
        bool validateGSUBChain(GNode *targ, GNode *repl);
        void subtableBreak();
        void flagExtension(bool isLookup);

        Label getNextNamedLkpLabel();

        void setLkpFlagAttribute(unsigned short *val, unsigned int attr, unsigned short markAttachClassIndex);
        void setLkpFlag(unsigned short flagVal);
        void callLkp(State &st);
        void useLkp(const std::string name);
        Label getLabelIndex(const std::string name);

        void startFeature(Tag tag);
        void endFeature();
        int startScriptOrLang(TagType type, Tag tag);
        void startTable(Tag tag);

        void aaltAddFeatureTag(Tag tag);
        void reportUnusedaaltTags();
        void aaltRuleSort(GNode **list);
        void aaltAddAlternates(GNode *targ, GNode *repl);
        void aaltCreate();
        void storeRuleInfo(GNode *targ, GNode *repl);

        GNode *curGCHead {nullptr}, **curGCTailAddr {nullptr};
        std::string curGCName;
};
