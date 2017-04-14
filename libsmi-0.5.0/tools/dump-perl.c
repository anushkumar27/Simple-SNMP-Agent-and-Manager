/*
 * dump-perl.c --
 *
 *      Operations to dump SMIng module information in Perl format.
 *
 * Copyright (c) 2000 Frank Strauss, Technical University of Braunschweig.
 * Copyright (c) 2000 J. Schoenwaelder, Technical University of Braunschweig.
 * Copyright (c) 2000 WideAwake Ltd.
 * Copyright (c) 2000 Martin Schulz martin.schulz@myrealbox.com
 *
 * See the file "COPYING" for information on usage and redistribution
 * of this file, and for a DISCLAIMER OF ALL WARRANTIES.
 *
 * @(#) $Id: dump-perl.c 1772 2012-04-01 12:15:23Z schoenw $
 */

/*
 * TODO:
 *
 */

#include <config.h>

#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#include "smi.h"
#include "smidump.h"



#define  INDENT         4    /* indent factor */
#define  INDENTVALUE    20   /* column to start values, except multiline */
#define  INDENTTEXTS    4    /* column to start multiline texts */
#define  INDENTMAX      64   /* max column to fill, break lines otherwise */



typedef struct PerlEscape {
    char character;
    char *escape;
} PerlEscape;

static PerlEscape perlEscapes [] = {
    { '\'',     "\\'" },
    { '\\',     "\\\\" },
    { 0,        NULL }
};


static int current_column = 0;

static char* currentModuleName = NULL;

static char *getStringLanguage(SmiLanguage lang)
{
    return
        (lang == SMI_LANGUAGE_SMIV1) ? "SMIv1" :
        (lang == SMI_LANGUAGE_SMIV2) ? "SMIv2" :
        (lang == SMI_LANGUAGE_SMING) ? "SMIng" :
                                        NULL;
}



static char *getStringStatus(SmiStatus status)
{
    return
        (status == SMI_STATUS_CURRENT)     ? "current" :
        (status == SMI_STATUS_DEPRECATED)  ? "deprecated" :
        (status == SMI_STATUS_OBSOLETE)    ? "obsolete" :
        (status == SMI_STATUS_MANDATORY)   ? "current" :
        (status == SMI_STATUS_OPTIONAL)    ? "current" :
                                             "<unknown>";
}



static char *getAccessString(SmiAccess access)
{
    return
        (access == SMI_ACCESS_NOT_ACCESSIBLE) ? "noaccess" :
        (access == SMI_ACCESS_NOTIFY)         ? "notifyonly" :
        (access == SMI_ACCESS_READ_ONLY)      ? "readonly" :
        (access == SMI_ACCESS_READ_WRITE)     ? "readwrite" :
                                                "<unknown>";
}



static char *getStringBasetype(SmiBasetype basetype)
{
    return
        (basetype == SMI_BASETYPE_UNKNOWN)           ? "<UNKNOWN>" :
        (basetype == SMI_BASETYPE_OCTETSTRING)       ? "OctetString" :
        (basetype == SMI_BASETYPE_OBJECTIDENTIFIER)  ? "ObjectIdentifier" :
        (basetype == SMI_BASETYPE_UNSIGNED32)        ? "Unsigned32" :
        (basetype == SMI_BASETYPE_INTEGER32)         ? "Integer32" :
        (basetype == SMI_BASETYPE_UNSIGNED64)        ? "Unsigned64" :
        (basetype == SMI_BASETYPE_INTEGER64)         ? "Integer64" :
        (basetype == SMI_BASETYPE_FLOAT32)           ? "Float32" :
        (basetype == SMI_BASETYPE_FLOAT64)           ? "Float64" :
        (basetype == SMI_BASETYPE_FLOAT128)          ? "Float128" :
        (basetype == SMI_BASETYPE_ENUM)              ? "Enumeration" :
        (basetype == SMI_BASETYPE_BITS)              ? "Bits" :
                                                   "<unknown>";
}



static char *getTimeString(time_t t)
{
    static char   s[27];
    struct tm     *tm;

    tm = gmtime(&t);
    sprintf(s, "%04d-%02d-%02d %02d:%02d",
            tm->tm_year + 1900, tm->tm_mon + 1, tm->tm_mday,
            tm->tm_hour, tm->tm_min);
    return s;
}



static void fprint(FILE *f, char *fmt, ...)
{
    va_list ap;
    char    *s;
    char    *p;

    va_start(ap, fmt);
    current_column += smiVasprintf(&s, fmt, ap);
    va_end(ap);
    fputs(s, f);
    if ((p = strrchr(s, '\n'))) {
        current_column = strlen(p) - 1;
    }
    free(s);
}



static void fprintSegment(FILE *f, int column, char *string, int length)
{
    fprint(f, "%*c%s", column, ' ', string);
    if (length) {
        fprint(f, "%*c", length - strlen(string) - column, ' ');
    }
}



