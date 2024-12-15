#ifndef Barbaro_HPP
#define Barbaro_HPP

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <vector>

#include "Player/Personagem.hpp"

//Objetivo da classe: dano alto, muita vida, pouca resistência, atrai o foco do inimigo
class Barbaro : public Personagem
{
    private:
        void Atacar(std::vector<Personagem*> alvos); //Ataca o inimigo
        void CausarDano(Personagem* alvo); //Dano físico alto
        void EfeitoAuxiliar(std::vector<Personagem*> alvos); //Provoca o inimigo e aumenta a defesa

        std::string ImprimirDados() const;

    public:
        Barbaro();
};



#endif