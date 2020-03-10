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

    return (val > 0) ? 1 : 2; // sentido horário ou anti-horário
}

bool Ponto::checkIntersect(Ponto a, Ponto b, Ponto c, Ponto d) {
    double o1 = orientation(a, b, c);
    double o2 = orientation(a, b, d);
    double o3 = orientation(c, d, a);
    double o4 = orientation(c, d, b);

    // se cruzam
    if (o1 != o2 && o3 != o4)
        return true;

    // caso 'a', 'b' e 'c' sejam colineares e 'c' esteja sobre o segmento 'a-b'
    if (o1 == 0 && inSegment(a, b, c))
        return true;

    // caso 'a', 'b' e 'd' sejam colineares e 'd' esteja sobre o segmento 'a-b'
    if (o2 == 0 && inSegment(a, b, d))
        return true;

    // caso 'c', 'd' e 'a' sejam colineares e 'a' esteja sobre o segmento 'c-d'
    if (o3 == 0 && inSegment(c, d, a))
        return true;

    // caso 'c', 'd' e 'b' sejam colineares e 'b' esteja sobre o segmento 'c-d'
    if (o4 == 0 && inSegment(c, d, b))
        return true;

    // c.c não há interseção entre os segmentos
    return false;
}

int Ponto::checkPos(vector <Ponto> poligono, int n, Ponto a, Ponto centro) {

    int i = 0, cnt = 0;

    do {
        int next = (i + 1) % n;


    } while(i != 0);

    return (cnt % 2 == 1) ? DENTRO : FORA;
}
