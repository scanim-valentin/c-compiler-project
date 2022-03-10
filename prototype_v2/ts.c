#include "ts.h"

void push_TdS(char * Nom, char * Type, int Scope){
    Symbolle * S = malloc(sizeof(Symbolle)) ; 
    if(table_des_symbolles.first != NULL)
    {
        S->next = table_des_symbolles.first;
        S->offset = S->next->offset + 1 ; 
    }else{
        table_des_symbolles.last = S ; 
        S->offset = 1 ;     
    }
    table_des_symbolles.first = S ; 
    S->next = NULL ; 
    strcpy(S->Nom, Nom) ; 
    strcpy(S->Type,Type)  ; 
    S->scope = Scope ;
}

Symbolle pop_TdS(){
    if(table_des_symbolles.first != NULL)
    {
        Symbolle ret = *(table_des_symbolles.first) ; 
        free(table_des_symbolles.first) ;
        table_des_symbolles.first = ret.next ; 
        return ret ; 
    }else{
        exit(-1) ;     
    }
}

Symbolle * getSymbolle_TdS(char * Nom, int Scope){
    Symbolle * aux = table_des_symbolles.first;  
    while( aux->next != NULL ){
        if(strcmp(aux->Nom,Nom))
            return aux ;
        aux = aux->next ;  
    }
    return NULL ; 
}

Symbolle * getLastAdded_TdS(){
    return table_des_symbolles.first ;
}

void print_Symbolle(Symbolle * S){
    if(S == NULL)
        printf("{}") ;
    else
        printf("{ Name: %s | Offset: %d | Type: %s | Scope: %d }\n", S->Nom, S->offset, S->Type, S->scope) ;

}

void print_TdS(){
    Symbolle * aux = table_des_symbolles.first;
    while( aux->next != NULL ) print_Symbolle(aux);
}
