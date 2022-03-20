%{
#include <stdlib.h>
#include <stdio.h>

#include "ts.h"
void yyerror(char *s);

#define TAILLE_ZONE_MEMOIRE_VAR 1000 ;
#define TAILLE_ZONE_MEMOIRE_TEMP 1000 ;

Parse_Init("ASM_file") ;

%}
%token tDeclareInt  tDeclareConstInt tOpeningBracket tClosingBracket tWhile tElse tIf tMain  tPlus  tMinus  tMult  tDiv  tEqual  tOpeningParenthesis  tClosingParenthesis  tNewline tPointVirgule tVirgule tPrintf
%token <nb> tValueInt
%token <var> tVarName
%token <nb_exp> tValueExp
%type <nb> Assign
%type <var>  DeclarationType VarName  
%type <op> Operator
%union { int nb; char * var; double nb_exp; ASM op; }
%start PROGRAMME

%%
    PROGRAMME : tMain Bloc { Parse_End(); }
             ;

    Bloc : tOpeningBracket Corps tClosingBracket | Ligne ;

    Corps : Ligne Corps | ;

    Ligne : ContenuLigne tPointVirgule ;
    ContenuLigne : Declaration | Assignation | Printf | InstructionIfElse | InstructionWhile ;

    InstructionIfElse : tIf tOpeningParenthesis Val tClosingParenthesis Bloc InstructionElse ;
    InstructionElse : tElse Bloc | ;

    InstructionWhile : tWhile tOpeningParenthesis Val tClosingParenthesis Bloc ;

    Printf : tPrintf tOpeningParenthesis Val tClosingParenthesis ;

    Declaration : DeclarationType VarName Assign { push_TdS($2, $1,0) ; }
                ;
    DeclarationType : tDeclareConstInt { $$ = "Const Int" ; }
                    | tDeclareInt { $$ = "Int" ; }
                ;

    VarName : tVarName tVirgule VarName { $$ = $1 ;} //????
            | tVarName { $$ = $1 }
            ;

    Assignation : tVarName Assign { Parse_Affect($1,$2) ; }
                | tVarName
                ;
    Assign : tEqual Val { $$ = $2 ;}
            |
            ;

    Val : tVarName { $$ = getOffset_TdS($1) ; }
        | tValueInt { $$ = $1 ; }
        | tValueExp { $$ = $1 ; }
        | Arithmetique { $$ = $1 ; }
        ;
    Arithmetique : Val Operator Val { Parse_Arith($2); };
    Operator : tPlus { $$ = ADD ; }
            | tMinus { $$ = SUB ; }
            | tMult  { $$ = MUL ; }
            | tDiv   { $$ = DIV ; }
            ;

%%

void yyerror(char *s) { fprintf(stderr, "%s\n", s); }
int main(){
    printf("Resultat de la compilation : \n") ; 
    yyparse();
    return 0 ;
}
