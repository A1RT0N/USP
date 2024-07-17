#include "ListaEncadeada.h"
#include "funcoes.h"


NO * CriarNO(int id, long int ByteOffset, int size){
    /*
        Função auxiliar de uma lista encadeada que cria um nó e preenche ele dada as entradas
        Recebe três inteiros e retorna um nó
    */


    NO *no = (NO *) malloc(sizeof(NO));

    no->prox = NULL;

    no->id = id;
    no->ByteOffset = ByteOffset;
    no->size = size;

    return no;
}



Lista * ListaCriar(){
    /*
    Função auxiliar da lista encadeada que cria ela
    Não recebe nada como entrada e retorna uma lista encadeada alocada dinamicamente e inicializada
    */

    Lista *lista = (Lista *) malloc(sizeof(Lista));

    lista->topo = NULL;

    lista->tamanho = 0;

    return lista;
}

void ListaInserir(Lista *lista, int id, long int ByteOffset, int size){

    /*
    Função auxiliar da lista encadeada que insere um elemento nela
    Recebe três inteiros referentes aos valores dos registros de indices e a lista e não retorna nada
    */

    NO *new_node = CriarNO(id, ByteOffset, size);

    if ((lista->tamanho == 0) || (lista->topo->size > size)){ //lista vazia ou o elemento a ser inserido é o menor de todos
        new_node->prox = lista->topo;
        lista->topo = new_node;
    } else {
        NO *p = lista->topo;
        NO *anterior = NULL;

        while (p != NULL && p->size <= size) {  // Percorre a lista
            anterior = p;
            p = p->prox;
        }

        new_node->prox = anterior->prox;
        anterior->prox = new_node;
    }

    lista->tamanho++;
}



void ListaRemover(Lista *lista, int id){

    /*
    Função auxiliar da lista encadeada que remove um elemento nela dado um id, que é único
    Recebe o id e a lista e não retorna nada
    */

    NO *p = lista->topo;
    NO *anterior = NULL;

    while (p->id != id){
        anterior = p;
        p = p->prox;
    }

    //p é o cara a ser removido

    if (anterior == NULL){ //signfica que o cara a ser removido é o lista->topo
        lista->topo = p->prox;

        return;
    }

    anterior->prox = p->prox;

    lista->tamanho --;
}


