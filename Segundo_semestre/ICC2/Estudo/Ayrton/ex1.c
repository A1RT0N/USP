#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int *v, int i, int j);
int busca_normal(int *v, int n, int inicio, int chave);
void busca_transposicao(int *v, int n, int chave);


void swap(int *v, int i, int j){
    int tmp;

    tmp = v[i];

    v[i] = v[j];

    v[j] = tmp;
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


void busca_transposicao(int *v, int n, int chave){
    for(int i = 0; i< n; i++){
        if(v[i] == chave){
            if(i != 0){
                swap(v,i,i-1);
            }
            return;
        }
    }
}



int main(){

    srand((unsigned int)time(NULL));

    int v[10000];

    for (int i = 0; i < 10000; i++){
        v[i] = (rand() % 100000) + 1;
    }

    int chave[50] = {0};
    
    int tmp = 0;
    int i = 0;

    while(i<50){
        tmp = rand()%100000 ;
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


    double tempo_antes_da_busca_transposicao = clock();

    for(int i =0; i< 1000; i++){
        for(int j= 0; j< 50; j++){
            busca_transposicao(v,10000,chave[j]);
        }
    }

    double tempo_depois_da_busca_transposicao = clock();

    printf("Tempo da busca normal: %lf\nTempo da busca transposicao: %lf\n",(tempo_depois_da_busca_normal-tempo_antes_da_busca_normal)/CLOCKS_PER_SEC, (tempo_depois_da_busca_transposicao-tempo_antes_da_busca_transposicao)/CLOCKS_PER_SEC);

    return 0;

}



/*

Implemente em C uma função que, supondo que haja recuperação recorrente de
registros, realiza busca sequencial em um arranjo não ordenado de 10.000 elementos e
utiliza o método da transposição. Neste método um registro recuperado com sucesso é
trocado com o registro anterior. Faça o seguinte experimento com esse método:
- Insira 10.000 chaves aleatórias entre 1 e 100.000 no arranjo
- Marque o tempo para realizar a busca sequencial convencional de 50 chaves
diferentes (ex. os números de 1 a 51), buscando cada chave 1000 vezes.
- Marque o tempo para realizar a busca sequencial com o método da transposição
(técnicas vistas em aula, p.e. chaves mais buscadas são colocadas no inicio do
vetor), das mesmas 50 chaves diferentes, buscando cada chave 1000 vezes.
Considere buscas desses elementos em ordem aleatória.

*/