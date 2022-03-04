yacc -d prototype_v2.y
lex prototype_v2.l
gcc lex.yy.c y.tab.c -o compil
