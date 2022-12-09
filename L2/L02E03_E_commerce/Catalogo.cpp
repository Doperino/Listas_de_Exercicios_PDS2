#include "Catalogo.hpp"

void Catalogo::adicionar_produto(std::string nome, int idade_minima, float valor) {
    _id++;
    Brinquedo* brinquedo = new Brinquedo(_id, valor, nome, idade_minima);
    _produtos.push_back(brinquedo);
}

void Catalogo::adicionar_produto(std::string titulo, std::string autor, int ano, float valor) {
    _id++;
    Livro* livro = new Livro(_id, valor, titulo, autor, ano);
    _produtos.push_back(livro);
}

void Catalogo::adicionar_produto(std::string marca, std::string modelo, float valor) {
    _id++;
    Eletronico* eletronico = new Eletronico(_id, valor, marca, modelo);
    _produtos.push_back(eletronico);
}

Produto* Catalogo::buscar_produto(int id) {
    int id_produto = 0;
    for(Produto* n : _produtos) {
        id_produto = n->get_id_produto();

        if(id == id_produto) {
            return n;
        }
    }

    std::cout << "Produto não encontrado!" << std::endl;
    return nullptr;
}

void Catalogo::imprimir() {
    for(Produto*n : _produtos) {
        n->imprimir_info();
    }
}