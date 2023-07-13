#include <stdio.h>
#include <stdlib.h>

void imprime(int n, int m, int *v){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
           printf("%d ", v[i*m+j]);
        }
        printf("\n");
    }
}

void leitura(int **v, int n, int m){

    //Definimos, para auxiliar, que N é o número de LINHAS e M é o número de COLUNAS
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
           scanf("%d", &(*v)[i*m+j]);
        }
    }
}

void transposta(int n, int m, int *mat, int *matt){
    for(int i =0; i<m; i++){
        for(int j =0;j<n;j++){
            matt[i*n+j] = mat[j*m+i];
        }
    }
    imprime(m,n,matt);

}

int main(){
    int *mat, *matt;
    int n, m;
    scanf("%d %d", &n,&m);
    mat = malloc(sizeof(int)*n*m);
    leitura(&mat,n, m);
    transposta(n,m,mat, matt);
    

    return 0;

}