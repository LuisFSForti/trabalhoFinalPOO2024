#ifndef Personagem_HPP
#define Personagem_HPP

#include <stdio.h>
#include <stdlib.h>
#include <time.h>S
#include <iostream>
#include <vector>

class Personagem
{
    friend class Paladino;

    protected:
        int _vida, _vidaMaxima, _armadura, _armaduraMagica, _esquiva, _precisao, _sorte, _arma, _ferramenta; //Valores base
        int _buffVida, _buffArmadura, _buffArmaduraMagica, _buffEsquiva, _buffPrecisao, _buffSorte, _buffArma, _buffFerramenta; //Buffs permanentes
        int _modificadorEsquiva; //Para quando estiver esquivando
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
        Personagem();

        void Comando(int instr, std::vector<Personagem> alvos, int idAlvo);

        friend std::ostream& operator<<(std::ostream& out, const Personagem& p);
};



#endif