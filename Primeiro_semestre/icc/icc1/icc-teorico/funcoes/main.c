#include <stdio.h>
#include <stdlib.h>

/*implementar funcao que recebe a e b, 
 * e coloca o valor de a em b e de b em a*/

/*
 *Implemente uma funcao que recebe a e b, se forem iguais retorna 0,
 *se a for menor retorna um numero negativo, se nao um numero positivo
 */

/*
 *implementar funcao que recebe o vetor v,
 *Compare o primeiro elemento com o próximo elemento adjacente.
 *Se o primeiro elemento for maior que o próximo, troque suas posições.
 *Continue comparando e trocando os elementos adjacentes ao longo da lista.
 *Ao final da primeira iteração, o maior elemento estará na última posição da lista.
 *Repita os passos, percorrendo a lista novamente, mas ignorando a última posição.
 *Continue repetindo esse processo até que não ocorram mais trocas durante uma iteração completa.
 *Retorne o número de trocas feitas 
 */

int cmp_int(int a, int b);
void troca_int(int *a, int *b);
int ordena(int n, int *v);

int cmp_int(int a, int b) {
    return a - b;
}

void troca_int(int *a, int *b) {
    int tmp = *b;
    *b = *a;
    *a = tmp; 
}

int ordena(int n, int *v) {
    int soma_trocas = 0;
    int soma_trocas_iteracao = 0;
    while(1) {
        for(int i = 1; i < n; i++) {
            if(cmp_int(v[i - 1], v[i]) > 0) { // a > b
                troca_int(&v[i - 1], &v[i]);
                soma_trocas_iteracao++;
            }
        }
        soma_trocas += soma_trocas_iteracao;

        if(!soma_trocas_iteracao) {
            return soma_trocas;
        }
        soma_trocas_iteracao = 0;
    }
    return soma_trocas;
}

int main(int argc, char** argv) {
    int n;
    scanf(" %d", &n);

    int v[n];

    for (int i = 0; i < n; i++) {
        scanf(" %d", &v[i]);
    }

    int trocas = ordena(n, v);

    for (int i = 0; i < n; i++) {
        printf("%d ", v[i]);
    }
    printf("\n");
    printf("Foram feitas %d trocas\n", trocas);

    return (EXIT_SUCCESS);
}

