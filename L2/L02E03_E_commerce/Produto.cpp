#include "Produto.hpp"

Produto::Produto() : _id(0), _valor_unitario(0) {}
Produto::Produto(int id, float valor_unitario) : _id(id), _valor_unitario(valor_unitario) {}

void Produto::imprimir_info() {}

float Produto::get_valor_produto() {
    return _valor_unitario;
}

int Produto::get_id_produto() {
    return _id;
}

