VAPTH = ../util

CPPFLAGS = -I../util
CFLAGS = -c -g

OBJLIST := parserfn.o variables.o actions.o common.o

all : liblib.a

liblib.a : $(OBJLIST)
	$(AR) $(ARFLAGS) $@ $?

%.o : %.c %.h
	$(CC) $(CPPFLAGS) $(CFLAGS) $<


clean :
	rm ./*.o ./*.a -f