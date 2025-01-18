#include <stdio.h>
#include <stdlib.h>

struct seque{
    int valor;
    struct seque *prox;
};

typedef struct seque seq;

void criar(seq **inicio, int n){
    seq *new_cell;
    seq *fim;

    for (int i = 0; i < n; i++){
        new_cell = (seq *) malloc(sizeof(seq));

        scanf("%d", &(new_cell->valor));

        if ((*inicio) == NULL) {
            (*inicio) = new_cell;
        } else fim->prox = new_cell;

        fim = new_cell;
    }
}

void juncao(seq *t1, seq *t2, seq **t3){
    seq *new_cell;
    seq *fim;

    while (1){
        if ((t1 == NULL) && (t2 ==NULL)){
            break;
        }

        new_cell = (seq *) malloc(sizeof(seq));

        if (t1 == NULL){
            new_cell->valor = t2->valor;
            
            t2 = t2->prox;
        } else if(t2 == NULL){
            new_cell->valor = t1->valor;
            
            t1 = t1->prox;
        } else{
            if (t1->valor < t2->valor){
                new_cell->valor = t1->valor;
                
                t1 = t1->prox;
            } else {
                new_cell->valor = t2->valor;
                
                t2 = t2->prox;
            }
        }

        if ((*t3) == NULL){
                (*t3) = new_cell;
            } else{
                fim->prox = new_cell;
            }

            fim = new_cell;
    }
}

seq* inverter(seq **t3){
    seq *anterior = NULL;
    seq *atual = *t3;
    seq *proximo = NULL;

    while (atual != NULL){
        proximo = atual->prox;
        atual->prox = anterior;

        anterior = atual;
        atual = proximo;
    }

    *t3 = anterior;
}

int main(void){
    int n;

    scanf("%d", &n);

    seq *t1 = NULL;

    criar(&t1, n);

    scanf("%d", &n);

    seq *t2 = NULL;

    criar(&t2, n);

    seq *t3 = NULL;

    juncao(t1, t2, &t3);  

    inverter(&t3);

    for (seq *p = t3; p != NULL; p = p->prox){
        printf("%d ", p->valor);
    }
}