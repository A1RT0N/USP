#include <stdio.h>
#include <stdlib.h>

int pertencente(int *v, int tamanho, int item){
    for (int i = 0; i < tamanho; i++){
        if (v[i] == item) return 1;
    }

    return 0;
}

int main(void){
    int n;

    scanf("%d", &n);
    
    int v[n];

    int tamanho = 0;

    for (int i = 0; i < n; i++){
        int item;

        scanf("%d", &item);

        if (!pertencente(v, tamanho, item)) {
            v[tamanho] = item;

            tamanho ++;
        }
    }

    int contador = 0;

    for (int i = 0; i < tamanho; i++){
        int num = v[i];

        for (int j = 0; j < tamanho; j++){
            if (num > v[j]) {
                contador ++;
            }
        }
    }

    printf("%d", contador);
}