#ifndef Mago_HPP
#define Mago_HPP

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <vector>

#include "Player/Personagem.hpp"

//Objetivo da classe: muito dano, pouca vida, paralisa o inimigo
class Mago : public Personagem
{
    private:
        void Atacar(std::vector<Personagem*> alvos); //Ataca o inimigo
        void CausarDano(Personagem* alvo); //Alto dano mágico
        void EfeitoAuxiliar(std::vector<Personagem*> alvos); //Paralisa o inimigo

        void ImprimirDados(std::ostream& out) const;

    public:
        Mago();
};



#endif