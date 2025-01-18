#include <stdio.h>
#include <stdlib.h>

void aloca(int a, int b, double ***m, double **p){
    *m = (double**)malloc(a*sizeof(double*));
    *p = (double*)malloc(a*b*sizeof(double));
    for (int i=0; i<a; i++){
        (*m)[i] = &(*p)[i*b];
    }
}


int main(){
    int linha, coluna;
    scanf("%d %d", &linha, &coluna);
    // Esse programa aloca uma matriz de inteiros de tamanho a x b de modo mais eficiente (usando menos malloc do que antes usando for)
    double **m, *p;
    aloca(linha, coluna, &m, &p);
}