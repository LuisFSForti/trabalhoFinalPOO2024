#include "Personagens/Mago.hpp"

//Ataca o inimigo
void Mago::Atacar(std::vector<Personagem*> alvos)
{
    //Pega o monstro
    Personagem* alvo = alvos.at(4);

    //Calcula se acertou
    if(rand()%20 + this->_precisao + this->_buffPrecisao >= (alvo->GetEsquiva() + alvo->GetBuffEsquiva()) * alvo->GetModificadorEsquiva() + 10)
        //Calcula o dano
        this->CausarDano(alvo);
}
    
//Alto dano mágico
void Mago::CausarDano(Personagem* alvo)
{
    //Calcula o critico
    bool critico = rand() % 20 + _sorte >= 20;

    //Calcula o dano, usando tanto a arma quanto a ferramenta
    //(1 + critico) = 1 ou 2
    int dano = (rand()%12 + this->_arma + this->_buffArma + this->_ferramenta + this->_buffFerramenta) * (1 + critico);

    //Alerta o alvo que recebeu dano mágico e quanto
    alvo->ReceberDanoMagico(dano);
}
    
//Paraliza o inimigo
void Mago::EfeitoAuxiliar(std::vector<Personagem*> alvos)
{
    //Define que já usou a habilidade auxiliar
    this->_mana = false;
    
    //Paraliza o inimigo
    alvos.at(4)->AplicarStatus(paralizado);
}

void Mago::ImprimirDados(std::ostream& out) const
{
    Item consumivel = this->_consumivel;

    out  << "============================================================================================================\n";
    out << "                         MAGO                     " << std::to_string(this->_vida) <<  "/" + std::to_string(this->_vidaMaxima) << "                     STATUS\n";
    out << "============================================================================================================\n";

    if(this->_hasItem)
        out << "||  1. Bola de Fogo               3. Consumir item  ||  Mana: " << this->_mana << "                       Esquiva: " << this->_esquiva << "\n";
    else
        out << "||  1. Bola de Fogo               \033[31m3. Consumir item\033[0m  ||  Mana: " << this->_mana << "                       Esquiva: " << this->_esquiva << "\n";

    if(this->_mana) //Se tiver mana, escreve normalmente
        out << "||  2. Paralizar                  4. Esquivar       ||  Arma: " << this->_arma << "                       Armadura: " << this->_armadura << "\n";
    else //Se não tiver, escreve em vermelho
        out << "||  \033[31m2. Paralizar\033[0m                  4. Esquivar       ||  Arma: " << this->_arma << "                       Armadura: " << this->_armadura << "\n";
    out << "============================================================================================================\n";
    
    if(this->_hasItem)
    {
        out << "    Item Disponível: " << consumivel.GetNome() << "\n" ;
        out << "    Descricao: " << consumivel.GetDesc() << "\n";
        out << "============================================================================================================";

    }  
}

Mago::Mago()
{
    //Inicializa o aleatorizador
    srand(time(NULL));

    this->_vidaMaxima = 0; //20
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
    this->_status = estavel;
    _mana = true;
}