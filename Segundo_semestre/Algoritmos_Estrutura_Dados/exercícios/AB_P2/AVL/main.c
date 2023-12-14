#include <stdio.h>
#include "avl.h"
#include <stdlib.h>

int main(){

    AVL* avl = avl_criar();

    for(int i = 1; i<10; i+= 2){
        avl_inserir(avl, item_criar(i));
    }
    avl_imprimir(avl);

    avl_remover(avl, 9);
    
    
    
    return 0;
}