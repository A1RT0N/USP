#include "abb.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include "pilha.h"



struct ab_
{
    NO* raiz;
    int profundidade;
};


NO *abb_inserir_no(NO *raiz, NO *novo_no);
NO* abb_cria_no(ITEM* item);
bool abb_inserir_iterativo(AB *T, ITEM *item, int lado, int chave);
bool abb_remover_aux (NO **raiz, int chave);
void troca_max_esq(NO *troca, NO *raiz, NO *ant);
int ab_preordem(NO *raiz);
void apagar_arvore(NO **raiz);


void abb_em_ordem(NO* raiz){ // impressão crescente
    if(raiz == NULL){
        return;
    }
    abb_em_ordem(raiz->esq);
    printf("%d", item_get_chave(raiz->item));
    abb_em_ordem(raiz->dir);

}

void abb_imprimir_crescente(AB* arvore){
    if(arvore == NULL || arvore->raiz == NULL) return;
    abb_em_ordem(arvore->raiz);
    
}



AB *abb_criar(void){
    AB* arvore = (AB*) malloc(sizeof(AB));
    if(arvore == NULL) return NULL;
    arvore->raiz = NULL;
    arvore->profundidade = 0;

    return arvore;
}


NO* abb_cria_no(ITEM* item){
    if(item == NULL) return NULL;
    NO* nozinho = (NO*) malloc(sizeof(NO));
    if(nozinho == NULL) return NULL;
    nozinho->item = item;
    nozinho->dir = NULL;
    nozinho->esq = NULL;
    
    return nozinho;
}

NO *abb_inserir_no(NO *raiz, NO *novo_no){
    if (raiz == NULL)
        raiz = novo_no;
    else if(item_get_chave(novo_no->item) < item_get_chave(raiz->item))
        raiz->esq = abb_inserir_no(raiz->esq,novo_no);
    else if(item_get_chave(novo_no->item) > item_get_chave(raiz->item))
        raiz->dir = abb_inserir_no(raiz->dir,novo_no);
    return(raiz);
}

void abb_inserir_no_melhor(NO** raiz, NO* novo_no){ // Teria que chamar essa função com &
    if((*raiz) == NULL)
        (*raiz) = novo_no;
    else if(item_get_chave(novo_no->item) < item_get_chave((*raiz)->item))
        abb_inserir_no_melhor(&(*raiz)->esq, novo_no);
    else if(item_get_chave(novo_no->item) > item_get_chave((*raiz)->item))
        abb_inserir_no_melhor(&(*raiz)->dir, novo_no);
}

bool abb_inserir(AB *T, ITEM *item, int lado, int chave){
    NO *novo_no;
    if (T == NULL)
        return(false);
    novo_no = abb_cria_no(item);
    if (novo_no != NULL){
        T->raiz = abb_inserir_no(T->raiz, novo_no);
        return(true);
    }
    return(false);
}

/*

NO *abb_inserir_no(NO *raiz, ITEM *item, int lado, int chave){
    if(raiz != NULL){
        raiz->esq = ab_inserir_no(raiz->esq, item, lado, chave);
        raiz->dir = ab_inserir_no(raiz->dir, item, lado, chave);

        if(chave == item_get_chave(raiz->item)){
            if(lado == FILHO_ESQ) raiz->esq = ab_criar_no(item);
            else if(lado == FILHO_DIR) raiz->dir = ab_criar_no(item);
        }
    }

    return (raiz);
} 

*/



/*
Na inserção de ABB, eu nunca vou inserir um novo nó entre dois nós
O novo nó que eu insiro será SEMPRE um nó folha em ABB
*/

bool abb_inserir_iterativo(AB *T, ITEM *item, int lado, int chave){
    NO *novo_no;
    if (T == NULL)
        return(false);
    novo_no = abb_cria_no(item);
    if (novo_no != NULL){
        NO* tmp;
        NO* anterior;
        tmp = T->raiz;
        if(tmp == NULL){
            T->raiz = novo_no;
            return true;
        }
        while(1){
            if(tmp != NULL && item_get_chave(tmp->item) < chave){ // Direita
                anterior = tmp;
                tmp = tmp->dir;
            }else{
                if(tmp != NULL && item_get_chave(tmp->item) > chave){ // Esquerda
                    anterior = tmp;
                    tmp = tmp->esq;
                }else{
                    break;
                }
            }
        }

        if(item_get_chave(anterior->item) < chave){
            anterior->dir = novo_no;
        }else{
            if(item_get_chave(anterior->item) > chave){
                anterior->esq = novo_no;
            }
        }

        return true;
        
    }
    return(false);
}


void troca_max_esq(NO *troca, NO *raiz, NO *ant){
    if(troca->dir != NULL){
        troca_max_esq(troca->dir, raiz, troca);
        return;
    }

    if(raiz == ant) // raiz não tem subárvore direita e troca é o filho esquerdo direto de raiz
        ant->esq = troca->esq; 
    else
        ant->dir = troca->esq;  
    
    raiz->item = troca->item;  // Passa o item da folha pra raiz
    free(troca); troca = NULL; // Apaga o nó folha (MAS NÃO O SEU ITEM, QUE SE NÃO ELE SOME DA RAIZ) 
}


/*

    Caso que consegue ir pra direita à esquerda de 10:
       10
      /  \
     5    15
    / \     \
   3   8     20
      /
     7

    Nesse caso, o 8 troca com o 10. 
    Entra nesse caso: ant->dir = troca->esq;
    Assim a aresta direita de 5 vai apontar pro 7 

    Caso que consegue ir pra direita à esquerda de 10:
       10
      /  \
     5    15
    /    /  \
   3    14  20

    Nesse caso, o 5 troca com o 10. 
    Entra nesse caso: ant->esq = troca->esq;
    Assim a aresta esquerda de 10 vai apontar pro 3 (assim posso apagar o nó 5 tranquilamente)

*/



bool abb_remover_aux (NO **raiz, int chave){
    NO *p;
    if(*raiz == NULL)
        return (false);
    if(chave == item_get_chave((*raiz)->item))
    {
        if ((*raiz)->esq == NULL|| (*raiz)->dir == NULL)
        {/*Caso 1 se resume ao caso 2: há um filho(2) ou nenhum(1)*/
            p = *raiz; // Esse nó p serve para apagar a raiz depois de ela ser modificada
            if((*raiz)->esq == NULL)
                *raiz = (*raiz)->dir;
            else
                *raiz = (*raiz)->esq; // Caso em que raiz é nó folha
            item_apagar(&p->item);
            free(p);
            p = NULL;
        }
        else /*Caso 3: há ambos os filhos(3)*/
            troca_max_esq((*raiz)->esq, (*raiz), (*raiz));
        return(true);
    }
    else
    if(chave < item_get_chave((*raiz)->item))
        return abb_remover_aux (&(*raiz)->esq, chave);
    else
        return abb_remover_aux (&(*raiz)->dir, chave);
}



bool abb_remover(AB *T, int chave){
    if (T != NULL)
        return (abb_remover_aux(&T->raiz, chave));
    return (false);
}


void apagar_arvore(NO **raiz){
    if(*raiz != NULL){
        apagar_arvore(&(*raiz)->esq);
        apagar_arvore(&(*raiz)->dir);

        item_apagar(&(*raiz)->item);

        free(*raiz);

        *raiz = NULL;
    }
}

void abb_apagar_arvore(AB **T){
    apagar_arvore(&(*T)->raiz);
    free(*T);
    *T = NULL;
}

