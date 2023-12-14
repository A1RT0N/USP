/*
4. Uma lista duplamente encadeada pode ser esquematizada como na figura abaixo. Suponha
que cada nó da lista guarde como item um número inteiro apenas. Implemente uma função para
remover um nó em qualquer posição da lista. Defina os tipos de dados (e structs
correspondentes) para esta lista.
*/
#include "lista.h"

typedef struct {
    NO* proximo;
    NO* anterior;
    ITEM* item;
} NO;

struct lista_
{
    NO* inicio;
    NO* fim;
    int tamanho;
};

// PROTÓTIPO
NO *lista_busca_no(LISTA *lista, int chave);


LISTA *lista_criar(void){

    LISTA *lista;
    lista = (LISTA *) malloc(sizeof(LISTA));

    if( lista != NULL){
        lista->inicio = NULL;
        lista->fim = NULL;
        lista->tamanho = 0;

    }

    return lista;
}
bool lista_inserir(LISTA *lista, ITEM *item){ // ORDENADAMENTE
    if(lista!= NULL){
        // Achar
        NO* inicio = lista->inicio;
        NO* fim = lista->fim;
        int flag = -1;
        while(1){
            if(item_get_chave(inicio->proximo->item) >= item_get_chave(item)){
                flag = 0;
                break;
            } 
            if(item_get_chave(fim->anterior->item) <= item_get_chave(item)){
                flag = 1;
                break;
            }
            inicio = inicio->proximo;
            fim = fim->anterior;
        }
        // Inserir;
        NO* pnovo = (NO*) malloc(sizeof(NO));
        pnovo->item = item;
        if(flag == 1){
            pnovo->anterior = fim->anterior;
            fim->anterior = pnovo;
            pnovo->proximo = fim;
            return true;
        }else{
            if(flag == 0){
                pnovo->proximo = inicio->proximo;
                inicio->proximo = pnovo;
                pnovo->anterior = inicio;
                return true;
            }else{
                return false;
            }
        }
    }
    return false;

}


bool lista_apagar(LISTA **lista){
    if((*lista) != NULL){
        NO* inicio = (*lista)->inicio;
        while(inicio != NULL){
            lista_remover(lista,item_get_chave(inicio->item));
            inicio = inicio->proximo;
        }
        (*lista)->inicio = NULL;
        (*lista)->fim = NULL;
        free(*lista);
        (*lista) = NULL;

    }
}
ITEM *lista_remover(LISTA *lista, int chave){
    if(lista!= NULL){
        NO* remover = lista_busca_no(lista,chave);
        remover->anterior->proximo = remover->proximo;
        remover->proximo = NULL;
        ITEM* retornar = remover->item;
        free(remover);
        remover = NULL;
        return retornar;
    }
} 

NO *lista_busca_no(LISTA *lista, int chave){
    if(lista!= NULL){
        NO* atual = lista->inicio;
        while(item_get_chave(atual->item) != chave){
            atual = atual->proximo;
        }
        return atual;
    }
    return NULL;
}


ITEM *lista_busca(LISTA *lista, int chave){
    return (lista_busca_no(lista,chave)->item);
}

int lista_tamanho(LISTA *lista){
    return lista->tamanho;
}
bool lista_vazia(LISTA *lista){
    return (lista->tamanho == 0 ? true: false);
}
bool lista_cheia(LISTA *lista); // trivial
void lista_imprimir(LISTA *lista){
    if(lista!= NULL){
        NO* atual = lista->inicio;
        while(atual != NULL){
            printf("%d\n",item_get_chave(atual->item));
            atual = atual->proximo;
        }
    }
}


