#include "Musica.hpp"

Musica::Musica(int id, std::string nome, std::string artista, std::string album, float duracao) {
    _id = id;
    _nome = nome;
    _artista = artista;
    _album = album;
    _duracao = duracao;
    _favorita = false;
}

Musica::Musica() {
}

void Musica::imprimir_dados() {
    int minutes = _duracao;
    int seconds = round((_duracao - minutes)*60);
    std::cout << _id << "\t" << _album << "\t" << _artista << "\t" << _nome << "\t";

    //format the printing with width of 2 (including existing caracters). 
    std::cout << std::setfill('0') << std::setw(2);
    std::cout << minutes << ":";
    std::cout << std::setfill('0') << std::setw(2);
    std::cout << seconds << "\t" << _favorita << std::endl;
    }