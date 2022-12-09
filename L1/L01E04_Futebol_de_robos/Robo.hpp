#ifndef ROBO_H
#define ROBO_H

#include "Ponto2D.hpp"

struct Robo {

    int _id;
    double _energia = 100;
    Ponto2D _ponto;
    bool _com_bola;

    Robo(int, Ponto2D, bool); //feito
    
    void mover(double v, double th, double t); //feito

    double calcular_distancia(Robo *robo); //feito

    Robo *determinar_robo_mais_proximo(Robo **naves, int n); 

    void passar_bola(Robo **time, int n);

    void imprimir_status();
};

#endif