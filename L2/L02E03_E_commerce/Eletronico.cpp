#include "Eletronico.hpp"

Eletronico::Eletronico(int id, float valor, std::string marca, std::string modelo) : Produto(id, valor), _marca(marca), _modelo(modelo) {}

void Eletronico::imprimir_info() {
    Produto::imprimir_info();
    std::cout << get_id_produto() << "\t" << "Eletronico" << "\t" << _marca << "\t" << _modelo << "\t";
    std::cout << "R$ ";
    std::cout << std::fixed;
    std::cout << std::setprecision(2) << get_valor_produto() << std::endl;
}

Eletronico::~Eletronico() {
}