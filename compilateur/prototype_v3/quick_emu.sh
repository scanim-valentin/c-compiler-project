lex emulateur.l
gcc -g -Wall lex.yy.c -o emulateur.o
xxd -p ASM_file.asm | ./emulateur.o
