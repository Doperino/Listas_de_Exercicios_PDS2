#include "Filme.hpp"

Filme::Filme (int id, std::string nome, std::string genero, int duracao) : _id(id), _nome(nome), _genero(genero), _duracao(duracao) {};

Filme::~Filme () {

    //std::cout << "objects is being deleted" << std::endl;
    
}

Review* Filme::adicionar_review (std::string comentario, float nota) {

    Filme* aux = new Filme(_id, _nome, _genero, _duracao);
    Review* filme_atual = new Review(aux, comentario, nota);
    _reviews.push_back(*filme_atual);

    return filme_atual;
    
}

void Filme::imprimir_nota_consolidada() {

    float nota = 0;
    float nota_media_av = 0;

    for (Review n : _reviews)
        nota += n.get_nota_filme();

    if (nota != 0)
        nota_media_av = nota / _reviews.size();

    std::cout << _nome << "\t" << "Reviews: " << _reviews.size() << "\t";
    std::cout << "Nota Media: ";
    std::cout << std::fixed;
    std::cout << std::setprecision(1) << nota_media_av << std::endl;
}

std::string Filme::get_nome_filme() {
    return _nome;
}