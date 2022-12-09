#ifndef USUARIO_H
#define USUARIO_H

#include "Review.hpp"
#include <vector>
#include <string>
#include <iostream>
#include <iomanip>

class Review;

class Usuario {

    public:

        //Constructor of the User. Sets it's values
        Usuario (std::string login, std::string nome);
        //Demolisher of the User. Deletes from memory
        ~Usuario ();

        //Inserts the review into the set of reviews
        void associar_review (Review* review);

        //Prints the info about the user, like name and number of evaluations
        void imprimir_info ();

        //Prints the info about the user, and all the info about his reviews
        void imprimir_reviews ();

        //Getters to access private members
        std::string get_login_usuario();
        std::string get_nome_usuario();

    private:

        std::string _login;
        std::string _nome;
        std::vector<Review> _reviews;

};

#endif