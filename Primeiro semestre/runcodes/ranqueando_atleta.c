#include <stdio.h>
#include <string.h>

void ordenar(int n, int v[]){
    int aux = 0;
    for (int j = 0; j<n; j++){
        for (int k = 0; k<n-1; k++){
            if (v[k+1]>v[k]){
                aux = v[k];
                v[k] = v[k+1];
                v[k+1] = aux;
                
            }
        }
    }
}


int main(){
    int n;
    scanf("%d", &n);
    int v[n];
    for (int i = 0; i<n; i++){
        scanf("%d", &v[i]);
    }
    
    int p[n];
    
    for (int i =0; i<n;i++){
        p[i] = v[i];
    }
    
    ordenar(n, v);
    for (int j = 0; j<n; j++){
        for (int k =0; k<n; k++){
            if (p[j] == v[k]){
                printf("%dº Atleta, %d Pontos, %dº Colocado\n", j+1, p[j],k+1);
            }
        }
    }
    
    
}
