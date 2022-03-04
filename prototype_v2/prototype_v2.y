%{
#include <stdlib.h>
#include <stdio.h>
void yyerror(char *s);
%}
%token tDeclareInt  tDeclareConstInt tOpeningBracket tClosingBracket  tMain  tPlus  tMinus  tMult  tDiv  tEqual  tOpeningParenthesis  tClosingParenthesis  tNewline tPointVirgule
%token <nb> tValueInt
%token <var> tVarName
%token <nb_exp> tValueExp
%union { int nb; char * var; double nb_exp; } 
%start PROGRAMME

%%
    PROGRAMME : tMain tOpeningBracket CORPS tClosingBracket
                { printf("Main trouve\n");
                }  
             ;
    CORPS : tDeclareInt tVarName tPointVirgule CORPS | tDeclareInt tVarName tPointVirgule
            { printf("Declaration trouve\n");
              printf($2);
              printf("\n");
            } 
        ;
    



%%
void yyerror(char *s) { fprintf(stderr, "%s\n", s); }
int main(){
    printf("Resultat de la compilation : \n") ; 
    yyparse();
    return 0 ;
}