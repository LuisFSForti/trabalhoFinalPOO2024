#include "Mago.hpp"

//Ataca o inimigo
void Mago::Atacar(std::vector<Personagem> alvos)
{
    //Pega o monstro
    Personagem alvo = alvos.at(4);

    //Calcula se acertou
    if(rand()%20 + this->_precisao + this->_buffPrecisao >= (alvo.GetEsquiva() + alvo.GetBuffEsquiva()) * alvo.GetModificadorEsquiva() + 10)
        //Calcula o dano
        this->CausarDano(alvo);
}
    
//Alto dano mágico
void Mago::CausarDano(Personagem alvo)
{
    //Calcula o critico
    bool critico = rand() % 20 + _sorte >= 20;

    //Calcula o dano, usando tanto a arma quanto a ferramenta
    //(1 + critico) = 1 ou 2
    int dano = (rand()%12 + this->_arma + this->_buffArma + this->_ferramenta + this->_buffFerramenta) * (1 + critico);

    //Alerta o alvo que recebeu dano mágico e quanto
    alvo.ReceberDanoMagico(dano);
}
    
//Paraliza o inimigo
void Mago::EfeitoAuxiliar(std::vector<Personagem> alvos)
{
    //Define que já usou a habilidade auxiliar
    this->_mana = false;
    
    //Paraliza o inimigo
    alvos.at(4).AplicarStatus(1);
}

std::string Mago::ImprimirDados() const
{
    //Necessário pegar o código da Heloísa
}

Mago::Mago()
{
    //Inicializa o aleatorizador
    srand(time(NULL));

    this->_vidaMaxima = 20;
    this->_vida = this->_vidaMaxima;
    this->_armadura = 1;
    this->_esquiva = 1;

    this->_precisao = 6;
    this->_sorte = 2;
    this->_arma = 5;

    this->_ferramenta = 4; //Tomo
    this->_armaduraMagica = this->_arma + this->_ferramenta; //Resistência mágica

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