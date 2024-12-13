#include "Barbaro.hpp"

void Barbaro::Atacar(std::vector<Personagem> alvos)
{
    Personagem alvo = alvos.at(4);
    if(rand()%20 + this->_precisao + this->_buffPrecisao >= (alvo._esquiva + alvo._buffEsquiva) * alvo._modificadorEsquiva + 10)
        this->CausarDano(alvo);
}
    
void Barbaro::CausarDano(Personagem alvo)
{
    bool critico = rand() % 20 + _sorte >= 20;
    int dano = (this->_arma + this->_buffArma) * (1 + critico) - (alvo._armadura + alvo._buffArmadura + alvo._modificadorDefesa);

    if(dano > 0)
        alvo.ReceberDano(dano);
}
    
void Barbaro::EfeitoAuxiliar(std::vector<Personagem> alvos)
{
    alvos.at(4)._status = 3; //Provoca o inimigo

    this->_modificadorDefesa = this->_ferramenta + this->_buffFerramenta;
}

std::string Barbaro::ImprimirDados() const
{
    //Necessário pegar o código da Heloísa
}

Barbaro::Barbaro()
{
    //Inicializa o aleatorizador
    srand(time(NULL));

    this->_vidaMaxima = 75;
    this->_vida = this->_vidaMaxima;
    this->_armadura = 2;
    this->_esquiva = 1;

    this->_precisao = 4;
    this->_sorte = 2;
    this->_arma = 7;

    this->_ferramenta = 3; //Totens
    this->_armaduraMagica = this->_ferramenta; //Resistência espiritual

    this->_buffVida = 0;
    this->_buffArma = 0;
    this->_buffArmaduraMagica = 0;
    this->_buffEsquiva = 0;
    this->_buffPrecisao = 0;
    this->_buffSorte = 0;
    this->_buffArma = 0;
    this->_buffFerramenta = 0;

    this->_modificadorEsquiva = 1;
    this->_status = 0;
}