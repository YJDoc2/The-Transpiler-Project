.PHONY : lib util transpiler

UCFLAGS = -O3

all : lib util transpiler
	cp ./transpiler/ttp ./

lib :
	cd ./lib && make UCFLAGS=$(UCFLAGS)

util :
	cd ./util && make UCFLAGS=$(UCFLAGS)

transpiler :
	cd ./transpiler && make UCFLAGS=$(UCFLAGS)

clean :
	cd ./util && make clean
	cd ./lib && make clean
	cd ./transpiler && make clean
	rm ./ttp -f