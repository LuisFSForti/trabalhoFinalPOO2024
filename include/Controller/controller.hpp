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
        Player _player;
        //list<Enemies> enemies;

        int round = 0;
        std::string filesPath = "Text/";

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

    public:

        // ============================
        // ======== GAME STATE ========
        // ============================

        void StartGame()
        {
            // Load inital "scene"
            // Initial story text
            // Choose class
            
            PrintFile p(filesPath + "epilogue.txt");
            p.PrintText(true);
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
            // After is all set -> start game
            int option = -1;
            std::cin >> option;

            switch (option)
            {
                case 1:                 // MAGO
                    StartBattle();
                    break;

                case 2:                 // BARBARO
                    StartBattle();
                    break;

                case 3:                 // BARDO
                    StartBattle();
                    break;

                case 4:                 // PALADINO
                    StartBattle();
                    break;
                
                default:
                    std::cout << "Sorry, this option is not valid... choose another one." << std::endl;
                    Cooldown(1);
                    StartGame();
                    break;
            }
        }

        // ============================
        // ========== BATTLE ==========
        // ============================

        void StartBattle()
        {
            // Erase screen
            // Load enemy 
            PrintFile p1(filesPath + "monsterTest.txt");
            p1.PrintText(true);
            PrintFile p2(filesPath + "enemyLife.txt");
            p2.PrintText(false);
            PrintFile p3(filesPath + "playerAtacks.txt");
            p3.PrintText(false);
            // Load status
            // Set everything from scene
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