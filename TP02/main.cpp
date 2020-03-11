/**
  *  Author: Robert Cristiano
  *  last edit: 09/03/2020
  *  by: Robert Cristiano
  *  refer: https://github.com/robertcristianoo/Geometric-Algorithms/tree/master/TP02
  */

# include <iostream>
# include <stdio.h>
# include <stdlib.h>
# include <vector>
# include <algorithm>

# include "Ponto.hpp"

using namespace std;

#define EMCIMA 0
#define FORA -1
#define DENTRO 1

int main() {

    int n;
    // n = quantidade de vértices do poligono
    // p_x = coordenada x do ponto de entrada
    // p_y = coordenada y do ponto de entrada
    double p_x, p_y;

    cin>>n;

    if (!n)
        return 0;

    vector <Ponto> poligono;

    Ponto minimo, maximo;
    int pos_min_x, pox_max_x;

    // leitura do poligono
    for (int i = 0; i < n; ++i) {
        double x, y;

        cin>>x>>y;

        if (!i) {
            minimo = maximo = Ponto(x, y);
            pox_max_x = pos_min_x = i;
        } else if (x <= minimo.x && y <= minimo.y) {
            minimo = Ponto(x, y);
            pos_min_x = i;
        } else if (x >= maximo.x && y >= maximo.y) {
            maximo = Ponto(x, y);
            pox_max_x = i;
        }

        poligono.push_back(Ponto(x, y));
    }

    //    cout<<"max=("<<maximo.x<<","<<maximo.y<<")"<<endl;
    //    cout<<"min=("<<minimo.x<<","<<minimo.y<<")"<<endl;

//    poligono.rotate(poligono.begin(), poligono.end() + pox_max_x, poligono.end());

    // quantidade de pontos que serão checados
    int q;

    cin>>q;

    for (int i = 0; i < q; ++i) {
        // leitura do q-ésimo ponto
        cin>>p_x>>p_y;

        int pos;

        Ponto p(p_x, p_y);

        // verfica de qual lado do vetor 'pi-pj' o ponto 'p' está
        int lado = p.orientation(poligono[pos_min_x], poligono[pox_max_x], p);

        // se estiver a direita, executa busca binária no subconjunto 'pi..pj'
        if (lado == 1) {
            pos = p.binarySearch(poligono, pos_min_x, pox_max_x, p);
            // se estiver a esquerda,
        } else if (lado == 2) {
            // verifica o caso especial do último triângulo
            int o1 = p.orientation(poligono[n-1], poligono[0], p);
            int o2 = p.orientation(poligono[0], poligono[n-2], p);
            int o3 = p.orientation(poligono[n-2], poligono[n-1], p);

            if (!o2 || !o3) pos = EMCIMA;
            else if (o1 >= 0 && o2 >= 0 && o3 >= 0) pos = DENTRO;
            else pos = FORA;
                // c.c executa a busca binária no subconjunto 'pj..pn-1'
            } else
                pos = p.binarySearch(poligono, pox_max_x, n-1, p);
            // se for colinear (sobre o vetor), verifica se o vetor 'pi-pj' é uma aresta,
            // caso seja, o ponto está EM CIMA do poligono. C.C dentro.
        } else {
            int o1 = p.orientation(poligono[0], poligono[1], p);
            int o2 = p.orientation(poligono[n-1], poligono[0], p);
            if (o1 == 1 && o2 == 1)
                pos = DENTRO;
            else if (o1 == 2 && o2 == 2)
                pos = FORA;
            else {
                pos = EMCIMA;
            }
        }

        if (pos == FORA) {
            cout<<"FORA"<<endl;
        } else if (pos == DENTRO) {
            cout<<"DENTRO"<<endl;
        } else {
            cout<<"EM CIMA"<<endl;
        }
    }

    return 0;
}
