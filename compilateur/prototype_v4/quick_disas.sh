lex desassembleur.l
gcc -g -Wall lex.yy.c -o desassembleur.o
xxd -p -c 100000 ASM_file.asm | ./desassembleur.o
