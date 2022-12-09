#include "Playlist.hpp"

void Playlist::atualiza_id() {
    Musica *aux = head;
    int count = 0;

    while(aux != nullptr) {
        count++;
        aux->_id = count;
        aux = aux->next;
    }
}

void Playlist::adicionar_musica_inicio(Musica *musica) {
    Musica *aux = musica;
    if(head == nullptr) {
        head = aux;
        tail = aux;
    }
    else {
        aux->next = head;
        head = aux;
    }
}

void Playlist::adicionar_musica(std::string nome, std::string artista, std::string album, float duracao) {
    Musica *aux = new Musica(1, nome, artista, album, duracao);
    if(head == nullptr) {
        head = aux;
        tail = aux;
    }
    else {
        aux->_id = tail->_id + 1;
        tail->next = aux;
        tail = aux;
    }
    _size++;
}

Musica *Playlist::buscar_musica(std::string nome, std::string artista) {
    Musica* aux = head;
    //While para percorrer toda a lista
    while(aux != nullptr) {
        //Verify if the there's a artist with a specific song in the playlist
        if(aux->_nome == nome && aux->_artista == artista) {
            return aux;
        }
        aux = aux->next;
    }
    return nullptr;
}

void Playlist::remover_musica(int id) {
    Musica *current = head;
    Musica *previous = nullptr;

    while(current != nullptr) {
        if(current->_id == id) {
            if(previous == nullptr) { //Verify if the exclusion will be in the Head
                head = current->next;
            }
            else if(current->next == nullptr) { //Verify if the exclusion will be in the Tail
                previous->next = nullptr;
                tail = previous;
            }
            else { //Verify if the exclusion will be in the middle
                previous->next = current->next; 
            }
            delete current;
            _size--;
            return;
        }
        previous = current;
        current = current->next;
    }
}

void Playlist::favoritar_musica(int id) {
    Musica *current = head;
    Musica *previous = nullptr;

    while(current != nullptr) {
        if(current->_id == id) {
            if(!current->_favorita) { //Do something if the music isn't a favorite one
                current->_favorita = true;
                
                if(previous == nullptr) {  
                }
                else if(current->next == nullptr) {
                    previous->next = nullptr;
                    tail = previous;
                }
                else {
                    previous->next = current->next;
                }

                current->next = head;
                head = current;
            }
            return;
        }
        previous = current;
        current = current->next;
    }
}

void Playlist::desfavoritar_musica(int id) {
    Musica *current = head;
    Musica *previous = nullptr;

    while(current != nullptr) {
        if(current->_id == id) {
            if(current->_favorita) { //Do something if the music isn't a favorite one
                current->_favorita = false;
                
                if(current == tail) {  
                }
                else if(previous == nullptr) {
                    head = current->next;
                }
                else {
                    previous->next = current->next;
                }
                tail->next = current;
                current->next = nullptr;
                tail = current;
            }
            return;
        }
        previous = current;
        current = current->next;
    }
}

void Playlist::imprimir() {
    Musica *aux = head;
    float time = 0;

    while(aux != nullptr) {
        aux->imprimir_dados();
        time += aux->_duracao;
        aux = aux->next;
    }

    int hours = time/60;
    int minutes = time - hours*60;
    int seconds = round(((time - hours*60) - minutes)*60);

    std::cout << "Tempo total: ";
    //format the printing with width of 2 (including existing caracters).
    std::cout << std::setfill('0') << std::setw(2);
    std::cout << hours << ":";
    std::cout << std::setfill('0') << std::setw(2);
    std::cout << minutes << ":";
    std::cout << std::setfill('0') << std::setw(2);
    std::cout << seconds << std::endl;

}