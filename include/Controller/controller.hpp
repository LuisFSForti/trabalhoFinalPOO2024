#ifndef CONTROLLER_HPP
#define CONTROLLER_HPP

#include <stdio.h>
#include <iostream>
#include <time.h>
#include <vector>

#include "Controller/printFile.hpp"

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
        std::vector<Personagem*> _party;                 // Membros da equipe do jogador  
        std::vector<Personagem> _enemies;               // Possíveis inimigos

        bool won;                                       // Se o player ganhou ou não
        int  round = 0;                                 // Qual a rodada presente
        int  currentPartyMember = 0;                    // Qual membro da equipe esta atualmente jogando
        std::string filesPath = "Text/";                // Pasta de texto para arquivos em ascii
        std::string enemyPath = "Inimigos/";

        // ============================
        // ========= HELPERS ==========
        // ============================

        void Cooldown(int seconds)                      // Tempo para carregar textos
        {
            clock_t start = clock();
            clock_t period = seconds * CLOCKS_PER_SEC;
            clock_t elapsed;

            do {
                elapsed = clock() - start;
            } while(elapsed < period);
        }

        void Print(std::string file, bool erase)        // Escrever algum arquivo .txt na tela
        {
            PrintFile p(filesPath + file);
            p.PrintText(erase);
        }

        void PrintEnemyLife()                           // Escrever a vida atual do inimigo
        {
            std::cout << "==============================" << std::endl;
            std::cout << "          " << _party[_party.size()-1]->GetVida() << "/" << _party[_party.size()-1]->GetVidaMaxima() << std::endl; 
            std::cout << "==============================" << std::endl;
        }

        void PrintPlayerLife(int currentPartyMember)    // Escrever a vida atual do membro da equipe
        {
            std::cout << "||               " << _party[currentPartyMember]->GetVida() << "/" << _party[currentPartyMember]->GetVidaMaxima() << std::endl;
            std::cout << "==========================================" << std::endl;
        }

        void PrintPartyMemberItem(Personagem member)    // Escrever o item disponivel daquele membro da equipe
        {
            std::cout << "Item Disponível:" << std::endl;
            //std::cout << "Item Disponível:" << member.GetItem().nome() << std::endl;
            std::cout << "==========================================" << std::endl;
        }

        void ReloadScreen()                             // Recarregar a tela com novas informacoes
        {
            Print(_party[_party.size()-1]->GetFileId(), true);
            PrintEnemyLife();        
            std::cout << *_party[currentPartyMember] << std::endl;
        }

    public:

        // ============================
        // ======== GAME STATE ========
        // ============================

        void StartGame()                                // Inicializar jogo
        {   
            //Print("gameIcon.txt", true);
            //Cooldown(2);
            //Print("epilogue.txt", false);
            //Cooldown(2);
            SetPlayer();
        }

        void EndGame()                                  // Terminar jogo
        {
            Print("endGame.txt", false);
            char op;
            std::cin >> op;

            if(op == 'S')
                StartGame();
            else
                exit(0);
        }

        // ============================
        // ======= INITAL SETUP =======
        // ============================

        void SetPlayer()                                // Setando os membros da equipe e inimigos
        {
            _party.resize(5);
            _party[0] = new Barbaro();
            _party[1] = new Paladino();
            _party[2] = new Bardo();
            _party[3] = new Mago();

            _enemies.push_back(Centauro(enemyPath + "centauroBasico.txt"));
            _enemies.push_back(Dragao(enemyPath +  "dragaoBasico.txt"));
            _enemies.push_back(Fada(enemyPath +  "fadaBasico.txt"));
            _enemies.push_back(Fantasma(enemyPath +  "fantasmaBasico.txt"));
            _enemies.push_back(Grifo(enemyPath +  "grifoBasico.txt"));
            _enemies.push_back(Sereia(enemyPath +  "sereiaBasico.txt"));

            StartBattle();
        }

        // ============================
        // ========== BATTLE ==========
        // ============================

        void StartBattle()                                          // Iniciar Batalha
        {
            int op;

            if(_enemies.empty())                                    // Se nao tiver mais inimigos -> jogador ganhou
            {
                Won();
                return;
            }

            int randIndex = rand() % 6;                             // Sorteia algum dos inimigos

            switch (randIndex)
            {
                case 0:
                    _party[4] = new Centauro(enemyPath + "centauroBasico.txt");
                    break;

                case 1:
                    _party[4] = new Dragao(enemyPath +  "dragaoBasico.txt");
                    break;

                case 2:
                    _party[4] = new Fada(enemyPath +  "fadaBasico.txt");
                    break;

                case 3:
                    _party[4] = new Fantasma(enemyPath +  "fantasmaBasico.txt");
                    break;

                case 4:
                    _party[4] = new Grifo(enemyPath +  "grifoBasico.txt");
                    break;

                case 5:
                    _party[4] = new Sereia(enemyPath +  "sereiaBasico.txt");
                    break;
                
                default:
                    break;
            }
            
            _enemies.erase(std::next(_enemies.begin(), randIndex)); // Apaga da lista de inimigos

            round++;
            bool someOneAlive = false;
            while(_party[_party.size()-1]->GetVida() > 0)                 // Enquanto o inimigo ou o jogador nao morrem
            {
                for(currentPartyMember = 0; currentPartyMember < _party.size()-1; currentPartyMember++)
                {
                    if(_party[currentPartyMember]->GetVida() <= 0) continue;

                    ReloadScreen();                                 // Carrega a tela para novo membro
                    std::cout << "Escolha uma das opcoes: ";        // Espera a escolha de alguma das opcoes
                    std::cin  >> op;

                    _party[currentPartyMember]->Comando(op-1, _party);
                    Cooldown(2);
                }

                Cooldown(2);

                _party[currentPartyMember]->Comando(1, _party);          // Inimigo ataca
                currentPartyMember = 0;                             // Reseta party 
                ReloadScreen();
                std::cout << "O INIMIGO ESTÁ ATACANDO!" << std::endl;

                Cooldown(2);

                for(currentPartyMember = 0; currentPartyMember < _party.size()-1; currentPartyMember++)
                    if(_party[currentPartyMember]->GetVida() > 0)   someOneAlive = true;
                
                if(!someOneAlive) break;
            }

            if(someOneAlive) won = true;                         // Se terminou e nao morreram todos os membros
            EndBattle();                                            // Acabar batalha

        }

        void EndBattle()
        {
            if(won)
            {
                GivePrize();                                        // Recebe um item
                StartBattle();                                      // Inicia proxima batalha
            }
            else
                Lose();                                             // Perde
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

        

};

#endif