#include <stdio.h>

void entrada(int n1, int n2, int matriz1[][n2], int m1, int m2, int matriz2[][m2]){
    for (int i = 0; i<n1;i++){
        for (int j=0;j<n2;j++){
            scanf("%d", &matriz1[i][j]);
        }
    }
    for (int i = 0; i<m1;i++){
        for (int j=0;j<m2;j++){
            scanf("%d", &matriz2[i][j]);
        }
    }
}

void multiplicacao(int n1, int n2, int matriz1[][n2], int m1, int m2, int matriz2[][m2], int resultado[][m2]){
    int soma;
    for(int linha=0; linha<n1; linha++){
        for(int coluna=0; coluna<m2; coluna++){
            soma=0;
            for(int i=0; i<n2; i++){ // Pode ser i<n2 ou i< m1 porque n2==m1
                soma+=matriz1[linha][i]*matriz2[i][coluna];
                resultado[linha][coluna]=soma;
            }
            printf("%d ", resultado[linha][coluna]);
        }
        printf("\n");
    
    }
    
}


int main(){
    
    int n1,n2,m1,m2;
    scanf("%d %d", &n1, &n2);
    scanf("%d %d", &m1, &m2);
    if (n2!=m1){
        printf("Impossível multiplicar matrizes com essas dimensões.");
    } else{
        int matriz1[n1][n2];
        int matriz2[m1][m2];
        int resultado[n1][m2];
        entrada(n1, n2, matriz1, m1, m2, matriz2);
        multiplicacao(n1, n2, matriz1, m1, m2, matriz2, resultado);
    }
    
    
    return 0;
}