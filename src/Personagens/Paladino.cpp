#include "Paladino.hpp"

void Paladino::Atacar(std::vector<Personagem> alvos)
{
    Personagem alvo = alvos.at(4);
    if(rand()%20 + this->_precisao + this->_buffPrecisao >= alvo._esquiva + alvo._buffEsquiva + alvo._modificadorEsquiva + 10)
        this->CausarDano(alvo);
}
    
void Paladino::CausarDano(Personagem alvo)
{
    bool critico = rand() % 20 + _sorte >= 20;
    int dano = (this->_arma + this->_buffArma) * (1 + critico) - (alvo._armadura + alvo._buffArmadura);

    if(dano > 0)
        alvo.ReceberDano(dano);
}
    
void Paladino::EfeitoAuxiliar(std::vector<Personagem> alvos)
{
    int cura = rand() % 12 + this->_ferramenta + this->_buffFerramenta;

    for(int i = 0; i < alvos.size() - 1; i++) //alvos.Size()-1 para não curar o monstro
    {
        alvos.at(i).Curar(cura);
    }
}

std::string Paladino::ImprimirDados() const
{
    //Necessário pegar o código da Heloísa
}

Paladino::Paladino()
{
    //Inicia o aleatorizador
    srand(time(NULL));

    this->_vidaMaxima = 50;
    this->_vida = 50;
    this->_armadura = 5;
    this->_esquiva = 2;

    this->_precisao = 4;
    this->_sorte = 1;
    this->_arma = 5;

    this->_ferramenta = 2; //Símbolo divinio
    this->_armaduraMagica = this->_ferramenta; //Resistência divina

    this->_buffVida = 0;
    this->_buffArma = 0;
    this->_buffArmaduraMagica = 0;
    this->_buffEsquiva = 0;
    this->_buffPrecisao = 0;
    this->_buffSorte = 0;
    this->_buffArma = 0;
    this->_buffFerramenta = 0;

    this->_modificadorEsquiva = 0;
    this->_status = 0;
}