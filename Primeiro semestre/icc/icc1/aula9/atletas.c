#include <stdio.h>

void fillArr(int *atletas, int n, int *pos, int *atletas_aux);
void sortArr(int *arr, int n, int *pos, int *atletas_aux);
void swap(int *a, int *b);

void fillArr(int *atletas, int n, int *pos, int *atletas_aux) {
    for(int i = 0; i < n; i++) {
        scanf("%d", &atletas[i]);
        pos[i] = i + 1;
        atletas_aux[i] = atletas[i]; 
    }
}

void swap(int *a, int *b) {
    int temp = *b;
    *b = *a;
    *a = temp;
}

void sortArr(int *arr, int n, int *pos, int *atletas_aux) {
    for(int i = 0; i < n; i++) {
        int swapped = 0;
        for(int j = 0; j < n - i - 1; j++) {
            if(atletas_aux[j] > atletas_aux[j + 1]) {
                swap(&pos[j], &pos[j + 1]);
                swap(&atletas_aux[j], &atletas_aux[j + 1]);
                swapped = 1;
            }
        }
        if(!swapped)
            break;
    }
}

int main() {
    int n;
    scanf("%d", &n);
    int atletas[n];
    int atletas_aux[n];
    int pos[n];

    fillArr(atletas, n, pos, atletas_aux);
    sortArr(atletas, n, pos, atletas_aux);

    for(int i = 0; i < n; i++) {
        printf("%dº Atleta, %d Pontos, %dº Colocado\n", i + 1, atletas[i], pos[i]);
    }

    return 0;
}