#include "avl.h"
#include <stdio.h>
#include <stdlib.h>
#define max(a, b) ((a > b) ? a : b) // Função que calcula máximo de dois elementos para calcular altura de um nó

// Algoritmo da AVL

struct no_{
    int item;
    NO *esq;
    NO *dir;
    int altura;
};

// Cada nó terá um elemento à sua esquerda, direita. Terá um item e a sua altura
// Cada nó terá sua altura para facilitar o cálculo do fator de balanceamento



struct avl_
{
    NO* raiz; // Raiz da árvore AVL
};


// Protótipos de funções auxiliares

void avl_apagar_aux(NO *raiz);
NO* avl_cria_no(int item);
NO *rodar_direita(NO *a);
NO *rodar_esquerda(NO *a);
NO *rodar_esquerda_direita(NO *a);
NO *rodar_direita_esquerda(NO *a);
NO *avl_inserir_no(NO *raiz, NO *no, int* flag_inseriu);
NO *avl_remover_aux(NO **raiz, int chave, int * flag);
void troca_max_esq(NO *troca, NO *raiz, NO *ant);
NO* avl_busca_aux(AVL*t, NO* raiz, int chave);
void avl_em_ordem(AVL* tree, NO* raiz);
void avl_pos_ordem(AVL* tree, NO* raiz);




AVL *avl_criar(void){ // Função que cria uma árvore
    AVL* arvore = (AVL*) malloc(sizeof(AVL));

    if(arvore == NULL) return NULL; // Caso acontece algum problema durante o malloc()
    
    arvore->raiz = NULL; // Inicialmente a raiz é nula

    return arvore;
}

int avl_altura_no(NO* raiz) { // Função que retorna a altura do nó  
    if (raiz == NULL) { // Se o nó não existir, retorna -1 (convenção)
        return -1;
    } else {
        return raiz->altura;
    }
}

void avl_apagar_aux(NO *raiz) { // Função auxiliar recursiva pós-ordem que apaga a árvore
    if (raiz != NULL) {
        avl_apagar_aux(raiz->esq);
        avl_apagar_aux(raiz->dir);
        free(raiz);
    }
}


void avl_apagar(AVL **arvore) { // Função principal de apagar árvore qie chama função auxiliar
    if ((*arvore) == NULL) return;
    avl_apagar_aux((*arvore)->raiz); // Apaga cada elemento da árvore, incluindo a raiz
    free(*arvore); // Desaloca a árvore que foi alocada em avl_criar();  
    *arvore = NULL;
}


NO* avl_cria_no(int item){ // Função que cria um novo nó e recebem o item dele como parâmetro

    NO* nozinho = (NO*) malloc(sizeof(NO));
    if(nozinho == NULL) return NULL; // Caso o nó seja alocado incorretamente
    nozinho->item = item; 
    nozinho->dir = NULL;
    nozinho->esq = NULL;
    nozinho->altura = 0; // Altura de um novo nó inicia-se como 0 (todo novo nó criado e inserido numa árvore é sempre nó folha)

    return nozinho;
}



NO *rodar_direita(NO *a){ // Função de rotacionar para direita, caso o fator de balanceamento seja positivo (caído para esquerda)
    if(a == NULL) return NULL;
    NO *b = a->esq;  // Nó temporário para guardar o nó esquerda de a
    a->esq = b->dir; // Para sub-árvore esquerda de a receber a sub-árvore direita de b para b->dir não ficar órfão
    b->dir = a;
    a->altura = max(avl_altura_no(a->esq),avl_altura_no(a->dir)) + 1; // Atualiza altura de a
    b->altura = max(avl_altura_no(b->esq),avl_altura_no(b->dir)) + 1; // Atualiza altura de b

    return b;

}


NO *rodar_esquerda(NO *a){  // Função de rotacionar para esquerda, caso o fator de balanceamento seja negativo (caído para direita)
    if(a == NULL) return NULL;
    NO *b = a->dir;  // Nó temporário para guardar o nó direita de a
    a->dir = b->esq; // Para sub-árvore direita de a receber a sub-árvore esquerda de b para b->esq não ficar órfão
    b->esq = a;
    a->altura = max(avl_altura_no(a->esq),avl_altura_no(a->dir)) + 1; // Atualiza altura de a
    b->altura = max(avl_altura_no(b->esq),avl_altura_no(b->dir)) + 1; // Atualiza altura de b

    return b;

}



NO *rodar_esquerda_direita(NO *a) { // Função que é chamada quando os sinais de balanceamento são diferentes e o sinal de a é 2
    a->esq = rodar_esquerda(a->esq); // A->esq recebe a raiz da primeira rotação
    return rodar_direita(a); 
}

