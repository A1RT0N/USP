#include <stdio.h>
#include <stdlib.h>

void aloca(int ***v, int n, int m);
void leitura(int ***v, int *n, int *m);
void somaacima(int **v, int n, int m, int valor);


int main(){
    int **matriz;
    int n, m;
    leitura(&matriz, &n, &m);
    int valor;
    somaacima(matriz, n,m,valor);
    for (int i =0; i<n;i++){
        free(matriz[i]);
    }
    free(matriz);
    return 0;
}

void aloca(int ***v, int n, int m){
    *v = (int **)malloc(sizeof(int *)*n);
    for (int i=0;i<m;i++){
        (*v)[i] = (int *)malloc(sizeof(int)*m);
    }
}


// void aloca(int a, int b, double ***m, double **p){
//     *m = (double**)malloc(a*sizeof(double*));
//     *p = (double*)malloc(a*b*sizeof(double));
//     for (int i=0; i<a; i++){
//         (*m)[i] = &(*p)[i*b];
//     }
// }

void leitura(int ***v, int *n, int *m){
    scanf("%d %d", n, m);
    aloca(v, *n, *m);
    for (int i =0; i< *n; i++){
        for(int j=0;j<*m;j++){
            scanf("%d",&(*v)[i][j]);
        }
    }
}

void somaacima(int **v, int n, int m, int valor){
    scanf("%d", &valor);
    printf("Os valores são: ");
    for (int i =0; i<n; i++){
        for(int j=0;j<m;j++){
            if((v)[i][j] > valor){
                printf("%d ", (v)[i][j]);
            }
        }
    }


}