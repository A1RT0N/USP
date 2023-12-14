#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAMANHO_VETOR 10000  // Exemplo com 10 mil elementos

void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp; 
}
int *busca_sequencial(int v[], int tamanho, int num_buscado) {
    for (int i = 0; i < tamanho; i++) {
        if (v[i] == num_buscado) {
            return &v[i];
        }
    }
    return NULL;
}


int *busca_transposicao(int v[], int tamanho, int num_buscado) {
    for (int i = 0; i < tamanho; i++) {
        if (v[i] == num_buscado) {
            int tmp = v[i];
            for (int j = i; j > 0; j--) {
                v[j] = v[j-1];
            }
            v[0] = tmp;
            return &v[0];
        }
    }
    return NULL;
}


int main() {
    int vetor[TAMANHO_VETOR];

    // Inicializa o gerador de números aleatórios
    srand(time(NULL));

    // Preenche o vetor com números aleatórios
    for (int i = 0; i < TAMANHO_VETOR; i++) {
        vetor[i] = rand() % 100001;  // Pode ajustar para gerar números dentro de uma faixa específica
    }
    int j;

    float tempo_antes_1 = clock();
    // Aqui 50 chaves distintas são buscadas 1000 vezes cada utilizando a busca com transposicao
    for (int k = 0; k < 50; k++) {
        j = rand() % 100001;
        for (int i = 0; i < 1000; i++) {
            busca_sequencial(vetor, TAMANHO_VETOR, j);
        }
    }

    float tempo_depois_1 = clock();


    float tempo_antes_2 = clock();
    // Aqui 50 chaves distintas são buscadas 1000 vezes cada utilizando a busca com transposicao
    for (int k = 0; k < 50; k++) {
        int indice_aleatorio = rand() % TAMANHO_VETOR; // Gera um índice aleatório dentro do vetor
        j = vetor[indice_aleatorio]; // Usa o valor nesse índice para a busca     
        printf("NUMERO BUSCADO %d: %d\n", k, j);   
        for (int i = 0; i < 1000; i++) {
            busca_transposicao(vetor, TAMANHO_VETOR, j);
        }
    }

    float tempo_depois_2 = clock();
    

    // Código para verificar a ordenação, imprimir o vetor, etc.
    printf("\n\nPRIMEIROS 50 NUMEROS DO VETOR APOS A BUSCA TRANSPOSICAO:\n");
    for (int i = 0; i < 50; i++) {
        printf("%d\n", vetor[i]); 
    }
    printf("\n\nTEMPO DE EXECUCAO BUSCA SEQUENCIAL: %f\n\n", (tempo_depois_1 - tempo_antes_1) / CLOCKS_PER_SEC);
    printf("TEMPO DE EXECUCAO BUSCA TRANSPOSICAO: %f", (tempo_depois_2 - tempo_antes_2) / CLOCKS_PER_SEC);
    return 0;
}

/* 

COMENTÁRIOS ACERCA DOS RESULTADOS

A busca sequencial levou um tempo considerável, de quase 1 segundo em média.
Por meio da busca com transposição do valor buscado para a primeira posição do vetor, as buscas seguintes se 
tornaram muito mais velozes. Dessa forma, o tempo de execução se tornou, de acordo com os testes realizados,
cerca de 100x mais curto. Esse método de busca para valores mais frequentemente buscados otimiza de maneira
eficiente o programa.

*/

