#ifndef ARVORE_BINARIA_H
	#define ARVORE_BINARIA_H
    #include "item.h"

    typedef struct avl_ AVL;

    AVL *avl_criar(void);
    void avl_apagar(AVL **arvore);
    bool avl_inserir(AVL *arvore, ITEM *item);
    bool avl_remover(AVL *T, int chave);
    ITEM* avl_busca(AVL* arvore, int chave);
    void avl_imprimir(AVL * arvore);
    void avl_imprimir_crescente(AVL * arvore);
    
    int avl_altura(AVL * arvore);
    
#endif