static void fprintMultilineString(FILE *f, int column, const char *s)
{
    int i, j, len;

#ifdef INDENTTEXTS
    fprintSegment(f, column + INDENTTEXTS, "", 0);
#endif
    if (s) {
        fputs ("'", f);
        current_column += 3;
        len = strlen(s);
        for (i=0; i < len; i++) {
            for (j = 0; perlEscapes[j].character; j++) {
                if (perlEscapes[j].character == s[i]) break;
            }
            if (perlEscapes[j].character) {
                fputs(perlEscapes[j].escape, f);
                current_column += strlen(perlEscapes[j].escape);
            } else {
                putc(s[i], f);
                current_column++;
            }
            if (s[i] == '\n') {
                current_column = 0;
            }
        }
        fputs ("'", f);
        current_column += 3;
    }
    current_column++;
}



static char *getValueString(SmiValue *valuePtr, SmiType *typePtr)
{
    static char    s[1024];
    char           ss[9];
    int            n;
    unsigned int   i;
    SmiNamedNumber *nn;

    s[0] = 0;

    switch (valuePtr->basetype) {
    case SMI_BASETYPE_UNSIGNED32:
        sprintf(s, "%lu", valuePtr->value.unsigned32);
        break;
    case SMI_BASETYPE_INTEGER32:
        sprintf(s, "%ld", valuePtr->value.integer32);
        break;
    case SMI_BASETYPE_UNSIGNED64:
        sprintf(s, UINT64_FORMAT, valuePtr->value.unsigned64);
        break;
    case SMI_BASETYPE_INTEGER64:
        sprintf(s, INT64_FORMAT, valuePtr->value.integer64);
        break;
    case SMI_BASETYPE_FLOAT32:
    case SMI_BASETYPE_FLOAT64:
    case SMI_BASETYPE_FLOAT128:
        break;
    case SMI_BASETYPE_ENUM:
        for (nn = smiGetFirstNamedNumber(typePtr); nn;
             nn = smiGetNextNamedNumber(nn)) {
            if (nn->value.value.unsigned32 == valuePtr->value.unsigned32)
                break;
        }
        if (nn) {
            sprintf(s, "%s", nn->name);
        } else {
            sprintf(s, "%ld", valuePtr->value.integer32);
        }
        break;
    case SMI_BASETYPE_OCTETSTRING:
        for (i = 0; i < valuePtr->len; i++) {
            if (!isprint((int)valuePtr->value.ptr[i])) break;
        }
        if (i == valuePtr->len) {
            sprintf(s, "%s", valuePtr->value.ptr);
        } else {
            sprintf(s, "0x%*s", 2 * valuePtr->len, "");
            for (i=0; i < valuePtr->len; i++) {
                sprintf(ss, "%02x", valuePtr->value.ptr[i]);
                strncpy(&s[2+2*i], ss, 2);
            }
        }
        break;
    case SMI_BASETYPE_BITS:
        sprintf(s, "(");
        for (i = 0, n = 0; i < valuePtr->len * 8; i++) {
            if (valuePtr->value.ptr[i/8] & (1 << (7-(i%8)))) {
                if (n)
                    sprintf(&s[strlen(s)], ", ");
                n++;
                for (nn = smiGetFirstNamedNumber(typePtr); nn;
                     nn = smiGetNextNamedNumber(nn)) {
                    if (nn->value.value.unsigned32 == i)
                        break;
                }
                if (nn) {
                    sprintf(&s[strlen(s)], "%s", nn->name);
                } else {
                    sprintf(s, "%d", i);
                }
            }
        }
        sprintf(&s[strlen(s)], ")");
        break;
    case SMI_BASETYPE_UNKNOWN:
        break;
    case SMI_BASETYPE_POINTER:
        break;
    case SMI_BASETYPE_OBJECTIDENTIFIER:
        for (i = 0; i < valuePtr->len; i++) {
            sprintf(&s[strlen(s)], i ? ".%u" : "%u", valuePtr->value.oid[i]);
        }
        break;
    }

    return s;
}



static void fprintNodeStartTag(FILE *f, int indent, const char *tag,
			       SmiNode *smiNode)
{
    unsigned int i;

    fprintSegment(f, indent, "", 0);
    fprint(f, "{\n", smiNode->name);
    fprintSegment(f, indent + INDENT, "", 0);
    fprint(f, "\"name\" => \"%s\",\n", smiNode->name);
    fprintSegment(f, indent + INDENT, "", 0);
    fprint(f, "\"type\" => \"%s\",\n", tag);
    fprintSegment(f, indent + INDENT, "", 0);
    fprint(f, "\"module\" => \"%s\",\n", currentModuleName);
    fprintSegment(f, indent + INDENT, "", 0);
    fprint(f, "\"oid\" => \"");
    for (i = 0; i < smiNode->oidlen; i++) {
        fprint(f, i ? ".%u" : "%u", smiNode->oid[i]);
    }
    fprint(f, "\"");

    if (smiNode->create) {
        fprint(f, ",\n");
        fprintSegment(f, indent + INDENT, "\"create\" => \"true\"", 0);
    }
    if (smiNode->status != SMI_STATUS_UNKNOWN) {
        fprint(f, ",\n");
        fprintSegment(f, indent + INDENT, "", 0);
        fprint(f, "\"status\" => \"%s\"", getStringStatus(smiNode->status));
    }
    if (smiNode->implied) {
        fprint(f, ",\n");
        fprintSegment(f, indent + INDENT, "\"implied\" => \"true\"", 0);
    }
    fprint(f, ",\n");
}



