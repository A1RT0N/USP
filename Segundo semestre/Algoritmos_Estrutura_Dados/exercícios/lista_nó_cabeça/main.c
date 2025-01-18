#include "lista.h"
#include "item.h"

int main(){
    int n;
    scanf("%d", &n);
    LISTA *lista = lista_criar();
    for(int i = 0; i<n; i++){
        int x;
        scanf("%d ", &x);
        ITEM* item;
        item = item_criar(0);
        item_set_chave(item,x);
        lista_inserir(lista, item);
    }

    lista_inverter(&lista);
    lista_imprimir(lista);

    lista_apagar(&lista);

    return 0;
}