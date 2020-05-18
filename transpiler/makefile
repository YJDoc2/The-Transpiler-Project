VPATH = ../lib ../util

CPPFLAGS = -I../util -I../lib
CFLAGS = -c

all : tpp

tpp : lexer.c parser.o libutil.a liblib.a
	cp ../lib/liblib.a ./
	cp ../util/libutil.a ./
	$(CC) $(CPPFLAGS) lexer.c parser.o -L. liblib.a libutil.a -ottp

libutil.a :
	cd ../util && make

liblib.a :
	cd ../lib && make

parser.o: parser.y
	bison -d parser.y
	mv ./parser.tab.c ./parser.c
	mv ./parser.tab.h ./parser.h
	$(CC) $(CPPFLAGS) $(CFLAGS) parser.c

clean:
	rm ./*.o ./ttp -f
reset:
	rm ./*.o  ./*.a ./lexer.c ./parser.c ./parser.h ./ttp -f