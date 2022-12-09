#ifndef REVIEW_H
#define REVIEW_H

#include <string>
#include "Filme.hpp"

class Filme;

class Review {

    public:

        //Constructor for the review
        Review(Filme* filme, std::string comentario, float nota);

        //Destructor for the review
        ~Review();

        //Getters for the name, comment and evaluation
        std::string get_comentario_filme();
        float get_nota_filme();
        Filme* get_filme();

    private:

        Filme* _filme;
        std::string _comentario;
        float _nota;
};

#endif