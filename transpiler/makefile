all : lexer.l parser.y
	bison -d  parser.y
	flex lexer.l
	gcc -g -I../lib -I../util parser.tab.c lex.yy.c parserfn.o variables.o hashmap.o

clean:
	rm ./ *.o ./lex.yy.c ./parser.tab.* ./a.out