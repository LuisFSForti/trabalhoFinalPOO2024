#ifndef PRINTFILE_HPP
#define PRINTFILE_HPP

#include <iostream>
#include <stdio.h>
#include <fstream>

class PrintFile
{
    std::string _fileName;

    private:
        
        void PrintError(int typeError = -1) 
        { 
            switch (typeError)
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

    public:

        PrintFile(std::string fileName = "") 
        {
            _fileName = fileName;
        }

        int PrintText()
        {
            if(_fileName == "")
            {
                PrintError(0);
                return -1;
            }

            std::ifstream f(_fileName);

            if (!f.is_open()) {
                PrintError(1);
                return -1;
            }

            std::string s;
            while (getline(f, s))
                std::cout << s << std::endl;

            f.close();   
            return 0;         
        }

};

#endif