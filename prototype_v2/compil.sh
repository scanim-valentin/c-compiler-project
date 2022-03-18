yacc -d prototype_v2.y
lex prototype_v2.l
gcc -g -Wall lex.yy.c y.tab.c ts.c -o compil
