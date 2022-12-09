#ifndef MUSICA_H
#define MUSICA_H

#include <string>
#include <iostream>
#include <iomanip>
#include <cmath>

struct Musica {
    
    //Attributes definitions
    int _id;
    std::string _nome;
    std::string _artista;
    std::string _album;
    float _duracao;
    bool _favorita;

    //Applying the concept of lists. When a music is added to the list,
    //There's no next music, she'll become the last one.
    Musica *next = nullptr;
    Musica();
    Musica(int id, std::string nome, std::string artista, std::string album, float duracao);
    void imprimir_dados();
};

#endif