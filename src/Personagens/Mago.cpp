#include "Mago.hpp"

void Mago::Atacar(std::vector<Personagem> alvos)
{
    Personagem alvo = alvos.at(4);
    if(rand()%20 + this->_precisao + this->_buffPrecisao >= (alvo._esquiva + alvo._buffEsquiva) * alvo._modificadorEsquiva + 10)
        this->CausarDano(alvo);
}
    
void Mago::CausarDano(Personagem alvo)
{
    bool critico = rand() % 20 + _sorte >= 20;
    int dano = (this->_arma + this->_buffArma) * (1 + critico) - (alvo._armaduraMagica + alvo._buffArmaduraMagica + alvo._modificadorDefesa);

    if(dano > 0)
        alvo.ReceberDano(dano);
}
    
void Mago::EfeitoAuxiliar(std::vector<Personagem> alvos)
{
    alvos.at(4)._status = 1; //Paraliza o inimigo
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
    this->_arma = 10;

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
    this->_status = 0;
}