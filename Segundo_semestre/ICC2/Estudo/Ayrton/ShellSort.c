#include <stdio.h>


void swap(int *a, int *b) {
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void printar(int *vetor){
    for (int i = 0; i < 6; i++) {
        printf("%d ", vetor[i]);
    }
}


void ShellSort(int vetor[], int n, int h) {
    int gap = 2 * h;

    while (gap > 0) {
        gap /= 2;

        for (int i = gap; i < n; i++) {
            if (vetor[i] < vetor[i - gap]) {
                printf("\nTrocando elemento %d (i = %d) com %d (i = %d). Gap = %d\n", vetor[i], i, vetor[i-gap], i-gap, gap);
                swap(&vetor[i], &vetor[i - gap]);
            }
        }
    }
}

int main() {
    int vetor[6] = {15, 34, 11, 2, 8000, 17};

    ShellSort(vetor, 6, 3);

    for (int i = 0; i < 6; i++) {
        printf("%d ", vetor[i]);
    }

    return 0;
}