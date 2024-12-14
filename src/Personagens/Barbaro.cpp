#include "Personagens/Barbaro.hpp"

//Ataca o inimigo
void Barbaro::Atacar(std::vector<Personagem> alvos)
{
    //Pega o monstro
    Personagem alvo = alvos.at(4);
    
    //Para cada ataque
    for(int i = 0; i < this->_qtdAtaques + this->_modificadorQuantidadeAtaques; i++)
        //Verifica se o ataque acerta
        if(rand()%20 + this->_precisao + this->_buffPrecisao >= (alvo.GetEsquiva() + alvo.GetBuffEsquiva()) * alvo.GetModificadorEsquiva() + 10)
            //Se sim, calcula o dano
            this->CausarDano(alvo);
}

//Dano físico alto    
void Barbaro::CausarDano(Personagem alvo)
{
    //Calcula o crítico
    bool critico = rand() % 20 + _sorte >= 20;

    //Calcula o dano
    //(1 + critico) = 1 ou 2
    int dano = (rand()%102+ this->_arma + this->_buffArma) * (1 + critico);

    //Alerta o alvo que recebeu dano físico e quanto
    alvo.ReceberDanoFisico(dano);
}
    
//Provoca o inimigo e aumenta a defesa
void Barbaro::EfeitoAuxiliar(std::vector<Personagem> alvos)
{
    //Define que usou a habilidade auxiliar
    this->_mana = false;
    
    //Provoca o monstro
    alvos.at(4).AplicarStatus(3);

    //Altera o modificador de defesa
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
    this->_qtdAtaques = 3;

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
    this->_modificadorDefesa = 0;
    this->_modificadorQuantidadeAtaques = 0;
    this->_status = 0;
    _mana = true;
}