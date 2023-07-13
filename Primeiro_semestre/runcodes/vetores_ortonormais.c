// Programa que reconhece se um vetor é ortonormal ou não
// Autor: Ayrton da Costa Ganem Filho

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
    int a, *p, *q, contador1 = 0, contador2 = 0, contador3 = 0;
    scanf("%d", &a);

    p = malloc(a * sizeof(int));
    q = malloc(a * sizeof(int));

    for (int i = 0; i<a; i++){
        scanf("%d", &p[i]);
    }
    for (int i = 0; i<a; i++){
        scanf("%d", &q[i]);
    }

    for (int i =0; i<a; i++){
        contador1 += pow(p[i], 2);
        contador2 += pow(q[i], 2);
        contador3 += p[i] * q[i];

    }
    if (contador1 == 1 && contador2 == 1 && contador3 == 0){
        printf("sao ortonormais\n");
    }
    else{
        printf("nao sao ortonormais\n");
    }
}