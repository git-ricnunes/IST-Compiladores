%option c++ yyclass="pwn_scanner" outfile="pwn_scanner.cpp"
%option stack noyywrap yylineno 8bit

%{ 
/* $Id: pwn_scanner.l,v 1.2 2015/03/06 20:15:44 ist171015 Exp $ */
// make relevant includes before including the parser's tab file
#include <string>
#include <cdk/ast/sequence_node.h>
#include <cdk/ast/expression_node.h>
#include "pwn_scanner.h"
#include "pwn_parser.tab.h"

// don't change this
#define yyerror LexerError
%}
%x X_STRING
%%

"--".*                 ; /* ignore comments */

">="                   return tGE; 
"<="                   return tLE; 
"=="                   return tEQ; 
"!="                   return tNE; 

"while"                return tWHILE; 
"if"                   return tIF; 
"else"                 return tELSE; 
"print"                return tPRINT; 
"read"                 return tREAD; 
"begin"                return tBEGIN; 
"end"                  return tEND; 

[A-Za-z][A-Za-z0-9_]*  yylval.s = new std::string(yytext); return tIDENTIFIER;

\'                     yy_push_state(X_STRING); yylval.s = new std::string("");
<X_STRING>\'           yy_pop_state(); return tSTRING;
<X_STRING>\\\'         *yylval.s += yytext + 1;
<X_STRING>.            *yylval.s += yytext;
<X_STRING>\n           yyerror("newline in string");

[0-9]+                 yylval.i = strtol(yytext, nullptr, 10); return tINTEGER;

[-()<>=+*/%;{}.]       return *yytext;

[ \t\n]+               ; /* ignore whitespace */

.                      yyerror("Unknown character");

%%
// Very, very dirty hack: flex is a mess generating C++ scanners.
int pwn_scanner::yywrap() { return 1; }
