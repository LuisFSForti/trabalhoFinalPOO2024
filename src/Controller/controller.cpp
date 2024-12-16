#include "Controller/controller.hpp"

// ============================
// ========= HELPERS ==========
// ============================

void Controller::Cooldown(int seconds)                      // Tempo para carregar textos
{
    //t0
    clock_t start = clock();
    //T
    clock_t period = seconds * CLOCKS_PER_SEC;
    //t
    clock_t elapsed;

    do {
        elapsed = clock() - start;
    } while(elapsed < period); //t-t0 < T
}

void Controller::Esperar()                                  // Espera o jogador apertar [Enter]
{
    std::cout << "\n\nPressione [Enter] para continuar\n";

    std::cin.clear();
    std::cin.ignore(1000000, '\n'); //Limpa o buffer de entrada
}

void Controller::Print(std::string file, bool erase)        // Escreve algum arquivo .txt na tela
{
    PrintFile p(filesPath + file);
    p.PrintText(erase);
}

void Controller::PrintEnemyLife()                           // Escreve a vida atual do inimigo
{
    std::cout << "      ==============================" << std::endl;
    std::cout << "                " << _party[_party.size()-1]->GetVida() << "/" << _party[_party.size()-1]->GetVidaMaxima() << std::endl; 
    std::cout << "      ==============================" << std::endl;
}

void Controller::ReloadScreen()                             // Recarrega a tela com novas informações
{
    Print(_party[_party.size()-1]->GetFileId(), true);
    PrintEnemyLife();        
    std::cout << *_party[currentPartyMember] << std::endl;
}

// ============================
// ======== GAME STATE ========
// ============================

void Controller::StartGame()                                // Inicializa o jogo
{   
    Print("gameIcon.txt", true);
    Cooldown(2); //Intervalo para dar aspecto de animção
    Print("epilogue.txt", false);
    Cooldown(4); //Intervalo para dar aspecto de animção
    Esperar();
    SetPlayer(); //Inicializa os valores do jogo
}

void Controller::EndGame()                                  // Termina o jogo
{
    Print("endGame.txt", false);
    char op;
    std::cin >> op; //Verifica se o jogador gostaria de jogar novamente
    std::cin.ignore(1000000, '\n'); //Limpa o buffer de entrada

    if(op == 's') //Se sim
        StartGame(); //Reinicia o jogo
    else //Se não
        exit(0); //Fecha
}

// ============================
// ======= INITAL SETUP =======
// ============================

void Controller::SetPlayer()                                // Seta os membros da equipe e inimigos
{
    _party.resize(5); //Define que o vetor terá tamanho 5
    //Instancia os personagens do grupo, na ordem padrão definida
    _party[0] = new Barbaro();
    _party[1] = new Paladino();
    _party[2] = new Bardo();
    _party[3] = new Mago();

    //Instancia todos os inimigos
    _enemies.push_back(new Centauro(enemyPath + "centauroBasico.txt"));
    _enemies.push_back(new Dragao(enemyPath +  "dragaoBasico.txt"));
    _enemies.push_back(new Fada(enemyPath +  "fadaBasico.txt"));
    _enemies.push_back(new Fantasma(enemyPath +  "fantasmaBasico.txt"));
    _enemies.push_back(new Grifo(enemyPath +  "grifoBasico.txt"));
    _enemies.push_back(new Sereia(enemyPath +  "sereiaBasico.txt"));

    //Instancia todos os possíveis itens
    _items.push_back(Item(20,false,0,0,0,0,0, "Hidromel", "Cura a vida do alvo em 20 pontos."));
    _items.push_back(Item(9999,false,0,0,0,0,0, "Ambrosia", "Restaura a vida maxima do alvo."));
    _items.push_back(Item(0,true,0,0,0,0,0, "Licor", "Restaura a mana do alvo."));
    _items.push_back(Item(0,false,1+rand()%5,0,0,0,0, "Pocao de Furia", "Aumenta o dano de arma."));
    _items.push_back(Item(0,false,0,0,0,0,1+rand()%4, "Terco", "Aumenta a protecao por meios divinos."));
    _items.push_back(Item(0,false,1+rand()%5,0,0,0,1+rand()%4, "Biblia", "Aumenta dano de arma e armadura pelo poder da palavra."));
    _items.push_back(Item(0,false,1+rand()%5,0,1+rand()%3,0,1+rand()%4, "Alcool", "Aumenta dano de arma e armadura totalmente."));
    _items.push_back(Item(0,false,0,1+rand()%3,0,0,0, "Ferradura", "Aumenta a sorte do alvo."));
    _items.push_back(Item(0,false,0,0,0,1+rand()%3,0, "Pocao de Agilidade", "Aumenta a agilidade do alvo."));
    _items.push_back(Item(0,false,0,0,1+rand()%3,0,0, "Bigorna", "Aumenta o buff de ferramenta."));

    //Começa uma batalha
    StartBattle();
}

