#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "item.h"
#include "Pilha.h"

bool balanceada(char *sequencia){
    ITEM *t2;
    PILHA *p1 = pilha_criar();
    for(int i=0;sequencia[i] != '\0'; i++){
        t2 = item_criar(sequencia[i]);
        if(item_get_chave(t2) == '}' || item_get_chave(t2) == ']' || item_get_chave(t2) == ')'){
            if (pilha_vazia(p1) == true){
                return false;
            }
            char topo = item_get_chave(pilha_topo(p1));
            if(item_get_chave(t2) == '}' && topo == '{' || item_get_chave(t2) == ']' && topo == '[' || item_get_chave(t2) == ')' && topo == '('){
                pilha_desempilhar(p1);
            } else{
                return false;
            }
        }else{
            if(pilha_empilhar(p1,t2) == false){
                printf("Não foi possível empilhar!");
                return false;
            }
        }
    }
    if(pilha_vazia(p1) == true){
        return true;
    } else{
        return false;
    }


    // Faltou desalocar a memória

}

