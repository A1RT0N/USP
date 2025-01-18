#include <stdio.h>
#include <stdlib.h>

void mostrar(int *v, int ini, int fim){
    for (int i = ini; i <= fim; i++){
        printf("%d ", v[i]);
    }
    printf("\n");
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

    for (int i = ini; i <= fim; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");
}

void Merge(int vetor[], int ini, int meio, int fim) {
    int n1 = meio - ini + 1;
    int n2 = fim - meio;

    int L[n1], R[n2];

    for (int i = 0; i < n1; i++) {
        L[i] = vetor[ini + i];
    }
    for (int j = 0; j < n2; j++) {
        R[j] = vetor[meio + 1 + j];
    }

    int i = 0, j = 0, k = ini;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            vetor[k] = L[i];
            i++;
        } else {
            vetor[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        vetor[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        vetor[k] = R[j];
        j++;
        k++;
    }
}

void mergesort(int *v, int ini, int fim, int k){
    if (fim + 1 - ini <= k) {
        InsertionSort(v, ini, fim);

        return;
    } else{
        int meio = (ini + fim) / 2;

        mergesort(v, ini, meio, k);
        mergesort(v, meio + 1, fim, k);

        Merge(v, ini, meio, fim);
    }
}

int main(void){
    int n;

    scanf("%d", &n);

    int *v;

    v = (int *) malloc(sizeof(int) * n);

    for (int i = 0; i < n; i++){
        scanf("%d", &v[i]);
    }

    int k;

    scanf("%d", &k);

    
    mergesort(v, 0, n - 1, k);

    mostrar(v, 0, n - 1);
}