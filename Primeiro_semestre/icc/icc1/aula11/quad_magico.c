#include <stdio.h>
#include <stdlib.h>

int **allocate_matrix(int n, int **mat);
int sum_line(int **mat, int n, int i);
int sum_col(int **mat, int n, int j);
int sum_diagonal(int **mat, int n, int k);
void fill_matrix(int m, int n, int **mat);
void print_matrix(int m, int n, int **mat);

int **allocate_matrix(int n, int **mat) {
    mat = (int**) malloc(n * sizeof(int*));
    for(int i = 0; i < n; i++) {
        mat[i] = (int*) malloc(n * sizeof(int));
    }
    return mat;
}

int sum_line(int **mat, int n, int i) {
    int sum = 0;

    for(int j = 0; j < n; j++)
        sum += mat[i][j];

    return sum;
}

int sum_col(int **mat, int n, int j) {
    int sum = 0;

    for(int i = 0; i < n; i++)
        sum += mat[i][j];
    
    return sum;
}

int sum_diagonal(int **mat, int n, int k) {
    int sum = 0;

    if(k == 0)
        for(int i = 0; i < n; i++)
            sum += mat[i][i];
    else
        for(int i = 0; i < n; i++)
            sum += mat[n - 1 - i][i];
    
    return sum;
}

void fill_matrix(int m, int n, int **mat) {
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            scanf("%d", &mat[i][j]);
        }
    }
}

void print_matrix(int m, int n, int **mat) {
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
}


int has_odd_number(int *vet, int n) {
    for(int i = 1; i < n; i++)
        if(vet[i - 1] != vet[i])
            return 1;

    return 0;
}

int main() {
    int **quad = NULL;
    int n;
    int *vet = NULL;
    int T = 0;
    int magico = 0;

    scanf("%d", &n);

    T = 2 * n + 2;
    quad = allocate_matrix(n, quad);
    vet = malloc((2 * n + 2) * sizeof(int));

    fill_matrix(n, n, quad);

    for(int i = 0; i < n; i++)
        vet[i] = sum_line(quad, n, i);
    
    for(int i = n; i < 2 * n; i++) 
        vet[i] = sum_col(quad, n, i - n);
    
    vet[T - 2] = sum_diagonal(quad, n, 0);
    vet[T - 1] = sum_diagonal(quad, n, 1); 
    magico = !has_odd_number(vet, T);

    if(magico)
        printf("SIM\n");
    else
        printf("NAO\n");

    free(quad);
    quad = NULL;

    free(vet);
    vet = NULL;

    return 0;
}