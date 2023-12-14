// IMPLEMENTAÇÃO CIRCULAR
#include "fila.h"
struct fila_{
    ITEM *fila[TAM_MAX];
    int inicio; /*posicao do 1o elemento da fila*/
    int fim; /*posicao do ultimo elemento da fila*/
    int tamanho;
};

FILA *fila_criar(void){
/*pré-condição: existir espaço na memória.
Na implementação estática não há o que verificar*/
    FILA *fila = (FILA *) malloc(sizeof(FILA));
    fila->inicio = 0;
    fila->fim = 0;
    fila->tamanho = 0; /* fila vazia*/
    return (fila);
}

bool fila_cheia(FILA *fila) {
    return (fila->tamanho == TAM_MAX);
}

bool fila_vazia(FILA *fila) {
    return (fila->tamanho == 0);
}


bool fila_inserir(FILA *fila, ITEM *item){
 if (fila != NULL && (!fila_cheia(fila)) ){
    fila->fila[fila->fim] = item;
    fila->fim = (fila->fim+1) % TAM_MAX;
    fila->tamanho ++;
 return(true);
}

 return(false);
}

ITEM *fila_remover(FILA *fila){
    if (fila != NULL && (!fila_vazia(fila))){
        ITEM* removido;
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
        printf("%d ", item_get_chave(fila->fila[i]));
    }
}

ITEM *fila_frente(FILA *fila){
    return (fila->fila[fila->inicio]);
}

// void fila_apagar(FILA **fila){

// }




// Fora de pilha




void cartas(int n){

    FILA * cartinhas = fila_criar();

    for(int i = 1; i<= n; i++){
        ITEM * numero = item_criar(i);
        fila_inserir(cartinhas,numero);
    }

    printf("Discarded cards: ");

    while(fila_tamanho(cartinhas) != 1){
        ITEM* numero1;
        numero1 = fila_remover(cartinhas);
        printf("%d", item_get_chave(numero1));
        item_apagar(&numero1);
        // ITEM* numero2 = item_criar(item_get_chave(fila_frente(cartinhas)));
        numero1 = item_criar(item_get_chave(fila_frente(cartinhas)));
        fila_inserir(cartinhas,numero1);
        numero1 = fila_remover(cartinhas);
        item_apagar(&numero1);
        if(fila_tamanho(cartinhas) != 1){
            printf(", ");
        }
    }
    

    printf("\nRemaining card: %d\n", item_get_chave(fila_frente(cartinhas)));

    fila_apagar(&cartinhas);
    
}



/*

    DEU CERTO TAMBÉM - eu que fiz

    while(fila_tamanho(cartinhas) != 1){
        ITEM* numero1;
        numero1 = fila_remover(cartinhas);
        printf("%d", item_get_chave(numero1));
        item_apagar(&numero1);
        ITEM* numero2 = item_criar(item_get_chave(fila_frente(cartinhas)));
        fila_inserir(cartinhas, numero2);
        numero2=fila_remover(cartinhas);
        item_apagar(&numero2);
        if(fila_tamanho(cartinhas) != 1){
            printf(", ");
        }
    }

*/