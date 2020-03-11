#include "Ponto.hpp"
#include <iostream>
#include <limits>

using namespace std;

#define INF 100000009
#define EMCIMA 0
#define FORA -1
#define DENTRO 1

const double EPSILON = numeric_limits<float>().epsilon();

Ponto::Ponto(){};

Ponto::Ponto(double x, double y) {
    this->x = x;
    this->y = y;
}

bool Ponto::inSegment(Ponto a, Ponto b, Ponto c) {
    if (c.x <= max(a.x, b.x) &&
            c.x >= min(a.x, b.x) &&
            c.y <= max(a.y, b.y) &&
            c.y >= min(a.y, b.y)) {
        return true;
    }

    return false;
}

double Ponto::orientation(Ponto a, Ponto b, Ponto c) {
    double val = (b.y - a.y) * (c.x - b.x) -
                 (b.x - a.x) * (c.y - b.y);
//              cout<<val<<endl;

    if (val == 0)
        return 0; // colineares

    return (val > 0) ? 1 : -1; // sentido horário ou anti-horário
}

int Ponto::checkPos(vector <Ponto> poligono, int n, Ponto a) {

    int i = 0, cnt = 0;

    do {
        int next = (i + 1) % n;


    } while(i != 0);

    return (cnt % 2 == 1) ? DENTRO : FORA;
}

int Ponto::binarySearch(vector <Ponto> poligono, int inicio, int fim, Ponto a) {
    if ((fim - inicio) >= 3) {
        int mid = (fim + inicio)/2;
    }



}
