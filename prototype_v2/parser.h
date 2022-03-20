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
void Parse_Affect(char * var_name, int value) ; 

//Opérations arithmétique et comparaisons
void Parse_Arith(ASM OP) ;

#endif
