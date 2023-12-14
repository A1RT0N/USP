#include "ponto.h"
#include <math.h>
#include <stdlib.h>

struct ponto_{
    float x;
    float y;
};

PONTO *ponto_criar(float x, float y){
    PONTO *pontinho;
    pontinho = (PONTO *)malloc(sizeof(PONTO *));
    pontinho->x = x;
    pontinho->y = y;
    return pontinho;
}

void ponto_apagar(PONTO *p){
    free(p);
    p = NULL;
}

float distancia_ponto_ponto(PONTO *p1, PONTO *p2){
    float distancia_ponto;
    distancia_ponto = sqrt(pow(p1->x-p2->x,2)+ pow(p1->y-p2->y,2));
    return distancia_ponto;
}

bool ponto_set(PONTO *p, float x, float y){
    int tmp;
    tmp = p->x;
    p->x = y;
    p->y = tmp;
    if(p->x == x && p->y == y){
        return true;
    }else{
        return false;
    }
}