static void fprintNodeEndTag(FILE *f, int indent, const char *tag,
			     const char *name)
{
    fprintSegment(f, indent, "", 0);
    fprint(f, "}, # %s\n", name);
}



static void fprintRanges(FILE *f, int indent, SmiType *smiType)
{
    SmiRange       *range;
    SmiValue	   min, max;
    int            rc;

    if (! smiGetFirstRange(smiType)) {
	return;
    }

    fprintSegment(f, indent, "\"ranges\" => (\n", 0);
    for (range = smiGetFirstRange(smiType);
	 range;
	 range = smiGetNextRange(range)) {
        fprintSegment(f, indent, "{\n", 0);
        fprintSegment(f, indent + INDENT, "", 0);
        fprint(f, "\"min\" => \"%s\",\n",
	       getValueString(&range->minValue, smiType));
        fprintSegment(f, indent + INDENT, "", 0);
        fprint(f, "\"max\" => \"%s\"\n",
	       getValueString(&range->maxValue, smiType));
        fprintSegment(f, indent, "},\n", 0);
    }
    fprintSegment(f, indent, "),\n", 0);

    rc = smiGetMinMaxRange(smiType, &min, &max);
    
    if (rc == 0
	&& min.basetype != SMI_BASETYPE_UNKNOWN
	&& max.basetype != SMI_BASETYPE_UNKNOWN) {
        fprintSegment(f, indent, "\"range\" => {\n", 0);
        fprintSegment(f, indent + INDENT, "", 0);
        fprint(f, "\"min\" => \"%s\",\n",
	       getValueString(&min, smiType));
        fprintSegment(f, indent + INDENT, "", 0);
        fprint(f, "\"max\" => \"%s\"\n",
	       getValueString(&max, smiType));
        fprintSegment(f, indent, "},\n", 0);
    }
}



static void fprintNamedNumbers(FILE *f, int indent, SmiType *smiType)
{
    SmiNamedNumber *nn;

    if ((smiType->basetype != SMI_BASETYPE_ENUM) &&
        (smiType->basetype != SMI_BASETYPE_BITS)) {
        return;
    }

    for (nn = smiGetFirstNamedNumber(smiType);
         nn;
         nn = smiGetNextNamedNumber(nn)) {
        fprintSegment(f, indent, "\"", 0);
        fprint(f, "%s\" => ", nn->name);
        fprint(f, "\"%s\",\n", getValueString(&nn->value, smiType));
    }
}



static void fprintValue(FILE *f, int indent, SmiValue *smiValue,
			SmiType *smiType)
{
    if (smiType && smiValue && smiValue->basetype != SMI_BASETYPE_UNKNOWN) {
        fprintSegment(f, indent, "\"DEFVAL\" => ", 0);
        fprint(f, "\"%s\"", getValueString(smiValue, smiType));
        fprint(f, ",\n");
    }
}



static void fprintDescription(FILE *f, int indent, const char *description)
{
    if (description) {
        fprintSegment(f, indent, "\"description\" =>\n", 0);
        fprintMultilineString(f, indent, description);
        fprint(f, ",\n");
    }
}



static void fprintReference(FILE *f, int indent, const char *reference)
{
    if (reference) {
        fprintSegment(f, indent, "\"reference\" =>\n", 0);
        fprintMultilineString(f, indent, reference);
        fprint(f, ",\n");
    }
}



static void fprintFormat(FILE *f, int indent, const char *format)
{
    if (format) {
        fprintSegment(f, indent, "", 0);
        fprint(f, "\"DISPLAY-HINT\" => \"%s\",\n", format);
    }
}



static void fprintUnits(FILE *f, int indent, const char *units)
{
    if (units) {
        fprintSegment(f, indent, "", 0);
        fprint(f, "\"UNITS\" => \"%s\",\n", units);
    }
}



static void fprintAccess(FILE *f, int indent, SmiAccess smiAccess)
{
    if (smiAccess != SMI_ACCESS_UNKNOWN) {
        fprintSegment(f, indent, "", 0);
        fprint(f, "\"access\" => \"%s\",\n", getAccessString(smiAccess));
    }
}



