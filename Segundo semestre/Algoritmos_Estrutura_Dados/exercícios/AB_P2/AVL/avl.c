#include "avl.h"
#include "fila.h"

#define max(a, b) ((a > b) ? a : b)

typedef struct no_ NO;

struct no_{
    ITEM *item;
    NO *esq;
    NO *dir;
    int altura;
};

/*
Embora o fator de balanceamento seja crucial para a operação da árvore AVL,
ele não precisa ser armazenado explicitamente em cada nó.
O fator de balanceamento pode ser calculado dinamicamente como a diferença
entre as alturas das subárvores esquerda e direita de um nó:

fator_balanceamento = avl_altura_no(raiz->fesq) - avl_altura_no(raiz->fdir);
*/


// Relembrando:
// Profundidade: único caminhodo nó até a raiz
// Altura: maior caminho de um nó a uma folha



struct avl_
{
    NO* raiz;
    int profundidade; // FAZER4 ISSO QUE RUDINEI NÃO FEZ
};

// A altura máxima de uma ABB AVL é 1,44 log2

// Protótipos de funções auxiliares
int ab_profundidade(NO *no);
int avl_altura_no(NO* raiz);
void avl_apagar_aux(NO *raiz);
NO* avl_cria_no(ITEM* item);
NO *rodar_direita(NO *a);
NO *rodar_esquerda(NO *a);
NO *rodar_esquerda_direita(NO *a);
NO *rodar_direita_esquerda(NO *a);
NO *avl_inserir_no(NO *raiz, NO *no);
NO *avl_remover_aux(NO **raiz, int chave);
void troca_max_esq(NO *troca, NO *raiz, NO *ant);
NO* avl_busca_aux(AVL*t, NO* raiz, int chave);
void avl_em_ordem(AVL* tree, NO* raiz);
void avl_pos_ordem(AVL* tree, NO* raiz);





int ab_profundidade(NO *no) {
    if (no == NULL) return -1;
    int e = ab_profundidade(no->esq);
    int d = ab_profundidade(no->dir);
    return ((e > d) ? e : d) + 1;
}

int avl_altura_no(NO* raiz) {
    if (raiz == NULL) {
        return -1;
    } else {
        return raiz->altura;
    }
}

int avl_altura(AVL * arvore){
    if (arvore == NULL || arvore->raiz == NULL) return -1;
    return avl_altura_no(arvore->raiz);
}

AVL *avl_criar(void){
    AVL* arvore = (AVL*) malloc(sizeof(AVL));
    if(arvore == NULL) return NULL;
    arvore->raiz = NULL;
    arvore->profundidade = -1; // conveção de profundidade de uma raiz nula

    return arvore;
}

void avl_apagar_aux(NO *raiz) {
    if (raiz != NULL) {
        avl_apagar_aux(raiz->esq);
        avl_apagar_aux(raiz->dir);
        item_apagar(&raiz->item);
        free(raiz);
    }
}


void avl_apagar(AVL **arvore) {
    if ((*arvore) == NULL) return;
    avl_apagar_aux((*arvore)->raiz);
    free(*arvore);
    *arvore = NULL;
}


NO* avl_cria_no(ITEM* item){
    if(item == NULL) return NULL;
    NO* nozinho = (NO*) malloc(sizeof(NO));
    if(nozinho == NULL) return NULL;
    nozinho->item = item;
    nozinho->dir = NULL;
    nozinho->esq = NULL;
    nozinho->altura = 0;

    return nozinho;
}


// Dica: Roda_direita de A se B está à esquerda de A => SEGUE ESSE PRA NÃO SE CONFUNDIR
// Dica2: Você rotaciona a direita se o fator de balanceamento de A for 2 (caído pra esquerda)

NO *rodar_direita(NO *a){
    if(a == NULL) return NULL;
    NO *b = a->esq;  // É o nosso nó temporário (que é o B) ->
    // Atenção para não fazer b->dir = a primeiro (uma subárvore assim ficará órfão)
    a->esq = b->dir;
    b->dir = a;
    a->altura = max(avl_altura_no(a->esq),avl_altura_no(a->dir)) + 1;
    // ATENÇÃO: isso pega a altura do nó, não o fator de balanceamento -> Pq não se pode
    // fazer operações com fator de balanceamento, e sim com altura (por isso que você precisa
    // da altura de cada nó salva)
    // b->altura = max(avl_altura_no(b->esq),a->altura) + 1; // a->altura pode ser avl_altura_no(b->dir)
    // NÃO PRECISA DO CÓDIGO ACIMA
    return b;

}

