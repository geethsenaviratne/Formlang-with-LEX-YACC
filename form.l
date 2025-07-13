%{
#include "form.tab.h"
#include <stdlib.h>
#include <string.h>
extern int yylineno;
%}

%%

form            { return FORM; }
section         { return SECTION; }
field           { return FIELD; }
required        { return REQUIRED; }
meta            { return META; }
validate        { return VALIDATE; }
if              { return IF; }
error           { return ERROR; }
true            { return TRUE; }
false           { return FALSE; }
options         { return OPTIONS; }

text            { yylval.str = strdup("text"); return IDENTIFIER; }
textarea        { yylval.str = strdup("textarea"); return IDENTIFIER; }
rows            { return ROWS; }
cols            { return COLS; }
default         { return DEFAULT; }
checkbox        { yylval.str = strdup("checkbox"); return IDENTIFIER; }
radio           { yylval.str = strdup("radio"); return IDENTIFIER; }
dropdown        { yylval.str = strdup("dropdown"); return IDENTIFIER; }

number          { yylval.str = strdup("number"); return IDENTIFIER; }
password        { yylval.str = strdup("password"); return IDENTIFIER; }
email           { yylval.str = strdup("email"); return IDENTIFIER; }
date            { yylval.str = strdup("date"); return IDENTIFIER; }
file            { yylval.str = strdup("file"); return IDENTIFIER; }

min             { return MIN; }
max             { return MAX; }



[0-9]+          { 
    yylval.str = strdup(yytext); return NUMBER; 
    }
\"[^\"]*\"      { 
    yylval.str = strdup(yytext); return STRING; 
    }

":"             { return COLON; }
";"             { return SEMICOLON; }
"{"             { return LBRACE; }
"}"             { return RBRACE; }
"="             { return EQUAL; }
"<"             { return LT; }
","             { return COMMA; }
\[              { return LBRACKET; }
\]              { return RBRACKET; }

[a-zA-Z_][a-zA-Z0-9_]*  { 
    yylval.str = strdup(yytext); return IDENTIFIER; 
    }

\n              { 
    yylineno++; 
    }

[ \t\r]+        ; // Skip whitespace
.               { 
    printf("Unexpected character: %s\n", yytext); exit(1); 
}

%%

int yywrap() { 
    return 1; 
    }
