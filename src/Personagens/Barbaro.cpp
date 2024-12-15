#include "Personagens/Barbaro.hpp"

//Ataca o inimigo
void Barbaro::Atacar(std::vector<Personagem*> alvos)
{
    //Pega o monstro
    Personagem* alvo = alvos.at(4);
    
    //Para cada ataque
    for(int i = 0; i < this->_qtdAtaques + this->_modificadorQuantidadeAtaques; i++)
        //Verifica se o ataque acerta
        if(rand()%20 + this->_precisao + this->_buffPrecisao >= (alvo->GetEsquiva() + alvo->GetBuffEsquiva()) * alvo->GetModificadorEsquiva() + 10)
            //Se sim, calcula o dano
            this->CausarDano(alvo);
}

//Dano físico alto    
void Barbaro::CausarDano(Personagem* alvo)
{
    //Calcula o crítico
    bool critico = rand() % 20 + _sorte >= 20;

    //Calcula o dano
    //(1 + critico) = 1 ou 2
    int dano = (rand()%102+ this->_arma + this->_buffArma) * (1 + critico);

    //Alerta o alvo que recebeu dano físico e quanto
    alvo->ReceberDanoFisico(dano);
}
    
//Provoca o inimigo e aumenta a defesa
void Barbaro::EfeitoAuxiliar(std::vector<Personagem*> alvos)
{
    //Define que usou a habilidade auxiliar
    this->_mana = false;
    
    //Provoca o monstro
    alvos.at(4)->AplicarStatus(provocado);

    //Altera o modificador de defesa
    this->_modificadorDefesa = this->_ferramenta + this->_buffFerramenta;
}

void Barbaro::ImprimirDados(std::ostream& out) const
{
    out  << "======================================================\n";
    out << "                         BÁRBARO                      \n";
    out << "                         " << std::to_string(this->_vida) <<  "/" + std::to_string(this->_vidaMaxima) << "\n";
    out << "======================================================\n";
    out << "||  1. Ataque de machado      3. Consumir item      ||\n";
    if(this->_mana) //Se tiver mana, escreve normalmente
        out << "||  " << "2. Provocar       " << "        4. Esquivar           ||\n";
    else //Se não tiver, escreve em vermelho
        out << "||  " << "\033[31m2. Provocar       \033[0m" << "        4. Esquivar           ||\n"; //\033m[xm define a cor do std::cout, 33 sendo vermelho e 0 é padrão
    out << "======================================================\n";
    out << "    Item Disponível: \n";
    out << "======================================================";  
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
    this->_status = estavel;
    _mana = true;
}