static void fprintElementList(FILE *f, int indent, const char *tag,
			      SmiElement *smiElement, int asArray)
{
    SmiModule *smiModule;
    SmiNode   *smiNode;

    for (; smiElement; smiElement = smiGetNextElement(smiElement)) {
        smiNode = smiGetElementNode(smiElement);
        smiModule = smiGetNodeModule(smiNode);
        fprintSegment(f, indent, "", 0);
        if (tag) {
            if (asArray) {
                fprint(f, "{\n");
                fprintSegment(f, indent + INDENT, "", 0);
                fprint(f, "\"name\" => \"%s\",\n", smiNode->name);
            } else {
                fprint(f, "\"%s\" => {\n", smiNode->name);
            }
            fprintSegment(f, indent + INDENT, "", 0);
            fprint(f, "\"type\" => \"%s\",\n", tag);
            fprintSegment(f, indent + INDENT, "", 0);
            fprint(f, "\"module\" => \"%s\"\n", smiModule->name);
            fprintSegment(f, indent, "},\n", 0);
        } else {
            if (asArray) {
                fprint(f, "{ \"module\" => \"%s\", ", smiModule->name);
                fprint(f, "\"name\" => \"%s\" },\n", smiNode->name);
            } else {
                fprint(f, "\"%s\" => \"%s\",\n", smiNode->name, smiModule->name);
            }
        }
    }
}



static void fprintIndexModule(FILE *f, int indent, const char *modname,
                              const char *nodename, const char *indexkind)
{
    fprintSegment(f, indent, "", 0);
    fprint(f, "\"%s\" => {\n", indexkind);
    fprintSegment(f, indent + INDENT, "", 0);
    fprint(f, "\"module\" => \"%s\",\n", modname);
    fprintSegment(f, indent + INDENT, "", 0);
    fprint(f, "\"name\" => \"%s\",\n", nodename);
    fprintSegment(f, indent, "},\n", 0);
}



static void fprintIndex(FILE *f, int indent, SmiNode *smiNode)
{
    SmiNode   *relatedNode;
    SmiModule *relatedModule = NULL;

    if (smiNode->implied) {
        fprintSegment(f, indent, "\"indeximplied\" => \"true\",\n", 0);
    }

    relatedNode = smiGetRelatedNode(smiNode);
    if (relatedNode) {
        relatedModule = smiGetNodeModule(relatedNode);
    }
    switch (smiNode->indexkind) {
    case SMI_INDEX_INDEX:
        fprintSegment(f, indent, "\"index\" => [\n", 0);
        fprintElementList(f, indent + INDENT, NULL,
			  smiGetFirstElement(smiNode), 1);
        fprintSegment(f, indent, "], #index\n", 0);
        break;
    case SMI_INDEX_AUGMENT:
        if (relatedNode && relatedModule) {
            fprintIndexModule(f, indent, relatedModule->name,
                              relatedNode->name, "augments");
        } /* TODO: else print error */
        break;
    case SMI_INDEX_REORDER:
        if (relatedNode && relatedModule) {
            fprintIndexModule(f, indent, relatedModule->name,
                              relatedNode->name, "reorders");
            fprintSegment(f, indent, "\"index\" => [\n", 0);
            fprintElementList(f, indent + INDENT, NULL,
			      smiGetFirstElement(smiNode), 1);
            fprintSegment(f, indent, "], #index\n", 0);
        } /* TODO: else print error */
        break;
    case SMI_INDEX_SPARSE:
        if (relatedNode && relatedModule) {
            fprintIndexModule(f, indent, relatedModule->name,
                              relatedNode->name, "sparse");
        } /* TODO: else print error */
        break;
    case SMI_INDEX_EXPAND:
        if (relatedNode && relatedModule) {
            fprintIndexModule(f, indent, relatedModule->name,
                              relatedNode->name, "expands");
        } /* TODO: else print error */
        break;
    case SMI_INDEX_UNKNOWN:
        break;
    }
}



static void fprintModule(FILE *f, SmiModule *smiModule)
{
    SmiRevision *smiRevision;
    SmiNode     *smiNode;
    int         i;
    int         there_were_revisions = 0;

    currentModuleName = smiModule->name;

    if (smiModule->organization) {
        fprintSegment(f, INDENT, "\"organization\" =>", INDENTVALUE);
        fprint(f, "\n");
        fprintMultilineString(f, INDENT, smiModule->organization);
        fprint(f, ",\n");
    }

    if (smiModule->contactinfo) {
        fprintSegment(f, INDENT, "\"contact\" =>", INDENTVALUE);
        fprint(f, "\n");
        fprintMultilineString(f, INDENT, smiModule->contactinfo);
        fprint(f, ",\n");
    }
    fprintDescription(f, INDENT, smiModule->description);
    fprintReference(f, INDENT, smiModule->reference);

    for(i = 0, smiRevision = smiGetFirstRevision(smiModule);
        smiRevision; smiRevision = smiGetNextRevision(smiRevision)) {
        if (i == 0) {
            fprintSegment(f, INDENT, "\"revisions\" => [\n", 0);
            there_were_revisions = 1;
        }
        fprintSegment(f, 2 * INDENT, "{\n", 0);
        fprintSegment(f, 3 * INDENT, "", 0);
        fprint(f, "\"date\" => \"%s\",\n",
	       getTimeString(smiRevision->date));
        fprintDescription(f, 3 * INDENT, smiRevision->description);
        fprintSegment(f, 2 * INDENT, "},\n", 0);
        i++;
    }
    if (there_were_revisions) {
        fprintSegment(f, INDENT, "],\n", 0);
    }

    smiNode = smiGetModuleIdentityNode(smiModule);
    if (smiNode) {
        fprintSegment(f, INDENT, "", 0);
        fprint(f, "\"identity\" => \"%s\",\n", smiNode->name);
    }
    fprint(f, "\n");
}



