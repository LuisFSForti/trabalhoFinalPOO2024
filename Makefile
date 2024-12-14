all: lib main

lib:
	g++ -c ./src/Player/Personagem.cpp -I ./include -o ./obj/player.o
	g++ -c ./src/Personagens/Barbaro.cpp -I ./include -o ./obj/player.o
	g++ -c ./src/Personagens/Bardo.cpp -I ./include -o ./obj/player.o
	g++ -c ./src/Personagens/Mago.cpp -I ./include -o ./obj/player.o
	g++ -c ./src/Personagens/Paladino.cpp -I ./include -o ./obj/player.o

	g++ -c ./src/Monstros/Centauro.cpp -I ./include -o ./obj/player.o
	g++ -c ./src/Monstros/Dragao.cpp -I ./include -o ./obj/player.o
	g++ -c ./src/Monstros/Fada.cpp -I ./include -o ./obj/player.o
	g++ -c ./src/Monstros/Fantasma.cpp -I ./include -o ./obj/player.o
	g++ -c ./src/Monstros/Grifo.cpp -I ./include -o ./obj/player.o
	g++ -c ./src/Monstros/Sereia.cpp -I ./include -o ./obj/player.o

main:
	g++ ./main.cpp ./obj/*.o -I ./include -o ./bin/programa

clean:
	rm ./bin/* ./obj/*

run:
	./bin/programa;
