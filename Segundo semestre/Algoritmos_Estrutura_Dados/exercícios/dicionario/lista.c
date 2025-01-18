#include "lista.h"
#include "item.h"

// Aqui não se está a implementação circular

struct lista
{
    ITEM* vector[TAM_MAX];
    int inicio; 
    // Vai precisar pro início na busca binária
    int fim;  // Onde (index) está o último elemento da lista no vector
    // Não preciso da variável int tamanho se não for usar a implementação circular
};


LISTA * lista_criar(){
    LISTA* lista;
    lista = (LISTA *) malloc(sizeof(LISTA)); // Isso é um vetor unitário (ponteiro)
    if(lista != NULL){
        lista->inicio = 0;  // (*lista).inicio ---> tem que colocar parênteses por causa da precedência
        lista->fim = 0;
    }
    return(lista);
}

bool lista_cheia(LISTA* lista){
    if(lista->fim == TAM_MAX-1){
        return true;
    }else{
        return false;
    }
}

bool lista_vazia(LISTA* lista){
    if(lista->fim == lista->inicio){
        return true;
    }else{
        return false;
    }
}

bool lista_insert(LISTA* lista, ITEM* item){
    if((lista != NULL) && (!lista_cheia(lista))){
        lista->vector[lista->fim] = item;
        lista++;

        return true;

    }

    return false;
}

bool lista_remover(LISTA* lista){  // Retirar o último elemento
    if(!lista_vazia(lista)){
        lista->vector[lista->fim] = NULL;
        lista->fim--;
        return true;
    }
    return false;
}


int lista_contar_itens(LISTA* lista){
    return(lista->fim + 1);
}

void lista_print(LISTA* lista){
    for(int i = lista->inicio; i<=lista->fim; i++){
        printf("%d", lista->vector[i]);
    }
}


// Recuperar item (Buscar item)
//  Pré-condição: uma chave x válida é informada  
//  Pós-condição: caso obtenha sucesso, retorna o
// item na lista cuja chave x foi fornecida. Retorna
// erro caso não encontre a chave x. Se x ocorre
// mais de uma vez, retorna a primeira ocorrência

ITEM* lista_recuperar_item(LISTA* lista, int numero){

    bool ok = false;
    
    // Não posso usar o algoritmo de busca binária porque a lista não está necessariamente ordenada. Usarei busca sequencial

    for(int i = lista->inicio; i<= lista->fim; i++){
        if(item_get_chave(lista->vector[i]) == numero){
            return lista->vector[i];
        }
    }

    if(!ok){
        printf("Não foi possivel encontrar o elemento");
        return NULL;
    }
    
}