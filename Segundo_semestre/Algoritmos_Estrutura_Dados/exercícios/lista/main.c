#include <stdio.h>
#include "lista.h"
#include "item.h"

int main(){   // Nao esquecer do apagar e do free
    int n;
    scanf("%d", &n);
    LISTA* lista = lista_criar();
    int v[n];
    int k = 0;
    for(int i = 0; i<n; i++){
        scanf("%d", &k);
        ITEM* item = item_criar(0);
        item_set_chave(item, k);
        lista_inserir(lista, item);
        v[i] = k;  
    }

    lista_imprimir(lista);

    // EXTRA:

    for(int i = 0; i<n;i++){
        lista_remover(lista,v[i]);
    }
    lista_apagar(&lista);
    return 0;

}
