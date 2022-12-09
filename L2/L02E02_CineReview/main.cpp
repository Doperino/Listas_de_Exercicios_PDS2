#include <iostream>
#include "Filme.hpp"
#include "RegistroAvaliacoes.hpp"
#include "Review.hpp"
#include "Usuario.hpp"
#include "avaliacao_basica_cinereview.hpp"

int main() {

    int id;
    char option;
    float nota;
    float duracao;
    std::string nome;
    std::string genero;
    std::string login;
    std::string comentario;
    RegistroAvaliacoes cine_review;
  
    while (std::cin >> option) {

        switch (option) {

            case 'u': {
  
                std::cin >> login >> nome;
                cine_review.adicionar_usuario (login, nome);
                break;
            }
  
            case 'f': {
  
                std::cin >> nome >> genero >> duracao;
                cine_review.adicionar_filme (nome, genero, duracao);
                break;
            }
  
            case 'r': {
  
                std::cin >> id >> login >> comentario >> nota;
                cine_review.adicionar_review (id, login, comentario, nota);
                break;
            }
  
            case 'p': {

                cine_review.imprimir_registro_geral ();
                break;
            }
  
            case 's': {

                cine_review.imprimir_estatisticas_usuarios ();
                break;
            }
  
            case 'l': {

                std::cin >> login;
                cine_review.imprimir_reviews_usuario(login);
                break;
            }
  
            case 'b': {

                avaliacao_basica();
                break;
            }
          
        }
      
    }
  
    return 0;
}