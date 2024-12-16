#include "Personagens/Paladino.hpp"

//Ataca o inimigo
void Paladino::Atacar(std::vector<Personagem*> alvos)
{
    //Pega o monstro
    Personagem* alvo = alvos.at(4);

    //Para cada ataque
    for(int i = 0; i < this->_qtdAtaques + this->_modificadorQuantidadeAtaques; i++)
    {
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
}

//Dano físico médios    
void Paladino::CausarDano(Personagem* alvo)
{
    //Calcula o crítico
    bool critico = rand() % 20 + _sorte >= 20;

    //Calcula o dano
    //(1 + critico) = 1 ou 2
    int dano = (rand()%12 + this->_arma + this->_buffArma) * (1 + critico);

    if(critico)
        std::cout << "Crítico!!!!" << std::endl;
    std::cout << "Acertou por " << dano << " de dano físico!" << std::endl << std::endl;

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

    out  << "============================================================================================================\n";
    out << "                         PALADINO                  " << std::to_string(this->_vida) <<  "/" + std::to_string(this->_vidaMaxima) << "                     STATUS\n";
    out << std::string(50 - this->Status().length()/2, ' ') << this->Status() << "\n";
    out << "============================================================================================================\n";

    if(this->_hasItem)
        out << "||  1. Ataque de espada           3. Consumir item  ||  Mana: " << this->_mana << "                       Esquiva: " << this->_esquiva + this->_buffEsquiva << "\n";
    else
        out << "||  1. Ataque de espada           \033[31m3. Consumir item\033[0m  ||  Mana: " << this->_mana << "                       Esquiva: " << this->_esquiva + this->_buffEsquiva << "\n";
    if(this->_mana) //Se tiver mana, escreve normalmente
        out << "||  2. Cura divina                4. Esquivar       ||  Arma: " << this->_arma + this->_buffArma << "                       Armadura: " << this->_armadura + this->_buffArmadura + this->_modificadorDefesa << "\n";
    else //Se não tiver, escreve em vermelho
        out << "||  \033[31m2. Cura divina\033[0m                4. Esquivar       ||  Arma: " << this->_arma + this->_buffArma << "                       Armadura: " << this->_armadura + this->_buffArmadura + this->_modificadorDefesa << "\n";
    out << "============================================================================================================\n";
   
    if(this->_hasItem)
    {
        out << consumivel;
       /*  out << "    Item Disponível: " << consumivel.GetNome() << "\n" ;
        out << "    Descricao: " << consumivel.GetDesc() << "\n";
        out << "============================================================================================================";
 */
    }  
}

Paladino::Paladino()
{
    //Inicializa o aleatorizador
    srand(time(NULL));

    this->_vidaMaxima = 50;
    this->_vida = this->_vidaMaxima;
    this->_armadura = 5;
    this->_esquiva = 3;

    this->_precisao = 6;
    this->_sorte = 1;
    this->_arma = 5;
    this->_qtdAtaques = 2;

    this->_ferramenta = 2; //Símbolo divinio
    this->_armaduraMagica = this->_ferramenta; //Resistência divina

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