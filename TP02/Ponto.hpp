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
      *  rametros padr�es para cria��o.
         @return Ponto
      */
    Ponto(double x, double y);

    /**
      *  Dado o segmento 'a-b', verifica se o ponto 'c' est� sobre o segmento
      *  'a-b'.
      *  @return bool "false" caso o ponto n�o esteja sobre o segmento;
                      "true"  caso o ponto esteja sobre o segmento.
      */
    bool inSegment(Ponto a, Ponto b, Ponto c);

    /**
      *  Calcula a orientacao da tripla de pontos 'a, b e c'.
      *  @return double "0" caso 'a', 'b' e 'c' sejam colineares;
      *                 "1" caso o sentido seja hor�rio;
      *                 "-1" caso o sentido seja anti-hor�rio.
      */
    double orientation(Ponto a, Ponto b, Ponto c);

    /**
      *  Fun��o que verifica em qual lado de um poligono simples, o ponto 'a'
      *  se encontra. Percorrendo por todos os v�rtices do poligono em forma
      *  circular, ou seja, come�ando a partir do segmento '0-1' at� o �ltimo
      *  segmento 'n-0'.
      *  @return int "DENTRO"  caso o ponto esteja dentro do	pol�gono;
      *              "FORA"    caso o ponto esteja fora do pol�gono;
      *              "EM CIMA" caso o ponto esteja em cima do pol�gono.
      */
    int checkPos(vector <Ponto> poligono, int n, Ponto a);

    int binarySearch(vector <Ponto> poligono, int inicio, int fim, Ponto a);
};

#endif
