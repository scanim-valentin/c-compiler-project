%{
#include <stdlib.h>
#include <stdio.h>
int line_nb = 0 ; 
unsigned int getElementFromInst(int place){
	const char destStr[3] = { yytext[2*place], yytext[2*place+1], '\0' } ; 
	return (unsigned int)strtol(destStr, NULL, 16) ;		 
}
void printInst(char * inst, char nb_param){
	line_nb++ ; 
	unsigned int dest = getElementFromInst(1) ;
	unsigned int a = getElementFromInst(2) ;
	unsigned int b = getElementFromInst(3) ;
	switch(nb_param) {
		case 1 : 
			printf("%x | %s %x \n", line_nb, inst, dest) ;
			break ; 
		
		case 2 : 
			printf("%x | %s %x %x \n", line_nb, inst, dest, a) ;
			break ; 
		
		case 3 : 
			printf("%x | %s %x %x %x\n", line_nb, inst, dest, a, b) ;
			break ; 
		default :
			printf("Unreckognised number of parameters: %d\n",nb_param) ;	
	} 
}
%}
%option noyywrap
%%
[0-9a-fA-F]{8} {
		const char op_str[3] = { yytext[0] , yytext[1] , '\0' } ; 
		unsigned int op = (unsigned int)strtol(op_str, NULL, 16) ;

		switch(op){
			case 1:
				printInst("ADD",3) ; 
				
				break;
			
			case 2:
				printInst("MUL",3) ; 
				
				break;
			
			case 3:
				printInst("SOU",3) ; 
				
				break;
			
			case 4:
				printInst("DIV",3) ; 
				
				break;
			
			case 5:
				printInst("COP",2) ; 
				
				break;
			
			case 6:
				printInst("AFC",2) ; 
				
				break;
			
			case 7:
				printInst("JMP",1) ; 
				
				break;
			case 8:
				printInst("JMF",2) ; 
				
				break;
			case 9:
				printInst("INF",3) ; 
				
				break;
			case 10:
				printInst("SUP",3) ; 
				
				break;
			case 11:
				printInst("EQU",3) ; 
				
				break;
			case 12:
				printInst("PRI",1) ; 
				
				break;
			
			default:
				printf("Unreckognised operation code: %d\n",op) ; 
				break;
				
		}	
}	

%%




int main(void) {
	yylex();
	return 0;
}
