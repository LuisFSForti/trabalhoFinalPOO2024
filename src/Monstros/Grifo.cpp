#include "Monstros/Grifo.hpp"

//Golpeia todos os inimigos, com chance de desvio
void Grifo::Atacar(std::vector<Personagem*> alvos)
{
    //Para cada herói
    for(int i = 0; i < alvos.size()-1; i++)
    {
        //Pega o alvo
        Personagem* alvo = alvos.at(i);

        if(alvo->GetVida() <= 0)
            continue;

        //Testa se o herói desvia do ataque
        //Se estiver ativamente esquivando aumenta a chance de desviar
        int dado = rand()%20;
        int ataque = this->_ferramenta + this->_buffFerramenta;
        int erro = dado + (alvo->GetSorte()) * alvo->GetModificadorEsquiva();

        std::cout << "Ataque: " << this->_ferramenta << " + " << this->_buffFerramenta << " = " << ataque << std::endl;
        std::cout << "Erro do ataque ("<< Nomes[i] << "): " << dado << " + " << alvo->GetSorte() << " * " << alvo->GetModificadorEsquiva() << " = " << erro << std::endl;

        if(erro < ataque)
        {
            //Se não desviou, calcula o dano
            this->CausarDano(alvo);
        }
    }
}
    
//Dano físico médio-baixo
void Grifo::CausarDano(Personagem* alvo)
{
    //Calcula se é crítico
    bool critico = rand() % 20 + _sorte >= 20;

    //Calcula o dano
    //(1 + critico) = 1 ou 2
    int dano = (rand() % 8 + this->_arma + this->_buffArma) * (1 + critico);

    if(critico)
        std::cout << "Crítico!!!!" << std::endl;
    std::cout << "Acertou por " << dano << " de dano físico!" << std::endl << std::endl;

    //Avisa o alvo que ele recebeu dano físico e quanto
    alvo->ReceberDanoFisico(dano);
}
    
//Paralisa todos os inimigos
void Grifo::EfeitoAuxiliar(std::vector<Personagem*> alvos)
{
    //Define que já usou sua habilidade auxiliar
    this->_mana = false;

    //Para cada herói
    for(int i = 0; i < alvos.size()-1; i++)
    {
        //Paralisa o alvo atual
        alvos.at(i)->AplicarStatus(paralisado);
    }
}

void Grifo::ImprimirDados(std::ostream& out) const
{
    out << "O grifo dá um gincho ensurdecedor\n Parece que voces perderam o controle do corpo\n";
    out << "==============================================\n";
}

Grifo::Grifo(std::string id)
{
    //Inicializa o aleatorizador
    srand(time(NULL));

    this->_vidaMaxima = 100;
    this->_vida = this->_vidaMaxima;
    this->_armadura = 4;
    this->_esquiva = 3;

    this->_precisao = 9;
    this->_sorte = 2;
    this->_arma = 6;

    this->_ferramenta = 11; //Cauda
    this->_armaduraMagica = 8; //Resistência mágica

    this->_buffVida = 0;
    this->_buffArmadura = 0;
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