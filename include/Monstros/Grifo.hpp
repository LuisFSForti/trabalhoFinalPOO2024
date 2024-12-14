#ifndef Grifo_HPP
#define Grifo_HPP

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <vector>

#include "../Player/Personagem.hpp"

//Objetivo da classe: vida e resistências médias, golpe de cauda em área desviável, grito paralisante
class Grifo : public Personagem
{
    private:
        void Atacar(std::vector<Personagem> alvos); //Golpeia todos os inimigos, com chance de desvio
        void CausarDano(Personagem alvo); //Dano físico médio-baixo
        void EfeitoAuxiliar(std::vector<Personagem> alvos); //Paraliza todos os inimigos

        std::string ImprimirDados() const;

    public:
        Grifo(std::string id = "");
};



#endif