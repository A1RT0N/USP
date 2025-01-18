#include "abb.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#include "pilha.h"
#include "fila.h"


struct ab_
{
    NO* raiz;
    int profundidade;
};

int max(int a, int b);


/*

EXERCÍCIOS PROVA (implemente para árvores no geral ou especificadas pelo exercício): OK!!!!

01) Escreva algoritmos recursivos e não recursivos para determinar:
a) (OK: rec, iterativo)   O número de nós em uma árvore binária. 

b) (OK: rec, iterativo)    A soma dos conteúdos de todos os nós em uma árvore binária, considerando que cada nó contém
um inteiro. (runcodes)

c) (OK: rec, iterativo)    O maior elemento de uma árvore binária genérica (runcodes)

d) (OK: rec, iterativo)   O menor elemento de uma árvore binária genérica (pode só explicar a diferença pro de cima).

e) (OK:rec )   A profundidade de uma árvore binária.

f) (OK: rec )   A altura de uma árvore binária. -> Mesmo lance para profundidade

g) (OK: rec)    Se uma árvore é perfeitamente balanceada

f) (OK: iterativo)   Se uma árvore está completa e desejo inserir um novo elemento



04) Escreva um algoritmo para determina se uma árvore binária é completa cheia.



05) Duas árvores binárias são similares se elas são vazias ou se elas não são vazias e suas subárvores
da esquerda são similares e suas subárvores da direita são também similares. Escreva um algoritmo
para determinar se duas árvores binárias são similares. -> outro exercicio é mt parecido com esse



RELEMBRANDO:

Árvore completa é quando o nícel d-1 está totalente preenchido e o nível d estão com os nós mais a querda possível
Uma árvore completa cheia é quando ela é estritamente binária e todos os nós folhas estão no último nível
Uma árvore completa cheia, por consequência, é completa (obviamente)


*/


bool arvore_similares(NO* C, NO* D){
    if(C == NULL && D== NULL) return true;

    if((C != NULL && D != NULL) && (arvore_similares(C->esq, D->esq) && arvore_similares(C->dir, D->dir))) return true;

    return false;
    
}

int arvore_inserir_completa(NO** raiz, NO* novo_no){ // Seria bom iterativo para percorrer em níveis
    
    FILA* fila = fila_criar();

    if(*raiz == NULL) *raiz = novo_no;
    
    fila_inserir(fila, *raiz);

    while(!fila_vazia(fila)){
        NO* atual = fila_remover(fila);

        if(atual->esq == NULL){
            atual->esq = novo_no;
            break;
        }

        if(atual->dir == NULL){
            atual->dir = novo_no;
            break;
        }

        fila_inserir(fila, atual->esq);
        fila_inserir(fila, atual->dir);
    }

}



int conta_nos_iterativo(NO *raiz) {
    PILHA *p;
    p = pilha_criar();
    int contador = 0;

    pilha_inserir(p, raiz);

    while (pilha_tamanho(p) != 0) {
        NO *atual = pilha_remover(p);
        contador++; // Se fosse item, seria contador+=item_get_chace(atual->item)
        
        if (atual->esq != NULL) pilha_inserir(p, atual->esq);
        if (atual->dir != NULL) pilha_inserir(p, atual->dir); 
    }

    return contador;

}

int maior_recursivo(NO* raiz){
    if(raiz ==NULL){
        return -111;
    }

    int a = item_get_chave(raiz->item);

    int b = maior_recursivo(raiz->esq);
    int c = maior_recursivo(raiz->dir);

    return max(a,max(b,c));  // Se fosse menor, tinha que fazer uma função maxima
}

int maior_no_iterativo(NO* raiz){
    PILHA* p;
    p = pilha_criar();
    int contador = 0;

    

    pilha_inserir(p, raiz);

    while(pilha_tamanho(p) != 0){
        NO* atual = pilha_remover(p);

        if(contador < item_get_chave(atual->item)){ // para saber o menor é só inverter '<'
            contador = item_get_chave(atual->item); 
        }

        if(atual->esq != NULL) pilha_inserir(p, atual->esq);
        if(atual->dir != NULL) pilha_inserir(p, atual->dir);
    }

    return contador;

}



