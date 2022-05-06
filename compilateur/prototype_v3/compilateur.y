%{
#include <stdlib.h>
#include <stdio.h>

#include "include/ts.h"
#include "include/parser.h"

void yyerror(char *s);

#define TAILLE_ZONE_MEMOIRE_VAR 1000 ;
#define TAILLE_ZONE_MEMOIRE_TEMP 1000 ;

%}
%token tDeclareInt  tDeclareConstInt tOpeningBracket tClosingBracket tWhile tElse tIf tMain  tPlus  tMinus  tMult  tDiv  tSup tInf tEqual tAssign tOpeningParenthesis  tClosingParenthesis  tNewline tPointVirgule tVirgule tPrintf
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

    Bloc : tOpeningBracket { initBloc_TdS() ;} Corps tClosingBracket { expungeBloc_TdS() ;} ;

    Corps : Ligne Corps | BlocBased {printf("Post Bloc Corps\n");}  Corps | ;

    Ligne : ContenuLigne tPointVirgule ;
    
    BlocBased : Bloc | InstructionIfElse | InstructionWhile ; 
    
    ContenuLigne : Declaration | Assignation | Printf ;

    InstructionIfElse : tIf tOpeningParenthesis Val tClosingParenthesis { Parse_If() ; } Bloc { Parse_Else() ; } InstructionElse { Parse_EndElse() ; };
    
    InstructionElse : tElse {printf("tElse\n");}  Bloc {printf("Post Bloc Instruction Else\n");}  | ;

    InstructionWhile : tWhile { Parse_InitWhile() ; } tOpeningParenthesis Val tClosingParenthesis { Parse_While() ; } Bloc { Parse_EndWhile() ; };

    Printf : tPrintf tOpeningParenthesis Val tClosingParenthesis { Parse_printf() ; } 
            ;

    Declaration : DeclarationType VarName { push_TdS($2, $1) ; }
                | DeclarationType VarName { push_TdS($2, $1) ; } tAssign Val { Parse_Copy($2) ; }
                ;

    DeclarationType : tDeclareConstInt { $$ = "const_int" ; }
                    | tDeclareInt { $$ = "int" ; }
                ;

    VarName : tVarName tVirgule VarName { $$ = $1 ;}
            | tVarName { $$ = $1 ; }
            ;

    Assignation : tVarName tAssign Val { Parse_Copy($1) ; }
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
            | tEqual { $$ = EQU ; }
            | tSup   { $$ = SUP ; }
            | tInf   { $$ = INF ; }
            ;

%%

void yyerror(char *s) { fprintf(stderr, "%s\n", s); printf("error TdS: \n") ;  print_TdS() ; exit(-1); }

int main(){
    // On crée le fichier 
    Parse_Init("ASM_file") ;
    yyparse();
    printf("Final TdS: \n") ;  print_TdS() ;
    return 0 ;
}
