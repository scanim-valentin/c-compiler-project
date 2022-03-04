%{
#include <stdlib.h>
#include <stdio.h>

%}
%option noyywrap
%%
[ \t]+$ {}; /*Ignoring spaces at the end of a line*/
[ \t]+ return tkSpace; /*Replacing multiple spaces with a single space*/
[a-zA-Z][a-zA-Z0-9]* {yyval.text = malloc(sizeof(char)*strlen(yytex)) ; strcpy(yyval.text,yytext) ; return tkVariable ;} /*detecting variables*/
int[ \t]+[a-zA-Z][a-zA-Z0-9]* return tDeclareInt ; /*Detecting integers*/
const[ \t]+[a-zA-Z][a-zA-Z0-9]*; {return tDeclareConstInt} ; /*Detecting integer const declaration*/
[0-9]+ { yylval.val = atoi(yytext) ; return tValueInt ;}; /*Detecting integer values*/
[0-9]+E[0-9]+ { yyval.val = atof(yytext) ; return tValueExp ;} ; /*Detecting doubles values in scientific notation*/
"{" return tOpeningBracket  ;
"}" return tClosingInt  ;
"main()" return tMain  ;
"+" return tPlus ;
"-" return tMinus ;
"*" return tMult ;
"/" return tDiv ;
"=" return tEqual ;
"(" return tOpeningParenthesis ;
")" return tClosingParenthesis ;
"\n" return tNewline ;

%%

    int main(){
        yylex() ;
        return 1 ;
    }
