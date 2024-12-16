#include "Personagens/Mago.hpp"

//Ataca o inimigo
void Mago::Atacar(std::vector<Personagem*> alvos)
{
    //Pega o monstro
    Personagem* alvo = alvos.at(4);

    //Verifica se o ataque acerta
        int dado = rand()%20;
        int ataque = dado + this->_precisao + this->_buffPrecisao;
        int esquiva = (alvo->GetEsquiva() + alvo->GetBuffEsquiva()) * alvo->GetModificadorEsquiva() + 10;

        std::cout << "Ataque: " << dado << " + " << this->_precisao << " + " << this->_buffPrecisao << " = " << ataque << std::endl;
        std::cout << "Esquiva: (" << alvo->GetEsquiva() << " + " << alvo->GetBuffEsquiva() << ") *" << alvo->GetModificadorEsquiva() << " + 10 = " << esquiva << std::endl;

        if(ataque >= esquiva)
        {
            //Se sim, calcula o dano
            this->CausarDano(alvo);
        }
}
    
//Alto dano mágico
void Mago::CausarDano(Personagem* alvo)
{
    //Calcula o critico
    bool critico = rand() % 20 + _sorte >= 20;

    //Calcula o dano, usando tanto a arma quanto a ferramenta
    //(1 + critico) = 1 ou 2
    int dano = (rand()%12 + this->_arma + this->_buffArma + this->_ferramenta + this->_buffFerramenta) * (1 + critico);

    if(critico)
        std::cout << "Crítico!!!!" << std::endl;
    std::cout << "Acertou por " << dano << " de dano mágico!" << std::endl << std::endl;

    //Alerta o alvo que recebeu dano mágico e quanto
    alvo->ReceberDanoMagico(dano);
}
    
//Paralisa o inimigo
void Mago::EfeitoAuxiliar(std::vector<Personagem*> alvos)
{
    //Define que já usou a habilidade auxiliar
    this->_mana = false;
    
    //Paralisa o inimigo
    alvos.at(4)->AplicarStatus(paralisado);
}

void Mago::ImprimirDados(std::ostream& out) const
{
    Item consumivel = this->_consumivel;

    out  << "============================================================================================================\n";
    out << "                         MAGO                     " << std::to_string(this->_vida) <<  "/" + std::to_string(this->_vidaMaxima) << "                     STATUS\n";
    out << std::string(50 - this->Status().length()/2, ' ') << this->Status() << "\n";
    out << "============================================================================================================\n";

    if(this->_hasItem)
        out << "||  1. Bola de Fogo               3. Consumir item  ||  Mana: " << this->_mana << "                       Esquiva: " << this->_esquiva << "\n";
    else
        out << "||  1. Bola de Fogo               \033[31m3. Consumir item\033[0m  ||  Mana: " << this->_mana << "                       Esquiva: " << this->_esquiva << "\n";

    if(this->_mana) //Se tiver mana, escreve normalmente
        out << "||  2. Paralisar                  4. Esquivar       ||  Arma: " << this->_arma << "                       Armadura: " << this->_armadura << "\n";
    else //Se não tiver, escreve em vermelho
        out << "||  \033[31m2. Paralisar\033[0m                  4. Esquivar       ||  Arma: " << this->_arma << "                       Armadura: " << this->_armadura << "\n";
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

    this->_vidaMaxima = 20;
    this->_vida = this->_vidaMaxima;
    this->_armadura = 1;
    this->_esquiva = 0;

    this->_precisao = 10;
    this->_sorte = 2;
    this->_arma = 5;

    this->_ferramenta = 4; //Tomo
    this->_armaduraMagica = this->_arma + this->_ferramenta; //Resistência mágica

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
    this->_mana = true;
    this->_hasItem = false;
}