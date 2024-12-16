#ifndef Centauro_HPP
#define Centauro_HPP

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <vector>

#include "../Player/Personagem.hpp"

//Objetivo da classe: vida e resistência médias, investida poderosa
class Centauro : public Personagem
{
    private:
        void Atacar(std::vector<Personagem*> alvos); //Golpeia um inimigo, priorizando a linha de frente
        void CausarDano(Personagem* alvo); //Dano físico médio-alto
        void EfeitoAuxiliar(std::vector<Personagem*> alvos); //Dano físico altíssimo em um inimigo

        void ImprimirDados(std::ostream& out) const;

    public:
        Centauro(std::string id);
};



#endif