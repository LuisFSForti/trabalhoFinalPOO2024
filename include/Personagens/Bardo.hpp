#ifndef Bardo_HPP
#define Bardo_HPP

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <vector>

#include "Personagem.hpp"

//Objetivo da classe: dano base baixo, muita sorte, suporte ao time
class Bardo : Personagem
{
    private:
        void Atacar(std::vector<Personagem> alvos);
        void CausarDano(Personagem alvo);
        void EfeitoAuxiliar(std::vector<Personagem> alvos);

        std::string ImprimirDados() const;

    public:
        Bardo();

        void Comando(int instr, std::vector<Personagem> alvos);
};



#endif