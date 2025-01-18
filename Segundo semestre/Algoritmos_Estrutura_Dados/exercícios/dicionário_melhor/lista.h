// LISTA LINEAR SEQUENCIAL  - Ver benefícios e malefícios

#ifndef LISTA_H
    #define LISTA_H
    #define TAM_MAX 100 
    #define inicial 0
    #define ERRO -32000
    #define ORDENADA 0  // O USUÁRIO DEFINE AQUI SE ELE QUER ORDENADA OU NÃO - O código tem que estar preparado para os dois --> 0 = Ordeanda; 1 = Não ordenada
    typedef struct lista_ LISTA;
    #include "item.h"

    LISTA *lista_criar(void);
    bool lista_inserir(LISTA *lista, ITEM *item);
    bool lista_apagar(LISTA **lista);
    ITEM *lista_remover(LISTA *lista, int chave); // Fazer uma busca pelo item - requer deslocamento
    ITEM *lista_busca(LISTA *lista, int chave);
    
    int lista_tamanho(LISTA *lista);
    bool lista_vazia(LISTA *lista);
    bool lista_cheia(LISTA *lista);
    void lista_imprimir(LISTA *lista);
#endif

// Fazer (não no .h) inserir_fim,busca sequencial ordenada, busca_nao_ordenada, busca binária (em lista_inserir, vc analisa ela pra ver se ela está ordenada ou não)
