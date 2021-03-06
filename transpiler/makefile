VPATH = ../lib ../util

CPPFLAGS = -I../util -I../lib
CFLAGS = -c
UCFLAGS = -g

all : ttp

ttp : parser.o lexer.o preparser.o prelexer.o libutil liblib 
	cp ../lib/liblib.a ./
	cp ../util/libutil.a ./
	$(CC) $(CPPFLAGS) $(UCFLAGS) prelexer.o preparser.o lexer.o parser.o -L. liblib.a libutil.a -ottp

libutil :
	cd ../util && make

liblib :
	cd ../lib && make

lexer.o : lexer.l
ifeq ($(UCFLAGS),-g)
	flex -st lexer.l > lexer.c
endif
	$(CC) $(CPPFLAGS) $(CFLAGS) $(UCFLAGS) lexer.c

prelexer.o : prelexer.l
ifeq ($(UCFLAGS),-g)
	flex -st prelexer.l > prelexer.c
endif
	$(CC) $(CPPFLAGS) $(CFLAGS) $(UCFLAGS) prelexer.c

parser.o: parser.y
ifeq ($(UCFLAGS),-g)
	bison -dv parser.y
	mv ./parser.tab.c ./parser.c
	mv ./parser.tab.h ./parser.h
endif
	$(CC) $(CPPFLAGS) $(CFLAGS) $(UCFLAGS) parser.c

preparser.o : preparser.y
ifeq ($(UCFLAGS),-g)
	bison -d preparser.y
	mv ./preparser.tab.c ./preparser.c
	mv ./preparser.tab.h ./preparser.h
endif
	$(CC) $(CPPFLAGS) $(CFLAGS) $(UCFLAGS) preparser.c

memcheck : ttp
	valgrind --leak-check=full --show-leak-kinds=all  ./ttp ./test.ttp

clean:
	rm ./*.o ./ttp ./a.out -f
reset:
	rm ./*.o  ./*.a ./lexer.c ./parser.c ./parser.h ./prelexer.c ./preparser.h ./preparser.c ./ttp -f