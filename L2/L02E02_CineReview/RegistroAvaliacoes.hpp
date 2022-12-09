#ifndef REGISTROAVALIACOES_H
#define REGISTROAVALIACOES_H

#include <map>
#include "Review.hpp"
#include "Usuario.hpp"

class RegistroAvaliacoes {

    public:

        void adicionar_usuario(std::string login, std::string nome);
        void adicionar_filme(std::string nome, std::string genero, int duracao);
        void adicionar_review(int id_filme, std::string login_usuario, std::string comentario, float nota);
        void imprimir_estatisticas_usuarios();
        void imprimir_registro_geral();
        void imprimir_reviews_usuario(std::string login);

    private:

        std::map<std::string, Usuario> _usuarios;
        std::map<int, Filme> _filmes;
};

#endif