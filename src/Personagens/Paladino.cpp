#include "Personagens/Paladino.hpp"

//Ataca o inimigo
void Paladino::Atacar(std::vector<Personagem> alvos)
{
    std::cout << "PALADINO\n";
    //Pega o monstro
    Personagem alvo = alvos.at(4);

    //Para cada ataque
    for(int i = 0; i < this->_qtdAtaques + this->_modificadorQuantidadeAtaques; i++)
        //Calcula se o ataque acerta
        if(rand()%20 + this->_precisao + this->_buffPrecisao >= (alvo.GetEsquiva() + alvo.GetBuffEsquiva()) * alvo.GetModificadorEsquiva() + 10)
            //Se sim, calcula o dano
            this->CausarDano(alvo);
}

//Dano físico médios    
void Paladino::CausarDano(Personagem alvo)
{
    //Calcula o crítico
    bool critico = rand() % 20 + _sorte >= 20;

    //Calcula o dano
    //(1 + critico) = 1 ou 2
    int dano = (rand()%10 + this->_arma + this->_buffArma) * (1 + critico);

    //Alerta o alvo que recebeu dano físico
    alvo.ReceberDanoFisico(dano);
}
    
//Muita cura pro time todo
void Paladino::EfeitoAuxiliar(std::vector<Personagem> alvos)
{
    //Define que já usou a habilidade auxiliar
    this->_mana = false;
    
    //Calcula a cura
    int cura = (rand() % 12 + this->_ferramenta + this->_buffFerramenta) * 2;

    //Para cada herói
    for(int i = 0; i < alvos.size() - 1; i++)
    {
        //Cura o alvo
        alvos.at(i).Curar(cura);
    }
}

std::string Paladino::ImprimirDados() const
{
    //Necessário pegar o código da Heloísa
        std::string r;

    r  = "======================================================\n";
    r += "                        PALADINO                      \n";
    r += "                         " + this->_vida;
    r += "/" + this->_vidaMaxima;
    r += "\n";
    r += "======================================================\n";
    r += "||  1. Atacar                 3. Consumir item      ||\n";
    r += "||  2. Efeito Auxiliar        4. Esquivar           ||\n";
    r += "======================================================\n";

    return r;
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
    this->_status = 0;
    _mana = true;
}