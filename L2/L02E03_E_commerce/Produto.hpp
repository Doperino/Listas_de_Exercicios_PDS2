#ifndef PRODUTO_H
#define PRODUTO_H

#include <iostream>

class Produto {
    private:
        int _id;
        float _valor_unitario;

    public:
        Produto();
        Produto(int id, float valor_unitario);
        virtual void imprimir_info() = 0;
        float get_valor_produto();
        int get_id_produto();
};

#endif