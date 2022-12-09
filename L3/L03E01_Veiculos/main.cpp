#include "caminhao_autonomo.hpp"
#include "caminhao.hpp"
#include "veiculo.hpp"
#include <list>
#include <iostream>
#include <map>

void init_selecao (std::map<char, std::string> & selecao) {
    selecao.emplace('a', "add_c");
    selecao.emplace('b', "add_ca");
    selecao.emplace('c', "rm");
    selecao.emplace('d', "print");
}

char checa_selecao(std::map<char, std::string> selecoes, std::string selecao) {
    for (auto it = selecoes.begin(); it != selecoes.end(); ++it) {
        if(selecao == it->second)
           return it->first;
      }
    return 0;
}

void print_list(std::list<Veiculo*> l) {
    for(Veiculo* n : l) {
        n->print_info();
    }
}

void rm_id(std::list<Veiculo*> &l, int id) {

    std::list<Veiculo*>::iterator it;
    it = l.begin();
    int id_atual;
    for(Veiculo* n : l) {
        id_atual = n->get_id();

        if(id_atual == id) {
            delete n;
            l.erase(it);
            return;
        }

        ++it;
    }
}

int main () {

    Caminhao* caminhao;
    CaminhaoAutonomo* caminhao_autonomo;
    std::list<Veiculo*> veiculos;
    std::string selecao;
    std::string fabricante;
    int velocidade;
    int passageiros;
    int carga;
    int id;
    std::map<char, std::string> selecoes;
    init_selecao(selecoes);
    char id_selecao;
  
    while (std::cin >> selecao) {

        id_selecao = checa_selecao(selecoes, selecao);
        switch(id_selecao) {
          
            case 'a': {

                std::cin >> velocidade >> passageiros >> carga;
                caminhao = new Caminhao(velocidade, passageiros, carga);
                veiculos.push_back(caminhao);
                break;
            }

            case 'b': {

                std::cin >> velocidade >> passageiros >> carga >> fabricante;
                caminhao_autonomo = new CaminhaoAutonomo(velocidade, passageiros, carga, fabricante);
                veiculos.push_back(caminhao_autonomo);
                break;
            }

            case 'c': {

                std::cin >> id;
                rm_id(veiculos, id);
                break;
            }

            case 'd': {

                print_list(veiculos);
                break;
            }  
        }
    }
    
    return 0;
}