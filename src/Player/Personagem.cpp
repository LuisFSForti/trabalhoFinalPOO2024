#include "Personagem.hpp"

void Personagem::UsarConsumivel()
{
    //programar para chamar o item
}

void Personagem::Esquivar()
{
    this->_modificadorEsquiva = 2;
}

void Personagem::ReceberDano(int dano)
{
    this->_vida -= dano;
    if(this->_vida < 0)
        this->_vida = 0;
}

void Personagem::Curar(int cura)
{
    this->_vida += cura;
    if(this->_vida > this->_vidaMaxima)
        this->_vida = this->_vidaMaxima;
}

//Retorna se o usuário pode realizar ações
bool Personagem::CheckStatus(std::vector<Personagem> alvos)
{
    switch (this->_status)
    {
    case 0: //Estável
        return true;
        break;

    case 1: //Paralizado
        break;

    case 2: //Encantado
        this->CausarDano(alvos.at(rand() % 4));
        break;
    
    case 3: //Provocado pelo bárbaro (que sempre estará na posição 0)
        this->CausarDano(alvos.at(0));
        break;

    default: //Erro
        break;
    }

    if(rand() % 20 + this->_sorte + this->_buffSorte >= 14)
        this->_status = 0;

    return false;    
}

void Personagem::Comando(int instr, std::vector<Personagem> alvos) 
{
    this->_modificadorEsquiva = 1;

    //Verifica se o personagem pode agir
    if(!this->CheckStatus(alvos))
        return;

    switch (instr)
    {
    case 0:
        this->Atacar(alvos);
        break;

    case 1:
        this->EfeitoAuxiliar(alvos);
        break;

    case 2:
        this->UsarConsumivel();
        break;

    case 3:
        this->Esquivar();
        break;
    
    default:
        break;
    }
}

void Personagem::BatalhaEncerrada()
{
    this->_status = 0;
    this->_modificadorDefesa = 0;
    this->_modificadorEsquiva = 1;
}

std::ostream& operator<<(std::ostream& out, const Personagem& p)
{
    out << p.ImprimirDados();
}