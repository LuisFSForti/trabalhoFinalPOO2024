#include "Personagens/Bardo.hpp"

//Ataca o inimigo
void Bardo::Atacar(std::vector<Personagem*> alvos)
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
    
//Dano psicológico baixo, alta chanca de crítico
void Bardo::CausarDano(Personagem* alvo)
{
    //Calcula o crítico
    bool critico = rand() % 20 + _sorte >= 20;

    //Calcula o dano
    //(1 + critico) = 1 ou 2
    int dano = (rand()%6 + this->_arma + this->_buffArma) * (1 + critico); //Dano psicológico, não tem resistência

    if(critico)
        std::cout << "Crítico!!!!" << std::endl;
    std::cout << "Acertou por " << dano << " de dano psicológico!" << std::endl << std::endl;

    //Alerta o alvo que recebeu dano psicológico e quanto
    alvo->ReceberDanoPsicologico(dano);
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
        alvos.at(i)->AplicarStatus(estavel); //Remove qualquer status sobre ele
    }
}

void Bardo::ImprimirDados(std::ostream& out) const
{
    Item consumivel = this->_consumivel;

    out  << "============================================================================================================\n";
    out << "                         BARDO                     " << std::to_string(this->_vida) <<  "/" + std::to_string(this->_vidaMaxima) << "                     STATUS\n";
    out << std::string(50 - this->Status().length()/2, ' ') << this->Status() << "\n";
    out << "============================================================================================================\n";

    if(this->_status == estavel || this->_status == amedrontado) //Se o bardo puder agir normalmente
    {
        if(this->_hasItem)
            out << "||  1. Zombar                     3. Consumir item  ||  Mana: " << this->_mana << "                       Esquiva: " << this->_esquiva << "\n";
        else
            out << "||  1. Zombar                     \033[31m3. Consumir item\033[0m  ||  Mana: " << this->_mana << "                       Esquiva: " << this->_esquiva << "\n";

        if(this->_mana) //Se tiver mana, escreve normalmente
            out << "||  2. Canção de restauração      4. Esquivar       ||  Arma: " << this->_arma << "                       Armadura: " << this->_armadura << "\n";
        else //Se não tiver, escreve em vermelho
            out << "||  \033[31m2. Canção de restauração\033[0m      4. Esquivar       ||  Arma: " << this->_arma << "                       Armadura: " << this->_armadura << "\n";
        out << "============================================================================================================\n";

        if(this->_hasItem)
        {
            out << "    Item Disponível: " << consumivel.GetNome() << "\n" ;
            out << "    Descricao: " << consumivel.GetDesc() << "\n";
            out << "============================================================================================================";

        }
    }
    else //Se estiver sob controle do inimigo
    {
        out << "||  1, 3, 4. Aceitar seu estado        2. Canção de restauração                                           ||\n";
        out << "============================================================================================================\n";
    }
}

Bardo::Bardo()
{
    //Inicializa o aleatorizador
    srand(time(NULL));

    this->_vidaMaxima = 35; 
    this->_vida = this->_vidaMaxima;
    this->_armadura = 2;
    this->_esquiva = 4;

    this->_precisao = 8;
    this->_sorte = 5;
    this->_arma = 3; //Dano baixo pois é psicológico

    this->_ferramenta = 2; //Instrumento
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
    this->_hasItem = false;
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