#include "caminhao.hpp"

Caminhao::Caminhao(std::string subtipo, int velo_max, int n_passageiros, int carga_max) : Veiculo(subtipo, velo_max, n_passageiros), _carga_max(carga_max) {}

Caminhao::Caminhao(int velo_max, int n_passageiros, int carga_max) : Veiculo("Caminhao", velo_max, n_passageiros), _carga_max(carga_max) {}

Caminhao::~Caminhao() {
    std::cout << std::endl << "Destrutor Caminhao" << std::endl;
}

int Caminhao::estima_preco() {
    Veiculo::estima_preco();

    int preco_estimado = 50000 + 100 * _carga_max + 10 * _velo_max;

    return preco_estimado;
}

void Caminhao::print_info() {
    Veiculo::print_info();

    std::cout << "\t" << "Carga maxima: " << _carga_max << " kg";

}
