#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int *v, int i, int j){
    int tmp = v[i];
    v[i] = v[j];
    v[j] = tmp;
}

void transposicao(int *v){
    for (int i = 0; i < 1000; i++){ //buscar cada chave 1000 vezes
        for (int j = 1; j <= 51; j++){ //buscar cada chave
            for (int k = 0; k < 10000; k++){
                if (v[k] == j){ //se encontrado
                    if (k > 0) swap(v, k - 1, k); //trocar de posição

                    break;
                }
            }
        }
    }
}

void mover(int *v){
    for (int i = 0; i < 1000; i++){ //buscar cada chave 1000 vezes
        for (int j = 1; j <= 51; j++){ //buscar cada chave
            for (int k = 0; k < 10000; k++){
                if (v[k] == j){ //se encontrado
                    
                    for (int l = k; l >0; l--){
                        v[l] = v[l - 1];
                    }

                    v[0] = j;

                    break;
                }
            }
        }
    }
}

void normal(int *v){
    for (int i = 0; i < 1000; i++){ //buscar cada chave 1000 vezes
        for (int j = 1; j <= 51; j++){ //buscar cada chave
            for (int k = 0; k < 10000; k++){
                if (v[k] == j){ //se encontrado
                    break; //encontrou
                }
            }
        }
    }
}

int main(void){
    srand((unsigned int)time(NULL));

    int v[10000];

    for (int i = 0; i < 10000; i++){
        v[i] = (rand() % 100000) + 1;
    }

    float tempo_antes_1 = clock();
    normal(v);
    float tempo_depois_1 = clock();

    float tempo_antes_2 = clock();
    transposicao(v);
    float tempo_depois_2 = clock();

    for (int i = 0; i < 10000; i++){ //regerando o vetor para não ser bias
        v[i] = (rand() % 10000) + 1;
    }

    float tempo_antes_3 = clock();
    mover(v);
    float tempo_depois_3 = clock();

    printf("\n\nTEMPO DE EXECUCAO BUSCA SEQUENCIAL: %f\n\n", (tempo_depois_1 - tempo_antes_1) / CLOCKS_PER_SEC);
    printf("TEMPO DE EXECUCAO BUSCA TRANSPOSICAO: %f\n\n", (tempo_depois_2 - tempo_antes_2) / CLOCKS_PER_SEC);
    printf("TEMPO DE EXECUCAO BUSCA MOVER: %f", (tempo_depois_3 - tempo_antes_3) / CLOCKS_PER_SEC);
}

/*
Resultados:

TEMPO DE EXECUCAO BUSCA SEQUENCIAL: 0.191325

TEMPO DE EXECUCAO BUSCA TRANSPOSICAO: 0.175999

TEMPO DE EXECUCAO BUSCA MOVER: 0.087280

Pode-se ver que a de tranposicao é mais rápida do que a busca sequencial, mas a de mover é muito mais rápida que as duas.
*/