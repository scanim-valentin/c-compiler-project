#include "parser.h"
#include "ts.h"

char binaire[30000] ; 
int end_of_file = 0;

void Parse_Arith(char* op) {

}

void Parse_Affect(char * var_name, int value){
    int offset = getOffset_TdS(var_name) ;
    binaire[end_of_file+1] = "AFC" ;
    binaire[end_of_file+3] = offset ;
    binaire[end_of_file+4] = value ;
    end_of_file += 3 ; 
}