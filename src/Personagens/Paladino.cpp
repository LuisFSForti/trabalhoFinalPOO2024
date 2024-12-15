#include "Personagens/Paladino.hpp"

//Ataca o inimigo
void Paladino::Atacar(std::vector<Personagem*> alvos)
{
    //Pega o monstro
    Personagem* alvo = alvos.at(4);

    //Para cada ataque
    for(int i = 0; i < this->_qtdAtaques + this->_modificadorQuantidadeAtaques; i++)
        //Calcula se o ataque acerta
        if(rand()%20 + this->_precisao + this->_buffPrecisao >= (alvo->GetEsquiva() + alvo->GetBuffEsquiva()) * alvo->GetModificadorEsquiva() + 10)
            //Se sim, calcula o dano
            this->CausarDano(alvo);
}

//Dano físico médios    
void Paladino::CausarDano(Personagem* alvo)
{
    //Calcula o crítico
    bool critico = rand() % 20 + _sorte >= 20;

    //Calcula o dano
    //(1 + critico) = 1 ou 2
    int dano = (rand()%10 + this->_arma + this->_buffArma) * (1 + critico);

    //Alerta o alvo que recebeu dano físico
    alvo->ReceberDanoFisico(dano);
}
    
//Muita cura pro time todo
void Paladino::EfeitoAuxiliar(std::vector<Personagem*> alvos)
{
    //Define que já usou a habilidade auxiliar
    this->_mana = false;
    
    //Calcula a cura
    int cura = (rand() % 12 + this->_ferramenta + this->_buffFerramenta) * 2;

    //Para cada herói
    for(int i = 0; i < alvos.size() - 1; i++)
    {
        //Cura o alvo
        alvos.at(i)->Curar(cura);
    }
}

void Paladino::ImprimirDados(std::ostream& out) const
{
    Item consumivel = this->_consumivel;

    out  << "======================================================\n";
    out << "                         PALADINO                      \n";
    out << "                         " << std::to_string(this->_vida) <<  "/" + std::to_string(this->_vidaMaxima) << "\n";
    out << "======================================================\n";
    out << "||  1. Ataque de espada       3. Consumir item      ||\n";
    if(this->_mana) //Se tiver mana, escreve normalmente
        out << "||  " << "2. Cura divina    " << "        4. Esquivar           ||\n";
    else //Se não tiver, escreve em vermelho
        out << "||  " << "\033[31m2. Cura divina    \033[0m" << "        4. Esquivar           ||\n"; //\033m[xm define a cor do std::cout, 33 sendo vermelho e 0 é padrão
    out << "======================================================\n";
   
    if(this->_hasItem)
    {
        out << "    Item Disponível: " << consumivel.GetNome() << "\n" ;
        out << "    Descricao: " << consumivel.GetDesc() << "\n";
        out << "======================================================";

    }  
}

Paladino::Paladino()
{
    //Inicializa o aleatorizador
    srand(time(NULL));

    this->_vidaMaxima = 50;
    this->_vida = this->_vidaMaxima;
    this->_armadura = 5;
    this->_esquiva = 2;

    this->_precisao = 4;
    this->_sorte = 1;
    this->_arma = 5;
    this->_qtdAtaques = 2;

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

    this->_modificadorEsquiva = 1;
    this->_modificadorDefesa = 0;
    this->_modificadorQuantidadeAtaques = 0;
    this->_status = estavel;
    _mana = true;
}