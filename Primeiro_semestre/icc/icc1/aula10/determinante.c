#include <stdio.h>

void fillMatrix(int m, int mat[][m]);
int positiveSum(int m, int mat[][m]);
int negativeSum(int m, int mat[][m]);
int calculateMatrixDeterminant(int m, int mat[][m]);

int positiveSum(int m, int mat[][m]) {
    int sum_pos = 0;
    for(int i = 0; i < m; i++) {
        int prod_pos = 1;
        for(int j = 0; j < m; j++) {
            prod_pos *= mat[j][(j + i) % m];
        }
        sum_pos += prod_pos;
        if(m == 2)
            break;
    }

    return sum_pos;
}

int negativeSum(int m, int mat[][m]) {
    int sum_neg = 0;
    for(int i = 0; i < m; i++) {
        int prod_neg = -1;
        for(int j = m - 1, k = 0; j > -1; j--, k++) {
            prod_neg *= mat[j][(k + i) % m];
        }
        sum_neg += prod_neg;
        if(m == 2)
            break;
    }
    if(m == 1)
        return 0;
    return sum_neg;
}

int calculateMatrixDeterminant(int m, int mat[][m]) {
    return positiveSum(m, mat) + negativeSum(m, mat);
}

void fillMatrix(int m, int mat[][m]) {
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < m; j++) {
            scanf("%d", &mat[i][j]);  
        }
    }
}

int main() {
    int m;
    scanf("%d", &m);
    int mat[m][m];
    fillMatrix(m, mat);
    printf("%d\n", calculateMatrixDeterminant(m, mat));

    return 0;
}
