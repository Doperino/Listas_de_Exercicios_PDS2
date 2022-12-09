#include "Ponto2D.hpp"

Ponto2D::Ponto2D(double x, double y) {
    _x = x;
    _y = y;
}

Ponto2D::Ponto2D() {
    _x = 0.0;
    _y = 0.0;
}

double Ponto2D::calculaDistancia(Ponto2D &ponto) {
    double dx = _x - ponto._x;
    double dy = _y - ponto._y;
    return sqrt(dx*dx + dy*dy);
}