static void fprintImports(FILE *f, SmiModule *smiModule)
{
    SmiImport *smiImport;
    SmiIdentifier lastModule = NULL;
    int        i;

    for (i = 0, smiImport = smiGetFirstImport(smiModule);
         smiImport;
         i++,
         smiImport = smiGetNextImport(smiImport)) {
        if (i == 0) {
            fprintSegment(f, INDENT, "\"imports\" => [\n", 0);
        }
        if (smiImport->module == NULL)
            continue;
        
        if ( lastModule == NULL || strcmp(lastModule, smiImport->module)) {
            if ( lastModule ) {
                fprintSegment(f, 3 * INDENT, "]\n", 0);
                fprintSegment(f, 2 * INDENT, "},\n", 0);
            }
            fprintSegment(f, 2 * INDENT, "{\n", 0);
            fprintSegment(f, 3 * INDENT, "", 0);
            fprint(f, "\"module\" => \"%s\",\n",
		   smiImport->module);
            fprintSegment(f, 3 * INDENT, "\"names\" => [\n", 0);
        }
        fprintSegment(f, 4 * INDENT, "", 0);
        fprint(f, "\"%s\",\n", smiImport->name);
        lastModule = smiImport->module;
    }
    if (lastModule) {
        fprintSegment(f, 3 * INDENT, "],\n", 0);
        fprintSegment(f, 2 * INDENT, "}\n", 0);
    }

    if (i) {
        fprintSegment(f, INDENT, "], # imports\n\n", 0);
    }
}



static void fprintTypedef(FILE *f, int indent, SmiType *smiType)
{
    SmiModule *parentModule;
    SmiType *parentType;

    fprintSegment(f, indent, "", 0);
    if (smiType->name) {
        fprint(f, "\"%s\" => ", smiType->name);
    }
    fprint(f, "{\n");
    fprintSegment(f, indent + INDENT, "", 0);
    fprint(f, "\"basetype\" => \"%s\",\n",
	   getStringBasetype(smiType->basetype));
    if (smiType->name && smiType->status != SMI_STATUS_UNKNOWN) {
        fprintSegment(f, indent + INDENT, "", 0);
        fprint(f, "\"status\" => \"%s\",\n", getStringStatus(smiType->status));
    }

    parentType = smiGetParentType(smiType);
    parentModule = smiGetTypeModule(parentType);
    if (parentType && parentModule && strlen(parentModule->name)) {
        fprintSegment(f, indent + INDENT, "\"parent\" => {\n", 0);
        fprintSegment(f, indent + (2 * INDENT), "", 0);
        fprint(f, "\"module\" => \"%s\",\n", parentModule->name);
        fprintSegment(f, indent + (2 * INDENT), "", 0);
        fprint(f, "\"name\" => \"%s\",\n", parentType->name);
        fprintSegment(f, indent + INDENT, "},\n", 0);
    }
    fprintRanges(f, indent + INDENT, smiType);
    fprintNamedNumbers(f, indent + INDENT, smiType);
    fprintValue(f, indent + INDENT, &smiType->value, smiType);
    fprintFormat(f, indent + INDENT, smiType->format);
    fprintUnits(f, indent + INDENT, smiType->units);
    fprintDescription(f, indent + INDENT, smiType->description);
    fprintReference(f, indent + INDENT, smiType->reference);

    fprintSegment(f, indent, "},", 0);
    if (smiType->name) {
	fprint(f, " # %s\n", smiType->name);
    } else {
	fprint(f, "\n", smiType->name);
    }
}



static void fprintTypedefs(FILE *f, SmiModule *smiModule)
{
    int          i;
    SmiType      *smiType;

    for(i = 0, smiType = smiGetFirstType(smiModule);
        smiType;
        i++, smiType = smiGetNextType(smiType)) {

        if (i == 0) {
            fprintSegment(f, INDENT, "\"typedefs\" => {\n", 0);
        }
        fprintTypedef(f, 2 * INDENT, smiType);
    }

    if (i) {
        fprintSegment(f, INDENT, "}, # typedefs\n\n", 0);
    }
}