// ============================
// ========== BATTLE ==========
// ============================

void Controller::StartBattle()                              // Inicia a Batalha
{
    int op;

    if(_enemies.empty()) // Se nao tiver mais inimigos -> jogador ganhou
    {
        Won();
        return;
    }

    int randIndex = rand() % _enemies.size(); // Sorteia algum dos inimigos restantes
    _party[4] = _enemies[randIndex]; //Adiciona ele ao vetor da batalha
    _enemies.erase(std::next(_enemies.begin(), randIndex)); // Apaga da lista de inimigos
    
    won = false; //Define que ainda não venceu
    bool someOneAlive; //Para verificar posteriormente se ainda há um herói vivo

    currentPartyMember = _party.size()-1; //Começa pelo inimigo
    EnemyPlay(1); //Inimigo usa efeito auxiliar
    //Cooldown(3);
    Esperar(); //Espera o jogador

    while(_party[_party.size()-1]->GetVida() > 0) // Enquanto o inimigo estiver vivo
    {
        for(currentPartyMember = 0; currentPartyMember < _party.size()-1; currentPartyMember++) //Para cada herói
        {
            if(_party[currentPartyMember]->GetVida() <= 0) //Se está morto
                continue; //Avança para o próximo

            Estados estado = _party[currentPartyMember]->GetStatus(); //Pega o estado do herói
            if(estado != estavel && estado != amedrontado) //Se estiver sob controle
            {
                if(!(currentPartyMember == 2 && _party[currentPartyMember]->GetMana())) //Se não for o bardo com mana
                {
                    ReloadScreen();

                    //Converte o estado para uma string
                    std::string estadoS = _party[currentPartyMember]->Status();
                    std::transform(estadoS.begin(), estadoS.end(), estadoS.begin(), [](unsigned char c) {return std::tolower(c);}); //https://stackoverflow.com/questions/313970/how-to-convert-an-instance-of-stdstring-to-lower-case
                    //Alerta o jogador
                    std::cout << "Esse membro está " << estadoS << " entao nao pode escolher o que fazer...\n";

                    //Comando aleatório pra chamar as funções de controle de estado
                    _party[currentPartyMember]->Comando(0, _party);
                    
                    //Cooldown(3);
                    Esperar(); //Espera o jogador
                    continue; //Avança pro próximo herói
                }
            }
            //Se não estiver sob controle

            ReloadScreen(); //Carrega a tela
            std::cout << "Escolha uma das opcoes: "; //Espera a escolha de alguma das opções
            std::cin  >> op;
            std::cin.ignore(1000000, '\n'); //Limpa o buffer de entrada

            _party[currentPartyMember]->Comando(op-1, _party); //Chama o comando passado

            if(_party[_party.size()-1]->GetVida() <= 0) //Se o inimigo morreu
                break; //Para o loop de heróis

            //Cooldown(8);
            Esperar();
        }

        if(_party[_party.size()-1]->GetVida() > 0) //Se o inimigo não morreu
        {
            EnemyPlay(0); // Inimigo ataca
            //Cooldown(1);
        }

        someOneAlive = false; //Assume-se que todos os heróis morreram
        for(currentPartyMember = 0; currentPartyMember < _party.size()-1; currentPartyMember++)
        {
            if(_party[currentPartyMember]->GetVida() > 0) //Se o herói não estiver morto
            {
                someOneAlive = true; //Define que ainda tem alguem vivo
                break; //Encerra o loop
            }
        }

        //Se todos os heróis morreram
        if(!someOneAlive)
            break; //Encerra o loop de combate

        //Cooldown(5);
        Esperar(); //Espera o jogador
    }

    if(someOneAlive)
        won = true; //Se terminou e não morreram todos os membros, define que venceu

    EndBattle(); // Acaba a batalha

}

