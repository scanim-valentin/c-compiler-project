#include "../include/parser.h"
#include "../include/ts.h"
#include "string.h"


FILE* file ; //Fichier qui contient les instructions codées tel qu'indiqué dans le sujet

//Création du fichier qui va accueillir le code compilé
void Parse_Init(char * name){
    char buff_name[50];
    strcpy(buff_name,name) ;
    file = fopen(strcat(buff_name,".asm"), "wb") ;
    strcpy(buff_name,name) ;
    printf("Created assembly file %s\n",name) ;
}

//Fermeture du fichier après compilation
void Parse_End(){
    fclose(file) ;
    printf("Closed assembly file \n") ;
}


// Instructions à 1 / 2 / 3 opérandes (avec bourage de 0 si besoin)
void Parse_Instruction(ASM Instruct, int P1, int P2, int P3){
    fprintf(file, "%c%c%c%c", Instruct, P1, P2, P3) ;
}

//On écrit l'instruction à partir des adresses du sommet de la pile
void Parse_Arith(ASM OP) {
    int P1 = popTemp_TdS() ;
    int P2 = popTemp_TdS() ;
    int ret = pushTemp_TdS("int") ; //A changer plus tard
    Parse_Instruction(OP,ret,P2,P1) ; // !! P2 - P1
}

//Gestion des blocs et du scope



void Parse_Copy_To_TdS_Top(char * var) {
    int source = getOffset_TdS(var) ;
    int dest = pushTemp_TdS("int");
    Parse_Instruction(COP, dest, source, 0) ; 
}

int Parse_getValue(char * var) {
    int source = getOffset_TdS(var) ; 
}

void Parse_AllocateTemp(int value, char * type){
    int addr = pushTemp_TdS(type) ;
    Parse_Instruction(AFC, addr, value, 0) ;
}

void Parse_Copy(char * var_dest){
    int source = popTemp_TdS() ;
    int dest = getOffset_TdS(var_dest) ;
    Parse_Instruction(COP, dest, source, 0) ;
}

void Parse_printf() {
    int source = popTemp_TdS() ;
    Parse_Instruction(PRI, source, 0, 0) ;
}

//Gestion du IF

unsigned int position_debut ;

unsigned int taille_instruction = 4 ; 

void Parse_If() {
    int cond = pop_TdS();
    Parse_Instruction(JMF, cond, 0, 0) ;
    position_debut = ftell(file) ; 
}

void Parse_Else() {
    Parse_Instruction(JMP, 0, 0, 0) ;
    unsigned int position_fin = ftell(file) ; 
    fseek(file, position_debut-2, 0) ;
    fprintf(file, "%c", 1+position_fin/taille_instruction) ;
    fseek(file, 0, 2) ;    
    position_debut = position_fin ; 
}

void Parse_EndElse() {
    unsigned int position_fin = ftell(file) ; 
    fseek(file, position_debut-3, 0) ;
    fprintf(file, "%c", 1+position_fin/taille_instruction) ;
    fseek(file, 0, 2) ;
}


