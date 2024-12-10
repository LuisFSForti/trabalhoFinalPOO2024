#ifndef CONTROLLER_HPP
#define CONTROLLER_HPP

#include <stdio.h>
#include <iostream>
#include <time.h>
#include <list>
#include "Player/Player.hpp"
#include "Controller/printFile.hpp"

// ========================================================================
// ============================== CONTROLLER ==============================
// ========================================================================

class Controller
{
    private:
        std::list<Player> _party;
        //list<Enemies> enemies;

        int currentPartyMember = 0;
        int round = 0;
        std::string filesPath = "Text/";

        int enemyLife = 1000;   // Teste por agora
        int playerLife = 100;   // Teste por agora

        // ============================
        // ========= HELPERS ==========
        // ============================

        void Cooldown(int seconds)
        {
            clock_t start = clock();
            clock_t period = seconds * CLOCKS_PER_SEC;
            clock_t elapsed;

            do {
                elapsed = clock() - start;
            } while(elapsed < period);
        }

        void Print(std::string file, bool erase)
        {
            PrintFile p(filesPath + file);
            p.PrintText(erase);
        }

        void PrintEnemyLife()
        {
            std::cout << "==============================" << std::endl;
            std::cout << "          " << enemyLife << "/1000           " << std::endl; 
            std::cout << "==============================" << std::endl;
        }

        void PrintPlayerLife(int currentPartyMember)
        {
            std::cout << "||               " << playerLife << "/100                ||" << std::endl;
            std::cout << "==========================================" << std::endl;
        }

        void ReloadScreen()
        {
            Print("monsterTest.txt", true);
            PrintEnemyLife();        
            Print("playerAtacks.txt", false);
            PrintPlayerLife(0);
        }

    public:

        // ============================
        // ======== GAME STATE ========
        // ============================

        void StartGame()
        {
            // Load inital "scene"
            // Initial story text
            // Choose class
            
            Print("gameIcon.txt", true);
            Cooldown(2);
            Print("epilogue.txt", false);
            Cooldown(10);
            SetPlayer();
        }

        void EndGame()
        {

        }

        // ============================
        // ======= INITAL SETUP =======
        // ============================

        void SetPlayer()
        {
            //_party.front(Mage());
            //_party.front(Barbarian());
            //_party.front(Bard());
            //_party.front(Paladin());

            StartBattle();
        }

        // ============================
        // ========== BATTLE ==========
        // ============================

        void StartBattle()
        {
            int op;
            //Atack atk;
            ReloadScreen();
            std::cout << "Escolha uma das opcoes: ";
            std::cin  >> op;

            //if(op <= 4)
                //party[currentPartyMember].Atack(atack);
                //
            //else      // is item
                //party[currentPartyMember].UseItem(op-4); 

        }

        void EndBattle()
        {
            // Check if player is dead or enemy
            // if player => EndGame()
            // else => givePrize, nextBattle()
        }

        void GivePrize()
        {

        }

};

#endif