// Dica: Roda_esquerda de A se B está à direita de A
// Dica2: Você rotaciona a esquerda de A se o fator de balanceamento de A for -2 (caído pra direita)

NO *rodar_esquerda(NO *a){
    if(a == NULL) return NULL;
    NO *b = a->dir;  // É o nosso nó temporário
    // -> Atenção para não fazer b->dir = a primeiro (uma subárvore assim ficará órfão)
    a->dir = b->esq;
    b->esq = a;
    a->altura = max(avl_altura_no(a->esq),avl_altura_no(a->dir)) + 1;
    // b->altura = max(avl_altura_no(b->dir),a->altura) + 1;  NÃO PRECISA

    return b; // B vira o nó com maior altura

}

// Seguindo a dica: rodar duplo é quando A e B tem sinais contrários (fator de balanceamento)
// Se B estiver a esquerda de A e C estiver à direita de B
// Rodar primeiro esquerda de B (C vai subir (vai ser o mais alto), aí vc faz a->esq apontar para C) e à direita de A
// C era o mais baixo e vai ser o mais alto

NO *rodar_esquerda_direita(NO *a) { // B está a esquerda de A e C está a direita de B
    a->esq = rodar_esquerda(a->esq);
    return rodar_direita(a); // Essa função retorna C(antes era o nó folha)
}

NO *rodar_direita_esquerda(NO *a) { // B está a direita de A e C está a esquerda de B
    a->dir = rodar_direita(a->dir);
    return rodar_esquerda(a);
}

// Insere o nó (pré-ordem) e volta consertando a altura e fazendo balanceamentos(se necessário)
NO *avl_inserir_no(NO *raiz, NO *no) {
    // Percurso pós ordem, sendo que toda vez que ele volta, ele conserta a altura de todos
    if (raiz == NULL)
        raiz = no;
    else if (item_get_chave(no->item) < item_get_chave(raiz->item))
        raiz->esq = avl_inserir_no(raiz->esq, no);
    else if (item_get_chave(no->item) > item_get_chave(raiz->item))
        raiz->dir = avl_inserir_no(raiz->dir, no);

    raiz->altura = max(avl_altura_no(raiz->esq), avl_altura_no(raiz->dir)) + 1;

    // Altura esquerda - direita = -2 -> Quer rotacionar com quem está a direita (que é o problema)
    // Se B está à direita de A, rotaciona esquerda de A

    if (avl_altura_no(raiz->esq) - avl_altura_no(raiz->dir) == -2) // Direita tá mais alto
        if (avl_altura_no(raiz->dir->esq) - avl_altura_no(raiz->dir->dir) <= 0) // Não existe o caso que isso dá 0
            raiz = rodar_esquerda(raiz);
        else
            raiz = rodar_direita_esquerda(raiz);
    if (avl_altura_no(raiz->esq) - avl_altura_no(raiz->dir) == 2)
        if (avl_altura_no(raiz->esq->esq) - avl_altura_no(raiz->esq->dir) > 0)
            raiz = rodar_direita(raiz);
        else
            raiz = rodar_esquerda_direita(raiz);
    return raiz;

    // Rotações não alteram a altura de uma subarvore rotacionada nem seu percurso em-ordem!!!

}


/*
Rudinei inserir_no no final:

if (avl_altura_no(raiz->esq) - avl_altura_no(raiz->dir) == -2)
        if (item_get_chave(no->item) > item_get_chave(raiz->dir->item))
            raiz = rodar_esquerda(raiz);
        else
            raiz = rodar_direita_esquerda(raiz);
    if (avl_altura_no(raiz->esq) - avl_altura_no(raiz->dir) == 2)
        if (item_get_chave(no->item) < item_get_chave(raiz->esq->item))
            raiz = rodar_direita(raiz);
        else
            raiz = rodar_esquerda_direita(raiz);
    return raiz;


*/



bool avl_inserir(AVL *arvore, ITEM *item) {
    NO *novo;
    if (arvore == NULL) return (false);
        novo = avl_cria_no(item);
    if (novo != NULL){
        arvore->raiz = avl_inserir_no(arvore->raiz, novo);
        return (true);
    }
    return (false);
}

bool avl_remover(AVL *T, int chave){
    return ((T->raiz = avl_remover_aux(&T->raiz, chave)) != NULL);
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

    raiz->item = troca->item;
    free(troca); troca = NULL;
}