NO *rodar_direita_esquerda(NO *a) { // Função que é chamada quando os sinais de balanceamento são diferentes e o sinal de a é -22
    a->dir = rodar_direita(a->dir); // A->dir recebe a raiz da primeira rotação
    return rodar_esquerda(a);
}

NO *avl_inserir_no(NO *raiz, NO *no, int* flag_inseriu) { // Função recursiva que insere nó (no) na árvore de raiz (raiz). Recebe como parâmetro raiz, no e flag_inserir, que mostra se o item foi inserido (modificada para 1) ou se já existia o elemento a ser inserido na árvore (modificada para 0) 
    // Algoritmo de achar o nó nulo para inserir em uma ABB
    if (raiz == NULL)
        raiz = no; // Insere o nó
    else if ((no->item) < (raiz->item))
        raiz->esq = avl_inserir_no(raiz->esq, no, flag_inseriu); // Caminha para esquerda e atribui o resultado a raiz->esq
    else if ((no->item) > (raiz->item))
        raiz->dir = avl_inserir_no(raiz->dir, no, flag_inseriu); // Caminha para direita e atribui o resultado a raiz->dir
    
    else if((no->item) == (raiz->item)){ // Caso o elemento inserido já exista
        *flag_inseriu = 1;
        return raiz; // Retorna raiz, já que não é necessário fazer rotações ou alterar as alturas
    }


    raiz->altura = max(avl_altura_no(raiz->esq), avl_altura_no(raiz->dir)) + 1; // Atualiza a altura de cada nó na volta
    

    if (avl_altura_no(raiz->esq) - avl_altura_no(raiz->dir) == -2) // Quando o fator de balanceamento é -2, o nó está desbalanceado para direita
        if (avl_altura_no(raiz->dir->esq) - avl_altura_no(raiz->dir->dir) <= 0) // Se o sinal de balanceamento do nó direito for igual ao do pai, fará uma rotação simples para direita
            raiz = rodar_esquerda(raiz);
        else
            raiz = rodar_direita_esquerda(raiz); // Se o sinal de balanceamento do nó direito for diferente do do pai, fará uma rotação dupla
    if (avl_altura_no(raiz->esq) - avl_altura_no(raiz->dir) == 2) // Quando o fator de balanceamento é 2, o nó está desbalanceado para esquerda
        if (avl_altura_no(raiz->esq->esq) - avl_altura_no(raiz->esq->dir) >= 0) // Se o sinal de balanceamento do nó esquerdo for igual ao do pai, fará uma rotação simples para esquerda
            raiz = rodar_direita(raiz);
        else
            raiz = rodar_esquerda_direita(raiz);  // Se o sinal de balanceamento do nó esquerdo for diferente do do pai, fará uma rotação dupla
    return raiz;

}




bool avl_inserir(AVL *arvore, int item) { // Função principal que cria insere nó na AVL
    NO *novo;
    if (arvore == NULL) return (false);
        novo = avl_cria_no(item); // Cria o novo nó se a árvore não for nula (pode ou não ser vazia)
    if (novo != NULL){
        int inseriu = 0; // Flag que mostra se foi possível inserir o nó (se ele já existem retorna falso, senão, retorna verdadeiro)
        arvore->raiz = avl_inserir_no(arvore->raiz, novo, &inseriu);
        if(inseriu == 1){
            free(novo);
            return false;
        }
        return (true);
    }
    free(novo);
    return (false);
}

bool avl_remover(AVL *T, int chave){ // Função principal que remove elemento da árvore que é passado como parâmetro
    if(T == NULL) return false;

    int flag_inseriu_remocao = 0; // Flag que mostra se o nó foi removido (retorna verdadeiro) ou se ele já não existia (retorna falso)
    
    T->raiz = avl_remover_aux(&(T->raiz), chave, &flag_inseriu_remocao); // Raiz da árvore vai receber a nova raiz ao remover o elemento caso aconteça ou não rotações após a remoção

    if(flag_inseriu_remocao == 1) return false;
    if(T->raiz == NULL) return false;

    return true;
}

void troca_max_esq(NO *troca, NO *raiz, NO *ant){ // Função recursiva que, quando o nó tem dois filhos, troca o nó máximo (mais a direita) da sub-árvore esquerda daquele nó
    if(troca->dir != NULL){
        troca_max_esq(troca->dir, raiz, troca); // Caminha para direita, se possível
        return;
    }

    if(raiz == ant) // Caso não foi possível caminhar para direita (sub-árvore esquerda do nó não tem sub-árvore direita)
        ant->esq = troca->esq;
    else // Caso foi possível caminhar para direita 
        ant->dir = troca->esq;

    raiz->item = troca->item; // Troca os itens do elemento desejado e do elemento a ser trocado
    free(troca); troca = NULL; // Remove o elemento máximo direito que foi trocado
}

