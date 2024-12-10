#ifndef CONTROLLER_HPP
#define CONTROLLER_HPP

#include <stdio.h>
#include <iostream>
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
            p.PrintText();
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
        }

        // ============================
        // ========== BATTLE ==========
        // ============================

        void StartBattle()
        {
            // Erase screen
            // Load enemy 
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