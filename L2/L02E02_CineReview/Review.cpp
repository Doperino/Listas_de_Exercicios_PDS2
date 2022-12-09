#include "Review.hpp"

Review::Review (Filme* filme, std::string comentario, float nota) : _filme(filme), _comentario(comentario), _nota(nota) {};

Review::~Review () {
    //std::cout << "objects is being deleted" << std::endl;
}

float Review::get_nota_filme () {
    return _nota;
}

Filme* Review::get_filme () {
    return _filme;
}

std::string Review::get_comentario_filme () {
    return _comentario;
}