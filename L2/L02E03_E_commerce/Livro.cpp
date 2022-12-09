#include "Livro.hpp"

Livro::Livro(int id, float valor, std::string titulo, std::string autor, int ano) : Produto(id, valor), _titulo(titulo), _autor(autor), _ano(ano) {}

void Livro::imprimir_info() {
    Produto::imprimir_info();
    
    std::cout << get_id_produto() << "\t" << "Livro" << "\t" << _titulo << "\t" << _autor << "\t" << _ano << "\t";
    std::cout << "R$ ";
    std::cout << std::fixed;
    std::cout << std::setprecision(2) << get_valor_produto() << std::endl;
}

Livro::~Livro() {
}