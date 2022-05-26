yacc -d compilateur.y
lex compilateur.l
gcc -g -Wall lex.yy.c y.tab.c ./source/*.c -o compilateur.o
