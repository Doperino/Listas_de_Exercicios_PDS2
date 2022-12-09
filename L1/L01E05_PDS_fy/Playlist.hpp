#ifndef PLAYLIST_H
#define PLAYLIST_H

#include <string>
#include "Musica.hpp"

struct Playlist {

    //Defining List
    Musica *head = nullptr;
    Musica *tail = nullptr;
    int _size = 0;

    void atualiza_id();
    //Defining operations
    void adicionar_musica_inicio(Musica *musica);

    void adicionar_musica(std::string nome, std::string artista, std::string album, float duracao);
    
    Musica *buscar_musica(std::string nome, std::string artista);

    void remover_musica(int id);

    void favoritar_musica(int id);

    void desfavoritar_musica(int id);

    void imprimir();

};

#endif