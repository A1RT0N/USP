#include <stdio.h>
#define M 3
#define N 4

typedef double matriz[M][N];

double soma(double num, int n_linhas, int n_colunas, double matriz[][N]);
void entrada(double *num, matriz mat, int lin, int col);
void resultado(double res, double num);


double soma(double num, int n_linhas, int n_colunas, double matriz[][N]){ // precisa de matriz[][N] para funcionar pois o compilador precisa saber o tamanho da matriz para reservar o espaço na memória
    double s = 0.0;
    for (int i = 0; i < n_linhas; i++){
        for (int j = 0; j < n_colunas; j++){
            if (matriz[i][j] > num){
                s += matriz[i][j];
            }
        }
    }
    return s;
}

void entrada(double *num, matriz mat, int lin, int col){
    printf("Digite um valor: \n");
    scanf("%lf", num); //Precisa trabalhar com ponteiros em número, pois a passagem é por referência (igual o scanf)
    printf("Digite os elementos da matriz: \n");
    for (int i = 0; i < lin; i++){
        for (int j = 0; j < col; j++){
            scanf("%lf ", &mat[i][j]);
        }
    }
}

void resultado(double res, double num){
    printf("A soma dos elementos da matriz maiores que %lf é: %lf", num, res);
}

int main(){
    double rsoma = 0.0;
    matriz mat;
    double num;

    entrada(&num, mat, M, N);
    rsoma = soma(num, M, N, mat);
    resultado(rsoma, num);

    return 0;
}
