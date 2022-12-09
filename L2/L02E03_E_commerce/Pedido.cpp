#include "Pedido.hpp"

Pedido::Pedido(Produto* produto, int quantidade) : _produto(produto), _quantidade(quantidade) {}

double Pedido::get_valor_total() {
    float valor_produto = _produto->get_valor_produto();
    return valor_produto * _quantidade;
}

Produto* Pedido::get_produto() {
    return _produto;
}

int Pedido::get_quantidade_pedido() {
    return _quantidade;
}