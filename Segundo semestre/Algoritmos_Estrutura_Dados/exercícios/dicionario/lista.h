#ifndef LISTA // Se alguém já implementou essa estrutura de dados --- Lista estática
    #define TAM_MAX 100

    // Criar lista
    // -> Inserir item (última posição)
    // -> Remover item (última posição)
    // -> Recuperar item (dada uma chave)
    // -> Contar número de itens
    // -> Verificar se a lista está vazia
    // -> Verificar se a lista está cheia
    // -> Imprimir lista


    #include <stdio.h>
    #include <stdlib.h>
    #include <stdbool.h>
    #include "item.h"

    typedef struct lista LISTA;
    

    LISTA* lista_criar(void);
    bool lista_cheia(LISTA* lista);
    bool lista_vazia(LISTA* lista);
    bool lista_apagar(LISTA* lista);
    bool lista_insert(LISTA* lista, ITEM* item);
    bool lista_remover(LISTA* lista);
    ITEM* lista_recuperar_item(LISTA* lista, int chave);
    int lista_contar_itens(LISTA* lista);
    void lista_print(LISTA* lista);
    

#endif