NO *avl_remover_aux(NO **raiz, int chave, int * flag){ // Função  recursiva que remove a raiz de elemento chave usando derreferenciamento (ponteiro duplo) que recebe como parâmetro também uma flag que mostra se o elemento a ser removido existe ou não
    NO* p; // Cria nó temporário local que será de apoio para remoção
    if(*raiz == NULL) { // Se não encontrar o elemento (altera flag)
        *flag = 1;
        return (NULL);
    }

    // Algoritmo de remoção de uma ABB

    else if (chave == ((*raiz)->item)){ // Se encontrar a raiz (não faz nada com a flag)
        if((*raiz)->esq == NULL || (*raiz)->dir == NULL){ // Caso que nó não tem filho ou tem 1 só folho

            p = *raiz;

            if((*raiz)->esq == NULL)  // Caso o nó esquerdo seja nulo
                *raiz = (*raiz)->dir;

            else
                *raiz = (*raiz)->esq;

            free(p);
            p = NULL;
        }
        else
        troca_max_esq((*raiz)->esq, (*raiz), (*raiz)); // Caso em que o nó a ser removido tem 2 filhos
    }

    else if (chave < ((*raiz)->item))
    (*raiz)->esq = avl_remover_aux(&(*raiz)->esq, chave, flag); // Caminha para esquerda e atribui o retorno ao nó esquerda de raiz caso haja rotação
    else if (chave > ((*raiz)->item))
    (*raiz)->dir = avl_remover_aux(&(*raiz)->dir, chave, flag); // Caminha para direita

    // Algoritmo de rotação (volta da recursão)

    if (*raiz != NULL) { 
        (*raiz)->altura = max(avl_altura_no((*raiz)->esq), avl_altura_no((*raiz)->dir))+1; // Consertando altura
        if (avl_altura_no ((*raiz)->esq) - avl_altura_no((*raiz)->dir) == -2) { // Se o nó mais novo tiver fator de balanceamento -2 (desbalanceado para direita)
            if (avl_altura_no((*raiz)->dir->esq) - avl_altura_no((*raiz)->dir->dir) <= 0){ // Se o nó direito tiver mesmo sinal do pai, faz rotação simples, senão dupla
                *raiz = rodar_esquerda (*raiz);
            } else {
                *raiz = rodar_direita_esquerda (*raiz);
            }

            if (avl_altura_no ((*raiz)->esq) - avl_altura_no((*raiz)->dir) == 2) { // Se o nó mais novo tiver fator de balanceamento 2 (desbalanceado para esquerda)
                if (avl_altura_no ( (*raiz)->esq->esq) - avl_altura_no((*raiz)->esq->dir) >= 0){ // Se o nó direito tiver mesmo sinal do pai, faz rotação simples, senão dupla
                    *raiz = rodar_direita(*raiz);
                }
                else{
                    *raiz = rodar_esquerda_direita(*raiz);
                }
            }
        }
    }
    return *raiz;
}

NO* avl_busca_aux(AVL*t, NO* raiz, int chave){ // Função auxiliar de busca em uma ABB
    if(raiz == NULL) return NULL; // Retorna nulo se não achar o nó

    if((raiz->item) > chave) // Caminha para direita
        return avl_busca_aux(t,raiz->esq, chave);

    else if((raiz->item) < chave) // Caminha para esquerda
        return avl_busca_aux(t,raiz->dir, chave);

    else return raiz;
}


bool avl_busca(AVL* arvore, int chave){ // Função principal que busca uma chave na árvore caso ela exista ou não for vazia e que retorna se achou ou não a chave na árvore
    if(arvore == NULL || arvore->raiz == NULL) return false;
    return (avl_busca_aux(arvore, arvore->raiz, chave) != NULL);
}



void avl_em_ordem(AVL* tree, NO* raiz){  // Função que imprime a árvore crescente utilizando o algoritmo recursivo em-ordem
    if(raiz == NULL){ // Caso chegue em um nó nulo, volta na recursão
        return;
    }
    avl_em_ordem(tree, raiz->esq);
    printf("%d ",(raiz->item));
    avl_em_ordem(tree, raiz->dir);

}


void avl_imprimir(AVL* arvore){ // Função que imprime a árvore se ela existir ou não for vazia
    if(arvore == NULL || arvore->raiz == NULL) return;
    avl_em_ordem(arvore, arvore->raiz);

}




NO* avl_raiz_esquerda(NO* raiz){ // Função que retorna a raiz esquerda do nó (serão utilizadas no TAD set.c)
    return(raiz->esq);
}
NO* avl_raiz_direita(NO* raiz){ // Função que retorna a raiz direita do nó
    return(raiz->dir);
}
NO* avl_raiz(AVL* arvore){ // Função que retorna a raiz da árvore
    return(arvore->raiz);
}
int avl_raiz_item(NO* raiz){ // Função que retorna o elemento do nó
    return(raiz->item);
}