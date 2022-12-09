#ifndef LIVRO_H
#define LIVRO_H

#include <iostream>
#include <iomanip>
#include <string>
#include "Produto.hpp"

class Livro : public Produto {
    private:
        std::string _titulo;
        std::string _autor;
        int _ano;

    public:
        Livro(int id, float valor, std::string titulo, std::string autor, int ano);
        ~Livro();
        void imprimir_info() override;
};
#endif