// Faça um programa modularizado (funções) para calcular a transposta de uma matriz;

#include <stdio.h>

void entrada(int lin, int col, double mat[lin][col]){
    for(int i=0; i<lin; i++){
        for(int j=0; j<col; j++){
            scanf("%lf", &mat[i][j]);
        }
        
    }

}

void transposta(int lin, int col, double mat[lin][col]){
    int lint;
    lint = col;
    int colt = lin;
    int matrizt[lint][colt];
    for (int i = 0; i<lint; i++){
        for (int j = 0; j<colt; j++){
            matrizt[i][j] = mat[j][i];
            printf("%d ", matrizt[i][j]);
        }
        printf("\n");
    }

}




int main(){

    int lin, col;
    scanf("%d %d", &lin, &col);
    double mat[lin][col];
    double matt[col][lin];
    entrada(lin, col, mat);
    printf("\n");
    transposta(lin, col, mat);
    
    return 0;
}