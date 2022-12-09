#ifndef CARRINHO_H
#define CARRINHO_H

#include <vector>
#include <iomanip>
#include "Pedido.hpp"
#include "Produto.hpp"

class Carrinho {
    private:
        std::vector<Pedido*> _pedidos;
        Pedido* _pedido;
    public:
        void adicionar_pedido(Produto* produto, int quantidade);
        void imprimir_resumo();
        Pedido* get_pedido();
};
#endif