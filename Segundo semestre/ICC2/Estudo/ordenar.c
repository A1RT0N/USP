#include <stdio.h>
#include <stdlib.h>

int contar(int *vetor, int n, int atual){
    int retorno = 0;

    for(int i =0; i< n; i++){
        if(atual == vetor[i]){
            retorno++;
        }
    }

    return retorno;

}

int main(){
    int a, contador = 0;
    scanf("%d", &a);
    int vetor[a];
    int vetor_sem_repeticao[a];

    int k = 0;

    for(int i = 0; i< a; i++){
        scanf("%d", &vetor[i]);
        if(contar(vetor, i, vetor[i]) == 0){
            vetor_sem_repeticao[k] = vetor[i];
            k++;
        }

    }



    for(int i =0; i<k; i++){
        for(int j = 0; j<k; j++){
            if(vetor_sem_repeticao[i]>vetor_sem_repeticao[j]){
                contador++;
            }
        }
    }

    printf("%d", contador);

    return 0;
    
}