#ifndef Fantasma_HPP
#define Fantasma_HPP

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <vector>

#include "Personagem.hpp"

//Objetivo da classe: baixíssima vida, altíssima esquiva, dano mágico baixo
class Fantasma : Personagem
{
    private:
        void Atacar(std::vector<Personagem> alvos); //Golpeia um inimigo
        void CausarDano(Personagem alvo); //Dano mágico médio
        void EfeitoAuxiliar(std::vector<Personagem> alvos); //Amedronta os inimigos

        std::string ImprimirDados() const;

    public:
        Fantasma();
};



#endif