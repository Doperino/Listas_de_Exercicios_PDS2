#ifndef CATALOGO_H
#define CATALOGO_H

#include <vector>
#include <iostream>
#include <string>
#include "Brinquedo.hpp"
#include "Livro.hpp"
#include "Eletronico.hpp"

class Catalogo {
    private:
        std::vector<Produto*> _produtos;
        int _id = 0;

    public:
        void adicionar_produto(std::string nome, int idade_minima, float valor);
        void adicionar_produto(std::string titulo, std::string autor, int ano, float valor);
        void adicionar_produto(std::string marca, std::string modelo, float valor);
        Produto* buscar_produto(int id);
        void imprimir();
};      

#endif