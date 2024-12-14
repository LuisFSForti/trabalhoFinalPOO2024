#include "Personagens/Bardo.hpp"

//Ataca o inimigo
void Bardo::Atacar(std::vector<Personagem*> alvos)
{
    //Pega o monstro
    Personagem alvo = *alvos.at(4);

    //Verifica se o ataque acert
    if(rand()%20 + this->_precisao + this->_buffPrecisao >= (alvo.GetEsquiva() + alvo.GetBuffEsquiva()) * alvo.GetModificadorEsquiva() + 10)
        //Se sim, calcula o dano
        this->CausarDano(alvo);
}
    
//Dano psicológico baixo, alta chanca de crítico
void Bardo::CausarDano(Personagem alvo)
{
    //Calcula o crítico
    bool critico = rand() % 20 + _sorte >= 20;

    //Calcula o dano
    //(1 + critico) = 1 ou 2
    int dano = (rand()%6 + this->_arma + this->_buffArma) * (1 + critico); //Dano psicológico, não tem resistência

    //Alerta o alvo que recebeu dano psicológico e quanto
    alvo.ReceberDanoPsicologico(dano);
}

//Remove efeitos e cura um pouco o time todo    
void Bardo::EfeitoAuxiliar(std::vector<Personagem*> alvos)
{
    //Define que já usou a habilidade auxiliar
    this->_mana = false;
    
    //Cura baixa
    int cura = rand() % 12 + this->_ferramenta + this->_buffFerramenta;

    //Para cada herói
    for(int i = 0; i < alvos.size() - 1; i++)
    {
        alvos.at(i)->Curar(cura); //Cura
        alvos.at(i)->AplicarStatus(0); //Remove qualquer status sobre ele
    }
}

std::string Bardo::ImprimirDados() const
{
    //Necessário pegar o código da Heloísa
    std::string r;

    r  = "======================================================\n";
    r += "                          BARDO                       \n";
    r += "                         " + std::to_string(this->_vida) + "/" + std::to_string(this->_vidaMaxima) + "\n";
    r += "======================================================\n";
    r += "||  1. Atacar                 3. Consumir item      ||\n";
    r += "||  2. Efeito Auxiliar        4. Esquivar           ||\n";
    r += "======================================================\n";

    return r;
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
    this->_arma = 3; //Dano baixo pois é psicológico

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
    this->_modificadorDefesa = 0;
    this->_modificadorQuantidadeAtaques = 0;
    this->_status = 0;
    _mana = true;
}

void Bardo::Comando(int instr, std::vector<Personagem*> alvos) 
{
    //Reinicia o modificador de esquiva
    this->_modificadorEsquiva = 1;

    //Bardo pode usar sua habilidade auxiliar em qualquer estado, desde que tenha mana
    if(instr == 1 && this->_mana)
    {
        //Utiliza o efeito auxiliar
        this->EfeitoAuxiliar(alvos);
        return;
    }

    //Verifica se o personagem pode agir
    if(!this->CheckStatus(alvos))
        //Se não, retorna
        return;

    //Verifica qual é a instrução
    switch (instr)
    {
    //Se ataque
    case 0:
        //Ataca
        this->Atacar(alvos);
        break;

    //Se usar item consumível
    case 2:
        //Usa o item
        this->UsarConsumivel();
        break;

    //Se esquivar
    case 3:
        //Esquiva
        this->Esquivar();
        break;
    
    //Erro
    default:
        break;
    }
}