/*
 *  The scanner definition for COOL.
 */

/*
 *  Stuff enclosed in %{ %} in the first section is copied verbatim to the
 *  output, so headers and global definitions are placed here to be visible
 * to the code in the file.  Don't remove anything that was here initially
 */

%option noyywrap

%{
#include <cool-parse.h>
#include <stringtab.h>
#include <utilities.h>
#include <stdlib.h>

/* The compiler assumes these identifiers. */
#define yylval cool_yylval
#define yylex  cool_yylex

/* Max size of string constants */
#define MAX_STR_CONST 1025
#define YY_NO_UNPUT   /* keep g++ happy */

extern FILE *fin; /* we read from this file */

/* define YY_INPUT so we read from the FILE fin:
 * This change makes it possible to use this scanner in
 * the Cool compiler.
 */
#undef YY_INPUT
#define YY_INPUT(buf,result,max_size) \
	if ( (result = fread( (char*)buf, sizeof(char), max_size, fin)) < 0) \
		YY_FATAL_ERROR( "read() in flex scanner failed");

char string_buf[MAX_STR_CONST]; /* to assemble string constants */
char *string_buf_ptr;

extern int curr_lineno;
extern int verbose_flag;

extern YYSTYPE cool_yylval;

/*
 *  Add Your own definitions here
 */

%}

/*
 * Define names for regular expressions here.
 */

/*
 * 10.1 Integers, Identifiers, and Special Notation
 */
DIGIT                   [0-9]
LOWERCASE_LETTER        [a-z]
UPPERCASE_LETTER        [A-Z]
LETTER                  ({LOWERCASE_LETTER}|{UPPERCASE_LETTER})
INTEGER                 {DIGIT}+
TYPE_IDENTIFIER         ("SELF_TYPE"|{UPPERCASE_LETTER}({LETTER}|{DIGIT}|"_")*)
OBJECT_IDENTIFIER       ("self"|{LETTER}({LETTER}|{DIGIT}|"_")*)
SINGLE_CHAR_OPERATOR    ("+"|"/"|"-"|"*"|"="|"<"|"."|"~"|","|";"|":"|"("|")"|"@"|"{"|"}")
ASSIGN                  "<-"
DARROW                  "=>"
LE                      "<="

/*
 * 10.2 Strings
 */
STRING_START    "\""
STRING_END      "\""

/*
 * 10.3 Comments
 */
ONE_LINE_COMMENT_START         "--"
ONE_LINE_COMMENT_END           "--"
MULTIPLE_LINE_COMMENT_START    "\(\*"
MULTIPLE_LINE_COMMENT_END      "\*\)"

/*
 * 10.4 Keywords are case insensitive, expect for the constants true and false
 */
CLASS       (?i:class)
ELSE        (?i:else)
FI          (?i:fi)
IF          (?i:if)
IN          (?i:in)
INHERITS    (?i:inherits)
ISVOID      (?i:isvoid)
LET         (?i:let)
LOOP        (?i:loop)
POOL        (?i:pool)
THEN        (?i:then)
WHILE       (?i:while)
CASE        (?i:case)
ESAC        (?i:esac)
NEW         (?i:new)
OF          (?i:of)
NOT         (?i:not)

BOOL_CONST_TRUE     (t)(?i:rue)
BOOL_CONST_FALSE    (f)(?i:alse)

/*
 * 10.5 White Space
 */
WHITE_SPACE    (" "|\f|\r|\t|\v)

%%

 /*
  *  The keywords.
  */
{CLASS} { return CLASS; }
{ELSE} { return ELSE; }
{FI} { return FI; }
{IF} { return IF; }
{IN} { return IN; }
{INHERITS} { return INHERITS; }
{ISVOID} { return ISVOID; }
{LET} { return LET; }
{LOOP} { return LOOP; }
{POOL} { return POOL; }
{THEN} { return THEN; }
{WHILE} { return WHILE; }
{CASE} { return CASE; }
{ESAC} { return ESAC; }
{NEW} { return NEW; }
{OF} { return OF; }
{NOT} { return NOT; }

 /*
  *  The multiple-character operators.
  */
{ASSIGN} { return ASSIGN; }
{DARROW} { return DARROW; }
{LE} { return LE; }

 /*
  *  The single-character operators.
  */
{SINGLE_CHAR_OPERATOR} { return yytext[0]; }


{INTEGER} {
  cool_yylval.symbol = inttable.add_string(yytext);
  return INT_CONST;
}

{TYPE_IDENTIFIER} {
  cool_yylval.symbol = idtable.add_string(yytext);
  return TYPEID;
}

{OBJECT_IDENTIFIER} {
  cool_yylval.symbol = idtable.add_string(yytext);
  return OBJECTID;
}

{BOOL_CONST_TRUE} {
  cool_yylval.boolean = true;
  return BOOL_CONST;
}
{BOOL_CONST_FALSE} {
  cool_yylval.boolean = false;
  return BOOL_CONST;
}

 /*
  *  Nested comments
  */




 /*
  * Keywords are case-insensitive except for the values true and false,
  * which must begin with a lower-case letter.
  */


 /*
  *  String constants (C syntax)
  *  Escape sequence \c is accepted for all characters c. Except for 
  *  \n \t \b \f, the result is c.
  *
  */

\n { curr_lineno++; }
{WHITE_SPACE} {}

%%
