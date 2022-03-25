yacc -d prototype.y
lex prototype.l
gcc -g -Wall lex.yy.c y.tab.c ./source/*.c -o prototype
