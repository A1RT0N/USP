#include "lista.h"

int busca_nao_ordenada(LISTA* lista, int x);
int busca_binaria(LISTA* listinha, int x);
bool lista_inserir_posicao(LISTA *l, int pos, ITEM *item);

struct lista_ {
    ITEM *lista[TAM_MAX];
    int tamanho;
};

LISTA *lista_criar(void){
    LISTA* listinha = (LISTA*)malloc(sizeof(LISTA));
    if(listinha != NULL){
        listinha->tamanho = 0;
        return listinha;
    }
    return listinha;
}

int busca_nao_ordenada(LISTA* lista, int x){
    for (int i = 0; i < lista->tamanho; i++){
        if (item_get_chave(lista->lista[i]) == x)
            return (i);
    }
    return (ERRO);
}

int busca_binaria(LISTA* listinha, int x){
    int inicio = 0;
    int fim = listinha->tamanho - 1;
    int meio;
    while (fim >= inicio){
        meio = (inicio + fim) / 2;
        if (item_get_chave(listinha->lista[meio]) == x){
            return meio;
        }
        if (x > item_get_chave(listinha->lista[meio])){
            inicio = meio + 1;
        } else{
            fim = meio - 1;
        }
    }
    return inicio;
}


bool lista_inserir_posicao(LISTA *l, int pos, ITEM *item) {
    if (!lista_cheia(l) && (pos <= l->tamanho - 1)) {
        for (int i = (l->tamanho-1); i >= pos; i--) { 
            l->lista[i + 1] = l->lista[i];
        }
        l->lista[pos] = item; 
        l->tamanho++; 
        return (true);
    } else {
        return (false);
    }
}



bool lista_inserir(LISTA *lista, ITEM *item){
    if(lista != NULL && !lista_cheia(lista)){
        int pos;
        if(lista_vazia(lista)){
            lista->lista[0] = item;
            lista->tamanho++;
            return true;
        }

        if(ORDENADA){
            pos = busca_binaria(lista,item_get_chave(item));
        }else{
            pos = busca_nao_ordenada(lista,item_get_chave(item));
        }

        for (int i = (lista->tamanho-1); i >= pos; i--) { 
            lista->lista[i + 1] = lista->lista[i];
        }
        lista->lista[pos] = item; 
        lista->tamanho++; 

        return true;
    }
    return false;

}
void lista_apagar(LISTA **lista){
    for(int i = 0; i< (*lista)->tamanho; i++){
        item_apagar(&((*lista)->lista[i]));
    }
    free(*lista);
    *lista = NULL; 
}


ITEM* lista_remover(LISTA *lista, int chave){
    if(!lista_vazia(lista) && lista != NULL){
        int pos;
        if(ORDENADA){
            pos = busca_binaria(lista,chave);
        }else{
            pos = busca_nao_ordenada(lista,chave);
        }
        ITEM* item;
        item = lista->lista[pos];
        for(int i = pos; i< lista->tamanho-2; i++){
            lista->lista[i] = lista->lista[i+1]; // Shift
        }

        lista->tamanho--;
        return item;
    }

    return NULL;

}   


ITEM *lista_busca(LISTA *lista, int chave){
    ITEM* item;
    if(!ORDENADA){
        item_set_chave(item,chave);
    } else{
        item_set_chave(item,chave); 
    }
    return item;
}

int lista_tamanho(LISTA *lista){
    return(lista->tamanho);
}

bool lista_cheia(LISTA* lista){
    if(lista->tamanho == TAM_MAX-1){
        return true;
    }else{
        return false;
    }
}

bool lista_vazia(LISTA* lista){
    if(lista->tamanho == 0){
        return true;
    }else{
        return false;
    }
}

void lista_imprimir(LISTA* lista){
    for(int i = 0; i<lista->tamanho; i++){
        if(i == lista->tamanho-1){
            printf("[%d];", item_get_chave(lista->lista[i]));
        }else{
            printf("[%d]; ",item_get_chave(lista->lista[i]));
        }
    }
    printf("\n\n");
}
