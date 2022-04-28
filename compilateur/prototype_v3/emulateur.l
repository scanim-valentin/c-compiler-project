%{
#include <stdlib.h>
#include <stdio.h>
#define MEM_SIZE 255

unsigned int line_nb = 0 ; 
char data_mem[MEM_SIZE] ; 
/*
NOTE : Pour les jumps j'ai essaye de directement changer la tete de lecture du fichier yyin avec fseek au court de l'analyse mais ça a echoue
*/
char * inst_mem[MEM_SIZE] ;

unsigned int currentInst ; //Correpond a la position de la tete de lecture
unsigned int getElementFromInst(int place){
	const char destStr[3] = { inst_mem[currentInst][2*place], inst_mem[currentInst][2*place+1], '\0' } ; 
	return (unsigned int)strtol(destStr, NULL, 16) ;		 
}
%}
%option noyywrap
%%

[0-9a-fA-F]{8} {
		strcpy(inst_mem[line_nb],yytext) ; 
		line_nb++;	
}	

%%

int main(void) {
	// On copie d'abort les instructions dans la memoire d'instruction
	char end[9] = "00000000" ;
	for(int i = 0 ; i < MEM_SIZE ; i++){
		inst_mem[i] = malloc(sizeof(char)*9) ; 
		
		strcpy(inst_mem[i],end) ; 
	}
	yylex();
	// Execution
	for(unsigned int i = 0 ; i < MEM_SIZE ; i++){
		currentInst = i ;  
		//printf("i = %d | s = %s \n",i,inst_mem[currentInst]);
		const char op_str[3] = { inst_mem[currentInst][0] , inst_mem[currentInst][1] , '\0' } ; 
		unsigned int op = (unsigned int)strtol(op_str, NULL, 16) ;
		
		switch(op){
		
			case 0:
				i=MEM_SIZE ; 
			case 1:
					 
				data_mem[getElementFromInst(1)] = data_mem[getElementFromInst(2)] + data_mem[getElementFromInst(3)] ;
				break;
			
			case 2:
				data_mem[getElementFromInst(1)] = data_mem[getElementFromInst(2)] * data_mem[getElementFromInst(3)] ;
				break;
			
			case 3:
				data_mem[getElementFromInst(1)] = data_mem[getElementFromInst(2)] - data_mem[getElementFromInst(3)] ;
				break;
			
			case 4:
				data_mem[getElementFromInst(1)] = data_mem[getElementFromInst(2)] / data_mem[getElementFromInst(3)] ;
				
				break;
			
			case 5:
				data_mem[getElementFromInst(1)] = data_mem[getElementFromInst(2)] ; 
				
				break;
			
			case 6:
				data_mem[getElementFromInst(1)] = getElementFromInst(2) ; 
				
				break;
			
			case 7:
				// -2 car : (1) parser.c part de 1 dans le comptage des lignes (2) i++ dans le for
				i = getElementFromInst(1)-2 ; 
				break;
			case 8:
				if(data_mem[getElementFromInst(1)] == 0) {
					i=getElementFromInst(2)-2 ;	
				}
				break;
			case 9:
				data_mem[getElementFromInst(1)] = (data_mem[getElementFromInst(2)] < data_mem[getElementFromInst(3)]) ;
				
				break;
			case 10:
				data_mem[getElementFromInst(1)] = (data_mem[getElementFromInst(2)] > data_mem[getElementFromInst(3)]) ;
				
				break;
			case 11:
				data_mem[getElementFromInst(1)] = (data_mem[getElementFromInst(2)] == data_mem[getElementFromInst(3)]) ;
				
				break;
			case 12:
				printf("%d\n",data_mem[getElementFromInst(1)]) ; 
				break;
			
			default:
				printf("Unreckognised operation code: %d\n",op) ; 
				break;
				
		}
	}
	
	return 0;
}
