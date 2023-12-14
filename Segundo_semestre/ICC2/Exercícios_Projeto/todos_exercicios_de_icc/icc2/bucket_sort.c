#include <stdio.h>
#include <stdlib.h>

int NumeroDeUns(int num) {
    int uns = 0;

    while (num != 0) {
        if (num % 2 == 1) {
            uns++;
        }
        num = num / 2;
    }

    return uns;
}

void InsertionSort(int *vetor, int n) {
    int i, chave, j;

    for (i = 0; i < n; i++) {
        chave = vetor[i];
        j = i - 1;

        while (j >= 0 && vetor[j] > chave) {
            vetor[j + 1] = vetor[j];
            j--;
        }
        vetor[j + 1] = chave;
    }
}


void BucketSort(int arr[], int tamanho) {
    int **buckets;
    buckets = (int **) malloc(10 * sizeof(int *));
    for (int i = 0; i < 10; i++) {
        buckets[i] = (int *) malloc(252 * sizeof(int));
    }

    for (int i = 0; i < tamanho; i++) {
        int j = 0;
        while (buckets[NumeroDeUns(arr[i]) - 1][j] != 0) {
            j++;
        }
        buckets[NumeroDeUns(arr[i]) - 1][j] = arr[i];
    }

    for (int i = 0; i < 10; i++) {
        int size = 0;
        int j = 0;
        while (buckets[i][j] != 0) {
            size++;
            j++;
        }
        InsertionSort(buckets[i], size);
    }

    for (int i = 0; i < tamanho; i++) {
        int flag = 0;
        int j = 0;
        while (buckets[i][j] != 0) {
            flag = 1;
            printf("%d ", buckets[i][j]);
            j++;
        }
        if (flag) {
            printf("\n");
        }
    }

    int ordenada[2520];
    int k = 0;
    for (int i = 0; i < tamanho; i++) {
        int j = 0;
        while (buckets[i][j] != 0) {
            ordenada[k] = buckets[i][j];
            k++;
            j++;
        }

    }
    InsertionSort(ordenada, k);

    for (int i = 0; i < k; i++) {
        printf("%d ", ordenada[i]);
    }
}


int main() {
    int n;
    scanf("%d", &n);

    int array[n];



    for (int i = 0; i < n; i++) {
        scanf("%d", &array[i]);
    }

    BucketSort(array, n);



    return 0;
}