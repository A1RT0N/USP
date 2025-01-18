#include "circulo.h"
#include "ponto.h"
#include <stdlib.h>
#include <math.h>

struct circulo_{
    PONTO* ponto_centro;
    float raio;
};

float circulo_area (CIRCULO* circ){
    float area;
    area = 3.1415 * pow(circ->raio, 2);
    return area;
}

CIRCULO *circulo_criar(PONTO *p, float raio){
    CIRCULO *circulinho;
    circulinho = (CIRCULO *)malloc(sizeof(CIRCULO *));
    circulinho->raio = raio;
    circulinho->ponto_centro = p;
    return circulinho;
}

void circulo_apagar (CIRCULO* circ){
    free(circ);
    circ = NULL;
}

float distancia(PONTO* p, CIRCULO* r){
    float dist;
    dist = distancia_ponto_ponto(p, r->ponto_centro);
    return dist;
}




