#include "Ponto.hpp"
#include <iostream>
#include <limits>

using namespace std;

#define INF 100000009
#define EMCIMA 0
#define FORA -1
#define DENTRO 1

const double EPSILON = numeric_limits<float>().epsilon();

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

int Ponto::checkPos(vector <Ponto> poligono, int n, Ponto a) {
    // cria um ponto no infinito
    Ponto p_inf(INF, a.y);

    int cnt = 0, i = 0;

    do {
        int next = (i + 1) % n;

        /** Caso o segmento 'a-p_inf', que corta o poligono do ponto 'a' até o INF,
         esteja sobre algum vértice do poligono, soma-se um valor EPSILON na coor-
         denada y do ponto 'p_inf', para que o algoritmo conte corretamente quantas
         vezes existe uma troca de lado (DENTRO ou FORA), evitando assim, contar o
         mesmo vértice para dois segmentos consecutivos.
         */
        if (p_inf.y == poligono[i].y || p_inf.y == poligono[next].y) {
            p_inf.y = p_inf.y + EPSILON;
//            cout<<EPSILON<<endl;
        }

        // se o segmento 'i-next' possui interseção com o segmento 'a-p_inf'
        // então existe uma troca de lado, incrementando o contador 'cnt'
        if (checkIntersect(poligono[i], poligono[next], a, p_inf)) {
//            cout<<"("<<poligono[i].x<<" ,"<<poligono[i].y<<") -> ";
//            cout<<"("<<poligono[next].x<<" ,"<<poligono[next].y<<")"<<endl;

            /** Caso especial em que o ponto 'a' encontra-se sobre uma aresta do
                poligono, logo a busca é encerrada e o resultado retornado.
            */
            if (orientation(poligono[i], poligono[next], a) == 0 &&
                    inSegment(poligono[i], poligono[next], a)) {
//                cout<<"EMCIMA"<<endl;
                return EMCIMA;
            }

//            cout<<"CRUZOU"<<endl;
            cnt++;
        }

        // avança para o próximo vértice e continua a contagem
        i = next;
    } while(i != 0);

//    cout<<"cnt = "<<cnt<<endl;

    /** Como provado pelo 'Jordan curve theorem', se o número de colisões entre
    o segmento 'a-p_inf' e o poligono for par, significa que o ponto não se en-
    contra no lado interior do poligono. Por outro lado, se a quantidade de co-
    lisões for ímpar, o ponto de consulta está dentro do poligono.
    Refer https://en.wikipedia.org/wiki/Jordan_curve_theorem
    */
    return (cnt % 2 == 1) ? DENTRO : FORA;
}
