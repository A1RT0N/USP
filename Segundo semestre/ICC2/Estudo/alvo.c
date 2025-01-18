#include <stdio.h>
#include <stdlib.h>

int main(){
    int n, alvo,indice_inicial, indice_final, soma, valor_mais_proximo = 99999999;
    scanf("%d", &n);
    int v[n];
    for(int i = 0; i < n; i++){
        scanf("%d", &v[i]);
    }
    scanf("%d", &alvo);
    
    for(int i = 0; i<n;i++){
        soma = 0;
        for(int k = i; k<n; k++){
            soma+=v[k];
            if(abs(alvo-soma)<abs(alvo-valor_mais_proximo)){
                valor_mais_proximo = soma;
                indice_inicial = i;
                indice_final = k;
            }
        }
    }
    
    printf("%d %d", indice_inicial+1, indice_final+1);
    
    return 0;
}