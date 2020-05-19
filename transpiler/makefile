VPATH = ../lib ../util

CPPFLAGS = -I../util -I../lib
CFLAGS = -c -g

all : ttp

ttp : parser.o lexer.o libutil liblib
	cp ../lib/liblib.a ./
	cp ../util/libutil.a ./
	$(CC) $(CPPFLAGS) lexer.o parser.o -L. liblib.a libutil.a -ottp

libutil :
	cd ../util && make

liblib :
	cd ../lib && make

lexer.o : lexer.l
	flex -t lexer.l > lexer.c
	$(CC) $(CPPFLAGS) $(CFLAGS) lexer.c

parser.o: parser.y
	bison -d parser.y
	mv ./parser.tab.c ./parser.c
	mv ./parser.tab.h ./parser.h
	$(CC) $(CPPFLAGS) $(CFLAGS) parser.c

clean:
	rm ./*.o ./ttp -f
reset:
	rm ./*.o  ./*.a ./lexer.c ./parser.c ./parser.h ./ttp -f