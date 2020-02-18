#ifndef _PONTO_HPP_
#define _PONTO_HPP_

# include <iostream>
# include <vector>

using namespace std;

class Ponto {
public:
    long long int x, y;
    Ponto(long long int x, long long int y);

    // Dado o segmento 'a-b', verifica se o ponto 'c' est� sobre o segmento 'a-b'
    bool inSegment(Ponto a, Ponto b, Ponto c);

    // Calcula a orientacao da tripla de pontos 'a, b e c'
    // 0 --> a, b e c s�o colineares
    // 1 --> sentido hor�rio
    // 2 --> sentido anti-hor�rio
    int orientation(Ponto a, Ponto b, Ponto c);

    // Verifica se o segmento 'a-b' cruza com o segmento 'c-d'
    bool checkIntersect(Ponto a, Ponto b, Ponto c, Ponto d);

    // Verifica se o ponto 'a' est� dentro, fora ou no 'poligono' de 'n' v�rtices
    int checkPos(vector <Ponto> poligono, int n, Ponto a);
};

#endif
