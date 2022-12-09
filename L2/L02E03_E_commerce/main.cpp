// NÃO ALTERE ESSA LINHA
#include "avaliacao_basica_ecommerce.hpp"
#include "Brinquedo.hpp"
#include "Carrinho.hpp"
#include "Catalogo.hpp"
#include "Eletronico.hpp"
#include "Livro.hpp"
#include "Pedido.hpp"
#include "Produto.hpp"
#include <iostream>

int main() {

    std::string nome;
    std::string marca;
    std::string modelo;
    std::string titulo;
    std::string autor;
    int id;
    int idade;
    int ano;
    int quantidade;
    float valor;
    char selecao;
    Catalogo catalogo;
    Produto* produto;
    Carrinho carrinho;

    while(std::cin >> selecao) {

        switch(selecao) {

            case 'q': {
                std::cin >> nome >> idade >> valor;
                catalogo.adicionar_produto(nome, idade, valor);
                break;
            }

            case 'l': {
                std::cin >> titulo >> autor >> ano >> valor;
                catalogo.adicionar_produto(titulo, autor, ano, valor);
                break;
            }

            case 'e': {
                std::cin >> marca >> modelo >> valor;
                catalogo.adicionar_produto(marca, modelo, valor);
                break;
            }

            case 'c': {
                catalogo.imprimir();
                break;
            }

            case 'p': {
                std::cin >> id >> quantidade;

                produto = catalogo.buscar_produto(id);
                carrinho.adicionar_pedido(produto, quantidade);
                
                break;
            }

            case 'r': {
                carrinho.imprimir_resumo();
                break;
            }


            case 'b': {
                avaliacao_basica();
                break;
            }
        }
    }
    return 0;
}