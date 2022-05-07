lex emulateur.l
gcc -g -Wall lex.yy.c -o emulateur.o
xxd -p -c 100000 ASM_file.asm | ./emulateur.o

