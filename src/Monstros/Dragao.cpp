#include "Monstros/Dragao.hpp"

//Golpeia um inimigo, priorizando a linha de frente
void Dragao::Atacar(std::vector<Personagem> alvos)
{
    int posAlvo;
    do
    {
        int aleatorio = rand() % 20;
        
        //Para priorizar a linha de frente
        if(aleatorio <= 7) //Maior chance de ser o Paladino
        {
            posAlvo = 1;
        }
        else if(aleatorio <= 13) //Depois o bárbaro
        {
            posAlvo = 0;
        }
        else if(aleatorio <= 17) //O bardo
        {
            posAlvo = 2;
        }
        else //Por fim, o mago
        {
            posAlvo = 3;
        }
    } while (alvos.at(posAlvo).GetVida() <= 0); //Até achar um alvo válido

    //Pega o alvo
    Personagem alvo = alvos.at(posAlvo);

    //Verifica se o ataque acerta
    if(rand()%20 + this->_precisao + this->_buffPrecisao >= (alvo.GetEsquiva() + alvo.GetBuffEsquiva()) * alvo.GetModificadorEsquiva() + 10)
        //Se sim, calcula o dano
        this->CausarDano(alvo);
}
    
//Dano físico alto
void Dragao::CausarDano(Personagem alvo)
{
    //Calcula o crítico
    bool critico = rand() % 20 + _sorte >= 20;

    //Calcula o dano
    //(1 + critico) = 1 ou 2
    int dano = (rand() % 10 + this->_arma + this->_buffArma) * (1 + critico);

    //Alerta o alvo que ele recebeu dano físico e quanto
    alvo.ReceberDanoFisico(dano);
}
    
//Dano físico alto em área
void Dragao::EfeitoAuxiliar(std::vector<Personagem> alvos)
{
    //Define que ele já usou sua habilidade auxiliar
    this->_mana = false;
    
    //Calcula o dano, sem crítico pois já é em área e alto
    int dano = rand()%10 + this->_ferramenta + this->_buffFerramenta;

    //Para cada herói
    for(int i = 0; i < alvos.size() - 1; i++)
    {
        //Alerta o alvo atual que recebeu dano físico e quanto
        alvos.at(i).ReceberDanoFisico(dano);
    }
}

std::string Dragao::ImprimirDados() const
{
    //Necessário pegar o código da Heloísa
    return "";
}

Dragao::Dragao(std::string id)
{
    //Inicializa o aleatorizador
    srand(time(NULL));

    this->_vidaMaxima = 150;
    this->_vida = this->_vidaMaxima;
    this->_armadura = 5;
    this->_esquiva = 0;

    this->_precisao = 4;
    this->_sorte = 1;
    this->_arma = 8;

    this->_ferramenta = 10; //Calor interno
    this->_armaduraMagica = this->_ferramenta; //Resistência mágica

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

    _idFile = id;
}