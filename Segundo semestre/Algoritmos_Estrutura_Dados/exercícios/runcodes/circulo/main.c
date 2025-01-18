#include <stdio.h>
#include "ponto.h"
#include "circulo.h"

int main(){
    PONTO *p;
    float x1, y1, x2, y2, raio;
    scanf("%f %f", &x1, &y1);
    scanf("%f %f", &x2, &y2);   
    scanf("%f", &raio);
    p = ponto_criar(x1, y1);
    PONTO *p2;
    p2 = ponto_criar(x2, y2);
    CIRCULO *c;
    c = circulo_criar(p, raio);
    if(distancia(p2, c) < raio){
        printf("O ponto é interior à circunferência.\nDistância: %.2f\n", distancia(p2, c));
    }else{
        if(distancia(p2, c) > raio){
            printf("O ponto é exterior à circunferência.\nDistância: %.2f\n", distancia(p2, c));
        }else{
            printf("O ponto pertence à circunferência.\nDistância: %.2f\n", distancia(p2, c));
        }
    }
    circulo_apagar(c);
    ponto_apagar(p);
    ponto_apagar(p2);
    return 0;
}