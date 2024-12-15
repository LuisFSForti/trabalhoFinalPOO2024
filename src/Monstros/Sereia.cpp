#include "Monstros/Sereia.hpp"

//Ataca todos os inimigos
void Sereia::Atacar(std::vector<Personagem*> alvos)
{
    //Para cada herói
    for(int i = 0; i < alvos.size() - 1; i++)
    {
        //Pega o alvo
        Personagem* alvo = alvos.at(i);

        //Verifica se o ataque acerta
        if(rand()%20 + this->_precisao + this->_buffPrecisao >= (alvo->GetEsquiva() + alvo->GetBuffEsquiva()) * alvo->GetModificadorEsquiva() + 10)
            //Se sim, calcula o dano
            this->CausarDano(alvo);
    }
}
    
//Dano psicológico baixo
void Sereia::CausarDano(Personagem* alvo)
{
    //Calcula o crítico
    bool critico = rand() % 20 + _sorte >= 20;

    //Calcula o dano
    //(1 + critico) = 1 ou 2
    int dano = (rand() % 4 + this->_arma + this->_buffArma) * (1 + critico);

    //Avisa o alvo que recebeu dano psicológico
    alvo->ReceberDanoPsicologico(dano);
}
    
//Encanta um inimigo aleatório
void Sereia::EfeitoAuxiliar(std::vector<Personagem*> alvos)
{
    //Define que já usou a habilidade auxiliar
    this->_mana = false;
    
    int posAlvo;
    do
    {
        //Sem prioridade de alvo
        posAlvo = rand() % 4;
    } while (alvos.at(posAlvo)->GetVida() <= 0); //Até achar um alvo válido

    alvos.at(posAlvo)->AplicarStatus(encantado); //Encanta o alvo
}

void Sereia::ImprimirDados(std::ostream& out) const
{
    
}

Sereia::Sereia(std::string id)
{
    //Inicializa o aleatorizador
    srand(time(NULL));

    this->_vidaMaxima = 70;
    this->_vida = this->_vidaMaxima;
    this->_armadura = 2;
    this->_esquiva = 3;

    this->_precisao = 4;
    this->_sorte = 2;
    this->_arma = 3; //Dano baixo pois é psicológico

    this->_ferramenta = 0;
    this->_armaduraMagica = 6; //Resistência mágica

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
    this->_status = estavel;
    _mana = true;

    _idFile = id;
}