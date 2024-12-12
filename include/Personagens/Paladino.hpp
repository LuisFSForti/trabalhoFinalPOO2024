#ifndef Paladino_HPP
#define Paladino_HPP

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <vector>

#include "Personagem.hpp"

class Paladino : Personagem
{
    private:
        void Atacar(std::vector<Personagem> alvos);
        void CausarDano(Personagem alvo);
        void EfeitoAuxiliar(std::vector<Personagem> alvos);

        std::string ImprimirDados() const;

    public:
        Paladino();
};



#endif