static void fprintNode(FILE *f, int indent, SmiNode *smiNode,
		       SmiNode *lastSmiNode)
{
    SmiModule   *smiModule;
    SmiType     *smiType;
    char        *tag = NULL;

    if (smiNode->nodekind == SMI_NODEKIND_NODE) {
        tag = "node";
    } else if (smiNode->nodekind == SMI_NODEKIND_CAPABILITIES) {
        tag = "capabilities";
    } else if (smiNode->nodekind == SMI_NODEKIND_TABLE) {
        tag = "table";
    } else if (smiNode->nodekind == SMI_NODEKIND_ROW) {
        /* indent += INDENT; */
        tag = "row";
    } else if (smiNode->nodekind == SMI_NODEKIND_COLUMN) {
        /* indent += 2 * INDENT; */
        tag = "column";
    } else if (smiNode->nodekind == SMI_NODEKIND_SCALAR) {
        tag = "scalar";
    }

/*      if (lastSmiNode */
/*      && lastSmiNode->nodekind == SMI_NODEKIND_COLUMN */
/*      && smiNode->nodekind != SMI_NODEKIND_COLUMN) { */
/*      printNodeEndTag(indent + INDENT, "row", smiNode->name); */
/*          printNodeEndTag(indent, "table", smiNode->name); */
/*      } */

    smiType = smiGetNodeType(smiNode);

    fprintNodeStartTag(f, indent, tag, smiNode);
    fprintDescription(f, indent + INDENT, smiNode->description);
    fprintReference(f, indent + INDENT, smiNode->reference);

    if (smiType && (smiType->basetype != SMI_BASETYPE_UNKNOWN)) {
        fprintSegment(f, indent + INDENT, "\"syntax\" => {\n", 0);
        smiModule = smiGetTypeModule(smiType);
        fprintSegment(f, indent + 2 *INDENT, "", 0);
        fprint(f, "\"type\" => ");
        if (smiType->name && smiModule) {
            fprint(f, "{ \"module\" => \"%s\", \"name\" => \"%s\"},\n",
                   smiModule->name, smiType->name);
        } else {
            fprint(f, "\n");
            fprintTypedef(f, indent + 2 * INDENT, smiType);
        }
        fprintSegment(f, indent + INDENT, "},\n", 0);
    }
    if ((smiNode->nodekind != SMI_NODEKIND_TABLE) &&
        (smiNode->nodekind != SMI_NODEKIND_ROW) &&
        (smiNode->nodekind != SMI_NODEKIND_CAPABILITIES) &&
        (smiNode->nodekind != SMI_NODEKIND_NODE)) {
        fprintAccess(f, indent + INDENT, smiNode->access);
    }
    if (smiType) {
        fprintValue(f, indent + INDENT, &smiNode->value, smiType);
    }
    fprintFormat(f, indent + INDENT, smiNode->format);
    fprintUnits(f, indent + INDENT, smiNode->units);
    if (smiNode->nodekind == SMI_NODEKIND_ROW) {
        fprintIndex(f, indent + INDENT, smiNode);
    }

    fprintNodeEndTag(f, indent, tag, smiNode->name);
}



static void fprintNodes(FILE *f, SmiModule *smiModule)
{
    int          i;
    SmiNode      *smiNode, *lastSmiNode;
    SmiNodekind  nodekinds;

    nodekinds =  SMI_NODEKIND_NODE | SMI_NODEKIND_TABLE |
        SMI_NODEKIND_ROW | SMI_NODEKIND_COLUMN | SMI_NODEKIND_SCALAR |
        SMI_NODEKIND_CAPABILITIES;

    for (i = 0,
             lastSmiNode = NULL,
             smiNode = smiGetFirstNode(smiModule, nodekinds);
         smiNode;
         i++,
             lastSmiNode = smiNode,
             smiNode = smiGetNextNode(smiNode, nodekinds)) {

        if (i == 0) {
            fprintSegment(f, INDENT, "\"nodes\" => [\n", 0);
        }

        fprintNode(f, 2 * INDENT, smiNode, lastSmiNode);
    }

/*      if (lastSmiNode */
/*      && lastSmiNode->nodekind == SMI_NODEKIND_COLUMN) { */
/*      printNodeEndTag(3 * INDENT, "row", smiNode->name); */
/*          printNodeEndTag(2 * INDENT, "table", smiNode->name); */
/*      } */

    if (i) {
        fprintSegment(f, INDENT, "], # nodes\n\n", 0);
    }
}



