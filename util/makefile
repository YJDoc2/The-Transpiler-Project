OBJLIST := hashmap.o linkedlist.o

all : libutil.a

libutil.a : $(OBJLIST)
	$(AR) $(ARFLAGS) $@ $?

clean: 
	rm ./*.o ./*.a -f