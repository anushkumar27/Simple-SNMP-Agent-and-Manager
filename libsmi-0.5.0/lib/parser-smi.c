/* A Bison parser, made by GNU Bison 2.7.12-4996.  */

/* Bison implementation for Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2013 Free Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.
   
   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.7.12-4996"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 1

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1


/* Substitute the variable and function names.  */
#define yyparse         smiparse
#define yylex           smilex
#define yyerror         smierror
#define yylval          smilval
#define yychar          smichar
#define yydebug         smidebug
#define yynerrs         sminerrs

/* Copy the first part of user declarations.  */
/* Line 371 of yacc.c  */
#line 17 "parser-smi.y"


#include <config.h>
    
#ifdef BACKEND_SMI

#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <limits.h>

#if defined(_MSC_VER)
#include <malloc.h>
#endif

#include "smi.h"
#include "error.h"
#include "parser-smi.h"
#include "scanner-smi.h"
#include "smi-data.h"
#include "smi-check.h"
#include "util.h"
    
#ifdef HAVE_DMALLOC_H
#include <dmalloc.h>
#endif


#define thisParserPtr      ((Parser *)parserPtr)
#define thisModulePtr     (((Parser *)parserPtr)->modulePtr)


    
/*
 * NOTE: The argument lvalp is not really a void pointer. Unfortunately,
 * we don't know it better at this point. bison generated C code declares
 * YYSTYPE just a few lines below based on the `%union' declaration.
 */
extern int yylex(void *lvalp, Parser *parserPtr);



static int	   impliedFlag;
static SmiNodekind variationkind;
static SmiBasetype defaultBasetype;
static int	   indexFlag;

/*
 * Values for the indexFlag variable
 */
#define INDEXFLAG_NONE     0
#define INDEXFLAG_PIBINDEX 1
#define INDEXFLAG_AUGMENTS 2
#define INDEXFLAG_EXTENDS  3
 

#define SMI_EPOCH	631152000	/* 01 Jan 1990 00:00:00 */ 

 

static char *convertImportv2[] = {
    "RFC1155-SMI", "internet",	    "SNMPv2-SMI", "internet",
    "RFC1155-SMI", "directory",	    "SNMPv2-SMI", "directory",
    "RFC1155-SMI", "mgmt",	    "SNMPv2-SMI", "mgmt",
    "RFC1155-SMI", "experimental",  "SNMPv2-SMI", "experimental",
    "RFC1155-SMI", "private",	    "SNMPv2-SMI", "private",
    "RFC1155-SMI", "enterprises",   "SNMPv2-SMI", "enterprises",
    "RFC1155-SMI", "IpAddress",     "SNMPv2-SMI", "IpAddress",
    "RFC1155-SMI", "Counter",       "SNMPv2-SMI", "Counter32",
    "RFC1155-SMI", "Gauge",         "SNMPv2-SMI", "Gauge32",
    "RFC1155-SMI", "TimeTicks",     "SNMPv2-SMI", "TimeTicks",
    "RFC1155-SMI", "Opaque",        "SNMPv2-SMI", "Opaque",
    "RFC1065-SMI", "internet",	    "SNMPv2-SMI", "internet",
    "RFC1065-SMI", "directory",	    "SNMPv2-SMI", "directory",
    "RFC1065-SMI", "mgmt",	    "SNMPv2-SMI", "mgmt",
    "RFC1065-SMI", "experimental",  "SNMPv2-SMI", "experimental",
    "RFC1065-SMI", "private",	    "SNMPv2-SMI", "private",
    "RFC1065-SMI", "enterprises",   "SNMPv2-SMI", "enterprises",
    "RFC1065-SMI", "IpAddress",     "SNMPv2-SMI", "IpAddress",
    "RFC1065-SMI", "Counter",       "SNMPv2-SMI", "Counter32",
    "RFC1065-SMI", "Gauge",         "SNMPv2-SMI", "Gauge32",
    "RFC1065-SMI", "TimeTicks",     "SNMPv2-SMI", "TimeTicks",
    "RFC1065-SMI", "Opaque",        "SNMPv2-SMI", "Opaque",
    "RFC1213-MIB", "mib-2",         "SNMPv2-SMI", "mib-2",    
    "RFC1213-MIB", "DisplayString", "SNMPv2-TC",  "DisplayString",    
    NULL, NULL, NULL, NULL
};



static void
checkDescr(Parser *parser, char *descr)
{
    if (descr) {
	if (descr[0] == 0) {
	    smiPrintError(parser, ERR_EMPTY_DESCRIPTION);
	}
	/* we might want to add more checks since I have recently
	   seen things like DESCRIPTION "." to cirumvent warnings */
    }
}
 

 
static void
checkNameLen(Parser *parser, char *name, int error_32, int error_64)
{
    int len = strlen(name);
    
    if (len > 64) {
	smiPrintError(parser, error_64, name);
    } else if (len > 32) {
	smiPrintError(parser, error_32, name);
    }
}


 
static void
checkModuleName(Parser *parserPtr, Module *modulePtr)
{
     static char *mib_ignore[] = {
	 "SNMPv2-SMI", "SNMPv2-TC", "SNMPv2-CONF", NULL
     };
     
     static char *pib_ignore[] = {
	 "COPS-PR-SPPI", "COPS-PR-SPPI-TC",
	 "SNMPv2-SMI", "SNMPv2-TC", "SNMPv2-CONF", NULL
     };

     const char *name = thisModulePtr->export.name;
     const int len = strlen(name);
     int i;

     switch (modulePtr->export.language) {
     case SMI_LANGUAGE_SMIV1:
     case SMI_LANGUAGE_SMIV2:
     case SMI_LANGUAGE_SMING:
	 for (i = 0; mib_ignore[i]; i++) {
	     if (strcmp(mib_ignore[i], name) == 0) {
		 return;
	     }
	 }
	 if (len > 3 && (strcmp(name + len - 4, "-MIB") != 0)) {
	     smiPrintError(parserPtr, ERR_MIB_MODULENAME_SUFFIX, name);
	     return;
	 }
	 break;
     case SMI_LANGUAGE_SPPI:
	 for (i = 0; pib_ignore[i]; i++) {
	     if (strcmp(pib_ignore[i], name) == 0) {
		 return;
	     }
	 }
	 if (len > 3 && (strcmp(name + len - 4, "-PIB") != 0)) {
	     smiPrintError(parserPtr, ERR_PIB_MODULENAME_SUFFIX, name);
	 }
	 break;
     case SMI_LANGUAGE_YANG:
     case SMI_LANGUAGE_UNKNOWN:
	 break;
     }
}



static void
checkModuleIdentity(Parser *parserPtr, Module *modulePtr)
{
    if ((modulePtr->export.language == SMI_LANGUAGE_SMIV2)
	&& (modulePtr->numModuleIdentities < 1)
	&& strcmp(modulePtr->export.name, "SNMPv2-SMI")
	&& strcmp(modulePtr->export.name, "SNMPv2-CONF")
	&& strcmp(modulePtr->export.name, "SNMPv2-TC")
        && strcmp(modulePtr->export.name, "COPS-PR-SPPI")) {
	smiPrintError(parserPtr, ERR_NO_MODULE_IDENTITY);
    }
}



static void
checkObjects(Parser *parserPtr, Module *modulePtr)
{
    Object *objectPtr;
    Node *nodePtr;
    int i;
    Type *counterTypePtr, *counter32TypePtr, *counter64TypePtr;
    
    counterTypePtr = findTypeByName("Counter");
    counter32TypePtr = findTypeByModulenameAndName("SNMPv2-SMI", "Counter32");
    counter64TypePtr = findTypeByModulenameAndName("SNMPv2-SMI", "Counter64");
    
    for (objectPtr = modulePtr->firstObjectPtr;
	 objectPtr; objectPtr = objectPtr->nextPtr) {

	Object *parentPtr;
	
	if ((objectPtr->export.decl != SMI_DECL_UNKNOWN) &&
	    objectPtr->nodePtr->parentPtr &&
	    objectPtr->nodePtr->parentPtr->lastObjectPtr) {
	    parentPtr = objectPtr->nodePtr->parentPtr->lastObjectPtr;
	} else {
	    parentPtr = NULL;
	}

	/*
	 * Set nodekinds of all newly defined objects.
	 */
	
	if (objectPtr->export.decl == SMI_DECL_MODULEIDENTITY) {
	    objectPtr->export.nodekind = SMI_NODEKIND_NODE;
	} else if ((objectPtr->export.decl == SMI_DECL_VALUEASSIGNMENT) ||
		   (objectPtr->export.decl == SMI_DECL_OBJECTIDENTITY)) {
	    objectPtr->export.nodekind = SMI_NODEKIND_NODE;
	} else if ((objectPtr->export.decl == SMI_DECL_OBJECTTYPE) &&
		   (objectPtr->typePtr) &&
		   (objectPtr->typePtr->export.decl == SMI_DECL_IMPL_SEQUENCEOF)) {
	    objectPtr->export.nodekind = SMI_NODEKIND_TABLE;
	} else if ((objectPtr->export.decl == SMI_DECL_OBJECTTYPE) &&
		   ((objectPtr->export.indexkind != SMI_INDEX_UNKNOWN)
		    || (parentPtr
			&& parentPtr->export.nodekind == SMI_NODEKIND_TABLE))) {
	    objectPtr->export.nodekind = SMI_NODEKIND_ROW;
	} else if ((objectPtr->export.decl == SMI_DECL_NOTIFICATIONTYPE) ||
		   (objectPtr->export.decl == SMI_DECL_TRAPTYPE)) {
	    objectPtr->export.nodekind = SMI_NODEKIND_NOTIFICATION;
	} else if ((objectPtr->export.decl == SMI_DECL_OBJECTGROUP) ||
		   (objectPtr->export.decl == SMI_DECL_NOTIFICATIONGROUP)) {
	    objectPtr->export.nodekind = SMI_NODEKIND_GROUP;
	} else if (objectPtr->export.decl == SMI_DECL_MODULECOMPLIANCE) {
	    objectPtr->export.nodekind = SMI_NODEKIND_COMPLIANCE;
	} else if (objectPtr->export.decl == SMI_DECL_AGENTCAPABILITIES) {
	    objectPtr->export.nodekind = SMI_NODEKIND_CAPABILITIES;
	} else if ((objectPtr->export.decl == SMI_DECL_OBJECTTYPE) &&
		   (parentPtr) &&
		   ((parentPtr->export.indexkind != SMI_INDEX_UNKNOWN)
		    || (parentPtr
			&& parentPtr->export.nodekind == SMI_NODEKIND_ROW))) {
	    objectPtr->export.nodekind = SMI_NODEKIND_COLUMN;
	} else if ((objectPtr->export.decl == SMI_DECL_OBJECTTYPE) &&
		   (parentPtr) &&
		   (parentPtr->export.indexkind == SMI_INDEX_UNKNOWN)) {
	    objectPtr->export.nodekind = SMI_NODEKIND_SCALAR;
	}
    }

    for (objectPtr = modulePtr->firstObjectPtr;
	 objectPtr; objectPtr = objectPtr->nextPtr) {

	Object *parentPtr;
	
	if (objectPtr->nodePtr->parentPtr &&
	    objectPtr->nodePtr->parentPtr->lastObjectPtr) {
	    parentPtr = objectPtr->nodePtr->parentPtr->lastObjectPtr;
	} else {
	    parentPtr = NULL;
	}

	/*
	 * Check whether the associated type resolves to a known base type.
	 */
	
	if (objectPtr->typePtr
	    && (objectPtr->export.nodekind == SMI_NODEKIND_COLUMN
		|| objectPtr->export.nodekind == SMI_NODEKIND_SCALAR)
	    && objectPtr->typePtr->export.basetype == SMI_BASETYPE_UNKNOWN) {
	    smiPrintErrorAtLine(parserPtr, ERR_BASETYPE_UNKNOWN,
				objectPtr->line,
				objectPtr->typePtr->export.name ?
				objectPtr->typePtr->export.name : "[unknown]",
				objectPtr->export.name);
	}

	/*
	 * Mark types that are referenced in this module.
	 */

	if (objectPtr->typePtr
	    && (objectPtr->export.nodekind == SMI_NODEKIND_COLUMN
		|| objectPtr->export.nodekind == SMI_NODEKIND_SCALAR)
	    && (objectPtr->typePtr->export.decl == SMI_DECL_TYPEDEF
		|| objectPtr->typePtr->export.decl == SMI_DECL_TEXTUALCONVENTION
		|| objectPtr->typePtr->export.decl == SMI_DECL_IMPLICIT_TYPE)) {
	    addTypeFlags(objectPtr->typePtr, FLAG_INSYNTAX);
	    if (objectPtr->typePtr->export.decl == SMI_DECL_IMPLICIT_TYPE) {
		addTypeFlags(objectPtr->typePtr->parentPtr, FLAG_INSYNTAX);
	    }
	}
	
	/*
	 * Check whether the status of the associated type matches the
	 * status of the object.
	 */

	if (objectPtr->typePtr
	    && (objectPtr->export.nodekind == SMI_NODEKIND_COLUMN
		|| objectPtr->export.nodekind == SMI_NODEKIND_SCALAR)
	    && (objectPtr->export.status < objectPtr->typePtr->export.status)) {
	    if (objectPtr->typePtr->export.status == SMI_STATUS_DEPRECATED) {
		smiPrintErrorAtLine(parserPtr, ERR_TYPE_STATUS_DEPRECATED,
				    objectPtr->line,
				    objectPtr->typePtr->export.name,
				    objectPtr->export.name);
	    }
	    if (objectPtr->typePtr->export.status == SMI_STATUS_OBSOLETE) {
		smiPrintErrorAtLine(parserPtr, ERR_TYPE_STATUS_OBSOLETE,
				    objectPtr->line,
				    objectPtr->typePtr->export.name,
				    objectPtr->export.name);
	    }
	}

	/*
	 * Check the nodekind of the parent node.
	 */

	if (parentPtr) {
	    switch (objectPtr->export.nodekind) {
	    case SMI_NODEKIND_COLUMN:
		if (parentPtr->export.nodekind != SMI_NODEKIND_ROW) {
		    smiPrintErrorAtLine(parserPtr, ERR_COLUMN_PARENT_TYPE,
					objectPtr->line, objectPtr->export.name);
		}
		break;
	    case SMI_NODEKIND_ROW:
		if (parentPtr->export.nodekind != SMI_NODEKIND_TABLE) {
		    smiPrintErrorAtLine(parserPtr, ERR_ROW_PARENT_TYPE,
					objectPtr->line, objectPtr->export.name);
		}
		if (parentPtr->typePtr && parentPtr->typePtr->parentPtr &&
		    strcmp(parentPtr->typePtr->parentPtr->export.name,
			   objectPtr->typePtr->export.name)) {
		    smiPrintErrorAtLine(parserPtr, ERR_TABLE_ROW_TYPE_MISMATCH,
					objectPtr->line,
					objectPtr->export.name);
		}
		break;
	    case SMI_NODEKIND_TABLE:
		if ((parentPtr->export.nodekind != SMI_NODEKIND_UNKNOWN) &&
		    (parentPtr->export.nodekind != SMI_NODEKIND_NODE)) {
		    smiPrintErrorAtLine(parserPtr, ERR_TABLE_PARENT_TYPE,
					objectPtr->line, objectPtr->export.name);
		}
		break;
	    case SMI_NODEKIND_SCALAR:
		if ((parentPtr->export.nodekind != SMI_NODEKIND_UNKNOWN) &&
		    (parentPtr->export.nodekind != SMI_NODEKIND_NODE)) {
		    smiPrintErrorAtLine(parserPtr, ERR_SCALAR_PARENT_TYPE,
					objectPtr->line, objectPtr->export.name);
		}
		break;
	    case SMI_NODEKIND_NOTIFICATION:
		if ((parentPtr->export.nodekind != SMI_NODEKIND_NODE) &&
		    (parentPtr->export.nodekind != SMI_NODEKIND_UNKNOWN)) {
		    smiPrintErrorAtLine(parserPtr, ERR_NOTIFICATION_PARENT_TYPE,
					objectPtr->line, objectPtr->export.name);
		}
		if (parserPtr && parentPtr->nodePtr->parentPtr &&
		    parentPtr->nodePtr->parentPtr->lastObjectPtr) {
		    Object *parent2Ptr = parentPtr->nodePtr->parentPtr->lastObjectPtr;
		    if ((parent2Ptr->export.nodekind != SMI_NODEKIND_NODE) &&
			(parent2Ptr->export.nodekind != SMI_NODEKIND_UNKNOWN)) {
			smiPrintErrorAtLine(parserPtr,
					    ERR_NOTIFICATION_PARENT_TYPE,
					    objectPtr->line,
					    objectPtr->export.name);
		    }
		}
		break;
	    case SMI_NODEKIND_NODE:
		/* Node defined by OBJECT IDENTIFIER assignments can have
		   arbitrary parent node. */
		if ((parentPtr->export.nodekind != SMI_NODEKIND_UNKNOWN) &&
		    (parentPtr->export.nodekind != SMI_NODEKIND_NODE) &&
		    (objectPtr->export.decl != SMI_DECL_VALUEASSIGNMENT)) {
		    smiPrintErrorAtLine(parserPtr, ERR_NODE_PARENT_TYPE,
					objectPtr->line, objectPtr->export.name);
		}
		break;
	    case SMI_NODEKIND_GROUP:
		if ((parentPtr->export.nodekind != SMI_NODEKIND_UNKNOWN) &&
		    (parentPtr->export.nodekind != SMI_NODEKIND_NODE)) {
		    smiPrintErrorAtLine(parserPtr, ERR_GROUP_PARENT_TYPE,
					objectPtr->line, objectPtr->export.name);
		}
		break;
	    case SMI_NODEKIND_COMPLIANCE:
		if ((parentPtr->export.nodekind != SMI_NODEKIND_UNKNOWN) &&
		    (parentPtr->export.nodekind != SMI_NODEKIND_NODE)) {
		    smiPrintErrorAtLine(parserPtr, ERR_COMPLIANCE_PARENT_TYPE,
					objectPtr->line, objectPtr->export.name);
		}
		break;
	    case SMI_NODEKIND_CAPABILITIES:
		if ((parentPtr->export.nodekind != SMI_NODEKIND_UNKNOWN) &&
		    (parentPtr->export.nodekind != SMI_NODEKIND_NODE)) {
		    smiPrintErrorAtLine(parserPtr, ERR_CAPABILITIES_PARENT_TYPE,
					objectPtr->line, objectPtr->export.name);
		}
		break;
	    }
	}

	/*
	 * Check whether a row has only object-type children and
	 * that their types are consistent with the type of the
	 * row.
	 */

	if (objectPtr->export.nodekind == SMI_NODEKIND_ROW) {
	    smiCheckRowMembers(parserPtr, objectPtr);
	}
	
	/*
	 * Check whether groups only contain scalars, columns and
	 * notifications.
	 */

	if (objectPtr->export.nodekind == SMI_NODEKIND_GROUP) {
	    smiCheckGroupMembers(parserPtr, objectPtr);
	}

	/*
	 * Check whether compliance statements contain out of date
	 * groups or objects.
	 */

	if (objectPtr->export.nodekind == SMI_NODEKIND_COMPLIANCE) {
	    smiCheckComplianceStatus(parserPtr, objectPtr);
	}

	/*
	 * Check whether notification statements contain useful
	 * objects.
	 */

	if (objectPtr->export.nodekind == SMI_NODEKIND_NOTIFICATION) {
	    smiCheckNotificationOid(parserPtr, modulePtr, objectPtr);
	    smiCheckNotificationMembers(parserPtr, objectPtr);
	}

        if (modulePtr->export.language != SMI_LANGUAGE_SPPI) {
	    /*
	     * Check whether tables and rows are not accessible
	     * (RFC 2578 7.1.12).
	     */

	    if (objectPtr->export.nodekind == SMI_NODEKIND_TABLE
	        && objectPtr->export.access != SMI_ACCESS_NOT_ACCESSIBLE) {
	        smiPrintErrorAtLine(parserPtr, ERR_TABLE_ACCESS,
				    objectPtr->line, objectPtr->export.name);
	    }

	    if (objectPtr->export.nodekind == SMI_NODEKIND_ROW
	        && objectPtr->export.access != SMI_ACCESS_NOT_ACCESSIBLE) {
	        smiPrintErrorAtLine(parserPtr, ERR_ROW_ACCESS,
				    objectPtr->line, objectPtr->export.name);
	    }

	    /*
	     * Check whether counter objects are read-only or
	     * accessible-for-notify (RFC 2578, 7.1.6).
	     */
	    if (((objectPtr->export.nodekind == SMI_NODEKIND_SCALAR) ||
		 (objectPtr->export.nodekind == SMI_NODEKIND_COLUMN)) &&
	        (objectPtr->export.access != SMI_ACCESS_NOTIFY) &&
		(objectPtr->export.access != SMI_ACCESS_READ_ONLY) &&
		(smiTypeDerivedFrom(objectPtr->typePtr, counterTypePtr) ||
		 smiTypeDerivedFrom(objectPtr->typePtr, counter32TypePtr) ||
		 smiTypeDerivedFrom(objectPtr->typePtr, counter64TypePtr))) {
	        smiPrintErrorAtLine(parserPtr, ERR_COUNTER_ACCESS,
				    objectPtr->line, objectPtr->export.name);
	    }
        }
	
	/*
	 * Check whether a row's subid is 1, see RFC 2578 7.10 (1).
	 */
	
	if (objectPtr->export.nodekind == SMI_NODEKIND_ROW) {
	    int len;
	    
	    if (objectPtr->nodePtr->subid != 1) {
		smiPrintErrorAtLine(parserPtr, ERR_ROW_SUBID_ONE,
				    objectPtr->line, objectPtr->export.name);
	    }

	    len = strlen(objectPtr->export.name);
	    if (len < 6 || strcmp(objectPtr->export.name+len-5, "Entry")) {
		smiPrintErrorAtLine(parserPtr, ERR_ROWNAME_ENTRY,
				    objectPtr->line, objectPtr->export.name);
	    } else {

		/*
		 * This misreports some cases where the table name
		 * does not have the "*Table" suffix.  This is trying
		 * to allow Entry names of either fooTableEntry or
		 * fooEntry.
		 */
		if (parentPtr &&
		    !(((int)strlen(parentPtr->export.name) == len ||
		       (int)strlen(parentPtr->export.name) == len - 5) &&
		      !strncmp(objectPtr->export.name, parentPtr->export.name,
			len - 5))) {
		    smiPrintErrorAtLine(parserPtr, ERR_ROWNAME_TABLENAME,
					objectPtr->line,
					objectPtr->export.name,
					parentPtr->export.name);
		}
	    }
	}

	/*
	 * Check whether a row's SEQUENCE contains exactly the list
	 * of child nodes (columns).  An unknown SEQUENCE type
	 * is handled later.
	 */

	if (objectPtr->export.nodekind == SMI_NODEKIND_ROW &&
	    ((objectPtr->typePtr->flags & FLAG_INCOMPLETE) == 0)) {
	    List *p;
	    Node *seqNodePtr, *childNodePtr;
	    Object *colPtr;
	    int i;
	    
	    /*
	     * Walk through the SEQUENCE elements and find those
	     * that are misordered or have no matching columnar object.
	     */
	    for (p = objectPtr->typePtr->listPtr, i = 1,
		     childNodePtr = objectPtr->nodePtr->firstChildPtr;
		 p && childNodePtr;
		 p = p->nextPtr, childNodePtr = childNodePtr->nextPtr, i++) {
		seqNodePtr = ((Object *)p->ptr)->nodePtr;

		if (seqNodePtr->parentPtr != childNodePtr->parentPtr) {
		    smiPrintErrorAtLine(parserPtr, ERR_SEQUENCE_NO_COLUMN,
					objectPtr->typePtr->line,
					i,
					((Object *)p->ptr)->export.name,
					objectPtr->export.name);
		    continue;
		}

		if (seqNodePtr != childNodePtr) {
		    smiPrintErrorAtLine(parserPtr, ERR_SEQUENCE_ORDER,
					objectPtr->typePtr->line,
					i,
					((Object *)p->ptr)->export.name,
					objectPtr->export.name);
		    break;
		}
	    }
	    if ((p != NULL) && (childNodePtr == NULL)) {
		smiPrintErrorAtLine(parserPtr, ERR_SEQUENCE_NO_COLUMN,
				    objectPtr->typePtr->line,
				    i, 
				    ((Object *)p->ptr)->export.name,
				    objectPtr->export.name);
	    }

	    /*
	     * Walk through all child objects and find those
	     * that were missing in the SEQUENCE.
	     */
	    for (childNodePtr = objectPtr->nodePtr->firstChildPtr;
		 childNodePtr; childNodePtr = childNodePtr->nextPtr) {
		colPtr = findObjectByModuleAndNode(modulePtr, childNodePtr);
		if (!colPtr) continue;
		for (p = objectPtr->typePtr->listPtr; p; p = p->nextPtr) {
		    if (((Object *)p->ptr)->nodePtr == colPtr->nodePtr)
			break;
		}
		if (!p) {
		    if (colPtr->export.name) {
			/*
			 * Don't complain, if it's an implcitly defined
			 * unnamed node (could happen for parent node of
			 * TRAP-TYPE definitions).
			 */
			smiPrintErrorAtLine(parserPtr,
					    ERR_SEQUENCE_MISSING_COLUMN,
					    objectPtr->typePtr->line,
					    objectPtr->typePtr->export.name,
					    colPtr->export.name);
		    }
		}
	    }
	    
	}
	
	if (objectPtr->export.nodekind == SMI_NODEKIND_TABLE) {
	    int len;

	    len = strlen(objectPtr->export.name);
	    if (len < 6 || strcmp(objectPtr->export.name+len-5, "Table")) {
		smiPrintErrorAtLine(parserPtr, ERR_TABLENAME_TABLE,
				    objectPtr->line, objectPtr->export.name);
	    }
	}

	/*
	 * TODO: check whether the row is the only node below the
         * table node
	 */

	/*
	 * Check references to unknown identifiers.
	 */

	if ((objectPtr->flags & FLAG_INCOMPLETE) &&
	    (objectPtr->export.decl != SMI_DECL_IMPL_OBJECT)) {
	    if (objectPtr->export.name) {
		smiPrintErrorAtLine(parserPtr, ERR_UNKNOWN_OIDLABEL,
				    objectPtr->line, objectPtr->export.name);
	    } else {
		smiPrintErrorAtLine(parserPtr, ERR_IMPLICIT_NODE,
				    objectPtr->line);
	    }
	}

	/*
	 * Adjust the status of implicit type definitions.
	 */
	
	if (objectPtr->typePtr
	    && (objectPtr->typePtr->export.decl == SMI_DECL_IMPLICIT_TYPE)
	    && (objectPtr->typePtr->export.status == SMI_STATUS_UNKNOWN)) {
	    objectPtr->typePtr->export.status = objectPtr->export.status;
	}

	/*
	 * Link implicit type definition from refinements into
	 * the type derivation tree. Adjust the status of implicit
	 * type definitions in refinements. 
	 */

	if (objectPtr->export.nodekind == SMI_NODEKIND_COMPLIANCE) {

	    List *listPtr;

	    for (listPtr = objectPtr->refinementlistPtr;
		 listPtr;
		 listPtr = listPtr->nextPtr) {

		Refinement *refinementPtr;
		Type *typePtr;
		
		refinementPtr = ((Refinement *)(listPtr->ptr));
		typePtr = refinementPtr->typePtr;
		if (typePtr) {
		    if (typePtr->export.status == SMI_STATUS_UNKNOWN) {
			typePtr->export.status = objectPtr->export.status;
		    }
		}

		typePtr = refinementPtr->writetypePtr;
		if (typePtr) {
		    if (typePtr->export.status == SMI_STATUS_UNKNOWN) {
			typePtr->export.status = objectPtr->export.status;
		    }
		}
		
	    }
	    /* relocate the refinement type into the type tree */
	    /* relocate the write refinement type into the type tree */
	}

	/*
	 * Set the oidlen/oid values that are not yet correct.
	 */

	if (objectPtr->export.oidlen == 0) {
	    if (objectPtr->nodePtr->oidlen == 0) {
		for (nodePtr = objectPtr->nodePtr, i = 1;
		     nodePtr->parentPtr != thisParserPtr->pendingNodePtr &&
			 nodePtr->parentPtr != smiHandle->rootNodePtr &&
			 nodePtr != nodePtr->parentPtr &&
			 nodePtr->parentPtr != NULL &&
			 i <= 128;
		     nodePtr = nodePtr->parentPtr, i++);
		if ((objectPtr->export.name) &&
		    ((i > 128) || (nodePtr == nodePtr->parentPtr))) {
		    smiPrintErrorAtLine(parserPtr, ERR_OID_RECURSIVE,
					objectPtr->line,
					objectPtr->export.name);
		}
		objectPtr->nodePtr->oid = smiMalloc(i * sizeof(SmiSubid));
		objectPtr->nodePtr->oidlen = i;
		for (nodePtr = objectPtr->nodePtr; i > 0; i--) {
		    objectPtr->nodePtr->oid[i-1] = nodePtr->subid;
		    nodePtr = nodePtr->parentPtr;
		}
	    }
	    objectPtr->export.oidlen = objectPtr->nodePtr->oidlen;
	    objectPtr->export.oid = objectPtr->nodePtr->oid;
	}

	if ((objectPtr->export.decl != SMI_DECL_UNKNOWN)
	    && (objectPtr->export.nodekind != SMI_NODEKIND_NODE)
	    && (objectPtr->export.nodekind != SMI_NODEKIND_UNKNOWN)
	    && objectPtr->export.name
	    && objectPtr->export.oid[objectPtr->export.oidlen-1] == 0
	    && objectPtr->export.oidlen != 2 && objectPtr->export.oid[0] != 0) {
	    smiPrintErrorAtLine(parserPtr, ERR_OID_ADMIN_ZERO,
				objectPtr->line,
				objectPtr->export.name);
	}

	/*
	 * Check whether the module identity is registered in a well
	 * known controlled location. 
	 */

	if (objectPtr->export.decl == SMI_DECL_MODULEIDENTITY) {
	    smiCheckModuleIdentityRegistration(parserPtr, objectPtr);
	}

	/*
	 * Check table linkage constraints for row objects.
	 */

	if (objectPtr->export.nodekind == SMI_NODEKIND_ROW) {
	    switch (objectPtr->export.indexkind) {
	    case SMI_INDEX_INDEX:
		smiCheckIndex(parserPtr, objectPtr);
		break;
	    case SMI_INDEX_AUGMENT:
            case SMI_INDEX_SPARSE:
		smiCheckAugment(parserPtr, objectPtr);
		break;
	    case SMI_INDEX_UNKNOWN:
		smiPrintErrorAtLine(parserPtr, ERR_INDEX_MISSING,
				    objectPtr->line,
				    objectPtr->export.name);
		break;
	    default:
		break;
	    }
	}
	
	/*
	 * Determine the longest common OID prefix of all nodes.
	 */

	if (!modulePtr->prefixNodePtr) {
	    modulePtr->prefixNodePtr = objectPtr->nodePtr;
	} else {
	    if (objectPtr->nodePtr->oidlen < modulePtr->prefixNodePtr->oidlen) {
		Node *nodePtr = findNodeByOid(objectPtr->nodePtr->oidlen,
					      modulePtr->prefixNodePtr->oid);
		if (nodePtr)
		    modulePtr->prefixNodePtr = nodePtr;
		else
		    smiPrintError(parserPtr, ERR_OTHER_ERROR,
				  "Failed to create complete object tree - "
				  "expect incorrect output");
	    }
	    for (i = 0; i < modulePtr->prefixNodePtr->oidlen; i++) {
		if (modulePtr->prefixNodePtr->oid[i] !=
		    objectPtr->nodePtr->oid[i]) {
		    modulePtr->prefixNodePtr =
			findNodeByOid(i, modulePtr->prefixNodePtr->oid);
		    break;
		}
	    }
	}
    }

    if (modulePtr->export.language == SMI_LANGUAGE_SMIV2) {
	for (objectPtr = modulePtr->firstObjectPtr;
	     objectPtr; objectPtr = objectPtr->nextPtr) {
	    
	    /*
	     * Check whether all objects and notifications are contained in at
	     * least one conformance group (RFC 2580 3.3 and 4.1).
	     */
	    
	    smiCheckGroupMembership(parserPtr, objectPtr);
	}
    }

    if (modulePtr->export.language == SMI_LANGUAGE_SPPI) {
        Object *parentPtr;
        
        for (objectPtr = modulePtr->firstObjectPtr;
             objectPtr; objectPtr = objectPtr->nextPtr) {
            /*
             * All checks for SPPI constructs
             */
            if (objectPtr->nodePtr->parentPtr)
                parentPtr = objectPtr->nodePtr->parentPtr->lastObjectPtr;
            else
                parentPtr = NULL;
            
            /*
             * Do all rows contain a PIB-INDEX/AUGMENTS/EXTENDS ?
             * See RFC 3159 7.5, 7.7, 7.8
             */
            if (parentPtr  &&
                (parentPtr->export.nodekind == SMI_NODEKIND_TABLE) &&
                (objectPtr->export.indexkind != SMI_INDEX_INDEX) &&
                (objectPtr->export.indexkind != SMI_INDEX_AUGMENT) &&
                (objectPtr->export.indexkind != SMI_INDEX_SPARSE))
                smiPrintErrorAtLine(parserPtr, ERR_ROW_LACKS_PIB_INDEX,
                                    objectPtr->line);

            /*
             * Does any non row contain a PIB-INDEX/AUGMENTS/EXTENDS ?
             * See RFC 3159 7.5, 7.7, 7.8
             */
            if ((objectPtr->export.nodekind != SMI_NODEKIND_ROW) &&
                (objectPtr->export.indexkind != SMI_INDEX_UNKNOWN))
                smiPrintErrorAtLine(parserPtr, ERR_PIB_INDEX_FOR_NON_ROW_TYPE,
                                    objectPtr->line);

            /*
             * Check the PIB-INDEX and other indices
             */
            if ((objectPtr->export.nodekind == SMI_NODEKIND_ROW) &&
                (objectPtr->export.indexkind == SMI_INDEX_INDEX)) {

                /*
                 * Only the first element (PIB-INDEX) has to be an InstanceId.
                 * See RFC 3159 7.5
                 */
                if (objectPtr->listPtr && objectPtr->listPtr->ptr) {
                    Object *pibindex = (Object *)objectPtr->listPtr->ptr;
                    if (pibindex->typePtr && pibindex->typePtr->export.name &&
                        strcmp(pibindex->typePtr->export.name, "InstanceId"))
                        smiPrintErrorAtLine(thisParserPtr, ERR_PIB_INDEX_NOT_INSTANCEID,
                                            pibindex->line, pibindex->export.name);
                }
            }
            
            /*
             * Do all tables contain a PIB-ACCESS clause?
             * See RFC 3159 7.3
             */
            if ((objectPtr->export.nodekind == SMI_NODEKIND_TABLE) &&
                (objectPtr->export.access == SMI_ACCESS_UNKNOWN))
                smiPrintErrorAtLine(parserPtr, ERR_TABLE_LACKS_PIB_ACCESS,
                                    objectPtr->line);

            /*
             * Does any non table types contain a PIB-ACCESS clause?
             * See RFC 3159 7.3
             */
            if (((objectPtr->export.nodekind == SMI_NODEKIND_NODE) ||
                 (objectPtr->export.nodekind == SMI_NODEKIND_ROW) ||
                 (objectPtr->export.nodekind == SMI_NODEKIND_SCALAR)) &&
                (objectPtr->export.access != SMI_ACCESS_UNKNOWN))
                smiPrintErrorAtLine(parserPtr, ERR_PIB_ACCESS_FOR_NON_TABLE,
                                    objectPtr->line);

            /*
             * Check the UNIQUENESS clause and its entries
             * See RFC 3159 7.9
             */
            if (objectPtr->uniquenessPtr) {
                if (objectPtr->export.nodekind != SMI_NODEKIND_ROW)
                    smiPrintErrorAtLine(parserPtr, ERR_UNIQUENESS_FOR_NON_ROW,
                                        objectPtr->line);
                else
                    smiCheckUniqueness(parserPtr, objectPtr);
            }
            
            /*
             * Does the PIB-REFERENCES object point to a PRC (table)?
             * See RFC 3159 7.10
             */
            if (objectPtr->typePtr && objectPtr->typePtr->export.name &&
                !strcmp(objectPtr->typePtr->export.name, "ReferenceId") &&
                objectPtr->relatedPtr &&
                (objectPtr->relatedPtr->export.nodekind != SMI_NODEKIND_ROW))
                smiPrintErrorAtLine(parserPtr, ERR_PIB_REFERENCES_NOT_ROW,
                                    objectPtr->line);

            /*
             * Do all PIB-TAGs point to objects with a SYNTAX of TagId?
             * See RFC 3159 7.12
             */
            if (objectPtr->typePtr && objectPtr->typePtr->export.name &&
                !strcmp(objectPtr->typePtr->export.name, "TagReferenceId") &&
                objectPtr->relatedPtr && objectPtr->relatedPtr->typePtr &&
                objectPtr->relatedPtr->typePtr->export.name &&
                strcmp(objectPtr->relatedPtr->typePtr->export.name, "TagId"))
                smiPrintErrorAtLine(parserPtr, ERR_PIB_TAG_TYPE, objectPtr->line);
            
            /*
             * Is the attribute member of at least one compliance group?
             * See RFC 3159 9.1
             */
            if (objectPtr->export.nodekind & SMI_NODEKIND_COLUMN) {
                Object *group;
                int found = 0;
                
                for (group = modulePtr->firstObjectPtr; group;
                     group = group->nextPtr) {
                    if ((group->export.nodekind == SMI_NODEKIND_GROUP) &&
                        group->listPtr) {
                        List *l;
                        
                        for (l = group->listPtr; l; l = l->nextPtr)
                            if (((Object *)l->ptr)->export.name &&
                                !strcmp(((Object *)l->ptr)->export.name,
                                        objectPtr->export.name)) {
                                found = 1;
                                break;
                            }
                    }
                    if (found)
                        break;
                }
                if (!found)
                    smiPrintErrorAtLine(parserPtr, ERR_ATTRIBUTE_NOT_IN_GROUP,
                                        objectPtr->line, objectPtr->export.name);
            }
        }
    }
}



static void
checkTypes(Parser *parserPtr, Module *modulePtr)
{
    Type *typePtr;
    
    for (typePtr = modulePtr->firstTypePtr;
	typePtr; typePtr = typePtr->nextPtr) {

	/*
	 * Check references to unknown types.
	 */
	
	if ((typePtr->flags & FLAG_INCOMPLETE)
	    && typePtr->export.name
	    && (typePtr->export.decl == SMI_DECL_UNKNOWN)) {
	    smiPrintErrorAtLine(parserPtr, ERR_UNKNOWN_TYPE,
				typePtr->line, typePtr->export.name);
	}

	/*
	 * Use TCs instead of type assignments in SMIv2.
	 */

	if (thisModulePtr->export.language == SMI_LANGUAGE_SMIV2
	    && typePtr->export.decl == SMI_DECL_TYPEASSIGNMENT
	    && typePtr->export.basetype != SMI_BASETYPE_UNKNOWN
	    && strcmp(thisModulePtr->export.name, "SNMPv2-SMI")) {
	    smiPrintErrorAtLine(parserPtr, ERR_SMIV2_TYPE_ASSIGNEMENT,
				typePtr->line, typePtr->export.name);
	}

	/*
	 * Check whether we have types that are not used in this
	 * module.
	 */

	if ((typePtr->export.decl == SMI_DECL_TYPEDEF
	     || typePtr->export.decl == SMI_DECL_TEXTUALCONVENTION)
	    && ! (typePtr->flags & FLAG_INSYNTAX)) {
	    static char *status[] = { "Unknown", "current", "deprecated",
				      "mandatory", "optional", "obsolete" };
	    smiPrintErrorAtLine(parserPtr, ERR_TYPE_UNREF,
				typePtr->line,
				status[typePtr->export.status],
				typePtr->export.name);
	}

	/*
	 * Complain about TCs derived from other TCs (RFC 2579 3.5).
	 */
	
	if (typePtr->parentPtr
	    && typePtr->export.decl == SMI_DECL_TEXTUALCONVENTION
	    && typePtr->export.decl == typePtr->parentPtr->export.decl) {
	    smiPrintErrorAtLine(parserPtr, ERR_SMIV2_NESTED_TEXTUAL_CONVENTION,
				typePtr->line,
				typePtr->export.name,
				typePtr->parentPtr->export.name);

	    if (typePtr->export.status < typePtr->parentPtr->export.status) {
		if (typePtr->parentPtr->export.status == SMI_STATUS_DEPRECATED) {
		    smiPrintErrorAtLine(parserPtr, ERR_TYPE_STATUS_DEPRECATED,
					typePtr->line,
					typePtr->parentPtr->export.name,
					typePtr->export.name);
		}
		if (typePtr->parentPtr->export.status == SMI_STATUS_OBSOLETE) {
		    smiPrintErrorAtLine(parserPtr, ERR_TYPE_STATUS_OBSOLETE,
					typePtr->line,
					typePtr->parentPtr->export.name,
					typePtr->export.name);
		}
	    }
	}

	smiCheckTypeFormat(parserPtr, typePtr);
	smiCheckNamedNumberRedefinition(parserPtr, typePtr);
	smiCheckNamedNumberSubtyping(parserPtr, typePtr);
    }
}


				
static void
adjustDefval(Parser *parserPtr, SmiValue *valuePtr, Type *typePtr, int line)
{
    Object *object2Ptr;
    List *bitsListPtr, *valueListPtr, *p, *pp, *nextPtr, *listPtr;
    Import *importPtr;
    int nBits, bit;
    
    if (valuePtr->basetype == SMI_BASETYPE_UNKNOWN)
	return;
	
    if (valuePtr->basetype == SMI_BASETYPE_OBJECTIDENTIFIER) {
	/* a len of -1 indicates an unresolved label in ptr */
	if (valuePtr->len == -1) {
	    object2Ptr = findObjectByModuleAndName(parserPtr->modulePtr,
						  (char *)valuePtr->value.ptr);
	    if (!object2Ptr) {
		importPtr = findImportByName(
		    (char *)valuePtr->value.ptr, parserPtr->modulePtr);
		if (importPtr) {		/* imported object */
		    importPtr->use++;
		    object2Ptr = findObjectByModulenameAndName(
			importPtr->export.module,
			importPtr->export.name);
		}
	    }
	    if (!object2Ptr) {
		smiPrintErrorAtLine(parserPtr, ERR_UNKNOWN_OIDLABEL,
				    line,
				    (char *)valuePtr->value.ptr);
		smiFree(valuePtr->value.ptr);
		valuePtr->value.ptr = NULL;
		valuePtr->basetype = SMI_BASETYPE_UNKNOWN;
	    } else {
		smiFree(valuePtr->value.ptr);
		valuePtr->len = object2Ptr->export.oidlen;
		valuePtr->value.ptr = smiMalloc(object2Ptr->export.oidlen *
						sizeof(SmiSubid));
		memcpy(valuePtr->value.ptr,
		       object2Ptr->export.oid,
		       object2Ptr->export.oidlen * sizeof(SmiSubid));
	    }
	}
    } else if (valuePtr->basetype == SMI_BASETYPE_BITS) {
	bitsListPtr = typePtr->listPtr;
	valueListPtr = (void *)valuePtr->value.ptr;
	for (nBits = 0, p = bitsListPtr; p; p = p->nextPtr) {
	    if (nBits < 1+((NamedNumber *)(p->ptr))->export.value.value.integer32) {
		nBits = 1+((NamedNumber *)(p->ptr))->export.value.value.integer32;
	    }
	}
	valuePtr->value.ptr = smiMalloc((nBits+7)/8);
	memset(valuePtr->value.ptr, 0, (nBits+7)/8);
	valuePtr->len = (nBits+7)/8;
	for (p = valueListPtr; p;) {
	    for (pp = bitsListPtr; pp; pp = pp->nextPtr) {
		if (!strcmp(p->ptr,
			    ((NamedNumber *)(pp->ptr))->export.name)) {
		    bit = ((NamedNumber *)(pp->ptr))->export.value.value.integer32;
		    valuePtr->value.ptr[bit/8] |=
			1 << (7-(bit%8));
		}
	    }
	    smiFree(p->ptr);
	    nextPtr = p->nextPtr;
	    smiFree(p);
	    p = nextPtr;
	}
    } else if (valuePtr->basetype == SMI_BASETYPE_ENUM) {
	/* a len of -1 indicates an unresolved enum label in ptr */
	if (valuePtr->len == -1) {
	    for (listPtr = typePtr->listPtr; listPtr;
		 listPtr = listPtr->nextPtr) {
		if (!strcmp(((NamedNumber *)(listPtr->ptr))->export.name,
			    (char *)valuePtr->value.ptr)) {
		    smiFree(valuePtr->value.ptr);
		    valuePtr->value.integer32 =
			((NamedNumber *)(listPtr->ptr))->
			export.value.value.integer32;
		    valuePtr->len = 1;
		    break;
		}
	    }
	}
    }
}



static void
checkDefvals(Parser *parserPtr, Module *modulePtr)
{
    Object *objectPtr;
    
    /*
     * Check unknown identifiers in OID DEFVALs.
     */

    for(objectPtr = modulePtr->firstObjectPtr;
	objectPtr; objectPtr = objectPtr->nextPtr) {

	adjustDefval(parserPtr, &objectPtr->export.value,
		     objectPtr->typePtr, objectPtr->line);
	
	if (objectPtr->export.value.len == -1) {
	    smiPrintErrorAtLine(parserPtr,
				ERR_DEFVAL_SYNTAX, objectPtr->line);
	}
	
	smiCheckDefault(parserPtr, objectPtr);
    }
}



static void
checkImportsUsage(Parser *parserPtr, Module *modulePtr)
{
    Import *importPtr;
    
    /*
     * Check usage of all imported identifiers.
     */

    if (strcmp(modulePtr->export.name, "SNMPv2-TC") &&
	strcmp(modulePtr->export.name, "SNMPv2-CONF") &&
	strcmp(modulePtr->export.name, "RFC-1212") &&
	strcmp(modulePtr->export.name, "RFC-1215")) {
	for(importPtr = modulePtr->firstImportPtr;
	    importPtr; importPtr = importPtr->nextPtr) {
	    if (! strcmp(importPtr->export.module, "SNMPv2-SMI")) {
		if (! strcmp(importPtr->export.name, "ExtUTCTime")
		    || !strcmp(importPtr->export.name, "ObjectName")
		    || !strcmp(importPtr->export.name, "NotificationName")) {
		    smiPrintErrorAtLine(parserPtr, ERR_ILLEGAL_IMPORT,
					importPtr->line,
					importPtr->export.name,
					importPtr->export.module);
		}
	    }
	    /* checkImports() handles KIND_NOTFOUND */
	    if (importPtr->use == 0 && importPtr->kind != KIND_NOTFOUND) {
		smiPrintErrorAtLine(parserPtr, ERR_UNUSED_IMPORT,
				    importPtr->line,
				    importPtr->export.name,
				    importPtr->export.module);
	    }

	    if (modulePtr->export.language == SMI_LANGUAGE_SMIV2) {
		int j;
		for (j = 0; convertImportv2[j]; j += 4) {
		    if ((strcmp(convertImportv2[j],
				importPtr->export.module) == 0)
			&& (strcmp(convertImportv2[j+1],
				   importPtr->export.name) == 0)) {
			smiPrintErrorAtLine(parserPtr,
					    ERR_OBSOLETE_IMPORT,
					    importPtr->line,
					    importPtr->export.name,
					    convertImportv2[j+2],
					    importPtr->export.module);
		    }
		}
	    }
	}
    }
}



static time_t
checkDate(Parser *parserPtr, char *date)
{
    struct tm	tm;
    time_t	anytime;
    int		i, len;
    char	*p;
    
    memset(&tm, 0, sizeof(tm));
    anytime = 0;
    
    len = strlen(date);
    if (len == 11 || len == 13) {
	for (i = 0; i < len; i++) {
	    if ( (i < len-1 && ! isdigit((int) date[i]))
		 || (i == len-1 && date[len-1] != 'Z')) {
		smiPrintError(parserPtr, ERR_DATE_CHARACTER, date);
		anytime = (time_t) -1;
		break;
	    }
	}
    } else {
	smiPrintError(parserPtr, ERR_DATE_LENGTH, date);
	anytime = (time_t) -1;
    }

    if (anytime == 0) {
	for (i = 0, p = date, tm.tm_year = 0;
	     i < ((len == 11) ? 2 : 4); i++, p++) {
	    tm.tm_year = tm.tm_year * 10 + (*p - '0');
	}
	if (len == 11) {
	    tm.tm_year += 1900;
	    if (tm.tm_year < 1990)
		smiPrintError(parserPtr, ERR_DATE_YEAR_2DIGITS,
			      date, tm.tm_year);
	}
	tm.tm_mon  = (p[0]-'0') * 10 + (p[1]-'0');
	p += 2;
	tm.tm_mday = (p[0]-'0') * 10 + (p[1]-'0');
	p += 2;
	tm.tm_hour = (p[0]-'0') * 10 + (p[1]-'0');
	p += 2;
	tm.tm_min  = (p[0]-'0') * 10 + (p[1]-'0');
	
	if (tm.tm_mon < 1 || tm.tm_mon > 12) {
	    smiPrintError(parserPtr, ERR_DATE_MONTH, date);
	}
	if (tm.tm_mday < 1 || tm.tm_mday > 31) {
	    smiPrintError(parserPtr, ERR_DATE_DAY, date);
	}
	if (tm.tm_hour < 0 || tm.tm_hour > 23) {
	    smiPrintError(parserPtr, ERR_DATE_HOUR, date);
	}
	if (tm.tm_min < 0 || tm.tm_min > 59) {
	    smiPrintError(parserPtr, ERR_DATE_MINUTES, date);
	}
	
	tm.tm_year -= 1900;
	tm.tm_mon -= 1;
	tm.tm_isdst = 0;

	anytime = timegm(&tm);
	
	if (anytime == (time_t) -1) {
	    smiPrintError(parserPtr, ERR_DATE_VALUE, date);
	} else {
	    if (anytime < SMI_EPOCH) {
		smiPrintError(parserPtr, ERR_DATE_IN_PAST, date);
	    }
	    if (anytime > time(NULL)) {
		smiPrintError(parserPtr, ERR_DATE_IN_FUTURE, date);
	    }
	}
    }

    return (anytime == (time_t) -1) ? 0 : anytime;
}


/* Line 371 of yacc.c  */
#line 1337 "parser-smi.c"

# ifndef YY_NULL
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULL nullptr
#  else
#   define YY_NULL 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "parser-smi.tab.h".  */
#ifndef YY_SMI_PARSER_SMI_TAB_H_INCLUDED
# define YY_SMI_PARSER_SMI_TAB_H_INCLUDED
/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif
#if YYDEBUG
extern int smidebug;
#endif

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     DOT_DOT = 258,
     COLON_COLON_EQUAL = 259,
     UPPERCASE_IDENTIFIER = 260,
     LOWERCASE_IDENTIFIER = 261,
     NUMBER = 262,
     NEGATIVENUMBER = 263,
     NUMBER64 = 264,
     NEGATIVENUMBER64 = 265,
     BIN_STRING = 266,
     HEX_STRING = 267,
     QUOTED_STRING = 268,
     ACCESS = 269,
     AGENT_CAPABILITIES = 270,
     APPLICATION = 271,
     AUGMENTS = 272,
     BEGIN_ = 273,
     BITS = 274,
     CHOICE = 275,
     CONTACT_INFO = 276,
     CREATION_REQUIRES = 277,
     COUNTER32 = 278,
     COUNTER64 = 279,
     DEFINITIONS = 280,
     DEFVAL = 281,
     DESCRIPTION = 282,
     DISPLAY_HINT = 283,
     END = 284,
     ENTERPRISE = 285,
     EXPORTS = 286,
     EXTENDS = 287,
     FROM = 288,
     GROUP = 289,
     GAUGE32 = 290,
     IDENTIFIER = 291,
     IMPLICIT = 292,
     IMPLIED = 293,
     IMPORTS = 294,
     INCLUDES = 295,
     INDEX = 296,
     INSTALL_ERRORS = 297,
     INTEGER = 298,
     INTEGER32 = 299,
     INTEGER64 = 300,
     IPADDRESS = 301,
     LAST_UPDATED = 302,
     MACRO = 303,
     MANDATORY_GROUPS = 304,
     MAX_ACCESS = 305,
     MIN_ACCESS = 306,
     MODULE = 307,
     MODULE_COMPLIANCE = 308,
     MODULE_IDENTITY = 309,
     NOT_ACCESSIBLE = 310,
     NOTIFICATIONS = 311,
     NOTIFICATION_GROUP = 312,
     NOTIFICATION_TYPE = 313,
     OBJECT = 314,
     OBJECT_GROUP = 315,
     OBJECT_IDENTITY = 316,
     OBJECT_TYPE = 317,
     OBJECTS = 318,
     OCTET = 319,
     OF = 320,
     ORGANIZATION = 321,
     OPAQUE = 322,
     PIB_ACCESS = 323,
     PIB_DEFINITIONS = 324,
     PIB_INDEX = 325,
     PIB_MIN_ACCESS = 326,
     PIB_REFERENCES = 327,
     PIB_TAG = 328,
     POLICY_ACCESS = 329,
     PRODUCT_RELEASE = 330,
     REFERENCE = 331,
     REVISION = 332,
     SEQUENCE = 333,
     SIZE = 334,
     STATUS = 335,
     STRING = 336,
     SUBJECT_CATEGORIES = 337,
     SUPPORTS = 338,
     SYNTAX = 339,
     TEXTUAL_CONVENTION = 340,
     TIMETICKS = 341,
     TRAP_TYPE = 342,
     UNIQUENESS = 343,
     UNITS = 344,
     UNIVERSAL = 345,
     UNSIGNED32 = 346,
     UNSIGNED64 = 347,
     VALUE = 348,
     VARIABLES = 349,
     VARIATION = 350,
     WRITE_SYNTAX = 351
   };
#endif


#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{
/* Line 387 of yacc.c  */
#line 1297 "parser-smi.y"

    char           *text;	  		/* scanned quoted text       */
    char           *id;				/* identifier name           */
    int            err;				/* actually just a dummy     */
    time_t	   date;			/* a date value              */
    Object         *objectPtr;			/* object identifier         */
    SmiStatus      status;			/* a STATUS value            */
    SmiAccess      access;			/* an ACCESS value           */
    Type           *typePtr;
    List           *listPtr;			/* SEQUENCE and INDEX lists  */
    NamedNumber    *namedNumberPtr;		/* BITS or enum item         */
    Range          *rangePtr;			/* type restricting range    */
    SmiValue	   *valuePtr;
    SmiUnsigned32  unsigned32;			/*                           */
    SmiInteger32   integer32;			/*                           */
    SmiUnsigned64  unsigned64;			/*                           */
    SmiInteger64   integer64;			/*                           */
    struct Compl   compl;
    struct Index   index;
    Module	   *modulePtr;
    SubjectCategories *subjectCategoriesPtr;


/* Line 387 of yacc.c  */
#line 1500 "parser-smi.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int smiparse (void *YYPARSE_PARAM);
#else
int smiparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int smiparse (struct Parser *parserPtr);
#else
int smiparse ();
#endif
#endif /* ! YYPARSE_PARAM */

#endif /* !YY_SMI_PARSER_SMI_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

/* Line 390 of yacc.c  */
#line 1527 "parser-smi.c"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef __attribute__
/* This feature is available in gcc versions 2.5 and later.  */
# if (! defined __GNUC__ || __GNUC__ < 2 \
      || (__GNUC__ == 2 && __GNUC_MINOR__ < 5))
#  define __attribute__(Spec) /* empty */
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif


/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(N) (N)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (YYID (0))
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  6
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   665

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  107
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  222
/* YYNRULES -- Number of rules.  */
#define YYNRULES  425
/* YYNRULES -- Number of states.  */
#define YYNSTATES  710

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   351

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     101,   102,     2,     2,   100,     2,   105,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    99,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,   103,     2,   104,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    97,   106,    98,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     6,     8,    11,    12,    23,    27,
      28,    30,    32,    34,    35,    39,    40,    41,    45,    47,
      48,    50,    53,    57,    59,    63,    65,    67,    69,    71,
      73,    75,    77,    79,    81,    83,    85,    87,    89,    91,
      93,    95,    97,    99,   101,   103,   105,   107,   109,   111,
     113,   115,   117,   119,   121,   122,   124,   127,   129,   131,
     133,   135,   137,   139,   141,   143,   145,   147,   149,   151,
     154,   155,   156,   162,   164,   166,   168,   170,   172,   174,
     176,   178,   180,   182,   183,   187,   189,   191,   192,   201,
     202,   207,   209,   211,   213,   215,   217,   219,   221,   223,
     225,   227,   229,   231,   233,   235,   237,   239,   240,   241,
     253,   255,   259,   261,   266,   268,   272,   275,   277,   282,
     284,   286,   289,   291,   295,   296,   302,   303,   304,   305,
     320,   321,   322,   346,   347,   350,   351,   352,   364,   369,
     370,   372,   376,   378,   381,   382,   384,   386,   387,   390,
     392,   394,   395,   401,   402,   403,   409,   410,   411,   417,
     418,   420,   421,   423,   427,   429,   430,   436,   437,   439,
     443,   448,   449,   453,   454,   458,   459,   460,   461,   477,
     478,   479,   480,   481,   482,   483,   484,   485,   510,   515,
     516,   518,   520,   524,   526,   531,   533,   536,   538,   540,
     542,   544,   550,   556,   558,   560,   562,   564,   565,   569,
     570,   574,   576,   577,   581,   582,   586,   591,   594,   599,
     602,   603,   608,   611,   616,   620,   622,   624,   626,   628,
     630,   632,   634,   636,   640,   643,   646,   650,   654,   657,
     660,   663,   665,   668,   670,   671,   675,   678,   680,   683,
     686,   689,   691,   694,   696,   699,   702,   705,   708,   711,
     714,   716,   719,   721,   723,   725,   727,   729,   730,   734,
     741,   743,   747,   749,   753,   755,   757,   759,   761,   763,
     765,   769,   771,   775,   776,   782,   784,   786,   788,   790,
     793,   794,   797,   798,   800,   801,   807,   812,   813,   819,
     820,   821,   827,   828,   830,   834,   837,   839,   841,   843,
     848,   849,   851,   855,   857,   858,   860,   864,   866,   868,
     871,   872,   874,   875,   877,   880,   881,   887,   892,   893,
     898,   900,   904,   906,   911,   913,   917,   919,   921,   923,
     924,   927,   929,   932,   934,   938,   940,   945,   952,   954,
     956,   959,   964,   966,   967,   968,   969,   985,   986,   987,
     988,  1004,  1005,  1006,  1007,  1023,  1025,  1027,  1030,  1031,
    1037,  1040,  1042,  1043,  1048,  1049,  1051,  1055,  1057,  1059,
    1060,  1062,  1065,  1067,  1069,  1070,  1076,  1077,  1086,  1089,
    1090,  1093,  1094,  1096,  1099,  1102,  1103,  1104,  1105,  1106,
    1124,  1126,  1127,  1129,  1132,  1133,  1142,  1144,  1148,  1150,
    1153,  1155,  1157,  1158,  1160,  1163,  1164,  1165,  1177,  1180,
    1181,  1183,  1188,  1189,  1191,  1195
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     108,     0,    -1,   109,    -1,    -1,   110,    -1,   109,   110,
      -1,    -1,   126,   111,   112,   113,     4,    18,   116,   114,
     127,    29,    -1,    97,   270,    98,    -1,    -1,    25,    -1,
      69,    -1,   115,    -1,    -1,    39,   118,    99,    -1,    -1,
      -1,    31,   117,    99,    -1,   119,    -1,    -1,   120,    -1,
     119,   120,    -1,   121,    33,   126,    -1,   122,    -1,   121,
     100,   122,    -1,     6,    -1,     5,    -1,   123,    -1,   124,
      -1,   125,    -1,    19,    -1,    44,    -1,    46,    -1,    49,
      -1,    53,    -1,    54,    -1,    60,    -1,    61,    -1,    62,
      -1,    67,    -1,    85,    -1,    86,    -1,    91,    -1,    15,
      -1,    23,    -1,    24,    -1,    35,    -1,    57,    -1,    58,
      -1,    87,    -1,    45,    -1,    92,    -1,     5,    -1,   128,
      -1,    -1,   129,    -1,   128,   129,    -1,   139,    -1,   137,
      -1,   159,    -1,   163,    -1,   167,    -1,   193,    -1,   197,
      -1,   285,    -1,   277,    -1,   281,    -1,   308,    -1,   130,
      -1,     1,    98,    -1,    -1,    -1,   133,   131,    48,   132,
      29,    -1,    54,    -1,    62,    -1,    87,    -1,    58,    -1,
      61,    -1,    85,    -1,    60,    -1,    57,    -1,    53,    -1,
      15,    -1,    -1,    20,   135,    98,    -1,     6,    -1,     5,
      -1,    -1,   136,   138,    59,    36,     4,    97,   270,    98,
      -1,    -1,   141,   140,     4,   146,    -1,     5,    -1,   142,
      -1,   145,    -1,   143,    -1,   144,    -1,    46,    -1,    86,
      -1,    67,    -1,    44,    -1,    91,    -1,    23,    -1,    35,
      -1,    24,    -1,    45,    -1,    92,    -1,   154,    -1,    -1,
      -1,    85,   147,   238,    80,   236,    27,   268,   148,   256,
      84,   154,    -1,   134,    -1,    78,    65,   150,    -1,     5,
      -1,    78,    97,   152,    98,    -1,   153,    -1,   152,   100,
     153,    -1,     6,   155,    -1,   210,    -1,    19,    97,   156,
      98,    -1,   212,    -1,    19,    -1,     5,   225,    -1,   157,
      -1,   156,   100,   157,    -1,    -1,     6,   158,   101,     7,
     102,    -1,    -1,    -1,    -1,     6,   160,    61,   161,    80,
     236,    27,   268,   162,   256,     4,    97,   270,    98,    -1,
      -1,    -1,     6,   164,    62,   165,    84,   154,   239,   174,
     177,   179,    80,   236,   166,   186,   256,   241,   244,   181,
     250,     4,    97,   254,    98,    -1,    -1,    27,   268,    -1,
      -1,    -1,   136,   168,    87,   169,    30,   270,   170,   173,
     256,     4,     7,    -1,    94,    97,   171,    98,    -1,    -1,
     172,    -1,   171,   100,   172,    -1,   254,    -1,    27,   268,
      -1,    -1,   190,    -1,   175,    -1,    -1,   176,   240,    -1,
      74,    -1,    68,    -1,    -1,    72,   178,    97,   249,    98,
      -1,    -1,    -1,    73,   180,    97,   254,    98,    -1,    -1,
      -1,    88,   182,    97,   183,    98,    -1,    -1,   184,    -1,
      -1,   185,    -1,   184,   100,   185,    -1,   254,    -1,    -1,
      42,   187,    97,   188,    98,    -1,    -1,   189,    -1,   188,
     100,   189,    -1,     6,   101,     7,   102,    -1,    -1,    50,
     191,   240,    -1,    -1,    14,   192,   240,    -1,    -1,    -1,
      -1,     6,   194,    58,   195,   261,    80,   236,    27,   268,
     196,   256,     4,    97,   255,    98,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     6,   198,    54,   199,   206,
     200,    47,   269,   201,    66,   268,   202,    21,   268,   203,
      27,   268,   204,   257,   205,     4,    97,   270,    98,    -1,
      82,    97,   207,    98,    -1,    -1,   208,    -1,   209,    -1,
     208,   100,   209,    -1,     6,    -1,     6,   101,     7,   102,
      -1,   214,    -1,   211,   214,    -1,   149,    -1,   150,    -1,
     151,    -1,   222,    -1,   103,    16,     7,   104,    37,    -1,
     103,    90,     7,   104,    37,    -1,   221,    -1,   224,    -1,
     220,    -1,    43,    -1,    -1,    43,   215,   226,    -1,    -1,
      43,   216,   231,    -1,    44,    -1,    -1,    44,   217,   226,
      -1,    -1,     5,   218,   231,    -1,   126,   105,     5,   231,
      -1,     5,   226,    -1,   126,   105,     5,   226,    -1,    64,
      81,    -1,    -1,    64,    81,   219,   227,    -1,     5,   227,
      -1,   126,   105,     5,   227,    -1,    59,    36,   225,    -1,
       7,    -1,     8,    -1,     9,    -1,    10,    -1,    11,    -1,
      12,    -1,     6,    -1,    13,    -1,    97,   274,    98,    -1,
      43,   225,    -1,    44,   225,    -1,    64,    81,   225,    -1,
      59,    36,   225,    -1,    46,   225,    -1,    23,   225,    -1,
      23,   226,    -1,    35,    -1,    35,   226,    -1,    91,    -1,
      -1,    91,   223,   226,    -1,    86,   225,    -1,    67,    -1,
      67,   227,    -1,    24,   225,    -1,    24,   226,    -1,    45,
      -1,    45,   226,    -1,    92,    -1,    92,   226,    -1,    46,
     225,    -1,    23,   225,    -1,    35,   225,    -1,    91,   225,
      -1,    86,   225,    -1,    67,    -1,    24,   225,    -1,    45,
      -1,    92,    -1,   226,    -1,   227,    -1,   231,    -1,    -1,
     101,   228,   102,    -1,   101,    79,   101,   228,   102,   102,
      -1,   229,    -1,   228,   106,   229,    -1,   230,    -1,   230,
       3,   230,    -1,     8,    -1,     7,    -1,    10,    -1,     9,
      -1,    12,    -1,    11,    -1,    97,   232,    98,    -1,   233,
      -1,   232,   100,   233,    -1,    -1,     6,   234,   101,   235,
     102,    -1,     7,    -1,     8,    -1,     6,    -1,     6,    -1,
      28,   268,    -1,    -1,    89,   268,    -1,    -1,     6,    -1,
      -1,    70,   242,    97,   249,    98,    -1,    17,    97,   249,
      98,    -1,    -1,    32,   243,    97,   249,    98,    -1,    -1,
      -1,    41,   245,    97,   246,    98,    -1,    -1,   247,    -1,
     246,   100,   247,    -1,    38,   248,    -1,   248,    -1,   254,
      -1,   254,    -1,    26,    97,   251,    98,    -1,    -1,   213,
      -1,    97,   252,    98,    -1,   253,    -1,    -1,     6,    -1,
     253,   100,     6,    -1,   270,    -1,   270,    -1,    76,   268,
      -1,    -1,   258,    -1,    -1,   259,    -1,   258,   259,    -1,
      -1,    77,   269,   260,    27,   268,    -1,    63,    97,   263,
      98,    -1,    -1,    63,    97,   263,    98,    -1,   264,    -1,
     263,   100,   264,    -1,   254,    -1,    56,    97,   266,    98,
      -1,   267,    -1,   266,   100,   267,    -1,   255,    -1,    13,
      -1,    13,    -1,    -1,   271,   272,    -1,   273,    -1,   272,
     273,    -1,   136,    -1,   126,   105,     6,    -1,     7,    -1,
       6,   101,     7,   102,    -1,   126,   105,     6,   101,     7,
     102,    -1,   275,    -1,   276,    -1,   275,   276,    -1,     6,
     101,     7,   102,    -1,     7,    -1,    -1,    -1,    -1,     6,
     278,    60,   279,   262,    80,   236,    27,   268,   280,   256,
       4,    97,   270,    98,    -1,    -1,    -1,    -1,     6,   282,
      57,   283,   265,    80,   236,    27,   268,   284,   256,     4,
      97,   270,    98,    -1,    -1,    -1,    -1,     6,   286,    53,
     287,    80,   236,    27,   268,   288,   256,   289,     4,    97,
     270,    98,    -1,   290,    -1,   291,    -1,   290,   291,    -1,
      -1,    52,   293,   292,   294,   297,    -1,     5,   270,    -1,
       5,    -1,    -1,    49,    97,   295,    98,    -1,    -1,   296,
      -1,   295,   100,   296,    -1,   270,    -1,   298,    -1,    -1,
     299,    -1,   298,   299,    -1,   300,    -1,   302,    -1,    -1,
      34,   301,   270,    27,   268,    -1,    -1,    59,   303,   254,
     304,   305,   307,    27,   268,    -1,    84,   154,    -1,    -1,
      96,   306,    -1,    -1,   154,    -1,    51,   240,    -1,    71,
     240,    -1,    -1,    -1,    -1,    -1,     6,   309,    15,   310,
      75,   268,    80,   237,    27,   268,   311,   256,   312,     4,
      97,   270,    98,    -1,   313,    -1,    -1,   314,    -1,   313,
     314,    -1,    -1,    83,   318,   315,    40,    97,   316,    98,
     319,    -1,   317,    -1,   316,   100,   317,    -1,   270,    -1,
       5,   270,    -1,     5,    -1,   320,    -1,    -1,   321,    -1,
     320,   321,    -1,    -1,    -1,    95,   254,   322,   304,   305,
     324,   326,   250,   323,    27,   268,    -1,    14,   325,    -1,
      -1,     6,    -1,    22,    97,   327,    98,    -1,    -1,   328,
      -1,   327,   100,   328,    -1,   254,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,  1595,  1595,  1600,  1605,  1607,  1616,  1615,  1677,  1680,
    1683,  1685,  1694,  1697,  1700,  1715,  1717,  1716,  1737,  1740,
    1744,  1746,  1750,  1795,  1797,  1805,  1811,  1817,  1833,  1843,
    1849,  1850,  1851,  1852,  1853,  1854,  1855,  1856,  1857,  1858,
    1859,  1860,  1861,  1864,  1865,  1866,  1867,  1868,  1869,  1870,
    1873,  1874,  1877,  1889,  1892,  1896,  1898,  1902,  1907,  1912,
    1917,  1922,  1927,  1932,  1937,  1942,  1947,  1952,  1957,  1962,
    1977,  1989,  1976,  2022,  2023,  2024,  2025,  2026,  2027,  2028,
    2029,  2030,  2031,  2035,  2034,  2064,  2069,  2085,  2084,  2125,
    2124,  2290,  2294,  2318,  2332,  2333,  2342,  2343,  2344,  2345,
    2346,  2349,  2350,  2351,  2354,  2355,  2358,  2375,  2406,  2374,
    2442,  2450,  2464,  2509,  2517,  2523,  2543,  2626,  2632,  2654,
    2658,  2663,  2696,  2702,  2716,  2715,  2751,  2761,  2786,  2750,
    2814,  2824,  2813,  3121,  3130,  3138,  3148,  3137,  3220,  3225,
    3230,  3240,  3262,  3268,  3274,  3277,  3281,  3290,  3293,  3297,
    3301,  3306,  3305,  3313,  3317,  3316,  3324,  3329,  3328,  3336,
    3339,  3342,  3345,  3351,  3365,  3370,  3369,  3377,  3380,  3386,
    3400,  3422,  3421,  3433,  3432,  3446,  3456,  3476,  3445,  3507,
    3517,  3542,  3546,  3550,  3557,  3564,  3568,  3506,  3614,  3621,
    3628,  3635,  3641,  3656,  3677,  3700,  3704,  3724,  3729,  3734,
    3739,  3756,  3758,  3766,  3771,  3788,  3797,  3811,  3810,  3830,
    3829,  3844,  3871,  3870,  3902,  3901,  3955,  4002,  4057,  4107,
    4113,  4112,  4124,  4170,  4211,  4218,  4225,  4231,  4238,  4245,
    4271,  4294,  4314,  4331,  4364,  4368,  4393,  4397,  4403,  4431,
    4457,  4494,  4520,  4553,  4578,  4577,  4608,  4636,  4674,  4720,
    4746,  4783,  4809,  4846,  4872,  4915,  4943,  4969,  4995,  5019,
    5047,  5087,  5113,  5138,  5165,  5182,  5199,  5218,  5225,  5235,
    5247,  5253,  5267,  5274,  5284,  5290,  5296,  5302,  5308,  5331,
    5358,  5364,  5370,  5384,  5383,  5405,  5420,  5429,  5488,  5504,
    5514,  5519,  5529,  5534,  5601,  5600,  5618,  5629,  5628,  5642,
    5648,  5647,  5681,  5686,  5692,  5706,  5711,  5717,  5727,  5733,
    5753,  5757,  5759,  5767,  5770,  5773,  5779,  5792,  5798,  5804,
    5814,  5817,  5820,  5823,  5825,  5830,  5829,  5860,  5865,  5870,
    5876,  5882,  5895,  5907,  5913,  5919,  5932,  5943,  5954,  5960,
    5960,  5975,  5979,  5988,  6082,  6186,  6210,  6270,  6339,  6343,
    6345,  6349,  6351,  6356,  6366,  6385,  6355,  6416,  6426,  6448,
    6415,  6480,  6490,  6508,  6479,  6572,  6578,  6582,  6618,  6617,
    6646,  6655,  6665,  6670,  6675,  6680,  6686,  6699,  6722,  6729,
    6736,  6740,  6807,  6813,  6822,  6821,  6855,  6854,  6902,  6916,
    6921,  6939,  6944,  6950,  6956,  6965,  6971,  6981,  7003,  6970,
    7038,  7041,  7044,  7046,  7051,  7050,  7077,  7087,  7104,  7110,
    7119,  7129,  7132,  7135,  7137,  7142,  7154,  7141,  7174,  7177,
    7180,  7245,  7255,  7258,  7260,  7264
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "DOT_DOT", "COLON_COLON_EQUAL",
  "UPPERCASE_IDENTIFIER", "LOWERCASE_IDENTIFIER", "NUMBER",
  "NEGATIVENUMBER", "NUMBER64", "NEGATIVENUMBER64", "BIN_STRING",
  "HEX_STRING", "QUOTED_STRING", "ACCESS", "AGENT_CAPABILITIES",
  "APPLICATION", "AUGMENTS", "BEGIN_", "BITS", "CHOICE", "CONTACT_INFO",
  "CREATION_REQUIRES", "COUNTER32", "COUNTER64", "DEFINITIONS", "DEFVAL",
  "DESCRIPTION", "DISPLAY_HINT", "END", "ENTERPRISE", "EXPORTS", "EXTENDS",
  "FROM", "GROUP", "GAUGE32", "IDENTIFIER", "IMPLICIT", "IMPLIED",
  "IMPORTS", "INCLUDES", "INDEX", "INSTALL_ERRORS", "INTEGER", "INTEGER32",
  "INTEGER64", "IPADDRESS", "LAST_UPDATED", "MACRO", "MANDATORY_GROUPS",
  "MAX_ACCESS", "MIN_ACCESS", "MODULE", "MODULE_COMPLIANCE",
  "MODULE_IDENTITY", "NOT_ACCESSIBLE", "NOTIFICATIONS",
  "NOTIFICATION_GROUP", "NOTIFICATION_TYPE", "OBJECT", "OBJECT_GROUP",
  "OBJECT_IDENTITY", "OBJECT_TYPE", "OBJECTS", "OCTET", "OF",
  "ORGANIZATION", "OPAQUE", "PIB_ACCESS", "PIB_DEFINITIONS", "PIB_INDEX",
  "PIB_MIN_ACCESS", "PIB_REFERENCES", "PIB_TAG", "POLICY_ACCESS",
  "PRODUCT_RELEASE", "REFERENCE", "REVISION", "SEQUENCE", "SIZE", "STATUS",
  "STRING", "SUBJECT_CATEGORIES", "SUPPORTS", "SYNTAX",
  "TEXTUAL_CONVENTION", "TIMETICKS", "TRAP_TYPE", "UNIQUENESS", "UNITS",
  "UNIVERSAL", "UNSIGNED32", "UNSIGNED64", "VALUE", "VARIABLES",
  "VARIATION", "WRITE_SYNTAX", "'{'", "'}'", "';'", "','", "'('", "')'",
  "'['", "']'", "'.'", "'|'", "$accept", "mibFile", "modules", "module",
  "$@1", "moduleOid", "definitions", "linkagePart", "linkageClause",
  "exportsClause", "$@2", "importPart", "imports", "import",
  "importIdentifiers", "importIdentifier", "importedKeyword",
  "importedSMIKeyword", "importedSPPIKeyword", "moduleName",
  "declarationPart", "declarations", "declaration", "macroClause", "$@3",
  "$@4", "macroName", "choiceClause", "$@5", "fuzzy_lowercase_identifier",
  "valueDeclaration", "$@6", "typeDeclaration", "$@7", "typeName",
  "typeSMI", "typeSMIandSPPI", "typeSMIonly", "typeSPPIonly",
  "typeDeclarationRHS", "$@8", "$@9", "conceptualTable", "row",
  "entryType", "sequenceItems", "sequenceItem", "Syntax", "sequenceSyntax",
  "NamedBits", "NamedBit", "$@10", "objectIdentityClause", "$@11", "$@12",
  "$@13", "objectTypeClause", "$@14", "$@15", "descriptionClause",
  "trapTypeClause", "$@16", "$@17", "VarPart", "VarTypes", "VarType",
  "DescrPart", "MaxOrPIBAccessPart", "PibAccessPart", "PibAccess",
  "SPPIPibReferencesPart", "$@18", "SPPIPibTagPart", "$@19",
  "SPPIUniquePart", "$@20", "UniqueTypesPart", "UniqueTypes", "UniqueType",
  "SPPIErrorsPart", "$@21", "Errors", "Error", "MaxAccessPart", "$@22",
  "$@23", "notificationTypeClause", "$@24", "$@25", "$@26",
  "moduleIdentityClause", "$@27", "$@28", "$@29", "$@30", "$@31", "$@32",
  "$@33", "$@34", "SubjectCategoriesPart", "SubjectCategories",
  "CategoryIDs", "CategoryID", "ObjectSyntax", "typeTag",
  "sequenceObjectSyntax", "valueofObjectSyntax", "SimpleSyntax", "$@35",
  "$@36", "$@37", "$@38", "$@39", "valueofSimpleSyntax",
  "sequenceSimpleSyntax", "ApplicationSyntax", "$@40",
  "sequenceApplicationSyntax", "anySubType", "integerSubType",
  "octetStringSubType", "ranges", "range", "value", "enumSpec",
  "enumItems", "enumItem", "$@41", "enumNumber", "Status",
  "Status_Capabilities", "DisplayPart", "UnitsPart", "Access", "IndexPart",
  "$@42", "$@43", "MibIndex", "$@44", "IndexTypes", "IndexType", "Index",
  "Entry", "DefValPart", "Value", "BitsValue", "BitNames", "ObjectName",
  "NotificationName", "ReferPart", "RevisionPart", "Revisions", "Revision",
  "$@45", "NotificationObjectsPart", "ObjectGroupObjectsPart", "Objects",
  "Object", "NotificationsPart", "Notifications", "Notification", "Text",
  "ExtUTCTime", "objectIdentifier", "$@46", "subidentifiers",
  "subidentifier", "objectIdentifier_defval", "subidentifiers_defval",
  "subidentifier_defval", "objectGroupClause", "$@47", "$@48", "$@49",
  "notificationGroupClause", "$@50", "$@51", "$@52",
  "moduleComplianceClause", "$@53", "$@54", "$@55", "ComplianceModulePart",
  "ComplianceModules", "ComplianceModule", "$@56", "ComplianceModuleName",
  "MandatoryPart", "MandatoryGroups", "MandatoryGroup", "CompliancePart",
  "Compliances", "Compliance", "ComplianceGroup", "$@57",
  "ComplianceObject", "$@58", "SyntaxPart", "WriteSyntaxPart",
  "WriteSyntax", "AccessPart", "agentCapabilitiesClause", "$@59", "$@60",
  "$@61", "ModulePart_Capabilities", "Modules_Capabilities",
  "Module_Capabilities", "$@62", "CapabilitiesGroups", "CapabilitiesGroup",
  "ModuleName_Capabilities", "VariationPart", "Variations", "Variation",
  "$@63", "$@64", "VariationAccessPart", "VariationAccess", "CreationPart",
  "Cells", "Cell", YY_NULL
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
     335,   336,   337,   338,   339,   340,   341,   342,   343,   344,
     345,   346,   347,   348,   349,   350,   351,   123,   125,    59,
      44,    40,    41,    91,    93,    46,   124
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   107,   108,   108,   109,   109,   111,   110,   112,   112,
     113,   113,   114,   114,   115,   116,   117,   116,   118,   118,
     119,   119,   120,   121,   121,   122,   122,   122,   123,   123,
     123,   123,   123,   123,   123,   123,   123,   123,   123,   123,
     123,   123,   123,   124,   124,   124,   124,   124,   124,   124,
     125,   125,   126,   127,   127,   128,   128,   129,   129,   129,
     129,   129,   129,   129,   129,   129,   129,   129,   129,   129,
     131,   132,   130,   133,   133,   133,   133,   133,   133,   133,
     133,   133,   133,   135,   134,   136,   136,   138,   137,   140,
     139,   141,   141,   141,   142,   142,   143,   143,   143,   143,
     143,   144,   144,   144,   145,   145,   146,   147,   148,   146,
     146,   149,   150,   151,   152,   152,   153,   154,   154,   155,
     155,   155,   156,   156,   158,   157,   160,   161,   162,   159,
     164,   165,   163,   166,   166,   168,   169,   167,   170,   170,
     171,   171,   172,   173,   173,   174,   174,   174,   175,   176,
     176,   178,   177,   177,   180,   179,   179,   182,   181,   181,
     183,   183,   184,   184,   185,   187,   186,   186,   188,   188,
     189,   191,   190,   192,   190,   194,   195,   196,   193,   198,
     199,   200,   201,   202,   203,   204,   205,   197,   206,   206,
     207,   208,   208,   209,   209,   210,   210,   210,   210,   210,
     210,   211,   211,   212,   212,   213,   214,   215,   214,   216,
     214,   214,   217,   214,   218,   214,   214,   214,   214,   214,
     219,   214,   214,   214,   214,   220,   220,   220,   220,   220,
     220,   220,   220,   220,   221,   221,   221,   221,   222,   222,
     222,   222,   222,   222,   223,   222,   222,   222,   222,   222,
     222,   222,   222,   222,   222,   224,   224,   224,   224,   224,
     224,   224,   224,   224,   225,   225,   225,   225,   226,   227,
     228,   228,   229,   229,   230,   230,   230,   230,   230,   230,
     231,   232,   232,   234,   233,   235,   235,   236,   237,   238,
     238,   239,   239,   240,   242,   241,   241,   243,   241,   241,
     245,   244,   244,   246,   246,   247,   247,   248,   249,   250,
     250,   251,   251,   252,   252,   253,   253,   254,   255,   256,
     256,   257,   257,   258,   258,   260,   259,   261,   261,   262,
     263,   263,   264,   265,   266,   266,   267,   268,   269,   271,
     270,   272,   272,   273,   273,   273,   273,   273,   274,   275,
     275,   276,   276,   278,   279,   280,   277,   282,   283,   284,
     281,   286,   287,   288,   285,   289,   290,   290,   292,   291,
     293,   293,   293,   294,   294,   295,   295,   296,   297,   297,
     298,   298,   299,   299,   301,   300,   303,   302,   304,   304,
     305,   305,   306,   307,   307,   307,   309,   310,   311,   308,
     312,   312,   313,   313,   315,   314,   316,   316,   317,   318,
     318,   319,   319,   320,   320,   322,   323,   321,   324,   324,
     325,   326,   326,   327,   327,   328
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     0,     1,     2,     0,    10,     3,     0,
       1,     1,     1,     0,     3,     0,     0,     3,     1,     0,
       1,     2,     3,     1,     3,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     0,     1,     2,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     2,
       0,     0,     5,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     0,     3,     1,     1,     0,     8,     0,
       4,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     0,     0,    11,
       1,     3,     1,     4,     1,     3,     2,     1,     4,     1,
       1,     2,     1,     3,     0,     5,     0,     0,     0,    14,
       0,     0,    23,     0,     2,     0,     0,    11,     4,     0,
       1,     3,     1,     2,     0,     1,     1,     0,     2,     1,
       1,     0,     5,     0,     0,     5,     0,     0,     5,     0,
       1,     0,     1,     3,     1,     0,     5,     0,     1,     3,
       4,     0,     3,     0,     3,     0,     0,     0,    15,     0,
       0,     0,     0,     0,     0,     0,     0,    24,     4,     0,
       1,     1,     3,     1,     4,     1,     2,     1,     1,     1,
       1,     5,     5,     1,     1,     1,     1,     0,     3,     0,
       3,     1,     0,     3,     0,     3,     4,     2,     4,     2,
       0,     4,     2,     4,     3,     1,     1,     1,     1,     1,
       1,     1,     1,     3,     2,     2,     3,     3,     2,     2,
       2,     1,     2,     1,     0,     3,     2,     1,     2,     2,
       2,     1,     2,     1,     2,     2,     2,     2,     2,     2,
       1,     2,     1,     1,     1,     1,     1,     0,     3,     6,
       1,     3,     1,     3,     1,     1,     1,     1,     1,     1,
       3,     1,     3,     0,     5,     1,     1,     1,     1,     2,
       0,     2,     0,     1,     0,     5,     4,     0,     5,     0,
       0,     5,     0,     1,     3,     2,     1,     1,     1,     4,
       0,     1,     3,     1,     0,     1,     3,     1,     1,     2,
       0,     1,     0,     1,     2,     0,     5,     4,     0,     4,
       1,     3,     1,     4,     1,     3,     1,     1,     1,     0,
       2,     1,     2,     1,     3,     1,     4,     6,     1,     1,
       2,     4,     1,     0,     0,     0,    15,     0,     0,     0,
      15,     0,     0,     0,    15,     1,     1,     2,     0,     5,
       2,     1,     0,     4,     0,     1,     3,     1,     1,     0,
       1,     2,     1,     1,     0,     5,     0,     8,     2,     0,
       2,     0,     1,     2,     2,     0,     0,     0,     0,    17,
       1,     0,     1,     2,     0,     8,     1,     3,     1,     2,
       1,     1,     0,     1,     2,     0,     0,    11,     2,     0,
       1,     4,     0,     1,     3,     1
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       3,    52,     0,     2,     4,     6,     1,     5,     9,   339,
       0,     0,     0,    10,    11,     0,     8,    86,    85,   345,
       0,   343,   340,   341,     0,     0,     0,   342,    15,     0,
     344,    16,    13,   346,     0,     0,    19,     0,    12,     0,
      17,    26,    25,    43,    30,    44,    45,    46,    31,    50,
      32,    33,    34,    35,    47,    48,    36,    37,    38,    39,
      40,    41,    49,    42,    51,     0,    18,    20,     0,    23,
      27,    28,    29,     0,    86,    85,    82,   101,   103,   102,
      99,   104,    96,    81,    73,    80,    76,    79,    77,    74,
      98,    78,    97,    75,   100,   105,     0,     0,    55,    68,
      70,    87,    58,    57,    89,    92,    94,    95,    93,    59,
      60,    61,    62,    63,    65,    66,    64,    67,   347,    14,
      21,     0,     0,    69,     0,     0,     0,     0,     0,     0,
       0,     0,     7,    56,     0,     0,     0,     0,    22,    24,
     127,   131,   176,   180,   354,   358,   362,   397,    71,     0,
     136,     0,     0,     0,   328,   189,     0,     0,     0,     0,
       0,     0,     0,   112,     0,    83,   267,   267,   241,   206,
     211,   251,   267,     0,     0,   247,     0,   107,   267,   243,
     253,     0,     0,   110,    90,   197,   198,   199,   106,   117,
       0,   195,   200,     0,     0,     0,     0,     0,   181,     0,
       0,     0,     0,     0,     0,    72,     0,   339,     0,     0,
     217,   222,     0,     0,     0,   239,   240,   265,   266,   249,
     250,     0,   242,     0,     0,     0,   252,   238,   264,   267,
     219,     0,   248,     0,     0,   290,   246,     0,   254,     0,
       0,     0,    52,   196,   287,     0,   292,   339,     0,     0,
       0,   339,     0,   339,     0,     0,   337,     0,   339,   139,
     275,   274,   277,   276,   279,   278,     0,     0,   270,   272,
     215,   124,     0,   122,    84,   283,     0,   281,   208,   210,
     213,   224,     0,   112,   111,     0,     0,   114,     0,     0,
     245,     0,     0,     0,     0,     0,   147,   332,     0,   330,
     317,     0,   193,     0,   190,   191,     0,     0,     0,   336,
       0,   334,   318,     0,     0,     0,     0,     0,   144,     0,
     268,     0,     0,     0,   118,     0,     0,   280,     0,   221,
     267,   120,   267,   267,   267,   267,   267,   262,   267,     0,
       0,   260,   267,   267,   263,   116,   119,   203,   204,   113,
       0,   289,     0,     0,     0,   218,   223,   216,   128,   291,
     173,   171,   150,   149,   153,   146,     0,   145,   327,   339,
       0,     0,   188,     0,   338,   182,   329,     0,   333,   339,
       0,   363,   288,     0,    88,   339,     0,   320,     0,   271,
     273,     0,   123,     0,   282,   121,   256,   261,   257,   234,
     235,   255,   267,   267,   259,   258,   115,     0,   201,   202,
     320,     0,     0,   151,   156,   293,   148,   331,   177,     0,
     192,     0,   355,   335,   359,   320,     0,     0,   140,   142,
     143,     0,     0,     0,     0,   285,   286,     0,   237,   236,
       0,     0,   174,   172,     0,   154,     0,   320,   194,     0,
     320,   320,     0,   398,   138,   339,   319,     0,   269,   125,
     284,   108,     0,   339,     0,     0,     0,   183,     0,     0,
     372,     0,   365,   366,   320,   141,   137,   320,   339,     0,
     308,   339,   133,     0,     0,     0,     0,   371,   368,     0,
     367,   401,     0,     0,   152,     0,     0,   167,   339,     0,
     339,   339,   370,   374,   339,     0,     0,   400,   402,     0,
     129,   155,   134,   165,   320,     0,   184,     0,     0,     0,
     379,     0,   339,   404,     0,   403,   109,     0,   299,   178,
       0,   356,   360,   339,   384,   386,   369,   378,   380,   382,
     383,   364,   409,     0,   339,     0,     0,   297,   294,   302,
       0,   377,     0,   375,   339,   339,   381,     0,     0,     0,
       0,   168,   339,     0,     0,   300,   159,   185,   373,   339,
       0,   389,   339,   399,     0,   166,     0,     0,   339,   339,
       0,   157,   310,   322,   376,     0,     0,   391,   408,     0,
     406,     0,   169,   296,     0,     0,   339,     0,     0,     0,
       0,   186,   321,   323,   385,   388,     0,   395,   412,   339,
     170,   298,   295,   339,     0,   303,   306,   307,   339,     0,
       0,   325,     0,   324,   392,   390,     0,     0,     0,   339,
     405,   411,   413,   407,   305,   301,   339,     0,   160,   162,
     164,   231,   225,   226,   227,   228,   229,   230,   232,   314,
     311,   205,     0,   339,     0,     0,   393,   394,     0,   415,
     414,   304,   158,   339,   315,   352,     0,   313,     0,   348,
     349,   309,     0,     0,   339,   387,   389,   163,     0,   312,
       0,   233,     0,   350,   132,   326,     0,   391,     0,   316,
     187,   419,   351,     0,   422,   420,   418,     0,   310,   339,
     416,   425,     0,   423,     0,   421,   339,     0,   424,   417
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,     4,     8,    10,    15,    37,    38,    32,
      35,    65,    66,    67,    68,    69,    70,    71,    72,   182,
      96,    97,    98,    99,   134,   160,   100,   183,   213,    21,
     102,   135,   103,   137,   104,   105,   106,   107,   108,   184,
     235,   477,   185,   186,   187,   286,   287,   188,   345,   272,
     273,   323,   109,   124,   152,   410,   110,   125,   153,   497,
     111,   136,   162,   318,   427,   428,   387,   364,   365,   366,
     414,   444,   446,   464,   582,   597,   637,   638,   639,   514,
     527,   560,   561,   367,   412,   411,   112,   126,   154,   447,
     113,   127,   155,   250,   421,   484,   530,   583,   622,   198,
     303,   304,   305,   189,   190,   346,   650,   191,   223,   224,
     225,   209,   282,   651,   347,   192,   237,   348,   215,   228,
     217,   267,   268,   269,   218,   276,   277,   326,   437,   245,
     383,   289,   296,   416,   549,   564,   563,   566,   580,   614,
     615,   616,   479,   599,   652,   666,   667,   480,   309,   432,
     601,   602,   603,   654,   196,   200,   298,   299,   202,   310,
     311,   257,   375,   300,    12,    22,    23,   668,   669,   670,
     114,   128,   156,   450,   115,   129,   157,   451,   116,   130,
     158,   425,   471,   472,   473,   503,   488,   520,   552,   553,
     536,   537,   538,   539,   554,   540,   555,   587,   607,   625,
     628,   117,   131,   159,   474,   506,   507,   508,   543,   589,
     590,   523,   630,   631,   632,   676,   704,   694,   696,   698,
     702,   703
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -509
static const yytype_int16 yypact[] =
{
      23,  -509,    50,    23,  -509,  -509,  -509,  -509,   -57,  -509,
       9,   -39,    32,  -509,  -509,    70,  -509,    27,   -15,  -509,
      57,  -509,    32,  -509,    95,   130,   134,  -509,   139,    65,
      89,  -509,   153,  -509,   187,   102,   535,   351,  -509,   100,
    -509,  -509,  -509,  -509,  -509,  -509,  -509,  -509,  -509,  -509,
    -509,  -509,  -509,  -509,  -509,  -509,  -509,  -509,  -509,  -509,
    -509,  -509,  -509,  -509,  -509,   108,   535,  -509,    -3,  -509,
    -509,  -509,  -509,   110,   206,    64,  -509,  -509,  -509,  -509,
    -509,  -509,  -509,  -509,  -509,  -509,  -509,  -509,  -509,  -509,
    -509,  -509,  -509,  -509,  -509,  -509,   183,   461,  -509,  -509,
    -509,   126,  -509,  -509,  -509,  -509,  -509,  -509,  -509,  -509,
    -509,  -509,  -509,  -509,  -509,  -509,  -509,  -509,  -509,  -509,
    -509,    23,   535,  -509,   154,   155,   158,   166,   161,   168,
     173,   214,  -509,  -509,   180,   171,   144,   229,  -509,  -509,
    -509,  -509,  -509,  -509,  -509,  -509,  -509,  -509,  -509,   198,
    -509,   160,   159,   156,   184,   172,   192,   194,   163,   178,
     231,   257,   232,    15,   167,  -509,   -45,   -45,   169,   -28,
     170,   169,   -45,   233,   186,   174,   -32,  -509,   -45,   175,
     169,    -2,   176,  -509,  -509,  -509,  -509,  -509,  -509,  -509,
      55,  -509,  -509,   262,   213,   177,   199,   181,  -509,   185,
     203,   188,   204,   262,   260,  -509,   189,  -509,    36,   191,
    -509,  -509,   281,   195,   283,  -509,  -509,  -509,  -509,  -509,
    -509,   140,  -509,   169,   191,   169,  -509,  -509,  -509,   -45,
     196,   211,  -509,   287,   288,   267,  -509,   169,  -509,   289,
     291,   296,   -17,  -509,  -509,   275,   218,  -509,   262,   297,
     261,  -509,   262,  -509,   262,   284,  -509,   230,  -509,   219,
    -509,  -509,  -509,  -509,  -509,  -509,   217,   -19,  -509,   309,
    -509,  -509,   -36,  -509,  -509,  -509,    35,  -509,  -509,  -509,
    -509,  -509,   174,  -509,  -509,   301,    38,  -509,   260,   234,
    -509,   215,   222,   -45,   260,   260,     8,  -509,    56,  -509,
    -509,   294,   221,   225,   227,  -509,   302,    59,   303,  -509,
      60,  -509,  -509,   304,   260,   322,   235,   237,   305,   140,
    -509,   140,   140,   228,  -509,   281,   236,  -509,   283,  -509,
     -45,  -509,   -45,   -45,   -45,   -45,   -45,  -509,   -45,   299,
     258,  -509,   -45,   -45,  -509,  -509,  -509,  -509,  -509,  -509,
     288,  -509,   262,   306,   311,  -509,  -509,  -509,  -509,  -509,
    -509,  -509,  -509,  -509,   266,  -509,   334,  -509,  -509,  -509,
     260,   335,  -509,   297,  -509,  -509,  -509,   260,  -509,  -509,
     260,  -509,  -509,   314,  -509,  -509,   260,   273,    -6,  -509,
    -509,   344,  -509,   136,  -509,  -509,  -509,  -509,  -509,  -509,
    -509,  -509,   -45,   -45,  -509,  -509,  -509,   326,  -509,  -509,
     273,   334,   334,  -509,   282,  -509,  -509,  -509,  -509,   252,
    -509,   292,  -509,  -509,  -509,   273,   260,    63,  -509,  -509,
    -509,   260,   355,   259,   269,  -509,  -509,   274,  -509,  -509,
     260,   358,  -509,  -509,   272,  -509,   298,   273,  -509,   260,
     273,   273,   312,  -509,  -509,  -509,  -509,   356,  -509,  -509,
    -509,  -509,   280,  -509,   285,   262,   375,  -509,   377,   380,
     384,   381,   312,  -509,   273,  -509,  -509,   273,  -509,   293,
    -509,  -509,   371,   313,   378,   318,   319,   122,  -509,   323,
    -509,   317,   337,   308,  -509,   321,   260,   359,  -509,   260,
    -509,  -509,  -509,   353,  -509,   398,   419,   317,  -509,   213,
    -509,  -509,  -509,  -509,   273,   327,  -509,   328,   329,   331,
       2,   332,   389,  -509,   336,  -509,  -509,   338,    40,  -509,
     397,  -509,  -509,  -509,  -509,  -509,  -509,     2,  -509,  -509,
    -509,  -509,  -509,   391,  -509,   426,   342,  -509,  -509,   393,
     260,  -509,    68,  -509,  -509,  -509,  -509,   343,   346,   340,
      78,  -509,  -509,   348,   349,  -509,   360,  -509,  -509,  -509,
     420,   365,  -509,  -509,   443,  -509,   426,   354,  -509,  -509,
     357,  -509,   425,   379,  -509,   260,   213,   361,  -509,    87,
    -509,   362,  -509,  -509,   363,   367,   417,   366,   373,   454,
     302,  -509,   379,  -509,  -509,  -509,   213,   -20,   364,  -509,
    -509,  -509,  -509,  -509,    88,  -509,  -509,  -509,   370,    96,
     374,  -509,   468,  -509,  -509,  -509,   334,   334,   446,  -509,
    -509,   364,  -509,  -509,  -509,  -509,   417,   376,   382,  -509,
    -509,  -509,  -509,  -509,  -509,  -509,  -509,  -509,  -509,   190,
    -509,  -509,   383,  -509,   448,   386,  -509,  -509,   260,  -509,
    -509,  -509,  -509,  -509,   385,  -509,   390,   387,   395,   193,
    -509,  -509,   396,   260,  -509,  -509,   365,  -509,   470,  -509,
     473,  -509,   385,  -509,  -509,  -509,   399,   361,   400,  -509,
    -509,   466,  -509,   492,   477,  -509,  -509,   403,   425,  -509,
    -509,  -509,    91,  -509,   474,  -509,  -509,   260,  -509,  -509
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -509,  -509,  -509,   500,  -509,  -509,  -509,  -509,  -509,  -509,
    -509,  -509,  -509,   438,  -509,   388,  -509,  -509,  -509,    13,
    -509,  -509,   411,  -509,  -509,  -509,  -509,  -509,  -509,   -16,
    -509,  -509,  -509,  -509,  -509,  -509,  -509,  -509,  -509,  -509,
    -509,  -509,  -509,   276,  -509,  -509,   162,  -192,  -509,  -509,
     200,  -509,  -509,  -509,  -509,  -509,  -509,  -509,  -509,  -509,
    -509,  -509,  -509,  -509,  -509,    61,  -509,  -509,  -509,  -509,
    -509,  -509,  -509,  -509,  -509,  -509,  -509,  -509,  -152,  -509,
    -509,  -509,   -59,  -509,  -509,  -509,  -509,  -509,  -509,  -509,
    -509,  -509,  -509,  -509,  -509,  -509,  -509,  -509,  -509,  -509,
    -509,  -509,   147,  -509,  -509,  -509,  -509,   339,  -509,  -509,
    -509,  -509,  -509,  -509,  -509,  -509,  -509,  -509,  -161,  -148,
    -151,   207,   209,   205,  -182,  -509,   208,  -509,  -509,  -199,
    -509,  -509,  -509,  -404,  -509,  -509,  -509,  -509,  -509,  -509,
    -105,   -81,  -508,  -165,  -509,  -509,  -509,  -246,    39,  -384,
    -509,  -509,   -68,  -509,  -509,  -509,   300,   197,  -509,  -509,
     164,  -285,   -62,    -9,  -509,  -509,   517,  -509,  -509,  -127,
    -509,  -509,  -509,  -509,  -509,  -509,  -509,  -509,  -509,  -509,
    -509,  -509,  -509,  -509,    72,  -509,  -509,  -509,  -509,   -14,
    -509,  -509,    12,  -509,  -509,  -509,  -509,  -120,  -130,  -509,
    -509,  -509,  -509,  -509,  -509,  -509,  -509,    54,  -509,  -509,
     -47,  -509,  -509,  -509,   -67,  -509,  -509,  -509,  -509,  -509,
    -509,  -141
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -411
static const yytype_int16 yytable[] =
{
      11,   297,   246,   351,   255,   297,   219,   442,   443,   358,
     359,   227,   211,     5,   239,   210,     5,   236,   216,   220,
     222,   101,   360,   226,   232,    20,   441,   270,     1,   381,
     121,   626,   238,   233,    13,    20,   534,    17,    18,    19,
       9,   452,   279,   260,   261,   262,   263,   264,   265,   301,
       6,   627,   214,   308,   577,   313,   208,   546,   361,    16,
     242,   535,   324,   466,   325,   234,   468,   469,   281,  -209,
     594,   595,   547,  -207,    24,   278,   362,   280,    14,  -396,
    -214,   101,   363,   320,   208,   418,    25,   321,   240,   290,
     491,   211,   422,   492,   210,   424,   433,   122,   169,   170,
     321,   430,   641,   642,   643,   644,   645,   646,   647,   648,
     548,   357,  -214,    28,   173,   266,   208,  -361,  -179,   174,
     -52,  -357,  -175,   297,  -353,  -126,  -130,  -339,  -339,  -339,
     528,   329,   -52,   327,   138,   328,   349,    29,   350,   429,
      30,   453,   356,   435,   436,   355,   456,   260,   261,   262,
     263,   264,   265,   407,   368,   461,   369,   376,   378,   369,
     379,   454,    26,   455,   467,   163,   568,    33,   569,   395,
      31,   396,   397,   398,   399,   400,   575,   401,   576,   164,
     165,   404,   405,   166,   167,   608,   635,   609,   636,   705,
      34,   706,    36,   649,    39,   168,   664,   665,   259,   682,
     665,    40,   118,   169,   170,   171,   172,   119,   123,   429,
     -91,   512,   132,  -135,   516,   140,   142,   141,   163,   173,
     143,   144,   656,   657,   174,   145,   146,   175,   148,   147,
     149,   150,   164,   151,   161,   495,   166,   167,   176,   193,
     194,   438,   439,   203,   312,   177,   178,   195,   168,   316,
     201,   179,   180,   204,   197,   199,   169,   170,   171,   172,
     205,   206,   207,   181,   212,   567,   482,   230,   244,   229,
     221,  -212,   173,   256,   247,   231,  -244,   174,   249,   248,
     175,   241,   251,   252,   254,   253,   258,   271,   214,   275,
     266,   176,   283,   274,   285,   288,   291,  -220,   292,   178,
     604,   293,   294,   302,   179,   180,   330,   295,   306,   571,
     315,   314,   322,   317,   352,   374,   181,   526,   319,   353,
     331,   370,   371,   372,   332,   333,   354,   373,   382,   391,
     377,   380,   386,   384,   385,   402,   334,   393,   413,   403,
     415,   426,   419,   408,   335,   336,   337,   338,   409,   431,
     617,   434,    73,   440,   448,   445,    74,    75,   449,   457,
     339,   458,   462,   476,   470,   340,    76,   617,   341,   463,
     312,   459,   640,   675,    77,    78,   460,   478,   465,   483,
     -54,   485,   481,   659,   486,   489,    79,   342,   685,   487,
     617,   494,   343,   344,   605,    80,    81,    82,   496,   499,
     505,   513,   519,   522,    83,    84,   510,   672,    85,    86,
     498,    87,    88,    89,   624,   500,   501,   640,    90,   511,
     504,   509,   709,   524,   550,   529,   531,   532,   533,  -410,
     541,   557,   559,   544,   565,   545,    91,    92,    93,   562,
     572,   574,    94,    95,   573,   578,   579,   585,   581,   586,
     591,   598,   593,   701,   596,   613,   600,   606,   620,   629,
     701,   611,    73,   618,   610,   612,    74,    75,  -161,   493,
     619,   653,   655,   658,   662,   673,    76,   688,   502,   689,
     693,   671,   663,   674,    77,    78,   678,   680,   679,   312,
     -53,   517,   518,   681,   684,   521,    79,   690,   695,   697,
     699,   707,   692,     7,   120,    80,    81,    82,   133,   284,
     139,   677,   406,   542,    83,    84,   475,   592,    85,    86,
     420,    87,    88,    89,   551,   392,   388,   390,    90,   243,
     389,   661,   634,   700,   623,   558,   394,   515,   621,    27,
      41,    42,   683,   423,   490,   570,    91,    92,    93,   556,
      43,   307,    94,    95,    44,   584,   687,   691,    45,    46,
     551,   525,   633,   588,   660,   708,   417,     0,     0,     0,
      47,     0,     0,     0,     0,     0,     0,     0,     0,    48,
      49,    50,     0,     0,    51,     0,     0,     0,    52,    53,
       0,     0,    54,    55,     0,    56,    57,    58,     0,     0,
     588,     0,    59,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      60,    61,    62,     0,     0,     0,    63,    64,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   686
};

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-509)))

#define yytable_value_is_error(Yytable_value) \
  YYID (0)

static const yytype_int16 yycheck[] =
{
       9,   247,   194,   288,   203,   251,   167,   411,   412,   294,
     295,   172,   163,     0,    16,   163,     3,   178,   166,   167,
     168,    37,    14,   171,   175,    12,   410,   209,     5,   314,
      33,    51,   180,    65,    25,    22,    34,     5,     6,     7,
      97,   425,   224,     7,     8,     9,    10,    11,    12,   248,
       0,    71,    97,   252,   562,   254,   101,    17,    50,    98,
       5,    59,    98,   447,   100,    97,   450,   451,   229,    97,
     578,   579,    32,   101,     4,   223,    68,   225,    69,    15,
      97,    97,    74,   102,   101,   370,   101,   106,    90,   237,
     474,   242,   377,   477,   242,   380,   102,   100,    43,    44,
     106,   386,     6,     7,     8,     9,    10,    11,    12,    13,
      70,   293,    97,    18,    59,    79,   101,    53,    54,    64,
     105,    57,    58,   369,    60,    61,    62,     5,     6,     7,
     514,   282,   105,    98,   121,   100,    98,     7,   100,   385,
       6,   426,   293,     7,     8,   293,   431,     7,     8,     9,
      10,    11,    12,   352,    98,   440,   100,    98,    98,   100,
     100,    98,   105,   100,   449,     5,    98,   102,   100,   330,
      31,   332,   333,   334,   335,   336,    98,   338,   100,    19,
      20,   342,   343,    23,    24,    98,    98,   100,   100,    98,
     101,   100,    39,    97,     7,    35,     6,     7,   207,     6,
       7,    99,   102,    43,    44,    45,    46,    99,    98,   455,
       4,   496,    29,    87,   499,    61,    58,    62,     5,    59,
      54,    60,   626,   627,    64,    57,    53,    67,    48,    15,
      59,    87,    19,     4,    36,   481,    23,    24,    78,    80,
      84,   402,   403,    80,   253,    85,    86,    63,    35,   258,
      56,    91,    92,    75,    82,    63,    43,    44,    45,    46,
      29,     4,    30,   103,    97,   550,   465,    81,     6,    36,
     101,   101,    59,    13,    97,   101,   101,    64,    97,    80,
      67,   105,    97,    80,    80,    97,    97,     6,    97,     6,
      79,    78,     5,    98,     6,    28,     7,   101,     7,    86,
     585,     5,    27,     6,    91,    92,     5,    89,    47,   555,
      80,    27,     3,    94,    80,    13,   103,   509,   101,   104,
      19,    27,   101,    98,    23,    24,   104,   100,     6,   101,
      27,    27,    27,    98,    97,    36,    35,   101,    72,    81,
       6,    27,     7,    37,    43,    44,    45,    46,    37,    76,
     596,     7,     1,    27,   102,    73,     5,     6,    66,     4,
      59,   102,     4,     7,    52,    64,    15,   613,    67,    97,
     379,   102,   618,   658,    23,    24,   102,    97,    80,     4,
      29,     4,    97,   629,     4,     4,    35,    86,   673,     5,
     636,    98,    91,    92,   586,    44,    45,    46,    27,    21,
      83,    42,    49,     5,    53,    54,    98,   653,    57,    58,
      97,    60,    61,    62,   606,    97,    97,   663,    67,    98,
      97,    84,   707,     4,    27,    98,    98,    98,    97,    40,
      98,    40,     6,    97,    41,    97,    85,    86,    87,    97,
      97,   101,    91,    92,    98,    97,    97,    27,    88,    84,
       7,    26,    98,   699,    97,    38,    77,    96,     4,    95,
     706,    98,     1,    97,   102,    98,     5,     6,    98,   478,
      97,    97,     4,    27,    98,    27,    15,     7,   487,     6,
      14,    98,   100,    97,    23,    24,   101,   100,    98,   498,
      29,   500,   501,    98,    98,   504,    35,    98,     6,    22,
      97,    27,   102,     3,    66,    44,    45,    46,    97,   233,
     122,   663,   350,   522,    53,    54,   455,   576,    57,    58,
     373,    60,    61,    62,   533,   325,   319,   322,    67,   190,
     321,   636,   613,   698,   602,   544,   328,   498,   600,    22,
       5,     6,   669,   379,   472,   554,    85,    86,    87,   537,
      15,   251,    91,    92,    19,   569,   676,   687,    23,    24,
     569,   507,   609,   572,   631,   706,   369,    -1,    -1,    -1,
      35,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    44,
      45,    46,    -1,    -1,    49,    -1,    -1,    -1,    53,    54,
      -1,    -1,    57,    58,    -1,    60,    61,    62,    -1,    -1,
     609,    -1,    67,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      85,    86,    87,    -1,    -1,    -1,    91,    92,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   674
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,     5,   108,   109,   110,   126,     0,   110,   111,    97,
     112,   270,   271,    25,    69,   113,    98,     5,     6,     7,
     126,   136,   272,   273,     4,   101,   105,   273,    18,     7,
       6,    31,   116,   102,   101,   117,    39,   114,   115,     7,
      99,     5,     6,    15,    19,    23,    24,    35,    44,    45,
      46,    49,    53,    54,    57,    58,    60,    61,    62,    67,
      85,    86,    87,    91,    92,   118,   119,   120,   121,   122,
     123,   124,   125,     1,     5,     6,    15,    23,    24,    35,
      44,    45,    46,    53,    54,    57,    58,    60,    61,    62,
      67,    85,    86,    87,    91,    92,   127,   128,   129,   130,
     133,   136,   137,   139,   141,   142,   143,   144,   145,   159,
     163,   167,   193,   197,   277,   281,   285,   308,   102,    99,
     120,    33,   100,    98,   160,   164,   194,   198,   278,   282,
     286,   309,    29,   129,   131,   138,   168,   140,   126,   122,
      61,    62,    58,    54,    60,    57,    53,    15,    48,    59,
      87,     4,   161,   165,   195,   199,   279,   283,   287,   310,
     132,    36,   169,     5,    19,    20,    23,    24,    35,    43,
      44,    45,    46,    59,    64,    67,    78,    85,    86,    91,
      92,   103,   126,   134,   146,   149,   150,   151,   154,   210,
     211,   214,   222,    80,    84,    63,   261,    82,   206,    63,
     262,    56,   265,    80,    75,    29,     4,    30,   101,   218,
     226,   227,    97,   135,    97,   225,   226,   227,   231,   225,
     226,   101,   226,   215,   216,   217,   226,   225,   226,    36,
      81,   101,   227,    65,    97,   147,   225,   223,   226,    16,
      90,   105,     5,   214,     6,   236,   154,    97,    80,    97,
     200,    97,    80,    97,    80,   236,    13,   268,    97,   270,
       7,     8,     9,    10,    11,    12,    79,   228,   229,   230,
     231,     6,   156,   157,    98,     6,   232,   233,   226,   231,
     226,   225,   219,     5,   150,     6,   152,   153,    28,   238,
     226,     7,     7,     5,    27,    89,   239,   254,   263,   264,
     270,   236,     6,   207,   208,   209,    47,   263,   236,   255,
     266,   267,   270,   236,    27,    80,   270,    94,   170,   101,
     102,   106,     3,   158,    98,   100,   234,    98,   100,   227,
       5,    19,    23,    24,    35,    43,    44,    45,    46,    59,
      64,    67,    86,    91,    92,   155,   212,   221,   224,    98,
     100,   268,    80,   104,   104,   226,   227,   231,   268,   268,
      14,    50,    68,    74,   174,   175,   176,   190,    98,   100,
      27,   101,    98,   100,    13,   269,    98,    27,    98,   100,
      27,   268,     6,   237,    98,    97,    27,   173,   228,   229,
     230,   101,   157,   101,   233,   225,   225,   225,   225,   225,
     225,   225,    36,    81,   225,   225,   153,   236,    37,    37,
     162,   192,   191,    72,   177,     6,   240,   264,   268,     7,
     209,   201,   268,   267,   268,   288,    27,   171,   172,   254,
     268,    76,   256,   102,     7,     7,     8,   235,   225,   225,
      27,   256,   240,   240,   178,    73,   179,   196,   102,    66,
     280,   284,   256,   268,    98,   100,   268,     4,   102,   102,
     102,   268,     4,    97,   180,    80,   256,   268,   256,   256,
      52,   289,   290,   291,   311,   172,     7,   148,    97,   249,
     254,    97,   236,     4,   202,     4,     4,     5,   293,     4,
     291,   256,   256,   270,    98,   254,    27,   166,    97,    21,
      97,    97,   270,   292,    97,    83,   312,   313,   314,    84,
      98,    98,   268,    42,   186,   255,   268,   270,   270,    49,
     294,   270,     5,   318,     4,   314,   154,   187,   256,    98,
     203,    98,    98,    97,    34,    59,   297,   298,   299,   300,
     302,    98,   270,   315,    97,    97,    17,    32,    70,   241,
      27,   270,   295,   296,   301,   303,   299,    40,   270,     6,
     188,   189,    97,   243,   242,    41,   244,   268,    98,   100,
     270,   254,    97,    98,   101,    98,   100,   249,    97,    97,
     245,    88,   181,   204,   296,    27,    84,   304,   270,   316,
     317,     7,   189,    98,   249,   249,    97,   182,    26,   250,
      77,   257,   258,   259,   268,   154,    96,   305,    98,   100,
     102,    98,    98,    38,   246,   247,   248,   254,    97,    97,
       4,   269,   205,   259,   154,   306,    51,    71,   307,    95,
     319,   320,   321,   317,   248,    98,   100,   183,   184,   185,
     254,     6,     7,     8,     9,    10,    11,    12,    13,    97,
     213,   220,   251,    97,   260,     4,   240,   240,    27,   254,
     321,   247,    98,   100,     6,     7,   252,   253,   274,   275,
     276,    98,   254,    27,    97,   268,   322,   185,   101,    98,
     100,    98,     6,   276,    98,   268,   270,   304,     7,     6,
      98,   305,   102,    14,   324,     6,   325,    22,   326,    97,
     250,   254,   327,   328,   323,    98,   100,    27,   328,   268
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  However,
   YYFAIL appears to be in use.  Nevertheless, it is formally deprecated
   in Bison 2.4.2's NEWS entry, where a plan to phase it out is
   discussed.  */

#define YYFAIL		goto yyerrlab
#if defined YYFAIL
  /* This is here to suppress warnings from the GCC cpp's
     -Wunused-macros.  Normally we don't worry about that warning, but
     some users do, and we want to make it easy for users to remove
     YYFAIL uses, which will produce warnings from Bison 2.5.  */
#endif

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (parserPtr, YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))

/* Error token number */
#define YYTERROR	1
#define YYERRCODE	256


/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */
#ifdef YYLEX_PARAM
# define YYLEX yylex (&yylval, YYLEX_PARAM)
#else
# define YYLEX yylex (&yylval, parserPtr)
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value, parserPtr); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, struct Parser *parserPtr)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep, parserPtr)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
    struct Parser *parserPtr;
#endif
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
  YYUSE (parserPtr);
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, struct Parser *parserPtr)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep, parserPtr)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
    struct Parser *parserPtr;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep, parserPtr);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule, struct Parser *parserPtr)
#else
static void
yy_reduce_print (yyvsp, yyrule, parserPtr)
    YYSTYPE *yyvsp;
    int yyrule;
    struct Parser *parserPtr;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       , parserPtr);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule, parserPtr); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULL, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULL;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - Assume YYFAIL is not used.  It's too flawed to consider.  See
       <http://lists.gnu.org/archive/html/bison-patches/2009-12/msg00024.html>
       for details.  YYERROR is fine as it does not invoke this
       function.
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULL, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, struct Parser *parserPtr)
#else
static void
yydestruct (yymsg, yytype, yyvaluep, parserPtr)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
    struct Parser *parserPtr;
#endif
{
  YYUSE (yyvaluep);
  YYUSE (parserPtr);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YYUSE (yytype);
}




/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (struct Parser *parserPtr)
#else
int
yyparse (parserPtr)
    struct Parser *parserPtr;
#endif
#endif
{
/* The lookahead symbol.  */
int yychar;


#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
/* Default value used for initialization, for pacifying older GCCs
   or non-GCC compilers.  */
static YYSTYPE yyval_default;
# define YY_INITIAL_VALUE(Value) = Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval YY_INITIAL_VALUE(yyval_default);

    /* Number of syntax errors so far.  */
    int yynerrs;

    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss_alloc, yyss);
	YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
/* Line 1787 of yacc.c  */
#line 1596 "parser-smi.y"
    {
        (yyval.err) = 0;
    }
    break;

  case 3:
/* Line 1787 of yacc.c  */
#line 1600 "parser-smi.y"
    {
	(yyval.err) = 0;
    }
    break;

  case 4:
/* Line 1787 of yacc.c  */
#line 1606 "parser-smi.y"
    { (yyval.err) = 0; }
    break;

  case 5:
/* Line 1787 of yacc.c  */
#line 1608 "parser-smi.y"
    { (yyval.err) = 0; }
    break;

  case 6:
/* Line 1787 of yacc.c  */
#line 1616 "parser-smi.y"
    {
			    thisParserPtr->firstStatementLine = thisParserPtr->line;
			    thisParserPtr->currentDecl = SMI_DECL_MODULE;
			    
			    thisParserPtr->modulePtr = findModuleByName((yyvsp[(1) - (1)].id));
			    if (!thisParserPtr->modulePtr) {
				thisParserPtr->modulePtr =
				    addModule((yyvsp[(1) - (1)].id),
					      smiStrdup(thisParserPtr->path),
					      0,
					      thisParserPtr);
				thisParserPtr->modulePtr->
				    numImportedIdentifiers = 0;
				thisParserPtr->modulePtr->
				    numStatements = 0;
				thisParserPtr->modulePtr->
				    numModuleIdentities = 0;
				if (!strcmp((yyvsp[(1) - (1)].id), "SNMPv2-SMI")) {
			            /*
				     * SNMPv2-SMI is an SMIv2 module
				     * that cannot be identified by
				     * importing from SNMPv2-SMI.
				     */
				    thisModulePtr->export.language =
					SMI_LANGUAGE_SMIV2;
				}
			    } else {
			        smiPrintError(thisParserPtr,
					      ERR_MODULE_ALREADY_LOADED,
					      (yyvsp[(1) - (1)].id));
				/*
				 * this aborts parsing the whole file,
				 * not only the current module.
				 */
				YYABORT;
			    }
			}
    break;

  case 7:
/* Line 1787 of yacc.c  */
#line 1660 "parser-smi.y"
    {
			    if (thisModulePtr->export.language == SMI_LANGUAGE_UNKNOWN)
				thisModulePtr->export.language = SMI_LANGUAGE_SMIV1;
			    checkModuleName(thisParserPtr, thisModulePtr);
			    checkModuleIdentity(thisParserPtr, thisModulePtr);
			    checkObjects(thisParserPtr, thisModulePtr);
			    checkTypes(thisParserPtr, thisModulePtr);
			    checkDefvals(thisParserPtr, thisModulePtr);
			    checkImportsUsage(thisParserPtr, thisModulePtr);
			    smiCheckTypeUsage(thisParserPtr, thisModulePtr);
			    
			    thisParserPtr->capabilitiesModulePtr = NULL;

                            (yyval.err) = 0;
			}
    break;

  case 8:
/* Line 1787 of yacc.c  */
#line 1678 "parser-smi.y"
    { (yyval.err) = 0; }
    break;

  case 9:
/* Line 1787 of yacc.c  */
#line 1680 "parser-smi.y"
    { (yyval.err) = 0; }
    break;

  case 10:
/* Line 1787 of yacc.c  */
#line 1684 "parser-smi.y"
    { }
    break;

  case 11:
/* Line 1787 of yacc.c  */
#line 1686 "parser-smi.y"
    {
                            thisModulePtr->export.language = SMI_LANGUAGE_SPPI;
                        }
    break;

  case 12:
/* Line 1787 of yacc.c  */
#line 1695 "parser-smi.y"
    { (yyval.err) = 0; }
    break;

  case 13:
/* Line 1787 of yacc.c  */
#line 1697 "parser-smi.y"
    { (yyval.err) = 0; }
    break;

  case 14:
/* Line 1787 of yacc.c  */
#line 1701 "parser-smi.y"
    {
			    thisParserPtr->firstStatementLine = thisParserPtr->line;
			    thisParserPtr->currentDecl = SMI_DECL_MODULE;

			    if ((thisModulePtr->export.language != SMI_LANGUAGE_SMIV2) &&
                                (thisModulePtr->export.language != SMI_LANGUAGE_SPPI))
				thisModulePtr->export.language = SMI_LANGUAGE_SMIV1;
			    
			    (yyval.err) = 0;
			}
    break;

  case 15:
/* Line 1787 of yacc.c  */
#line 1715 "parser-smi.y"
    { (yyval.err) = 0; }
    break;

  case 16:
/* Line 1787 of yacc.c  */
#line 1717 "parser-smi.y"
    {
                            if (thisParserPtr->modulePtr->export.language ==
                                 SMI_LANGUAGE_SPPI)
                                smiPrintError(thisParserPtr, ERR_SMI_CONSTRUCT_IN_PIB, "EXPORTS");
                            
			    thisParserPtr->firstStatementLine = thisParserPtr->line;
			    thisParserPtr->currentDecl = SMI_DECL_MODULE;

			    if (strcmp(thisParserPtr->modulePtr->export.name,
				       "RFC1155-SMI") &&
				strcmp(thisParserPtr->modulePtr->export.name,
				       "RFC1065-SMI")) {
			        smiPrintError(thisParserPtr, ERR_EXPORTS);
			    }
			}
    break;

  case 17:
/* Line 1787 of yacc.c  */
#line 1734 "parser-smi.y"
    { (yyval.err) = 0; }
    break;

  case 18:
/* Line 1787 of yacc.c  */
#line 1738 "parser-smi.y"
    { (yyval.err) = 0; }
    break;

  case 19:
/* Line 1787 of yacc.c  */
#line 1740 "parser-smi.y"
    { (yyval.err) = 0; }
    break;

  case 20:
/* Line 1787 of yacc.c  */
#line 1745 "parser-smi.y"
    { (yyval.err) = 0; }
    break;

  case 21:
/* Line 1787 of yacc.c  */
#line 1747 "parser-smi.y"
    { (yyval.err) = 0; }
    break;

  case 22:
/* Line 1787 of yacc.c  */
#line 1753 "parser-smi.y"
    {
			    Import      *importPtr;
			    Module      *modulePtr;
                            
			    /*
			     * Recursively call the parser to suffer
			     * the IMPORTS, if the module is not yet
			     * loaded.
			     */
			    modulePtr = findModuleByName((yyvsp[(3) - (3)].id));
			    if (!modulePtr) {
				modulePtr = loadModule((yyvsp[(3) - (3)].id), thisParserPtr);
			    }
			    checkImports(modulePtr, thisParserPtr);

			    if (modulePtr && !strcmp((yyvsp[(3) - (3)].id), "SNMPv2-SMI")) {
			        /*
				 * A module that imports a macro or
				 * type definition from SNMPv2-SMI
				 * seems to be SMIv2 style - but only if
                                 * it is not SPPI yet.
				 */
                                if (thisModulePtr->export.language != SMI_LANGUAGE_SPPI) {
				    for (importPtr =
					     thisModulePtr->firstImportPtr;
				         importPtr;
				         importPtr = importPtr->nextPtr) {
				        if ((!strcmp(importPtr->export.module,
						     (yyvsp[(3) - (3)].id))) &&
					    ((importPtr->kind == KIND_MACRO) ||
					     (importPtr->kind == KIND_TYPE))) {
					    thisModulePtr->export.language =
					        SMI_LANGUAGE_SMIV2;
				        }
				    }
                                }
			    }

			    smiFree((yyvsp[(3) - (3)].id));
			}
    break;

  case 23:
/* Line 1787 of yacc.c  */
#line 1796 "parser-smi.y"
    { (yyval.err) = 0; }
    break;

  case 24:
/* Line 1787 of yacc.c  */
#line 1799 "parser-smi.y"
    { (yyval.err) = 0; }
    break;

  case 25:
/* Line 1787 of yacc.c  */
#line 1806 "parser-smi.y"
    {
			    addImport((yyvsp[(1) - (1)].id), thisParserPtr);
			    thisParserPtr->modulePtr->numImportedIdentifiers++;
			    (yyval.id) = 0;
			}
    break;

  case 26:
/* Line 1787 of yacc.c  */
#line 1812 "parser-smi.y"
    {
			    addImport((yyvsp[(1) - (1)].id), thisParserPtr);
			    thisParserPtr->modulePtr->numImportedIdentifiers++;
			    (yyval.id) = 0;
			}
    break;

  case 27:
/* Line 1787 of yacc.c  */
#line 1818 "parser-smi.y"
    {
			    addImport(smiStrdup((yyvsp[(1) - (1)].id)), thisParserPtr);
			    thisParserPtr->modulePtr->numImportedIdentifiers++;
			    (yyval.id) = 0;
			}
    break;

  case 28:
/* Line 1787 of yacc.c  */
#line 1834 "parser-smi.y"
    {
                            /*
                             * There are PIBs that import e.g. Counter64 - so
                             * don't complain here about SMI keywords.
                             */
                           /* if (thisParserPtr->modulePtr->export.language == SMI_LANGUAGE_SPPI)
                              smiPrintError(thisParserPtr, ERR_SMI_CONSTRUCT_IN_PIB, $1);*/
                            (yyval.id) = (yyvsp[(1) - (1)].id);
                        }
    break;

  case 29:
/* Line 1787 of yacc.c  */
#line 1844 "parser-smi.y"
    {
                            if (thisParserPtr->modulePtr->export.language != SMI_LANGUAGE_SPPI)
				smiPrintError(thisParserPtr, ERR_SPPI_TYPE_IN_MIB, (yyvsp[(1) - (1)].id));
                            (yyval.id) = (yyvsp[(1) - (1)].id);
                        }
    break;

  case 52:
/* Line 1787 of yacc.c  */
#line 1878 "parser-smi.y"
    {
			    checkNameLen(thisParserPtr, (yyvsp[(1) - (1)].id),
					 ERR_MODULENAME_32, ERR_MODULENAME_64);
			    (yyval.id) = (yyvsp[(1) - (1)].id);
			}
    break;

  case 53:
/* Line 1787 of yacc.c  */
#line 1890 "parser-smi.y"
    { (yyval.err) = 0; }
    break;

  case 54:
/* Line 1787 of yacc.c  */
#line 1892 "parser-smi.y"
    { (yyval.err) = 0; }
    break;

  case 55:
/* Line 1787 of yacc.c  */
#line 1897 "parser-smi.y"
    { (yyval.err) = 0; }
    break;

  case 56:
/* Line 1787 of yacc.c  */
#line 1899 "parser-smi.y"
    { (yyval.err) = 0; }
    break;

  case 57:
/* Line 1787 of yacc.c  */
#line 1903 "parser-smi.y"
    { 
			    thisParserPtr->modulePtr->numStatements++;
			    (yyval.err) = 0;
			}
    break;

  case 58:
/* Line 1787 of yacc.c  */
#line 1908 "parser-smi.y"
    { 
			    thisParserPtr->modulePtr->numStatements++;
			    (yyval.err) = 0;
			}
    break;

  case 59:
/* Line 1787 of yacc.c  */
#line 1913 "parser-smi.y"
    { 
			    thisParserPtr->modulePtr->numStatements++;
			    (yyval.err) = 0;
			}
    break;

  case 60:
/* Line 1787 of yacc.c  */
#line 1918 "parser-smi.y"
    { 
			    thisParserPtr->modulePtr->numStatements++;
			    (yyval.err) = 0;
			}
    break;

  case 61:
/* Line 1787 of yacc.c  */
#line 1923 "parser-smi.y"
    { 
			    thisParserPtr->modulePtr->numStatements++;
			    (yyval.err) = 0;
			}
    break;

  case 62:
/* Line 1787 of yacc.c  */
#line 1928 "parser-smi.y"
    { 
			    thisParserPtr->modulePtr->numStatements++;
			    (yyval.err) = 0;
			}
    break;

  case 63:
/* Line 1787 of yacc.c  */
#line 1933 "parser-smi.y"
    { 
			    thisParserPtr->modulePtr->numStatements++;
			    (yyval.err) = 0;
			}
    break;

  case 64:
/* Line 1787 of yacc.c  */
#line 1938 "parser-smi.y"
    { 
			    thisParserPtr->modulePtr->numStatements++;
			    (yyval.err) = 0;
			}
    break;

  case 65:
/* Line 1787 of yacc.c  */
#line 1943 "parser-smi.y"
    { 
			    thisParserPtr->modulePtr->numStatements++;
			    (yyval.err) = 0;
			}
    break;

  case 66:
/* Line 1787 of yacc.c  */
#line 1948 "parser-smi.y"
    {
			    thisParserPtr->modulePtr->numStatements++;
			    (yyval.err) = 0;
			}
    break;

  case 67:
/* Line 1787 of yacc.c  */
#line 1953 "parser-smi.y"
    { 
			    thisParserPtr->modulePtr->numStatements++;
			    (yyval.err) = 0;
			}
    break;

  case 68:
/* Line 1787 of yacc.c  */
#line 1958 "parser-smi.y"
    { 
			    thisParserPtr->modulePtr->numStatements++;
			    (yyval.err) = 0;
			}
    break;

  case 69:
/* Line 1787 of yacc.c  */
#line 1963 "parser-smi.y"
    {
			    smiPrintError(thisParserPtr,
					  ERR_FLUSH_DECLARATION);
			    yyerrok;
			    (yyval.err) = 1;
			}
    break;

  case 70:
/* Line 1787 of yacc.c  */
#line 1977 "parser-smi.y"
    {
			    Macro *macroPtr;

			    thisParserPtr->firstStatementLine = thisParserPtr->line;
			    thisParserPtr->currentDecl = SMI_DECL_MACRO;

			    macroPtr = addMacro(smiStrdup((yyvsp[(1) - (1)].id)),
						0, thisParserPtr);
			    setMacroLine(macroPtr, thisParserPtr->firstStatementLine,
					 thisParserPtr);
			}
    break;

  case 71:
/* Line 1787 of yacc.c  */
#line 1989 "parser-smi.y"
    {
			    /*
			     * ASN.1 macros are known to be in these
			     * modules.
			     */
			    if (strcmp(thisParserPtr->modulePtr->export.name,
				       "SNMPv2-SMI") &&
			        strcmp(thisParserPtr->modulePtr->export.name,
				       "SNMPv2-TC") &&
				strcmp(thisParserPtr->modulePtr->export.name,
				       "SNMPv2-CONF") &&
				strcmp(thisParserPtr->modulePtr->export.name,
				       "RFC-1212") &&
				strcmp(thisParserPtr->modulePtr->export.name,
				       "RFC-1215") &&
				strcmp(thisParserPtr->modulePtr->export.name,
				       "RFC1065-SMI") &&
				strcmp(thisParserPtr->modulePtr->export.name,
				       "RFC1155-SMI") &&
                                strcmp(thisParserPtr->modulePtr->export.name,
                                       "COPS-PR-SPPI") &&
                                strcmp(thisParserPtr->modulePtr->export.name,
                                       "COPS-PR-SPPI-TC")) {
			        smiPrintError(thisParserPtr, ERR_MACRO);
			    }
			}
    break;

  case 72:
/* Line 1787 of yacc.c  */
#line 2017 "parser-smi.y"
    {
			    (yyval.err) = 0;
                        }
    break;

  case 73:
/* Line 1787 of yacc.c  */
#line 2022 "parser-smi.y"
    { (yyval.id) = (yyvsp[(1) - (1)].id); }
    break;

  case 74:
/* Line 1787 of yacc.c  */
#line 2023 "parser-smi.y"
    { (yyval.id) = (yyvsp[(1) - (1)].id); }
    break;

  case 75:
/* Line 1787 of yacc.c  */
#line 2024 "parser-smi.y"
    { (yyval.id) = (yyvsp[(1) - (1)].id); }
    break;

  case 76:
/* Line 1787 of yacc.c  */
#line 2025 "parser-smi.y"
    { (yyval.id) = (yyvsp[(1) - (1)].id); }
    break;

  case 77:
/* Line 1787 of yacc.c  */
#line 2026 "parser-smi.y"
    { (yyval.id) = (yyvsp[(1) - (1)].id); }
    break;

  case 78:
/* Line 1787 of yacc.c  */
#line 2027 "parser-smi.y"
    { (yyval.id) = (yyvsp[(1) - (1)].id); }
    break;

  case 79:
/* Line 1787 of yacc.c  */
#line 2028 "parser-smi.y"
    { (yyval.id) = (yyvsp[(1) - (1)].id); }
    break;

  case 80:
/* Line 1787 of yacc.c  */
#line 2029 "parser-smi.y"
    { (yyval.id) = (yyvsp[(1) - (1)].id); }
    break;

  case 81:
/* Line 1787 of yacc.c  */
#line 2030 "parser-smi.y"
    { (yyval.id) = (yyvsp[(1) - (1)].id); }
    break;

  case 82:
/* Line 1787 of yacc.c  */
#line 2031 "parser-smi.y"
    { (yyval.id) = (yyvsp[(1) - (1)].id); }
    break;

  case 83:
/* Line 1787 of yacc.c  */
#line 2035 "parser-smi.y"
    {
			    if (strcmp(thisParserPtr->modulePtr->export.name,
				       "SNMPv2-SMI") &&
			        strcmp(thisParserPtr->modulePtr->export.name,
				       "SNMPv2-TC") &&
				strcmp(thisParserPtr->modulePtr->export.name,
				       "SNMPv2-CONF") &&
				strcmp(thisParserPtr->modulePtr->export.name,
				       "RFC-1212") &&
				strcmp(thisParserPtr->modulePtr->export.name,
				       "RFC1065-SMI") &&
				strcmp(thisParserPtr->modulePtr->export.name,
				       "RFC1155-SMI") && 
                                strcmp(thisParserPtr->modulePtr->export.name,
                                       "COPS-PR-SPPI")) {
			        smiPrintError(thisParserPtr, ERR_CHOICE);
			    }
			}
    break;

  case 84:
/* Line 1787 of yacc.c  */
#line 2055 "parser-smi.y"
    {
			    (yyval.typePtr) = addType(NULL, SMI_BASETYPE_UNKNOWN, 0,
					 thisParserPtr);
			}
    break;

  case 85:
/* Line 1787 of yacc.c  */
#line 2065 "parser-smi.y"
    {
			  (yyval.id) = (yyvsp[(1) - (1)].id);
			}
    break;

  case 86:
/* Line 1787 of yacc.c  */
#line 2070 "parser-smi.y"
    {
			    smiPrintError (thisParserPtr,
					   ERR_BAD_LOWER_IDENTIFIER_CASE,
					   (yyvsp[(1) - (1)].id));
			    /* xxx
			    if ((thisParserPtr->flags & SMI_FLAG_BE_LAX) == 0) {
			        YYERROR;
			    }
			    */
			  (yyval.id) = (yyvsp[(1) - (1)].id);
			}
    break;

  case 87:
/* Line 1787 of yacc.c  */
#line 2085 "parser-smi.y"
    {
			    thisParserPtr->firstStatementLine = thisParserPtr->line;
			    thisParserPtr->currentDecl = SMI_DECL_VALUEASSIGNMENT;

			    checkNameLen(thisParserPtr, (yyvsp[(1) - (1)].id),
					 ERR_OIDNAME_32, ERR_OIDNAME_64);
			    smiCheckObjectName(thisParserPtr,
					       thisModulePtr, (yyvsp[(1) - (1)].id));
			    if (thisModulePtr->export.language == SMI_LANGUAGE_SMIV2)
			    {
			        if (strchr((yyvsp[(1) - (1)].id), '-') &&
				    (strcmp((yyvsp[(1) - (1)].id), "mib-2") ||
				  strcmp(thisModulePtr->export.name, "SNMPv2-SMI"))) {
				    smiPrintError(thisParserPtr,
						  ERR_OIDNAME_INCLUDES_HYPHEN,
						  (yyvsp[(1) - (1)].id));
				}
			    }
			}
    break;

  case 88:
/* Line 1787 of yacc.c  */
#line 2106 "parser-smi.y"
    {
			    Object *objectPtr;
			    
			    objectPtr = (yyvsp[(7) - (8)].objectPtr);
			    smiCheckObjectReuse(thisParserPtr, (yyvsp[(1) - (8)].id), &objectPtr);
			    objectPtr = setObjectName(objectPtr, (yyvsp[(1) - (8)].id), thisParserPtr);
			    deleteObjectFlags(objectPtr, FLAG_INCOMPLETE);
			    setObjectLine(objectPtr, thisParserPtr->firstStatementLine,
					  thisParserPtr);
			    setObjectDecl(objectPtr,
					  SMI_DECL_VALUEASSIGNMENT);
			    (yyval.err) = 0;
			}
    break;

  case 89:
/* Line 1787 of yacc.c  */
#line 2125 "parser-smi.y"
    {
			    thisParserPtr->firstStatementLine = thisParserPtr->line;
			    thisParserPtr->currentDecl = SMI_DECL_TYPEASSIGNMENT;

			    checkNameLen(thisParserPtr, (yyvsp[(1) - (1)].id),
					 ERR_TYPENAME_32, ERR_TYPENAME_64);
			}
    break;

  case 90:
/* Line 1787 of yacc.c  */
#line 2133 "parser-smi.y"
    {
			    Type *typePtr;
			    
			    if (strlen((yyvsp[(1) - (4)].id))) {
				if ((yyvsp[(4) - (4)].typePtr)->export.basetype != SMI_BASETYPE_UNKNOWN) {
				    smiCheckTypeName(thisParserPtr,
						     thisModulePtr, (yyvsp[(1) - (4)].id),
						     thisParserPtr->firstStatementLine);
				}
				setTypeLine((yyvsp[(4) - (4)].typePtr), thisParserPtr->firstStatementLine,
					    thisParserPtr);
				setTypeName((yyvsp[(4) - (4)].typePtr), (yyvsp[(1) - (4)].id));
				(yyval.err) = 0;
			    } else {
				(yyval.err) = 0;
			    }

			    /*
			     * If we are in an SMI module, some type
			     * definitions derived from ASN.1 `INTEGER'
			     * must be modified to libsmi basetypes.
			     */
			    if (thisModulePtr &&
				(!strcmp(thisModulePtr->export.name, "SNMPv2-SMI"))) {
				if (!strcmp((yyvsp[(1) - (4)].id), "Counter32")) {
				    (yyvsp[(4) - (4)].typePtr)->export.basetype = SMI_BASETYPE_UNSIGNED32;
				    setTypeParent((yyvsp[(4) - (4)].typePtr), smiHandle->typeUnsigned32Ptr);
				    if ((yyvsp[(4) - (4)].typePtr)->listPtr) {
					((Range *)(yyvsp[(4) - (4)].typePtr)->listPtr->ptr)->export.minValue.basetype = SMI_BASETYPE_UNSIGNED32;
					((Range *)(yyvsp[(4) - (4)].typePtr)->listPtr->ptr)->export.minValue.value.unsigned32 = 0;
					((Range *)(yyvsp[(4) - (4)].typePtr)->listPtr->ptr)->export.maxValue.basetype = SMI_BASETYPE_UNSIGNED32;
					((Range *)(yyvsp[(4) - (4)].typePtr)->listPtr->ptr)->export.maxValue.value.unsigned32 = 4294967295U;
				    }
				} else if (!strcmp((yyvsp[(1) - (4)].id), "Gauge32")) {
				    (yyvsp[(4) - (4)].typePtr)->export.basetype = SMI_BASETYPE_UNSIGNED32;
				    setTypeParent((yyvsp[(4) - (4)].typePtr), smiHandle->typeUnsigned32Ptr);
				    if ((yyvsp[(4) - (4)].typePtr)->listPtr) {
					((Range *)(yyvsp[(4) - (4)].typePtr)->listPtr->ptr)->export.minValue.basetype = SMI_BASETYPE_UNSIGNED32;
					((Range *)(yyvsp[(4) - (4)].typePtr)->listPtr->ptr)->export.minValue.value.unsigned32 = 0;
					((Range *)(yyvsp[(4) - (4)].typePtr)->listPtr->ptr)->export.maxValue.basetype = SMI_BASETYPE_UNSIGNED32;
					((Range *)(yyvsp[(4) - (4)].typePtr)->listPtr->ptr)->export.maxValue.value.unsigned32 = 4294967295U;
				    }
				} else if (!strcmp((yyvsp[(1) - (4)].id), "Unsigned32")) {
				    (yyvsp[(4) - (4)].typePtr)->export.basetype = SMI_BASETYPE_UNSIGNED32;
				    setTypeParent((yyvsp[(4) - (4)].typePtr), smiHandle->typeUnsigned32Ptr);
				    if ((yyvsp[(4) - (4)].typePtr)->listPtr) {
					((Range *)(yyvsp[(4) - (4)].typePtr)->listPtr->ptr)->export.minValue.basetype = SMI_BASETYPE_UNSIGNED32;
					((Range *)(yyvsp[(4) - (4)].typePtr)->listPtr->ptr)->export.minValue.value.unsigned32 = 0;
					((Range *)(yyvsp[(4) - (4)].typePtr)->listPtr->ptr)->export.maxValue.basetype = SMI_BASETYPE_UNSIGNED32;
					((Range *)(yyvsp[(4) - (4)].typePtr)->listPtr->ptr)->export.maxValue.value.unsigned32 = 4294967295U;
				    }
				} else if (!strcmp((yyvsp[(1) - (4)].id), "TimeTicks")) {
				    (yyvsp[(4) - (4)].typePtr)->export.basetype = SMI_BASETYPE_UNSIGNED32;
				    setTypeParent((yyvsp[(4) - (4)].typePtr), smiHandle->typeUnsigned32Ptr);
				    if ((yyvsp[(4) - (4)].typePtr)->listPtr) {
					((Range *)(yyvsp[(4) - (4)].typePtr)->listPtr->ptr)->export.minValue.basetype = SMI_BASETYPE_UNSIGNED32;
					((Range *)(yyvsp[(4) - (4)].typePtr)->listPtr->ptr)->export.minValue.value.unsigned32 = 0;
					((Range *)(yyvsp[(4) - (4)].typePtr)->listPtr->ptr)->export.maxValue.basetype = SMI_BASETYPE_UNSIGNED32;
					((Range *)(yyvsp[(4) - (4)].typePtr)->listPtr->ptr)->export.maxValue.value.unsigned32 = 4294967295U;
				    }
				} else if (!strcmp((yyvsp[(1) - (4)].id), "Counter64")) {
				    (yyvsp[(4) - (4)].typePtr)->export.basetype = SMI_BASETYPE_UNSIGNED64;
				    if ((yyvsp[(4) - (4)].typePtr)->listPtr) {
					((Range *)(yyvsp[(4) - (4)].typePtr)->listPtr->ptr)->export.minValue.basetype = SMI_BASETYPE_UNSIGNED64;
					((Range *)(yyvsp[(4) - (4)].typePtr)->listPtr->ptr)->export.minValue.value.unsigned64 = 0;
					((Range *)(yyvsp[(4) - (4)].typePtr)->listPtr->ptr)->export.maxValue.basetype = SMI_BASETYPE_UNSIGNED64;
					((Range *)(yyvsp[(4) - (4)].typePtr)->listPtr->ptr)->export.maxValue.value.unsigned64 = SMI_BASETYPE_UNSIGNED64_MAX;
				    }
				    setTypeParent((yyvsp[(4) - (4)].typePtr), smiHandle->typeUnsigned64Ptr);
				}
			    }
			    if (thisModulePtr &&
				(!strcmp(thisModulePtr->export.name, "RFC1155-SMI") ||
				 !strcmp(thisModulePtr->export.name, "RFC1065-SMI"))) {
				if (!strcmp((yyvsp[(1) - (4)].id), "Counter")) {
				    (yyvsp[(4) - (4)].typePtr)->export.basetype = SMI_BASETYPE_UNSIGNED32;
				    setTypeParent((yyvsp[(4) - (4)].typePtr), smiHandle->typeUnsigned32Ptr);
				    if ((yyvsp[(4) - (4)].typePtr)->listPtr) {
					((Range *)(yyvsp[(4) - (4)].typePtr)->listPtr->ptr)->export.minValue.basetype = SMI_BASETYPE_UNSIGNED32;
					((Range *)(yyvsp[(4) - (4)].typePtr)->listPtr->ptr)->export.minValue.value.unsigned32 = 0;
					((Range *)(yyvsp[(4) - (4)].typePtr)->listPtr->ptr)->export.maxValue.basetype = SMI_BASETYPE_UNSIGNED32;
					((Range *)(yyvsp[(4) - (4)].typePtr)->listPtr->ptr)->export.maxValue.value.unsigned32 = 4294967295U;
				    }
				} else if (!strcmp((yyvsp[(1) - (4)].id), "Gauge")) {
				    (yyvsp[(4) - (4)].typePtr)->export.basetype = SMI_BASETYPE_UNSIGNED32;
				    setTypeParent((yyvsp[(4) - (4)].typePtr), smiHandle->typeUnsigned32Ptr);
				    if ((yyvsp[(4) - (4)].typePtr)->listPtr) {
					((Range *)(yyvsp[(4) - (4)].typePtr)->listPtr->ptr)->export.minValue.basetype = SMI_BASETYPE_UNSIGNED32;
					((Range *)(yyvsp[(4) - (4)].typePtr)->listPtr->ptr)->export.minValue.value.unsigned32 = 0;
					((Range *)(yyvsp[(4) - (4)].typePtr)->listPtr->ptr)->export.maxValue.basetype = SMI_BASETYPE_UNSIGNED32;
					((Range *)(yyvsp[(4) - (4)].typePtr)->listPtr->ptr)->export.maxValue.value.unsigned32 = 4294967295U;
				    }
				} else if (!strcmp((yyvsp[(1) - (4)].id), "TimeTicks")) {
				    (yyvsp[(4) - (4)].typePtr)->export.basetype = SMI_BASETYPE_UNSIGNED32;
				    setTypeParent((yyvsp[(4) - (4)].typePtr), smiHandle->typeUnsigned32Ptr);
				    if ((yyvsp[(4) - (4)].typePtr)->listPtr) {
					((Range *)(yyvsp[(4) - (4)].typePtr)->listPtr->ptr)->export.minValue.basetype = SMI_BASETYPE_UNSIGNED32;
					((Range *)(yyvsp[(4) - (4)].typePtr)->listPtr->ptr)->export.minValue.value.unsigned32 = 0;
					((Range *)(yyvsp[(4) - (4)].typePtr)->listPtr->ptr)->export.maxValue.basetype = SMI_BASETYPE_UNSIGNED32;
					((Range *)(yyvsp[(4) - (4)].typePtr)->listPtr->ptr)->export.maxValue.value.unsigned32 = 4294967295U;
				    }
				} else if (!strcmp((yyvsp[(1) - (4)].id), "NetworkAddress")) {
				    setTypeName((yyvsp[(4) - (4)].typePtr), smiStrdup("NetworkAddress"));
				    (yyvsp[(4) - (4)].typePtr)->export.basetype = SMI_BASETYPE_OCTETSTRING;
				    setTypeParent((yyvsp[(4) - (4)].typePtr), findTypeByModuleAndName(
					                   thisModulePtr,
						           "IpAddress"));
				} else if (!strcmp((yyvsp[(1) - (4)].id), "IpAddress")) {
				    typePtr = findTypeByModuleAndName(
					thisModulePtr, "NetworkAddress");
				    if (typePtr) 
					setTypeParent(typePtr, (yyvsp[(4) - (4)].typePtr));
				}
			    }
			    if (thisModulePtr &&
				(!strcmp(thisModulePtr->export.name, "COPS-PR-SPPI"))) {
				if (!strcmp((yyvsp[(1) - (4)].id), "Unsigned32")) {
				    (yyvsp[(4) - (4)].typePtr)->export.basetype = SMI_BASETYPE_UNSIGNED32;
				    setTypeParent((yyvsp[(4) - (4)].typePtr), smiHandle->typeUnsigned32Ptr);
				    if ((yyvsp[(4) - (4)].typePtr)->listPtr) {
					((Range *)(yyvsp[(4) - (4)].typePtr)->listPtr->ptr)->export.minValue.basetype = SMI_BASETYPE_UNSIGNED32;
					((Range *)(yyvsp[(4) - (4)].typePtr)->listPtr->ptr)->export.minValue.value.unsigned32 = 0;
					((Range *)(yyvsp[(4) - (4)].typePtr)->listPtr->ptr)->export.maxValue.basetype = SMI_BASETYPE_UNSIGNED32;
					((Range *)(yyvsp[(4) - (4)].typePtr)->listPtr->ptr)->export.maxValue.value.unsigned32 = 4294967295U;
				    }
				} else if (!strcmp((yyvsp[(1) - (4)].id), "TimeTicks")) {
				    (yyvsp[(4) - (4)].typePtr)->export.basetype = SMI_BASETYPE_UNSIGNED32;
				    setTypeParent((yyvsp[(4) - (4)].typePtr), smiHandle->typeUnsigned32Ptr);
				    if ((yyvsp[(4) - (4)].typePtr)->listPtr) {
					((Range *)(yyvsp[(4) - (4)].typePtr)->listPtr->ptr)->export.minValue.basetype = SMI_BASETYPE_UNSIGNED32;
					((Range *)(yyvsp[(4) - (4)].typePtr)->listPtr->ptr)->export.minValue.value.unsigned32 = 0;
					((Range *)(yyvsp[(4) - (4)].typePtr)->listPtr->ptr)->export.maxValue.basetype = SMI_BASETYPE_UNSIGNED32;
					((Range *)(yyvsp[(4) - (4)].typePtr)->listPtr->ptr)->export.maxValue.value.unsigned32 = 4294967295U;
				    }
				} else if (!strcmp((yyvsp[(1) - (4)].id), "Unsigned64")) {
				    (yyvsp[(4) - (4)].typePtr)->export.basetype = SMI_BASETYPE_UNSIGNED64;
				    if ((yyvsp[(4) - (4)].typePtr)->listPtr) {
					((Range *)(yyvsp[(4) - (4)].typePtr)->listPtr->ptr)->export.minValue.basetype = SMI_BASETYPE_UNSIGNED64;
					((Range *)(yyvsp[(4) - (4)].typePtr)->listPtr->ptr)->export.minValue.value.unsigned64 = 0;
					((Range *)(yyvsp[(4) - (4)].typePtr)->listPtr->ptr)->export.maxValue.basetype = SMI_BASETYPE_UNSIGNED64;
					((Range *)(yyvsp[(4) - (4)].typePtr)->listPtr->ptr)->export.maxValue.value.unsigned64 = SMI_BASETYPE_UNSIGNED64_MAX;
				    }
				    setTypeParent((yyvsp[(4) - (4)].typePtr), smiHandle->typeUnsigned64Ptr);
				} else if (!strcmp((yyvsp[(1) - (4)].id), "Integer64")) {
				    (yyvsp[(4) - (4)].typePtr)->export.basetype = SMI_BASETYPE_INTEGER64;
				    if ((yyvsp[(4) - (4)].typePtr)->listPtr) {
					((Range *)(yyvsp[(4) - (4)].typePtr)->listPtr->ptr)->export.minValue.basetype = SMI_BASETYPE_INTEGER64;
					((Range *)(yyvsp[(4) - (4)].typePtr)->listPtr->ptr)->export.minValue.value.integer64 = SMI_BASETYPE_INTEGER64_MIN;
					((Range *)(yyvsp[(4) - (4)].typePtr)->listPtr->ptr)->export.maxValue.basetype = SMI_BASETYPE_INTEGER64;
					((Range *)(yyvsp[(4) - (4)].typePtr)->listPtr->ptr)->export.maxValue.value.integer64 = SMI_BASETYPE_INTEGER64_MAX;
				    }
				    setTypeParent((yyvsp[(4) - (4)].typePtr), smiHandle->typeInteger64Ptr);
				}
			    }
			}
    break;

  case 91:
/* Line 1787 of yacc.c  */
#line 2291 "parser-smi.y"
    {
			    (yyval.id) = (yyvsp[(1) - (1)].id);
			}
    break;

  case 92:
/* Line 1787 of yacc.c  */
#line 2295 "parser-smi.y"
    {
			    (yyval.id) = smiStrdup((yyvsp[(1) - (1)].id));
			    /*
			     * well known types (keywords in this grammar)
			     * are known to be defined in these modules.
			     */
			    if (strcmp(thisParserPtr->modulePtr->export.name,
				       "SNMPv2-SMI") &&
			        strcmp(thisParserPtr->modulePtr->export.name,
				       "SNMPv2-TC") &&
				strcmp(thisParserPtr->modulePtr->export.name,
				       "SNMPv2-CONF") &&
				strcmp(thisParserPtr->modulePtr->export.name,
				       "RFC-1212") &&
				strcmp(thisParserPtr->modulePtr->export.name,
				       "RFC1065-SMI") &&
				strcmp(thisParserPtr->modulePtr->export.name,
				       "RFC1155-SMI") &&
				strcmp(thisParserPtr->modulePtr->export.name,
				       "COPS-PR-SPPI")) {
			        smiPrintError(thisParserPtr, ERR_TYPE_SMI_OR_SPPI, (yyvsp[(1) - (1)].id));
			    }
			}
    break;

  case 93:
/* Line 1787 of yacc.c  */
#line 2319 "parser-smi.y"
    {
			    (yyval.id) = smiStrdup((yyvsp[(1) - (1)].id));
			    /*
			     * well known types (keywords in this grammar)
			     * are known to be defined in these modules.
			     */
			    if ((strcmp(thisParserPtr->modulePtr->export.name,
					"COPS-PR-SPPI")) &&
				(thisParserPtr->modulePtr->export.language == SMI_LANGUAGE_SPPI))
			        smiPrintError(thisParserPtr, ERR_TYPE_SPPI, (yyvsp[(1) - (1)].id));
                        }
    break;

  case 95:
/* Line 1787 of yacc.c  */
#line 2334 "parser-smi.y"
    {
                            if ((thisParserPtr->modulePtr->export.language == SMI_LANGUAGE_SPPI) &&
                                !findImportByName((yyvsp[(1) - (1)].id), thisParserPtr->modulePtr))
                                smiPrintError(thisParserPtr, ERR_SMI_CONSTRUCT_IN_PIB, (yyvsp[(1) - (1)].id));
                            (yyval.id) = (yyvsp[(1) - (1)].id);
                        }
    break;

  case 106:
/* Line 1787 of yacc.c  */
#line 2359 "parser-smi.y"
    {
			    if ((yyvsp[(1) - (1)].typePtr)->export.name) {
				/*
				 * If we found an already defined type,
				 * we have to inherit a new type structure.
				 * (Otherwise the `Syntax' rule created
				 * a new type for us.)
				 */
				(yyval.typePtr) = duplicateType((yyvsp[(1) - (1)].typePtr), 0, thisParserPtr);
				setTypeDecl((yyval.typePtr), SMI_DECL_TYPEASSIGNMENT);
			    } else {
				(yyval.typePtr) = (yyvsp[(1) - (1)].typePtr);
				setTypeDecl((yyval.typePtr), SMI_DECL_TYPEASSIGNMENT);
			    }
			}
    break;

  case 107:
/* Line 1787 of yacc.c  */
#line 2375 "parser-smi.y"
    {
			    Import *importPtr;

			    thisParserPtr->currentDecl = SMI_DECL_TEXTUALCONVENTION;

			    if (thisModulePtr->export.language == SMI_LANGUAGE_UNKNOWN)
				thisModulePtr->export.language = SMI_LANGUAGE_SMIV2;

			    if (strcmp(thisModulePtr->export.name, "SNMPv2-TC")) {
				importPtr =
				    findImportByName("TEXTUAL-CONVENTION",
						     thisModulePtr);
				if (importPtr) {
				    importPtr->use++;
				} else {
                                    if (thisParserPtr->modulePtr->export.language != SMI_LANGUAGE_SPPI)
				        smiPrintError(thisParserPtr,
						      ERR_MACRO_NOT_IMPORTED,
						      "TEXTUAL-CONVENTION",
						      "SNMPv2-TC");
                                    else
				        smiPrintError(thisParserPtr,
						      ERR_MACRO_NOT_IMPORTED,
						      "TEXTUAL-CONVENTION",
						      "COPS-PR-SPPI");
				}
			    }
			}
    break;

  case 108:
/* Line 1787 of yacc.c  */
#line 2406 "parser-smi.y"
    {
			    checkDescr(thisParserPtr, (yyvsp[(7) - (7)].text));
			}
    break;

  case 109:
/* Line 1787 of yacc.c  */
#line 2411 "parser-smi.y"
    {
			    if (((yyvsp[(11) - (11)].typePtr)) && !((yyvsp[(11) - (11)].typePtr)->export.name)) {
				/*
				 * If the Type we found has just been
				 * defined, we don't have to allocate
				 * a new one.
				 */
				(yyval.typePtr) = (yyvsp[(11) - (11)].typePtr);
			    } else {
				if (!((yyvsp[(11) - (11)].typePtr)))
				    smiPrintError(thisParserPtr, ERR_INTERNAL);
				/*
				 * Otherwise, we have to allocate a
				 * new Type struct, inherited from $10.
				 */
				(yyval.typePtr) = duplicateType((yyvsp[(11) - (11)].typePtr), 0, thisParserPtr);
			    }
			    setTypeDescription((yyval.typePtr), (yyvsp[(7) - (11)].text), thisParserPtr);
			    if ((yyvsp[(9) - (11)].text)) {
				setTypeReference((yyval.typePtr), (yyvsp[(9) - (11)].text), thisParserPtr);
			    }
			    setTypeStatus((yyval.typePtr), (yyvsp[(5) - (11)].status));
			    if ((yyvsp[(3) - (11)].text)) {
				if (smiCheckFormat(thisParserPtr,
						   (yyval.typePtr)->export.basetype, (yyvsp[(3) - (11)].text),
						   thisParserPtr->firstStatementLine)) {
				    setTypeFormat((yyval.typePtr), (yyvsp[(3) - (11)].text));
				}
			    }
			    setTypeDecl((yyval.typePtr), SMI_DECL_TEXTUALCONVENTION);
			}
    break;

  case 110:
/* Line 1787 of yacc.c  */
#line 2443 "parser-smi.y"
    {
			    (yyval.typePtr) = (yyvsp[(1) - (1)].typePtr);
			    setTypeDecl((yyval.typePtr), SMI_DECL_TYPEASSIGNMENT);
			}
    break;

  case 111:
/* Line 1787 of yacc.c  */
#line 2451 "parser-smi.y"
    {
			    if ((yyvsp[(3) - (3)].typePtr)) {
				(yyval.typePtr) = addType(NULL,
					     SMI_BASETYPE_UNKNOWN, 0,
					     thisParserPtr);
				setTypeDecl((yyval.typePtr), SMI_DECL_IMPL_SEQUENCEOF);
				setTypeParent((yyval.typePtr), (yyvsp[(3) - (3)].typePtr));
			    } else {
				(yyval.typePtr) = NULL;
			    }
			}
    break;

  case 112:
/* Line 1787 of yacc.c  */
#line 2470 "parser-smi.y"
    {
			    Type *typePtr;
			    Import *importPtr;

			    (yyval.typePtr) = findTypeByModulenameAndName(
				thisParserPtr->modulePtr->export.name, (yyvsp[(1) - (1)].id));
			    if (! (yyval.typePtr)) {
				importPtr = findImportByName((yyvsp[(1) - (1)].id),
							     thisModulePtr);
				if (!importPtr ||
				    (importPtr->kind == KIND_NOTFOUND)) {
				    /* 
				     * forward referenced type. create it,
				     * marked with FLAG_INCOMPLETE.
				     */
				    typePtr = addType((yyvsp[(1) - (1)].id),
						      SMI_BASETYPE_UNKNOWN,
						      FLAG_INCOMPLETE,
						      thisParserPtr);
				    (yyval.typePtr) = typePtr;
				} else {
				    /*
				     * imported type.
				     * TODO: is this allowed in a SEQUENCE? 
				     */
				    importPtr->use++;
				    (yyval.typePtr) = findTypeByModulenameAndName(
					importPtr->export.module,
					importPtr->export.name);
				    smiFree((yyvsp[(1) - (1)].id));
				}
			    } else {
				smiFree((yyvsp[(1) - (1)].id));
			    }
			}
    break;

  case 113:
/* Line 1787 of yacc.c  */
#line 2510 "parser-smi.y"
    {
			    (yyval.typePtr) = addType(NULL, SMI_BASETYPE_UNKNOWN, 0,
					 thisParserPtr);
			    setTypeList((yyval.typePtr), (yyvsp[(3) - (4)].listPtr));
			}
    break;

  case 114:
/* Line 1787 of yacc.c  */
#line 2518 "parser-smi.y"
    {
			    (yyval.listPtr) = smiMalloc(sizeof(List));
			    (yyval.listPtr)->ptr = (yyvsp[(1) - (1)].objectPtr);
			    (yyval.listPtr)->nextPtr = NULL;
			}
    break;

  case 115:
/* Line 1787 of yacc.c  */
#line 2525 "parser-smi.y"
    {
			    List *p, *pp;
			    
			    p = smiMalloc(sizeof(List));
			    p->ptr = (void *)(yyvsp[(3) - (3)].objectPtr);
			    p->nextPtr = NULL;
			    for (pp = (yyvsp[(1) - (3)].listPtr); pp->nextPtr; pp = pp->nextPtr);
			    pp->nextPtr = p;
			    (yyval.listPtr) = (yyvsp[(1) - (3)].listPtr);
			}
    break;

  case 116:
/* Line 1787 of yacc.c  */
#line 2544 "parser-smi.y"
    {
			    Object *objectPtr;
			    Import *importPtr;
			    Type *typePtr;
			    
			    objectPtr =
			        findObjectByModuleAndName(thisParserPtr->modulePtr,
							  (yyvsp[(1) - (2)].id));

			    if (!objectPtr) {
				importPtr = findImportByName((yyvsp[(1) - (2)].id),
							     thisModulePtr);
				if (!importPtr ||
				    (importPtr->kind == KIND_NOTFOUND)) {
				    objectPtr = addObject((yyvsp[(1) - (2)].id), thisParserPtr->pendingNodePtr,
					                  0,
					                  FLAG_INCOMPLETE |
							  FLAG_SEQTYPE,
						          thisParserPtr);
				    setObjectType(objectPtr, (yyvsp[(2) - (2)].typePtr));
				} else {
				    /*
				     * imported object.
				     */
				    importPtr->use++;
				    objectPtr = findObjectByModulenameAndName(
					importPtr->export.module, (yyvsp[(1) - (2)].id));
				    smiFree((yyvsp[(1) - (2)].id));

				    if (objectPtr->typePtr->export.name) {
					typePtr = objectPtr->typePtr;
				    } else {
					typePtr = objectPtr->typePtr->parentPtr;
				    }
				    if (((yyvsp[(2) - (2)].typePtr) != typePtr) &&
					(((yyvsp[(2) - (2)].typePtr)->export.basetype !=
					  SMI_BASETYPE_INTEGER32) ||
					 (typePtr->export.basetype !=
					  SMI_BASETYPE_ENUM)) &&
					(((yyvsp[(2) - (2)].typePtr)->export.basetype !=
					  SMI_BASETYPE_OCTETSTRING) ||
					 (typePtr->export.basetype !=
					  SMI_BASETYPE_BITS))) {
					smiPrintError(thisParserPtr,
						      ERR_SEQUENCE_TYPE_MISMATCH,
						      objectPtr->export.name);
				    }
				}
			    } else {
				smiFree((yyvsp[(1) - (2)].id));
				if (objectPtr->typePtr) {

				    if (objectPtr->typePtr->export.name) {
					typePtr = objectPtr->typePtr;
				    } else {
					typePtr = objectPtr->typePtr->parentPtr;
				    }
				    if (((yyvsp[(2) - (2)].typePtr) != typePtr) &&
					(((yyvsp[(2) - (2)].typePtr)->export.basetype !=
					  SMI_BASETYPE_INTEGER32) ||
					 (typePtr->export.basetype !=
					  SMI_BASETYPE_ENUM)) &&
					(((yyvsp[(2) - (2)].typePtr)->export.basetype !=
					  SMI_BASETYPE_OCTETSTRING) ||
					 (typePtr->export.basetype !=
					  SMI_BASETYPE_BITS))) {
					smiPrintError(thisParserPtr,
						      ERR_SEQUENCE_TYPE_MISMATCH,
						      objectPtr->export.name);
				    }

				} else {
				    setObjectType(objectPtr, (yyvsp[(2) - (2)].typePtr));
				    addObjectFlags(objectPtr,
						   FLAG_SEQTYPE);
				}
			    }

			    (yyval.objectPtr) = objectPtr;
			}
    break;

  case 117:
/* Line 1787 of yacc.c  */
#line 2627 "parser-smi.y"
    {
			    (yyval.typePtr) = (yyvsp[(1) - (1)].typePtr);
			    if ((yyval.typePtr))
				defaultBasetype = (yyval.typePtr)->export.basetype;
			}
    break;

  case 118:
/* Line 1787 of yacc.c  */
#line 2635 "parser-smi.y"
    {
			    Type *typePtr;
			    List *p;
			    
			    defaultBasetype = SMI_BASETYPE_BITS;
			    typePtr = addType(NULL, SMI_BASETYPE_BITS,
					      FLAG_INCOMPLETE,
					      thisParserPtr);
			    setTypeDecl(typePtr, SMI_DECL_IMPLICIT_TYPE);
			    setTypeParent(typePtr, smiHandle->typeBitsPtr);
			    setTypeList(typePtr, (yyvsp[(3) - (4)].listPtr));
			    for (p = (yyvsp[(3) - (4)].listPtr); p; p = p->nextPtr)
				((NamedNumber *)p->ptr)->typePtr = typePtr;
			    smiCheckNamedNumbersOrder(parserPtr, typePtr);
			    (yyval.typePtr) = typePtr;
			}
    break;

  case 119:
/* Line 1787 of yacc.c  */
#line 2655 "parser-smi.y"
    {
			    (yyval.typePtr) = (yyvsp[(1) - (1)].typePtr);
			}
    break;

  case 120:
/* Line 1787 of yacc.c  */
#line 2659 "parser-smi.y"
    {
			    /* TODO: */
			    (yyval.typePtr) = smiHandle->typeOctetStringPtr;
			}
    break;

  case 121:
/* Line 1787 of yacc.c  */
#line 2664 "parser-smi.y"
    {
			    Type *typePtr;
			    Import *importPtr;
			    
			    (yyval.typePtr) = findTypeByModulenameAndName(
				thisParserPtr->modulePtr->export.name, (yyvsp[(1) - (2)].id));
			    if (! (yyval.typePtr)) {
				importPtr = findImportByName((yyvsp[(1) - (2)].id),
							     thisModulePtr);
				if (!importPtr ||
				    (importPtr->kind == KIND_NOTFOUND)) {
				    /* 
				     * forward referenced type. create it,
				     * marked with FLAG_INCOMPLETE.
				     */
				    typePtr = addType((yyvsp[(1) - (2)].id), SMI_BASETYPE_UNKNOWN,
						      FLAG_INCOMPLETE,
						      thisParserPtr);
				    (yyval.typePtr) = typePtr;
				} else {
				    importPtr->use++;
				    (yyval.typePtr) = findTypeByModulenameAndName(
					importPtr->export.module,
					importPtr->export.name);
				    smiFree((yyvsp[(1) - (2)].id));
				}
			    } else {
				smiFree((yyvsp[(1) - (2)].id));
			    }
			}
    break;

  case 122:
/* Line 1787 of yacc.c  */
#line 2697 "parser-smi.y"
    {
			    (yyval.listPtr) = smiMalloc(sizeof(List));
			    (yyval.listPtr)->ptr = (yyvsp[(1) - (1)].namedNumberPtr);
			    (yyval.listPtr)->nextPtr = NULL;
			}
    break;

  case 123:
/* Line 1787 of yacc.c  */
#line 2703 "parser-smi.y"
    {
			    List *p, *pp;
			    
			    p = smiMalloc(sizeof(List));
			    p->ptr = (void *)(yyvsp[(3) - (3)].namedNumberPtr);
			    p->nextPtr = NULL;
			    for (pp = (yyvsp[(1) - (3)].listPtr); pp->nextPtr; pp = pp->nextPtr);
			    pp->nextPtr = p;
			    (yyval.listPtr) = (yyvsp[(1) - (3)].listPtr);
			}
    break;

  case 124:
/* Line 1787 of yacc.c  */
#line 2716 "parser-smi.y"
    {
			    checkNameLen(thisParserPtr, (yyvsp[(1) - (1)].id),
					 ERR_BITNAME_32, ERR_BITNAME_64);
			    if (thisModulePtr->export.language == SMI_LANGUAGE_SMIV2)
			    {
				if (strchr((yyvsp[(1) - (1)].id), '-')) {
				    smiPrintError(thisParserPtr,
						  ERR_NAMEDBIT_INCLUDES_HYPHEN,
						  (yyvsp[(1) - (1)].id));
				}
			    }
			}
    break;

  case 125:
/* Line 1787 of yacc.c  */
#line 2729 "parser-smi.y"
    {
			    (yyval.namedNumberPtr) = smiMalloc(sizeof(NamedNumber));
			    (yyval.namedNumberPtr)->export.name = (yyvsp[(1) - (5)].id);
			    (yyval.namedNumberPtr)->export.value.basetype =
				                       SMI_BASETYPE_UNSIGNED32;
			    (yyval.namedNumberPtr)->export.value.value.unsigned32 = (yyvsp[(4) - (5)].unsigned32);
			    /* RFC 2578 7.1.4 */
			    if ((yyvsp[(4) - (5)].unsigned32) >= 65535*8) {
				smiPrintError(thisParserPtr,
					      ERR_BITS_NUMBER_TOO_LARGE,
					      (yyvsp[(1) - (5)].id), (yyvsp[(4) - (5)].unsigned32));
			    } else {
				if ((yyvsp[(4) - (5)].unsigned32) >= 128) {
				    smiPrintError(thisParserPtr,
						  ERR_BITS_NUMBER_LARGE,
						  (yyvsp[(1) - (5)].id), (yyvsp[(4) - (5)].unsigned32));
				}
			    }
			}
    break;

  case 126:
/* Line 1787 of yacc.c  */
#line 2751 "parser-smi.y"
    {
			    thisParserPtr->firstStatementLine = thisParserPtr->line;
			    thisParserPtr->currentDecl = SMI_DECL_OBJECTIDENTITY;

			    checkNameLen(thisParserPtr, (yyvsp[(1) - (1)].id),
					 ERR_OIDNAME_32, ERR_OIDNAME_64);
			    smiCheckObjectName(thisParserPtr,
					       thisModulePtr, (yyvsp[(1) - (1)].id));
			}
    break;

  case 127:
/* Line 1787 of yacc.c  */
#line 2761 "parser-smi.y"
    {
			    Import *importPtr;

			    if (strcmp(thisModulePtr->export.name, "SNMPv2-SMI") &&
                                strcmp(thisModulePtr->export.name, "COPS-PR-SPPI")) {
				importPtr = findImportByName("OBJECT-IDENTITY",
							     thisModulePtr);
				if (importPtr) {
				    importPtr->use++;
				} else {
                                    if (thisParserPtr->modulePtr->export.language != SMI_LANGUAGE_SPPI)
				        smiPrintError(thisParserPtr,
						      ERR_MACRO_NOT_IMPORTED,
						      "OBJECT-IDENTITY",
						      "SNMPv2-SMI");
                                    else
				        smiPrintError(thisParserPtr,
						      ERR_MACRO_NOT_IMPORTED,
						      "OBJECT-IDENTITY",
						      "COPS-PR-SPPI");
				}
			    }
			}
    break;

  case 128:
/* Line 1787 of yacc.c  */
#line 2786 "parser-smi.y"
    {
			    checkDescr(thisParserPtr, (yyvsp[(8) - (8)].text));
			}
    break;

  case 129:
/* Line 1787 of yacc.c  */
#line 2792 "parser-smi.y"
    {
			    Object *objectPtr;
			    
			    objectPtr = (yyvsp[(13) - (14)].objectPtr);
			    smiCheckObjectReuse(thisParserPtr, (yyvsp[(1) - (14)].id), &objectPtr);

			    objectPtr = setObjectName(objectPtr, (yyvsp[(1) - (14)].id), thisParserPtr);
			    setObjectDecl(objectPtr, SMI_DECL_OBJECTIDENTITY);
			    setObjectLine(objectPtr, thisParserPtr->firstStatementLine,
					  thisParserPtr);
			    setObjectStatus(objectPtr, (yyvsp[(6) - (14)].status));
			    setObjectDescription(objectPtr, (yyvsp[(8) - (14)].text), thisParserPtr);
			    if ((yyvsp[(10) - (14)].text)) {
				setObjectReference(objectPtr, (yyvsp[(10) - (14)].text), thisParserPtr);
			    }
			    addObjectFlags(objectPtr, FLAG_REGISTERED);
			    deleteObjectFlags(objectPtr, FLAG_INCOMPLETE);
			    (yyval.err) = 0;
			}
    break;

  case 130:
/* Line 1787 of yacc.c  */
#line 2814 "parser-smi.y"
    {
			    thisParserPtr->firstStatementLine = thisParserPtr->line;
			    thisParserPtr->currentDecl = SMI_DECL_OBJECTTYPE;
			    
			    checkNameLen(thisParserPtr, (yyvsp[(1) - (1)].id),
					 ERR_OIDNAME_32, ERR_OIDNAME_64);
			    smiCheckObjectName(thisParserPtr,
					       thisModulePtr, (yyvsp[(1) - (1)].id));
			}
    break;

  case 131:
/* Line 1787 of yacc.c  */
#line 2824 "parser-smi.y"
    {
			    Import *importPtr;
			    
			    importPtr = findImportByName("OBJECT-TYPE",
							 thisModulePtr);
			    if (importPtr) {
				importPtr->use++;
			    } else {
				if (thisModulePtr->export.language ==
				    SMI_LANGUAGE_SMIV2) {
				    smiPrintError(thisParserPtr,
						  ERR_MACRO_NOT_IMPORTED,
						  "OBJECT-TYPE", "SNMPv2-SMI");
				} else if (thisModulePtr->export.language ==
                                    SMI_LANGUAGE_SPPI) {
                                    smiPrintError(thisParserPtr,
                                                  ERR_MACRO_NOT_IMPORTED,
                                                  "OBJECT-TYPE", "COPS-PR-SPPI");
                                } else {
				    smiPrintError(thisParserPtr,
						  ERR_MACRO_NOT_IMPORTED,
						  "OBJECT-TYPE", "RFC-1212");
				}
			    }
                            indexFlag = 0;
			    variationkind = SMI_NODEKIND_UNKNOWN;
			}
    break;

  case 132:
/* Line 1787 of yacc.c  */
#line 2865 "parser-smi.y"
    {
			    Object *objectPtr, *parentPtr;
			    Type *typePtr = NULL;
			    
			    objectPtr = (yyvsp[(22) - (23)].objectPtr);

			    smiCheckObjectReuse(thisParserPtr, (yyvsp[(1) - (23)].id), &objectPtr);

			    objectPtr = setObjectName(objectPtr, (yyvsp[(1) - (23)].id), thisParserPtr);
			    setObjectDecl(objectPtr, SMI_DECL_OBJECTTYPE);
			    setObjectLine(objectPtr, thisParserPtr->firstStatementLine,
					  thisParserPtr);
			    if (checkObjectFlags(objectPtr, FLAG_SEQTYPE)) {
				deleteObjectFlags(objectPtr, FLAG_SEQTYPE);
				if ((yyvsp[(6) - (23)].typePtr)) {
				    if ((yyvsp[(6) - (23)].typePtr)->export.name) {
					typePtr = (yyvsp[(6) - (23)].typePtr);
                                        /*
                                         * According to RFC 3159 7.1.3. Opaque must not be used
                                         * in a SYNTAX clause.
                                         */
                                        if ((thisModulePtr->export.language == SMI_LANGUAGE_SPPI) &&
                                            !strcmp(typePtr->export.name, "Opaque"))
                                            smiPrintError(thisParserPtr, ERR_OPAQUE_IN_SYNTAX);
                                        /*
                                         * According to RFC 3159 7.1.4. IpAddress must not be used
                                         * in a SYNTAX clause.
                                         */
                                        if ((thisModulePtr->export.language == SMI_LANGUAGE_SPPI) &&
                                            !strcmp(typePtr->export.name, "IpAddress"))
                                            smiPrintError(thisParserPtr, ERR_IPADDRESS_IN_SYNTAX);
				    } else {
					typePtr = (yyvsp[(6) - (23)].typePtr)->parentPtr;
				    }
				    if ((objectPtr->typePtr != typePtr) &&
					((objectPtr->typePtr->export.basetype !=
					  SMI_BASETYPE_INTEGER32) ||
					 (typePtr->export.basetype !=
					  SMI_BASETYPE_ENUM)) &&
					((objectPtr->typePtr->export.basetype !=
					  SMI_BASETYPE_OCTETSTRING) ||
					 (typePtr->export.basetype !=
					  SMI_BASETYPE_BITS))) {
					smiPrintError(thisParserPtr,
						      ERR_SEQUENCE_TYPE_MISMATCH,
						      objectPtr->export.name);
				    }
				}
			    }
			    setObjectType(objectPtr, (yyvsp[(6) - (23)].typePtr));
			    if (!((yyvsp[(6) - (23)].typePtr)->export.name)) {
				/*
				 * An inlined type.
				 */
#if 0 /* export implicitly defined types by the node's lowercase name */
				setTypeName((yyvsp[(6) - (23)].typePtr), (yyvsp[(1) - (23)].id));
#endif
			    }
			    setObjectUnits(objectPtr, (yyvsp[(7) - (23)].text));
			    setObjectAccess(objectPtr, (yyvsp[(8) - (23)].access));
			    if (thisParserPtr->flags & FLAG_CREATABLE) {
				thisParserPtr->flags &= ~FLAG_CREATABLE;
				parentPtr =
				  objectPtr->nodePtr->parentPtr->lastObjectPtr;
				if (parentPtr &&
				    parentPtr->export.indexkind !=
				       SMI_INDEX_UNKNOWN) {
				    /*
				     * add objectPtr to the parent object's
				     * listPtr, which is the list of columns
				     * needed for row creation.
				     *
				     * Note, that this would clash, if the
				     * parent row object-type is not yet
				     * defined.
				     */
				    /*
				    newlistPtr = smiMalloc(sizeof(List));
				    newlistPtr->nextPtr = NULL;
				    newlistPtr->ptr = objectPtr;
				    */
				    /*
				     * Look up the parent object-type.
				     */
				    /*
				    if (parentPtr->listPtr) {
					for(listPtr = parentPtr->listPtr;
					    listPtr->nextPtr;
					    listPtr = listPtr->nextPtr);
					listPtr->nextPtr = newlistPtr;
				    } else {
					parentPtr->listPtr = newlistPtr;
				    }
				    */
				    addObjectFlags(parentPtr, FLAG_CREATABLE);
				    setObjectCreate(parentPtr, 1);
				} else {
				    smiPrintError(thisParserPtr,
						  ERR_SCALAR_READCREATE);
				}
			    }
			    setObjectStatus(objectPtr, (yyvsp[(12) - (23)].status));
			    addObjectFlags(objectPtr, FLAG_REGISTERED);
			    deleteObjectFlags(objectPtr, FLAG_INCOMPLETE);
			    if ((yyvsp[(13) - (23)].text)) {
				setObjectDescription(objectPtr, (yyvsp[(13) - (23)].text), thisParserPtr);
			    }
			    if ((yyvsp[(15) - (23)].text)) {
				setObjectReference(objectPtr, (yyvsp[(15) - (23)].text), thisParserPtr);
			    }
                            if (thisParserPtr->modulePtr->export.language != SMI_LANGUAGE_SPPI) {
                                /*
                                 * For SMI documents either $16 (IndexPart) or $17 (MibIndex)
                                 * are used, but not both. This is signalled via the indexFlag
                                 * which is 1 if IndexPart has been used.
                                 */
                                if (indexFlag == INDEXFLAG_AUGMENTS) { /* IndexPart was used */
			            if ((yyvsp[(16) - (23)].index).indexkind != SMI_INDEX_UNKNOWN) {
				        setObjectList(objectPtr, (yyvsp[(16) - (23)].index).listPtr);
				        setObjectImplied(objectPtr, (yyvsp[(16) - (23)].index).implied);
				        setObjectIndexkind(objectPtr, (yyvsp[(16) - (23)].index).indexkind);
				        setObjectRelated(objectPtr, (yyvsp[(16) - (23)].index).rowPtr);
			            }
                                } else {
			            if ((yyvsp[(17) - (23)].index).indexkind != SMI_INDEX_UNKNOWN) {
				        setObjectList(objectPtr, (yyvsp[(17) - (23)].index).listPtr);
				        setObjectImplied(objectPtr, (yyvsp[(17) - (23)].index).implied);
				        setObjectIndexkind(objectPtr, (yyvsp[(17) - (23)].index).indexkind);
				        setObjectRelated(objectPtr, (yyvsp[(17) - (23)].index).rowPtr);
			            }
                                }
                            } else {
                                /*
                                 * PIBs contain either PIB-INDEX or AUGMENTS or EXTENDS - 
                                 * but only with one Index entry. A PIB-INDEX may be
                                 * followed by a full INDEX. We get the indexkind
                                 * from the first.
                                 * Note that PIB-INDEX/AUGMENTS/EXTENS is always
                                 * the first element in objectPtr->listPtr.
                                 * If an optional INDEX exists then it is
                                 * appended to this list.
                                 */
			        if ((yyvsp[(16) - (23)].index).indexkind != SMI_INDEX_UNKNOWN) {
                                    setObjectList(objectPtr, (yyvsp[(16) - (23)].index).listPtr);
				    setObjectIndexkind(objectPtr, (yyvsp[(16) - (23)].index).indexkind);
				    setObjectRelated(objectPtr, (yyvsp[(16) - (23)].index).rowPtr);
			        }
			        if ((yyvsp[(17) - (23)].index).indexkind != SMI_INDEX_UNKNOWN) {
                                    if (objectPtr->listPtr) {
                                        List *p;
                                        for (p = objectPtr->listPtr; p->nextPtr;
                                             p = p->nextPtr);
                                        p->nextPtr = (yyvsp[(17) - (23)].index).listPtr;
                                    }
				    setObjectImplied(objectPtr, (yyvsp[(17) - (23)].index).implied);
			        }
                            }
                            if ((yyvsp[(18) - (23)].listPtr)) {
                                setObjectUniqueness(objectPtr, (yyvsp[(18) - (23)].listPtr));
                            }
			    if ((yyvsp[(19) - (23)].valuePtr)) {
				if (objectPtr->typePtr
				    && (((objectPtr->typePtr->export.basetype == SMI_BASETYPE_OCTETSTRING) &&
					 ((yyvsp[(19) - (23)].valuePtr)->basetype != SMI_BASETYPE_OCTETSTRING))
					|| ((objectPtr->typePtr->export.basetype == SMI_BASETYPE_OBJECTIDENTIFIER) &&
					    ((yyvsp[(19) - (23)].valuePtr)->basetype != SMI_BASETYPE_OBJECTIDENTIFIER)))) {
				    smiPrintError(thisParserPtr,
						  ERR_DEFVAL_SYNTAX);
				    if ((yyvsp[(19) - (23)].valuePtr)->basetype == SMI_BASETYPE_OBJECTIDENTIFIER) {
					smiFree((yyvsp[(19) - (23)].valuePtr)->value.oid);
				    }
				    if (((yyvsp[(19) - (23)].valuePtr)->basetype == SMI_BASETYPE_BITS) ||
					((yyvsp[(19) - (23)].valuePtr)->basetype == SMI_BASETYPE_OCTETSTRING)) {
					smiFree((yyvsp[(19) - (23)].valuePtr)->value.ptr);
				    }
				    smiFree((yyvsp[(19) - (23)].valuePtr));
				} else {
				    setObjectValue(objectPtr, (yyvsp[(19) - (23)].valuePtr));
				}
			    }
                            if ((yyvsp[(9) - (23)].objectPtr)) {
                                if (objectPtr->relatedPtr)
                                    smiPrintError(thisParserPtr, ERR_OBJECTPTR_ELEMENT_IN_USE,
                                                  "relatedPtr", "PIB-REFERENCES");
                                /*
                                 * PIB-REFERENCES clauses are only allowed for
                                 * objects with a SYNTAX of 'ReferenceId'.
                                 * See RFC 3159 7.10
                                 */
                                if (objectPtr->typePtr && objectPtr->typePtr->export.name &&
                                    strcmp(objectPtr->typePtr->export.name, "ReferenceId"))
                                    smiPrintErrorAtLine(parserPtr, ERR_PIB_REFERENCES_WRONG_TYPE,
                                                        objectPtr->line);
                                else
                                    setObjectRelated(objectPtr, (yyvsp[(9) - (23)].objectPtr));
                            } else {
                               /*
                                * Does this object have a SYNTAX of 'ReferenceId'
                                * and a PIB-REFERENCES clause?
                                * See RFC 3159 7.10
                                */
                               if ((thisModulePtr->export.language == SMI_LANGUAGE_SPPI) &&
                                   objectPtr->typePtr && objectPtr->typePtr->export.name &&
                                   !strcmp(objectPtr->typePtr->export.name, "ReferenceId"))
                                   smiPrintErrorAtLine(parserPtr, ERR_LACKING_PIB_REFERENCES,
                                                       objectPtr->line);
                            }
                            if ((yyvsp[(10) - (23)].objectPtr)) {
                                if (objectPtr->relatedPtr)
                                    smiPrintError(thisParserPtr, ERR_OBJECTPTR_ELEMENT_IN_USE,
                                                  "relatedPtr", "PIB-TAG");
                                /*
                                 * PIB-TAG clauses are only allowed for
                                 * objects with a SYNTAX of 'TagReferenceId'.
                                 * See RFC 3159 7.11
                                 */
                                if (objectPtr->typePtr && objectPtr->typePtr->export.name &&
                                    strcmp(objectPtr->typePtr->export.name, "TagReferenceId"))
                                    smiPrintErrorAtLine(parserPtr, ERR_PIB_TAG_WRONG_TYPE,
                                                        objectPtr->line);
                                else
                                    setObjectRelated(objectPtr, (yyvsp[(10) - (23)].objectPtr));
                            } else {
                                /*
                                 * Does this object have a SYNTAX of 'TagReferenceId'
                                 * and a PIB-TAG clause?
                                 * See RFC 3159 7.11
                                 */
                                if ((thisModulePtr->export.language == SMI_LANGUAGE_SPPI) &&
                                    objectPtr->typePtr && objectPtr->typePtr->export.name &&
                                    !strcmp(objectPtr->typePtr->export.name, "TagReferenceId"))
                                    smiPrintErrorAtLine(parserPtr, ERR_LACKING_PIB_TAG,
                                                        objectPtr->line);

                            }
                            if ((yyvsp[(14) - (23)].listPtr)) {
                                if (objectPtr->listPtr)
                                    smiPrintError(thisParserPtr, ERR_OBJECTPTR_ELEMENT_IN_USE,
                                                  "listPtr", "INSTALL-ERRORS");
                                /*
                                 * Are INSTALL-ERRORS only used with tables?
                                 * See RFC 3159 7.4
                                 */
                                if (!((objectPtr->export.decl == SMI_DECL_OBJECTTYPE) &&
                                    (objectPtr->typePtr) &&
                                    (objectPtr->typePtr->export.decl == SMI_DECL_IMPL_SEQUENCEOF)))
                                    smiPrintErrorAtLine(parserPtr, ERR_INSTALL_ERRORS_FOR_NON_TABLE,
                                                        objectPtr->line);
                                else
                                    setObjectList(objectPtr, (yyvsp[(14) - (23)].listPtr));
                            }
			    (yyval.err) = 0;
			}
    break;

  case 133:
/* Line 1787 of yacc.c  */
#line 3121 "parser-smi.y"
    {
			    if ((thisModulePtr->export.language == SMI_LANGUAGE_SMIV2) ||
                                (thisModulePtr->export.language == SMI_LANGUAGE_SPPI))
			    {
				smiPrintError(thisParserPtr,
					      ERR_MISSING_DESCRIPTION);
			    }
			    (yyval.text) = NULL;
			}
    break;

  case 134:
/* Line 1787 of yacc.c  */
#line 3131 "parser-smi.y"
    {
			    (yyval.text) = (yyvsp[(2) - (2)].text);
			    checkDescr(thisParserPtr, (yyvsp[(2) - (2)].text));
			}
    break;

  case 135:
/* Line 1787 of yacc.c  */
#line 3138 "parser-smi.y"
    {
			    thisParserPtr->firstStatementLine = thisParserPtr->line;
			    thisParserPtr->currentDecl = SMI_DECL_TRAPTYPE;
			    
			    checkNameLen(thisParserPtr, (yyvsp[(1) - (1)].id),
					 ERR_OIDNAME_32, ERR_OIDNAME_64);
			    smiCheckObjectName(thisParserPtr,
					       thisModulePtr, (yyvsp[(1) - (1)].id));
			}
    break;

  case 136:
/* Line 1787 of yacc.c  */
#line 3148 "parser-smi.y"
    {
			    Import *importPtr;
                            if (thisParserPtr->modulePtr->export.language == SMI_LANGUAGE_SPPI)
                                smiPrintError(thisParserPtr, ERR_SMI_CONSTRUCT_IN_PIB, "TRAP-TYPE");
			    
			    if (thisModulePtr->export.language == SMI_LANGUAGE_SMIV2)
			    {
			        smiPrintError(thisParserPtr, ERR_TRAP_TYPE);
			    }

			    importPtr = findImportByName("TRAP-TYPE",
							 thisModulePtr);
			    if (importPtr) {
				importPtr->use++;
			    } else {
				smiPrintError(thisParserPtr,
					      ERR_MACRO_NOT_IMPORTED,
					      "TRAP-TYPE", "RFC-1215");
			    }
			}
    break;

  case 137:
/* Line 1787 of yacc.c  */
#line 3174 "parser-smi.y"
    {
			    Object *objectPtr;
			    Node *nodePtr;
			    
			    objectPtr = (yyvsp[(6) - (11)].objectPtr);
			    nodePtr = findNodeByParentAndSubid(
				objectPtr->nodePtr, 0);
			    if (nodePtr && nodePtr->lastObjectPtr &&
	       		        (nodePtr->lastObjectPtr->modulePtr == thisModulePtr)) {
				/*
				 * hopefully, the last defined Object for
				 * this Node is the one we expect.
				 */
				objectPtr = nodePtr->lastObjectPtr;
			    } else {
				objectPtr = addObject(NULL,
						      objectPtr->nodePtr,
						      0,
						      FLAG_INCOMPLETE,
						      thisParserPtr);
			    }
			    objectPtr = addObject(NULL,
						  objectPtr->nodePtr,
						  (yyvsp[(11) - (11)].unsigned32),
						  FLAG_INCOMPLETE,
						  thisParserPtr);
			    
			    smiCheckObjectReuse(thisParserPtr, (yyvsp[(1) - (11)].id), &objectPtr);

			    objectPtr = setObjectName(objectPtr, (yyvsp[(1) - (11)].id), thisParserPtr);
			    setObjectDecl(objectPtr,
					  SMI_DECL_TRAPTYPE);
			    setObjectLine(objectPtr, thisParserPtr->firstStatementLine,
					  thisParserPtr);
			    addObjectFlags(objectPtr, FLAG_REGISTERED);
			    deleteObjectFlags(objectPtr, FLAG_INCOMPLETE);
			    setObjectList(objectPtr, (yyvsp[(7) - (11)].listPtr));
			    setObjectStatus(objectPtr, SMI_STATUS_CURRENT); 
			    setObjectDescription(objectPtr, (yyvsp[(8) - (11)].text), thisParserPtr);
			    if ((yyvsp[(9) - (11)].text)) {
				setObjectReference(objectPtr, (yyvsp[(9) - (11)].text), thisParserPtr);
			    }
			    (yyval.err) = 0;
			}
    break;

  case 138:
/* Line 1787 of yacc.c  */
#line 3221 "parser-smi.y"
    {
			    (yyval.listPtr) = (yyvsp[(3) - (4)].listPtr);
			}
    break;

  case 139:
/* Line 1787 of yacc.c  */
#line 3225 "parser-smi.y"
    {
			    (yyval.listPtr) = NULL;
			}
    break;

  case 140:
/* Line 1787 of yacc.c  */
#line 3231 "parser-smi.y"
    {
			    if ((yyvsp[(1) - (1)].objectPtr)) {
				(yyval.listPtr) = smiMalloc(sizeof(List));
				(yyval.listPtr)->ptr = (yyvsp[(1) - (1)].objectPtr);
				(yyval.listPtr)->nextPtr = NULL;
			    } else {
				(yyval.listPtr) = NULL;
			    }
			}
    break;

  case 141:
/* Line 1787 of yacc.c  */
#line 3241 "parser-smi.y"
    {
			    List *p, *pp;

			    if ((yyvsp[(3) - (3)].objectPtr)) {
				p = smiMalloc(sizeof(List));
				p->ptr = (yyvsp[(3) - (3)].objectPtr);
				p->nextPtr = NULL;
				if ((yyvsp[(1) - (3)].listPtr)) {
				    for (pp = (yyvsp[(1) - (3)].listPtr); pp->nextPtr;
					 pp = pp->nextPtr);
				    pp->nextPtr = p;
				    (yyval.listPtr) = (yyvsp[(1) - (3)].listPtr);
				} else {
				    (yyval.listPtr) = p;
				}
			    } else {
				(yyval.listPtr) = (yyvsp[(1) - (3)].listPtr);
			    }
			}
    break;

  case 142:
/* Line 1787 of yacc.c  */
#line 3263 "parser-smi.y"
    {
			    (yyval.objectPtr) = (yyvsp[(1) - (1)].objectPtr);
			}
    break;

  case 143:
/* Line 1787 of yacc.c  */
#line 3269 "parser-smi.y"
    {
			    (yyval.text) = (yyvsp[(2) - (2)].text);
			    checkDescr(thisParserPtr, (yyvsp[(2) - (2)].text));
			}
    break;

  case 144:
/* Line 1787 of yacc.c  */
#line 3274 "parser-smi.y"
    { (yyval.text) = NULL; }
    break;

  case 145:
/* Line 1787 of yacc.c  */
#line 3278 "parser-smi.y"
    {
                            (yyval.access) = (yyvsp[(1) - (1)].access);
                        }
    break;

  case 146:
/* Line 1787 of yacc.c  */
#line 3282 "parser-smi.y"
    {
                            if (thisParserPtr->modulePtr->export.language != SMI_LANGUAGE_SPPI)
                                smiPrintError(thisParserPtr, ERR_SPPI_CONSTRUCT_IN_MIB, "MAX-ACCESS");
                            if ((yyvsp[(1) - (1)].access) == SMI_ACCESS_NOT_ACCESSIBLE)
                                smiPrintError(thisParserPtr, ERR_NOT_ACCESSIBLE_IN_PIB_ACCESS);
                            (yyval.access) = (yyvsp[(1) - (1)].access);
                        }
    break;

  case 147:
/* Line 1787 of yacc.c  */
#line 3290 "parser-smi.y"
    { (yyval.access) = 0;  }
    break;

  case 148:
/* Line 1787 of yacc.c  */
#line 3294 "parser-smi.y"
    { (yyval.access) = (yyvsp[(2) - (2)].access); }
    break;

  case 149:
/* Line 1787 of yacc.c  */
#line 3298 "parser-smi.y"
    { 
                            smiPrintError(thisParserPtr, ERR_POLICY_ACCESS_IN_PIB);
                        }
    break;

  case 150:
/* Line 1787 of yacc.c  */
#line 3302 "parser-smi.y"
    { }
    break;

  case 151:
/* Line 1787 of yacc.c  */
#line 3306 "parser-smi.y"
    {
                            if (thisParserPtr->modulePtr->export.language != SMI_LANGUAGE_SPPI)
                                smiPrintError(thisParserPtr, ERR_SPPI_CONSTRUCT_IN_MIB, "PIB-REFERENCES");
                        }
    break;

  case 152:
/* Line 1787 of yacc.c  */
#line 3311 "parser-smi.y"
    { (yyval.objectPtr) = (yyvsp[(4) - (5)].objectPtr); }
    break;

  case 153:
/* Line 1787 of yacc.c  */
#line 3313 "parser-smi.y"
    { (yyval.objectPtr) = 0; }
    break;

  case 154:
/* Line 1787 of yacc.c  */
#line 3317 "parser-smi.y"
    {
                            if (thisParserPtr->modulePtr->export.language != SMI_LANGUAGE_SPPI)
                                smiPrintError(thisParserPtr, ERR_SPPI_CONSTRUCT_IN_MIB, "PIB-TAG");
                        }
    break;

  case 155:
/* Line 1787 of yacc.c  */
#line 3322 "parser-smi.y"
    { (yyval.objectPtr) = (yyvsp[(4) - (5)].objectPtr); }
    break;

  case 156:
/* Line 1787 of yacc.c  */
#line 3324 "parser-smi.y"
    { (yyval.objectPtr) = 0; }
    break;

  case 157:
/* Line 1787 of yacc.c  */
#line 3329 "parser-smi.y"
    {
                            if (thisParserPtr->modulePtr->export.language != SMI_LANGUAGE_SPPI)
                                smiPrintError(thisParserPtr, ERR_SPPI_CONSTRUCT_IN_MIB, "UNIQUENESS");
                        }
    break;

  case 158:
/* Line 1787 of yacc.c  */
#line 3334 "parser-smi.y"
    { (yyval.listPtr) = (yyvsp[(4) - (5)].listPtr); }
    break;

  case 159:
/* Line 1787 of yacc.c  */
#line 3336 "parser-smi.y"
    { (yyval.listPtr) = NULL; }
    break;

  case 160:
/* Line 1787 of yacc.c  */
#line 3340 "parser-smi.y"
    { (yyval.listPtr) = (yyvsp[(1) - (1)].listPtr); }
    break;

  case 161:
/* Line 1787 of yacc.c  */
#line 3342 "parser-smi.y"
    { (yyval.listPtr) = NULL; }
    break;

  case 162:
/* Line 1787 of yacc.c  */
#line 3346 "parser-smi.y"
    {
			    (yyval.listPtr) = smiMalloc(sizeof(List));
			    (yyval.listPtr)->ptr = (yyvsp[(1) - (1)].objectPtr);
			    (yyval.listPtr)->nextPtr = NULL;
			}
    break;

  case 163:
/* Line 1787 of yacc.c  */
#line 3353 "parser-smi.y"
    {
			    List *p, *pp;
			    
			    p = smiMalloc(sizeof(List));
			    p->ptr = (yyvsp[(3) - (3)].objectPtr);
			    p->nextPtr = NULL;
			    for (pp = (yyvsp[(1) - (3)].listPtr); pp->nextPtr; pp = pp->nextPtr);
			    pp->nextPtr = p;
			    (yyval.listPtr) = (yyvsp[(1) - (3)].listPtr);
                        }
    break;

  case 164:
/* Line 1787 of yacc.c  */
#line 3366 "parser-smi.y"
    { (yyval.objectPtr) = (yyvsp[(1) - (1)].objectPtr); }
    break;

  case 165:
/* Line 1787 of yacc.c  */
#line 3370 "parser-smi.y"
    {
                            if (thisParserPtr->modulePtr->export.language != SMI_LANGUAGE_SPPI)
                                smiPrintError(thisParserPtr, ERR_SPPI_CONSTRUCT_IN_MIB, "INSTALL-ERRORS");
                        }
    break;

  case 166:
/* Line 1787 of yacc.c  */
#line 3375 "parser-smi.y"
    { (yyval.listPtr) = (yyvsp[(4) - (5)].listPtr); }
    break;

  case 167:
/* Line 1787 of yacc.c  */
#line 3377 "parser-smi.y"
    { (yyval.listPtr) = NULL; }
    break;

  case 168:
/* Line 1787 of yacc.c  */
#line 3381 "parser-smi.y"
    {
			    (yyval.listPtr) = smiMalloc(sizeof(List));
			    (yyval.listPtr)->ptr = (yyvsp[(1) - (1)].objectPtr);
			    (yyval.listPtr)->nextPtr = NULL;
			}
    break;

  case 169:
/* Line 1787 of yacc.c  */
#line 3388 "parser-smi.y"
    {
			    List *p, *pp;
			    
			    p = smiMalloc(sizeof(List));
			    p->ptr = (yyvsp[(3) - (3)].objectPtr);
			    p->nextPtr = NULL;
			    for (pp = (yyvsp[(1) - (3)].listPtr); pp->nextPtr; pp = pp->nextPtr);
			    pp->nextPtr = p;
			    (yyval.listPtr) = (yyvsp[(1) - (3)].listPtr);
                        }
    break;

  case 170:
/* Line 1787 of yacc.c  */
#line 3401 "parser-smi.y"
    {
			    Object *objectPtr;
			    
                            if (((yyvsp[(3) - (4)].unsigned32) < 1) || ((yyvsp[(3) - (4)].unsigned32) > 65536))
                                smiPrintError(thisParserPtr, ERR_ERROR_NUMBER_RANGE, (yyvsp[(3) - (4)].unsigned32));
                            /*
                             * This is not a regular object that will be added vid
                             * 'addObject' as error identifier have no other
                             * meaning in PIBs. They are just used for
                             * a direct mapping to the actual protocol fields.
                             */
                            objectPtr = smiMalloc(sizeof(Object));
                            objectPtr->export.name = (yyvsp[(1) - (4)].id);
                            objectPtr->export.oidlen = 1;
                            objectPtr->export.oid = (void *)(yyvsp[(3) - (4)].unsigned32);
			    (yyval.objectPtr) = objectPtr;
			}
    break;

  case 171:
/* Line 1787 of yacc.c  */
#line 3422 "parser-smi.y"
    {
			    if (thisModulePtr->export.language == SMI_LANGUAGE_SMIV1)
			    {
			        smiPrintError(thisParserPtr,
					      ERR_MAX_ACCESS_IN_SMIV1);
			    } else if (thisParserPtr->modulePtr->export.language == SMI_LANGUAGE_SPPI)
                                smiPrintError(thisParserPtr, ERR_SMI_CONSTRUCT_IN_PIB, "MAX-ACCESS");
			}
    break;

  case 172:
/* Line 1787 of yacc.c  */
#line 3431 "parser-smi.y"
    { (yyval.access) = (yyvsp[(3) - (3)].access); }
    break;

  case 173:
/* Line 1787 of yacc.c  */
#line 3433 "parser-smi.y"
    {
			    if (thisModulePtr->export.language == SMI_LANGUAGE_SMIV2)
			    {
			        smiPrintError(thisParserPtr, ERR_ACCESS_IN_SMIV2);
			    } else if (thisParserPtr->modulePtr->export.language == SMI_LANGUAGE_SPPI)
                                smiPrintError(thisParserPtr, ERR_SMI_CONSTRUCT_IN_PIB, "ACCESS");
			}
    break;

  case 174:
/* Line 1787 of yacc.c  */
#line 3442 "parser-smi.y"
    { (yyval.access) = (yyvsp[(3) - (3)].access); }
    break;

  case 175:
/* Line 1787 of yacc.c  */
#line 3446 "parser-smi.y"
    {
			    thisParserPtr->firstStatementLine = thisParserPtr->line;
			    thisParserPtr->currentDecl = SMI_DECL_NOTIFICATIONTYPE;

			    checkNameLen(thisParserPtr, (yyvsp[(1) - (1)].id),
					 ERR_OIDNAME_32, ERR_OIDNAME_64);
			    smiCheckObjectName(thisParserPtr,
					       thisModulePtr, (yyvsp[(1) - (1)].id));
			}
    break;

  case 176:
/* Line 1787 of yacc.c  */
#line 3456 "parser-smi.y"
    {
			    Import *importPtr;

                            if (thisParserPtr->modulePtr->export.language == SMI_LANGUAGE_SPPI)
                                smiPrintError(thisParserPtr, ERR_SMI_CONSTRUCT_IN_PIB, "NOTIFICATION-TYPE");
                                
			    importPtr = findImportByName("NOTIFICATION-TYPE",
							 thisModulePtr);
			    if (importPtr) {
				importPtr->use++;
			    } else {
				smiPrintError(thisParserPtr,
					      ERR_MACRO_NOT_IMPORTED,
					      "NOTIFICATION-TYPE",
					      "SNMPv2-SMI");
			    }
			}
    break;

  case 177:
/* Line 1787 of yacc.c  */
#line 3476 "parser-smi.y"
    {
			    checkDescr(thisParserPtr, (yyvsp[(9) - (9)].text));
			}
    break;

  case 178:
/* Line 1787 of yacc.c  */
#line 3482 "parser-smi.y"
    {
			    Object *objectPtr;
			    
			    objectPtr = (yyvsp[(14) - (15)].objectPtr);

			    smiCheckObjectReuse(thisParserPtr, (yyvsp[(1) - (15)].id), &objectPtr);

			    objectPtr = setObjectName(objectPtr, (yyvsp[(1) - (15)].id), thisParserPtr);
			    setObjectDecl(objectPtr,
					  SMI_DECL_NOTIFICATIONTYPE);
			    setObjectLine(objectPtr, thisParserPtr->firstStatementLine,
					  thisParserPtr);
			    addObjectFlags(objectPtr, FLAG_REGISTERED);
			    deleteObjectFlags(objectPtr, FLAG_INCOMPLETE);
			    setObjectList(objectPtr, (yyvsp[(5) - (15)].listPtr));
			    setObjectStatus(objectPtr, (yyvsp[(7) - (15)].status));
			    setObjectDescription(objectPtr, (yyvsp[(9) - (15)].text), thisParserPtr);
			    if ((yyvsp[(11) - (15)].text)) {
				setObjectReference(objectPtr, (yyvsp[(11) - (15)].text), thisParserPtr);
			    }
			    (yyval.err) = 0;
			}
    break;

  case 179:
/* Line 1787 of yacc.c  */
#line 3507 "parser-smi.y"
    {
			    thisParserPtr->firstStatementLine = thisParserPtr->line;
			    thisParserPtr->currentDecl = SMI_DECL_MODULEIDENTITY;
			    
			    checkNameLen(thisParserPtr, (yyvsp[(1) - (1)].id),
					 ERR_OIDNAME_32, ERR_OIDNAME_64);
			    smiCheckObjectName(thisParserPtr,
					       thisModulePtr, (yyvsp[(1) - (1)].id));
			}
    break;

  case 180:
/* Line 1787 of yacc.c  */
#line 3517 "parser-smi.y"
    {
			    Import *importPtr;
			    
			    importPtr = findImportByName("MODULE-IDENTITY",
							 thisModulePtr);
			    if (importPtr) {
				importPtr->use++;
			    } else {
				smiPrintError(thisParserPtr,
					      ERR_MACRO_NOT_IMPORTED,
					      "MODULE-IDENTITY",
					      "SNMPv2-SMI");
			    }
			    
			    if (thisParserPtr->modulePtr->numModuleIdentities > 0)
			    {
			        smiPrintError(thisParserPtr,
					      ERR_TOO_MANY_MODULE_IDENTITIES);
			    }
			    if (thisParserPtr->modulePtr->numStatements > 0) {
			        smiPrintError(thisParserPtr,
					      ERR_MODULE_IDENTITY_NOT_FIRST);
			    }
			}
    break;

  case 181:
/* Line 1787 of yacc.c  */
#line 3542 "parser-smi.y"
    {
                          /* do nothing at the moment */
                        }
    break;

  case 182:
/* Line 1787 of yacc.c  */
#line 3546 "parser-smi.y"
    {
			    setModuleLastUpdated(thisParserPtr->modulePtr, (yyvsp[(8) - (8)].date));
			}
    break;

  case 183:
/* Line 1787 of yacc.c  */
#line 3550 "parser-smi.y"
    {
			    if ((yyvsp[(11) - (11)].text) && !strlen((yyvsp[(11) - (11)].text))) {
				smiPrintError(thisParserPtr,
					      ERR_EMPTY_ORGANIZATION);
			    }
			}
    break;

  case 184:
/* Line 1787 of yacc.c  */
#line 3557 "parser-smi.y"
    {
			    if ((yyvsp[(14) - (14)].text) && !strlen((yyvsp[(14) - (14)].text))) {
				smiPrintError(thisParserPtr,
					      ERR_EMPTY_CONTACT);
			    }
			}
    break;

  case 185:
/* Line 1787 of yacc.c  */
#line 3564 "parser-smi.y"
    {
			    checkDescr(thisParserPtr, (yyvsp[(17) - (17)].text));
			}
    break;

  case 186:
/* Line 1787 of yacc.c  */
#line 3568 "parser-smi.y"
    {
			    if ((!thisModulePtr->firstRevisionPtr) ||
				(thisModulePtr->firstRevisionPtr->export.date !=
				 thisModulePtr->lastUpdated)) {
				smiPrintError(thisParserPtr,
					      ERR_REVISION_MISSING);
				addRevision(thisModulePtr->lastUpdated,
					    smiStrdup(
						"[Revision added by libsmi due to a LAST-UPDATED clause.]"),
					    thisParserPtr);
			    }
			}
    break;

  case 187:
/* Line 1787 of yacc.c  */
#line 3582 "parser-smi.y"
    {
			    Object *objectPtr;
			    
			    objectPtr = (yyvsp[(23) - (24)].objectPtr);
			    smiCheckObjectReuse(thisParserPtr, (yyvsp[(1) - (24)].id), &objectPtr);

			    thisParserPtr->modulePtr->numModuleIdentities++;

			    objectPtr = setObjectName(objectPtr, (yyvsp[(1) - (24)].id), thisParserPtr);
			    setObjectDecl(objectPtr, SMI_DECL_MODULEIDENTITY);
			    setObjectLine(objectPtr, thisParserPtr->firstStatementLine,
					  thisParserPtr);
			    setObjectStatus(objectPtr, SMI_STATUS_CURRENT);
			    addObjectFlags(objectPtr, FLAG_REGISTERED);
			    deleteObjectFlags(objectPtr, FLAG_INCOMPLETE);
			    setModuleIdentityObject(thisParserPtr->modulePtr,
						    objectPtr);
			    setModuleOrganization(thisParserPtr->modulePtr,
						  (yyvsp[(11) - (24)].text));
			    setModuleContactInfo(thisParserPtr->modulePtr,
						 (yyvsp[(14) - (24)].text));
			    setModuleDescription(thisParserPtr->modulePtr,
						 (yyvsp[(17) - (24)].text), thisParserPtr);
                            if ((yyvsp[(5) - (24)].subjectCategoriesPtr) != NULL) {
                                setObjectList(objectPtr, (yyvsp[(5) - (24)].subjectCategoriesPtr)->categories);
                                smiFree((yyvsp[(5) - (24)].subjectCategoriesPtr));
                            }
			    /* setObjectDescription(objectPtr, $15); */
			    (yyval.err) = 0;
			}
    break;

  case 188:
/* Line 1787 of yacc.c  */
#line 3615 "parser-smi.y"
    {
                            if (thisParserPtr->modulePtr->export.language != SMI_LANGUAGE_SPPI)
                                smiPrintError(thisParserPtr, ERR_SPPI_CONSTRUCT_IN_MIB, "SUBJECT-CATEGORIES");
                            (yyval.subjectCategoriesPtr) = (yyvsp[(3) - (4)].subjectCategoriesPtr);
                        }
    break;

  case 189:
/* Line 1787 of yacc.c  */
#line 3621 "parser-smi.y"
    {
                            if (thisParserPtr->modulePtr->export.language == SMI_LANGUAGE_SPPI)
                                smiPrintError(thisParserPtr, ERR_SUBJECT_CATEGORIES_MISSING);
                            (yyval.subjectCategoriesPtr) = NULL;
                        }
    break;

  case 190:
/* Line 1787 of yacc.c  */
#line 3629 "parser-smi.y"
    {
                            (yyval.subjectCategoriesPtr) = smiMalloc(sizeof(SubjectCategories));
                            (yyval.subjectCategoriesPtr)->categories    = (yyvsp[(1) - (1)].listPtr);
                        }
    break;

  case 191:
/* Line 1787 of yacc.c  */
#line 3636 "parser-smi.y"
    {
			    (yyval.listPtr) = smiMalloc(sizeof(List));
			    (yyval.listPtr)->ptr = (yyvsp[(1) - (1)].objectPtr);
			    (yyval.listPtr)->nextPtr = NULL;
			}
    break;

  case 192:
/* Line 1787 of yacc.c  */
#line 3642 "parser-smi.y"
    {
			    List *p, *pp;
			    
                            if ((yyvsp[(1) - (3)].listPtr)->ptr == NULL)
                                smiPrintError(thisParserPtr, ERR_SUBJECT_CATEGORIES_ALL);
			    p = smiMalloc(sizeof(List));
			    p->ptr = (void *)(yyvsp[(3) - (3)].objectPtr);
			    p->nextPtr = NULL;
			    for (pp = (yyvsp[(1) - (3)].listPtr); pp->nextPtr; pp = pp->nextPtr);
			    pp->nextPtr = p;
			    (yyval.listPtr) = (yyvsp[(1) - (3)].listPtr);
			}
    break;

  case 193:
/* Line 1787 of yacc.c  */
#line 3657 "parser-smi.y"
    {
                            Object *objectPtr;
                            
                            if (strcmp((yyvsp[(1) - (1)].id), "all"))
                                smiPrintError(thisParserPtr, ERR_SUBJECT_CATEGORIES_MISSING_SUBID);
                            else {
                                /*
                                 * This is not a regular object that will be added via
                                 * 'addObject' as subject category dentifier have no
                                 * other meaning in PIBs. They are just used for
                                 * a direct mapping to the actual protocol fields.
                                 */
                                objectPtr = smiMalloc(sizeof(Object));
                                objectPtr->export.name = "all";
                                objectPtr->export.oidlen = 0;
                                objectPtr->export.oid = 0;
                                (yyval.objectPtr) = objectPtr;
                            }
                            smiFree((yyvsp[(1) - (1)].id));
                        }
    break;

  case 194:
/* Line 1787 of yacc.c  */
#line 3678 "parser-smi.y"
    {
			    Object *objectPtr;
			    
                            if (!strcmp((yyvsp[(1) - (4)].id), "all")) {
                                smiPrintError(thisParserPtr, ERR_SUBJECT_CATEGORIES_ALL_WITH_SUBID);
                                (yyval.objectPtr) = NULL;
                            } else {
                                /*
                                 * This is not a regular object that will be added via
                                 * 'addObject' as subject category dentifier have no
                                 * other meaning in PIBs. They are just used for
                                 * a direct mapping to the actual protocol fields.
                                 */
                                objectPtr = smiMalloc(sizeof(Object));
                                objectPtr->export.name = (yyvsp[(1) - (4)].id);
                                objectPtr->export.oidlen = 1;
                                objectPtr->export.oid = (void *)(yyvsp[(3) - (4)].unsigned32);
                                (yyval.objectPtr) = objectPtr;
                            }
			}
    break;

  case 195:
/* Line 1787 of yacc.c  */
#line 3701 "parser-smi.y"
    {
			    (yyval.typePtr) = (yyvsp[(1) - (1)].typePtr);
			}
    break;

  case 196:
/* Line 1787 of yacc.c  */
#line 3705 "parser-smi.y"
    {
			    if (strcmp(thisParserPtr->modulePtr->export.name,
				       "SNMPv2-SMI") &&
			        strcmp(thisParserPtr->modulePtr->export.name,
				       "SNMPv2-TC") &&
				strcmp(thisParserPtr->modulePtr->export.name,
				       "SNMPv2-CONF") &&
				strcmp(thisParserPtr->modulePtr->export.name,
				       "RFC-1212") &&
				strcmp(thisParserPtr->modulePtr->export.name,
				       "RFC1065-SMI") &&
				strcmp(thisParserPtr->modulePtr->export.name,
				       "RFC1155-SMI") &&
                                strcmp(thisParserPtr->modulePtr->export.name,
                                       "COPS-PR-SPPI")) {
			        smiPrintError(thisParserPtr, ERR_TYPE_TAG, (yyvsp[(1) - (2)].err));
			    }
			    (yyval.typePtr) = (yyvsp[(2) - (2)].typePtr);
			}
    break;

  case 197:
/* Line 1787 of yacc.c  */
#line 3725 "parser-smi.y"
    {
			    /* TODO */
			    (yyval.typePtr) = (yyvsp[(1) - (1)].typePtr);
			}
    break;

  case 198:
/* Line 1787 of yacc.c  */
#line 3730 "parser-smi.y"
    {
			    /* TODO */
			    (yyval.typePtr) = (yyvsp[(1) - (1)].typePtr);
			}
    break;

  case 199:
/* Line 1787 of yacc.c  */
#line 3735 "parser-smi.y"
    {
			    /* TODO */
			    (yyval.typePtr) = (yyvsp[(1) - (1)].typePtr);
			}
    break;

  case 200:
/* Line 1787 of yacc.c  */
#line 3740 "parser-smi.y"
    {
			    Import *importPtr;

			    if ((yyvsp[(1) - (1)].typePtr) && (yyvsp[(1) - (1)].typePtr)->export.name) {
				importPtr = findImportByName((yyvsp[(1) - (1)].typePtr)->export.name,
							     thisModulePtr);
				if (importPtr) {
				    importPtr->use++;
				}
			    }

			    /* TODO */
			    (yyval.typePtr) = (yyvsp[(1) - (1)].typePtr);
			}
    break;

  case 201:
/* Line 1787 of yacc.c  */
#line 3757 "parser-smi.y"
    { (yyval.err) = 0; /* TODO: check range */ }
    break;

  case 202:
/* Line 1787 of yacc.c  */
#line 3759 "parser-smi.y"
    { (yyval.err) = 0; /* TODO: check range */ }
    break;

  case 203:
/* Line 1787 of yacc.c  */
#line 3767 "parser-smi.y"
    { (yyval.typePtr) = (yyvsp[(1) - (1)].typePtr); }
    break;

  case 204:
/* Line 1787 of yacc.c  */
#line 3772 "parser-smi.y"
    {
			    Import *importPtr;

			    if ((yyvsp[(1) - (1)].typePtr) && (yyvsp[(1) - (1)].typePtr)->export.name) {
				importPtr = findImportByName((yyvsp[(1) - (1)].typePtr)->export.name,
							     thisModulePtr);
				if (importPtr) {
				    importPtr->use++;
				}
			    }

			    /* TODO */
			    (yyval.typePtr) = (yyvsp[(1) - (1)].typePtr);
			}
    break;

  case 205:
/* Line 1787 of yacc.c  */
#line 3789 "parser-smi.y"
    { (yyval.valuePtr) = (yyvsp[(1) - (1)].valuePtr); }
    break;

  case 206:
/* Line 1787 of yacc.c  */
#line 3798 "parser-smi.y"
    {
			    if ((thisModulePtr->export.language == SMI_LANGUAGE_SMIV2)
				&&
				(strcmp(thisModulePtr->export.name, "SNMPv2-SMI") &&
				 strcmp(thisModulePtr->export.name, "SNMPv2-TC") &&
                                 strcmp(thisModulePtr->export.name, "COPS-PR-SPPI")))
				smiPrintError(thisParserPtr,
					      ERR_INTEGER_IN_SMIV2);

			    defaultBasetype = SMI_BASETYPE_INTEGER32;
			    (yyval.typePtr) = smiHandle->typeInteger32Ptr;
			}
    break;

  case 207:
/* Line 1787 of yacc.c  */
#line 3811 "parser-smi.y"
    {
			    defaultBasetype = SMI_BASETYPE_INTEGER32;
			}
    break;

  case 208:
/* Line 1787 of yacc.c  */
#line 3815 "parser-smi.y"
    {
			    if ((thisModulePtr->export.language == SMI_LANGUAGE_SMIV2)
				&&
				(strcmp(thisModulePtr->export.name, "SNMPv2-SMI") &&
				 strcmp(thisModulePtr->export.name, "SNMPv2-TC") &&
                                 strcmp(thisModulePtr->export.name, "COPS-PR-SPPI")))
				smiPrintError(thisParserPtr,
					      ERR_INTEGER_IN_SMIV2);

			    (yyval.typePtr) = duplicateType(smiHandle->typeInteger32Ptr, 0,
					       thisParserPtr);
			    setTypeList((yyval.typePtr), (yyvsp[(3) - (3)].listPtr));
			    smiCheckTypeRanges(thisParserPtr, (yyval.typePtr));
			}
    break;

  case 209:
/* Line 1787 of yacc.c  */
#line 3830 "parser-smi.y"
    {
			    defaultBasetype = SMI_BASETYPE_ENUM;
			}
    break;

  case 210:
/* Line 1787 of yacc.c  */
#line 3834 "parser-smi.y"
    {
			    List *p;
			    
			    (yyval.typePtr) = duplicateType(smiHandle->typeEnumPtr, 0,
					       thisParserPtr);
			    setTypeList((yyval.typePtr), (yyvsp[(3) - (3)].listPtr));
			    for (p = (yyvsp[(3) - (3)].listPtr); p; p = p->nextPtr)
				((NamedNumber *)p->ptr)->typePtr = (yyval.typePtr);
			    smiCheckNamedNumbersOrder(parserPtr, (yyval.typePtr));
			}
    break;

  case 211:
/* Line 1787 of yacc.c  */
#line 3845 "parser-smi.y"
    {
			    Import *importPtr;

			    defaultBasetype = SMI_BASETYPE_INTEGER32;
			    importPtr = findImportByName("Integer32",
							 thisModulePtr);
			    if (importPtr) {
				importPtr->use++;
			    } else {
				if (thisModulePtr->export.language ==
				    SMI_LANGUAGE_SMIV2) {
				    smiPrintError(thisParserPtr,
						  ERR_SMIV2_BASETYPE_NOT_IMPORTED,
						  "Integer32");
				} else if (thisModulePtr->export.language ==
					   SMI_LANGUAGE_SPPI) {
				    smiPrintError(thisParserPtr,
						  ERR_SPPI_BASETYPE_NOT_IMPORTED,
						  "Integer32");
				}
			    }

			    /* TODO: any need to distinguish from INTEGER? */
			    (yyval.typePtr) = smiHandle->typeInteger32Ptr;
			}
    break;

  case 212:
/* Line 1787 of yacc.c  */
#line 3871 "parser-smi.y"
    {
			    defaultBasetype = SMI_BASETYPE_INTEGER32;
			}
    break;

  case 213:
/* Line 1787 of yacc.c  */
#line 3875 "parser-smi.y"
    {
			    Import *importPtr;
			    
			    importPtr = findImportByName("Integer32",
							 thisModulePtr);
			    if (importPtr) {
				importPtr->use++;
			    } else {
				if (thisModulePtr->export.language ==
				    SMI_LANGUAGE_SMIV2) {
				    smiPrintError(thisParserPtr,
						  ERR_SMIV2_BASETYPE_NOT_IMPORTED,
						  "Integer32");
				} else if (thisModulePtr->export.language ==
					   SMI_LANGUAGE_SPPI) {
				    smiPrintError(thisParserPtr,
						  ERR_SPPI_BASETYPE_NOT_IMPORTED,
						  "Integer32");
				}
			    }

			    (yyval.typePtr) = duplicateType(smiHandle->typeInteger32Ptr, 0,
					       thisParserPtr);
			    setTypeList((yyval.typePtr), (yyvsp[(3) - (3)].listPtr));
			    smiCheckTypeRanges(thisParserPtr, (yyval.typePtr));
			}
    break;

  case 214:
/* Line 1787 of yacc.c  */
#line 3902 "parser-smi.y"
    {
			    defaultBasetype = SMI_BASETYPE_ENUM;
			}
    break;

  case 215:
/* Line 1787 of yacc.c  */
#line 3906 "parser-smi.y"
    {
			    Type *parentPtr;
			    Import *importPtr;
			    List *p;
			    
			    parentPtr = findTypeByModuleAndName(
			        thisParserPtr->modulePtr, (yyvsp[(1) - (3)].id));
			    if (!parentPtr) {
			        importPtr = findImportByName((yyvsp[(1) - (3)].id),
							     thisModulePtr);
				if (importPtr &&
				    importPtr->kind == KIND_TYPE) {
				    importPtr->use++;
				    parentPtr = findTypeByModulenameAndName(
					importPtr->export.module, (yyvsp[(1) - (3)].id));
				}
			    }
			    if (parentPtr) {
				if ((parentPtr->export.basetype !=
				     SMI_BASETYPE_ENUM) &&
				    (parentPtr->export.basetype !=
				     SMI_BASETYPE_BITS)) {
				    smiPrintError(thisParserPtr,
						  ERR_ILLEGAL_ENUM_FOR_PARENT_TYPE,
						  (yyvsp[(1) - (3)].id));
				    (yyval.typePtr) = duplicateType(smiHandle->typeEnumPtr, 0,
						       thisParserPtr);
				} else {
				    (yyval.typePtr) = duplicateType(parentPtr, 0,
						       thisParserPtr);
				}
				smiFree((yyvsp[(1) - (3)].id));
			    } else {
				/* 
				 * forward referenced type. create it,
				 * marked with FLAG_INCOMPLETE.
				 */
				parentPtr = addType((yyvsp[(1) - (3)].id),
						    SMI_BASETYPE_UNKNOWN,
						    FLAG_INCOMPLETE,
						    thisParserPtr);
				(yyval.typePtr) = duplicateType(parentPtr, 0,
						   thisParserPtr);
			    }
			    setTypeList((yyval.typePtr), (yyvsp[(3) - (3)].listPtr));
			    for (p = (yyvsp[(3) - (3)].listPtr); p; p = p->nextPtr)
				((NamedNumber *)p->ptr)->typePtr = (yyval.typePtr);
			    smiCheckNamedNumbersOrder(parserPtr, (yyval.typePtr));
			}
    break;

  case 216:
/* Line 1787 of yacc.c  */
#line 3957 "parser-smi.y"
    {
			    Type *parentPtr;
			    Import *importPtr;
			    List *p;
			    
                            defaultBasetype = SMI_BASETYPE_ENUM;
                            parentPtr = findTypeByModulenameAndName((yyvsp[(1) - (4)].id), (yyvsp[(3) - (4)].id));
			    if (!parentPtr) {
				importPtr =
				    findImportByModulenameAndName((yyvsp[(1) - (4)].id),
							  (yyvsp[(3) - (4)].id), thisModulePtr);
				if (importPtr &&
				    importPtr->kind == KIND_TYPE) {
				    importPtr->use++;
				    parentPtr =
					findTypeByModulenameAndName((yyvsp[(1) - (4)].id), (yyvsp[(3) - (4)].id));
				}
			    }
			    if (parentPtr) {
				if ((parentPtr->export.basetype !=
				     SMI_BASETYPE_ENUM) &&
				    (parentPtr->export.basetype !=
				     SMI_BASETYPE_BITS)) {
				    smiPrintError(thisParserPtr,
						  ERR_ILLEGAL_ENUM_FOR_PARENT_TYPE,
						  (yyvsp[(3) - (4)].id));
				    (yyval.typePtr) = duplicateType(smiHandle->typeEnumPtr, 0,
						       thisParserPtr);
				} else {
				    (yyval.typePtr) = duplicateType(parentPtr, 0,
						       thisParserPtr);
				}
			    } else {
				smiPrintError(thisParserPtr,
					      ERR_UNKNOWN_TYPE, (yyvsp[(3) - (4)].id));
				(yyval.typePtr) = duplicateType(smiHandle->typeEnumPtr, 0,
						   thisParserPtr);
			    }
			    setTypeList((yyval.typePtr), (yyvsp[(4) - (4)].listPtr));
			    for (p = (yyvsp[(4) - (4)].listPtr); p; p = p->nextPtr)
				((NamedNumber *)p->ptr)->typePtr = (yyval.typePtr);
			    smiCheckNamedNumbersOrder(parserPtr, (yyval.typePtr));
			    smiFree((yyvsp[(1) - (4)].id));
			    smiFree((yyvsp[(3) - (4)].id));
			}
    break;

  case 217:
/* Line 1787 of yacc.c  */
#line 4003 "parser-smi.y"
    {
			    Type *parentPtr;
			    Import *importPtr;
			    
			    parentPtr = findTypeByModuleAndName(
				thisParserPtr->modulePtr, (yyvsp[(1) - (2)].id));
			    if (!parentPtr) {
				importPtr = findImportByName((yyvsp[(1) - (2)].id),
							     thisModulePtr);
				if (importPtr &&
				    importPtr->kind == KIND_TYPE) {
				    importPtr->use++;
				    parentPtr = findTypeByModulenameAndName(
					importPtr->export.module, (yyvsp[(1) - (2)].id));
				}
			    }
			    if (parentPtr) {
				if ((parentPtr->export.basetype !=
				    SMI_BASETYPE_INTEGER32) &&
				    (parentPtr->export.basetype !=
				     SMI_BASETYPE_INTEGER64) &&
				    (parentPtr->export.basetype !=
				     SMI_BASETYPE_UNSIGNED32) &&
				    (parentPtr->export.basetype !=
				     SMI_BASETYPE_UNSIGNED64)) {
				    smiPrintError(thisParserPtr,
					     ERR_ILLEGAL_RANGE_FOR_PARENT_TYPE,
						  (yyvsp[(1) - (2)].id));
				    (yyval.typePtr) = duplicateType(smiHandle->typeInteger32Ptr, 0,
						       thisParserPtr);
				    defaultBasetype = SMI_BASETYPE_INTEGER32;
				} else {
				    defaultBasetype =
					parentPtr->export.basetype;
				    (yyval.typePtr) = duplicateType(parentPtr, 0,
						       thisParserPtr);
				}
				smiFree((yyvsp[(1) - (2)].id));
			    } else {
				/* 
				 * forward referenced type. create it,
				 * marked with FLAG_INCOMPLETE.
				 */
				parentPtr = addType((yyvsp[(1) - (2)].id),
						    SMI_BASETYPE_UNKNOWN,
						    FLAG_INCOMPLETE,
						    thisParserPtr);
				(yyval.typePtr) = duplicateType(parentPtr, 0,
						   thisParserPtr);
				defaultBasetype = SMI_BASETYPE_INTEGER32;
			    }
			    setTypeList((yyval.typePtr), (yyvsp[(2) - (2)].listPtr));
			    smiCheckTypeRanges(thisParserPtr, (yyval.typePtr));
			}
    break;

  case 218:
/* Line 1787 of yacc.c  */
#line 4059 "parser-smi.y"
    {
			    Type *parentPtr;
			    Import *importPtr;
			    
			    parentPtr = findTypeByModulenameAndName((yyvsp[(1) - (4)].id), (yyvsp[(3) - (4)].id));
			    if (!parentPtr) {
				importPtr = findImportByModulenameAndName((yyvsp[(1) - (4)].id),
							  (yyvsp[(3) - (4)].id), thisModulePtr);
				if (importPtr &&
				    importPtr->kind == KIND_TYPE) {
				    importPtr->use++;
				    parentPtr = findTypeByModulenameAndName(
					(yyvsp[(1) - (4)].id), (yyvsp[(3) - (4)].id));
				}
			    }
			    if (parentPtr) {
				if ((parentPtr->export.basetype !=
				    SMI_BASETYPE_INTEGER32) &&
				    (parentPtr->export.basetype !=
				     SMI_BASETYPE_INTEGER64) &&
				    (parentPtr->export.basetype !=
				     SMI_BASETYPE_UNSIGNED32) &&
				    (parentPtr->export.basetype !=
				     SMI_BASETYPE_UNSIGNED64)) {
				    smiPrintError(thisParserPtr,
					     ERR_ILLEGAL_RANGE_FOR_PARENT_TYPE,
						  (yyvsp[(3) - (4)].id));
				    (yyval.typePtr) = duplicateType(smiHandle->typeInteger32Ptr, 0,
						       thisParserPtr);
				    defaultBasetype = SMI_BASETYPE_INTEGER32;
				} else {
				    defaultBasetype =
					parentPtr->export.basetype;
				    (yyval.typePtr) = duplicateType(parentPtr, 0,
						       thisParserPtr);
				}
			    } else {
				smiPrintError(thisParserPtr,
					      ERR_UNKNOWN_TYPE, (yyvsp[(3) - (4)].id));
				(yyval.typePtr) = duplicateType(smiHandle->typeInteger32Ptr, 0,
						   thisParserPtr);
				defaultBasetype = SMI_BASETYPE_INTEGER32;
			    }
			    setTypeList((yyval.typePtr), (yyvsp[(4) - (4)].listPtr));
			    smiCheckTypeRanges(thisParserPtr, (yyval.typePtr));
			    smiFree((yyvsp[(1) - (4)].id));
			    smiFree((yyvsp[(3) - (4)].id));
			}
    break;

  case 219:
/* Line 1787 of yacc.c  */
#line 4108 "parser-smi.y"
    {
			    defaultBasetype = SMI_BASETYPE_OCTETSTRING;
			    (yyval.typePtr) = smiHandle->typeOctetStringPtr;
			}
    break;

  case 220:
/* Line 1787 of yacc.c  */
#line 4113 "parser-smi.y"
    {
			    defaultBasetype = SMI_BASETYPE_OCTETSTRING;
			}
    break;

  case 221:
/* Line 1787 of yacc.c  */
#line 4117 "parser-smi.y"
    {
			    
			    (yyval.typePtr) = duplicateType(smiHandle->typeOctetStringPtr, 0,
					       thisParserPtr);
			    setTypeList((yyval.typePtr), (yyvsp[(4) - (4)].listPtr));
			    smiCheckTypeRanges(thisParserPtr, (yyval.typePtr));
			}
    break;

  case 222:
/* Line 1787 of yacc.c  */
#line 4125 "parser-smi.y"
    {
			    Type *parentPtr;
			    Import *importPtr;
			    
			    defaultBasetype = SMI_BASETYPE_OCTETSTRING;
			    parentPtr = findTypeByModuleAndName(
				thisParserPtr->modulePtr, (yyvsp[(1) - (2)].id));
			    if (!parentPtr) {
				importPtr = findImportByName((yyvsp[(1) - (2)].id),
							     thisModulePtr);
				if (importPtr &&
				    importPtr->kind == KIND_TYPE) {
				    importPtr->use++;
				    parentPtr = findTypeByModulenameAndName(
					importPtr->export.module, (yyvsp[(1) - (2)].id));
				}
			    }
			    if (parentPtr) {
				if (parentPtr->export.basetype !=
				    SMI_BASETYPE_OCTETSTRING) {
				    smiPrintError(thisParserPtr,
					      ERR_ILLEGAL_SIZE_FOR_PARENT_TYPE,
						  (yyvsp[(1) - (2)].id));
				    (yyval.typePtr) = duplicateType(smiHandle->typeOctetStringPtr, 0,
						       thisParserPtr);
				} else {
				    (yyval.typePtr) = duplicateType(parentPtr, 0,
						       thisParserPtr);
				}
				smiFree((yyvsp[(1) - (2)].id));
			    } else {
				/* 
				 * forward referenced type. create it,
				 * marked with FLAG_INCOMPLETE.
				 */
				parentPtr = addType((yyvsp[(1) - (2)].id),
						    SMI_BASETYPE_UNKNOWN,
						    FLAG_INCOMPLETE,
						    thisParserPtr);
				(yyval.typePtr) = duplicateType(parentPtr, 0,
						   thisParserPtr);
			    }
			    setTypeList((yyval.typePtr), (yyvsp[(2) - (2)].listPtr));
			    smiCheckTypeRanges(thisParserPtr, (yyval.typePtr));
			}
    break;

  case 223:
/* Line 1787 of yacc.c  */
#line 4172 "parser-smi.y"
    {
			    Type *parentPtr;
			    Import *importPtr;
			    
			    defaultBasetype = SMI_BASETYPE_OCTETSTRING;
			    parentPtr = findTypeByModulenameAndName((yyvsp[(1) - (4)].id), (yyvsp[(3) - (4)].id));
			    if (!parentPtr) {
				importPtr = findImportByModulenameAndName((yyvsp[(1) - (4)].id),
							  (yyvsp[(3) - (4)].id), thisModulePtr);
				if (importPtr &&
				    importPtr->kind == KIND_TYPE) {
				    importPtr->use++;
				    parentPtr = findTypeByModulenameAndName(
					(yyvsp[(1) - (4)].id), (yyvsp[(3) - (4)].id));
				}
			    }
			    if (parentPtr) {
				if (parentPtr->export.basetype !=
				    SMI_BASETYPE_OCTETSTRING) {
				    smiPrintError(thisParserPtr,
					      ERR_ILLEGAL_SIZE_FOR_PARENT_TYPE,
						  (yyvsp[(3) - (4)].id));
				    (yyval.typePtr) = duplicateType(smiHandle->typeOctetStringPtr, 0,
						       thisParserPtr);
				} else {
				    (yyval.typePtr) = duplicateType(parentPtr, 0,
						       thisParserPtr);
				}
			    } else {
				smiPrintError(thisParserPtr,
					      ERR_UNKNOWN_TYPE, (yyvsp[(3) - (4)].id));
				(yyval.typePtr) = duplicateType(smiHandle->typeOctetStringPtr, 0,
						   thisParserPtr);
			    }
			    setTypeList((yyval.typePtr), (yyvsp[(4) - (4)].listPtr));
			    smiCheckTypeRanges(thisParserPtr, (yyval.typePtr));
			    smiFree((yyvsp[(1) - (4)].id));
			    smiFree((yyvsp[(3) - (4)].id));
			}
    break;

  case 224:
/* Line 1787 of yacc.c  */
#line 4212 "parser-smi.y"
    {
			    defaultBasetype = SMI_BASETYPE_OBJECTIDENTIFIER;
			    (yyval.typePtr) = smiHandle->typeObjectIdentifierPtr;
			}
    break;

  case 225:
/* Line 1787 of yacc.c  */
#line 4220 "parser-smi.y"
    {
			    (yyval.valuePtr) = smiMalloc(sizeof(SmiValue));
			    (yyval.valuePtr)->basetype = SMI_BASETYPE_UNSIGNED32;
			    (yyval.valuePtr)->value.unsigned32 = (yyvsp[(1) - (1)].unsigned32);
			}
    break;

  case 226:
/* Line 1787 of yacc.c  */
#line 4226 "parser-smi.y"
    {
			    (yyval.valuePtr) = smiMalloc(sizeof(SmiValue));
			    (yyval.valuePtr)->basetype = SMI_BASETYPE_INTEGER32;
			    (yyval.valuePtr)->value.integer32 = (yyvsp[(1) - (1)].integer32);
			}
    break;

  case 227:
/* Line 1787 of yacc.c  */
#line 4232 "parser-smi.y"
    {   
                            /* The scanner already checks for the language */
			    (yyval.valuePtr) = smiMalloc(sizeof(SmiValue));
			    (yyval.valuePtr)->basetype = SMI_BASETYPE_UNSIGNED64;
			    (yyval.valuePtr)->value.unsigned64 = (yyvsp[(1) - (1)].unsigned64);
			}
    break;

  case 228:
/* Line 1787 of yacc.c  */
#line 4239 "parser-smi.y"
    {
                            /* The scanner already checks for the language */
			    (yyval.valuePtr) = smiMalloc(sizeof(SmiValue));
			    (yyval.valuePtr)->basetype = SMI_BASETYPE_INTEGER64;
			    (yyval.valuePtr)->value.integer64 = (yyvsp[(1) - (1)].integer64);
			}
    break;

  case 229:
/* Line 1787 of yacc.c  */
#line 4246 "parser-smi.y"
    {
			    char s[9];
			    int i, len, j;
			    
			    (yyval.valuePtr) = smiMalloc(sizeof(SmiValue));
			    if (defaultBasetype == SMI_BASETYPE_OCTETSTRING) {
				(yyval.valuePtr)->basetype = SMI_BASETYPE_OCTETSTRING;
				len = strlen((yyvsp[(1) - (1)].text));
				(yyval.valuePtr)->value.ptr =
				    smiMalloc((len+7)/8+1);
				for (i = 0; i < len; i += 8) {
				    strncpy(s, &(yyvsp[(1) - (1)].text)[i], 8);
				    for (j = 1; j < 8; j++) {
					if (!s[j]) s[j] = '0';
				    }
				    s[8] = 0;
				    (yyval.valuePtr)->value.ptr[i/8] =
					(unsigned char)strtol(s, 0, 2);
				}
				(yyval.valuePtr)->len = (len+7)/8;
			    } else {
				(yyval.valuePtr)->basetype = SMI_BASETYPE_UNSIGNED32;
				(yyval.valuePtr)->value.unsigned32 = strtoul((yyvsp[(1) - (1)].text), NULL, 2);
			    }
			}
    break;

  case 230:
/* Line 1787 of yacc.c  */
#line 4272 "parser-smi.y"
    {
			    char s[3];
			    int i, len;
			    
			    (yyval.valuePtr) = smiMalloc(sizeof(SmiValue));
			    if (defaultBasetype == SMI_BASETYPE_OCTETSTRING) {
				(yyval.valuePtr)->basetype = SMI_BASETYPE_OCTETSTRING;
				len = strlen((yyvsp[(1) - (1)].text));
				(yyval.valuePtr)->value.ptr = smiMalloc((len+1)/2+1);
				for (i = 0; i < len; i += 2) {
				    strncpy(s, &(yyvsp[(1) - (1)].text)[i], 2);
				    if (!s[1]) s[1] = '0';
				    s[2] = 0;
				    (yyval.valuePtr)->value.ptr[i/2] =
					(unsigned char)strtol(s, 0, 16);
				}
				(yyval.valuePtr)->len = (len+1)/2;
			    } else {
				(yyval.valuePtr)->basetype = SMI_BASETYPE_UNSIGNED32;
				(yyval.valuePtr)->value.unsigned32 = strtoul((yyvsp[(1) - (1)].text), NULL, 16);
			    }
			}
    break;

  case 231:
/* Line 1787 of yacc.c  */
#line 4295 "parser-smi.y"
    {
			    (yyval.valuePtr) = smiMalloc(sizeof(SmiValue));
			    if ((defaultBasetype != SMI_BASETYPE_ENUM) &&
				(defaultBasetype != SMI_BASETYPE_OBJECTIDENTIFIER)) {
				smiPrintError(thisParserPtr, ERR_DEFVAL_SYNTAX);
				(yyval.valuePtr)->basetype = defaultBasetype;
				if (defaultBasetype == SMI_BASETYPE_ENUM) {
				    (yyval.valuePtr)->len = 1;
				    (yyval.valuePtr)->value.unsigned32 = 0;
				} else {
				    (yyval.valuePtr)->len = 0;
				    (yyval.valuePtr)->value.ptr = NULL;
				}
			    } else {
				(yyval.valuePtr)->basetype = defaultBasetype;
				(yyval.valuePtr)->len = -1;  /* indicates unresolved ptr */
				(yyval.valuePtr)->value.ptr = (unsigned char *) (yyvsp[(1) - (1)].id); /* JS: needs strdup? */
			    }
			}
    break;

  case 232:
/* Line 1787 of yacc.c  */
#line 4315 "parser-smi.y"
    {
			    (yyval.valuePtr) = smiMalloc(sizeof(SmiValue));
			    (yyval.valuePtr)->basetype = SMI_BASETYPE_OCTETSTRING;
			    (yyval.valuePtr)->value.ptr = (unsigned char *) smiStrdup((yyvsp[(1) - (1)].text));
			    (yyval.valuePtr)->len = strlen((yyvsp[(1) - (1)].text));
			}
    break;

  case 233:
/* Line 1787 of yacc.c  */
#line 4338 "parser-smi.y"
    {
			    /*
			     * SMIv1 allows something like { 0 0 } !
			     * SMIv2 does not!
			     */
			    /* TODO: make it work correctly for SMIv1 */
			    if (thisModulePtr->export.language == SMI_LANGUAGE_SMIV2) {
				smiPrintError(thisParserPtr,
					      ERR_OID_DEFVAL_TOO_LONG_SMIV2);
			    } else {
				smiPrintError(thisParserPtr,
					      ERR_OID_DEFVAL_TOO_LONG_SMIV1);
			    }
			    (yyval.valuePtr) = smiMalloc(sizeof(SmiValue));
			    (yyval.valuePtr)->basetype = SMI_BASETYPE_OBJECTIDENTIFIER;
			    (yyval.valuePtr)->len = 2;
			    (yyval.valuePtr)->value.oid = smiMalloc(2 * sizeof(SmiSubid));
			    (yyval.valuePtr)->value.oid[0] = 0;
			    (yyval.valuePtr)->value.oid[1] = 0;
			}
    break;

  case 234:
/* Line 1787 of yacc.c  */
#line 4365 "parser-smi.y"
    {
			    (yyval.typePtr) = smiHandle->typeInteger32Ptr;
			}
    break;

  case 235:
/* Line 1787 of yacc.c  */
#line 4369 "parser-smi.y"
    {
			    Import *importPtr;
			    
			    /* TODO: any need to distinguish from INTEGER? */
			    (yyval.typePtr) = smiHandle->typeInteger32Ptr;

			    importPtr = findImportByName("Integer32",
							 thisModulePtr);
			    if (importPtr) {
				importPtr->use++;
			    } else {
				if (thisModulePtr->export.language ==
				    SMI_LANGUAGE_SMIV2) {
				    smiPrintError(thisParserPtr,
						  ERR_SMIV2_BASETYPE_NOT_IMPORTED,
						  "Integer32");
				} else if (thisModulePtr->export.language ==
					   SMI_LANGUAGE_SPPI) {
				    smiPrintError(thisParserPtr,
						  ERR_SPPI_BASETYPE_NOT_IMPORTED,
						  "Integer32");
				}
			    }
			}
    break;

  case 236:
/* Line 1787 of yacc.c  */
#line 4394 "parser-smi.y"
    {
			    (yyval.typePtr) = smiHandle->typeOctetStringPtr;
			}
    break;

  case 237:
/* Line 1787 of yacc.c  */
#line 4398 "parser-smi.y"
    {
			    (yyval.typePtr) = smiHandle->typeObjectIdentifierPtr;
			}
    break;

  case 238:
/* Line 1787 of yacc.c  */
#line 4404 "parser-smi.y"
    {
			    Import *importPtr;
			    
			    (yyval.typePtr) = findTypeByName("IpAddress");
			    if (! (yyval.typePtr)) {
				smiPrintError(thisParserPtr, ERR_UNKNOWN_TYPE,
					      "IpAddress");
			    }
			    
			    importPtr = findImportByName("IpAddress",
							 thisModulePtr);
			    if (importPtr) {
				importPtr->use++;
			    } else {
				if (thisModulePtr->export.language ==
				    SMI_LANGUAGE_SMIV2) {
				    smiPrintError(thisParserPtr,
						  ERR_SMIV2_BASETYPE_NOT_IMPORTED,
						  "IpAddress");
				} else if (thisModulePtr->export.language ==
					   SMI_LANGUAGE_SPPI) {
				    smiPrintError(thisParserPtr,
						  ERR_SPPI_BASETYPE_NOT_IMPORTED,
						  "IpAddress");
				}
			    }
			}
    break;

  case 239:
/* Line 1787 of yacc.c  */
#line 4432 "parser-smi.y"
    {
			    Import *importPtr;

                            if ((thisParserPtr->modulePtr->export.language == SMI_LANGUAGE_SPPI) &&
                                !findImportByName("Counter32", thisParserPtr->modulePtr))
                                smiPrintError(thisParserPtr, ERR_SMI_CONSTRUCT_IN_PIB, "COUNTER32");
			    (yyval.typePtr) = findTypeByName("Counter32");
			    if (! (yyval.typePtr)) {
				smiPrintError(thisParserPtr, ERR_UNKNOWN_TYPE,
					      "Counter32");
			    }
			    
			    importPtr = findImportByName("Counter32",
							 thisModulePtr);
			    if (importPtr) {
				importPtr->use++;
			    } else {
				if (thisModulePtr->export.language ==
				    SMI_LANGUAGE_SMIV2) {
				    smiPrintError(thisParserPtr,
						  ERR_SMIV2_BASETYPE_NOT_IMPORTED,
						  "Counter32");
				}
			    }
			}
    break;

  case 240:
/* Line 1787 of yacc.c  */
#line 4458 "parser-smi.y"
    {
			    Import *importPtr;
			    List *listPtr, *nextListPtr;
			    
			    smiPrintError(thisParserPtr,
					  ERR_ILLEGAL_RANGE_FOR_COUNTER,
					  "Counter32");
			    for (listPtr = (yyvsp[(2) - (2)].listPtr); listPtr;
				 listPtr = nextListPtr) {
				nextListPtr = listPtr->nextPtr;
				smiFree((Range *)listPtr->ptr);
				smiFree(listPtr);
			    }
			    
                            if ((thisParserPtr->modulePtr->export.language == SMI_LANGUAGE_SPPI) &&
                                !findImportByName("Counter32", thisParserPtr->modulePtr))
                                smiPrintError(thisParserPtr, ERR_SMI_CONSTRUCT_IN_PIB, "Counter32");
			    (yyval.typePtr) = findTypeByName("Counter32");
			    if (! (yyval.typePtr)) {
				smiPrintError(thisParserPtr, ERR_UNKNOWN_TYPE,
					      "Counter32");
			    }
			    
			    importPtr = findImportByName("Counter32",
							 thisModulePtr);
			    if (importPtr) {
				importPtr->use++;
			    } else {
				if (thisModulePtr->export.language ==
				    SMI_LANGUAGE_SMIV2) {
				    smiPrintError(thisParserPtr,
						  ERR_SMIV2_BASETYPE_NOT_IMPORTED,
						  "Counter32");
				}
			    }
			}
    break;

  case 241:
/* Line 1787 of yacc.c  */
#line 4495 "parser-smi.y"
    {
			    Import *importPtr;

                            if ((thisParserPtr->modulePtr->export.language == SMI_LANGUAGE_SPPI) &&
                                !findImportByName("Gauge32", thisParserPtr->modulePtr))
                                smiPrintError(thisParserPtr, ERR_SMI_CONSTRUCT_IN_PIB, "Gauge32");
			    (yyval.typePtr) = findTypeByName("Gauge32");
			    if (! (yyval.typePtr)) {
				smiPrintError(thisParserPtr, ERR_UNKNOWN_TYPE,
					      "Gauge32");
			    }
			    
			    importPtr = findImportByName("Gauge32",
							 thisModulePtr);
			    if (importPtr) {
				importPtr->use++;
			    } else {
				if (thisModulePtr->export.language ==
				    SMI_LANGUAGE_SMIV2) {
				    smiPrintError(thisParserPtr,
						  ERR_SMIV2_BASETYPE_NOT_IMPORTED,
						  "Gauge32");
				}
			    }
			}
    break;

  case 242:
/* Line 1787 of yacc.c  */
#line 4521 "parser-smi.y"
    {
			    Type *parentPtr;
			    Import *importPtr;
			    
                            if ((thisParserPtr->modulePtr->export.language == SMI_LANGUAGE_SPPI) &&
                                !findImportByName("Gauge32", thisParserPtr->modulePtr))
                                smiPrintError(thisParserPtr, ERR_SMI_CONSTRUCT_IN_PIB, "Gauge32");
			    parentPtr = findTypeByName("Gauge32");
			    if (! parentPtr) {
				smiPrintError(thisParserPtr, ERR_UNKNOWN_TYPE,
					      "Gauge32");
				(yyval.typePtr) = NULL;
			    } else {
				(yyval.typePtr) = duplicateType(parentPtr, 0,
						   thisParserPtr);
				setTypeList((yyval.typePtr), (yyvsp[(2) - (2)].listPtr));
				smiCheckTypeRanges(thisParserPtr, (yyval.typePtr));
			    }
			    
			    importPtr = findImportByName("Gauge32",
							 thisModulePtr);
			    if (importPtr) {
				importPtr->use++;
			    } else {
				if (thisModulePtr->export.language ==
				    SMI_LANGUAGE_SMIV2) {
				    smiPrintError(thisParserPtr,
						  ERR_SMIV2_BASETYPE_NOT_IMPORTED,
						  "Gauge32");
				}
			    }
			}
    break;

  case 243:
/* Line 1787 of yacc.c  */
#line 4554 "parser-smi.y"
    {
			    Import *importPtr;

			    (yyval.typePtr) = smiHandle->typeUnsigned32Ptr;
			    
			    importPtr = findImportByName("Unsigned32",
							 thisModulePtr);
			    if (importPtr) {
				importPtr->use++;
			    } else {
				if (thisModulePtr->export.language ==
				    SMI_LANGUAGE_SMIV2) {
				    smiPrintError(thisParserPtr,
						  ERR_SMIV2_BASETYPE_NOT_IMPORTED,
						  "Unsigned32");
				} else if (thisModulePtr->export.language ==
					   SMI_LANGUAGE_SPPI) {
				    smiPrintError(thisParserPtr,
						  ERR_SPPI_BASETYPE_NOT_IMPORTED,
						  "Unsigned32");
				}
			    }
			}
    break;

  case 244:
/* Line 1787 of yacc.c  */
#line 4578 "parser-smi.y"
    {
			    defaultBasetype = SMI_BASETYPE_UNSIGNED32;
			}
    break;

  case 245:
/* Line 1787 of yacc.c  */
#line 4582 "parser-smi.y"
    {
			    Import *importPtr;
			    
			    (yyval.typePtr) = duplicateType(smiHandle->typeUnsigned32Ptr, 0,
					       thisParserPtr);
			    setTypeList((yyval.typePtr), (yyvsp[(3) - (3)].listPtr));
			    smiCheckTypeRanges(thisParserPtr, (yyval.typePtr));

			    importPtr = findImportByName("Unsigned32",
							 thisModulePtr);
			    if (importPtr) {
				importPtr->use++;
			    } else {
				if (thisModulePtr->export.language ==
				    SMI_LANGUAGE_SMIV2) {
				    smiPrintError(thisParserPtr,
						  ERR_SMIV2_BASETYPE_NOT_IMPORTED,
						  "Unsigned32");
				} else if (thisModulePtr->export.language ==
					   SMI_LANGUAGE_SPPI) {
				    smiPrintError(thisParserPtr,
						  ERR_SPPI_BASETYPE_NOT_IMPORTED,
						  "Unsigned32");
				}
			    }
			}
    break;

  case 246:
/* Line 1787 of yacc.c  */
#line 4609 "parser-smi.y"
    {
			    Import *importPtr;
			    
			    (yyval.typePtr) = findTypeByName("TimeTicks");
			    if (! (yyval.typePtr)) {
				smiPrintError(thisParserPtr, ERR_UNKNOWN_TYPE,
					      "TimeTicks");
			    }
			    
			    importPtr = findImportByName("TimeTicks",
							 thisModulePtr);
			    if (importPtr) {
				importPtr->use++;
			    } else {
				if (thisModulePtr->export.language ==
				    SMI_LANGUAGE_SMIV2) {
				    smiPrintError(thisParserPtr,
						  ERR_SMIV2_BASETYPE_NOT_IMPORTED,
						  "TimeTicks");
				} else if (thisModulePtr->export.language ==
					   SMI_LANGUAGE_SPPI) {
				    smiPrintError(thisParserPtr,
						  ERR_SPPI_BASETYPE_NOT_IMPORTED,
						  "TimeTicks");
				}
			    }
			}
    break;

  case 247:
/* Line 1787 of yacc.c  */
#line 4637 "parser-smi.y"
    {
			    Import *importPtr;
			    
			    (yyval.typePtr) = findTypeByName("Opaque");
			    if (! (yyval.typePtr)) {
				smiPrintError(thisParserPtr, ERR_UNKNOWN_TYPE,
					      "Opaque");
			    } else {
				if (thisModulePtr->export.language ==
				    SMI_LANGUAGE_SMIV2) {
				    smiPrintError(thisParserPtr,
						  ERR_SMIV2_OPAQUE_OBSOLETE);
				} else if (thisModulePtr->export.language ==
					   SMI_LANGUAGE_SPPI) {
				    smiPrintError(thisParserPtr,
						  ERR_SPPI_OPAQUE_OBSOLETE);
				}
			    }
			    
			    importPtr = findImportByName("Opaque",
							 thisModulePtr);
			    if (importPtr) {
				importPtr->use++;
			    } else {
				if (thisModulePtr->export.language ==
				    SMI_LANGUAGE_SMIV2) {
				    smiPrintError(thisParserPtr,
						  ERR_SMIV2_BASETYPE_NOT_IMPORTED,
						  "Opaque");
				} else if (thisModulePtr->export.language ==
					   SMI_LANGUAGE_SPPI) {
				    smiPrintError(thisParserPtr,
						  ERR_SPPI_BASETYPE_NOT_IMPORTED,
						  "Opaque");
				}
			    }
			}
    break;

  case 248:
/* Line 1787 of yacc.c  */
#line 4675 "parser-smi.y"
    {
			    Type *parentPtr;
			    Import *importPtr;
			    
			    parentPtr = findTypeByName("Opaque");
			    if (! parentPtr) {
				smiPrintError(thisParserPtr, ERR_UNKNOWN_TYPE,
					      "Opaque");
				(yyval.typePtr) = NULL;
			    } else {
				if (thisModulePtr->export.language ==
				    SMI_LANGUAGE_SMIV2) {
				    smiPrintError(thisParserPtr,
						  ERR_SMIV2_OPAQUE_OBSOLETE,
						  "Opaque");
				} else if (thisModulePtr->export.language ==
					   SMI_LANGUAGE_SPPI) {
				    smiPrintError(thisParserPtr,
						  ERR_SPPI_OPAQUE_OBSOLETE,
						  "Opaque");
				}
				(yyval.typePtr) = duplicateType(parentPtr, 0,
						   thisParserPtr);
				setTypeList((yyval.typePtr), (yyvsp[(2) - (2)].listPtr));
				smiCheckTypeRanges(thisParserPtr, (yyval.typePtr));
			    }

			    importPtr = findImportByName("Opaque",
							 thisModulePtr);
			    if (importPtr) {
				importPtr->use++;
			    } else {
				if (thisModulePtr->export.language ==
				    SMI_LANGUAGE_SMIV2) {
				    smiPrintError(thisParserPtr,
						  ERR_SMIV2_BASETYPE_NOT_IMPORTED,
						  "Opaque");
				} else if (thisModulePtr->export.language ==
					   SMI_LANGUAGE_SPPI) {
				    smiPrintError(thisParserPtr,
						  ERR_SPPI_BASETYPE_NOT_IMPORTED,
						  "Opaque");
				}
			    }
			}
    break;

  case 249:
/* Line 1787 of yacc.c  */
#line 4721 "parser-smi.y"
    {
			    Import *importPtr;

                            if ((thisParserPtr->modulePtr->export.language == SMI_LANGUAGE_SPPI) &&
                                !findImportByName("Counter64", thisParserPtr->modulePtr))
                                smiPrintError(thisParserPtr, ERR_SMI_CONSTRUCT_IN_PIB, "Counter64");
			    (yyval.typePtr) = findTypeByName("Counter64");
			    if (! (yyval.typePtr)) {
				smiPrintError(thisParserPtr, ERR_UNKNOWN_TYPE,
					      "Counter64");
			    }

			    importPtr = findImportByName("Counter64",
							 thisModulePtr);
			    if (importPtr) {
				importPtr->use++;
			    } else {
				if (thisModulePtr->export.language ==
				    SMI_LANGUAGE_SMIV2) {
				    smiPrintError(thisParserPtr,
						  ERR_SMIV2_BASETYPE_NOT_IMPORTED,
						  "Counter64");
				}
			    }
			}
    break;

  case 250:
/* Line 1787 of yacc.c  */
#line 4747 "parser-smi.y"
    {
			    Import *importPtr;
			    List *listPtr, *nextListPtr;
			    
			    smiPrintError(thisParserPtr,
					  ERR_ILLEGAL_RANGE_FOR_COUNTER,
					  "Counter64");
			    for (listPtr = (yyvsp[(2) - (2)].listPtr); listPtr;
				 listPtr = nextListPtr) {
				nextListPtr = listPtr->nextPtr;
				smiFree((Range *)listPtr->ptr);
				smiFree(listPtr);
			    }
			    
                            if ((thisParserPtr->modulePtr->export.language == SMI_LANGUAGE_SPPI) &&
                                !findImportByName("Counter64", thisParserPtr->modulePtr))
                                smiPrintError(thisParserPtr, ERR_SMI_CONSTRUCT_IN_PIB, "Counter64");
			    (yyval.typePtr) = findTypeByName("Counter64");
			    if (! (yyval.typePtr)) {
				smiPrintError(thisParserPtr, ERR_UNKNOWN_TYPE,
					      "Counter64");
			    }

			    importPtr = findImportByName("Counter64",
							 thisModulePtr);
			    if (importPtr) {
				importPtr->use++;
			    } else {
				if (thisModulePtr->export.language ==
				    SMI_LANGUAGE_SMIV2) {
				    smiPrintError(thisParserPtr,
						  ERR_SMIV2_BASETYPE_NOT_IMPORTED,
						  "Counter64");
				}
			    }
			}
    break;

  case 251:
/* Line 1787 of yacc.c  */
#line 4784 "parser-smi.y"
    {
			    Import *importPtr;

			    (yyval.typePtr) = findTypeByModulenameAndName(
				thisParserPtr->modulePtr->export.name, "Integer64");
			    if (! (yyval.typePtr)) {
				importPtr = findImportByName("Integer64",
							     thisModulePtr);
				if (!importPtr) {
				    (yyval.typePtr) = findTypeByName("Integer64");
				    if ((thisParserPtr->modulePtr->export.language != SMI_LANGUAGE_SPPI)) {
					smiPrintError(thisParserPtr, ERR_SPPI_CONSTRUCT_IN_MIB, "Integer64");
				    } else {
					smiPrintError(thisParserPtr,
						      ERR_SPPI_BASETYPE_NOT_IMPORTED,
						      "Integer64");
				    }
				} else {
				    importPtr->use++;
				    (yyval.typePtr) = findTypeByModulenameAndName(
					importPtr->export.module,
					importPtr->export.name);
				}
			    }
			}
    break;

  case 252:
/* Line 1787 of yacc.c  */
#line 4810 "parser-smi.y"
    {
			    Type *parentPtr;
			    Import *importPtr;
			    
			    parentPtr = findTypeByModulenameAndName(
				thisParserPtr->modulePtr->export.name, "Integer64");
			    if (! parentPtr) {
				importPtr = findImportByName("Integer64",
							     thisModulePtr);
				if (!importPtr) {
				    parentPtr = findTypeByName("Integer64");
				    if ((thisParserPtr->modulePtr->export.language != SMI_LANGUAGE_SPPI)) {
					smiPrintError(thisParserPtr, ERR_SPPI_CONSTRUCT_IN_MIB, "Integer64");
				    } else {
					smiPrintError(thisParserPtr,
						      ERR_SPPI_BASETYPE_NOT_IMPORTED,
						      "Integer64");
				    }
				} else {
				    importPtr->use++;
				    parentPtr = findTypeByModulenameAndName(
					importPtr->export.module,
					importPtr->export.name);
				}
			    }
			    if (! parentPtr) {
				smiPrintError(thisParserPtr, ERR_UNKNOWN_TYPE,
					      "Integer64");
				(yyval.typePtr) = NULL;
			    } else {
				(yyval.typePtr) = duplicateType(parentPtr, 0,
						   thisParserPtr);
				setTypeList((yyval.typePtr), (yyvsp[(2) - (2)].listPtr));
				smiCheckTypeRanges(thisParserPtr, (yyval.typePtr));
			    }
			}
    break;

  case 253:
/* Line 1787 of yacc.c  */
#line 4847 "parser-smi.y"
    {
			    Import *importPtr;

			    (yyval.typePtr) = findTypeByModulenameAndName(
				thisParserPtr->modulePtr->export.name, "Unsigned64");
			    if (! (yyval.typePtr)) {
				importPtr = findImportByName("Unsigned64",
							     thisModulePtr);
				if (!importPtr) {
				    (yyval.typePtr) = findTypeByName("Unsigned64");
				    if ((thisParserPtr->modulePtr->export.language != SMI_LANGUAGE_SPPI)) {
					smiPrintError(thisParserPtr, ERR_SPPI_CONSTRUCT_IN_MIB, "Unsigned64");
				    } else {
					smiPrintError(thisParserPtr,
						      ERR_SPPI_BASETYPE_NOT_IMPORTED,
						      "Unsigned64");
				    }
				} else {
				    importPtr->use++;
				    (yyval.typePtr) = findTypeByModulenameAndName(
					importPtr->export.module,
					importPtr->export.name);
				}
			    }
			}
    break;

  case 254:
/* Line 1787 of yacc.c  */
#line 4873 "parser-smi.y"
    {
			    Type *parentPtr;
			    Import *importPtr;
			    
			    parentPtr = findTypeByModulenameAndName(
				thisParserPtr->modulePtr->export.name, "Unsigned64");
			    if (! parentPtr) {
				importPtr = findImportByName("Unsigned64",
							     thisModulePtr);
				if (!importPtr) {
				    parentPtr = findTypeByName("Unsigned64");
				    if ((thisParserPtr->modulePtr->export.language != SMI_LANGUAGE_SPPI)) {
					smiPrintError(thisParserPtr, ERR_SPPI_CONSTRUCT_IN_MIB, "Unsigned64");
				    } else {
					smiPrintError(thisParserPtr,
						      ERR_SPPI_BASETYPE_NOT_IMPORTED,
						      "Unsigned64");
				    }
				} else {
				    importPtr->use++;
				    parentPtr = findTypeByModulenameAndName(
					importPtr->export.module,
					importPtr->export.name);
				}
			    }
			    if (! parentPtr) {
				smiPrintError(thisParserPtr, ERR_UNKNOWN_TYPE,
					      "Unsigned64");
				(yyval.typePtr) = NULL;
			    } else {
				(yyval.typePtr) = duplicateType(parentPtr, 0,
						   thisParserPtr);
				setTypeList((yyval.typePtr), (yyvsp[(2) - (2)].listPtr));
				smiCheckTypeRanges(thisParserPtr, (yyval.typePtr));
			    }
			}
    break;

  case 255:
/* Line 1787 of yacc.c  */
#line 4916 "parser-smi.y"
    {
			    Import *importPtr;
			    
			    (yyval.typePtr) = findTypeByName("IpAddress");
			    if (! (yyval.typePtr)) {
				smiPrintError(thisParserPtr, ERR_UNKNOWN_TYPE,
					      "IpAddress");
			    }

			    importPtr = findImportByName("IpAddress",
							 thisModulePtr);
			    if (importPtr) {
				importPtr->use++;
			    } else {
				if (thisModulePtr->export.language ==
				    SMI_LANGUAGE_SMIV2) {
				    smiPrintError(thisParserPtr,
						  ERR_SMIV2_BASETYPE_NOT_IMPORTED,
						  "IpAddress");
				} else if (thisModulePtr->export.language ==
					   SMI_LANGUAGE_SPPI) {
				    smiPrintError(thisParserPtr,
						  ERR_SPPI_BASETYPE_NOT_IMPORTED,
						  "IpAddress");
				}
			    }
			}
    break;

  case 256:
/* Line 1787 of yacc.c  */
#line 4944 "parser-smi.y"
    {
			    Import *importPtr;
			    
                            if ((thisParserPtr->modulePtr->export.language == SMI_LANGUAGE_SPPI) &&
                                !findImportByName("Counter32", thisParserPtr->modulePtr))
                                smiPrintError(thisParserPtr, ERR_SMI_CONSTRUCT_IN_PIB, "Counter32");
			    (yyval.typePtr) = findTypeByName("Counter32");
			    if (! (yyval.typePtr)) {
				smiPrintError(thisParserPtr, ERR_UNKNOWN_TYPE,
					      "Counter32");
			    }

			    importPtr = findImportByName("Counter32",
							 thisModulePtr);
			    if (importPtr) {
				importPtr->use++;
			    } else {
				if (thisModulePtr->export.language ==
				    SMI_LANGUAGE_SMIV2) {
				    smiPrintError(thisParserPtr,
						  ERR_SMIV2_BASETYPE_NOT_IMPORTED,
						  "Counter32");
				}
			    }
			}
    break;

  case 257:
/* Line 1787 of yacc.c  */
#line 4970 "parser-smi.y"
    {
			    Import *importPtr;
			    
                            if ((thisParserPtr->modulePtr->export.language == SMI_LANGUAGE_SPPI) &&
                                !findImportByName("Gauge32", thisParserPtr->modulePtr))
                                smiPrintError(thisParserPtr, ERR_SMI_CONSTRUCT_IN_PIB, "Gauge32");
			    (yyval.typePtr) = findTypeByName("Gauge32");
			    if (! (yyval.typePtr)) {
				smiPrintError(thisParserPtr, ERR_UNKNOWN_TYPE,
					      "Gauge32");
			    }

			    importPtr = findImportByName("Gauge32",
							 thisModulePtr);
			    if (importPtr) {
				importPtr->use++;
			    } else {
				if (thisModulePtr->export.language ==
				    SMI_LANGUAGE_SMIV2) {
				    smiPrintError(thisParserPtr,
						  ERR_SMIV2_BASETYPE_NOT_IMPORTED,
						  "Gauge32");
				}
			    }
			}
    break;

  case 258:
/* Line 1787 of yacc.c  */
#line 4996 "parser-smi.y"
    {
			    Import *importPtr;
			    
			    (yyval.typePtr) = smiHandle->typeUnsigned32Ptr;

			    importPtr = findImportByName("Unsigned32",
							 thisModulePtr);
			    if (importPtr) {
				importPtr->use++;
			    } else {
				if (thisModulePtr->export.language ==
				    SMI_LANGUAGE_SMIV2) {
				    smiPrintError(thisParserPtr,
						  ERR_SMIV2_BASETYPE_NOT_IMPORTED,
						  "Unsigned32");
				} else if (thisModulePtr->export.language ==
					   SMI_LANGUAGE_SPPI) {
				    smiPrintError(thisParserPtr,
						  ERR_SPPI_BASETYPE_NOT_IMPORTED,
						  "Unsigned32");
				}
			    }
			}
    break;

  case 259:
/* Line 1787 of yacc.c  */
#line 5020 "parser-smi.y"
    {
			    Import *importPtr;
			    
			    (yyval.typePtr) = findTypeByName("TimeTicks");
			    if (! (yyval.typePtr)) {
				smiPrintError(thisParserPtr, ERR_UNKNOWN_TYPE,
					      "TimeTicks");
			    }

			    importPtr = findImportByName("TimeTicks",
							 thisModulePtr);
			    if (importPtr) {
				importPtr->use++;
			    } else {
				if (thisModulePtr->export.language ==
				    SMI_LANGUAGE_SMIV2) {
				    smiPrintError(thisParserPtr,
						  ERR_SMIV2_BASETYPE_NOT_IMPORTED,
						  "TimeTicks");
				} else if (thisModulePtr->export.language ==
					   SMI_LANGUAGE_SPPI) {
				    smiPrintError(thisParserPtr,
						  ERR_SPPI_BASETYPE_NOT_IMPORTED,
						  "TimeTicks");
				}
			    }
			}
    break;

  case 260:
/* Line 1787 of yacc.c  */
#line 5048 "parser-smi.y"
    {
			    Import *importPtr;
			    
			    (yyval.typePtr) = findTypeByName("Opaque");
			    if (! (yyval.typePtr)) {
				smiPrintError(thisParserPtr, ERR_UNKNOWN_TYPE,
					      "Opaque");
			    } else {
				if (thisModulePtr->export.language ==
				    SMI_LANGUAGE_SMIV2) {
				    smiPrintError(thisParserPtr,
						  ERR_SMIV2_OPAQUE_OBSOLETE,
						  "Opaque");
				} else if (thisModulePtr->export.language ==
					   SMI_LANGUAGE_SPPI) {
				    smiPrintError(thisParserPtr,
						  ERR_SPPI_OPAQUE_OBSOLETE,
						  "Opaque");
				}
			    }

			    importPtr = findImportByName("Opaque",
							 thisModulePtr);
			    if (importPtr) {
				importPtr->use++;
			    } else {
				if (thisModulePtr->export.language ==
				    SMI_LANGUAGE_SMIV2) {
				    smiPrintError(thisParserPtr,
						  ERR_SMIV2_BASETYPE_NOT_IMPORTED,
						  "Opaque");
				} else if (thisModulePtr->export.language ==
					   SMI_LANGUAGE_SPPI) {
				    smiPrintError(thisParserPtr,
						  ERR_SPPI_BASETYPE_NOT_IMPORTED,
						  "Opaque");
				}
			    }
			}
    break;

  case 261:
/* Line 1787 of yacc.c  */
#line 5088 "parser-smi.y"
    {
			    Import *importPtr;

                            if ((thisParserPtr->modulePtr->export.language == SMI_LANGUAGE_SPPI) &&
                                !findImportByName("Counter64", thisModulePtr))
                                smiPrintError(thisParserPtr, ERR_SMI_CONSTRUCT_IN_PIB, "Counter64");
			    (yyval.typePtr) = findTypeByName("Counter64");
			    if (! (yyval.typePtr)) {
				smiPrintError(thisParserPtr, ERR_UNKNOWN_TYPE,
					      "Counter64");
			    }

			    importPtr = findImportByName("Counter64",
							 thisModulePtr);
			    if (importPtr) {
				importPtr->use++;
			    } else {
				if (thisModulePtr->export.language ==
				    SMI_LANGUAGE_SMIV2) {
				    smiPrintError(thisParserPtr,
						  ERR_SMIV2_BASETYPE_NOT_IMPORTED,
						  "Counter64");
				}
			    }
			}
    break;

  case 262:
/* Line 1787 of yacc.c  */
#line 5114 "parser-smi.y"
    {
			    Import *importPtr;

                            if (thisParserPtr->modulePtr->export.language != SMI_LANGUAGE_SPPI)
                                smiPrintError(thisParserPtr, ERR_SPPI_CONSTRUCT_IN_MIB, "Integer64");
			    (yyval.typePtr) = findTypeByName("Integer64");
			    if (! (yyval.typePtr)) {
				smiPrintError(thisParserPtr, ERR_UNKNOWN_TYPE,
					      "Integer64");
			    }

			    importPtr = findImportByName("Integer64",
							 thisModulePtr);
			    if (importPtr) {
				importPtr->use++;
			    } else {
				if (thisModulePtr->export.language ==
					   SMI_LANGUAGE_SPPI) {
				    smiPrintError(thisParserPtr,
						  ERR_SPPI_BASETYPE_NOT_IMPORTED,
						  "Integer64");
				}
			    }
			}
    break;

  case 263:
/* Line 1787 of yacc.c  */
#line 5139 "parser-smi.y"
    {
			    Import *importPtr;

			    importPtr = findImportByName("Unsigned64",
							 thisModulePtr);
                            if ((thisParserPtr->modulePtr->export.language != SMI_LANGUAGE_SPPI) && (!importPtr))
                                smiPrintError(thisParserPtr, ERR_SPPI_CONSTRUCT_IN_MIB, "Unsigned64");
			    (yyval.typePtr) = findTypeByName("Unsigned64");
			    if (! (yyval.typePtr)) {
				smiPrintError(thisParserPtr, ERR_UNKNOWN_TYPE,
					      "Unsigned64");
			    }

			    if (importPtr) {
				importPtr->use++;
			    } else {
				if (thisModulePtr->export.language ==
					   SMI_LANGUAGE_SPPI) {
				    smiPrintError(thisParserPtr,
						  ERR_SPPI_BASETYPE_NOT_IMPORTED,
						  "Unsigned64");
				}
			    }
			}
    break;

  case 264:
/* Line 1787 of yacc.c  */
#line 5166 "parser-smi.y"
    {
			    List *listPtr, *nextListPtr;

			    if (thisModulePtr->export.language == SMI_LANGUAGE_SMIV2)
				smiPrintError(thisParserPtr,
					      ERR_UNEXPECTED_TYPE_RESTRICTION);

			    for (listPtr = (yyvsp[(1) - (1)].listPtr); listPtr;
				 listPtr = nextListPtr) {
				nextListPtr = listPtr->nextPtr;
				smiFree((Range *)(listPtr->ptr));
				smiFree(listPtr);
			    }

			    (yyval.listPtr) = NULL;
			}
    break;

  case 265:
/* Line 1787 of yacc.c  */
#line 5183 "parser-smi.y"
    {
			    List *listPtr, *nextListPtr;

			    if (thisModulePtr->export.language == SMI_LANGUAGE_SMIV2)
				smiPrintError(thisParserPtr,
					      ERR_UNEXPECTED_TYPE_RESTRICTION);

			    for (listPtr = (yyvsp[(1) - (1)].listPtr); listPtr;
				 listPtr = nextListPtr) {
				nextListPtr = listPtr->nextPtr;
				smiFree((Range *)(listPtr->ptr));
				smiFree(listPtr);
			    }

			    (yyval.listPtr) = NULL;
			}
    break;

  case 266:
/* Line 1787 of yacc.c  */
#line 5200 "parser-smi.y"
    {
			    List *listPtr, *nextListPtr;

			    if (thisModulePtr->export.language == SMI_LANGUAGE_SMIV2)
				smiPrintError(thisParserPtr,
					      ERR_UNEXPECTED_TYPE_RESTRICTION);

			    for (listPtr = (yyvsp[(1) - (1)].listPtr); listPtr;
				 listPtr = nextListPtr) {
				nextListPtr = listPtr->nextPtr;
				smiFree(((NamedNumber *)(listPtr->ptr))->export.name);
				smiFree((NamedNumber *)(listPtr->ptr));
				smiFree(listPtr);
			    }

			    (yyval.listPtr) = NULL;
			}
    break;

  case 267:
/* Line 1787 of yacc.c  */
#line 5218 "parser-smi.y"
    {
			    (yyval.listPtr) = NULL;
			}
    break;

  case 268:
/* Line 1787 of yacc.c  */
#line 5232 "parser-smi.y"
    { (yyval.listPtr) = (yyvsp[(2) - (3)].listPtr); }
    break;

  case 269:
/* Line 1787 of yacc.c  */
#line 5242 "parser-smi.y"
    {
			    (yyval.listPtr) = (yyvsp[(4) - (6)].listPtr);
			}
    break;

  case 270:
/* Line 1787 of yacc.c  */
#line 5248 "parser-smi.y"
    {
			    (yyval.listPtr) = smiMalloc(sizeof(List));
			    (yyval.listPtr)->ptr = (yyvsp[(1) - (1)].rangePtr);
			    (yyval.listPtr)->nextPtr = NULL;
			}
    break;

  case 271:
/* Line 1787 of yacc.c  */
#line 5254 "parser-smi.y"
    {
			    List *p, *pp;
			    
			    p = smiMalloc(sizeof(List));
			    p->ptr = (void *)(yyvsp[(3) - (3)].rangePtr);
			    p->nextPtr = NULL;
			    for (pp = (yyvsp[(1) - (3)].listPtr); pp->nextPtr; pp = pp->nextPtr);
			    pp->nextPtr = p;
			    
			    (yyval.listPtr) = (yyvsp[(1) - (3)].listPtr);
			}
    break;

  case 272:
/* Line 1787 of yacc.c  */
#line 5268 "parser-smi.y"
    {
			    (yyval.rangePtr) = smiMalloc(sizeof(Range));
			    (yyval.rangePtr)->export.minValue = *(yyvsp[(1) - (1)].valuePtr);
			    (yyval.rangePtr)->export.maxValue = *(yyvsp[(1) - (1)].valuePtr);
			    smiFree((yyvsp[(1) - (1)].valuePtr));
			}
    break;

  case 273:
/* Line 1787 of yacc.c  */
#line 5275 "parser-smi.y"
    {
			    (yyval.rangePtr) = smiMalloc(sizeof(Range));
			    (yyval.rangePtr)->export.minValue = *(yyvsp[(1) - (3)].valuePtr);
			    (yyval.rangePtr)->export.maxValue = *(yyvsp[(3) - (3)].valuePtr);
			    smiFree((yyvsp[(1) - (3)].valuePtr));
			    smiFree((yyvsp[(3) - (3)].valuePtr));
			}
    break;

  case 274:
/* Line 1787 of yacc.c  */
#line 5285 "parser-smi.y"
    {
			    (yyval.valuePtr) = smiMalloc(sizeof(SmiValue));
			    (yyval.valuePtr)->basetype = SMI_BASETYPE_INTEGER32;
			    (yyval.valuePtr)->value.integer32 = (yyvsp[(1) - (1)].integer32);
			}
    break;

  case 275:
/* Line 1787 of yacc.c  */
#line 5291 "parser-smi.y"
    {
			    (yyval.valuePtr) = smiMalloc(sizeof(SmiValue));
			    (yyval.valuePtr)->basetype = SMI_BASETYPE_UNSIGNED32;
			    (yyval.valuePtr)->value.unsigned32 = (yyvsp[(1) - (1)].unsigned32);
			}
    break;

  case 276:
/* Line 1787 of yacc.c  */
#line 5297 "parser-smi.y"
    {
			    (yyval.valuePtr) = smiMalloc(sizeof(SmiValue));
			    (yyval.valuePtr)->basetype = SMI_BASETYPE_INTEGER64;
			    (yyval.valuePtr)->value.integer64 = (yyvsp[(1) - (1)].integer64);
			}
    break;

  case 277:
/* Line 1787 of yacc.c  */
#line 5303 "parser-smi.y"
    {
			    (yyval.valuePtr) = smiMalloc(sizeof(SmiValue));
			    (yyval.valuePtr)->basetype = SMI_BASETYPE_UNSIGNED64;
			    (yyval.valuePtr)->value.unsigned64 = (yyvsp[(1) - (1)].unsigned64);
			}
    break;

  case 278:
/* Line 1787 of yacc.c  */
#line 5309 "parser-smi.y"
    {
			    char s[3];
			    int i, len;
			    
			    (yyval.valuePtr) = smiMalloc(sizeof(SmiValue));
			    if (defaultBasetype == SMI_BASETYPE_OCTETSTRING) {
				(yyval.valuePtr)->basetype = SMI_BASETYPE_OCTETSTRING;
				len = strlen((yyvsp[(1) - (1)].text));
				(yyval.valuePtr)->value.ptr = smiMalloc((len+1)/2+1);
				for (i = 0; i < len; i += 2) {
				    strncpy(s, &(yyvsp[(1) - (1)].text)[i], 2);
				    if (!s[1]) s[1] = '0';
				    s[2] = 0;
				    (yyval.valuePtr)->value.ptr[i/2] =
					(unsigned char)strtol(s, 0, 16);
				}
				(yyval.valuePtr)->len = (len+1)/2;
			    } else {
				(yyval.valuePtr)->basetype = SMI_BASETYPE_UNSIGNED32;
				(yyval.valuePtr)->value.unsigned32 = strtoul((yyvsp[(1) - (1)].text), NULL, 16);
			    }
			}
    break;

  case 279:
/* Line 1787 of yacc.c  */
#line 5332 "parser-smi.y"
    {
			    char s[9];
			    int i, len, j;
			    
			    (yyval.valuePtr) = smiMalloc(sizeof(SmiValue));
			    if (defaultBasetype == SMI_BASETYPE_OCTETSTRING) {
				(yyval.valuePtr)->basetype = SMI_BASETYPE_OCTETSTRING;
				len = strlen((yyvsp[(1) - (1)].text));
				(yyval.valuePtr)->value.ptr = smiMalloc((len+7)/8+1);
				for (i = 0; i < len; i += 8) {
				    strncpy(s, &(yyvsp[(1) - (1)].text)[i], 8);
				    for (j = 1; j < 8; j++) {
					if (!s[j]) s[j] = '0';
				    }
				    s[8] = 0;
				    (yyval.valuePtr)->value.ptr[i/8] =
					(unsigned char)strtol(s, 0, 2);
				}
				(yyval.valuePtr)->len = (len+7)/8;
			    } else {
				(yyval.valuePtr)->basetype = SMI_BASETYPE_UNSIGNED32;
				(yyval.valuePtr)->value.unsigned32 = strtoul((yyvsp[(1) - (1)].text), NULL, 2);
			    }
			}
    break;

  case 280:
/* Line 1787 of yacc.c  */
#line 5359 "parser-smi.y"
    {
			    (yyval.listPtr) = (yyvsp[(2) - (3)].listPtr);
			}
    break;

  case 281:
/* Line 1787 of yacc.c  */
#line 5365 "parser-smi.y"
    {
			    (yyval.listPtr) = smiMalloc(sizeof(List));
			    (yyval.listPtr)->ptr = (yyvsp[(1) - (1)].namedNumberPtr);
			    (yyval.listPtr)->nextPtr = NULL;
			}
    break;

  case 282:
/* Line 1787 of yacc.c  */
#line 5371 "parser-smi.y"
    {
			    List *p, *pp;
			    
			    p = smiMalloc(sizeof(List));
			    p->ptr = (void *)(yyvsp[(3) - (3)].namedNumberPtr);
			    p->nextPtr = NULL;
			    for (pp = (yyvsp[(1) - (3)].listPtr); pp->nextPtr; pp = pp->nextPtr);
			    pp->nextPtr = p;
			    (yyval.listPtr) = (yyvsp[(1) - (3)].listPtr);
			}
    break;

  case 283:
/* Line 1787 of yacc.c  */
#line 5384 "parser-smi.y"
    {
			    checkNameLen(thisParserPtr, (yyvsp[(1) - (1)].id),
					 ERR_ENUMNAME_32, ERR_ENUMNAME_64);
			    if (thisModulePtr->export.language == SMI_LANGUAGE_SMIV2)
			    {
				if (strchr((yyvsp[(1) - (1)].id), '-')) {
				    smiPrintError(thisParserPtr,
					  ERR_NAMEDNUMBER_INCLUDES_HYPHEN,
						  (yyvsp[(1) - (1)].id));
				}
			    }
			}
    break;

  case 284:
/* Line 1787 of yacc.c  */
#line 5397 "parser-smi.y"
    {
			    (yyval.namedNumberPtr) = smiMalloc(sizeof(NamedNumber));
			    (yyval.namedNumberPtr)->export.name = (yyvsp[(1) - (5)].id);
			    (yyval.namedNumberPtr)->export.value = *(yyvsp[(4) - (5)].valuePtr);
			    smiFree((yyvsp[(4) - (5)].valuePtr));
			}
    break;

  case 285:
/* Line 1787 of yacc.c  */
#line 5406 "parser-smi.y"
    {
			    if ((yyvsp[(1) - (1)].unsigned32) > SMI_BASETYPE_INTEGER32_MAX) {
				smiPrintError(thisParserPtr,
					      ERR_INTEGER32_TOO_LARGE, (yyvsp[(1) - (1)].unsigned32));
			    }
			    if ((thisModulePtr->export.language == SMI_LANGUAGE_SMIV1) &&
				((yyvsp[(1) - (1)].unsigned32) == 0)) {
				smiPrintError(thisParserPtr,
					      ERR_ENUM_ZERO);
			    }
			    (yyval.valuePtr) = smiMalloc(sizeof(SmiValue));
			    (yyval.valuePtr)->basetype = SMI_BASETYPE_INTEGER32;
			    (yyval.valuePtr)->value.integer32 = (yyvsp[(1) - (1)].unsigned32);
			}
    break;

  case 286:
/* Line 1787 of yacc.c  */
#line 5421 "parser-smi.y"
    {
			    (yyval.valuePtr) = smiMalloc(sizeof(SmiValue));
			    (yyval.valuePtr)->basetype = SMI_BASETYPE_INTEGER32;
			    (yyval.valuePtr)->value.integer32 = (yyvsp[(1) - (1)].integer32);
			    /* TODO: non-negative is suggested */
			}
    break;

  case 287:
/* Line 1787 of yacc.c  */
#line 5430 "parser-smi.y"
    {
			    if (thisModulePtr->export.language == SMI_LANGUAGE_SMIV2)
			    {
			        if (!strcmp((yyvsp[(1) - (1)].id), "current")) {
				    (yyval.status) = SMI_STATUS_CURRENT;
			        } else if (!strcmp((yyvsp[(1) - (1)].id), "deprecated")) {
				    (yyval.status) = SMI_STATUS_DEPRECATED;
			        } else if (!strcmp((yyvsp[(1) - (1)].id), "obsolete")) {
				    (yyval.status) = SMI_STATUS_OBSOLETE;
			        } else {
				    smiPrintError(thisParserPtr,
					          ERR_INVALID_SMIV2_STATUS,
					          (yyvsp[(1) - (1)].id));
				    if (!strcmp((yyvsp[(1) - (1)].id), "mandatory")
				        || !strcmp((yyvsp[(1) - (1)].id), "optional")) {
				        /* best guess */
				        (yyval.status) = SMI_STATUS_CURRENT;
				    } else {
				        (yyval.status) = SMI_STATUS_UNKNOWN;
				    }
			        }
			    } else if (thisModulePtr->export.language != SMI_LANGUAGE_SPPI) {
			        if (!strcmp((yyvsp[(1) - (1)].id), "mandatory")) {
				    (yyval.status) = SMI_STATUS_MANDATORY;
			        } else if (!strcmp((yyvsp[(1) - (1)].id), "optional")) {
				    (yyval.status) = SMI_STATUS_OPTIONAL;
			        } else if (!strcmp((yyvsp[(1) - (1)].id), "obsolete")) {
				    (yyval.status) = SMI_STATUS_OBSOLETE;
			        } else if (!strcmp((yyvsp[(1) - (1)].id), "deprecated")) {
				    (yyval.status) = SMI_STATUS_OBSOLETE;
			        } else {
				    smiPrintError(thisParserPtr,
					          ERR_INVALID_SMIV1_STATUS,
					          (yyvsp[(1) - (1)].id));
				    if (!strcmp((yyvsp[(1) - (1)].id), "current")) {
				        /* best guess */
				        (yyval.status) = SMI_STATUS_MANDATORY; 
				    } else {
				        (yyval.status) = SMI_STATUS_UNKNOWN;
				    }
			        }
			    } else { /* it is SPPI */
			        if (!strcmp((yyvsp[(1) - (1)].id), "current")) {
				    (yyval.status) = SMI_STATUS_CURRENT;
			        } else if (!strcmp((yyvsp[(1) - (1)].id), "obsolete")) {
				    (yyval.status) = SMI_STATUS_OBSOLETE;
			        } else if (!strcmp((yyvsp[(1) - (1)].id), "deprecated")) {
				    (yyval.status) = SMI_STATUS_OBSOLETE;
                                } else {
                                    smiPrintError(thisParserPtr,
                                                  ERR_INVALID_SPPI_STATUS, (yyvsp[(1) - (1)].id));
                                    (yyval.status) = SMI_STATUS_UNKNOWN;
                                }
                            }
			    smiFree((yyvsp[(1) - (1)].id));
			}
    break;

  case 288:
/* Line 1787 of yacc.c  */
#line 5489 "parser-smi.y"
    {
			    if (!strcmp((yyvsp[(1) - (1)].id), "current")) {
				(yyval.status) = SMI_STATUS_CURRENT;
			    } else if (!strcmp((yyvsp[(1) - (1)].id), "obsolete")) {
				(yyval.status) = SMI_STATUS_OBSOLETE;
			    } else {
				smiPrintError(thisParserPtr,
					      ERR_INVALID_CAPABILITIES_STATUS,
					      (yyvsp[(1) - (1)].id));
				(yyval.status) = SMI_STATUS_UNKNOWN;
			    }
			    smiFree((yyvsp[(1) - (1)].id));
			}
    break;

  case 289:
/* Line 1787 of yacc.c  */
#line 5505 "parser-smi.y"
    {
			    (yyval.text) = (yyvsp[(2) - (2)].text);
			    
			    if ((yyvsp[(2) - (2)].text) && !strlen((yyvsp[(2) - (2)].text))) {
				smiPrintError(thisParserPtr,
					      ERR_EMPTY_FORMAT);
			    }
			}
    break;

  case 290:
/* Line 1787 of yacc.c  */
#line 5514 "parser-smi.y"
    {
			    (yyval.text) = NULL;
			}
    break;

  case 291:
/* Line 1787 of yacc.c  */
#line 5520 "parser-smi.y"
    {
			    (yyval.text) = (yyvsp[(2) - (2)].text);
			    
			    if ((yyvsp[(2) - (2)].text) && !strlen((yyvsp[(2) - (2)].text))) {
				smiPrintError(thisParserPtr,
					      ERR_EMPTY_UNITS);
			    }
			}
    break;

  case 292:
/* Line 1787 of yacc.c  */
#line 5529 "parser-smi.y"
    {
			    (yyval.text) = NULL;
			}
    break;

  case 293:
/* Line 1787 of yacc.c  */
#line 5535 "parser-smi.y"
    {
			    if (thisModulePtr->export.language == SMI_LANGUAGE_SMIV2)
			    {
				if (!strcmp((yyvsp[(1) - (1)].id), "not-accessible")) {
				    (yyval.access) = SMI_ACCESS_NOT_ACCESSIBLE;
				} else if (!strcmp((yyvsp[(1) - (1)].id),
						   "accessible-for-notify")) {
				    (yyval.access) = SMI_ACCESS_NOTIFY;
				} else if (!strcmp((yyvsp[(1) - (1)].id), "read-only")) {
				    (yyval.access) = SMI_ACCESS_READ_ONLY;
				} else if (!strcmp((yyvsp[(1) - (1)].id), "read-write")) {
				    (yyval.access) = SMI_ACCESS_READ_WRITE;
				} else if (!strcmp((yyvsp[(1) - (1)].id), "read-create")) {
				    (yyval.access) = SMI_ACCESS_READ_WRITE;
				    thisParserPtr->flags |= FLAG_CREATABLE;
				    /* TODO:remember it's really read-create */
				} else if (!strcmp((yyvsp[(1) - (1)].id), "write-only")) {
				    smiPrintError(thisParserPtr,
						  ERR_SMIV2_WRITE_ONLY);
				    (yyval.access) = SMI_ACCESS_READ_WRITE;
				} else {
				    smiPrintError(thisParserPtr,
						  ERR_INVALID_SMIV2_ACCESS,
						  (yyvsp[(1) - (1)].id));
				    (yyval.access) = SMI_ACCESS_UNKNOWN;
				}
			    } else if (thisModulePtr->export.language != SMI_LANGUAGE_SPPI) {
				if (!strcmp((yyvsp[(1) - (1)].id), "not-accessible")) {
				    (yyval.access) = SMI_ACCESS_NOT_ACCESSIBLE;
				} else if (!strcmp((yyvsp[(1) - (1)].id), "read-only")) {
				    (yyval.access) = SMI_ACCESS_READ_ONLY;
				} else if (!strcmp((yyvsp[(1) - (1)].id), "read-write")) {
				    (yyval.access) = SMI_ACCESS_READ_WRITE;
				} else if (!strcmp((yyvsp[(1) - (1)].id), "write-only")) {
				    smiPrintError(thisParserPtr,
						  ERR_SMIV1_WRITE_ONLY);
				    (yyval.access) = SMI_ACCESS_READ_WRITE;
				} else {
				    smiPrintError(thisParserPtr,
						  ERR_INVALID_SMIV1_ACCESS,
						  (yyvsp[(1) - (1)].id));
				    (yyval.access) = SMI_ACCESS_UNKNOWN;
				}
			    } else {
			        if (!strcmp((yyvsp[(1) - (1)].id), "install")) {
				    (yyval.access) = SMI_ACCESS_INSTALL;
			        } else if (!strcmp((yyvsp[(1) - (1)].id), "install-notify")) {
				    (yyval.access) = SMI_ACCESS_INSTALL_NOTIFY;
			        } else if (!strcmp((yyvsp[(1) - (1)].id), "notify")) {
				    (yyval.access) = SMI_ACCESS_NOTIFY;
			        } else if (!strcmp((yyvsp[(1) - (1)].id), "report-only")) {
				    (yyval.access) = SMI_ACCESS_REPORT_ONLY;
			        } else if (!strcmp((yyvsp[(1) - (1)].id), "not-accessible")) {
				    (yyval.access) = SMI_ACCESS_NOT_ACCESSIBLE;
                                } else {
				    smiPrintError(thisParserPtr,
					          ERR_INVALID_SPPI_ACCESS,
					          (yyvsp[(1) - (1)].id));
				    (yyval.access) = SMI_ACCESS_UNKNOWN;
			        }
                            }
			    smiFree((yyvsp[(1) - (1)].id));
			}
    break;

  case 294:
/* Line 1787 of yacc.c  */
#line 5601 "parser-smi.y"
    {
                            if (thisParserPtr->modulePtr->export.language != SMI_LANGUAGE_SPPI)
                                smiPrintError(thisParserPtr, ERR_SPPI_CONSTRUCT_IN_MIB, "PIB-INDEX");
                        }
    break;

  case 295:
/* Line 1787 of yacc.c  */
#line 5606 "parser-smi.y"
    {
                            List *p = smiMalloc(sizeof(List));
                            
                            p->ptr       = (yyvsp[(4) - (5)].objectPtr);
                            p->nextPtr   = NULL;
                            
			    (yyval.index).indexkind = SMI_INDEX_INDEX;
			    (yyval.index).implied   = impliedFlag;
			    (yyval.index).listPtr   = p;
			    (yyval.index).rowPtr    = NULL;
                            indexFlag    = INDEXFLAG_PIBINDEX;
			}
    break;

  case 296:
/* Line 1787 of yacc.c  */
#line 5621 "parser-smi.y"
    {
			    (yyval.index).indexkind    = SMI_INDEX_AUGMENT;
			    (yyval.index).implied      = 0;
			    (yyval.index).listPtr      = NULL;
			    (yyval.index).rowPtr       = (yyvsp[(3) - (4)].objectPtr);
                            indexFlag       = INDEXFLAG_AUGMENTS;
			}
    break;

  case 297:
/* Line 1787 of yacc.c  */
#line 5629 "parser-smi.y"
    {
                            if (thisParserPtr->modulePtr->export.language != SMI_LANGUAGE_SPPI)
                                smiPrintError(thisParserPtr, ERR_SPPI_CONSTRUCT_IN_MIB, "EXTENDS");
                        }
    break;

  case 298:
/* Line 1787 of yacc.c  */
#line 5634 "parser-smi.y"
    {
			    (yyval.index).indexkind    = SMI_INDEX_SPARSE;
			    (yyval.index).implied      = 0;
			    (yyval.index).listPtr      = NULL;
			    (yyval.index).rowPtr       = (yyvsp[(4) - (5)].objectPtr);
                            indexFlag       = INDEXFLAG_EXTENDS;
			}
    break;

  case 299:
/* Line 1787 of yacc.c  */
#line 5642 "parser-smi.y"
    {
			    (yyval.index).indexkind = SMI_INDEX_UNKNOWN;
			}
    break;

  case 300:
/* Line 1787 of yacc.c  */
#line 5648 "parser-smi.y"
    {
                            /* 
                             * To avoid ambiguity caused by merging
                             * the SMI and SPPI parser we use a flag.
                             */
                            if (thisParserPtr->modulePtr->export.language != SMI_LANGUAGE_SPPI) {
                                /*
                                 * Only INDEX or AUGMENTS are allowed for SMI
                                 */
                                if (indexFlag != INDEXFLAG_NONE)
                                    smiPrintError(thisParserPtr, ERR_INDEX_AND_AUGMENTS_USED);
                            } else {
                                /*
                                 * INDEX may only be used if PIB_INDEX was used
                                 */
                                if (indexFlag != INDEXFLAG_PIBINDEX)
                                    smiPrintError(thisParserPtr, ERR_INDEX_WITHOUT_PIB_INDEX);
                            }
                            
			    /*
			     * Use a global variable to fetch and remember
			     * whether we have seen an IMPLIED keyword.
			     */
			    impliedFlag = 0;
			}
    break;

  case 301:
/* Line 1787 of yacc.c  */
#line 5674 "parser-smi.y"
    {
			    (yyval.index).indexkind = SMI_INDEX_INDEX;
			    (yyval.index).implied   = impliedFlag;
			    (yyval.index).listPtr   = (yyvsp[(4) - (5)].listPtr);
			    (yyval.index).rowPtr    = NULL;
                        }
    break;

  case 302:
/* Line 1787 of yacc.c  */
#line 5681 "parser-smi.y"
    {
			    (yyval.index).indexkind = SMI_INDEX_UNKNOWN;
			}
    break;

  case 303:
/* Line 1787 of yacc.c  */
#line 5687 "parser-smi.y"
    {
			    (yyval.listPtr) = smiMalloc(sizeof(List));
			    (yyval.listPtr)->ptr = (yyvsp[(1) - (1)].objectPtr);
			    (yyval.listPtr)->nextPtr = NULL;
			}
    break;

  case 304:
/* Line 1787 of yacc.c  */
#line 5694 "parser-smi.y"
    {
			    List *p, *pp;
			    
			    p = smiMalloc(sizeof(List));
			    p->ptr = (yyvsp[(3) - (3)].objectPtr);
			    p->nextPtr = NULL;
			    for (pp = (yyvsp[(1) - (3)].listPtr); pp->nextPtr; pp = pp->nextPtr);
			    pp->nextPtr = p;
			    (yyval.listPtr) = (yyvsp[(1) - (3)].listPtr);
			}
    break;

  case 305:
/* Line 1787 of yacc.c  */
#line 5707 "parser-smi.y"
    {
			    impliedFlag = 1;
			    (yyval.objectPtr) = (yyvsp[(2) - (2)].objectPtr);
			}
    break;

  case 306:
/* Line 1787 of yacc.c  */
#line 5712 "parser-smi.y"
    {
			    (yyval.objectPtr) = (yyvsp[(1) - (1)].objectPtr);
			}
    break;

  case 307:
/* Line 1787 of yacc.c  */
#line 5722 "parser-smi.y"
    {
			    (yyval.objectPtr) = (yyvsp[(1) - (1)].objectPtr);
			}
    break;

  case 308:
/* Line 1787 of yacc.c  */
#line 5728 "parser-smi.y"
    {
			    (yyval.objectPtr) = (yyvsp[(1) - (1)].objectPtr);
			}
    break;

  case 309:
/* Line 1787 of yacc.c  */
#line 5734 "parser-smi.y"
    {
			    /* must not be present in notification variations */
			    if (variationkind == SMI_NODEKIND_NOTIFICATION) {
				smiPrintError(thisParserPtr,
					      ERR_NOTIFICATION_VARIATION_DEFVAL);
			    }
			    (yyval.valuePtr) = (yyvsp[(3) - (4)].valuePtr);
			    if ((defaultBasetype == SMI_BASETYPE_BITS) &&
				((yyval.valuePtr)->basetype != SMI_BASETYPE_BITS)) {
				smiPrintError(thisParserPtr,
					      ERR_DEFVAL_SYNTAX);
				if ((yyval.valuePtr)->basetype == SMI_BASETYPE_OCTETSTRING) {
				    smiFree((yyval.valuePtr)->value.ptr);
				}
				smiFree((yyval.valuePtr));
				(yyval.valuePtr) = NULL;
			    }
			}
    break;

  case 310:
/* Line 1787 of yacc.c  */
#line 5753 "parser-smi.y"
    { (yyval.valuePtr) = NULL; }
    break;

  case 311:
/* Line 1787 of yacc.c  */
#line 5758 "parser-smi.y"
    { (yyval.valuePtr) = (yyvsp[(1) - (1)].valuePtr); }
    break;

  case 312:
/* Line 1787 of yacc.c  */
#line 5760 "parser-smi.y"
    {
			    (yyval.valuePtr) = smiMalloc(sizeof(SmiValue));
			    (yyval.valuePtr)->basetype = SMI_BASETYPE_BITS;
			    (yyval.valuePtr)->value.ptr = (void *)(yyvsp[(2) - (3)].listPtr);
			}
    break;

  case 313:
/* Line 1787 of yacc.c  */
#line 5768 "parser-smi.y"
    { (yyval.listPtr) = (yyvsp[(1) - (1)].listPtr); }
    break;

  case 314:
/* Line 1787 of yacc.c  */
#line 5770 "parser-smi.y"
    { (yyval.listPtr) = NULL; }
    break;

  case 315:
/* Line 1787 of yacc.c  */
#line 5774 "parser-smi.y"
    {
			    (yyval.listPtr) = smiMalloc(sizeof(List));
			    (yyval.listPtr)->ptr = (yyvsp[(1) - (1)].id);
			    (yyval.listPtr)->nextPtr = NULL;
			}
    break;

  case 316:
/* Line 1787 of yacc.c  */
#line 5780 "parser-smi.y"
    {
			    List *p, *pp;
			    
			    p = smiMalloc(sizeof(List));
			    p->ptr = (yyvsp[(3) - (3)].id);
			    p->nextPtr = NULL;
			    for (pp = (yyvsp[(1) - (3)].listPtr); pp->nextPtr; pp = pp->nextPtr);
			    pp->nextPtr = p;
			    (yyval.listPtr) = (yyvsp[(1) - (3)].listPtr);
			}
    break;

  case 317:
/* Line 1787 of yacc.c  */
#line 5793 "parser-smi.y"
    {
			    (yyval.objectPtr) = (yyvsp[(1) - (1)].objectPtr);
			}
    break;

  case 318:
/* Line 1787 of yacc.c  */
#line 5799 "parser-smi.y"
    {
			    (yyval.objectPtr) = (yyvsp[(1) - (1)].objectPtr);
			}
    break;

  case 319:
/* Line 1787 of yacc.c  */
#line 5805 "parser-smi.y"
    {
			    (yyval.text) = (yyvsp[(2) - (2)].text);

			    if ((yyvsp[(2) - (2)].text) && !strlen((yyvsp[(2) - (2)].text))) {
				smiPrintError(thisParserPtr,
					      ERR_EMPTY_REFERENCE);
			    }
			}
    break;

  case 320:
/* Line 1787 of yacc.c  */
#line 5814 "parser-smi.y"
    { (yyval.text) = NULL; }
    break;

  case 321:
/* Line 1787 of yacc.c  */
#line 5818 "parser-smi.y"
    { (yyval.err) = 0; }
    break;

  case 322:
/* Line 1787 of yacc.c  */
#line 5820 "parser-smi.y"
    { (yyval.err) = 0; }
    break;

  case 323:
/* Line 1787 of yacc.c  */
#line 5824 "parser-smi.y"
    { (yyval.err) = 0; }
    break;

  case 324:
/* Line 1787 of yacc.c  */
#line 5826 "parser-smi.y"
    { (yyval.err) = 0; }
    break;

  case 325:
/* Line 1787 of yacc.c  */
#line 5830 "parser-smi.y"
    {
			    thisParserPtr->firstRevisionLine = thisParserPtr->line;

			    if (thisParserPtr->modulePtr->lastRevisionPtr &&
				((yyvsp[(2) - (2)].date) >= thisParserPtr->modulePtr->lastRevisionPtr->export.date)) {
				smiPrintError(thisParserPtr,
					      ERR_REVISION_NOT_DESCENDING);
			    }

			    if ((yyvsp[(2) - (2)].date) > thisParserPtr->modulePtr->lastUpdated) {
				smiPrintError(thisParserPtr,
					      ERR_REVISION_AFTER_LAST_UPDATE);
			    }
			}
    break;

  case 326:
/* Line 1787 of yacc.c  */
#line 5845 "parser-smi.y"
    {
			    Revision *revisionPtr;

			    checkDescr(thisParserPtr, (yyvsp[(5) - (5)].text));

			    revisionPtr = addRevision((yyvsp[(2) - (5)].date), (yyvsp[(5) - (5)].text), thisParserPtr);
			    if (revisionPtr) {
				setRevisionLine(revisionPtr,
						thisParserPtr->firstRevisionLine,
						thisParserPtr);
			    }
			    (yyval.err) = revisionPtr ? 0 : -1;
			}
    break;

  case 327:
/* Line 1787 of yacc.c  */
#line 5861 "parser-smi.y"
    {
			    (yyval.listPtr) = (yyvsp[(3) - (4)].listPtr);
			}
    break;

  case 328:
/* Line 1787 of yacc.c  */
#line 5865 "parser-smi.y"
    {
			    (yyval.listPtr) = NULL;
			}
    break;

  case 329:
/* Line 1787 of yacc.c  */
#line 5871 "parser-smi.y"
    {
			    (yyval.listPtr) = (yyvsp[(3) - (4)].listPtr);
			}
    break;

  case 330:
/* Line 1787 of yacc.c  */
#line 5877 "parser-smi.y"
    {
			    (yyval.listPtr) = smiMalloc(sizeof(List));
			    (yyval.listPtr)->ptr = (yyvsp[(1) - (1)].objectPtr);
			    (yyval.listPtr)->nextPtr = NULL;
			}
    break;

  case 331:
/* Line 1787 of yacc.c  */
#line 5883 "parser-smi.y"
    {
			    List *p, *pp;
			    
			    p = smiMalloc(sizeof(List));
			    p->ptr = (yyvsp[(3) - (3)].objectPtr);
			    p->nextPtr = NULL;
			    for (pp = (yyvsp[(1) - (3)].listPtr); pp->nextPtr; pp = pp->nextPtr);
			    pp->nextPtr = p;
			    (yyval.listPtr) = (yyvsp[(1) - (3)].listPtr);
			}
    break;

  case 332:
/* Line 1787 of yacc.c  */
#line 5896 "parser-smi.y"
    {
			    (yyval.objectPtr) = (yyvsp[(1) - (1)].objectPtr);
			    if ((thisParserPtr->currentDecl == SMI_DECL_OBJECTGROUP) &&
				(yyval.objectPtr)->modulePtr != thisParserPtr->modulePtr) {
                                smiPrintError(thisParserPtr,
					      ERR_COMPLIANCE_MEMBER_NOT_LOCAL,
					      (yyval.objectPtr)->export.name);
			    }
			}
    break;

  case 333:
/* Line 1787 of yacc.c  */
#line 5908 "parser-smi.y"
    {
			    (yyval.listPtr) = (yyvsp[(3) - (4)].listPtr);
			}
    break;

  case 334:
/* Line 1787 of yacc.c  */
#line 5914 "parser-smi.y"
    {
			    (yyval.listPtr) = smiMalloc(sizeof(List));
			    (yyval.listPtr)->ptr = (yyvsp[(1) - (1)].objectPtr);
			    (yyval.listPtr)->nextPtr = NULL;
			}
    break;

  case 335:
/* Line 1787 of yacc.c  */
#line 5920 "parser-smi.y"
    {
			    List *p, *pp;
			    
			    p = smiMalloc(sizeof(List));
			    p->ptr = (yyvsp[(3) - (3)].objectPtr);
			    p->nextPtr = NULL;
			    for (pp = (yyvsp[(1) - (3)].listPtr); pp->nextPtr; pp = pp->nextPtr);
			    pp->nextPtr = p;
			    (yyval.listPtr) = (yyvsp[(1) - (3)].listPtr);
			}
    break;

  case 336:
/* Line 1787 of yacc.c  */
#line 5933 "parser-smi.y"
    {
			    (yyval.objectPtr) = (yyvsp[(1) - (1)].objectPtr);
			    if ((yyval.objectPtr)->modulePtr != thisParserPtr->modulePtr) {
                                smiPrintError(thisParserPtr,
					      ERR_COMPLIANCE_MEMBER_NOT_LOCAL,
					      (yyval.objectPtr)->export.name);
			    }
			}
    break;

  case 337:
/* Line 1787 of yacc.c  */
#line 5944 "parser-smi.y"
    {
			    int len;
			    (yyval.text) = smiStrdup((yyvsp[(1) - (1)].text));
			    len = strlen((yyval.text));
			    while (len > 0 && (yyval.text)[len-1] == '\n') {
				(yyval.text)[--len] = 0;
			    }
			}
    break;

  case 338:
/* Line 1787 of yacc.c  */
#line 5955 "parser-smi.y"
    {
			    (yyval.date) = checkDate(thisParserPtr, (yyvsp[(1) - (1)].text));
			}
    break;

  case 339:
/* Line 1787 of yacc.c  */
#line 5960 "parser-smi.y"
    {
			    thisParserPtr->parentNodePtr = smiHandle->rootNodePtr;
			}
    break;

  case 340:
/* Line 1787 of yacc.c  */
#line 5964 "parser-smi.y"
    {
			    (yyval.objectPtr) = (yyvsp[(2) - (2)].objectPtr);
			    if ((yyval.objectPtr)) {
				thisParserPtr->parentNodePtr = (yyvsp[(2) - (2)].objectPtr)->nodePtr;
			    } else {
				thisParserPtr->parentNodePtr = NULL;
			    }
			}
    break;

  case 341:
/* Line 1787 of yacc.c  */
#line 5976 "parser-smi.y"
    {
			    (yyval.objectPtr) = (yyvsp[(1) - (1)].objectPtr);
			}
    break;

  case 342:
/* Line 1787 of yacc.c  */
#line 5981 "parser-smi.y"
    {
			    (yyval.objectPtr) = (yyvsp[(2) - (2)].objectPtr);
			}
    break;

  case 343:
/* Line 1787 of yacc.c  */
#line 5989 "parser-smi.y"
    {
			    Object *objectPtr;
			    Import *importPtr;
			    
			    if (thisParserPtr->parentNodePtr != smiHandle->rootNodePtr) {
				smiPrintError(thisParserPtr,
					      ERR_OIDLABEL_NOT_FIRST, (yyvsp[(1) - (1)].id));
			    }
			    objectPtr = findObjectByModuleAndName(
				thisParserPtr->modulePtr, (yyvsp[(1) - (1)].id));
			    if (objectPtr) {
				(yyval.objectPtr) = objectPtr;
				smiFree((yyvsp[(1) - (1)].id));
			    } else {
				importPtr = findImportByName((yyvsp[(1) - (1)].id),
							     thisModulePtr);
				if (!importPtr ||
				    (importPtr->kind == KIND_NOTFOUND)) {
				    /*
				     * If we are in a MODULE-COMPLIANCE
				     * statement with a given MODULE...
				     */
				    if (thisParserPtr->complianceModulePtr) {
					objectPtr =
					    findObjectByModuleAndName(
						thisParserPtr->complianceModulePtr, (yyvsp[(1) - (1)].id));
					if (objectPtr) {
					    importPtr = addImport(
						(yyvsp[(1) - (1)].id),
						thisParserPtr);
					    setImportModulename(importPtr,
								thisParserPtr->complianceModulePtr->export.name);
					    addImportFlags(importPtr,
							   FLAG_INCOMPLIANCE);
					    importPtr->use++;
					} else {
					    objectPtr = addObject((yyvsp[(1) - (1)].id),
								  thisParserPtr->pendingNodePtr, 0,
								  FLAG_INCOMPLETE,
								  thisParserPtr);
					    smiPrintError(thisParserPtr,
							  ERR_IDENTIFIER_NOT_IN_MODULE, (yyvsp[(1) - (1)].id),
							  thisParserPtr->complianceModulePtr->export.name);
					}
				    } else if (thisParserPtr->capabilitiesModulePtr) {
					objectPtr =
					    findObjectByModuleAndName(
						thisParserPtr->capabilitiesModulePtr, (yyvsp[(1) - (1)].id));
					if (objectPtr) {
					    importPtr = addImport(
						(yyvsp[(1) - (1)].id),
						thisParserPtr);
					    setImportModulename(importPtr,
								thisParserPtr->capabilitiesModulePtr->
								export.name);
					    addImportFlags(importPtr,
							   FLAG_INCOMPLIANCE);
					    importPtr->use++;
					} else {
					    objectPtr = addObject((yyvsp[(1) - (1)].id),
								  thisParserPtr->pendingNodePtr, 0,
								  FLAG_INCOMPLETE,
								  thisParserPtr);
					    smiPrintError(thisParserPtr,
							  ERR_IDENTIFIER_NOT_IN_MODULE, (yyvsp[(1) - (1)].id),
							  thisParserPtr->capabilitiesModulePtr->export.name);
					}
				    } else {
					/* 
					 * forward referenced node.
					 * create it,
					 * marked with FLAG_INCOMPLETE.
					 */
					objectPtr = addObject((yyvsp[(1) - (1)].id),
							      thisParserPtr->pendingNodePtr,
							      0,
							      FLAG_INCOMPLETE,
							      thisParserPtr);
				    }
				    (yyval.objectPtr) = objectPtr;
				} else {
				    /*
				     * imported object.
				     */
				    importPtr->use++;
				    (yyval.objectPtr) = findObjectByModulenameAndName(
					importPtr->export.module, (yyvsp[(1) - (1)].id));
				    smiFree((yyvsp[(1) - (1)].id));
				}
			    }
			    if ((yyval.objectPtr))
				thisParserPtr->parentNodePtr = (yyval.objectPtr)->nodePtr;
			}
    break;

  case 344:
/* Line 1787 of yacc.c  */
#line 6083 "parser-smi.y"
    {
			    Object *objectPtr;
			    Import *importPtr;
			    char *md;
			    
			    if (thisParserPtr->parentNodePtr != smiHandle->rootNodePtr) {
				md = smiMalloc(sizeof(char) *
					       (strlen((yyvsp[(1) - (3)].id)) + strlen((yyvsp[(3) - (3)].id)) + 2));
				sprintf(md, "%s.%s", (yyvsp[(1) - (3)].id), (yyvsp[(3) - (3)].id));
				smiPrintError(thisParserPtr,
					      ERR_OIDLABEL_NOT_FIRST, md);
				smiFree(md);
			    } else {
				objectPtr = findObjectByModulenameAndName(
				    (yyvsp[(1) - (3)].id), (yyvsp[(3) - (3)].id));
				if (objectPtr) {
				    (yyval.objectPtr) = objectPtr;
				    smiFree((yyvsp[(1) - (3)].id));
				    smiFree((yyvsp[(3) - (3)].id));
				} else {
				    importPtr = findImportByModulenameAndName(
					(yyvsp[(1) - (3)].id), (yyvsp[(3) - (3)].id), thisModulePtr);
				    if (!importPtr ||
					(importPtr->kind == KIND_NOTFOUND)) {
					/* TODO: check: $1 == thisModule ? */
					/*
					 * If we are in a MODULE-COMPLIANCE
					 * statement with a given MODULE...
					 */
					if (thisParserPtr->complianceModulePtr) {
					    objectPtr =
						findObjectByModuleAndName(
						    thisParserPtr->complianceModulePtr, (yyvsp[(1) - (3)].id));
					    if (objectPtr) {
						importPtr = addImport(
						    (yyvsp[(1) - (3)].id),
						    thisParserPtr);
						setImportModulename(importPtr,
						    thisParserPtr->complianceModulePtr->export.name);
						addImportFlags(importPtr,
							       FLAG_INCOMPLIANCE);
						importPtr->use++;
					    } else {
						objectPtr = addObject((yyvsp[(1) - (3)].id),
						    thisParserPtr->pendingNodePtr, 0,
						    FLAG_INCOMPLETE,
						    thisParserPtr);
						smiPrintError(thisParserPtr,
					      ERR_IDENTIFIER_NOT_IN_MODULE, (yyvsp[(1) - (3)].id),
					     thisParserPtr->complianceModulePtr->export.name);
					    }
					} else if (thisParserPtr->capabilitiesModulePtr) {
					    objectPtr =
						findObjectByModuleAndName(
						    thisParserPtr->capabilitiesModulePtr, (yyvsp[(1) - (3)].id));
					    if (objectPtr) {
						importPtr = addImport(
						    (yyvsp[(1) - (3)].id),
						    thisParserPtr);
						setImportModulename(importPtr,
						        thisParserPtr->capabilitiesModulePtr->
								  export.name);
						addImportFlags(importPtr,
							       FLAG_INCOMPLIANCE);
						importPtr->use++;
					    } else {
						objectPtr = addObject((yyvsp[(1) - (3)].id),
						    thisParserPtr->pendingNodePtr, 0,
						    FLAG_INCOMPLETE,
						    thisParserPtr);
						smiPrintError(thisParserPtr,
					      ERR_IDENTIFIER_NOT_IN_MODULE, (yyvsp[(1) - (3)].id),
					   thisParserPtr->capabilitiesModulePtr->export.name);
					    }
					} else {
					    /* 
					     * forward referenced node.
					     * create it,
					     * marked with FLAG_INCOMPLETE.
					     */
					    objectPtr = addObject((yyvsp[(3) - (3)].id),
							    thisParserPtr->pendingNodePtr,
							      0,
							      FLAG_INCOMPLETE,
							      thisParserPtr);
					    smiFree((yyvsp[(1) - (3)].id));
					}
					(yyval.objectPtr) = objectPtr;
				    } else {
					/*
					 * imported object.
					 */
					importPtr->use++;
					(yyval.objectPtr) = findObjectByModulenameAndName(
					    importPtr->export.module, (yyvsp[(3) - (3)].id));
					smiFree((yyvsp[(1) - (3)].id));
					smiFree((yyvsp[(3) - (3)].id));
				    }
				}
				if ((yyval.objectPtr))
				    thisParserPtr->parentNodePtr = (yyval.objectPtr)->nodePtr;
			    }
			}
    break;

  case 345:
/* Line 1787 of yacc.c  */
#line 6187 "parser-smi.y"
    {
			    Node *nodePtr;
			    Object *objectPtr;

			    nodePtr = findNodeByParentAndSubid(thisParserPtr->parentNodePtr,
							       (yyvsp[(1) - (1)].unsigned32));
			    if (nodePtr && nodePtr->lastObjectPtr &&
	       		(nodePtr->lastObjectPtr->modulePtr == thisModulePtr)) {
				/*
				 * hopefully, the last defined Object for
				 * this Node is the one we expect.
				 */
				(yyval.objectPtr) = nodePtr->lastObjectPtr;
			    } else {
				objectPtr = addObject(NULL,
						      thisParserPtr->parentNodePtr,
						      (yyvsp[(1) - (1)].unsigned32),
						      FLAG_INCOMPLETE,
						      thisParserPtr);
				(yyval.objectPtr) = objectPtr;
			    }
			    thisParserPtr->parentNodePtr = (yyval.objectPtr)->nodePtr;
			}
    break;

  case 346:
/* Line 1787 of yacc.c  */
#line 6211 "parser-smi.y"
    {
			    Object *objectPtr = NULL;
			    Object *oldObjectPtr = NULL;
			    Node *oldNodePtr = NULL;
			    
			    /* TODO: search in local module and
			     *       in imported modules
			     */

			    oldNodePtr = findNodeByParentAndSubid(
				thisParserPtr->parentNodePtr, (yyvsp[(3) - (4)].unsigned32));
			    oldObjectPtr = findObjectByModuleAndName(
                                thisParserPtr->modulePtr, (yyvsp[(1) - (4)].id));

			    if (oldObjectPtr &&
				((oldObjectPtr->nodePtr->subid != (yyvsp[(3) - (4)].unsigned32)) ||
				 (oldObjectPtr->nodePtr->parentPtr != thisParserPtr->parentNodePtr))) {
				smiPrintError(thisParserPtr,
					      ERR_IDENTIFIER_OID_CHANGED,
					      (yyvsp[(1) - (4)].id));
				smiPrintErrorAtLine(thisParserPtr,
						    ERR_PREVIOUS_DEFINITION,
						    oldObjectPtr->line,
						    oldObjectPtr->export.name);
				objectPtr = addObject((yyvsp[(1) - (4)].id),
						      thisParserPtr->parentNodePtr,
						      (yyvsp[(3) - (4)].unsigned32), 0, thisParserPtr);
				setObjectDecl(objectPtr,
					      SMI_DECL_IMPL_OBJECT);
				(yyval.objectPtr) = objectPtr;
				thisParserPtr->parentNodePtr = (yyval.objectPtr)->nodePtr;
			    } else if (oldNodePtr &&
				       oldNodePtr->lastObjectPtr &&
				       oldNodePtr->lastObjectPtr->export.name &&
				       strcmp(oldNodePtr->lastObjectPtr->export.name, (yyvsp[(1) - (4)].id))) {
				smiPrintError(thisParserPtr,
					      ERR_OIDLABEL_CHANGED,
					      (yyvsp[(1) - (4)].id), oldNodePtr->lastObjectPtr->export.name);
				smiPrintErrorAtLine(thisParserPtr,
						    ERR_PREVIOUS_DEFINITION,
						    oldNodePtr->lastObjectPtr->line,
						    oldNodePtr->lastObjectPtr->export.name);
				objectPtr = addObject((yyvsp[(1) - (4)].id),
						      thisParserPtr->parentNodePtr,
						      (yyvsp[(3) - (4)].unsigned32), 0, thisParserPtr);
				setObjectDecl(objectPtr,
					      SMI_DECL_IMPL_OBJECT);
				(yyval.objectPtr) = objectPtr;
				thisParserPtr->parentNodePtr = (yyval.objectPtr)->nodePtr;
			    } else {
				objectPtr = addObject((yyvsp[(1) - (4)].id), thisParserPtr->parentNodePtr,
						      (yyvsp[(3) - (4)].unsigned32), 0,
						      thisParserPtr);
				setObjectDecl(objectPtr,
					      SMI_DECL_IMPL_OBJECT);
				(yyval.objectPtr) = objectPtr;
				thisParserPtr->parentNodePtr = (yyval.objectPtr)->nodePtr;
			    }
			}
    break;

  case 347:
/* Line 1787 of yacc.c  */
#line 6271 "parser-smi.y"
    {
			    Object *objectPtr = NULL;
			    Object *oldObjectPtr = NULL;
			    Node *oldNodePtr = NULL;
			    char *md;

			    md = smiMalloc(sizeof(char) *
					   (strlen((yyvsp[(1) - (6)].id)) + strlen((yyvsp[(3) - (6)].id)) + 2));
			    sprintf(md, "%s.%s", (yyvsp[(1) - (6)].id), (yyvsp[(3) - (6)].id));

			    oldNodePtr = findNodeByParentAndSubid(
				thisParserPtr->parentNodePtr, (yyvsp[(5) - (6)].unsigned32));
			    oldObjectPtr = findObjectByModulenameAndName(
                                (yyvsp[(1) - (6)].id), (yyvsp[(3) - (6)].id));

			    if (oldObjectPtr &&
				((oldObjectPtr->nodePtr->subid != (yyvsp[(5) - (6)].unsigned32)) ||
				 (oldObjectPtr->nodePtr->parentPtr != thisParserPtr->parentNodePtr))) {
				smiPrintError(thisParserPtr,
					      ERR_ILLEGALLY_QUALIFIED, md);
				smiPrintError(thisParserPtr,
					      ERR_IDENTIFIER_OID_CHANGED,
					      (yyvsp[(3) - (6)].id));
				smiPrintErrorAtLine(thisParserPtr,
						    ERR_PREVIOUS_DEFINITION,
						    oldObjectPtr->line,
						    oldObjectPtr->export.name);
				objectPtr = addObject((yyvsp[(3) - (6)].id),
						      thisParserPtr->parentNodePtr,
						      (yyvsp[(5) - (6)].unsigned32), 0, thisParserPtr);
				setObjectDecl(objectPtr,
					      SMI_DECL_IMPL_OBJECT);
				(yyval.objectPtr) = objectPtr;
				thisParserPtr->parentNodePtr = (yyval.objectPtr)->nodePtr;
			    } else if (oldNodePtr &&
				       oldNodePtr->lastObjectPtr &&
				       strcmp(oldNodePtr->lastObjectPtr->export.name, (yyvsp[(3) - (6)].id))) {
				smiPrintError(thisParserPtr,
					      ERR_ILLEGALLY_QUALIFIED, md);
				smiPrintError(thisParserPtr,
					      ERR_OIDLABEL_CHANGED,
					      (yyvsp[(3) - (6)].id), oldNodePtr->lastObjectPtr->export.name);
				smiPrintErrorAtLine(thisParserPtr,
						    ERR_PREVIOUS_DEFINITION,
						    oldNodePtr->lastObjectPtr->line,
						    oldNodePtr->lastObjectPtr->export.name);
				objectPtr = addObject((yyvsp[(3) - (6)].id),
						      thisParserPtr->parentNodePtr,
						      (yyvsp[(5) - (6)].unsigned32), 0, thisParserPtr);
				setObjectDecl(objectPtr,
					      SMI_DECL_IMPL_OBJECT);
				(yyval.objectPtr) = objectPtr;
				thisParserPtr->parentNodePtr = (yyval.objectPtr)->nodePtr;
			    } else {
				smiPrintError(thisParserPtr,
					      ERR_ILLEGALLY_QUALIFIED, md);
				objectPtr = addObject((yyvsp[(3) - (6)].id), thisParserPtr->parentNodePtr,
						      (yyvsp[(5) - (6)].unsigned32), 0,
						      thisParserPtr);
				setObjectDecl(objectPtr,
					      SMI_DECL_IMPL_OBJECT);
				(yyval.objectPtr) = objectPtr;
				thisParserPtr->parentNodePtr = (yyval.objectPtr)->nodePtr;
			    }
			    smiFree(md);
			}
    break;

  case 348:
/* Line 1787 of yacc.c  */
#line 6340 "parser-smi.y"
    { (yyval.text) = NULL; }
    break;

  case 349:
/* Line 1787 of yacc.c  */
#line 6344 "parser-smi.y"
    { (yyval.err) = 0; }
    break;

  case 350:
/* Line 1787 of yacc.c  */
#line 6346 "parser-smi.y"
    { (yyval.err) = 0; }
    break;

  case 351:
/* Line 1787 of yacc.c  */
#line 6350 "parser-smi.y"
    { (yyval.err) = 0; }
    break;

  case 352:
/* Line 1787 of yacc.c  */
#line 6352 "parser-smi.y"
    { (yyval.err) = 0; }
    break;

  case 353:
/* Line 1787 of yacc.c  */
#line 6356 "parser-smi.y"
    {
			    thisParserPtr->firstStatementLine = thisParserPtr->line;
			    thisParserPtr->currentDecl = SMI_DECL_OBJECTGROUP;
			    
			    checkNameLen(thisParserPtr, (yyvsp[(1) - (1)].id),
					 ERR_OIDNAME_32, ERR_OIDNAME_64);
			    smiCheckObjectName(thisParserPtr,
					       thisModulePtr, (yyvsp[(1) - (1)].id));
			}
    break;

  case 354:
/* Line 1787 of yacc.c  */
#line 6366 "parser-smi.y"
    {
			    Import *importPtr;
			    
			    if (thisModulePtr->export.language == SMI_LANGUAGE_UNKNOWN)
				thisModulePtr->export.language = SMI_LANGUAGE_SMIV2;

			    importPtr = findImportByName("OBJECT-GROUP",
							 thisModulePtr);
			    if (importPtr) {
				importPtr->use++;
			    } else {
				smiPrintError(thisParserPtr,
					      ERR_MACRO_NOT_IMPORTED,
					      "OBJECT-GROUP", "SNMPv2-CONF");
			    }
			}
    break;

  case 355:
/* Line 1787 of yacc.c  */
#line 6385 "parser-smi.y"
    {
			    checkDescr(thisParserPtr, (yyvsp[(9) - (9)].text));
			}
    break;

  case 356:
/* Line 1787 of yacc.c  */
#line 6390 "parser-smi.y"
    {
			    Object *objectPtr;
			    
			    objectPtr = (yyvsp[(14) - (15)].objectPtr);

			    smiCheckObjectReuse(thisParserPtr, (yyvsp[(1) - (15)].id), &objectPtr);

			    objectPtr = setObjectName(objectPtr, (yyvsp[(1) - (15)].id), thisParserPtr);
			    setObjectDecl(objectPtr, SMI_DECL_OBJECTGROUP);
			    setObjectLine(objectPtr, thisParserPtr->firstStatementLine,
					  thisParserPtr);
			    addObjectFlags(objectPtr, FLAG_REGISTERED);
			    deleteObjectFlags(objectPtr, FLAG_INCOMPLETE);
			    setObjectStatus(objectPtr, (yyvsp[(7) - (15)].status));
			    setObjectDescription(objectPtr, (yyvsp[(9) - (15)].text), thisParserPtr);
			    if ((yyvsp[(11) - (15)].text)) {
				setObjectReference(objectPtr, (yyvsp[(11) - (15)].text), thisParserPtr);
			    }
			    setObjectAccess(objectPtr,
					    SMI_ACCESS_NOT_ACCESSIBLE);
			    setObjectList(objectPtr, (yyvsp[(5) - (15)].listPtr));
			    (yyval.err) = 0;
			}
    break;

  case 357:
/* Line 1787 of yacc.c  */
#line 6416 "parser-smi.y"
    {
			    thisParserPtr->firstStatementLine = thisParserPtr->line;
			    thisParserPtr->currentDecl = SMI_DECL_NOTIFICATIONGROUP;
			    
			    checkNameLen(thisParserPtr, (yyvsp[(1) - (1)].id),
					 ERR_OIDNAME_32, ERR_OIDNAME_64);
			    smiCheckObjectName(thisParserPtr,
					       thisModulePtr, (yyvsp[(1) - (1)].id));
			}
    break;

  case 358:
/* Line 1787 of yacc.c  */
#line 6426 "parser-smi.y"
    {
			    Import *importPtr;
                            if (thisParserPtr->modulePtr->export.language == SMI_LANGUAGE_SPPI)
                                smiPrintError(thisParserPtr, ERR_SMI_CONSTRUCT_IN_PIB, "NOTIFICATION-GROUP");
			    
			    if (thisModulePtr->export.language == SMI_LANGUAGE_UNKNOWN)
				thisModulePtr->export.language = SMI_LANGUAGE_SMIV2;

			    importPtr = findImportByName("NOTIFICATION-GROUP",
							 thisModulePtr);
			    if (importPtr) {
				importPtr->use++;
			    } else {
				smiPrintError(thisParserPtr,
					      ERR_MACRO_NOT_IMPORTED,
					      "NOTIFICATION-GROUP",
					      "SNMPv2-CONF");
			    }
			}
    break;

  case 359:
/* Line 1787 of yacc.c  */
#line 6448 "parser-smi.y"
    {
			    checkDescr(thisParserPtr, (yyvsp[(9) - (9)].text));
			}
    break;

  case 360:
/* Line 1787 of yacc.c  */
#line 6453 "parser-smi.y"
    {
			    Object *objectPtr;
			    
			    objectPtr = (yyvsp[(14) - (15)].objectPtr);

			    smiCheckObjectReuse(thisParserPtr, (yyvsp[(1) - (15)].id), &objectPtr);

			    objectPtr = setObjectName(objectPtr, (yyvsp[(1) - (15)].id), thisParserPtr);
			    setObjectDecl(objectPtr,
					  SMI_DECL_NOTIFICATIONGROUP);
			    setObjectLine(objectPtr, thisParserPtr->firstStatementLine,
					  thisParserPtr);
			    addObjectFlags(objectPtr, FLAG_REGISTERED);
			    deleteObjectFlags(objectPtr, FLAG_INCOMPLETE);
			    setObjectStatus(objectPtr, (yyvsp[(7) - (15)].status));
			    setObjectDescription(objectPtr, (yyvsp[(9) - (15)].text), thisParserPtr);
			    if ((yyvsp[(11) - (15)].text)) {
				setObjectReference(objectPtr, (yyvsp[(11) - (15)].text), thisParserPtr);
			    }
			    setObjectAccess(objectPtr,
					    SMI_ACCESS_NOT_ACCESSIBLE);
			    setObjectList(objectPtr, (yyvsp[(5) - (15)].listPtr));
			    (yyval.err) = 0;
			}
    break;

  case 361:
/* Line 1787 of yacc.c  */
#line 6480 "parser-smi.y"
    {
			    thisParserPtr->firstStatementLine = thisParserPtr->line;
			    thisParserPtr->currentDecl = SMI_DECL_MODULECOMPLIANCE;
			    
			    checkNameLen(thisParserPtr, (yyvsp[(1) - (1)].id),
					 ERR_OIDNAME_32, ERR_OIDNAME_64);
			    smiCheckObjectName(thisParserPtr,
					       thisModulePtr, (yyvsp[(1) - (1)].id));
			}
    break;

  case 362:
/* Line 1787 of yacc.c  */
#line 6490 "parser-smi.y"
    {
			    Import *importPtr;
			    
			    if (thisModulePtr->export.language == SMI_LANGUAGE_UNKNOWN)
				thisModulePtr->export.language = SMI_LANGUAGE_SMIV2;
			    importPtr = findImportByName("MODULE-COMPLIANCE",
							 thisModulePtr);
			    if (importPtr) {
				importPtr->use++;
			    } else {
				smiPrintError(thisParserPtr,
					      ERR_MACRO_NOT_IMPORTED,
					      "MODULE-COMPLIANCE",
					      "SNMPv2-CONF");
			    }
			}
    break;

  case 363:
/* Line 1787 of yacc.c  */
#line 6508 "parser-smi.y"
    {
			    checkDescr(thisParserPtr, (yyvsp[(8) - (8)].text));
			}
    break;

  case 364:
/* Line 1787 of yacc.c  */
#line 6514 "parser-smi.y"
    {
			    Object *objectPtr;
			    Option *optionPtr;
			    Refinement *refinementPtr;
			    List *listPtr;
			    
			    objectPtr = (yyvsp[(14) - (15)].objectPtr);

			    smiCheckObjectReuse(thisParserPtr, (yyvsp[(1) - (15)].id), &objectPtr);

			    setObjectName(objectPtr, (yyvsp[(1) - (15)].id), thisParserPtr);
			    setObjectDecl(objectPtr,
					  SMI_DECL_MODULECOMPLIANCE);
			    setObjectLine(objectPtr, thisParserPtr->firstStatementLine,
					  thisParserPtr);
			    addObjectFlags(objectPtr, FLAG_REGISTERED);
			    deleteObjectFlags(objectPtr, FLAG_INCOMPLETE);
			    setObjectStatus(objectPtr, (yyvsp[(6) - (15)].status));
			    setObjectDescription(objectPtr, (yyvsp[(8) - (15)].text), thisParserPtr);
			    if ((yyvsp[(10) - (15)].text)) {
				setObjectReference(objectPtr, (yyvsp[(10) - (15)].text), thisParserPtr);
			    }
			    setObjectAccess(objectPtr,
					    SMI_ACCESS_NOT_ACCESSIBLE);
			    setObjectList(objectPtr, (yyvsp[(11) - (15)].compl).mandatorylistPtr);
			    objectPtr->optionlistPtr = (yyvsp[(11) - (15)].compl).optionlistPtr;
			    objectPtr->refinementlistPtr =
				                          (yyvsp[(11) - (15)].compl).refinementlistPtr;

			    if ((yyvsp[(11) - (15)].compl).optionlistPtr) {
				for (listPtr = (yyvsp[(11) - (15)].compl).optionlistPtr;
				     listPtr;
				     listPtr = listPtr->nextPtr) {
				    optionPtr = ((Option *)(listPtr->ptr));
				    optionPtr->compliancePtr = objectPtr;
				}
			    }

			    /*
			     * Dirty: Fake the types' names in the
			     * refinement list:
			     * ``<compliancename>+<objecttypename>+type''
			     * ``<compliancename>+<objecttypename>+writetype''
			     */
			    if ((yyvsp[(11) - (15)].compl).refinementlistPtr) {
				for (listPtr = (yyvsp[(11) - (15)].compl).refinementlistPtr;
				     listPtr;
				     listPtr = listPtr->nextPtr) {
				    refinementPtr =
					((Refinement *)(listPtr->ptr));
				    refinementPtr->compliancePtr = objectPtr;
				}
			    }

			    (yyval.err) = 0;
			}
    break;

  case 365:
/* Line 1787 of yacc.c  */
#line 6573 "parser-smi.y"
    {
			    (yyval.compl) = (yyvsp[(1) - (1)].compl);
			}
    break;

  case 366:
/* Line 1787 of yacc.c  */
#line 6579 "parser-smi.y"
    {
			    (yyval.compl) = (yyvsp[(1) - (1)].compl);
			}
    break;

  case 367:
/* Line 1787 of yacc.c  */
#line 6583 "parser-smi.y"
    {
			    List *listPtr;
			    
			    /* concatenate lists in $1 and $2 */
			    if ((yyvsp[(1) - (2)].compl).mandatorylistPtr) {
				for (listPtr = (yyvsp[(1) - (2)].compl).mandatorylistPtr;
				     listPtr->nextPtr;
				     listPtr = listPtr->nextPtr);
				listPtr->nextPtr = (yyvsp[(2) - (2)].compl).mandatorylistPtr;
				(yyval.compl).mandatorylistPtr = (yyvsp[(1) - (2)].compl).mandatorylistPtr;
			    } else {
				(yyval.compl).mandatorylistPtr = (yyvsp[(2) - (2)].compl).mandatorylistPtr;
			    }
			    if ((yyvsp[(1) - (2)].compl).optionlistPtr) {
				for (listPtr = (yyvsp[(1) - (2)].compl).optionlistPtr;
				     listPtr->nextPtr;
				     listPtr = listPtr->nextPtr);
				listPtr->nextPtr = (yyvsp[(2) - (2)].compl).optionlistPtr;
				(yyval.compl).optionlistPtr = (yyvsp[(1) - (2)].compl).optionlistPtr;
			    } else {
				(yyval.compl).optionlistPtr = (yyvsp[(2) - (2)].compl).optionlistPtr;
			    }
			    if ((yyvsp[(1) - (2)].compl).refinementlistPtr) {
				for (listPtr = (yyvsp[(1) - (2)].compl).refinementlistPtr;
				     listPtr->nextPtr;
				     listPtr = listPtr->nextPtr);
				listPtr->nextPtr = (yyvsp[(2) - (2)].compl).refinementlistPtr;
				(yyval.compl).refinementlistPtr = (yyvsp[(1) - (2)].compl).refinementlistPtr;
			    } else {
				(yyval.compl).refinementlistPtr = (yyvsp[(2) - (2)].compl).refinementlistPtr;
			    }
			}
    break;

  case 368:
/* Line 1787 of yacc.c  */
#line 6618 "parser-smi.y"
    {
			    /*
			     * Remember the module. SMIv2 is broken by
			     * design to allow subsequent clauses to
			     * refer identifiers that are not
			     * imported.  Although, SMIv2 does not
			     * require, we will fake it by inserting
			     * appropriate imports.
			     */
			    if ((yyvsp[(2) - (2)].modulePtr) == thisModulePtr)
				thisParserPtr->complianceModulePtr = NULL;
			    else
				thisParserPtr->complianceModulePtr = (yyvsp[(2) - (2)].modulePtr);
			}
    break;

  case 369:
/* Line 1787 of yacc.c  */
#line 6634 "parser-smi.y"
    {
			    (yyval.compl).mandatorylistPtr = (yyvsp[(4) - (5)].listPtr);
			    (yyval.compl).optionlistPtr = (yyvsp[(5) - (5)].compl).optionlistPtr;
			    (yyval.compl).refinementlistPtr = (yyvsp[(5) - (5)].compl).refinementlistPtr;
			    if (thisParserPtr->complianceModulePtr) {
				checkImports(thisParserPtr->complianceModulePtr,
					     thisParserPtr);
				thisParserPtr->complianceModulePtr = NULL;
			    }
			}
    break;

  case 370:
/* Line 1787 of yacc.c  */
#line 6647 "parser-smi.y"
    {
			    (yyval.modulePtr) = findModuleByName((yyvsp[(1) - (2)].id));
			    /* TODO: handle objectIdentifier */
			    if (!(yyval.modulePtr)) {
				(yyval.modulePtr) = loadModule((yyvsp[(1) - (2)].id), thisParserPtr);
			    }
			    smiFree((yyvsp[(1) - (2)].id));
			}
    break;

  case 371:
/* Line 1787 of yacc.c  */
#line 6656 "parser-smi.y"
    {
			    (yyval.modulePtr) = findModuleByName((yyvsp[(1) - (1)].id));
			    if (!(yyval.modulePtr)) {
				(yyval.modulePtr) = loadModule((yyvsp[(1) - (1)].id), thisParserPtr);
			    }
			    smiFree((yyvsp[(1) - (1)].id));
			}
    break;

  case 372:
/* Line 1787 of yacc.c  */
#line 6665 "parser-smi.y"
    {
			    (yyval.modulePtr) = thisModulePtr;
			}
    break;

  case 373:
/* Line 1787 of yacc.c  */
#line 6671 "parser-smi.y"
    {
			    (yyval.listPtr) = (yyvsp[(3) - (4)].listPtr);
			}
    break;

  case 374:
/* Line 1787 of yacc.c  */
#line 6675 "parser-smi.y"
    {
			    (yyval.listPtr) = NULL;
			}
    break;

  case 375:
/* Line 1787 of yacc.c  */
#line 6681 "parser-smi.y"
    {
			    (yyval.listPtr) = smiMalloc(sizeof(List));
			    (yyval.listPtr)->ptr = (yyvsp[(1) - (1)].objectPtr);
			    (yyval.listPtr)->nextPtr = NULL;
			}
    break;

  case 376:
/* Line 1787 of yacc.c  */
#line 6687 "parser-smi.y"
    {
			    List *p, *pp;
			    
			    p = smiMalloc(sizeof(List));
			    p->ptr = (yyvsp[(3) - (3)].objectPtr);
			    p->nextPtr = NULL;
			    for (pp = (yyvsp[(1) - (3)].listPtr); pp->nextPtr; pp = pp->nextPtr);
			    pp->nextPtr = p;
			    (yyval.listPtr) = (yyvsp[(1) - (3)].listPtr);
			}
    break;

  case 377:
/* Line 1787 of yacc.c  */
#line 6700 "parser-smi.y"
    {
			    /* TODO: check that objectIdentifier is
			       found, is defined in thisParserPtr->complianceModulePtr,
			       and is a group node. */
			    Import *importPtr;

			    (yyval.objectPtr) = (yyvsp[(1) - (1)].objectPtr);
			    if (thisParserPtr->complianceModulePtr) {
				(yyval.objectPtr) = findObjectByModuleAndName(
				                           thisParserPtr->complianceModulePtr,
							   (yyvsp[(1) - (1)].objectPtr)->export.name);
			    }
			    if (thisParserPtr->complianceModulePtr && (yyvsp[(1) - (1)].objectPtr)->export.name) {
				importPtr = findImportByModulenameAndName(
				    thisParserPtr->complianceModulePtr->export.name,
				    (yyvsp[(1) - (1)].objectPtr)->export.name, thisModulePtr);
				if (importPtr)
				    importPtr->use++;
			    }
			}
    break;

  case 378:
/* Line 1787 of yacc.c  */
#line 6723 "parser-smi.y"
    {
			    (yyval.compl).mandatorylistPtr = NULL;
			    (yyval.compl).optionlistPtr = (yyvsp[(1) - (1)].compl).optionlistPtr;
			    (yyval.compl).refinementlistPtr = (yyvsp[(1) - (1)].compl).refinementlistPtr;
			}
    break;

  case 379:
/* Line 1787 of yacc.c  */
#line 6729 "parser-smi.y"
    {
			    (yyval.compl).mandatorylistPtr = NULL;
			    (yyval.compl).optionlistPtr = NULL;
			    (yyval.compl).refinementlistPtr = NULL;
			}
    break;

  case 380:
/* Line 1787 of yacc.c  */
#line 6737 "parser-smi.y"
    {
			    (yyval.compl) = (yyvsp[(1) - (1)].compl);
			}
    break;

  case 381:
/* Line 1787 of yacc.c  */
#line 6741 "parser-smi.y"
    {
			    List *listPtr;
			    int stop;
			    
			    (yyval.compl).mandatorylistPtr = NULL;

			    /* check for duplicates in optionlist */
			    stop = 0;
			    if ((yyvsp[(2) - (2)].compl).optionlistPtr) {
				for (listPtr = (yyvsp[(1) - (2)].compl).optionlistPtr; listPtr;
				     listPtr = listPtr->nextPtr) {
				    if (((Option *)listPtr->ptr)->objectPtr ==
					((Option *)(yyvsp[(2) - (2)].compl).optionlistPtr->ptr)->objectPtr) {
					smiPrintError(thisParserPtr,
						      ERR_OPTIONALGROUP_ALREADY_EXISTS,
						      ((Option *)(yyvsp[(2) - (2)].compl).optionlistPtr->ptr)->objectPtr->export.name);
					stop = 1;
					(yyval.compl).optionlistPtr = (yyvsp[(1) - (2)].compl).optionlistPtr;
				    }
				}
			    }
	
                            /* concatenate optionlists */
			    if ((yyvsp[(1) - (2)].compl).optionlistPtr) {
				for (listPtr = (yyvsp[(1) - (2)].compl).optionlistPtr;
				     listPtr->nextPtr;
				     listPtr = listPtr->nextPtr);
				if (!stop) {
				    listPtr->nextPtr = (yyvsp[(2) - (2)].compl).optionlistPtr;
				}
				(yyval.compl).optionlistPtr = (yyvsp[(1) - (2)].compl).optionlistPtr;
			    } else {
				(yyval.compl).optionlistPtr = (yyvsp[(2) - (2)].compl).optionlistPtr;
			    }

			    /* check for duplicates in refinementlist */
			    stop = 0;
			    if ((yyvsp[(2) - (2)].compl).refinementlistPtr) {
				for (listPtr = (yyvsp[(1) - (2)].compl).refinementlistPtr; listPtr;
				     listPtr = listPtr->nextPtr) {
				    if (((Refinement *)listPtr->ptr)->objectPtr ==
					((Refinement *)(yyvsp[(2) - (2)].compl).refinementlistPtr->ptr)->objectPtr) {
					smiPrintError(thisParserPtr,
						      ERR_REFINEMENT_ALREADY_EXISTS,
						      ((Refinement *)(yyvsp[(2) - (2)].compl).refinementlistPtr->ptr)->objectPtr->export.name);
					stop = 1;
					(yyval.compl).refinementlistPtr = (yyvsp[(1) - (2)].compl).refinementlistPtr;
				    }
				}
			    }
			    
                            /* concatenate refinementlists */
			    if ((yyvsp[(1) - (2)].compl).refinementlistPtr) {
				for (listPtr = (yyvsp[(1) - (2)].compl).refinementlistPtr;
				     listPtr->nextPtr;
				     listPtr = listPtr->nextPtr);
				if (!stop) {
				    listPtr->nextPtr = (yyvsp[(2) - (2)].compl).refinementlistPtr;
				}
				(yyval.compl).refinementlistPtr = (yyvsp[(1) - (2)].compl).refinementlistPtr;
			    } else {
				(yyval.compl).refinementlistPtr = (yyvsp[(2) - (2)].compl).refinementlistPtr;
			    }
			}
    break;

  case 382:
/* Line 1787 of yacc.c  */
#line 6808 "parser-smi.y"
    {
			    (yyval.compl).mandatorylistPtr = NULL;
			    (yyval.compl).optionlistPtr = (yyvsp[(1) - (1)].listPtr);
			    (yyval.compl).refinementlistPtr = NULL;
			}
    break;

  case 383:
/* Line 1787 of yacc.c  */
#line 6814 "parser-smi.y"
    {
			    (yyval.compl).mandatorylistPtr = NULL;
			    (yyval.compl).optionlistPtr = NULL;
			    (yyval.compl).refinementlistPtr = (yyvsp[(1) - (1)].listPtr);
			}
    break;

  case 384:
/* Line 1787 of yacc.c  */
#line 6822 "parser-smi.y"
    {
			    thisParserPtr->firstNestedStatementLine = thisParserPtr->line;
			}
    break;

  case 385:
/* Line 1787 of yacc.c  */
#line 6827 "parser-smi.y"
    {
			    Import *importPtr;
			    
			    if (thisParserPtr->complianceModulePtr && (yyvsp[(3) - (5)].objectPtr)->export.name) {
				importPtr = findImportByModulenameAndName(
						    thisParserPtr->complianceModulePtr->export.name,
						    (yyvsp[(3) - (5)].objectPtr)->export.name,
						    thisModulePtr);
				if (importPtr)
				    importPtr->use++;
			    }

			    checkDescr(thisParserPtr, (yyvsp[(5) - (5)].text));
			    
			    (yyval.listPtr) = smiMalloc(sizeof(List));
			    (yyval.listPtr)->nextPtr = NULL;
			    (yyval.listPtr)->ptr = smiMalloc(sizeof(Option));
			    ((Option *)((yyval.listPtr)->ptr))->line = thisParserPtr->firstNestedStatementLine;
			    ((Option *)((yyval.listPtr)->ptr))->objectPtr = (yyvsp[(3) - (5)].objectPtr);
			    if (! (thisModulePtr->flags & SMI_FLAG_NODESCR)) {
				((Option *)((yyval.listPtr)->ptr))->export.description = (yyvsp[(5) - (5)].text);
			    } else {
				smiFree((yyvsp[(5) - (5)].text));
			    }
			}
    break;

  case 386:
/* Line 1787 of yacc.c  */
#line 6855 "parser-smi.y"
    {
			    thisParserPtr->firstNestedStatementLine = thisParserPtr->line;
			    variationkind = SMI_NODEKIND_UNKNOWN;
			}
    break;

  case 387:
/* Line 1787 of yacc.c  */
#line 6864 "parser-smi.y"
    {
			    Import *importPtr;

			    if (thisParserPtr->complianceModulePtr && (yyvsp[(3) - (8)].objectPtr)->export.name) {
				importPtr = findImportByModulenameAndName(
						    thisParserPtr->complianceModulePtr->export.name,
						    (yyvsp[(3) - (8)].objectPtr)->export.name,
						    thisModulePtr);
				if (importPtr) 
				    importPtr->use++;
			    }

			    checkDescr(thisParserPtr, (yyvsp[(8) - (8)].text));
			    
			    thisParserPtr->flags &= ~FLAG_CREATABLE;
			    (yyval.listPtr) = smiMalloc(sizeof(List));
			    (yyval.listPtr)->nextPtr = NULL;
			    (yyval.listPtr)->ptr = smiMalloc(sizeof(Refinement));
			    ((Refinement *)((yyval.listPtr)->ptr))->line =
				thisParserPtr->firstNestedStatementLine;
			    ((Refinement *)((yyval.listPtr)->ptr))->objectPtr = (yyvsp[(3) - (8)].objectPtr);
			    ((Refinement *)((yyval.listPtr)->ptr))->typePtr = (yyvsp[(4) - (8)].typePtr);
			    if ((yyvsp[(4) - (8)].typePtr)) {
				(yyvsp[(4) - (8)].typePtr)->parentPtr = (yyvsp[(3) - (8)].objectPtr)->typePtr;
			    }
			    ((Refinement *)((yyval.listPtr)->ptr))->writetypePtr = (yyvsp[(5) - (8)].typePtr);
			    if ((yyvsp[(5) - (8)].typePtr)) {
				(yyvsp[(5) - (8)].typePtr)->parentPtr = (yyvsp[(3) - (8)].objectPtr)->typePtr;
			    }
			    ((Refinement *)((yyval.listPtr)->ptr))->export.access = (yyvsp[(6) - (8)].access);
			    if (! (thisParserPtr->flags & SMI_FLAG_NODESCR)) {
				((Refinement *)((yyval.listPtr)->ptr))->export.description = (yyvsp[(8) - (8)].text);
			    } else {
				smiFree((yyvsp[(8) - (8)].text));
			    }
			}
    break;

  case 388:
/* Line 1787 of yacc.c  */
#line 6903 "parser-smi.y"
    {
			    /* must not be present in notification variations */
			    if (variationkind == SMI_NODEKIND_NOTIFICATION) {
				smiPrintError(thisParserPtr,
				      ERR_NOTIFICATION_VARIATION_SYNTAX);
			    }
			    if ((yyvsp[(2) - (2)].typePtr)->export.name) {
				(yyval.typePtr) = duplicateType((yyvsp[(2) - (2)].typePtr), 0, thisParserPtr);
			    } else {
				(yyval.typePtr) = (yyvsp[(2) - (2)].typePtr);
			    }
			}
    break;

  case 389:
/* Line 1787 of yacc.c  */
#line 6916 "parser-smi.y"
    {
			    (yyval.typePtr) = NULL;
			}
    break;

  case 390:
/* Line 1787 of yacc.c  */
#line 6922 "parser-smi.y"
    {
                            /* must not be present in PIBs */
                            if (thisParserPtr->modulePtr->export.language == SMI_LANGUAGE_SPPI) {
                                smiPrintError(thisParserPtr, ERR_SMI_CONSTRUCT_IN_PIB, "WRITE-SYNTAX");
			    }
			    /* must not be present in notification variations */
			    if (variationkind == SMI_NODEKIND_NOTIFICATION) {
				smiPrintError(thisParserPtr,
				      ERR_NOTIFICATION_VARIATION_WRITESYNTAX);
			    }
			    if ((yyvsp[(2) - (2)].typePtr)->export.name) {
				(yyval.typePtr) = duplicateType((yyvsp[(2) - (2)].typePtr), 0, thisParserPtr);
			    } else {
				(yyval.typePtr) = (yyvsp[(2) - (2)].typePtr);
			    }
			}
    break;

  case 391:
/* Line 1787 of yacc.c  */
#line 6939 "parser-smi.y"
    {
			    (yyval.typePtr) = NULL;
			}
    break;

  case 392:
/* Line 1787 of yacc.c  */
#line 6945 "parser-smi.y"
    {
			    (yyval.typePtr) = (yyvsp[(1) - (1)].typePtr);
			}
    break;

  case 393:
/* Line 1787 of yacc.c  */
#line 6951 "parser-smi.y"
    {
                            if (thisParserPtr->modulePtr->export.language == SMI_LANGUAGE_SPPI)
                                smiPrintError(thisParserPtr, ERR_SMI_CONSTRUCT_IN_PIB, "MIN-ACCESS");
			    (yyval.access) = (yyvsp[(2) - (2)].access);
			}
    break;

  case 394:
/* Line 1787 of yacc.c  */
#line 6957 "parser-smi.y"
    {
                            if (thisParserPtr->modulePtr->export.language != SMI_LANGUAGE_SPPI)
                                smiPrintError(thisParserPtr, ERR_SPPI_CONSTRUCT_IN_MIB, "PIB-MIN-ACCESS");
                            if ((yyvsp[(2) - (2)].access) == SMI_ACCESS_REPORT_ONLY)
                                smiPrintError(thisParserPtr, ERR_REPORT_ONLY_IN_PIB_MIN_ACCESS);
                            (yyval.access) = (yyvsp[(2) - (2)].access);
                        }
    break;

  case 395:
/* Line 1787 of yacc.c  */
#line 6965 "parser-smi.y"
    {
			    (yyval.access) = SMI_ACCESS_UNKNOWN;
			}
    break;

  case 396:
/* Line 1787 of yacc.c  */
#line 6971 "parser-smi.y"
    {
			    thisParserPtr->firstStatementLine = thisParserPtr->line;
			    thisParserPtr->currentDecl = SMI_DECL_AGENTCAPABILITIES;
			    
			    checkNameLen(thisParserPtr, (yyvsp[(1) - (1)].id),
					 ERR_OIDNAME_32, ERR_OIDNAME_64);
			    smiCheckObjectName(thisParserPtr,
					       thisModulePtr, (yyvsp[(1) - (1)].id));
			}
    break;

  case 397:
/* Line 1787 of yacc.c  */
#line 6981 "parser-smi.y"
    {
			    Import *importPtr;
                            if (thisParserPtr->modulePtr->export.language == SMI_LANGUAGE_SPPI)
                                smiPrintError(thisParserPtr, ERR_SMI_CONSTRUCT_IN_PIB, "AGENT-CAAPABILITIES");
			    
			    if (thisModulePtr->export.language == SMI_LANGUAGE_UNKNOWN)
				thisModulePtr->export.language = SMI_LANGUAGE_SMIV2;

			    importPtr = findImportByName("AGENT-CAPABILITIES",
							 thisModulePtr);
			    if (importPtr) {
				importPtr->use++;
			    } else {
				smiPrintError(thisParserPtr,
					      ERR_MACRO_NOT_IMPORTED,
					      "AGENT-CAPABILITIES",
					      "SNMPv2-CONF");
			    }
			}
    break;

  case 398:
/* Line 1787 of yacc.c  */
#line 7003 "parser-smi.y"
    {
			    checkDescr(thisParserPtr, (yyvsp[(10) - (10)].text));
			}
    break;

  case 399:
/* Line 1787 of yacc.c  */
#line 7009 "parser-smi.y"
    {
			    Object *objectPtr;
			    
			    objectPtr = (yyvsp[(16) - (17)].objectPtr);
			    
			    smiCheckObjectReuse(thisParserPtr, (yyvsp[(1) - (17)].id), &objectPtr);

			    setObjectName(objectPtr, (yyvsp[(1) - (17)].id), thisParserPtr);
			    setObjectDecl(objectPtr,
					  SMI_DECL_AGENTCAPABILITIES);
			    setObjectLine(objectPtr, thisParserPtr->firstStatementLine,
					  thisParserPtr);
			    addObjectFlags(objectPtr, FLAG_REGISTERED);
			    deleteObjectFlags(objectPtr, FLAG_INCOMPLETE);
			    setObjectStatus(objectPtr, (yyvsp[(8) - (17)].status));
			    setObjectDescription(objectPtr, (yyvsp[(10) - (17)].text), thisParserPtr);
			    if ((yyvsp[(12) - (17)].text)) {
				setObjectReference(objectPtr, (yyvsp[(12) - (17)].text), thisParserPtr);
			    }
			    setObjectAccess(objectPtr,
					    SMI_ACCESS_NOT_ACCESSIBLE);
				/*
				 * TODO: PRODUCT_RELEASE Text
				 * TODO: ModulePart_Capabilities
				 */
			    (yyval.err) = 0;
			}
    break;

  case 400:
/* Line 1787 of yacc.c  */
#line 7039 "parser-smi.y"
    { (yyval.err) = 0; }
    break;

  case 401:
/* Line 1787 of yacc.c  */
#line 7041 "parser-smi.y"
    { (yyval.err) = 0; }
    break;

  case 402:
/* Line 1787 of yacc.c  */
#line 7045 "parser-smi.y"
    { (yyval.err) = 0; }
    break;

  case 403:
/* Line 1787 of yacc.c  */
#line 7047 "parser-smi.y"
    { (yyval.err) = 0; }
    break;

  case 404:
/* Line 1787 of yacc.c  */
#line 7051 "parser-smi.y"
    {
			    /*
			     * Remember the module. SMIv2 is broken by
			     * design to allow subsequent clauses to
			     * refer identifiers that are not
			     * imported.  Although, SMIv2 does not
			     * require, we will fake it by inserting
			     * appropriate imports.
			     */
			    if ((yyvsp[(2) - (2)].modulePtr) == thisModulePtr)
				thisParserPtr->capabilitiesModulePtr = NULL;
			    else
				thisParserPtr->capabilitiesModulePtr = (yyvsp[(2) - (2)].modulePtr);
			}
    break;

  case 405:
/* Line 1787 of yacc.c  */
#line 7067 "parser-smi.y"
    {
			    if (thisParserPtr->capabilitiesModulePtr) {
				checkImports(thisParserPtr->capabilitiesModulePtr,
					     thisParserPtr);
				thisParserPtr->capabilitiesModulePtr = NULL;
			    }
			    (yyval.err) = 0;
			}
    break;

  case 406:
/* Line 1787 of yacc.c  */
#line 7078 "parser-smi.y"
    {
#if 0
			    (yyval.listPtr) = smiMalloc(sizeof(List));
			    (yyval.listPtr)->ptr = (yyvsp[(1) - (1)].listPtr);
			    (yyval.listPtr)->nextPtr = NULL;
#else
			    (yyval.listPtr) = NULL;
#endif
			}
    break;

  case 407:
/* Line 1787 of yacc.c  */
#line 7088 "parser-smi.y"
    {
#if 0
			    List *p, *pp;
			    
			    p = smiMalloc(sizeof(List));
			    p->ptr = (yyvsp[(3) - (3)].listPtr);
			    p->nextPtr = NULL;
			    for (pp = (yyvsp[(1) - (3)].listPtr); pp->nextPtr; pp = pp->nextPtr);
			    pp->nextPtr = p;
			    (yyval.listPtr) = (yyvsp[(1) - (3)].listPtr);
#else
			    (yyval.listPtr) = NULL;
#endif
			}
    break;

  case 408:
/* Line 1787 of yacc.c  */
#line 7105 "parser-smi.y"
    {
			    (yyval.listPtr) = NULL;
			}
    break;

  case 409:
/* Line 1787 of yacc.c  */
#line 7111 "parser-smi.y"
    {
			    (yyval.modulePtr) = findModuleByName((yyvsp[(1) - (2)].id));
			    /* TODO: handle objectIdentifier */
			    if (!(yyval.modulePtr)) {
				(yyval.modulePtr) = loadModule((yyvsp[(1) - (2)].id), thisParserPtr);
			    }
			    smiFree((yyvsp[(1) - (2)].id));
			}
    break;

  case 410:
/* Line 1787 of yacc.c  */
#line 7120 "parser-smi.y"
    {
			    (yyval.modulePtr) = findModuleByName((yyvsp[(1) - (1)].id));
			    if (!(yyval.modulePtr)) {
				(yyval.modulePtr) = loadModule((yyvsp[(1) - (1)].id), thisParserPtr);
			    }
			    smiFree((yyvsp[(1) - (1)].id));
			}
    break;

  case 411:
/* Line 1787 of yacc.c  */
#line 7130 "parser-smi.y"
    { (yyval.err) = 0; }
    break;

  case 412:
/* Line 1787 of yacc.c  */
#line 7132 "parser-smi.y"
    { (yyval.err) = 0; }
    break;

  case 413:
/* Line 1787 of yacc.c  */
#line 7136 "parser-smi.y"
    { (yyval.err) = 0; }
    break;

  case 414:
/* Line 1787 of yacc.c  */
#line 7138 "parser-smi.y"
    { (yyval.err) = 0; }
    break;

  case 415:
/* Line 1787 of yacc.c  */
#line 7142 "parser-smi.y"
    {
			    if ((yyvsp[(2) - (2)].objectPtr)) {
				variationkind = (yyvsp[(2) - (2)].objectPtr)->export.nodekind;
			    } else {
				variationkind = SMI_NODEKIND_UNKNOWN;
			    }
			}
    break;

  case 416:
/* Line 1787 of yacc.c  */
#line 7154 "parser-smi.y"
    {
			    if ((yyvsp[(8) - (8)].valuePtr)) {
				adjustDefval(thisParserPtr,
					     (yyvsp[(8) - (8)].valuePtr), (yyvsp[(2) - (8)].objectPtr)->typePtr,
					     thisParserPtr->line);
				smiCheckValueType(thisParserPtr,
						  (yyvsp[(8) - (8)].valuePtr), (yyvsp[(2) - (8)].objectPtr)->typePtr,
						  thisParserPtr->line);
			    }
			}
    break;

  case 417:
/* Line 1787 of yacc.c  */
#line 7165 "parser-smi.y"
    {
			    thisParserPtr->flags &= ~FLAG_CREATABLE;
			    (yyval.err) = 0;
			    variationkind = SMI_NODEKIND_UNKNOWN;

			    checkDescr(thisParserPtr, (yyvsp[(10) - (11)].id));
			}
    break;

  case 418:
/* Line 1787 of yacc.c  */
#line 7175 "parser-smi.y"
    { (yyval.access) = (yyvsp[(2) - (2)].access); }
    break;

  case 419:
/* Line 1787 of yacc.c  */
#line 7177 "parser-smi.y"
    { (yyval.access) = 0; }
    break;

  case 420:
/* Line 1787 of yacc.c  */
#line 7181 "parser-smi.y"
    {
			    if (!strcmp((yyvsp[(1) - (1)].id), "not-implemented")) {
				(yyval.access) = SMI_ACCESS_NOT_IMPLEMENTED;
			    } else if (!strcmp((yyvsp[(1) - (1)].id), "accessible-for-notify")) {
				if (variationkind ==
				    SMI_NODEKIND_NOTIFICATION) {
				    smiPrintError(thisParserPtr,
				     ERR_INVALID_NOTIFICATION_VARIATION_ACCESS,
					       (yyvsp[(1) - (1)].id));
				    (yyval.access) = SMI_ACCESS_UNKNOWN;
				} else {
				    (yyval.access) = SMI_ACCESS_NOTIFY;
				}
			    } else if (!strcmp((yyvsp[(1) - (1)].id), "read-only")) {
				if (variationkind ==
				    SMI_NODEKIND_NOTIFICATION) {
				    smiPrintError(thisParserPtr,
				     ERR_INVALID_NOTIFICATION_VARIATION_ACCESS,
					       (yyvsp[(1) - (1)].id));
				    (yyval.access) = SMI_ACCESS_UNKNOWN;
				} else {
				    (yyval.access) = SMI_ACCESS_READ_ONLY;
				}
			    } else if (!strcmp((yyvsp[(1) - (1)].id), "read-write")) {
				if (variationkind ==
				    SMI_NODEKIND_NOTIFICATION) {
				    smiPrintError(thisParserPtr,
				     ERR_INVALID_NOTIFICATION_VARIATION_ACCESS,
					       (yyvsp[(1) - (1)].id));
				    (yyval.access) = SMI_ACCESS_UNKNOWN;
				} else {
				    (yyval.access) = SMI_ACCESS_READ_WRITE;
				}
			    } else if (!strcmp((yyvsp[(1) - (1)].id), "read-create")) {
				if (variationkind ==
				    SMI_NODEKIND_NOTIFICATION) {
				    smiPrintError(thisParserPtr,
				     ERR_INVALID_NOTIFICATION_VARIATION_ACCESS,
					       (yyvsp[(1) - (1)].id));
				    (yyval.access) = SMI_ACCESS_UNKNOWN;
				} else {
				    (yyval.access) = SMI_ACCESS_READ_WRITE;
				}
			    } else if (!strcmp((yyvsp[(1) - (1)].id), "write-only")) {
				if (variationkind ==
				    SMI_NODEKIND_NOTIFICATION) {
				    smiPrintError(thisParserPtr,
				     ERR_INVALID_NOTIFICATION_VARIATION_ACCESS,
					       (yyvsp[(1) - (1)].id));
				    (yyval.access) = SMI_ACCESS_UNKNOWN;
				} else {
				    (yyval.access) = SMI_ACCESS_READ_WRITE; /* TODO */
				    smiPrintError(thisParserPtr,
					       ERR_SMIV2_WRITE_ONLY);
				}
			    } else {
				smiPrintError(thisParserPtr,
					      ERR_INVALID_VARIATION_ACCESS,
					      (yyvsp[(1) - (1)].id));
				(yyval.access) = SMI_ACCESS_UNKNOWN;
			    }
			}
    break;

  case 421:
/* Line 1787 of yacc.c  */
#line 7246 "parser-smi.y"
    {
			    /* must not be present in notification variations */
			    if (variationkind == SMI_NODEKIND_NOTIFICATION) {
				smiPrintError(thisParserPtr,
				      ERR_NOTIFICATION_VARIATION_CREATION);
			    }
			    (yyval.err) = 0;
			}
    break;

  case 422:
/* Line 1787 of yacc.c  */
#line 7255 "parser-smi.y"
    { (yyval.err) = 0; }
    break;

  case 423:
/* Line 1787 of yacc.c  */
#line 7259 "parser-smi.y"
    { (yyval.err) = 0; }
    break;

  case 424:
/* Line 1787 of yacc.c  */
#line 7261 "parser-smi.y"
    { (yyval.err) = 0; }
    break;

  case 425:
/* Line 1787 of yacc.c  */
#line 7265 "parser-smi.y"
    { (yyval.err) = 0; }
    break;


/* Line 1787 of yacc.c  */
#line 10189 "parser-smi.c"
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (parserPtr, YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (parserPtr, yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
	 error, discard it.  */

      if (yychar <= YYEOF)
	{
	  /* Return failure if at end of input.  */
	  if (yychar == YYEOF)
	    YYABORT;
	}
      else
	{
	  yydestruct ("Error: discarding",
		      yytoken, &yylval, parserPtr);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
	    {
	      yyn = yytable[yyn];
	      if (0 < yyn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
	YYABORT;


      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp, parserPtr);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (parserPtr, YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval, parserPtr);
    }
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp, parserPtr);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}


/* Line 2050 of yacc.c  */
#line 7268 "parser-smi.y"


#endif
