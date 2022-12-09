#ifndef ELETRONICO_H
#define ELETRONICO_H

#include "Produto.hpp"
#include <string>
#include <iomanip>
    
class Eletronico : public Produto {
    private:
        std::string _marca;
        std::string _modelo;
    
    public:
        Eletronico(int id, float valor, std::string marca, std::string modelo);
        ~Eletronico();
        void imprimir_info() override;
};

#endif