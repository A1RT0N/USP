// IMPLEMENTAÇÃO ENCADEADA 

#include "fila.h"

typedef struct no NO;
struct no {
ITEM* item;
NO* proximo;
};

struct fila_{
    NO* inicio;
    NO* fim;
    int tamanho;
};

FILA *fila_criar(void){

    FILA *fila = (FILA *) malloc(sizeof(FILA));
    if(fila == NULL){
        return NULL;
    }
    fila->inicio = NULL;
    fila->fim = NULL;
    fila->tamanho = 0; 
    return (fila);
}


bool fila_vazia(FILA *fila) {
    return (fila->tamanho == 0);
}

bool fila_cheia(FILA *fila){
    if (fila != NULL){
        NO *novo = (NO*) malloc(sizeof(NO));
        if(novo != NULL){
            free(novo);
            return false;
        }
        return true;
    }
    return true;


}


bool fila_inserir(FILA *fila, ITEM *item){
 if (fila != NULL && !fila_cheia(fila)){
    NO* pnovo = (NO *)malloc(sizeof(NO));
        pnovo->item = item;
        pnovo->proximo = NULL;

        if (fila_vazia(fila)){
            fila->inicio = pnovo;   
            fila->fim = pnovo;
            fila->tamanho++;
            return true;
        }

        fila->fim->proximo = pnovo;
        fila->fim = pnovo;
        fila->tamanho++;

        return true;
}

/*
if(!lista_cheia(lista)){
        NO* pnovo = (NO *)malloc(sizeof(NO));
        pnovo->item = item;
        pnovo->proximo = NULL;

        if (lista_vazia(lista)){
            lista->inicio = pnovo;
            lista->fim = pnovo;
            lista->tamanho++;
            return true;
        }

        lista->fim->proximo = pnovo;
        lista->fim = pnovo;
        lista->tamanho++;


        return true;
    }
*/

return(false);
}

ITEM *fila_remover(FILA *fila){
    if (fila != NULL && (!fila_vazia(fila))){
        NO* removido;
        removido=fila->inicio;
        ITEM* item = fila->inicio->item;
        fila->inicio = fila->inicio->proximo;
        removido->proximo = NULL;
        free(removido);
        removido = NULL;
        fila->tamanho--;
        return item;
    }
    return NULL;
}

int fila_tamanho(FILA *fila){
    return fila->tamanho;
}

void fila_imprimir(FILA *fila){
    for(NO*i = fila->inicio; i!= NULL; i=i->proximo){
        item_imprimir(i->item);
    }
}

ITEM *fila_frente(FILA *fila){
    return (fila->inicio->item);
}

void fila_apagar(FILA **fila){
    /* Implemente um procedimento recursivo capaz
    de esvaziar uma fila*/
    if ((*fila)->inicio != NULL && (!fila_vazia(*fila)) ) {
        NO* paux;
        paux = (*fila)->inicio;
        (*fila)->inicio = (*fila)->inicio->proximo;
        item_apagar(&(paux->item));
        free(paux);
        paux = NULL;
        (*fila)->tamanho--;
        fila_apagar(fila);
    }

}

void fila_inverter(FILA **fila){ 
    /*Implemente um procedimento para inverter
    uma fila (o primeiro elemento se tornará o
    último e vice-versa)*/

    NO *anterior = NULL;
    NO *atual = (*fila)->inicio;
    NO *proximo = NULL;
    (*fila)->fim = (*fila)->inicio;
    while (atual != NULL){
        proximo = atual->proximo; // Próximo vai virar o próximo
        atual->proximo = anterior; // Quem atual apontava vai apontar para anterior

        anterior = atual; // Anterior vai virar o atual
        atual = proximo; // Atual vai virar o próximo
    }

    (*fila)->inicio = anterior;
    
    
}


