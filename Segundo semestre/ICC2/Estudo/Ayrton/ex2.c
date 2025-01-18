#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct index_
{
    int kindex;
    int pos;
};

typedef struct index_ index;

void quicksort(int *v, int ini, int fim);
void cria_indice(int *v, int n, index indice[], int tam_indice);
int busca_normal(int *v, int n, int inicio, int chave);
int busca_indice(int *v, int n, index indice[], int tam_indice, int chave);
void swap(int *v, int i, int j);
int partition(int *v, int ini, int fim);

void cria_indice(int *v, int n, index indice[], int tam_indice){
    int pos;
    for(int i =0; i< tam_indice; i++){
        pos = (i*n)/tam_indice;

        indice[i].kindex = v[pos];
        indice[i].pos = pos;
        
    }
}


int busca_normal(int *v, int n, int inicio, int chave){ // Nos casos normais, inicio começa com 0;
    for(int i = inicio; i< n; i++){
        if(v[i] == chave){
            // printf("Achou o %d na posição: %d\n", v[i], i);
            return i;
        }
    }

    // se nao achou

    return -1;

}

int busca_indice(int *v, int n, index indice[], int tam_indice, int chave){ // para só um index (um nível) -- função retorna a posição do index que foi achada no vetor
    int index = 0;

    for(int i =0; i< tam_indice; i++){
        if(i+1 < tam_indice && indice[i+1].kindex > chave){
            if(indice[i].kindex == chave){
                // printf("Achou o %d na posição: %d\n", indice[i].kindex, indice[i].pos);
                return indice[i].pos;
            }else{
                index = indice[i].pos;
                break;
            }
        }
        if(indice[tam_indice].kindex == chave){
            // printf("Achou o %d na posição: %d\n", indice[i].kindex, indice[i].pos);
            return indice[tam_indice].pos;
        }else{
            index = indice[tam_indice].pos;
            break;
        }
    }

    return busca_normal(v,n,index,chave);


}


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

void printar_vetor(int *v, int n){
    for (int i = 0; i< n; i++){
        printf("%d ", v[i]);
    }
}


int main(){

    srand((unsigned int)time(NULL));

    int v[10000];

    for (int i = 0; i < 10000; i++){
        v[i] = (rand() % 100000) + 1;
    }

    double tempo1 = clock();

    quicksort(v, 0, 9999);

    double tempo2 = clock();

    // printar_vetor(v,10000);

    printf("\nTempo de execução para ordenar: %lf \n", (tempo2-tempo1)/CLOCKS_PER_SEC);

    int chave[50] = {0};

    int tmp = 0;

    int i = 0;
    while(i<50){
        tmp = rand()%100000;
        if(busca_normal(v,10000,0,tmp) != -1){ // existe no array original
            // vendo se é repetida
            for(int j = 0; j<i; j++){
                if(tmp == chave[j]){
                    continue;
                }
            }
            chave[i] = tmp;
            i++;
        }
        continue;
    }

    double tempo_antes_da_busca_normal = clock();

    for(int i =0; i< 1000; i++){
        for(int j= 0; j< 50; j++){
            busca_normal(v,10000,0,chave[j]);
        }
    }
    
    double tempo_depois_da_busca_normal = clock();

    index indice[50];

    cria_indice(v,10000,indice,50);

    double tempo_antes_da_busca_indice = clock();

    for(int i =0; i< 1000; i++){
        for(int j= 0; j< 50; j++){
            busca_indice(v,10000,indice,50,chave[j]);
        }
    }

    double tempo_depois_da_busca_indice = clock();

    printf("Tempo da busca normal: %lf\nTempo da busca indexada: %lf\n",(tempo_depois_da_busca_normal-tempo_antes_da_busca_normal)/CLOCKS_PER_SEC, (tempo_depois_da_busca_indice-tempo_antes_da_busca_indice)/CLOCKS_PER_SEC);

    return 0;

}



/*

Implemente em C uma função que realiza busca sequencial indexada. Para isso, utilize
um arranjo original com o número de itens n = 10.000 e o número de índices k = 50.
Faça o seguinte experimento com esse método:
- Insira 10.000 chaves aleatórias entre 1 e 100.000 no arranjo, e ordene o arranjo
utilizando algum método de ordenação (excluindo o bubblesort e variantes).
- Marque o tempo para realizar a busca sequencial convencional no arranjo
original, de 50 chaves diferentes, buscando cada chave 1.000 vezes.
- Marque o tempo para realizar a busca indexada, das mesmas 50 chaves,
buscando cada chave 1.000 vezes

*/