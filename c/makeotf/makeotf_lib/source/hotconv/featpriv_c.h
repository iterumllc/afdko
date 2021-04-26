/* Copyright 2014 Adobe Systems Incorporated (http://www.adobe.com/). All Rights Reserved.
   This software is licensed as OpenSource, under the Apache License, Version 2.0. This license is available at: http://opensource.org/licenses/Apache-2.0. */
/***********************************************************************/

#ifndef HOTCONV_FEAT_H
#define HOTCONV_FEAT_H

#include "common.h"

#ifdef __cplusplus
extern "C" {
#endif

#if HOT_FEAT_SUPPORT

/* --- PCCTS scanner functions --- */
int featOpenIncludeFile(hotCtx g, char *filename);
int featCloseIncludeFile(hotCtx g, int closeBase);
char *featTrimParensSpaces(char *text);
void featWrapUpFeatFile(void);
void featSetIncludeReturnMode(int mode);
int featGetIncludeReturnMode(void);
void featSetTagReturnMode(int mode);
int featGetTagReturnMode(void);
int featAddAnonDataChar(char ch, int isEOL);
void featAddNameStringChar(char ch);
void featUnexpectedEOF(void);

#define kDEFAULT_BASECLASS_NAME "FDK_BASE_CLASS"
#define kDEFAULT_LIGATURECLASS_NAME "FDK_LIGATURE_CLASS"
#define kDEFAULT_MARKCLASS_NAME "FDK_DEFAULT_MARK_CLASS"
#define kDEFAULT_COMPONENTCLASS_NAME "FDK_DEFAULT_COMPONENT_CLASS"

#endif /* HOT_FEAT_SUPPORT */

#ifdef __cplusplus
}
#endif

#endif /* HOTCONV_FEAT_H */
