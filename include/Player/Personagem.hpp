#ifndef Personagem_HPP
#define Personagem_HPP

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <vector>

class Personagem
{
    //Para as classes derivadas poderem alterar os valores
    friend class Paladino;
    friend class Barbaro;
    friend class Bardo;
    friend class Mago;

    protected:
        int _vida, _vidaMaxima, _armadura, _armaduraMagica, _esquiva, _precisao, _sorte, _arma, _ferramenta; //Valores base
        int _buffVida, _buffArmadura, _buffArmaduraMagica, _buffEsquiva, _buffPrecisao, _buffSorte, _buffArma, _buffFerramenta; //Buffs permanentes
        int _modificadorEsquiva, _modificadorDefesa; //Modificadores temporários
        int _status; //Para definir se está paralizado, envenenado, cego, etc
        //Item consumivel;
        std::string _enderecoFoto;

        virtual void Atacar(std::vector<Personagem> alvos);
        virtual void CausarDano(Personagem alvo);
        virtual void EfeitoAuxiliar(std::vector<Personagem> alvos);
        void UsarConsumivel();
        void Esquivar();

        void ReceberDano(int dano);
        void Curar(int cura);

        bool CheckStatus(std::vector<Personagem> alvos); //Retorna se o usuário pode realizar ações
        virtual std::string ImprimirDados() const;

    public:
        virtual void Comando(int instr, std::vector<Personagem> alvos); //Virtual pois o bardo é diferente
        void BatalhaEncerrada(); //Deve ser chamado pra todos os personagens no final de cada batalha

        friend std::ostream& operator<<(std::ostream& out, const Personagem& p);
};



#endif