#include "lista.h"
#include "item.h"

int main(){
    int n;
    scanf("%d", &n);
    LISTA *lista = lista_criar();
    for(int i = 0; i<n; i++){
        int x;
        scanf("%d", &x);
        ITEM* item;
        item = item_criar(0);
        item_set_chave(item,x);
        lista_inserir(lista, item);        
    }
    lista_imprimir(lista);

    printf("%d\n", lista_tamanho(lista));

    // Achar o elemento zero na lista e printar

    ITEM* itemx = item_criar(0);
    item_set_chave(itemx, item_get_chave(lista_busca(lista, 0)));
    item_imprimir(itemx);


    // Inverter a lista e printar

    lista_inverter(&lista);
    lista_imprimir(lista);

    // Apagar a lista e printar

    lista_apagar(&lista);

    if(lista == NULL){
        printf("Lista apagada com sucesso!\n");
    }


    return 0;
}