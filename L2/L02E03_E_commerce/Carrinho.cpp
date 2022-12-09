#include "Carrinho.hpp"

void Carrinho::adicionar_pedido(Produto* produto, int quantidade) {
    _pedido = new Pedido(produto, quantidade);
    _pedidos.push_back(_pedido);
}

void Carrinho::imprimir_resumo() {
    float valor_total_carrinho = 0;
    float valor_produto = 0;
    int quantidade_produto = 0;


    for(Pedido* n : _pedidos) {
        Produto* produto = n->get_produto();
        produto->imprimir_info();
        valor_produto = produto->get_valor_produto();

        quantidade_produto = n->get_quantidade_pedido();
        valor_total_carrinho += quantidade_produto * valor_produto;

        std::cout << "Qtde: " << quantidade_produto << " Total produto: " << "R$ "; 
        std::cout << std::fixed << std::setprecision(2) << n->get_valor_total() << std::endl;
    }
    
    std::cout << "Total carrinho: " << "R$ " << std::fixed << std::setprecision(2) << valor_total_carrinho << std::endl;
}

Pedido* Carrinho::get_pedido() {
    return _pedido;
}