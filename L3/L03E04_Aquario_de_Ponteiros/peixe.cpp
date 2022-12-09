#include "peixe.hpp"

Peixe::Peixe(double peso, char sexo) : Criatura("Peixe"), _peso(peso), _sexo(sexo) {
    std::cout << "Peixe:" << _subtipo << std::endl;
}

Peixe::~Peixe() {
    std::cout << "~Peixe:" << _subtipo << std::endl;
}

double Peixe::get_peso() {
    return _peso;
}

char Peixe::get_sexo() {
    return _sexo;
}

void Peixe::print_info() {
    Criatura::print_info();

    std::cout << "\t" << "Peso: " << _peso << " kg" << std::endl;
    std::cout << "\t" << "Sexo: " << _sexo << std::endl;
}

std::list<std::unique_ptr<Criatura>> Peixe::acasalar(std::shared_ptr<Criatura> c) {

    std::list<std::unique_ptr<Criatura>> lista_criaturas;

    if (c->get_subtipo() != "Peixe") {
        lista_criaturas.clear();  
        return lista_criaturas;
    }
    
    std::shared_ptr<Peixe> aux;
    aux = std::dynamic_pointer_cast<Peixe>(c);

    if (_sexo == aux->_sexo) {
        lista_criaturas.clear();  
        return lista_criaturas;
    }

    double peso_filhotes = (_peso + aux->_peso) / 2;
    lista_criaturas.push_back(std::unique_ptr<Peixe>(new Peixe(peso_filhotes, 'F')));
    lista_criaturas.push_back(std::unique_ptr<Peixe>(new Peixe(peso_filhotes, 'M')));
    
    return lista_criaturas;
}