int conta_nos(NO *raiz) {
    if (raiz == NULL) return 0;
    return (conta_nos(raiz->dir) + conta_nos(raiz->esq) + 1);
}

int soma_conteudos(NO *raiz) {
    if (raiz == NULL) return 0;
    return (soma_conteudos(raiz->dir) + conta_nos(raiz->esq) + item_get_chave(raiz->item));
}



// Para saber a altura de um nó é considerar ele como raiz da árvore
// Para saber a profundidade de um nó, *NÃO FUNCIONA* fazer a altura da árvore que ele é raiz menos a altura da árvore em que ele é raiz


// int ab_preordem_soma(NO *raiz) { // QUESTÃO 1B RECURSIVA  -> Outro modo de fazer
//     int contador = 0;
//     if(raiz == NULL){
//         return 0;
//     }
    
//     contador++;
//     contador += ab_preordem_soma(raiz->esq); 
//     contador += ab_preordem_soma(raiz->dir);
//     return contador;
    
// }

// int soma(AB *T){ // QUESTÃO 1B RECURSIVA
//     return ab_preordem_soma(T->raiz);
// }

int max(int a, int b) {
    return (a > b) ? a : b;
}






// ALGORITMOS DE ÁRVORES BINÁRIAS:






int ab_altura(NO *no) {
    if (no == NULL) return -1;
    int e = ab_altura(no->esq);
    int d = ab_altura(no->dir);
    return (max(e,d) + 1);
}


int ab_profund_iterativo_arvore(NO* no){ // É o nó raiz da árvore -> profundidade e altura de uma árvore

    if(no == NULL) return -1;
    FILA* fila = fila_criar();

    fila_inserir(fila, no);

    int profundidade = 0;

    int numero_atual;

    while(!fila_vazia(fila)){

        numero_atual = fila_tamanho(fila);

        for(int i =0; i< numero_atual; i++){
            NO* atual = fila_remover(fila);

            if(no->esq != NULL)
                fila_inserir(fila,no->esq);
            
            if(no->dir != NULL){
                fila_inserir(fila,no->dir);
            }

        }

        profundidade++;


    }

}


int ab_completa_cheia(NO* raiz){
    if(raiz == NULL){
        return 0;
    }

    (ab_completa_cheia(raiz->dir) + ab_completa_cheia(raiz->esq) + ((conta_nos(raiz->dir) ==  conta_nos(raiz->esq)) ? 0: 1));

}



bool eh_completa(AB* arvore){   // USANDO ESSA IDEIA DESSE CÓDIGO DÁ PARA DESCOBRIR A ALTURA E PROF DE UMA ÁRVORE
    if (arvore == NULL || arvore->raiz == NULL) return false;

    FILA *fila = fila_criar();
    fila_inserir(fila, arvore->raiz);

    int contador = 0;

    int flag = 0;

    int numero_no_nivel;

    while(!fila_vazia(fila)){ 
        numero_no_nivel = fila_tamanho(fila);

        if(pow(2,contador) == numero_no_nivel){
            contador++;
        }else{

            while(!fila_vazia(fila)){
                NO* checar = fila_remover(fila);
                if(checar->esq != NULL || checar->dir != NULL){
                    return false;
                }
            }
            
            return true;
            
        }


        for (int i = 0; i < numero_no_nivel; i++){  
            NO *atual = fila_remover(fila);

            if (atual->esq != NULL){
                fila_inserir(fila, atual->esq);
                if(flag == 1){
                    return false;
                }
                flag = 1;
            }

            if (atual->dir != NULL){
                fila_inserir(fila, atual->dir);
                if(flag == 1){
                    flag = 0;
                }
            }

            if(atual->esq == NULL && atual->dir != NULL)
                return false;
                
        }
        
    }

    fila_apagar(&fila);

    return true;
}


