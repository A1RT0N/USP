#include <stdio.h>
#include <stdlib.h>

void alocar(int ***matriz, int l2){
    for (int i =0; i<l2; i++){
        **matriz[i] = (int *) malloc(l2*sizeof(int));
    }
}

void ler(int ***matriz, int k1, int k2){
    for (int i =0;i<k1;i++){
        for (int j=0;j<k2;j++){
            scanf("%d",matriz[i][j]);
        }
    }
}

int **multiplicar(int **matriz1, int n1,int n2, int **matriz2, int m1, int m2){
    int p[n1][m2];
    for(int linha=0; linha<n1;linha++){
        for (int coluna= 0; coluna<m2; coluna++){
            int soma = 0;
            for (int h = 0;h<n1;h++){
                soma+=matriz1[linha][h]+matriz2[h][coluna];
                p[linha][coluna]=soma;
            }
        }
    }
    for(int s =0;s<10;s++){
        printf("-=");
    }
    return p;

}

int main(){
    int n1,n2,m1,m2;
    scanf("%d %d %d %d", &n1, &n2, &m1, &m2);
    int **matriz1 = (int **) malloc(n1*sizeof(int*));
    int **matriz2 = (int **) malloc(m1*sizeof(int*));
    alocar(&matriz1, n2);
    alocar(&matriz2, m2);
    ler(&matriz1, n1, n2);
    ler(&matriz2,m1,m2);
    int **p = multiplicar(matriz1,n1,n2,matriz2,m1,m2);
    for (int i =0;i<n1;i++){
        for (int j=0;j<m2;j++){
            printf("%d",p[i][j]);
        }
    }
    return 0;
}