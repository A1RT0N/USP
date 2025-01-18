#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int *v, int i, int j){
    int tmp;

    tmp = v[i];

    v[i] = v[j];

    v[j] = tmp;
}

int partition(int *v, int ini, int fim){
    int pivo;

    pivo = (ini + fim) / 2;

    swap(v, pivo, fim);

    pivo = v[fim]; 

    int i = ini - 1;
    
    for (int j = ini; j < fim; j++){
        if (v[j] < pivo){
            i++;

            swap(v, i, j);
        }
    }

    i++;

    swap(v, i, fim);

    return i;
}

void quicksort(int *v, int ini, int fim){
    if (fim <= ini) return; //caso base

    int pivo = partition(v, ini, fim);

    quicksort(v, ini, pivo - 1);
    quicksort(v, pivo + 1, fim);
}

void normal(int *v, int chave){
    for (int k = 0; k < 10000; k++){
        if (v[k] == chave){ //se encontrado
            return; //encontrou
        }

        if (v[k] > chave){
            return; //nao encontrou
        }
    }
}

void indexada(int *v, int *indices, int chave){
    int k = 0;

    while (1){
        if (chave == v[indices[k]]) return; //achou a chave

        if (chave >= v[indices[k + 1]]) k++; //ir para o proximo indice
        else{
            for (int i = indices[k] + 1; i < k + 201; i++){
                if (chave == v[i]) return; //achou

                if (v[i] > chave) return;
            }

            return; //nao achou
        }
    }
}

int main(void){
    srand((unsigned int)time(NULL));

    int v[10000];

    for (int i = 0; i < 10000; i++){
        v[i] = (rand() % 100000) + 1;
    }

    quicksort(v, 0, 9999); //ordernar

    int indices[50]; 

    //como existem 10000 elementos, entre cada um dos indices vai existir 200 elementos

    int chaves[50];
    int chave;

    for (int i = 0; i < 50; i++){
        while (1){ //pegar uma chave que ainda nao foi pega
            chave = (rand() % 10000) + 1;

            int flag = 0;

            for (int j = 0; j < i; j++){
                if (chave == v[j]) flag = 1;
            }

            if (!flag) break;
        }

        chaves[i] = chave;
    }

    for (int i = 0; i < 50; i++){
        indices[i] = i*200; //colocar os indexs
    }

    float tempo_antes_1 = clock();
    for (int i = 0; i < 1000; i++){ //buscar cada chave 1000 vezes
        for (int j = 0; j < 50; j++){ //buscar cada chave
            normal(v, chaves[j]);
        }
    }
    float tempo_depois_1 = clock();

    float tempo_antes_2 = clock();
    for (int i = 0; i < 1000; i++){ //buscar cada chave 1000 vezes
        for (int j = 0; j < 50; j++){ //buscar cada chave
            indexada(v, indices, chaves[j]);
        }
    }
    float tempo_depois_2 = clock();

    printf("\n\nTEMPO DE EXECUCAO BUSCA SEQUENCIAL: %f\n\n", (tempo_depois_1 - tempo_antes_1) / CLOCKS_PER_SEC);
    printf("TEMPO DE EXECUCAO BUSCA INDEXADA: %f\n\n", (tempo_depois_2 - tempo_antes_2) / CLOCKS_PER_SEC);
}

/*
TEMPO DE EXECUCAO BUSCA SEQUENCIAL: 0.028865

TEMPO DE EXECUCAO BUSCA INDEXADA: 0.001656

Pode-se ver que mesmo usando uma versão da busca sequencial melhor pelo fato do vetor estar ordenado, a busca indexada é muito melhor.
*/