VAPTH = ../util

CPPFLAGS = -I../util

OBJLIST := parserfn.o variables.o

all : liblib.a

liblib.a : $(OBJLIST)
	$(AR) $(ARFLAGS) $@ $?

clean :
	rm ./*.o ./*.a -f