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

// Allocation d'une variable temporaire
void Parse_AllocateTemp(int value, char * type) ;

// Permet de faire remonter une variable au sommet de la table des symboles
void Parse_Copy_To_TdS_Top(char * var) ;

// Creation du fichier qui contiendra le binaire du programme
void Parse_Init(char * name);

// Fermeture du fichier qui contient le binaire du programme
void Parse_End();

// PRI
void Parse_printf();

//// Gestion du IF :
// Ecrit le jump conditionnel avec un numero d'instruction cible a completer et retient le numero de l'instruction courante
void Parse_If() ;

// Ecrit le jump avec un numero d'instruction cible a completer et complete le jump conditionnel du IF a partir du numero de l'instruction courante 
void Parse_Else() ;

//Complete le jump conditionnel du ELSE a partir du numero de l'instruction courante
void Parse_EndElse() ;

void Parse_InitBloc() ;

//Vide la table des symboles locaux pour le bloc et diminue la profondeur (scope)
void Parse_EndBloc() ; 
#endif
