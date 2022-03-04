%option noyywrap
%%
[ \t]+$ ; /*Ignoring spaces at the end of a line*/
[ \t]+ printf(" "); /*Replacing multiple spaces with a single space*/
[a-zA-Z][a-zA-Z0-9]* printf(" var detected: %s ",yytext) ;
int[ \t]+[a-zA-Z][a-zA-Z0-9]* printf(" (int detected: %s) ",yytext) ; /*Detecting integers*/
const[ \t]+[a-zA-Z][a-zA-Z0-9]*; printf(" (const detected: %s ) ",yytext) ; 
"{" printf("beginning of section detected") ;
"}" printf("end of section detected") ;
"main()" printf("main detected") ;
"+" printf("+ operand detected") ;
"-" printf("- operand detected") ;
"*" printf("* operand detected") ;
"/" printf("/ operand detected") ;
"=" printf("= operand detected") ;
"(" printf("openning parenthesis detected") ;
")" printf("closing parenthesis detected") ;
"\n" printf("newline detected") ;
[0-9]+ printf("integer detecter: %s",yytext) ;
[0-9]+"E"[0-9]+ printf("integer exp format detected: %s",yytext) ;

%%

    int main(){
        yylex() ;
        return 1 ;
    }