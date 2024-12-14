#ifndef Dragao_HPP
#define Dragao_HPP

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <vector>

#include "../Player/Personagem.hpp"

//Objetivo da classe: muita vida, muita resistência, dano alto, dano em área alto
class Dragao : public Personagem
{
    private:
        void Atacar(std::vector<Personagem> alvos); //Golpeia um inimigo, priorizando a linha de frente
        void CausarDano(Personagem alvo); //Dano físico alto
        void EfeitoAuxiliar(std::vector<Personagem> alvos); //Dano físico alto em área

        std::string ImprimirDados() const;

    public:
        Dragao(std::string id = "") {}
};



#endif