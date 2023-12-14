#include <stdio.h>
#include <stdlib.h>

typedef struct fila_ FILA;

struct fila_{
    int fila[100];

    int tamanho;
};


int main(void){
    int n;

    scanf("%d", &n);

    int v[n];

    int maior = -99999;

    int menor = 10000;

    for (int i = 0; i < n; i++){
        int item;

        scanf("%d", &item);

        if (item > maior) maior = item;

        if (item < menor) menor = item;

        v[i] = item;
    }

    for (int i = 0; i < n; i++){
        v[i] += abs(menor);
    }

    int digitos = 0;

    maior += abs(menor);

    if (!maior) {
        digitos = 1;
    } else{
        while (maior > 0){
            maior /= 10;

            digitos++;
        }
    }

    int contador = 1;

    for (int i = 0; i < digitos; i++){
        FILA filas[10];

        for (int j = 0; j < 10; j++){
            filas[j].tamanho = 0;
        }

        for (int j = 0; j < n; j++) filas[(v[j] / contador) % 10].fila[filas[(v[j] / contador) % 10].tamanho ++] = v[j];

        int index = 0;

        for (int j = 0; j < 10; j++){
            for (int k = 0; k < filas[j].tamanho; k++){
                v[index] = filas[j].fila[k];

                index ++;
            }
        }

        contador *= 10;
    }

    for (int i = 0; i < n; i++){
        v[i] -= abs(menor);
    }

    for (int i = 0; i < n - 1; i++){
        printf("%d ", v[i]);
    }

    printf("%d", v[n - 1]);
}