NO *avl_remover_aux(NO **raiz, int chave){ // Preciso de ponteiro duplo pra raiz pelo msm motivo que ABB (motivo: *raiz = (*raiz)->dir)
    NO *p;
    if(*raiz == NULL) return (NULL);

    else if (chave == item_get_chave((*raiz)->item)){
        if((*raiz)->esq == NULL || (*raiz)->dir == NULL){

            p = *raiz;

            if((*raiz)->esq == NULL)
                *raiz = (*raiz)->dir;

            else
                *raiz = (*raiz)->esq;

            free(p);
            p = NULL;
        }
        else
        troca_max_esq((*raiz)->esq, (*raiz), (*raiz));
    }

    else if (chave < item_get_chave((*raiz)->item))
    (*raiz)->esq = avl_remover_aux(&(*raiz)->esq, chave);
    else if (chave > item_get_chave((*raiz)->item))
    (*raiz)->dir = avl_remover_aux(&(*raiz)->dir, chave);

    // Tudo aqui em cima é remoção em ABB. Tudo abaixo daqui é consertando altura e rotacionando
    // (para os nós não nulos)

    if (*raiz != NULL) { // Consertando balanceamento na volta
        (*raiz)->altura = max(avl_altura_no((*raiz)->esq), avl_altura_no((*raiz)->dir))+1;
        if (avl_altura_no ((*raiz)->esq) - avl_altura_no((*raiz)->dir) == -2) {
            if (avl_altura_no((*raiz)->dir->esq) - avl_altura_no((*raiz)->dir->dir) <= 0) // Tem como essa altura ser zero - preferimos quando é zero fazer rotação simples
                *raiz = rodar_esquerda (*raiz);
            } else {
                *raiz = rodar_direita_esquerda (*raiz);
            }

            if (avl_altura_no ((*raiz)->esq) - avl_altura_no((*raiz)->dir) == 2) {
                if (avl_altura_no ( (*raiz)->esq->esq) - avl_altura_no((*raiz)->esq->dir) >= 0){
                    *raiz = rodar_direita(*raiz);
                }
                else{
                    *raiz = rodar_esquerda_direita(*raiz);
                }
            }
    }
    return *raiz;
}

NO* avl_busca_aux(AVL*t, NO* raiz, int chave){
    if(raiz == NULL) return NULL;

    if(item_get_chave(raiz->item) > chave)
        return avl_busca_aux(t,raiz->esq, chave);

    else if(item_get_chave(raiz->item) < chave)
        return avl_busca_aux(t,raiz->dir, chave);

    else return raiz;
}

ITEM* avl_busca(AVL* arvore, int chave){
    if(arvore == NULL || arvore->raiz == NULL) return NULL;
    return avl_busca_aux(arvore, arvore->raiz, chave)->item;
}

void avl_imprimir(AVL * arvore){  // Impressão por níveis -- PRECISA DO TAD FILA

    if (arvore == NULL || arvore->raiz == NULL) return;

    // int cont = 1;
    int nivel = 2;

    FILA *fila = fila_criar();
    fila_inserir(fila, arvore->raiz);


    while(!fila_vazia(fila)){
        int numero_no_nivel = fila_tamanho(fila);

        for (int i = 0; i < numero_no_nivel; i++){
            NO *atual = fila_remover(fila);

            printf("%d ", item_get_chave(atual->item));

            if (atual->esq != NULL)
                fila_inserir(fila, atual->esq);

            if (atual->dir != NULL)
                fila_inserir(fila, atual->dir);
        }

        printf("\n");

        //printf("%d ", item_get_chave(atual->item));

       /* cont++;
        if(cont == nivel){
            printf("\n");
            nivel *= 2;
        }*/

    }

    fila_apagar(&fila);

}

void avl_em_ordem(AVL* tree, NO* raiz){ // impressão crescente
    if(raiz == NULL){
        return;
    }
    avl_em_ordem(tree, raiz->esq);
    printf("%d (altura: %d\n)", item_get_chave(raiz->item), raiz->altura);
    avl_em_ordem(tree, raiz->dir);

}

// O CIRCUITO PÓS ORDEM NÃO RESULTA NA IMPRESSÃO DECRESCENTE DOS ELEMENTOS

void avl_imprimir_crescente(AVL* arvore){
    if(arvore == NULL || arvore->raiz == NULL) return;
    avl_em_ordem(arvore, arvore->raiz);

}