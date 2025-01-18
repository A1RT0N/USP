#include <stdio.h>

void swap(int *num1, int *num2) {
    int tmp;
    tmp = *num1;
    *num1 = *num2;
    *num2 = tmp;
}

void print_vetor(int *vetor, int N) {
    for (int i = 0; i < N; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");
}

void Cocktail_shaker_sort(int *numeros, int N) {
    int j = 0;
    int k = N-1;
    int swapped = 0;
    for (int i = 0; i < N; i++) {
        if (i % 2 == 1) {
            //bubbled up
            for (int l = j; l <= k; l++) {
                if (numeros[l] > numeros[l+1]) {
                    swap(&numeros[l], &numeros[l+1]);
                    swapped = 1;

                }

            }
            j++;


        } else {
            //bubbled down
            for (int l = k; l > j; l--) {
                if (numeros[l] < numeros[l-1]) {
                    swap(&numeros[l], &numeros[l-1]);
                    swapped = 1;
                }

            }
            k--;
        }
        if (!swapped) break;
        swapped = 0;

        print_vetor(numeros, N);


    }

}


int main() {
    int N;
    scanf("%d", &N);

    int vetor[N];

    for (int i = 0; i < N; i++) {
        scanf("%d", &vetor[i]);
    }

    Cocktail_shaker_sort(vetor, N);


    return 0;
}