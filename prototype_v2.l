%option noyywrap
%%
[ \t]+$ {}; /*Ignoring spaces at the end of a line*/
[ \t]+ return 0; /*Replacing multiple spaces with a single space*/
[a-zA-Z][a-zA-Z0-9]* {return yytext ;} /*detecting variables*/
int[ \t]+[a-zA-Z][a-zA-Z0-9]* return tINT ; /*Detecting integers*/
const[ \t]+[a-zA-Z][a-zA-Z0-9]*; return 3 ; 
"{" return 4 ;
"}" return 5 ;
"main()" return 6 ;
"+" return 7 ;
"-" return 8 ;
"*" return 9;
"/" return 10;
"=" return 11;
"(" return 12;
")" return 13;
"\n" return 14 ;
[0-9]+ { yylval.val = atoi(yytext) ; return  ;};
[0-9]+E[0-9]+ { return atof(yytext) ;} ;
%%

    int main(){
        yylex() ;
        return 1 ;
    }