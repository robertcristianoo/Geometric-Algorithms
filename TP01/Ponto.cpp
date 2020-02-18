#include "Ponto.hpp"
#include <iostream>

using namespace std;

#define INF 100000009
#define EMCIMA 0
#define FORA -1
#define DENTRO 1

Ponto::Ponto(long long int x, long long int y) {
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

int Ponto::orientation(Ponto a, Ponto b, Ponto c) {
    int val = (b.y - a.y) * (c.x - b.x) -
              (b.x - a.x) * (c.y - b.y);

    if (val == 0)
        return 0; // colineares

    return (val > 0) ? 1 : 2; // sentido horário ou anti-horário
}

bool Ponto::checkIntersect(Ponto a, Ponto b, Ponto c, Ponto d) {
    int o1 = orientation(a, b, c);
    int o2 = orientation(a, b, d);
    int o3 = orientation(c, d, a);
    int o4 = orientation(c, d, b);

    // se cruzam
    if (o1 != o2 && o3 != o4)
        return true;

    // caso a, b e c sejam colineares e 'c' esteja sobre o segmento 'a-b'
    if (o1 == 0 && inSegment(a, b, c))
        return true;

    // caso a, b e d sejam colineares e 'd' esteja sobre o segmento 'a-b'
    if (o2 == 0 && inSegment(a, b, d))
        return true;

    // caso c, d e a sejam colineares e 'a' esteja sobre o segmento 'c-d'
    if (o3 == 0 && inSegment(c, d, a))
        return true;

    // caso c, d e b sejam colineares e 'b' esteja sobre o segmento 'c-d'
    if (o4 == 0 && inSegment(c, d, b))
        return true;

    // c.c não há interseção entre os segmentos
    return false;
}

int Ponto::checkPos(vector <Ponto> poligono, int n, Ponto a) {
    // cria um ponto no infinito
    Ponto p_infinito(INF, a.y);

    int cnt = 0, i = 0;
    // percorre todos os vértices do poligono
    do {
        int next = (i + 1) % n;

        // se o segmento 'a-p_infinito' possui interseção com o segmento 'i-next'
        // incrementa o cnt
        if (checkIntersect(poligono[i], poligono[next], a, p_infinito)) {
            // se o ponto 'a' é colinear ao segmento 'i-next'
            // então o ponto 'a' está sobre o poligono
            if (orientation(poligono[i], poligono[next], a) == 0 &&
                inSegment(poligono[i], poligono[next], a)) {
                return EMCIMA;
            }

            cnt++;
        }

        // avança para o próximo vértice e continua a contagem
        i = next;
    } while(i != 0);

    return (cnt % 2 == 1) ? DENTRO : FORA;
}
