all: lib main

lib:
	g++ -c ./src/Controller/controller.cpp -I ./include -o ./obj/controller.o
	g++ -c ./src/Controller/printFile.cpp -I ./include -o ./obj/printFile.o
	g++ -c ./src/Player/Personagem.cpp -I ./include -o ./obj/personagem.o
	g++ -c ./src/Personagens/Barbaro.cpp -I ./include -o ./obj/barbaro.o
	g++ -c ./src/Personagens/Bardo.cpp -I ./include -o ./obj/bardo.o
	g++ -c ./src/Personagens/Mago.cpp -I ./include -o ./obj/mago.o
	g++ -c ./src/Personagens/Paladino.cpp -I ./include -o ./obj/paladino.o

	g++ -c ./src/Monstros/Centauro.cpp -I ./include -o ./obj/centauro.o
	g++ -c ./src/Monstros/Dragao.cpp -I ./include -o ./obj/dragao.o
	g++ -c ./src/Monstros/Fada.cpp -I ./include -o ./obj/fada.o
	g++ -c ./src/Monstros/Fantasma.cpp -I ./include -o ./obj/fantasma.o
	g++ -c ./src/Monstros/Grifo.cpp -I ./include -o ./obj/grifo.o
	g++ -c ./src/Monstros/Sereia.cpp -I ./include -o ./obj/sereia.o

	g++ -c ./src/Item/Item.cpp -I ./include -o ./obj/item.o

main:
	g++ ./main.cpp ./obj/*.o -I ./include -o ./bin/programa

clean:
	rm ./bin/* ./obj/*

run:
	./bin/programa;
