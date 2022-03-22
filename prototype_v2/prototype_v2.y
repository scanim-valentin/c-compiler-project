%{
#include <stdlib.h>
#include <stdio.h>

#include "ts.h"
#include "parser.h"

void yyerror(char *s);

#define TAILLE_ZONE_MEMOIRE_VAR 1000 ;
#define TAILLE_ZONE_MEMOIRE_TEMP 1000 ;

%}
%token tDeclareInt  tDeclareConstInt tOpeningBracket tClosingBracket tWhile tElse tIf tMain  tPlus  tMinus  tMult  tDiv  tEqual  tOpeningParenthesis  tClosingParenthesis  tNewline tPointVirgule tVirgule tPrintf
%token <nb> tValueInt
%token <var> tVarName
%token <nb_exp> tValueExp
%type <var>  DeclarationType VarName
%type <nb> Operator
%union { int nb; char * var; double nb_exp; }
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

    Declaration : DeclarationType VarName { push_TdS($2, $1,0) ; }
                | DeclarationType VarName { push_TdS($2, $1,0) ; } tEqual Val { Parse_Copy($2) ; }
                ;

    DeclarationType : tDeclareConstInt { $$ = "const_int" ; }
                    | tDeclareInt { $$ = "int" ; }
                ;

    VarName : tVarName tVirgule VarName { $$ = $1 ;} //????
            | tVarName { $$ = $1 ; }
            ;

    Assignation : tVarName tEqual Val { printf("AAAAAAAAAA\n") ; Parse_Copy($1) ; }
                ;

    Val : tVarName { Parse_Copy_To_TdS_Top($1) ; }
        | tValueInt { Parse_AllocateTemp($1, "int") ; }
        | tValueExp { Parse_AllocateTemp($1, "int") ; }
        | Arithmetique
        ;
    Arithmetique : tOpeningParenthesis Val Operator Val tClosingParenthesis { Parse_Arith($3); };
    
    Operator : tPlus { $$ = ADD ; }
            | tMinus { $$ = SOU ; }
            | tMult  { $$ = MUL ; }
            | tDiv   { $$ = DIV ; }
            ;

%%

void yyerror(char *s) { fprintf(stderr, "%s\n", s); }
int main(){
    printf("Resultat de la compilation : \n") ; 
    Parse_Init("ASM_file") ;
    yyparse();
    printf("Final TdS: \n") ;  print_TdS() ;
    return 0 ;
}
