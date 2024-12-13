#include "Bardo.hpp"

void Bardo::Atacar(std::vector<Personagem> alvos)
{
    Personagem alvo = alvos.at(4);
    if(rand()%20 + this->_precisao + this->_buffPrecisao >= (alvo._esquiva + alvo._buffEsquiva) * alvo._modificadorEsquiva + 10)
        this->CausarDano(alvo);
}
    
void Bardo::CausarDano(Personagem alvo)
{
    bool critico = rand() % 20 + _sorte >= 20;
    int dano = (this->_arma + this->_buffArma) * (1 + critico); //Dano psicológico, não tem resistência

    alvo.ReceberDano(dano);
}
    
void Bardo::EfeitoAuxiliar(std::vector<Personagem> alvos)
{
    int cura = rand() % 12 + this->_ferramenta + this->_buffFerramenta; //Cura baixa

    for(int i = 0; i < alvos.size() - 1; i++) //alvos.Size()-1 para não afetar o monstro
    {
        alvos.at(i).Curar(cura); //Cura
        alvos.at(i)._status = 0; //Remove qualquer status sobre ele
    }
}

std::string Bardo::ImprimirDados() const
{
    //Necessário pegar o código da Heloísa
}

Bardo::Bardo()
{
    //Inicializa o aleatorizador
    srand(time(NULL));

    this->_vidaMaxima = 35;
    this->_vida = this->_vidaMaxima;
    this->_armadura = 2;
    this->_esquiva = 4;

    this->_precisao = 3;
    this->_sorte = 5;
    this->_arma = 2; //Dano baixo pois é psicológico

    this->_ferramenta = 2; //Instrumento
    this->_armaduraMagica = 0;

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

void Bardo::Comando(int instr, std::vector<Personagem> alvos) 
{
    this->_modificadorEsquiva = 1;
    
    //Bardo pode usar sua habilidade auxiliar em qualquer situação
    if(instr == 1)
    {
        this->EfeitoAuxiliar(alvos);
        return;
    }    

    //Verifica se o personagem pode agir
    if(!this->CheckStatus(alvos))
        return;

    switch (instr)
    {
    case 0:
        this->Atacar(alvos);
        break;

    case 2:
        this->UsarConsumivel();
        break;

    case 3:
        this->Esquivar();
        break;
    
    default:
        break;
    }
}