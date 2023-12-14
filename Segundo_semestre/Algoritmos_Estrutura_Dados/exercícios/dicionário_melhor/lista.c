#include "lista.h"

// O fim sempre está um index a mais


int busca_nao_ordenada(LISTA* lista, ITEM* x);
int busca_binaria(LISTA* listinha, ITEM* x);
bool lista_inserir_posicao(LISTA *l, int pos, ITEM *item);

struct lista_ {
    ITEM *lista[TAM_MAX];
    int inicio; //inicio da lista
    int fim; //fim da lista -1a posicao livre para insercao
};

LISTA *lista_criar(void){
    LISTA* listinha = (LISTA*)malloc(sizeof(LISTA));
    if(listinha != NULL){
        listinha->inicio = inicial;
        listinha->fim = listinha->inicio + 1;
        return listinha;
    }
    return listinha;
}

int busca_nao_ordenada(LISTA* lista, ITEM* x){
    for (int i = 0; i < lista->fim; i++) /*não usar ’i < TAM_MAX’ !!!*/
    if (item_get_chave(lista->lista[i]) == item_get_chave(x))
        return (i);
    return (ERRO);
}

int busca_binaria(LISTA* listinha, ITEM* x){
    int inicio = listinha->inicio;
    int fim = listinha->fim - 1;
    int meio;
    while(1){
        meio = (inicio+fim)/2;
        if(item_get_chave(listinha->lista[meio]) > item_get_chave(x)){
            fim = meio;
        } else{
            if(item_get_chave(listinha->lista[meio]) < item_get_chave(x)){
                inicio = meio;
            } else{
                return meio;
            }
        }
    }
}


bool lista_inserir_posicao(LISTA *l, int pos, ITEM *item) {
    int i;
    //verifica se existe espaço e se a posição está na lista
    if (!lista_cheia(l) && (pos <= l->fim - 1)) {
        for (i = (l->fim-1); i >= pos; i--) { //move os itens
            l->lista[i + 1] = l->lista[i];
            l->lista[pos] = item; //insere novo item
            l->fim++; //incrementa tamanho
            return (true);
        }
    } else {
        return (false);
    }
}



bool lista_inserir(LISTA *lista, ITEM *item){
    ITEM* pos;
    if(lista != NULL && !lista_cheia(lista)){
        item_set_chave(pos, lista_busca(lista,item_get_chave(item)));
        lista_inserir_posicao(lista, item_get_chave(pos),item);
        return true;
    }
    return false;

}
bool lista_apagar(LISTA **lista){
    for(int i = (*lista)->inicio; i< (*lista)->fim; i++){
        item_apagar((*lista)->lista[i]);
    }
}


ITEM* lista_remover(LISTA *lista, int chave){
    if(!lista_vazia(lista)){
        int pos = item_get_chave(lista_busca(lista, chave));
        ITEM* item;
        item_set_chave(item,chave);
        for(int i = pos; i< lista->fim-1; i++){
            lista->lista[i] = lista->lista[i+1]; // Shift
        }
        lista->fim--;
        return item;
    }

    return NULL;

}   


ITEM *lista_busca(LISTA *lista, int chave){
    ITEM* item;
    if(!ORDENADA){
        item_set_chave(item,busca_nao_ordenada(lista, chave));
    } else{
        item_set_chave(item,busca_binaria(lista, chave)); 
    }
    return item;
}

int lista_tamanho(LISTA *lista){
    return(lista->fim-lista->inicio - 1);
}

bool lista_cheia(LISTA* lista){
    if(lista->fim == TAM_MAX-1){
        return true;
    }else{
        return false;
    }
}

bool lista_vazia(LISTA* lista){
    if(lista->fim -1 == lista->inicio){
        return true;
    }else{
        return false;
    }
}

void lista_imprimir(LISTA* lista){
    for(int i = lista->inicio; i<lista->fim; i++){
        printf("%d", lista->lista[i]);
    }
}
// Fazer (não no .h) inserir_fim,busca sequencial ordenada, busca_nao_ordenada, busca binária (em lista_inserir, vc analisa ela pra ver se ela está ordenada ou não)
