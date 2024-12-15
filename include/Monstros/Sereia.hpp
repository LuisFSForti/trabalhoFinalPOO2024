#ifndef Sereia_HPP
#define Sereia_HPP

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <vector>

#include "../Player/Personagem.hpp"

//Objetivo da classe: vida e resistência médias, baixo dano psicológico em área, encanta um inimigo
class Sereia : public Personagem
{
    private:
        void Atacar(std::vector<Personagem*> alvos); //Ataca todos os inimigos
        void CausarDano(Personagem* alvo); //Dano psicológico baixo
        void EfeitoAuxiliar(std::vector<Personagem*> alvos); //Encanta um inimigo aleatório

        std::string ImprimirDados() const;

    public:
        Sereia(std::string id = "");
};



#endif