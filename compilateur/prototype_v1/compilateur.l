%option noyywrap
%%

[ \t]+$? {}; /*Ignoring spaces*/
"{" printf("opening bracket detected\n")   ;
"}" printf("closing bracket detected\n")   ;
"main()" printf("main detected\n")   ;
"+" printf("addition detected\n") ; 
"-" printf("substraction detected\n") ; 
"*" printf("multiplication detected\n") ; 
"/" printf("division detected\n") ; 
"==" printf("equal comparison detected\n") ; 
"<" printf("inferior comparison detected\n") ; 
">" printf("superior comparison detected\n") ; 
"=" printf("assign detected\n") ; 
"(" printf("opening parenthesis detected\n") ; 
")" printf("closing parenthesis detected\n") ;
"," printf("comma detected\n");
"\;" printf("semicolon detected\n");
"if" printf("if detected\n");
"else" printf("else detected\n");
"while" printf("while detected\n");
"printf" printf("printf detected\n");
"int" printf("int declaration detected\n"); ;
"const" printf("const declaration detected\n") ; /*Detecting integer const declaration*/
[a-zA-Z][a-zA-Z0-9]* printf("var detected: %s \n",yytext) ; /*Detecting integers*/
[0-9]+ printf("integer detecter: %s \n",yytext) ;
[0-9]+"E"[0-9]+ printf("integer exp format detected: %s \n",yytext) ;
"\n" {} ;

%%

    int main(){
        yylex() ;
        return 1 ;
    }
