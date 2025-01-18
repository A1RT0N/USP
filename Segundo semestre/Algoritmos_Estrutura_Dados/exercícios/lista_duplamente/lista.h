// LISTA DUPLAMENTE
#ifndef LISTA_H
    #define LISTA_H

    #define inicial 0
    #define ERRO -32000
    
    typedef struct lista_ LISTA;
    #include "item.h"

    LISTA *lista_criar(void);
    bool lista_inserir(LISTA *lista, ITEM *item); // ordenadamente
    bool lista_apagar(LISTA **lista);

    ITEM *lista_remover(LISTA *lista, int chave); 
    ITEM *lista_busca(LISTA *lista, int chave);
    
    int lista_tamanho(LISTA *lista);
    bool lista_vazia(LISTA *lista);
    bool lista_cheia(LISTA *lista);
    void lista_imprimir(LISTA *lista);
    
#endif

