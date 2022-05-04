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

/* 
Le choix d'utiliser une pile viens de l'impossibilite d'utiliser la table des symbolles pour cela (a part en detournant son utilisation principale a savoir relier des variables a leurs espaces memoires).
En effet c'est au niveau de la compilation que s'effectue la modifications des jumps  
*/
typedef struct debut_bloc{
    unsigned int num_instruction ;
    struct debut_bloc * next ;   
}  DebutBloc ; 

DebutBloc * PilePositionDebutBloc = NULL ;
 
void  push_debut(unsigned int num_instruction){
	DebutBloc * new_top = malloc(sizeof(DebutBloc)) ; 
	new_top->num_instruction = num_instruction ;
	new_top->next = PilePositionDebutBloc ; 
	PilePositionDebutBloc = new_top ;
}

unsigned int pop_debut(){
	DebutBloc * old_top = PilePositionDebutBloc ;
	unsigned int R = old_top->num_instruction ;  
	PilePositionDebutBloc = PilePositionDebutBloc->next ;
	free(old_top) ; 
	return R ;  
}

void print_PilePosition(){
	DebutBloc * aux = PilePositionDebutBloc ; 
	printf("PilePositions = ") ; 
	while(aux != NULL){
		if(aux->next == NULL)
			printf("%d\n",aux->num_instruction) ; 
		else
			printf("%d | ",aux->num_instruction) ;
		aux = aux->next ;  
	}
}

unsigned int taille_instruction = 4 ; 

void Parse_If() {
    int cond = pop_TdS();
    Parse_Instruction(JMF, cond, 0, 0) ;
    push_debut(ftell(file)) ; 
}

void Parse_Else() {
    Parse_Instruction(JMP, 0, 0, 0) ;
    unsigned int position_fin = ftell(file) ;
    printf("Parse_Else() : ") ; 
    print_PilePosition() ; 
    fseek(file, (pop_debut()/taille_instruction)-2, 0) ;
    fprintf(file, "%c", 1+position_fin/taille_instruction) ;
    fseek(file, 0, 2) ;    
    push_debut(position_fin) ; 
}

void Parse_EndElse() {
    unsigned int position_fin = ftell(file) ; 
    fseek(file, (pop_debut()/taille_instruction)-3, 0) ;
    fprintf(file, "%c", 1+position_fin/taille_instruction) ;
    fseek(file, 0, 2) ;
}


