/*Aula 4
Econtrar o x e retornar o ponteiro referente a ele na lista*/
#include <stdio.h>
#include <stdlib.h>

#define N 10

struct celula{
    int conteudo;
    struct celula *prox;
};

typedef struct celula cel;

void criar(cel **inicio){
    cel *new_cell;
    cel *fim;

    for (int i = 0; i < N; i++){
        new_cell = (cel *) malloc(sizeof(cel));

        new_cell->conteudo = i;

        if ((*inicio) == NULL) (*inicio) = new_cell;
        else fim->prox = new_cell;

        fim = new_cell;
    }
}

cel* achar(cel *inicio, int x){
    for (cel *p = inicio; p != NULL; p = p->prox){
        if (p->conteudo == x) return p;
    }

    return NULL;
}

void apagar(cel *incio){
    cel *tmp;
    cel *p;

    while (p != NULL){
        tmp = p;

        p = p->prox;

        free(tmp);
    }
}

int main(void){
    cel *inicio = NULL;

    criar(&inicio);

    cel *x_ponteiro;

    x_ponteiro = achar(inicio, 2);

    if (x_ponteiro == NULL) printf("Numero nao encontrado");
    else printf("%d", x_ponteiro->conteudo);

    apagar(inicio);
}