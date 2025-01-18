#include "item.h"
#include "ab.h"

int ab_preordem(NO *raiz) {
    if(raiz == NULL){
        return 0;
    }
    if (raiz != NULL) {
        int a;
        a = item_get_chave(raiz->item);
        a += ab_preordem(raiz->esq);
        a += ab_preordem(raiz->dir);
        return a;
    }
}

int soma(AB *T){
    return ab_preordem(T->raiz);
}