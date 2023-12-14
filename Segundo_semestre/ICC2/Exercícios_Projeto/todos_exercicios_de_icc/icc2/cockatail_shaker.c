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
    int swapped = 0;
    int start = 0;
    int end = N-1;
    for (int i = 0; i < N; i++) {
        if (i % 2 == 0) {
            //bubbled up
            for (int l = start; l < end; l++) {
                if (numeros[l] > numeros[l+1]) {
                    swap(&numeros[l], &numeros[l+1]);
                    swapped = 1;
                }

            }
            end--;
            if (swapped == 0) {
                break;
            }
            swapped = 0;

        } else {
            //bubbled down
            for (int l = end - 1; l >= start; l--) {
                if (numeros[l] > numeros[l+1]) {
                    swap(&numeros[l], &numeros[l+1]);
                    swapped = 1;
                }

            }
            start++;
            if (swapped == 0) {
                break;
            }
            swapped = 0;
        }
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

    print_vetor(vetor, N);


    return 0;
}
