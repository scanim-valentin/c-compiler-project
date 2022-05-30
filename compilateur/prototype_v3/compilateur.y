%{
#include <stdlib.h>
#include <stdio.h>
#include "include/ts.h"
#include "include/parser.h"
extern int yylineno;
void yyerror(char *s);
%}
%token tDeclareInt  tDeclareConstInt tOpeningBracket tClosingBracket tWhile tElse tIf tMain  tPlus  tMinus  tStar  tDiv  tSup tInf tEqual tAssign tEsp tOpeningParenthesis  tClosingParenthesis  tNewline tPointVirgule tVirgule tPrintf
%token <nb> tValueInt
%token <var> tVarName
%token <nb_exp> tValueExp
%type <var>  DeclarationType VarName
%union { int nb; char * var; double nb_exp; }
%start PROGRAMME

%%
    PROGRAMME : tMain Bloc { Parse_End(); }
             ;

    Bloc : tOpeningBracket { initBloc_TdS() ;} Corps tClosingBracket { expungeBloc_TdS() ;} ;

    Corps : Ligne Corps | BlocBased  Corps | ;

    Ligne : ContenuLigne tPointVirgule ;
    
    BlocBased : Bloc | InstructionIfElse | InstructionWhile ; 
    
    ContenuLigne : Declaration | Assignation | Printf ;

    InstructionIfElse : tIf tOpeningParenthesis Prio0Arith tClosingParenthesis { Parse_If() ; } Bloc { Parse_Else() ; } InstructionElse { Parse_EndElse() ; };
    
    InstructionElse : tElse  Bloc  | ;

    InstructionWhile : tWhile { Parse_InitWhile() ; } tOpeningParenthesis Prio0Arith tClosingParenthesis { Parse_While() ; } Bloc { Parse_EndWhile() ; };

    Printf : tPrintf tOpeningParenthesis Prio0Arith tClosingParenthesis { Parse_printf() ; }
            ;

    Declaration : DeclarationType VarName { push_TdS($2, $1) ; }
                | DeclarationType VarName { push_TdS($2, $1) ; } tAssign Prio0Arith { Parse_Copy($2) ; }
                ;

    DeclarationType : tDeclareConstInt { $$ = "const_int" ; }
                    | tDeclareInt { $$ = "int" ; }
                    ;

    VarName : tVarName tVirgule VarName { $$ = $1 ;}
            | tVarName { $$ = $1 ; }
            ;

    Assignation : tVarName tAssign Prio0Arith { Parse_Copy($1) ; }
                ;

    // Comparaison 
    Prio0Arith : Prio1Arith tSup Prio1Arith { Parse_Arith(SUP) ; }
                 | Prio1Arith tInf Prio1Arith { Parse_Arith(INF) ; }
                 | Prio1Arith tEqual Prio1Arith { Parse_Arith(EQU) ; }
                 | Prio1Arith ;

    // Addition et Soustraction
    Prio1Arith : Prio1Arith tPlus Prio2Arith { Parse_Arith(ADD) ; }
                 | Prio1Arith tMinus Prio2Arith { Parse_Arith(SOU) ; }
                 | Prio2Arith ;
    
    // Division et Multiplication
    Prio2Arith : Prio2Arith tDiv Prio3Arith { Parse_Arith(DIV) ; }
           | Prio2Arith tStar Prio3Arith { Parse_Arith(MUL) ; }
           | Prio3Arith ;

    // Referencement et dereferencement
    Prio3Arith : tStar { Parse_Unref() ; } Prio3Arith
           | tEsp  { Parse_Ref() ; } Prio3Arith
           | Val { Parse_ApplyRef() ; }
           | tOpeningParenthesis Prio0Arith tClosingParenthesis { Parse_ApplyRef() ; } ;

    // A l'issue de cette regle, la variable concerne (temporaire ou non) se trouve au sommet de la table des symboles
    Val : tVarName { Parse_Copy_To_TdS_Top($1) ; }
        | tValueInt { Parse_AllocateTemp($1, "int") ; }
        | tValueExp { Parse_AllocateTemp($1, "int") ; }
        ;

%%

void yyerror(char *s) {
    fprintf(stderr,  "line %d: %s\n",  yylineno, s);
    exit(-1);
}

int main(){
    // On crée le fichier 
    Parse_Init("ASM_file") ;
    yyparse();
    printf("Final TdS: \n") ;  print_TdS() ;
    return 0 ;
}
