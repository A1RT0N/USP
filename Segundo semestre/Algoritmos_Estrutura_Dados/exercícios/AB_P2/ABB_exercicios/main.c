#include "abb.h"
#include <stdio.h>
#include "item.h"


int main(){ 
    AB *A = abb_criar();

    

    for(int i = 0; i< 10; i++){
        ITEM* item = item_criar(i);
        abb_inserir(A,item,i%2,i);

    }


    abb_imprimir_crescente(A);
    

    abb_apagar_arvore(&A);
      	
    return (0);
}


