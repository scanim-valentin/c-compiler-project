#ifndef ts
#define ts

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int push_TdS(char * Nom, char * Type, int Scope) ;
int pushTemp_TdS(char * Type, int Scope) ;


//On retourne l'offset
int pop_TdS() ; //Offset du dernier + depilage
int popTemp_TdS(char * Type, int Scope) ;

int getLastAdded_TdS() ; //Offset du dernier 
int getOffset_TdS(char * Nom) ; //Offset du symbole recherché 

void print_TdS() ;
void print_Symbolle() ;
void arith(char* op) ;

#endif
