/*

#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b){
    int tmp = *b;
    *b = *a;
    *a = tmp;
}

void insertion_sort(int *vetor, int inicio, int fim) {
    int j, aux;
    for (int i = inicio; i < fim+1-inicio; i++) {
        aux = vetor[i];
        for (j = i; (j > 0) && (aux < vetor[j - 1]); j--) {
            if(vetor[j] < vetor[j-1]){
                swap(&vetor[j], &vetor[j-1]);
            }
        }
        vetor[j] = aux;
    }
}



void Mergesort(int *vet, int inicio, int fim, int k){
    if(abs(fim+1-inicio) <= k){
        insertion_sort(vet, inicio, fim);
    }else{
        int meio = (inicio+fim)/2;
        Mergesort(vet,meio+1,fim, k);
        Mergesort(vet,inicio,meio, k);
    }
}

int main(){
    int vetor[6] = {1,8,3,88,2,0};
    Mergesort(vetor,0,5,3);
    for(int i =0; i<6; i++){
        printf("%d ", vetor[i]);
    }
}
*/

#include <stdio.h>
#include <stdlib.h>

/*
Como será realizada uma nova consulta a cada quantidade de dinheiro inserido,
o algoritmo mais eficaz para imprimir os 3 maiores valores salariais é a Inserção Ordenada,
ou Insertion Sort, pois a cada nova inserção iremos precisar da lista ordenada.
*/

void imprimir(int *lista, int fim) {
    if (fim <= 1) {
        printf("-1\n");
    } else {
        printf("%d %d %d\n", lista[fim], lista[fim-1], lista[fim-2]);
    }
}

void swap(int *v, int i, int j){
    int tmp;

    tmp = v[i];

    v[i] = v[j];
    v[j] = tmp;
}

void InsertionSort(int vetor[], int ini, int fim) {
    int i, chave, j;

    for (i = ini; i <= fim; i++) {
        chave = vetor[i];
        j = i - 1;

        while (j >= ini && vetor[j] > chave) {
            vetor[j + 1] = vetor[j];
            j--;
        }
        vetor[j + 1] = chave;
    }
}

int main () {
    int t;
    scanf("%d", &t);

    int *lista;
    lista = (int *) malloc(sizeof(int) * t);
    int ini = 0;
    int fim = 0;

    for (int i = 0; i < t; i++) {
        scanf("%d", &lista[i]);

        InsertionSort(lista, ini, fim);

        imprimir(lista, fim);
        fim++;
    }

    free(lista);

    return 0;
}

