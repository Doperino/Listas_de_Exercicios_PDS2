#ifndef PILHA_H
#define PILHA_H

#include <iostream>

template<class T>
class Pilha {
    private:
        int _max_tam;
        int _top = -1;
        T* _arr = new T[_max_tam];

    public:
        Pilha(int max_tam) : _max_tam(max_tam) {}
        
        ~Pilha() {
            delete[] _arr;
        }
        
        bool push(const T& novo_e) {
            
            if ((_top + 1) == _max_tam) {
                return false;
            }
            else {
                if (_top < 0)
                    _arr[0] = novo_e;
                else
                    _arr[_top + 1] = novo_e;
                
                _top++;
                return true;
            }
        }

        bool pop(T& valor) {
            if (_top < 0)
                return false;
            
            valor = _arr[_top];
            _top--;
            return true;
        }

        bool get_maior (T& valor) {
            if (_top < 0)
                return false;
            
            T maior = _arr[0];

            for (int i = 1; i <= _top; i++) {
                if (_arr[i] > maior)
                    maior = _arr[i];
            }
            valor = maior;
            return true;
        }

        bool vazia() {
            if (_top < 0)
                return true;
            
            return false;
        }

        void print() {
            for (int i = 0; i <= _top; i++) {
                std::cout << _arr[i] << std::endl;
            }
        }
};

#endif