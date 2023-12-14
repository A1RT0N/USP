#include "set.h"
#include <stdio.h>
#include <stdlib.h>

int main(){
    SET *A, *B; // Declara dois conjuntos e seus tamanhos
    int tamanho_do_a, tamanho_do_b, elemento_a_inserir;
    int operador; // Declara a variável de operação a ser feita

    // Cria dois conjuntos

    A = set_criar();
    B = set_criar();

    scanf("%d %d", &tamanho_do_a, &tamanho_do_b);

    for(int i=0; i<tamanho_do_a; i++){ // Preenche o conjunto A
        scanf("%d",&elemento_a_inserir);
        set_inserir(A, elemento_a_inserir);
    }

    for(int i=0; i<tamanho_do_b; i++){ // Preenche o conjunto B
        scanf("%d",&elemento_a_inserir);
        set_inserir(B, elemento_a_inserir);
    }

    scanf("%d", &operador);

    switch(operador){
    case 1: { // Pertencimento
        int numero_analise;
        scanf("%d", &numero_analise);
        if(set_pertence(A,numero_analise)) 
            printf("O %d pertence ao conjunto.", numero_analise);
        else
            printf("O %d não pertence ao conjunto.", numero_analise);
        break;
    }
    case 2: { // União
        SET *C = set_uniao(A,B);
        set_imprimir(C); // Imprime o novo conjunto
        set_apagar(&C); // Apaga o novo conjunto
        break;
    }
    case 3: { // Intersecção
        SET *C = set_interseccao(A, B);
        set_imprimir(C);
        set_apagar(&C); 
        break;
    }
    case 4: { // Remoção de elemento do primeiro conjunto
        int numero_analise; // Variável que é o número que será removido do primeiro conjunto
        scanf("%d", &numero_analise);
        set_remover(A,numero_analise);
        set_imprimir(A); // Imprime o primeiro conjunto
    }
  }

    // Apaga o conjunto A e B
    set_apagar(&A);
    set_apagar(&B);
}

