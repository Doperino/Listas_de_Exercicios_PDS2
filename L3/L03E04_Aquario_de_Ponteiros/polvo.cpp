#include "polvo.hpp"

Polvo::Polvo(double qi) : Criatura("Polvo"), _qi(qi) {
    std::cout << "Polvo:" << _subtipo << std::endl;
} 

Polvo::~Polvo() {
    std::cout << "~Polvo:" << _subtipo << std::endl;
}

double Polvo::get_qi() {
    return _qi;
}

void Polvo::print_info() {
    Criatura::print_info();

    std::cout << "\t" << "QI: " << _qi << std::endl;
}

std::list<std::unique_ptr<Criatura>> Polvo::acasalar(std::shared_ptr<Criatura> c) {

    std::list<std::unique_ptr<Criatura>> lista_criaturas;

    if (_subtipo != c->get_subtipo()) {
        lista_criaturas.clear();  
        return lista_criaturas;
    }
  
    std::shared_ptr<Polvo> aux;
    aux = std::dynamic_pointer_cast<Polvo>(c);
  
    double qi_filhote = (_qi + aux->_qi) / 2; 
    lista_criaturas.push_back(std::unique_ptr<Polvo>(new Polvo(qi_filhote)));
    
    return lista_criaturas;
}