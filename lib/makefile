VAPTH = ../util

CPPFLAGS = -I../util
CFLAGS = -c
UCFLAGS = -g

OBJLIST := parserfn.o variables.o actions.o common.o literals.o tempvar.o functions.o scope.o expressions.o forloop.o class_decl.o class_access.o filenames.o globals.o help.o

all : liblib.a

liblib.a : $(OBJLIST)
	$(AR) $(ARFLAGS) $@ $?

%.o : %.c %.h
	$(CC) $(CPPFLAGS) $(UCFLAGS) $(CFLAGS) $<


clean :
	rm ./*.o ./*.a -f