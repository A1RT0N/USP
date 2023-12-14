#include "fila.h"

// FILA MODIFICADA PARA NÓ

typedef struct no_{
    ITEM *item;
    NO *esq;
    NO *dir;
    int altura;  
}NO;


struct fila_{
    NO *fila[TAM_MAX];
    int inicio; 
    int fim; 
    int tamanho;
};

FILA *fila_criar(void){

    FILA *fila = (FILA *) malloc(sizeof(FILA));
    fila->inicio = 0;
    fila->fim = 0;
    fila->tamanho = 0; 
    return (fila);
}

bool fila_cheia(FILA *fila) {
    return (fila->tamanho == TAM_MAX);
}

bool fila_vazia(FILA *fila) {
    return (fila->tamanho == 0);
}


bool fila_inserir(FILA *fila, NO *item){
    if (fila != NULL && (!fila_cheia(fila)) ){
    fila->fila[fila->fim] = item;
    fila->fim = (fila->fim+1) % TAM_MAX;
    fila->tamanho ++;
    return(true);
    }

    return(false);
}

NO *fila_remover(FILA *fila){
    if (fila != NULL && (!fila_vazia(fila))){
        NO* removido;
        removido=fila->fila[fila->inicio];
        fila->fila[fila->inicio] = NULL;
        fila->tamanho --;
        fila->inicio ++;
        return removido;
    }

    return NULL;
}

int fila_tamanho(FILA *fila){
    return fila->tamanho;
}

void fila_imprimir(FILA *fila){
    for(int i = fila->inicio; i<= fila->fim; i++){
        printf("%d ", item_get_chave(fila->fila[i]->item));
    }
}

ITEM *fila_frente(FILA *fila){
    return (fila->fila[fila->inicio]->item);
}

void fila_apagar(FILA **fila){
    if((*fila) == NULL) return;

    while(!fila_vazia(*fila)){
        fila_remover(*fila);
    }

    free(*fila);
    *fila = NULL;
}


