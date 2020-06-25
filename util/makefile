OBJLIST := hashmap.o linkedlist.o stack.o

CFLAGS = -c
UCFLAGS = -g

all : libutil.a

libutil.a : $(OBJLIST)
	$(AR) $(ARFLAGS) $@ $?

%.o : %.c %.h
	$(CC) $(CPPFLAGS) $(CFLAGS) $(UCFLAGS) $<

clean: 
	rm ./*.o ./*.a -f