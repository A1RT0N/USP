#ifndef CIRCULO_H
    #define CIRCULO_H

    #include "ponto.h"

    typedef struct circulo_ CIRCULO;
    CIRCULO *circulo_criar(PONTO *p, float raio);
    void circulo_apagar (CIRCULO* circ);
    float circulo_area (CIRCULO* circ);
    float distancia(PONTO* p, CIRCULO* r); // Função dada pelo exercício que usa a função distanica_ponto_ponto. Aqui é importada ponto.h, por isso que escolhi para ser aqui.
#endif


