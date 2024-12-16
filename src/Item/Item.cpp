#include "Item/Item.hpp"

//Construtor da classe, todos os valores devem serem passados aqui
Item::Item(int cura, bool mana, int buffAtaque, float buffSorte, int buffFerramenta, 
int buffEsquiva, int buffArmadura, std::string nome, std::string desc)
{
    _cura = cura;
    _mana = mana;
    _buffAtaque = buffAtaque;
    _buffSorte = buffSorte;
    _buffFerramenta = buffFerramenta;
    _buffEsquiva = buffEsquiva;
    _buffArmadura = buffArmadura;
    _nome = nome;
    _desc = desc;
}

//Getters da classe
int Item::GetCura()
{
    return _cura;
}
bool Item::GetMana()
{
    return _mana;
}
int Item::GetBuffAtaque()
{
    return _buffAtaque;

}
int Item::GetBuffSorte()
{
    return _buffSorte;
}
int Item::GetBuffArmadura() 
{
    return _buffArmadura;
}
int Item::GetBuffEsquiva() 
{
    return _buffEsquiva;
}
int Item::GetBuffFerramenta() 
{
    return _buffFerramenta;
}
std::string Item::GetNome() 
{
    return _nome;
}
std::string Item::GetDesc() 
{
    return _desc;
}

std::ostream& operator<<(std::ostream& out, const Item& i)
{
    out << "  Item Encontrado: " << i._nome << "\n";
    out << "  Descricao: " << i._desc  << "\n";
    out << "============================================================================================================" << std::endl;

    return out;
}