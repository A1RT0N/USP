#ifndef ARVORE_BINARIA_H
	#define ARVORE_BINARIA_H
    #include "item.h"
    

    typedef struct heap_sequencial HEAP;
    #define TAM 100

    HEAP *avl_criar(void);
    bool heap_cheia(HEAP *heap);
    bool heap_vazia(HEAP *heap);

    bool heap_inserir(HEAP *heap, ITEM *item);
    bool heap_remover(HEAP* heap, ITEM* item);

    bool eh_heap_max(int v[], int n);
    
    
#endif