#ifndef PONTO_H
    #define PONTO_H
    #include <stdbool.h> // Chamado essa biblioteca para usar o bool

    typedef struct ponto_ PONTO;
    PONTO *ponto_criar(float x, float y);
    void ponto_apagar(PONTO *p);
    bool ponto_set(PONTO *p, float x, float y); // Foi consertado de boolean para bool
    float distancia_ponto_ponto(PONTO *p1, PONTO *p2); // Essa função calcula a distância entre dois pontos.
    // Essa função será usada em circulo.c para calcular a distância entre o ponto e o centro do círculo do modo que foi pedido no exercício.


#endif





