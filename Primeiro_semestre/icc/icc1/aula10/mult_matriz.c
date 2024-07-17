#include <stdio.h>

void print_matrix(int m, int n, int mat[][n]);
void fill_matrix(int m, int n, int mat[][n]);
void matrix_product(int m, int n, int o, int mat1[][o], int mat2[][n], int mat3[][n]);

void matrix_product(int m, int n, int o, int mat1[][o], int mat2[][n], int mat3[][n]) {
    for(int k = 0; k < m; k++) {
        int sum = 0;
        for(int l = 0; l < n; l++) {
            for(int j = 0; j < o; j++) {
                sum += mat1[k][j] * mat2[j][l];
            }
            mat3[k][l] = sum;
            sum = 0;
        }
    }
}

void print_matrix(int m, int n, int mat[][n]) {
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
}

void fill_matrix(int m, int n, int mat[][n]) {
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            scanf("%d", &mat[i][j]);
        }
    }
}

int main() {
    int n1, m1, n2, m2;
    scanf("%d %d %d %d", &n1, &m1, &n2, &m2);
    int mat1[n1][m1];
    int mat2[n2][m2];
    int mat3[n1][m2];
    if(m1 != n2) {
        printf("Impossível multiplicar matrizes com essas dimensões.\n");
        return 0;
    }
    fill_matrix(n1, m1, mat1);
    fill_matrix(n2, m2, mat2);

    matrix_product(n1, m2, m1, mat1, mat2, mat3);
   
    print_matrix(n1, m2, mat3);
    return 0;
}