#ifndef PILHA_H
	#define PILHA_H

    #include "avl.h"

    typedef struct no_pilha NO_P;
    typedef struct pilha_ PILHA;

    PILHA* pilha_criar();
    void pilha_inserir(PILHA *pilha, NO *no_arvore);
    NO* pilha_remover(PILHA *pilha);
    int pilha_tamanho(PILHA *pilha);
	
#endif