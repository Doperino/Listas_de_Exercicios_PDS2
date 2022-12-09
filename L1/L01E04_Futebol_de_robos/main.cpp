#include <iostream>
#include "Ponto2D.hpp"

using namespace std;

int main() {

    Ponto2D ponto1 = Ponto2D(0, 0);
    Ponto2D ponto2 = Ponto2D(1, 1);

    double distancia = ponto2.calculaDistancia(ponto1);
    cout << distancia << endl;
}