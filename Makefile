all: lib main

lib:
	g++ -c ./src/Player/player.cpp -I ./include -o ./obj/player.o

main:
	g++ ./main.cpp ./obj/*.o -I ./include -o ./bin/programa

clean:
	rm ./bin/* ./obj/*

run:
	./bin/programa;
