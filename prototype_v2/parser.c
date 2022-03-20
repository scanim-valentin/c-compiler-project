#include "parser.h"
#include "ts.h"
#include "string.h"

//correspondance entre ASM et la string correspondante
char* ASM_EasyReading[] = { "ADD", "MUL", "SOU", "DIV", "COP", "AFC", "JMP", "JPF", "INF", "SUP", "EQU", "PRI" } ;

FILE* file ; //Fichier qui contient les instructions codées tel qu'indiqué dans le sujet
FILE* file_easy_reading ; //Fichier qui contient les instructions sous forme de mots pour faciliter la lecture

//Création du fichier qui va accueillir le code compilé
void Parse_Init(char * name){
    file = fopen(name, "w") ;
    file_easy_reading = fopen(strcat(name,"_EasyReading"), "w") ;
    printf("Created assembly file %s\n",name) ;

}

//Fermeture du fichier après compilation
void Parse_End(){
    fclose(file) ;
    fclose(file_easy_reading) ;
    printf("Closed assembly file \n") ;

}


// Instructions à 3 opérandes
void Parse_Instruction_3(ASM Instruct, int P1, int P2, int P3){
    fwrite(&Instruct, sizeof(int), 1, file) ;
    fwrite(&P1, sizeof(int), 1, file) ;
    fwrite(&P2, sizeof(int), 1, file) ;
    fwrite(&P3, sizeof(int), 1, file) ;

    //Partie en lecture facile
    fwrite(ASM_EasyReading[Instruct], sizeof(int), 1, file_easy_reading) ;
    fwrite(&P1, sizeof(int), 1, file_easy_reading) ;
    fwrite(&P2, sizeof(int), 1, file_easy_reading) ;
    fwrite(&P3, sizeof(int), 1, file_easy_reading) ;
}

// Instructions à 2 opérandes
void Parse_Instruction_2(ASM Instruct, int P1, int P2){
    fwrite(&Instruct, sizeof(int), 1, file) ;
    fwrite(&P1, sizeof(int), 1, file) ;
    fwrite(&P2, sizeof(int), 1, file) ;

    //Partie en lecture facile
    fwrite(ASM_EasyReading[Instruct], sizeof(int), 1, file_easy_reading) ;
    fwrite(&P1, sizeof(int), 1, file_easy_reading) ;
    fwrite(&P2, sizeof(int), 1, file_easy_reading) ;
}

// Instructions à 1 opérandes
void Parse_Instruction_1(ASM Instruct, int P1){
    fwrite(&Instruct, sizeof(int), 1, file) ;
    fwrite(&P1, sizeof(int), 1, file) ;

    //Partie en lecture facile
    fwrite(ASM_EasyReading[Instruct], sizeof(int), 1, file_easy_reading) ;
    fwrite(&P1, sizeof(int), 1, file_easy_reading) ;
}

//On écrit l'instruction à partir des adresses du sommet de la pile
void Parse_Arith(ASM OP) {
    int P1 = pop_TdS() ;
    int P2 = pop_TdS() ;
    int ret = pushTemp_TdS("int", 0) ; //A changer plus tard
    Parse_Instruction_3(OP,ret,P1,P2) ;
}

void Parse_Affect(char * var_name, int value){
    int offset = getOffset_TdS(var_name) ;
    Parse_Instruction_2(AFC, offset, value) ;
}

