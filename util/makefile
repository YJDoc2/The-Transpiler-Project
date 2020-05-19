OBJLIST := hashmap.o linkedlist.o stack.o

CFLAGS = -c -g

all : libutil.a

libutil.a : $(OBJLIST)
	$(AR) $(ARFLAGS) $@ $?

%.o : %.c %.h
	$(CC) $(CPPFLAGS) $(CFLAGS) $<

clean: 
	rm ./*.o ./*.a -f