#ifndef ARVORE_BINARIA_H
	#define ARVORE_BINARIA_H
    
    #include "item.h"

    typedef struct no_ NO;

    struct no_ {
        ITEM  *item;
        NO *esq;
        NO *dir;
    };

    typedef struct ab_ AB;

    AB *abb_criar(void); 
    bool abb_inserir(AB *T, ITEM *item, int lado, int chave);
    bool abb_remover(AB *T, int chave);
    void abb_apagar_arvore(AB **T);

    void abb_imprimir_crescente(AB* arvore);
    
#endif
