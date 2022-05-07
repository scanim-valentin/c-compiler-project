#ifndef parser
#define parser

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

//Code des instructions tel qu'indique dans le sujet
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

//Affectation directe (remplissage du contenu d'une case memoire par une valeur brute)
void Parse_Affect(char * var_name, int var) ;

//Affectation indirecte (copie du contenu d'une case memoire dans une autre)
void Parse_Copy(char * var_name) ;

//Operations arithmetiques et comparaisons
void Parse_Arith(ASM OP) ;

// Allocation d'une variable temporaire
void Parse_AllocateTemp(int value, char * type) ;

// Permet de faire remonter une variable au sommet de la table des symboles
void Parse_Copy_To_TdS_Top(char * var) ;

// Creation du fichier qui contiendra le binaire du programme
void Parse_Init(char * name);

// Fermeture du fichier qui contient le binaire du programme
void Parse_End();

// Affiche dans la sortie standard la reference indique
void Parse_printf();

//// Gestion du referencement / dereferencement (pointeurs)
// Augmente le niveau de referencement
void Parse_Unref();

// Diminue le niveau de referencement
void Parse_Ref();

// Applique le niveau de referencement lors de l'evaluation du symboles
void Parse_ApplyRef() ;

//// Gestion du IF :
// Ecrit le jump conditionnel avec un numero d'instruction cible a completer et retient le numero de l'instruction courante
void Parse_If() ;

// Ecrit le jump avec un numero d'instruction cible a completer et complete le jump conditionnel du IF a partir du numero de l'instruction courante 
void Parse_Else() ;

//Complete le jump conditionnel du ELSE a partir du numero de l'instruction courante
void Parse_EndElse() ;

////Gestion du WHILE :

// Maneuvre qui ne parse rien mais qui push le numero d'instruction AVANT la condition (afin de la reevaluer ulterieurement)
void Parse_InitWhile() ;

// Ecrit le jump avec un numero d'instruction cible a completer et complete le jump conditionnel du WHILE a partir du numero de l'instruction courante
void Parse_While() ;

// Ecrit le jump avec le numero d'instruction conduisant au jump conditionnel du WHILE et complete le jump conditionnel du WHILE a partir du numero de l'instruction courante
void Parse_EndWhile() ;

////Gestion de la profondeur :
//Incremente la profondeur
void Parse_InitBloc() ;

//Vide la table des symboles locaux pour le bloc et diminue la profondeur (scope)
void Parse_EndBloc() ; 

#endif