int eh_completa_cheia_aux(NO *raiz){
    if (raiz == NULL) return 0;

    int esq = eh_completa_cheia_aux(raiz->esq);
    int dir = eh_completa_cheia_aux(raiz->dir);

    if (esq != dir) return -1; 
    if (esq == -1) return -1; // Se algum momento deu -1, ele vai propagar
    if (dir == -1) return -1;
    

    return esq + dir + 1;
}


int eh_completa_cheia(NO* raiz_arvore){ 
    int resultado = eh_completa_cheia_aux(raiz_arvore);

    if (resultado == -1) return 0;

    return 1;
}

int profundidade_no(NO *raiz, int chave){
    if (raiz == NULL) return -1;
    if (chave == item_get_chave(raiz->item)) return 0;

    int esq = profundidade_no(raiz->esq, chave);
    int dir = profundidade_no(raiz->dir, chave);

    if (esq >= 0) return esq + 1;
    if (dir >= 0) return dir + 1;

    return -1;
}

// int altura_no(NO *raiz){
//     if (raiz == NULL) return -1;

//     int esq = altura_no(raiz->esq);
//     int dir = altura_no(raiz->dir);

//     if (esq > dir) return esq + 1; // Isso é retornar o máximo entre esquerda e direita

//     return dir + 1;
// }



int eh_balanceada_aux(NO *raiz){
    if (raiz == NULL) return -1;

    int esq = eh_balanceada_aux(raiz->esq);
    if (esq == -2) return -2;

    int dir = eh_balanceada_aux(raiz->dir);
    if (dir == -2) return -2;

    if (abs(esq - dir) > 1) return -2;

    return(max(esq,dir)+1)
}



int recursao_balanceada(NO* raiz){ // QUESTÃO 1G - perfeitamente balanceada

    if(raiz == NULL){
        return 0;
    }

    NO* tmp1;
    NO* tmp2;
    tmp1 = raiz->esq;
    tmp2 = raiz->dir;

    if(abs(ab_preordem(tmp1)-ab_preordem(tmp2)) > 1){ //ab_preordem conta quantos nós tem na árvore
        return -1;
    }

    return (recursao_balanceada(tmp1) + recursao_balanceada(tmp2));
    
}

bool perfeitamente_balanceada(AB* T){ // QUESTÃO 1G RECURSIVA 
    if(T == NULL) return false;
    
    if(recursao_balanceada(T->raiz) == 0){
        return true;
    }else{
        return false;
    }

}


int balanceada(NO* T){
    if (T == NULL) return 0;

    if(abs(ab_altura(T->esq) - ab_altura(T->dir)) > 1){
        return -1;
    }

    return balanceada(T->esq) + balanceada(T->dir);

}

bool estritamente_binaria(NO* raiz){
    if(raiz == NULL) return true;

    if(raiz->esq == NULL && raiz->dir != NULL || raiz->esq == NULL && raiz->dir != NULL) return false;

    return (estritamente_binaria(raiz->esq) && estritamente_binaria(raiz->dir));

}




// Prova caiu fazer função que recebe inteiro K tamanho e um vetor, ver se ele é max heap -- tinha que conferir se o nó sem filho do último nível estava com todos à direita(3)
// Caiu uma questão que determina se a árvore é estritamente binária (1)
// Caiu questão inserir e remover nós numa AVL (questão longa). Na remoção tinha pegadinha: pode trocar o máximo da esquerda ou o mínimo pra direita
// Além disso, quando na AVL dá zero, pode fazer rotação dupla ou simples (deveria mostrar os dois casos) (2)
// Caiu uma questão de Rubro Negra (inserção de nó com balanceamento) (5)
// Caiu questão de análise crítica de ABB, Rubro Negra, AVL e Heap dado um contexto de linha de produção de peças - catálogo. Tinha, ao comparar as árvores AVL e Rubro Negra, falar que a busca da Rubro negra é 2*log(n) e a da avl é 1,44*log(n)(4)