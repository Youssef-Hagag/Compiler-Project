%{
#include "value.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "parser.tab.h"

extern YYSTYPE yylval;
void yyerror(const char *, ...);
int line_num = 1;
%}

%%

"const"     { return CONST; }
"int"       { yylval.type_val = TYPE_INT; return TYPE; }
"float"     { yylval.type_val = TYPE_FLOAT; return TYPE; }
"char"      { yylval.type_val = TYPE_CHAR; return TYPE; }
"bool"      { yylval.type_val = TYPE_BOOL; return TYPE; }
"string"    { yylval.type_val = TYPE_STRING; return TYPE; }
"void"      { yylval.type_val = TYPE_VOID; return VOID; }

"true"      { yylval.val = make_bool(1); return BOOL_LITERAL; }
"false"     { yylval.val = make_bool(0); return BOOL_LITERAL; }

"if"        { return IF; }
"else"      { return ELSE; }
"while"     { return WHILE; }
"do"        { return DO; }
"for"       { return FOR; }
"return"    { return RETURN; }
"switch"    { return SWITCH; }
"case"      { return CASE; }
"default"   { return DEFAULT; }
"break"     { return BREAK; }
"continue"  { return CONTINUE; }

[0-9]+\.[0-9]+  { yylval.val = make_float(atof(yytext)); return FLOAT_LITERAL; }

[0-9]+    { yylval.val = make_int(atoi(yytext)); return INTEGER; }

\'(.)\'   { yylval.val = make_char(yytext[1]); return CHAR_LITERAL; }

\"([^\\"]|\\.)*\" {
    // Remove the quotes
    int len = strlen(yytext);
    yytext[len-1] = '\0';
    yylval.val = make_string(yytext+1);
    return STRING_LITERAL;
}

[a-zA-Z_][a-zA-Z0-9_]*  {
    yylval.str = strdup(yytext);
    return VARIABLE;
}

"=="    { yylval.relop = strdup(yytext); return RELOP; }
"!="    { yylval.relop = strdup(yytext); return RELOP; }
"<="    { yylval.relop = strdup(yytext); return RELOP; }
">="    { yylval.relop = strdup(yytext); return RELOP; }
"<"     { yylval.relop = strdup(yytext); return RELOP; }
">"     { yylval.relop = strdup(yytext); return RELOP; }

"&&"    { return LAND; }
"||"    { return LOR; }
"**"    { return POW; }

[+\-*/=%!]  { return *yytext; }
[{}();,:]   { return *yytext; }

[ \t]   ;
"//".*  ;
\n      { line_num++; }

. { yyerror("Unknown character"); }

%%

int yywrap(void) {
    return 1;
}
