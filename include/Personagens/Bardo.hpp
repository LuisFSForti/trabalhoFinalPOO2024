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
        void Atacar(std::vector<Personagem> alvos); //Ataca o inimigo
        void CausarDano(Personagem alvo); //Dano psicológico baixo, alta chanca de crítico
        void EfeitoAuxiliar(std::vector<Personagem> alvos); //Remove efeitos e cura um pouco o time todo

        std::string ImprimirDados() const;

    public:
        Bardo();

        void Comando(int instr, std::vector<Personagem> alvos);
};



#endif