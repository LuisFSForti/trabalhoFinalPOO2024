#include "Player/Personagem.hpp"

void Personagem::UsarConsumivel()
{
    //programar para chamar o item
}

//Dobra a esquiva até a próxima ação
void Personagem::Esquivar()
{
    this->_modificadorEsquiva = 2;
}

//Retorna se o usuário pode realizar ações
bool Personagem::CheckStatus(std::vector<Personagem*> alvos)
{
    bool podeAgir = false; //Pro caso de ele estar sobre um efeito, mas ainda puder agir
    switch (this->_status)
    {
    case 0: //Estável
        return true; //Retorna que ele pode agir
        break;

    case 1: //Paralizado
        break;

    case 2: //Encantado -> atinge um aliado
        int posAlvo;
        do
        {
            posAlvo = rand() % 4;
        } while(alvos.at(posAlvo)->GetVida() <= 0); //Até achar um alvo válido

        this->CausarDano(*alvos.at(posAlvo));

        break;
    
    case 3: //Provocado pelo bárbaro (que sempre estará na posição 0)
        if(alvos.at(0)->GetVida() <= 0) //Se o bárbaro estiver morto
            podeAgir = true; //Então pode agir normalmente
        else //Se ele estiver vivo
            this->CausarDano(*alvos.at(0)); //Ataca o bárbaro
        break;

    case 4: //Amedrontado
        this->_modificadorQuantidadeAtaques--; //Diminui a quantidade de ataques
        if(this->_qtdAtaques + this->_modificadorQuantidadeAtaques <= 0) //Se ele não poderia mais atacar
            this->_modificadorQuantidadeAtaques = -(this->_qtdAtaques - 1); //Corrige para sobrar 1 ataque

        podeAgir = true;

    default: //Erro
        break;
    }

    if(rand() % 20 + this->_sorte + this->_buffSorte >= 14) //Tenta reestabilizar
    {
        //Se ele estava amedrontado
        if(this->_status == 4)
            //Atualiza o modificador de quantidade de ataques
            this->_modificadorQuantidadeAtaques = 0;

        //Estabiliza
        this->_status = 0;
    }

    //Retorna se ele pode agir
    return podeAgir;
}

//Diminui o dano usando armadura
void Personagem::ReceberDanoFisico(int dano)
{
    //Diminui o dano
    dano -= this->_armadura + this->_buffArmadura + this->_modificadorDefesa;

    //Se o dano for negativo ou 0
    if(dano <= 0)
        //Então nada acontece
        return;

    //Diminui a vida
    this->_vida -= dano;
    //Se ficou abaixo de 0, corrige
    if(this->_vida < 0)
        this->_vida = 0;
}

//Diminui o dano usando armadura mágica
void Personagem::ReceberDanoMagico(int dano)
{
    //Diminui o danos
    dano -= this->_armaduraMagica + this->_buffArmaduraMagica + this->_modificadorDefesa;

    //Se o dano for negativo ou 0
    if(dano <= 0)
        //Então nada acontece
        return;

    //Diminui a vida
    this->_vida -= dano;
    //Se ficou abaixo de 0, corrige
    if(this->_vida < 0)
        this->_vida = 0;
}

//Recebe o dano todo
void Personagem::ReceberDanoPsicologico(int dano)
{
    //Diminui a vida
    this->_vida -= dano;
    //Se ficou abaixo de 0, corrige
    if(this->_vida < 0)
        this->_vida = 0;
}

//Cura
void Personagem::Curar(int cura)
{
    //Aumenta a vida
    this->_vida += cura;
    //Se ficou acima da vida máxima, corrige
    if(this->_vida > this->_vidaMaxima)
        this->_vida = this->_vidaMaxima;
}

//Aplica status
void Personagem::AplicarStatus(int status)
{
    if(status < 0 || status > 3) //Valida o status
        return; //Retorna pois é inválido

    //Se estava amedrontado
    if(this->_status == 4 && status == 0)
        //Reinicia o modificador de velocidade de ataque
        this->_modificadorQuantidadeAtaques = 0;

    //Aplica o status
    this->_status = status;
}

//Recebe uma instrução e os possíveis alvos
void Personagem::Comando(int instr, std::vector<Personagem*> alvos) 
{
    //Reinicia o modificador de esquiva
    this->_modificadorEsquiva = 1;

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

    //Se efeito auxiliar
    case 1:
        //Se tiver mana
        if(this->_mana)
            //Utiliza o efeito auxiliar
            this->EfeitoAuxiliar(alvos);

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

//Deve ser chamado pra todos os personagens no final de cada batalha, reinicia valores temporários
void Personagem::BatalhaEncerrada()
{
    this->_status = 0;
    this->_modificadorDefesa = 0;
    this->_modificadorEsquiva = 1;
    this->_modificadorQuantidadeAtaques = 0;
}

//Para imprimir os dados do personagem
std::ostream& operator<<(std::ostream& out, const Personagem& p)
{
    out << p.ImprimirDados();
    return out;
}

//Para acessar os valores
int Personagem::GetVida()
{
    return this->_vida;
}

int Personagem::GetVidaMaxima()
{
    return this->_vidaMaxima;
}

int Personagem::GetArmadura()
{
    return this->_armadura;
}

int Personagem::GetArmaduraMagica()
{
    return this->_armaduraMagica;
}

int Personagem::GetEsquiva()
{
    return this->_esquiva;
}

int Personagem::GetPrecisao()
{
    return this->_precisao;
}

int Personagem::GetSorte()
{
    return this->_sorte;
}

int Personagem::GetArma()
{
    return this->_arma;
}

int Personagem::GetFerramenta()
{
    return this->_ferramenta;
}

int Personagem::GetQuantidadeAtaques()
{
    return this->_qtdAtaques;
}

int Personagem::GetBuffVida()
{
    return this->_buffVida;
}

int Personagem::GetBuffArmadura()
{
    return this->_buffArmadura;
}

int Personagem::GetBuffArmaduraMagica()
{
    return this->_buffArmaduraMagica;
}

int Personagem::GetBuffEsquiva()
{
    return this->_buffEsquiva;
}

int Personagem::GetBuffPrecisao()
{
    return this->_buffPrecisao;
}

int Personagem::GetBuffSorte()
{
    return this->_buffSorte;
}

int Personagem::GetBuffArma()
{
    return this->_buffArma;
}

int Personagem::GetBuffFerramenta()
{
    return this->_buffFerramenta;
}

int Personagem::GetModificadorEsquiva()
{
    return this->_modificadorEsquiva;
}

int Personagem::GetModificadorDefesa()
{
    return this->_modificadorDefesa;
}

int Personagem::GetModificadorQuantidadeAtaques()
{
    return this->_modificadorQuantidadeAtaques;
}

int Personagem::GetStatus()
{
    return this->_status;
}