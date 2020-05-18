.PHONY : lib util transpiler

all : lib util transpiler
	cp ./transpiler/ttp ./

lib :
	cd ./lib && make

util :
	cd ./util && make

transpiler :
	cd ./transpiler && make

clean :
	cd ./util && make clean
	cd ./lib && make clean
	cd ./transpiler && make clean
	rm ./ttp