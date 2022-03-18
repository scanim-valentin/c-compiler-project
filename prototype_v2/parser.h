#ifndef parser
#define parser

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

enum ASM{
    ADD = 1,
    MUL = 2,
    SOU = 3,
    DIV = 4,
    COP = 5,
    AFC = 6,
    JMP = 7,
    JMF = 8
} ; 

void arith(char* op) ;

void Parse_Affect(char * var_name, int value) ; 

#endif