void Controller::EnemyPlay(int op)                          // Manipula a jogada do inimigo
{
    Estados estado = _party[_party.size()-1]->GetStatus(); //Pega o estado do inimigo
    if(estado == estavel || estado == amedrontado)     // Se o inimigo pode atacar
    {
        //Imprime os dados do inimigo
        Print(_party[_party.size()-1]->GetFileId(), true);
        PrintEnemyLife();

        std::cout << "==============================================" << std::endl;
        std::cout << "                ATAQUE INIMIGO                " << std::endl;
        std::cout << "==============================================" << std::endl;

        std::cout << *_party[_party.size()-1] << std::endl;

        //Chama o comando dado
        _party[_party.size()-1]->Comando(op, _party);
    }
    //Se estiver sob controle
    else
    {
        //Imprime os dados do inimigo
        Print(_party[_party.size()-1]->GetFileId(), true);
        PrintEnemyLife();

        //Converte o estado para uma string
        std::string estadoS = _party[_party.size()-1]->Status();
        std::transform(estadoS.begin(), estadoS.end(), estadoS.begin(), [](unsigned char c) {return std::tolower(c);}); //https://stackoverflow.com/questions/313970/how-to-convert-an-instance-of-stdstring-to-lower-case

        std::cout << "=============================================================================" << std::endl;
        std::cout << " O inimigo está " << estadoS << ", por isso não pode escolher o que vai fazer..." << std::endl;
        std::cout << "=============================================================================" << std::endl;

        _party[_party.size()-1]->Comando(0, _party); //Comando aleatório para ativar as funções de controle de estado
    }
}

void Controller::EndBattle()                                // Termina a batalha
{
    for(int i = 0; i < _party.size() - 1; i++) //Avisa os heróis que a batalha acabou
        _party[i]->BatalhaEncerrada(); //Para controlar as variáveis temporárias

    if(won) //Se venceu
        GivePrize(); //Recebe um item
    else
        Lose(); //Perde
}

void Controller::GivePrize()                                // Escolhe um item para entregar
{
    int randIndex = rand() % _items.size(); //Seleciona um item aleatório
    Item prize = _items[randIndex]; 
    _items.erase(_items.begin() + randIndex); //Remove o item

    LoadPrizeScreen(prize); //Abre a tela de recompensa passando o item
}

void Controller::LoadPrizeScreen(Item prize)                // Carrega a tela de item e manipula a entrega
{
    int op;

    //Carrega os dados
    Print("grantPrize.txt", true);

    std::cout << "  Item Encontrado: " << prize.GetNome() << std::endl;
    std::cout << "  Descricao: " << prize.GetDesc() << std::endl;
    std::cout << "======================================================" << std::endl;

    //Verifica o que o jogador deseja fazer com o item
    std::cin >> op;
    std::cin.ignore(1000000, '\n'); //Limpa o buffer de entrada

    //Se ele deseja descartar o item
    if(op == 5)
    {
        //Avança pra próxima batalha
        StartBattle();
        return;
    }

    //Verifica se o herói escolhido já tem um item
    if(_party[op-1]->HasItem())
    {
        //Se sim, alerta o usuário
        std::cout << "Parece que esse membro ja tem um item... Escolha outro." << std::endl;
        //Cooldown(2);
        Esperar(); //Espera o jogador
        LoadPrizeScreen(prize); //Recarrega a tela
    }
    //Se ainda não tem um item
    else
        //Entrega o item pro herói escolhido
        _party[op-1]->SetItem(prize);

    StartBattle(); //Inicia a próxima batalha
}

void Controller::Won()                                      // Tela de vitória
{
    Print("wonScreen.txt", true);
    EndGame();
}

void Controller::Lose()                                     // Tela de derrota
{
    Print("loseScreen.txt", true);
    EndGame();
}