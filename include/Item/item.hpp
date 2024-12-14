#ifndef ITEM_HPP
#define ITEM_HPP

#include <stdio.h>
#include <iostream>

class Item
{
    private:
        int _cura;              // restaura a vida
        int _mana;              // recupera mana
        int _buffAtaque;        // aumenta o ataque base
        int _dano;              // causa dano ao inimigo
        float _buffSorte;       // aumenta a sorte
        bool _revive;           // revive um personagem morto
    public:
        Item(int cura=0, int mana=0, int buffAtaque=0, int dano=0, float buffSorte=0, bool revive = false)
        {
            _cura = cura;
            _mana = mana;
            _buffAtaque = buffAtaque;
            _dano = dano;
            _buffSorte = buffSorte;
            _revive = revive;
        }
};
#endif  