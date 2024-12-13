#ifndef Mago_HPP
#define Mago_HPP

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <vector>

#include "Personagem.hpp"

//Objetivo da classe: muito dano, pouca vida, algum controle do inimigo
class Mago : Personagem
{
    private:
        void Atacar(std::vector<Personagem> alvos);
        void CausarDano(Personagem alvo);
        void EfeitoAuxiliar(std::vector<Personagem> alvos);

        std::string ImprimirDados() const;

    public:
        Mago();
};



#endif