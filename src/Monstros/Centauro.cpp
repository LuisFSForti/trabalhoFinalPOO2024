#include "Monstros/Centauro.hpp"

//Golpeia um inimigo, priorizando a linha de frente
void Centauro::Atacar(std::vector<Personagem*> alvos)
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
    } while (alvos.at(posAlvo)->GetVida() <= 0); //Até achar um alvo válido

    //Pega o alvo
    Personagem* alvo = alvos.at(posAlvo);

    //Verifica se o ataque acerta
    int dado = rand()%20;
    int ataque = dado + this->_precisao + this->_buffPrecisao;
    int esquiva = (alvo->GetEsquiva() + alvo->GetBuffEsquiva()) * alvo->GetModificadorEsquiva() + 10;

    std::cout << "Ataque: " << dado << " + " << this->_precisao << " + " << this->_buffPrecisao << " = " << ataque << std::endl;
    std::cout << "Esquiva ("<< Nomes[posAlvo] << "): (" << alvo->GetEsquiva() << " + " << alvo->GetBuffEsquiva() << ") *" << alvo->GetModificadorEsquiva() << " + 10 = " << esquiva << std::endl;

    if(ataque >= esquiva)
    {
        //Se sim, calcula o dano
        this->CausarDano(alvo);
    }
}

//Dano físico médio-alto    
void Centauro::CausarDano(Personagem* alvo)
{
    //Calcula se é um crítico
    bool critico = rand() % 20 + _sorte >= 20;
    //Calcula o dano
    //(1 + critico) = 1 ou 2
    int dano = (rand() % 10 + this->_arma + this->_buffArma) * (1 + critico);
    if(critico)
        std::cout << "Crítico!!!!" << std::endl;
    std::cout << "Acertou por " << dano << " de dano físico!" << std::endl << std::endl;

    //Alerta o alvo que ele recebeu dano físico e fala quanto
    alvo->ReceberDanoFisico(dano);
}
    
//Dano físico altíssimo em um inimigo
void Centauro::EfeitoAuxiliar(std::vector<Personagem*> alvos)
{
    //Marca que usou sua habilidade auxiliar
    this->_mana = false;

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
    } while (alvos.at(posAlvo)->GetVida() <= 0); //Até achar um alvo válido

    //Calcula o dano
    //Sem crítico, pois poderia ser massivo demais e injusto
    int dano = (rand() % 12 + this->_arma + this->_buffArma) * 2;

    //Alerta o alvo que ele recebeu dano físico e quanto
    alvos.at(posAlvo)->ReceberDanoFisico(dano);
}

void Centauro::ImprimirDados(std::ostream& out) const
{
    out << "O centauro está galopando furiosamente... \nSe prepare para uma pancada...\n";
    out << "==============================================\n";
}

Centauro::Centauro(std::string id)
{
    //Inicializa o aleatorizador
    srand(time(NULL));

    this->_vidaMaxima = 130;
    this->_vida = this->_vidaMaxima;
    this->_armadura = 3;
    this->_esquiva = 4;

    this->_precisao = 10;
    this->_sorte = 1;
    this->_arma = 10;

    this->_ferramenta = 0;
    this->_armaduraMagica = 0;

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

    _idFile = id;
}