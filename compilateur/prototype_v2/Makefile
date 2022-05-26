GRM=prototype.y
LEX=prototype.l
BIN=prototype

CC=gcc
LIB_FOLDER=./source
CFLAGS=-Wall -g $(LIB_FOLDER)/*.c

OBJ=y.tab.o lex.yy.o


all: $(BIN)

%.o: %.c
	$(CC) $(CFLAGS) $(CPPFLAGS) $< -o $@

y.tab.c: $(GRM)
	yacc -d $<

lex.yy.c: $(LEX)
	flex $<

$(BIN): $(OBJ)
	$(CC) $(CFLAGS) $(CPPFLAGS) $^ -o $@

clean:
	rm -f $(OBJ) $(BIN) ./test_output/* y.tab.c y.tab.h lex.yy.c *.asm *.o

