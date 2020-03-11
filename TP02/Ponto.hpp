#ifndef _PONTO_HPP_
#define _PONTO_HPP_

# include <iostream>
# include <vector>

using namespace std;

class Ponto {
public:
    double x, y;

    Ponto();

    /**
      *  Construtor da classe Ponto. Sendo as duas coordenadas x e y, como pa-
      *  rametros padrões para criação.
         @return Ponto
      */
    Ponto(double x, double y);

    /**
      *  Dado o segmento 'a-b', verifica se o ponto 'c' está sobre o segmento
      *  'a-b'.
      *  @return bool "false" caso o ponto não esteja sobre o segmento;
                      "true"  caso o ponto esteja sobre o segmento.
      */
    bool inSegment(Ponto a, Ponto b, Ponto c);

    /**
      *  Calcula a orientacao da tripla de pontos 'a, b e c'.
      *  @return double "0" caso 'a', 'b' e 'c' sejam colineares;
      *                 "1" caso o sentido seja horário;
      *                 "-1" caso o sentido seja anti-horário.
      */
    double orientation(Ponto a, Ponto b, Ponto c);

    /**
      *  Função que verifica em qual lado de um poligono simples, o ponto 'a'
      *  se encontra. Percorrendo por todos os vértices do poligono em forma
      *  circular, ou seja, começando a partir do segmento '0-1' até o último
      *  segmento 'n-0'.
      *  @return int "DENTRO"  caso o ponto esteja dentro do	polígono;
      *              "FORA"    caso o ponto esteja fora do polígono;
      *              "EM CIMA" caso o ponto esteja em cima do polígono.
      */
    int checkPos(vector <Ponto> poligono, int n, Ponto a);

    int binarySearch(vector <Ponto> poligono, int inicio, int fim, Ponto a);
};

#endif
