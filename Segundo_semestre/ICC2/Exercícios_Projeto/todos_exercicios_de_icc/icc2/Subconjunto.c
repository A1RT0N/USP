#include <stdio.h>
#include <stdlib.h>

struct sub{
    int inicial;
    int final;
    int valor;
};

typedef struct sub sub;

int main(void){
    int n;

    scanf("%d", &n);

    int vet[n];

    for (int i = 0; i < n; i++){
        scanf("%d", &vet[i]);
    }

    int alvo;

    scanf("%d", &alvo);

    sub subconjuntos[n];

    int melhor_subconjunto_index;
    int melhor_subconjunto_distancia = 10000;

    for (int i = 0; i < n; i++){
        subconjuntos[i].inicial = i + 1;
        int soma = 0;

        int melhor_distancia = 10000; //distancia entre o alvo
        int melhor_final;

        for (int j = i; j < n; j++){
            soma += vet[j];

            if (soma == alvo){
                printf("%d %d", subconjuntos[i].inicial, j + 1);

                return 0;
            }

            if (abs(alvo - soma) < melhor_distancia){
                melhor_distancia = soma;
                melhor_final = j + 1;
            }
        }

        subconjuntos[i].final = melhor_final;

        if (abs(alvo - melhor_distancia) < melhor_subconjunto_distancia){
            melhor_subconjunto_distancia = melhor_distancia;
            melhor_subconjunto_index = i;
        }
    }

    printf("%d %d", subconjuntos[melhor_subconjunto_index].inicial, subconjuntos[melhor_subconjunto_index].final);
}