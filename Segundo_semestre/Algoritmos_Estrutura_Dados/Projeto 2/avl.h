#ifndef ARVORE_BINARIA_H
	#define ARVORE_BINARIA_H

    #include <stdio.h>
    #include <stdlib.h>
    #include <stdbool.h>

    typedef struct avl_ AVL;
    typedef struct no_ NO;

    AVL *avl_criar(void);
    void avl_apagar(AVL **arvore);
    bool avl_inserir(AVL *arvore, int inteiro);
    bool avl_remover(AVL *T, int chave);
    bool avl_busca(AVL* arvore, int chave);

    void avl_imprimir(AVL * arvore);

    NO* avl_raiz_esquerda(NO* raiz);
    NO* avl_raiz_direita(NO* raiz);
    NO* avl_raiz(AVL* arvore);
    int avl_raiz_item(NO* raiz);
    
#endif


