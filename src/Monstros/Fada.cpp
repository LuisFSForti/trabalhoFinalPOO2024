#include "Monstros/Fada.hpp"

//Ataca múltiplos inimigos
void Fada::Atacar(std::vector<Personagem> alvos)
{
    //Para cada ataque
    for(int i = 0; i < this->_qtdAtaques + this->_modificadorQuantidadeAtaques; i++) //Ataca múltiplas vezes
    {
        int posAlvo;
        do
        {
            //Sem prioridade de alvo
            posAlvo = rand() % 4;
        } while (alvos.at(posAlvo).GetVida() <= 0); //Até achar um alvo válido

        //Pega o alvo atual
        Personagem alvo = alvos.at(posAlvo);

        //Verifica se o ataque acerta
        if(rand()%20 + this->_precisao + this->_buffPrecisao >= (alvo.GetEsquiva() + alvo.GetBuffEsquiva()) * alvo.GetModificadorEsquiva() + 10)
            //Calcula o dano
            this->CausarDano(alvo);
    }
}
    
//Dano mágico médio com alta chance de crítico
void Fada::CausarDano(Personagem alvo)
{
    //Calcula se é crítico
    bool critico = rand() % 20 + _sorte >= 20;

    //Calcula o dano
    //(1 + critico) = 1 ou 2
    int dano = (rand() % 6 + this->_arma + this->_buffArma) * (1 + critico);

    //Alerta o alvo que ele recebeu dano mágico e quanto
    alvo.ReceberDanoMagico(dano);
}
    
//Paraliza um inimigo
void Fada::EfeitoAuxiliar(std::vector<Personagem> alvos)
{
    //Define que já usou sua habilidade auxiliar
    this->_mana = false;

    int posAlvo;
    do
    {
        //Sem prioridade de alvo
        posAlvo = rand() % 4;
    } while (alvos.at(posAlvo).GetVida() <= 0); //Até achar um alvo válido

    //Paraliza o alvo
    alvos.at(posAlvo).AplicarStatus(1);
}

std::string Fada::ImprimirDados() const
{
    //Necessário pegar o código da Heloísa
    return "";
}

Fada::Fada(std::string id)
{
    //Inicializa o aleatorizador
    srand(time(NULL));

    this->_vidaMaxima = 50;
    this->_vida = this->_vidaMaxima;
    this->_armadura = 0;
    this->_esquiva = 6;

    this->_precisao = 6;
    this->_sorte = 4;
    this->_arma = 2;
    this->_qtdAtaques = 3;

    this->_ferramenta = 0;
    this->_armaduraMagica = 10; //Resistência mágica

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

    _idFile = id;
}