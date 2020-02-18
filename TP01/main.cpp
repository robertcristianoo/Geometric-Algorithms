# include <iostream>
# include <vector>

# include "Ponto.hpp"

using namespace std;

#define EMCIMA 0
#define FORA -1
#define DENTRO 1

int main() {

    // n = quantidade de vértices do poligono
    // p_x = coordenada x do ponto de entrada
    // p_y = coordenada y do ponto de entrada
    int n, p_x, p_y;

    cin>>n;

    // vetor de segmentos que forma um poligono
    vector <Ponto> poligono;

    // leitura do poligono
    for (int i = 0; i < n; ++i) {
        int a, b;

        cin>>a>>b;

        poligono.push_back(Ponto(a, b));
    }

    // leitura do ponto p
    cin>>p_x>>p_y;

    Ponto p(p_x, p_y);

    // função que verifica se o ponto está:
    // "DENTRO"	caso	o	ponto	a	esteja	dentro	do	polígono;
    // "FORA"	caso	o	ponto	esteja	fora	do	polígono;
    // "EM	CIMA"	caso	o	ponto	esteja	em	cima	do	polígono.
    int pos = p.checkPos(poligono, n, p);

    if (pos == FORA) {
        cout<<"FORA"<<endl;
    }else if (pos == EMCIMA) {
        cout<<"EM CIMA"<<endl;
    } else {
        cout<<"DENTRO"<<endl;
    }

    return 0;
}
