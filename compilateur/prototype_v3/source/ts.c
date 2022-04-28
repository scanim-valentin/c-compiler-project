#include "../include/ts.h"

typedef struct symb{
    char * Nom ; 
    int offset ;
    char * Type ; 
    int scope ;
    struct symb * next ;   
} Symbolle ; 

typedef struct{
    Symbolle * top ;
    Symbolle * bottom ;
    int taille ; 
} TdS ; 

TdS table_des_symbolles = { NULL, NULL } ; 
int Profondeur = 0;
char nb_variables_temporaires = 0;

int push_TdS(char * Nom, char * Type, int Scope){
    Symbolle * S = malloc(sizeof(Symbolle)) ; 
    S->next = table_des_symbolles.top;
    if(table_des_symbolles.top != NULL)
    {
        S->offset = S->next->offset + 1 ; 
    }else{
        table_des_symbolles.bottom = S ;
        S->offset = 1 ;     
    }
    table_des_symbolles.top = S ;
    table_des_symbolles.taille++ ; 
    S->Nom = strdup(Nom) ; 
    S->Type = strdup(Type)  ; 
    S->scope = Scope ;

    return S->offset ;

}

int pushTemp_TdS(char * Type, int Scope){
    nb_variables_temporaires ++ ;
    char nom[] = "temp_0" ;
    nom[5] = (char)(48 + nb_variables_temporaires);
    return push_TdS(nom, Type, Scope) ;
}

int pop_TdS(){
    if(table_des_symbolles.top != NULL)
    {
        Symbolle ret = *(table_des_symbolles.top) ;
        free(table_des_symbolles.top) ;
        table_des_symbolles.top = ret.next ;
        return ret.offset ; 
    }else{
        exit(-1) ; //Gros problème donc erreur    
    }
}

int popTemp_TdS(){
    nb_variables_temporaires -- ;
    return pop_TdS() ;
}

Symbolle * getSymbolle_TdS(char * Nom){
    Symbolle * aux = table_des_symbolles.top;
    while( aux != NULL ){
        if(!strcmp(aux->Nom,Nom))
            return aux ;
        aux = aux->next ;
    }
    return NULL ;
}

int getOffset_TdS(char * Nom){
    Symbolle * symb = getSymbolle_TdS(Nom) ;
    return symb != NULL ? symb->offset : -1 ;
}

int getLastAdded_TdS(){
    return table_des_symbolles.top->offset ;
}

void print_Symbolle(Symbolle * S){
    if(S == NULL)
        printf("{}") ;
    else
        printf("{ Name: %s | Offset: %d | Type: %s | Scope: %d }\n", S->Nom, S->offset, S->Type, S->scope) ;

}

void print_TdS(){
    printf("print\n");
    Symbolle * aux = table_des_symbolles.top;
    while( aux != NULL ){
        print_Symbolle(aux);
        aux = aux->next ; 
    }
}
