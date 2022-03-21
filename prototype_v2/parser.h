#ifndef parser
#define parser

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

//Code des instruction tel qu'indiqué dans le sujet
typedef enum{
    ADD = 1,
    MUL = 2,
    SOU = 3,
    DIV = 4,
    COP = 5,
    AFC = 6,
    JMP = 7,
    JMF = 8,
    INF = 9,
    SUP = 10,
    EQU = 11,
    PRI = 12
} ASM;

//Affection simple (valeur -> memoire)
void Parse_Affect(char * var_name, int var) ;

//Affection simple (valeur -> memoire)
void Parse_Copy(char * var_name) ;

//Opérations arithmétique et comparaisons
void Parse_Arith(ASM OP) ;

void Parse_AllocateTemp(int value, char * type) ;


void Parse_Copy_To_TdS_Top(char * var) ;

void Parse_Init(char * name);

void Parse_End();

#endif
