#ifndef Personagem_HPP
#define Personagem_HPP

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <vector>

#include "Item/Item.hpp"

//Classe base para todos os heróis e monstros
//Para a padronização do código, o vetor de alvos (std::vector<Personagem> alvos) deve ser organizado:
//0 = bárbaro
//1 = paladino
//2 = bardo
//3 = mago
//4 = monstro

enum Estados {estavel, paralizado, encantado, provocado, amedrontado, statusInvalido};

class Personagem
{
    protected:
        std::string _idFile;

        bool _mana, _hasItem; //Para definir se pode usar a habilidade auxiliar
        int _vida, _vidaMaxima, _armadura, _armaduraMagica, _esquiva, _precisao, _sorte, _arma, _ferramenta, _qtdAtaques; //Valores base
        int _buffVida, _buffArmadura, _buffArmaduraMagica, _buffEsquiva, _buffPrecisao, _buffSorte, _buffArma, _buffFerramenta; //Buffs permanentes
        int _modificadorEsquiva, _modificadorDefesa, _modificadorQuantidadeAtaques; //Modificadores temporários
        Estados _status; //Para definir se está paralizado, encantado, provocado ou amedrontado
        Item _consumivel;
        std::string _enderecoFoto;

        virtual void Atacar(std::vector<Personagem*> alvos) { std::cout << "AQUI!\n";}; //Virtual pois cada classe usa valores diferentes e alvos diferentes
        virtual void CausarDano(Personagem *alvo) {}; //Virtual pois cada classe usa valores e tipos diferentes
        virtual void EfeitoAuxiliar(std::vector<Personagem*> alvos) {}; //Virtual pois toda classe tem um efeito diferente
        void UsarConsumivel(); //Aplica um item ao personagem
        void Esquivar(); //Dobra a esquiva até a próxima ação

        virtual void ImprimirDados(std::ostream& out) const {};

    public:
        bool CheckStatus(std::vector<Personagem*> alvos); //Retorna se o usuário pode realizar ações
        void ReceberDanoFisico(int dano); //Diminui o dano usando armadura
        void ReceberDanoMagico(int dano); //Diminui o dano usando armadura mágica
        void ReceberDanoPsicologico(int dano); //Recebe o dano todo
        void Curar(int cura); //Cura
        void AplicarStatus(Estados status); //Aplica status

        virtual void Comando(int instr, std::vector<Personagem*> alvos); //Recebe uma instrução e os possíveis alvos, virtual pois o bardo possui uma variação
        void BatalhaEncerrada(); //Deve ser chamado pra todos os personagens no final de cada batalha, reinicia valores temporários

        friend std::ostream& operator<<(std::ostream& out, const Personagem& p); //Para imprimir os dados do personagem

        //Para acessar os valores
        int GetVida();
        int GetVidaMaxima();
        int GetArmadura();
        int GetArmaduraMagica();
        int GetEsquiva();
        int GetPrecisao();
        int GetSorte();
        int GetArma();
        int GetFerramenta();
        int GetQuantidadeAtaques();

        int GetBuffVida();
        int GetBuffArmadura();
        int GetBuffArmaduraMagica();
        int GetBuffEsquiva();
        int GetBuffPrecisao();
        int GetBuffSorte();
        int GetBuffArma();
        int GetBuffFerramenta();

        int GetModificadorEsquiva();
        int GetModificadorDefesa();
        int GetModificadorQuantidadeAtaques();

        Estados GetStatus();

        Item GetItem();
        void SetItem(Item consumivel);
        bool HasItem();

        std::string GetFileId() { return _idFile; }

        //Não há setters pois os valores devem serem alterados pelas funções
};



#endif