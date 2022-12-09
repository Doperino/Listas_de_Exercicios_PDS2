#include "Robo.hpp"
#include <iostream>

using namespace std;

Robo::Robo(int id, Ponto2D ponto, bool status) {
    _id = id;
    _ponto = ponto;
    _com_bola = status;
}

void Robo::mover(double v, double th, double t) {
    //Decomposição Vetorial
    double x = cos(th) * v * t;
    double y = sin(th) * v * t;

    //Atualização dos pontos do Robô
    _ponto._x += x;
    _ponto._y += y;

    //Decréscimo da energia por causa do movimento
    _energia -= v * t;
}

double Robo::calcular_distancia(Robo *robo) {
    double dx = _ponto._x - robo->_ponto._x;
    double dy = _ponto._y - robo->_ponto._y;
    return sqrt(dx*dx + dy*dy);
}

Robo *Robo::determinar_robo_mais_proximo(Robo **naves, int n) {

    //variável utilizada para que somente os valores da lista sejam considerados
    double menor = 99999;

    double distancia = 0;
    int posrobo;
    for (int i = 0; i < n; i++) {
        //Descarta a possibilidade do mesmo robô ser considerado
        if(naves[i]->_id != _id) {
            distancia = _ponto.calculaDistancia(naves[i]->_ponto);
            if(distancia <= menor) {
                menor = distancia;
                posrobo = i;
            }
        }
    }
    return naves[posrobo];
}

void Robo::passar_bola(Robo **time, int n) {
    Robo *robo_prox;
    if(_com_bola) {
        robo_prox = determinar_robo_mais_proximo(time, n);
        robo_prox->_com_bola = true;
        _com_bola = false;
    }
    else
        cout << "Estou sem a bola!" << endl;
}

void Robo::imprimir_status() {
    cout << _id << '\t' << _ponto._x << '\t' << _ponto._y << '\t' << _com_bola << '\t' << _energia << endl;
}



