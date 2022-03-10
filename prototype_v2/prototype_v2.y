%{
#include <stdlib.h>
#include <stdio.h>
#include "ts.h"
void yyerror(char *s);

#define TAILLE_ZONE_MEMOIRE_VAR 1000 ;
#define TAILLE_ZONE_MEMOIRE_TEMP 1000 ;
%}
%token tDeclareInt  tDeclareConstInt tOpeningBracket tClosingBracket tWhile tElse tIf tMain  tPlus  tMinus  tMult  tDiv  tEqual  tOpeningParenthesis  tClosingParenthesis  tNewline tPointVirgule tVirgule tPrintf
%token <nb> tValueInt
%token <var> tVarName
%token <nb_exp> tValueExp
%union { int nb; char * var; double nb_exp; } 
%start PROGRAMME

/* ANCIENNE VERSION
%%
    PROGRAMME : tMain tOpeningBracket CORPS tClosingBracket
                { printf("Main trouve\n");
                }  
             ;
    CORPS : Ligne COPRS |

    Ligne : ( Declaration | Operation | Printf | Bloc) tPointVirgule

    Printf : tPrintf tOpeningParenthesis tVarName tClosingParenthesis

    Declaration : ( tDeclareConstInt | tDeclareInt ) VarDeclaration  ( | Assign)

    VarDeclaration : tVarName ( | tVirgule VarDeclaration)

    Operation : tVarName Assign

    Assign : tEqual Rval ( | Arithmetique Rval )

    Rval : tVarName | tValueInt | tValueExp

    Bloc : (|tIf CondBloc (|tElse Bloc)| tWhile CondBloc) 

    CondBloc : tOpeningParenthesis Condition tClosingParenthesis tOpeningBracket CORPS tClosingBracket
   
%%
 */

%%
    PROGRAMME : tMain Bloc
                { printf("Main trouve\n");
                }
             ;

    Bloc : tOpeningBracket Corps tClosingBracket | Ligne ;

    Corps : Ligne Corps | ;

    Ligne : ContenuLigne tPointVirgule ;
    ContenuLigne : Declaration | Assignation | Printf | InstructionIfElse | InstructionWhile ;

    InstructionIfElse : tIf tOpeningParenthesis Val tClosingParenthesis Bloc InstructionElse ;
    InstructionElse :  | tElse Bloc ;

    InstructionWhile : tWhile tOpeningParenthesis Val tClosingParenthesis Bloc ;

    Printf : tPrintf tOpeningParenthesis tVarName tClosingParenthesis ;

    Declaration : DeclarationType VarName Assign ;
    DeclarationType : tDeclareConstInt | tDeclareInt ;

    VarName : tVarName | tVarName tVirgule VarName ;

    Assignation : tVarName Assign ;

    Assign : | tEqual Val;

    Val : tVarName | tValueInt | tValueExp | Arithmetique ;
    Arithmetique : Val Operator Val ;
    Operator : tPlus | tMinus | tMult | tDiv ;

%%

void yyerror(char *s) { fprintf(stderr, "%s\n", s); }
int main(){
    printf("Resultat de la compilation : \n") ; 
    yyparse();
    return 0 ;
}
