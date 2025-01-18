
#include "heap_seq.h"

struct heap_sequencial{
    ITEM * vetor[TAM];
    int fim; // Index do nó último
};

// FUNÇÕES AUXILIARES(PROTÓTIPOS):

void heap_fix_up(HEAP * heap);
void heap_swap(HEAP *heap, int i, int j);
void heap_fix_down(HEAP* heap);

HEAP *avl_criar(void){
    HEAP* heapzinha = (HEAP*) malloc(sizeof(HEAP));

    if(heapzinha != NULL) heapzinha->fim = -1;

    return heapzinha;
}

bool heap_cheia(HEAP *heap){
    if (heap == NULL) return false;

    return ((heap->fim == TAM - 1) ? true: false);
}

bool heap_vazia(HEAP *heap){
    if (heap == NULL) return false;

    return ((heap->fim == -1) ? true: false);
}


/* Relembrando:
    Nó esquerdo: 2*i + 1
    Nó direito: 2*i + 1;
    Pai do nó: (i-1)/2;
*/ 


void heap_swap(HEAP *heap, int i, int j) { // i e j são index
    ITEM *tmp = heap->vetor[i];
    heap->vetor[i] = heap->vetor[j];
    heap->vetor[j] = tmp;
}

void heap_fix_up(HEAP * heap){
    int w = heap->fim;

    while(w > 0 && item_get_chave(heap->vetor[w]) > item_get_chave(heap->vetor[(w-1)/2])){ // Nó pai
        swap(heap, w, (w-1)/2);
        w = (w-1)/2;
    }

}



bool heap_inserir(HEAP *heap, ITEM *item){
    if(!heap_cheia(heap)){
        heap->fim++;
        heap->vetor[heap->fim] = item;
        heap_fix_up(heap);
        return true;
    }
    return false;
}

void heap_fix_down(HEAP* heap){

    int x = 0;

    while(2*x+1 < heap->fim+1 || 2*x+1 < heap->fim+1){ // Se tem filho -> heap->fim+1 é o tamanho da heap
        int w;
        if(heap->vetor[2*x+1] > heap->vetor[2*x+2]) // Pega quem é o maior filho do nó x
            w = 2*x+1; // esquerdo
        else w=2*x+2; // direito

        if(item_get_chave(heap->vetor[w]) < item_get_chave(heap->vetor[x])) break; // Condição de parada 2

        heap_swap(heap, x, w); // Troca os nós

        x = w; // Desce

    } 

}

bool heap_remover(HEAP* heap, ITEM* item){
    if(heap == NULL || heap_vazia(heap)) return false;

    heap_swap(heap, 0, heap->fim);

    item_apagar(heap->vetor[heap->fim]);

    heap->fim--;

    heap_fix_down(heap);

    return true;

}






// Heap máxima é quando ela é completa e todos os nós filhos são menores que os pais (n é o tamanho)


bool eh_maxima_aux(int *v, int pai, int atual, int n){
    if(atual >= n) return true;

    if(v[pai] >= v[atual]){
        return (eh_maxima_aux(v, atual,2*atual+1, n) && eh_maxima_aux(v, atual,2*atual+2, n));
    }else{
        return false;
    }
}

// Não precisa checar se ela é completa pq qualquer vetor que não tenha buracos pode ser
// escrito como uma heap completa completo

bool eh_heap_max(int v[], int n){ // Considero que o vetor não tenha "buracos" -> o que é óbvio

    return((eh_maxima_aux(v, 0,2*0+1, n) && eh_maxima_aux(v, 0,2*0+2, n)) ? true : false);
}

// Versão iterativa:

bool is_max_heap(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left < n && arr[i] < arr[left])
            return false;
        if (right < n && arr[i] < arr[right])
            return false;
    }
    return true;
}
