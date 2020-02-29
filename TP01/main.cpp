# include <iostream>
# include <stdio.h>
# include <vector>

# include "Ponto.hpp"

using namespace std;

#define EMCIMA 0
#define FORA -1
#define DENTRO 1

int main() {

    int n, cnt = 1;

    do {
        // n = quantidade de vértices do poligono
        // p_x = coordenada x do ponto de entrada
        // p_y = coordenada y do ponto de entrada
        double p_x, p_y;

        cin>>n;

        if (!n)
            return 0;

        // vetor de segmentos que forma um poligono
        vector <Ponto> poligono;

        // leitura do poligono
        for (int i = 0; i < n; ++i) {
            double x, y;

            cin>>x>>y;

            poligono.push_back(Ponto(x, y));
        }

        double flag_x, flag_y;
        int m;

        cin>>flag_x>>flag_y>>m;

        Ponto flag(flag_x, flag_y);

        int flag_pos = flag.checkPos(poligono, n, flag);
        flag_pos++;

        cout<<"Instancia "<<cnt<<endl;

        for (int i = 0; i < m; ++i) {
            // leitura do ponto p
            cin>>p_x>>p_y;

            Ponto p(p_x, p_y);

            // função que verifica se o ponto está:
            // "DENTRO"	caso	o	ponto	a	esteja	dentro	do	polígono;
            // "FORA"	caso	o	ponto	esteja	fora	do	polígono;
            // "EM	CIMA"	caso	o	ponto	esteja	em	cima	do	polígono.
            int pos = p.checkPos(poligono, n, p);

            if (!flag_pos) {
                if (pos == FORA || pos == EMCIMA) {
                    cout<<"soldado "<<i+1<<" "<<"defender"<<endl;
                } else {
                    cout<<"soldado "<<i+1<<" "<<"espanhol"<<endl;
                }
            } else {
                if (pos == FORA) {
                    cout<<"soldado "<<i+1<<" "<<"espanhol"<<endl;
                } else {
                    cout<<"soldado "<<i+1<<" "<<"defender"<<endl;
                }
            }
        }

        printf("\n");
        cnt++;
    } while(n!=0);

    return 0;
}
