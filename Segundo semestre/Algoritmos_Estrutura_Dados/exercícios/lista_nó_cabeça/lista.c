#include "lista.h"

typedef struct{
    ITEM* item;
    NO * proximo;
} NO;

struct lista_{
    NO* header;
    NO* fim;

    int tamanho;

};



LISTA *lista_criar(void){

    LISTA* lista = (LISTA*) malloc(sizeof(LISTA));

    if(lista != NULL){
        NO* cabeca = (NO*) malloc(sizeof(NO));
        cabeca->item = NULL;
        cabeca->proximo = NULL;
        lista->header = cabeca;
        lista->fim = NULL;
        lista->tamanho = 0;
    }

    return lista;
}

bool lista_inserir(LISTA *lista, ITEM *item){ // Lista não ordenada
    if(!lista_cheia(lista)){
        NO* pnovo = (NO*) malloc(sizeof(NO));
        pnovo->item = item;
        if(lista_vazia(lista)){
            lista->header->proximo = pnovo;
            pnovo->proximo= NULL;
            lista->fim = pnovo;

        }else{
            lista->fim->proximo = pnovo;
            pnovo->proximo = NULL;
            lista->fim = pnovo;
        }

        lista->tamanho++;
    }

}


ITEM *lista_remover(LISTA *lista, int chave){
    if(lista != NULL){
        NO* aux;
        aux = lista->header->proximo;
        NO* anterior = lista->header;
        while(item_get_chave(aux->item) != chave){
            anterior = aux;
            aux = aux ->proximo;

        }
        anterior->proximo = aux->proximo;
        aux->proximo = NULL;
        free(aux);
        lista->tamanho--;
        return aux->item;
    }
    return NULL;

}
bool lista_apagar(LISTA **lista){
    if(*lista != NULL){
        NO* aux = (*lista)->header->proximo;
        while(aux != NULL){
            NO* tmp = aux->proximo;
            item_apagar(&aux->item);
            free(aux);
            aux = tmp;
        }
        free((*lista)->header);
        free(*lista);
        *lista = NULL;
        return true;
    }
    return false;
}
ITEM *lista_busca(LISTA *lista, int chave){
    if(lista != NULL){
        NO* aux;
        aux = lista->header->proximo;
        while(item_get_chave(aux->item) != chave){
            aux = aux ->proximo;

        }
        return aux->item;
    }
    return NULL;
}
int lista_tamanho(LISTA *lista){
    return lista->tamanho;
}
bool lista_vazia(LISTA *lista){
    return(lista->tamanho == 0 ? 1: 0);
}
bool lista_cheia(LISTA *lista){
    NO* tmp = (NO*) malloc(sizeof(NO));
    if(tmp == NULL){
        return true;
    }else{return false;}
}
void lista_imprimir(LISTA *lista){
    if(lista != NULL){
        NO* aux;
        aux = lista->header->proximo;
        while(aux != NULL){
            item_imprimir(aux->item);
            aux = aux->proximo;
        }
    }

}
bool lista_inverter(LISTA **lista){
    NO *anterior = NULL;
    NO *atual = (*lista)->header->proximo;
    NO *proximo = NULL;
    (*lista)->fim = (*lista)->header->proximo;
    while (atual != NULL){
        proximo = atual->proximo; // Próximo vai virar o próximo
        atual->proximo = anterior; // Quem atual apontava vai apontar para anterior

        anterior = atual; // Anterior vai virar o atual
        atual = proximo; // Atual vai virar o próximo
    }

    (*lista)->header->proximo = anterior;

    return true;
}



