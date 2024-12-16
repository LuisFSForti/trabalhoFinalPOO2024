#include "Controller/printFile.hpp"

void PrintFile::PrintError(int typeError)         //Se houve um erro na impressão
{ 
    switch (typeError) //Seleciona o erro e alerta
    {
        case 0:
            std::cout << "Invalid File Name: " << _fileName << std::endl;
            break;

        case 1:
            std::cout << "Error when opening " << _fileName << std::endl;
    
        default:
            std::cout << "Unknow error." << std::endl;
            break;
    }
}

PrintFile::PrintFile(std::string fileName)        //Construtor com endereço do arquivo
{
    _fileName = fileName;
}

int PrintFile::PrintText(bool erase)           //Imprime o texto, apagando a tela se necessário
{
    if(_fileName == "") //Se o endereço estiver vazio
    {
        PrintError(0); //Alerta o erro
        return -1; //Retorna que deu erro
    }

    if(erase) 
    { 
        //system("cls"); // WINDOWS 
        system("clear"); 
    } 

    //Abre o arquivo
    std::ifstream f(_fileName);

    //Se houve um erro ao abrir
    if (!f.is_open()) {
        //Alerta o erro
        PrintError(1);
        return -1; //Retorna que deu erro
    }

    //Auxiliar
    std::string s;
    while (getline(f, s)) //Pega a linha atual
        std::cout << s << std::endl; //Escreve na tela

    //Fecha o arquivo e sai
    f.close();   
    return 0; //Retorna que não deu erro    
}