#include <stdlib.h>
#include <string.h>

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
void push_TdS(char * Nom, char * Type, int Scope) ; 
Symbolle pop_TdS() ;
Symbolle * getLastAdded_TdS() ;
Symbolle * getSymbolle_TdS(char * Nom, int Scope) ;  
