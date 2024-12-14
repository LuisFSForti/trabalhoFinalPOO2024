#include "Grifo.hpp"

//Golpeia todos os inimigos, com chance de desvio
void Grifo::Atacar(std::vector<Personagem> alvos)
{
    //Para cada herói
    for(int i = 0; i < alvos.size()-1; i++)
    {
        //Testa se o herói desvia do ataque
        //Se estiver ativamente esquivando aumenta a chance de desviar
        if(rand()%20 + (alvos.at(i).GetSorte()) * alvos.at(i).GetModificadorEsquiva() < this->_ferramenta + this->_buffFerramenta)
            //Se não desviou, calcula o dano
            this->CausarDano(alvos.at(i));
    }
}
    
//Dano físico médio-baixo
void Grifo::CausarDano(Personagem alvo)
{
    //Calcula se é crítico
    bool critico = rand() % 20 + _sorte >= 20;

    //Calcula o dano
    //(1 + critico) = 1 ou 2
    int dano = (rand() % 8 + this->_arma + this->_buffArma) * (1 + critico);

    //Avisa o alvo que ele recebeu dano físico e quanto
    alvo.ReceberDanoFisico(dano);
}
    
//Paraliza todos os inimigos
void Grifo::EfeitoAuxiliar(std::vector<Personagem> alvos)
{
    //Define que já usou sua habilidade auxiliar
    this->_mana = false;

    //Para cada herói
    for(int i = 0; i < alvos.size()-1; i++)
    {
        //Paraliza o alvo atual
        alvos.at(i).AplicarStatus(1);
    }
}

std::string Grifo::ImprimirDados() const
{
    //Necessário pegar o código da Heloísa
}

Grifo::Grifo()
{
    //Inicializa o aleatorizador
    srand(time(NULL));

    this->_vidaMaxima = 100;
    this->_vida = this->_vidaMaxima;
    this->_armadura = 4;
    this->_esquiva = 3;

    this->_precisao = 4;
    this->_sorte = 2;
    this->_arma = 6;

    this->_ferramenta = 10; //Cauda
    this->_armaduraMagica = 8; //Resistência mágica

    this->_buffVida = 0;
    this->_buffArma = 0;
    this->_buffArmaduraMagica = 0;
    this->_buffEsquiva = 0;
    this->_buffPrecisao = 0;
    this->_buffSorte = 0;
    this->_buffArma = 0;
    this->_buffFerramenta = 0;

    this->_modificadorEsquiva = 1;
    this->_modificadorDefesa = 0;
    this->_modificadorQuantidadeAtaques = 0;
    this->_status = 0;
    _mana = true;
}