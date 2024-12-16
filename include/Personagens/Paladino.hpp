#ifndef Paladino_HPP
#define Paladino_HPP

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <vector>

#include "Player/Personagem.hpp"

//Objetivo da classe: média entre todos, resistente, muita cura
class Paladino : public Personagem
{
    private:
        void Atacar(std::vector<Personagem*> alvos); //Ataca o inimigo
        void CausarDano(Personagem* alvo); //Dano físico médio
        void EfeitoAuxiliar(std::vector<Personagem*> alvos); //Muita cura pro time todo

        void ImprimirDados(std::ostream& out) const;

    public:
        Paladino();
};



#endif