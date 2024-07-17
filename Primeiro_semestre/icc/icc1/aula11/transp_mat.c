#include <stdio.h>
#include <stdlib.h>

int **allocate_matrix(int **mat, int m, int n);
void deallocate_matrix(int **mat, int m);
int **fill_matrix(int **mat, int m, int n);
void print_matrix(int **mat, int m, int n);
int **transpose_matrix(int **mat, int m, int n);

int **allocate_matrix(int **mat, int m, int n) {
    if(mat == NULL) {
        mat = (int **) malloc(m * sizeof(int*));
    
        for(int i = 0; i < m; i++) {
            mat[i] = (int *) malloc(n * sizeof(int));
        }
    }

    return mat;
}

void deallocate_matrix(int **mat, int m) {
    for(int i = 0; i < m; i++) {
        free(mat[i]);
        mat[i] = NULL;
    }
    free(mat);
    mat = NULL;
}

int **fill_matrix(int **mat, int m, int n) {
    mat = allocate_matrix(mat, m, n);
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            scanf("%d", &mat[i][j]);
        }
    }
    return mat;
}

void print_matrix(int **mat, int m, int n) {
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            printf("%*d ", 2,mat[i][j]);
        }
        printf("\n");
    }
}

int **transpose_matrix(int **mat, int m, int n) {
    int **transp = NULL; 
    transp = allocate_matrix(transp, n, m);

    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            transp[j][i] = mat[i][j];
        }
    }

    return transp;
}

int main() {
    int m, n;
    scanf("%d %d", &m, &n);
    int **mat = NULL;
    int **transp = NULL;

    mat = fill_matrix(mat, m, n);
    transp = transpose_matrix(mat, m, n);
    deallocate_matrix(mat, m);

    print_matrix(transp, n, m);
    deallocate_matrix(transp, n);

    return 0;
}