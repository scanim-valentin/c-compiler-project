#ifndef ts
#define ts

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int push_TdS(char * Nom, char * Type) ;
int pushTemp_TdS(char * Type) ;


//On retourne l'offset
int pop_TdS() ; //Offset du dernier + depilage
int popTemp_TdS() ;

int getLastAdded_TdS() ; //Offset du dernier 
int getTopScope_TdS() ; // Retourne le scope du dernier symbole ajouté 
int getOffset_TdS(char * Nom) ; //Offset du symbole recherché 

void print_TdS() ;
void print_Symbolle() ;

void initBloc_TdS() ; 
void expungeBloc_TdS() ; 


#endif
