#include <stdio.h>

#define MAX_SIZE 9

void fill_matrix(int mat[][MAX_SIZE], int m, int n);
void print_matrix(int mat[][MAX_SIZE], int m, int n);
void transpose_matrix(int mat[][MAX_SIZE], int m, int n);

void fill_matrix(int mat[][MAX_SIZE], int m, int n) {
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            mat[i][j] = (i + 1) * 10 + (j + 1);
        }
    }
}

void print_matrix(int mat[][MAX_SIZE], int m, int n) {
    for(int i = 0; i < m; i++) {
        printf("| ");
        for(int j = 0; j < n; j++) {
            printf("%d ", mat[i][j]);
        }
        printf("|\n");
    }
}

void transpose_matrix(int mat[][MAX_SIZE], int m, int n) {
    int temp[MAX_SIZE][MAX_SIZE];

    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            temp[j][i] = mat[i][j];
        }
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            mat[i][j] = temp[i][j];
        }
    }
}

int main() {
    int m, n;
    printf("Digite dois inteiros entre 1 e 9 para as dimensões da matriz\n");
    scanf("%d %d", &m, &n);
    int mat[MAX_SIZE][MAX_SIZE];

    fill_matrix(mat, m, n);
    printf("Matriz original:\n");
    print_matrix(mat, m, n);

    transpose_matrix(mat, m, n);
    printf("Matriz transposta:\n");
    print_matrix(mat, n, m);

    return 0;
}