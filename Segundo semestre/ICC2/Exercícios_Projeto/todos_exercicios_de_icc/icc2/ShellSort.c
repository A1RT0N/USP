#include <stdio.h>

/*
A complexidade depende do H escolhido.

Ela normalmente é O(n²), entretanto, utilizando a estratégia de Knuth que é:
h_k = 3^k - 1, a complexidade pode varia entre O(n^1.25) e O(n^3/2)
 */


void swap(int *a, int *b) {
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}


void ShellSort(int vetor[], int n, int h) {
    int gap = h;

    while (gap > 0) {
        for (int i = gap; i < n; i++) {
            for (int j = i - gap; j >= 0 && vetor[j] > vetor[j + gap]; j -= gap) {
                swap(&vetor[j], &vetor[j + gap]);
            }
        }
        gap /= 2;
    }
}