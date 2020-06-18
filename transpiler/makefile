VPATH = ../lib ../util

CPPFLAGS = -I../util -I../lib
CFLAGS = -c -g

all : ttp

ttp : parser.o lexer.o preparser.o prelexer.o libutil liblib 
	cp ../lib/liblib.a ./
	cp ../util/libutil.a ./
	$(CC) $(CPPFLAGS) prelexer.o preparser.o lexer.o parser.o -L. liblib.a libutil.a -ottp

libutil :
	cd ../util && make

liblib :
	cd ../lib && make

lexer.o : lexer.l
	flex -t lexer.l > lexer.c
	$(CC) $(CPPFLAGS) $(CFLAGS) lexer.c

prelexer.o : prelexer.l
	flex -t prelexer.l > prelexer.c
	$(CC) $(CPPFLAGS) $(CFLAGS) prelexer.c

parser.o: parser.y
	bison -d parser.y
	mv ./parser.tab.c ./parser.c
	mv ./parser.tab.h ./parser.h
	$(CC) $(CPPFLAGS) $(CFLAGS) parser.c

preparser.o : preparser.y
	bison -d preparser.y
	mv ./preparser.tab.c ./preparser.c
	mv ./preparser.tab.h ./preparser.h
	$(CC) $(CPPFLAGS) $(CFLAGS) preparser.c

memcheck : ttp
	valgrind --leak-check=full --show-leak-kinds=all  ./ttp

clean:
	rm ./*.o ./ttp ./a.out -f
reset:
	rm ./*.o  ./*.a ./lexer.c ./parser.c ./parser.h ./prelexer.c ./preparser.h ./preparser.c ./ttp -f