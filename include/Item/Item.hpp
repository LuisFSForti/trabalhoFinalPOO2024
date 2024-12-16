#ifndef ITEM_HPP
#define ITEM_HPP

#include <stdio.h>
#include <iostream>

class Item
{
    private:
        int _cura;              // restaura a vida
        bool _mana;             // recupera mana
        int _buffAtaque;        // aumenta o buff de ataque
        float _buffSorte;       // aumenta a sorte
        int _buffFerramenta;    // aumenta ferramenta
        int _buffEsquiva;       // aumenta a esquiva
        int _buffArmadura;      // aumenta o buff de armadura
        std::string _nome;      // nome do item
        std::string _desc;      // descrição do item

    public:
        //Construtor da classe, todos os valores devem serem passados aqui
        Item(int cura=0, bool mana=false, int buffAtaque=0, float buffSorte=0, 
        int buffFerramenta=0, int buffEsquiva=0, int buffArmadura=0, 
        std::string nome="default", std::string desc = "nada");

        //Getters da classe
        int GetCura();
        bool GetMana();
        int GetBuffAtaque();
        int GetBuffSorte();
        int GetBuffArmadura();
        int GetBuffEsquiva();
        int GetBuffFerramenta();
        std::string GetNome();
        std::string GetDesc();

        friend std::ostream& operator<<(std::ostream& out, const Item& p); //Para imprimir os dados do item
};
#endif  