%{
#include <stdlib.h>
#include <stdio.h>
#include "y.tab.h"
%}
%option noyywrap
%%
[ \t]+$? {}; /*Ignoring spaces at the end of a line*/

"{" return tOpeningBracket  ;
"}" return tClosingBracket  ;
"main()" return tMain  ;
"+" return tPlus ;
"-" return tMinus ;
"*" return tMult ;
"/" return tDiv ;
"=" return tEqual ;
"(" return tOpeningParenthesis ;
")" return tClosingParenthesis ;
"," return tVirgule;
"\;" return tPointVirgule;
"if" return tIf;
"else" return tElse;
"while" return tWhile;
"printf" return tPrintf;
"int" return tDeclareInt ;
"const" return tDeclareConstInt ; /*Detecting integer const declaration*/
[a-zA-Z][a-zA-Z0-9]* {yylval.var = malloc(yyleng); strcpy(yylval.var,yytext) ; return tVarName ;} ; /*Detecting integers*/
[0-9]+ {yylval.nb = atoi(yytext); return tValueInt ;} ;
[0-9]+"E"[0-9]+ {yylval.nb_exp = atof(yytext); return tValueExp ;} ;
"\n" {} ;




