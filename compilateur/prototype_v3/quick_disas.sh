lex desassembleur.l
gcc -g -Wall lex.yy.c -o desassembleur.o
xxd -p ASM_file.asm | ./desassembleur.o
