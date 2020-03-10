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

bool sortFunction(const pair <Ponto, int> &a, const pair <Ponto, int> &b) {
    return (a.second < b.second);
}

int main() {

    int n;
    // n = quantidade de vértices do poligono
    // p_x = coordenada x do ponto de entrada
    // p_y = coordenada y do ponto de entrada
    double p_x, p_y;

    cin>>n;

    if (!n)
        return 0;

    vector <pair <Ponto, int> > poligono;

    // leitura do poligono
    for (int i = 0; i < n; ++i) {
        double x, y;

        cin>>x>>y;

        poligono.push_back(make_pair(Ponto(x, y), -1));
    }

    // cria um ponto central à três vértices, não colineares entre si, do poligono
    int it = 0;

    Ponto centro, p1, p2,p3;

    do {
        it = (it + 1) % n;

        p1 = poligono[it].first;
        p2 = poligono[++it].first;
        p3 = poligono[it+1].first;

        centro.x = (p1.x + p2.x + p3.x)/3;
        centro.y = (p1.y + p2.y + p3.y)/3;

    } while(!centro.orientation(p1, p2, p3));

    cout<<"Centro = ("<<centro.x<<", "<<centro.y<<")"<<endl;

    for(int i = 0; i < n; ++i) {
        if (poligono[i].first.y >= centro.y) {
            poligono[i].second = 1;
        } else {
            poligono[i].second = 0;
        }
    }

    sort(poligono.begin(), poligono.end(), sortFunction);

    for(auto a : poligono) {
        cout<<"P = ("<<a.first.x<<", "<<a.first.y<<")"<<endl;
    }

    // quantidade de pontos que serão checados
    int q;

//    for (int i = 0; i < q; ++i) {
//        // leitura do q-ésimo ponto
//        cin>>p_x>>p_y;
//
//        Ponto p(p_x, p_y);
//
//        int pos = p.checkPos(poligono, n, p, centro);
//
//        if (pos == FORA) {
//            cout<<"FORA"<<endl;
//        } else if (pos == DENTRO) {
//            cout<<"DENTRO"<<endl;
//        } else {
//            cout<<"EM CIMA"<<endl;
//        }
//    }

    return 0;
}
