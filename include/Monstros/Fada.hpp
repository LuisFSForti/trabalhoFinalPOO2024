#ifndef Fada_HPP
#define Fada_HPP

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <vector>

#include "../Player/Personagem.hpp"

//Objetivo da classe: baixa vida, esquiva alta, sorte alta, múltiplos ataques mágicos, controle de inimigo
class Fada : public Personagem
{
    private:
        void Atacar(std::vector<Personagem*> alvos); //Ataca múltiplos inimigos
        void CausarDano(Personagem* alvo); //Dano mágico médio com alta chance de crítico
        void EfeitoAuxiliar(std::vector<Personagem*> alvos); //Paraliza um inimigo

        std::string ImprimirDados() const;

    public:
        Fada(std::string id = "");
};



#endif