static void fprintNotification(FILE *f, int indent, SmiNode *smiNode)
{
    fprintNodeStartTag(f, indent, "notification", smiNode);
    fprintDescription(f, indent + INDENT, smiNode->description);
    fprintReference(f, indent + INDENT, smiNode->reference);

    fprintSegment(f, indent + INDENT, "\"objects\" => [\n", 0);
    fprintElementList(f, indent + 2 * INDENT, NULL,
		      smiGetFirstElement(smiNode), 1);
    fprintSegment(f, indent + INDENT, "],\n", 0);

    fprintNodeEndTag(f, indent, "notification", smiNode->name);
}



static void fprintNotifications(FILE *f, SmiModule *smiModule)
{
    SmiNode *smiNode;
    int      i;

    for(i = 0, smiNode = smiGetFirstNode(smiModule, SMI_NODEKIND_NOTIFICATION);
        smiNode;
        i++, smiNode = smiGetNextNode(smiNode, SMI_NODEKIND_NOTIFICATION)) {

        if (i == 0) {
            fprintSegment(f, INDENT, "\"notifications\" => [\n", 0);
        }
        fprintNotification(f, 2 * INDENT, smiNode);
    }

    if (i) {
        fprintSegment(f, INDENT, "], # notifications\n\n", 0);
    }
}



static void fprintGroup(FILE *f, int indent, SmiNode *smiNode)
{
    fprintNodeStartTag(f, indent, "group", smiNode);
    fprintDescription(f, indent + INDENT, smiNode->description);
    fprintReference(f, indent + INDENT, smiNode->reference);

    fprintSegment(f, indent + INDENT, "\"members\" => [\n", 0);
    fprintElementList(f, indent + 2 * INDENT, NULL,
		      smiGetFirstElement(smiNode), 1);
    fprintSegment(f, indent + INDENT, "], # members\n", 0);

    fprintNodeEndTag(f, indent, "group", smiNode->name);
}



static void fprintGroups(FILE *f, SmiModule *smiModule)
{
    SmiNode *smiNode;
    int      i;

    for(i = 0, smiNode = smiGetFirstNode(smiModule, SMI_NODEKIND_GROUP);
        smiNode;
        i++, smiNode = smiGetNextNode(smiNode, SMI_NODEKIND_GROUP)) {

        if (i == 0) {
            fprintSegment(f, INDENT, "\"groups\" => [\n", 0);
        }
        fprintGroup(f, 2 * INDENT, smiNode);
    }

    if (i) {
        fprintSegment(f, INDENT, "], # groups\n\n", 0);
    }
}



static void fprintComplGroups(FILE *f, int indent, SmiNode *smiNode)
{
    SmiNode   *optSmiNode;
    SmiModule *optSmiModule;
    SmiOption *smiOption;

    if (! smiGetFirstElement(smiNode) && !smiGetFirstOption(smiNode)) {
        return;
    }

    fprintSegment(f, indent, "\"requires\" => [\n", 0);
    fprintElementList(f, indent + INDENT, "mandatory",
		      smiGetFirstElement(smiNode), 1);

    for(smiOption = smiGetFirstOption(smiNode);
        smiOption;
        smiOption = smiGetNextOption(smiOption)) {
        optSmiNode = smiGetOptionNode(smiOption);
        optSmiModule = smiGetNodeModule(optSmiNode);
        fprintSegment(f, indent + INDENT, "", 0);
        fprint(f, "\"%s\" => {\n", optSmiNode->name);
        fprintSegment(f, indent + 2*INDENT, "\"type\" => \"optional\",\n", 0);
        fprintSegment(f, indent + 2*INDENT, "", 0);
        fprint(f, "\"module\" => \"%s\",\n", optSmiModule->name);
        fprintDescription(f, indent + 2 * INDENT, smiOption->description);
        fprintSegment(f, indent + INDENT, "},\n", 0);
    }

    fprintSegment(f, indent, "], # requires\n", 0);
}



static void fprintRefinement(FILE *f, int indent, SmiRefinement *smiRefinement)
{
    SmiModule *smiModule;
    SmiNode   *smiNode;
    SmiType   *smiType;

    smiNode = smiGetRefinementNode(smiRefinement);
    smiModule = smiGetNodeModule(smiNode);

    fprintSegment(f, indent, "", 0);
    fprint(f, "\"%s\" => {\n", smiNode->name);
    fprintSegment(f, indent + INDENT, "", 0);
    fprint(f, "\"module\" => \"%s\",\n", smiModule->name);

    smiType = smiGetRefinementType(smiRefinement);
    if (smiType) {
        fprintSegment(f, indent + INDENT, "\"syntax\" => {\n", 0);
        fprintSegment(f, indent + 2*INDENT, "\"type\" => ", 0);
        fprintTypedef(f, indent + 2 * INDENT, smiType);
        fprintSegment(f, indent + INDENT, "},\n", 0);
    }

    smiType = smiGetRefinementWriteType(smiRefinement);
    if (smiType) {
        fprintSegment(f, indent + INDENT, "\"writesyntax\" => {\n", 0);
        fprintSegment(f, indent + 2*INDENT, "\"type\" => ", 0);
        fprintTypedef(f, indent + 2 * INDENT, smiType);
        fprintSegment(f, indent + INDENT, "},\n", 0);
    }

    if (smiRefinement->access != SMI_ACCESS_UNKNOWN) {
        fprintAccess(f, indent + INDENT, smiRefinement->access);
    }
    fprintDescription(f, indent + INDENT, smiRefinement->description);
    fprintSegment(f, indent, "},\n", 0);
}



