#include "ts.h"

typedef struct symb{
    char * Nom ; 
    int offset ;
    char * Type ; 
    int scope ;
    struct symb * next ;   
} Symbolle ; 

typedef struct{
    Symbolle * first ; 
    Symbolle * last ; 
    int taille ; 
} TdS ; 

TdS table_des_symbolles = { NULL, NULL } ; 
int Profondeur = 0;

void push_TdS(char * Nom, char * Type, int Scope){
    Symbolle * S = malloc(sizeof(Symbolle)) ; 
    S->next = table_des_symbolles.first;
    if(table_des_symbolles.first != NULL)
    {
        S->offset = S->next->offset + 1 ; 
    }else{
        table_des_symbolles.last = S ; 
        S->offset = 1 ;     
    }
    table_des_symbolles.first = S ;  
    table_des_symbolles.taille++ ; 
    S->Nom = strdup(Nom) ; 
    S->Type = strdup(Type)  ; 
    S->scope = Scope ;

}

int pop_TdS(){
    if(table_des_symbolles.first != NULL)
    {
        Symbolle ret = *(table_des_symbolles.first) ; 
        free(table_des_symbolles.first) ;
        table_des_symbolles.first = ret.next ; 
        return ret.offset ; 
    }else{
        exit(-1) ; //Gros problème donc erreur    
    }
}

int getOffset_TdS(char * Nom){
    Symbolle * aux = table_des_symbolles.first;  
    while( aux->next != NULL ){
        if(strcmp(aux->Nom,Nom))
            return aux->offset ;
        aux = aux->next ;  
    }
    return -1 ; 
}

int getLastAdded_TdS(){
    return table_des_symbolles.first->offset ;
}

void print_Symbolle(Symbolle * S){
    if(S == NULL)
        printf("{}") ;
    else
        printf("{ Name: %s | Offset: %d | Type: %s | Scope: %d }\n", S->Nom, S->offset, S->Type, S->scope) ;

}

void print_TdS(){
    printf("print\n");
    Symbolle * aux = table_des_symbolles.first;
    while( aux != NULL ){
        print_Symbolle(aux);
        aux = aux->next ; 
    }
}