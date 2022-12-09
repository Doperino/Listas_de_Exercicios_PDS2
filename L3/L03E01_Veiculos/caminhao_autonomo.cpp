#include "caminhao_autonomo.hpp"

CaminhaoAutonomo::CaminhaoAutonomo(int velo_max, int n_passageiros, int carga_max, std::string fabricante) : Caminhao("CaminhaoAutonomo", velo_max, n_passageiros, carga_max), _fabricante(fabricante) {}

CaminhaoAutonomo::~CaminhaoAutonomo() {
    std::cout << std::endl << "Destrutor CaminhaoAutonomo" << std::endl;
}

int CaminhaoAutonomo::estima_preco() {

    int preco_estimado = 0;
    if (_fabricante == "Tesla") 
        preco_estimado = 500000 + 100 * _carga_max + 10 * _velo_max;
    else
        preco_estimado = 400000 + 100 * _carga_max + 10 * _velo_max;

      return preco_estimado;
        
}

void CaminhaoAutonomo::print_info() {
    Caminhao::print_info();

    std::cout << "\t" << "Fabricante: " << _fabricante;
}