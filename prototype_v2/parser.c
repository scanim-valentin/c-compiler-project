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
    char buff_name[50];
    strcpy(buff_name,name) ;
    file_easy_reading = fopen(strcat(buff_name,"_EasyReading"), "w") ;
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
    fprintf(file_easy_reading, "%s %d %d %d\n", ASM_EasyReading[Instruct-1], P1, P2, P3) ;
}

// Instructions à 2 opérandes
void Parse_Instruction_2(ASM Instruct, int P1, int P2){

    fwrite(&Instruct, sizeof(int), 1, file) ;
    fwrite(&P1, sizeof(int), 1, file) ;
    fwrite(&P2, sizeof(int), 1, file) ;

    //Partie en lecture facile
    fprintf(file_easy_reading, "%s %d %d\n", ASM_EasyReading[Instruct-1], P1, P2) ;
}

// Instructions à 1 opérandes
void Parse_Instruction_1(ASM Instruct, int P1){

    fwrite(&Instruct, sizeof(int), 1, file) ;
    fwrite(&P1, sizeof(int), 1, file) ;
    //Partie en lecture facile
    fprintf(file_easy_reading, "%s %d\n", ASM_EasyReading[Instruct-1], P1) ;
}

//On écrit l'instruction à partir des adresses du sommet de la pile
void Parse_Arith(ASM OP) {
    int P1 = popTemp_TdS() ;
    int P2 = popTemp_TdS() ;
    int ret = pushTemp_TdS("int", 0) ; //A changer plus tard
    Parse_Instruction_3(OP,ret,P2,P1) ; // !! P2 - P1
}

void Parse_Copy_To_TdS_Top(char * var) {
    int source = getOffset_TdS(var) ;
    int dest = pushTemp_TdS("int",0);
    Parse_Instruction_2(COP, dest, source) ;
}

void Parse_AllocateTemp(int value, char * type){
    int addr = pushTemp_TdS(type, 0) ;
    Parse_Instruction_2(AFC, addr, value) ;
    print_TdS() ;
}

void Parse_Copy(char * var_dest){
    int source = popTemp_TdS() ;
    int dest = getOffset_TdS(var_dest) ;
    Parse_Instruction_2(COP, dest, source) ;

    printf("copy %s %d %d \n", var_dest, source, dest) ;  print_TdS() ;
}

