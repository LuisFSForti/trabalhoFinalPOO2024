#ifndef Barbaro_HPP
#define Barbaro_HPP

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <vector>

#include "Personagem.hpp"

//Objetivo da classe: dano alto, muita vida, pouca resistência, atrai o foco do inimigo
class Barbaro : Personagem
{
    private:
        void Atacar(std::vector<Personagem> alvos);
        void CausarDano(Personagem alvo);
        void EfeitoAuxiliar(std::vector<Personagem> alvos);

        std::string ImprimirDados() const;

    public:
        Barbaro();
};



#endif