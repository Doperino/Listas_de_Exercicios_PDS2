#include "Brinquedo.hpp"

Brinquedo::Brinquedo(int id, float valor, std::string nome, int idade_minima) : Produto(id, valor), _nome(nome), _idade_minima(idade_minima) {}

void Brinquedo::imprimir_info() {
    Produto::imprimir_info();
    std::cout << get_id_produto() << "\t" << "Brinquedo" << "\t" << _nome << "\t" << _idade_minima << "\t" << "R$ ";
    std::cout << std::fixed;
    std::cout << std::setprecision(2) << get_valor_produto() << std::endl;
    
}

Brinquedo::~Brinquedo() {
}