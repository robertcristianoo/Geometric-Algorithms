# include <iostream>
# include <stdio.h>
# include <vector>

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

    // leitura do poligono
    for (int i = 0; i < n; ++i) {
        double x, y;

        cin>>x>>y;

        poligono.push_back(Ponto(x, y));
    }

    // leitura do ponto p
    cin>>p_x>>p_y;

    Ponto p(p_x, p_y);

    int pos = p.checkPos(poligono, n, p);

    if (pos == FORA) {
        cout<<"FORA"<<endl;
    } else if (pos == DENTRO) {
        cout<<"DENTRO"<<endl;
    } else {
        cout<<"EM CIMA"<<endl;
    }

    return 0;
}
