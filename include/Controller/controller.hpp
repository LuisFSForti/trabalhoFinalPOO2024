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

        bool won;
        int  round = 0;
        int  currentPartyMember = 0;
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
            Print("playerAtacks.txt", false); // Trocar para cada um dos tipos de player
            //Print("party" + currentPartyMember, false);
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

        // ============================
        // ======= INITAL SETUP =======
        // ============================

        void SetPlayer()
        {
            _party.push_front(Player());
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

            //if(enemies.empty())
            // Won();
            // return;  


            round++;
            while(!_party.empty() && enemyLife > 0)
            {

                for(currentPartyMember = 0; currentPartyMember < _party.size(); currentPartyMember++)
                {
                    ReloadScreen();
                    std::cout << "Escolha uma das opcoes: ";
                    std::cin  >> op;

                    switch (op)
                    {
                        case 1:
                            // Ataque
                            break;

                        case 2:
                            // Efeito Auxiliar
                            break;

                        case 3:
                            // ConsumirItem
                            break;

                        case 4:
                            // Esquivar
                            break;
                        
                        default:
                            break;
                    }

                    currentPartyMember = 0;
                }

                ReloadScreen();
                std::cout << "O INIMIGO ESTÁ ATACANDO!" << std::endl;
                // Enemy Atack()
                // loop through party -> check if someone died
                // if died -> remove from list
            }

            if(!_party.empty()) won = true;
            EndBattle();

        }

        void EndBattle()
        {
            // Check if player is dead or enemy
            // if player => EndGame()
            // else => givePrize, nextBattle()

            if(won)
            {
                GivePrize();
                StartBattle();
            }
            else
                Lose();
        }

        void GivePrize()
        {
            // Party pode escolher entre itens
        }

        void Won()
        {
            Print("wonScreen.txt", true);
            EndGame();
        }

        void Lose()
        {
            Print("loseScreen.txt", true);
            EndGame();
        }

        void EndGame()
        {
            std::cout << "                Pressione [S] para jogar novamente." << std::endl;
            std::cout << "                      Pressione [N] para sair." << std::endl;
            char op;
            std::cin >> op;

            if(op == 'S')
                StartGame();
            else
                exit(0);
        }

};

#endif