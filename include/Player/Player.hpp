#ifndef PLAYER_HPP
#define PLAEYR_HPP

#include <stdio.h>
#include <list>

class Player
{
    private:
        float _totalLife;
        float _currentLife;

        float _luck;
        float _armor;
        float _basicDamage;

        //list<Item> inventory;

    protected:

        virtual void TakeDamage(float damage)
        {
            _currentLife -= (damage*_armor);

            if(_currentLife <= 0)
                Die();
        }

        virtual void BasicDamage() 
        {
            float damage = _basicDamage*_luck;
            //_controller.BasicDamage(damage)
        }

        virtual void Die() {}

    public:

        Player(float totalLife = 100, float basicDamage = 10, float armor = 0.5, float luck = 0.5)
        {
            _totalLife = totalLife;
            _currentLife = totalLife;
            _basicDamage = basicDamage;
            _armor = armor;
            _luck = luck;
        }
};



#endif