static void fprintRefinements(FILE *f, int indent, SmiNode *smiNode)
{
    SmiRefinement *smiRefinement;
    int            i;

    for(i = 0, smiRefinement = smiGetFirstRefinement(smiNode);
        smiRefinement;
        i++, smiRefinement = smiGetNextRefinement(smiRefinement)) {

        if (!i) {
            fprintSegment(f, indent, "\"refinements\" => {\n", 0);
        }

        fprintRefinement(f, indent + INDENT, smiRefinement);
    }

    if (i) {
        fprintSegment(f, indent, "}, # refinements\n\n", 0);
    }
}



static void fprintCompliance(FILE *f, int indent, SmiNode *smiNode)
{
    fprintNodeStartTag(f, indent, "compliance", smiNode);
    fprintDescription(f, indent + INDENT, smiNode->description);
    fprintReference(f, indent + INDENT, smiNode->reference);

    fprintComplGroups(f, indent + INDENT, smiNode);
    fprintRefinements(f, indent + INDENT, smiNode);

    fprintNodeEndTag(f, indent, "compliance", smiNode->name);
}



static void fprintCompliances(FILE *f, SmiModule *smiModule)
{
    SmiNode *smiNode;
    int      i;

    for(i = 0, smiNode = smiGetFirstNode(smiModule, SMI_NODEKIND_COMPLIANCE);
        smiNode;
        i++, smiNode = smiGetNextNode(smiNode, SMI_NODEKIND_COMPLIANCE)) {

        if (!i) {
            fprintSegment(f, INDENT, "\"compliances\" => [\n", 0);
        }

        fprintCompliance(f, 2 * INDENT, smiNode);
    }

    if (i) {
        fprintSegment(f, INDENT, "], # compliances\n\n", 0);
    }
}



static void dumpPerlModule(FILE *f, SmiModule *smiModule)
{
    char *lang;

    fprint(f, "# Perl version 5\t\t\t\t\t\tDO NOT EDIT\n#\n");
    fprint(f, "# Generated by smidump " SMI_VERSION_STRING ":\n#\n");
    fprintf(f, "#   smidump -f perl %s\n\n", smiModule->name);
    
    fprint(f, "{\n");
    
    fprint(f, "\"%s\" => {\n", smiModule->name);
    fprintSegment(f, INDENT, "", 0);
    fprint(f, "\"name\" => \"%s\",\n\n", smiModule->name);
    
    fprintSegment(f, INDENT, "#    Compiler Info\n", 0);
    fprint(f, "");
    fprintSegment(f, INDENT, "", 0);
    fprint(f, "\"path\" => \"%s\",\n", smiModule->path);
    
    lang = getStringLanguage(smiModule->language);
    if (lang) {
	fprintSegment(f, INDENT, "", 0);
	fprint(f, "\"language\" => \"%s\",\n", lang);
    }
    
    fprint(f, "\n");
    fprintSegment(f, INDENT, "#    Module Identity\n", 0);
    fprintModule(f, smiModule);
    
    fprintSegment(f, INDENT, "#    Imports\n", 0);
    fprintImports(f, smiModule);
    fprintSegment(f, INDENT, "#    Module Body\n", 0);
    fprintTypedefs(f, smiModule);
    fprintNodes(f, smiModule);
    fprintNotifications(f, smiModule);
    fprintGroups(f, smiModule);
    fprintCompliances(f, smiModule);
    
    fprint(f, "  } # %s\n", smiModule->name);
    fprint(f, "};\n");
}



static void dumpPerl(int modc, SmiModule **modv, int flags, char *output)
{
    int  i;
    FILE *f = stdout;

    if (output) {
        f = fopen(output, "w");
        if (!f) {
            fprintf(stderr, "smidump: cannot open %s for writing: ", output);
            perror(NULL);
            exit(1);
        }
    }

    for (i = 0; i < modc; i++) {
	dumpPerlModule(f, modv[i]);
    }

    if (fflush(f) || ferror(f)) {
	perror("smidump: write error");
	exit(1);
    }

    if (output) {
        fclose(f);
    }
}



void initPerl()
{
    static SmidumpDriver driver = {
        "perl",
        dumpPerl,
        0,
        SMIDUMP_DRIVER_CANT_UNITE
	| SMIDUMP_DRIVER_CANT_YANG,
        "Perl MIB dictionaries",
        NULL,
        NULL
    };

    smidumpRegisterDriver(&driver);
}
