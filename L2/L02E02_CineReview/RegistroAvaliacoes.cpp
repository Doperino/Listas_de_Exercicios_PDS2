#include "RegistroAvaliacoes.hpp"

void RegistroAvaliacoes::adicionar_usuario (std::string login, std::string nome) {
  
    Usuario usuario = Usuario (login, nome);
    _usuarios.emplace (login, usuario);
}

void RegistroAvaliacoes::adicionar_filme (std::string nome, std::string genero, int duracao) {
   
    int id_filme = _filmes.size() + 1;
  
    Filme filme = Filme (id_filme, nome, genero, duracao);
    _filmes.emplace (id_filme, filme);
}

void RegistroAvaliacoes::adicionar_review (int id_filme, std::string login_usuario, std::string comentario, float nota) {

    Review* review_filme;
  
    for (auto it = _filmes.begin (); it != _filmes.end (); ++it) {
      
        if (it->first == id_filme) {
            review_filme = it->second.adicionar_review(comentario, nota);
        }
    }
  
    for (auto it = _usuarios.begin (); it != _usuarios.end (); ++it) {
        std::string login_user = it->second.get_login_usuario ();
      
        if (login_user == login_usuario) {
            it->second.associar_review (review_filme);
        }
    }
}

void RegistroAvaliacoes::imprimir_estatisticas_usuarios () {
  
    for (auto it = _usuarios.begin (); it != _usuarios.end (); ++it) {
        it->second.imprimir_info();
    }
}

void RegistroAvaliacoes::imprimir_registro_geral () {
  
    for (auto it = _filmes.begin (); it != _filmes.end (); ++it) {
        it->second.imprimir_nota_consolidada();
    }    
}

void RegistroAvaliacoes::imprimir_reviews_usuario (std::string login) {

    for (auto it = _usuarios.begin (); it != _usuarios.end (); ++it) {

        std::string login_usuario = it->second.get_login_usuario();
      
        if (login_usuario == login)
            it->second.imprimir_reviews();
    }
}