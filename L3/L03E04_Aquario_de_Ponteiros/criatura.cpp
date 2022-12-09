#include "criatura.hpp"

Criatura::Criatura(std::string subtipo) : _subtipo(subtipo) {
    std::cout << "Criatura:" << _subtipo << std::endl;
}

Criatura::~Criatura() {
    std::cout << "~Criatura:" << _subtipo << std::endl;
}

std::string Criatura::get_subtipo() {
    return _subtipo;
}

void Criatura::print_info() {
    std::cout << "Info: " << _subtipo << std::endl;
}

