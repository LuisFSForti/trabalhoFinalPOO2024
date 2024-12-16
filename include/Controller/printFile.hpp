#ifndef PRINTFILE_HPP
#define PRINTFILE_HPP

#include <iostream>
#include <stdio.h>
#include <fstream>

class PrintFile
{
    std::string _fileName; //Endereço do arquivo

    private:
        void PrintError(int typeError = -1);         //Se houve um erro na impressão
        
    public:
        PrintFile(std::string fileName = "");        //Construtor com endereço do arquivo
        
        int PrintText(bool erase = false);           //Imprime o texto, apagando a tela se necessário
};

#endif