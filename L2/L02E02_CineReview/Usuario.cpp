#include "Usuario.hpp"

Usuario::Usuario (std::string login, std::string nome) : _login(login), _nome(nome) {}

Usuario::~Usuario () {  
    
    //std::cout << "objects is being deleted" << std::endl; 
}

void Usuario::associar_review (Review* review) {

    _reviews.push_back(*review);
}

void Usuario::imprimir_info () {
    
    std::cout << _nome << "\t" << "Reviews: " << _reviews.size() << std::endl;
  
}

void Usuario::imprimir_reviews () {

    if (_reviews.size() == 0) {
        std::cout << "Usuario " << _nome << " nao possui reviews!" << std::endl;
        return;
    }

    imprimir_info();
  
    Filme* filme;
    std::string nome_filme;
    std::string comentario_filme;
    float nota_filme;
  
    for (Review n : _reviews) {

        filme = n.get_filme();
        nome_filme = filme->get_nome_filme();
        comentario_filme = n.get_comentario_filme();
        nota_filme = n.get_nota_filme();
      
        std::cout << nome_filme << "\t" << comentario_filme << "\t";
        std::cout << std::fixed;
        std::cout << std::setprecision(1) << nota_filme << std::endl;
    }
}

std::string Usuario::get_login_usuario () {
    return _login;
}

std::string Usuario::get_nome_usuario () {
    return _nome;
}
