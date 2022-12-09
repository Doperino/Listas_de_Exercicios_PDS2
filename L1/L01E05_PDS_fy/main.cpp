#include "Musica.hpp"
#include "Playlist.hpp"
#include "avaliacao_basica_playlist.hpp"

int main() {

    char data;
    Playlist playlist;
    std::string nome;
    std::string artista;
    std::string album;
    float duracao;

    while(std::cin >> data) {

        switch(data) {

            case 'a': {
                std::cin >> nome >> artista >> album >> duracao;
                playlist.adicionar_musica(nome, artista, album, duracao);
                break;
            }

            case 's': {
                std::cin >> nome >> artista;
                Musica *aux;
                aux = playlist.buscar_musica(nome, artista);
                aux->imprimir_dados();
                break;
            }

            case 'r': {
                std::cin >> nome >> artista;
                Musica *aux;
                aux = playlist.buscar_musica(nome, artista);
                playlist.remover_musica(aux->_id);
                break;
            }

            case 'f': {
                std::cin >> nome >> artista;
                Musica *aux;
                aux = playlist.buscar_musica(nome, artista);
                playlist.favoritar_musica(aux->_id);
                break;
            }

            case 'd': {
                std::cin >> nome >> artista;
                Musica *aux;
                aux = playlist.buscar_musica(nome, artista);
                playlist.desfavoritar_musica(aux->_id);
                break;
            }

            case 'p': {
                playlist.imprimir();
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