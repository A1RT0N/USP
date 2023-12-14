#include <stdio.h>
#include <stdlib.h>

struct cel {
    int conteudo;
    struct cel *prox;
};

typedef struct cel celula;

void InserirValor(celula *inicial, int inserir) {
    celula *atual = inicial;
    while (atual != NULL) {
        if (((atual->prox)->conteudo) > inserir) {
            celula *NovaCel;
            NovaCel = (celula *) malloc (sizeof(celula));
            NovaCel->conteudo = inserir;
            NovaCel->prox = atual->prox;
            atual->prox = NovaCel;
            break;
        }
        atual = atual->prox;
    }
}


int main() {
    celula *ini = NULL;
    celula *fim = NULL;

    for (int i = 0; i < 20; i+=2) {
        celula *NovaCelula = (celula *) malloc (sizeof(celula));
        NovaCelula->conteudo = i;
        NovaCelula->prox = NULL;

        if (ini == NULL) {
            ini = NovaCelula;
            fim = NovaCelula;
        }
        else {
            fim->prox = NovaCelula;
            fim = NovaCelula;
        }
    }

    celula *atual = ini;
    printf("Lista original:\n");
    while (atual != NULL) {
        printf("%d ", atual->conteudo);
        atual = atual->prox;
    }

    int inserir;
    printf("\nValor a inserir: ");
    scanf("%d", &inserir);

    InserirValor(ini, inserir);
    
    printf("Nova lista:\n");
    atual = ini;
    while (atual != NULL) {
        printf("%d ", atual->conteudo);
        atual = atual->prox;
    }

    atual = ini;
    while (atual != NULL) {
        celula *temp = atual;
        atual = atual->prox;
        free(temp);
    }


    return 0;
}