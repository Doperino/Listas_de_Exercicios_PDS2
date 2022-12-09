#ifndef FILME_H
#define FILME_H

#include <string>
#include <vector>
#include <iostream>
#include <iomanip>
#include "Review.hpp"

class Review;

class Filme {

    public:

        //Constructor for the Film class. 
        Filme(int id, std::string nome, std::string genero, int duracao);
        ~Filme();

        //Adds the review into the set of the proper Film.
        Review* adicionar_review(std::string comentario, float nota);

        //Prints the consolidated evaluation of the film reviews
        void imprimir_nota_consolidada();

        std::string get_nome_filme();

    private:

        int _id;
        std::string _nome;
        std::string _genero;
        int _duracao;
  
        std::vector<Review> _reviews;


                
};

#endif