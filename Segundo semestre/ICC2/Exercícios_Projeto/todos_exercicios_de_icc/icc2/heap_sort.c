#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printar_heap(int v[], int tamanho_do_vetor, int a){
    for(int i = 0; i<tamanho_do_vetor; i++){
        printf("%d ", v[i]);
    }
    printf("- %d\n", a);
}

void rearranjar_heap(int v[], int i, int tamanho_da_heap){
    int esq,dir,meio, maior,aux;
    esq = 3*i+1;
    meio = 3*i+2;
    dir = 3*i+3;

    if(esq < tamanho_da_heap && v[esq] > v[i]){
        maior = esq;
    } else maior = i;

    if(meio < tamanho_da_heap && v[meio] > v[maior]){
        maior = meio;
    }

    if(dir < tamanho_da_heap && v[dir] > v[maior]){
        maior = dir;
    }

    if(maior != i) {
        aux = v[i];
        v[i] = v[maior];
        v[maior] = aux;
        
        rearranjar_heap(v, maior, tamanho_da_heap);
    }

}

int* construir_heap(int v[], int tamanho_do_vetor){
    for(int i = tamanho_do_vetor/3-1; i>=0; i--){
        rearranjar_heap(v, i, tamanho_do_vetor);
    }
    return v;
}

int trocar_raiz(int v[], int tamanho_do_vetor){ // trocar a raiz com o último elemento do vetor
    int aux = v[0];
    v[0] = v[tamanho_do_vetor-1];
    v[tamanho_do_vetor-1] = aux;
    if(v[tamanho_do_vetor-1] != 0) printar_heap(v, tamanho_do_vetor-1, v[tamanho_do_vetor-1]);
    return aux;
}

int main(){
    int a;
    scanf("%d", &a);
    int vetor[a];
    int *heap;
    int vetor_ordenador_invertido[a];
    int vetor_ordenador[a];

    for(int i =0; i< a; i++){
        scanf("%d", &vetor[i]);
    }

    for (int i = 0; i < a; i++){
        printf("%d ", vetor[i]);
    }

    printf("\n");

    heap = construir_heap(vetor, a);

    // rearrajando o vetor
    for(int i = 0; i < a; i++){
        printf("%d ", heap[i]);
    }
    printf("\n\n");

    rearranjar_heap(heap, 0, a);
    // colocando a raiz no vetor ordenador

for(int i = 0; i<a; i++){
        vetor_ordenador_invertido[i] = trocar_raiz(heap, a-i);
        rearranjar_heap(heap, 0, a-i-1);
        if(a-i-1 > 1) {
            for(int j = 0; j < a-i-1; j++){
                printf("%d ", heap[j]);    
            }
            printf("\n");
        }
        if(a-i-1 != 0) printf("\n");
    }
    // invertendo a heap

    for(int i =0; i < a; i++){
        vetor_ordenador[i] = vetor_ordenador_invertido[a-i-1];
    }

    // imprimir
    for(int i = 0; i < a; i++){
        printf("%d ", vetor_ordenador[i]);
    }
    printf("\n");

    return 0;
}
