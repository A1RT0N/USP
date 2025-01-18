#include <stdio.h>
#include <stdlib.h>

#include "pilha.h"
#include "avl.h"

struct no_pilha{
    NO_P *proximo;

    NO *no_arvore;
};

struct pilha_ {
    NO_P *inicio;

    int tamanho;
};

NO_P* criar_no(NO *no_arvore){
    NO_P *new_node = (NO_P *) malloc(sizeof(NO_P));

    new_node->proximo = NULL;
    new_node->no_arvore = no_arvore;

    return new_node;
}

PILHA* pilha_criar(){
    PILHA *pilha = (PILHA *) malloc(sizeof(PILHA));

    pilha->inicio = NULL;
    pilha->tamanho = 0;
}

void pilha_inserir(PILHA *pilha, NO *no_arvore){
    if (pilha->tamanho == 0){
        pilha->inicio = criar_no(no_arvore);

        pilha->tamanho ++;

        return;
    }

    NO_P *new_node = criar_no(no_arvore);

    new_node->proximo = pilha->inicio;
    pilha->inicio = new_node;

    pilha->tamanho ++;
}

NO* pilha_remover(PILHA *pilha){
    NO_P* tmp = pilha->inicio;

    pilha->inicio = pilha->inicio->proximo;

    NO* arvore = tmp->no_arvore;

    free(tmp);

    pilha->tamanho --;

    return arvore;
}

int pilha_tamanho(PILHA *pilha){
    return pilha->tamanho;
}