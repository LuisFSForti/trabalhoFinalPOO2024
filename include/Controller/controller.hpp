#ifndef CONTROLLER_HPP
#define CONTROLLER_HPP

#include <stdio.h>
#include <iostream>
#include <time.h>
#include <vector>
#include <algorithm>

#include "Controller/printFile.hpp"
#include "Item/Item.hpp"

#include "Player/Personagem.hpp"
#include "Personagens/Barbaro.hpp"
#include "Personagens/Paladino.hpp"
#include "Personagens/Bardo.hpp"
#include "Personagens/Mago.hpp"

#include "Monstros/Centauro.hpp"
#include "Monstros/Dragao.hpp"
#include "Monstros/Fada.hpp"
#include "Monstros/Fantasma.hpp"
#include "Monstros/Grifo.hpp"
#include "Monstros/Sereia.hpp"

// ========================================================================
// ============================== CONTROLLER ==============================
// ========================================================================

class Controller
{
    private:
        std::vector<Personagem*> _party;                // Membros da equipe do jogador e inimigo atual  
        std::vector<Personagem*> _enemies;              // Possíveis inimigos
        std::vector<Item> _items;

        bool won = false;                               // Se o jogador ganhou ou não
        int  currentPartyMember = 0;                    // Qual membro da equipe ativo no momento
        std::string filesPath = "Text/";                // Pasta de arquivos em ascii com textos da UI
        std::string enemyPath = "Inimigos/";            // Pasta de arquivos ascii dos inimigos 

        // ============================
        // ========= HELPERS ==========
        // ============================

        void Cooldown(int seconds);                      // Tempo para carregar textos
        void Esperar();                                  // Espera o jogador apertar [Enter]

        void Print(std::string file, bool erase);        // Escreve algum arquivo .txt na tela
        void PrintEnemyLife();                           // Escreve a vida atual do inimigo
        void ReloadScreen();                             // Recarrega a tela com novas informações
        
    public:

        // ============================
        // ======== GAME STATE ========
        // ============================

        void StartGame();                                // Inicializa o jogo
        void EndGame();                                  // Termina o jogo

        // ============================
        // ======= INITAL SETUP =======
        // ============================

        void SetPlayer();                                // Seta os membros da equipe e inimigos

        // ============================
        // ========== BATTLE ==========
        // ============================

        void StartBattle();                              // Inicia a Batalha
        void EnemyPlay(int op);                          // Manipula a jogada do inimigo
        void EndBattle();                                // Termina a batalha

        void GivePrize();                                // Escolhe um item para entregar
        void LoadPrizeScreen(Item prize);                // Carrega a tela de item e manipula a entrega

        void Won();                                      // Tela de vitória
        void Lose();                                     // Tela de derrota
};

#endif