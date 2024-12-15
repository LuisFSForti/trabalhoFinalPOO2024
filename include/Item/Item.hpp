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
        int _dano;              // causa dano ao inimigo
        float _buffSorte;       // aumenta a sorte
        bool _revive;           // revive um personagem morto
        int _buffFerramenta;    // aumenta ferramenta
        int _buffEsquiva;       // aumenta a esquiva
        int _buffArmadura;      // aumenta o buff de armadura
        std::string _nome;      // nome do item
        std::string _desc;      // descricao do item
    public:
        Item(int cura=0, bool mana=false, int buffAtaque=0, int dano=0, float buffSorte=0, bool revive=false, int buffFerramenta=0, int buffEsquiva=0, int buffArmadura=0, std::string nome="default", std::string desc = "nada")
        {
            _cura = cura;
            _mana = mana;
            _buffAtaque = buffAtaque;
            _dano = dano;
            _buffSorte = buffSorte;
            _revive = revive;
            _buffFerramenta = buffFerramenta;
            _buffEsquiva = buffEsquiva;
            _buffArmadura = buffArmadura;
            _nome = nome;
            _desc = desc;
        }

        int GetCura(){return _cura;}
        bool GetMana() {return _mana;}
        int GetBuffAtaque(){return _buffAtaque;}
        int GetDano() {return _dano;}
        int GetBuffSorte(){return _buffSorte;}
        bool Revive() {return _revive;}
        int GetBuffArmadura() {return _buffArmadura;}
        int GetBuffEsquiva() {return _buffEsquiva;}
        int GetBuffFerramenta() {return _buffFerramenta;}

        std::string GetNome() {return _nome;}
        std::string GetDesc() {return _desc;}
};
#endif  