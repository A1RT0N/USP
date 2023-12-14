#include "set.h"

struct set
{
  AVL* avl;
  int tamanho; // Tamanho do conjunto
};


// Protótipos de funções
void set_uniao_auxiliar(NO* raiz, SET* C);
void set_interseccao_aux(NO* raiz, SET* C, AVL* parametro);

SET *set_criar(void){ // Função que cria conjunto
  SET* conjunto = malloc(sizeof(SET));
  if(conjunto == NULL) return NULL; // Verifica se o conjunto teve malloc() correto
  conjunto->avl = avl_criar(); // chama função para criar avl
  conjunto->tamanho = 0; 
}

bool set_pertence(SET *A, int elemento){ // Verifica se pertence
  if(A== NULL) return false; // Verifica se A existe
  return(avl_busca(A->avl,elemento)); // Avl busca retorna se foi achado ou não
}

bool set_inserir(SET *s, int elemento){
  if(s == NULL) return false; // verifica se existe
  if(avl_inserir(s->avl, elemento)){ // A função avl_inserir retorna se foi possível a inserção ou não, tanto por já existir elemento quanto por outros fatores
    s->tamanho++;
    return true;
  }
  return false;

}

bool set_remover(SET *s, int elemento){ // Função que remove elemento do conjunto
  if(s== NULL) return false;
  if(avl_remover(s->avl, elemento)){ // A função avl_remover retorna se foi possível a remoção ou não, tanto por já existir elemento quanto por outros fatores
    s->tamanho--;
    return true;
  }
  return false;
}

void set_apagar(SET **s){ // FUnção que apaga o conjunto
  if((*s) == NULL) return;
  avl_apagar(&((*s)->avl));
  free(*s);
}

void set_imprimir(SET *s){ // Função que imprime o conjunto
  if(s == NULL) return;
  avl_imprimir(s->avl);
}



void set_uniao_auxiliar(NO* raiz, SET* C){ // Função auxiliar que insere elementos de uma árvore com nó raiz em C recursiva caso o elemento não esteja no conjunto C
  if(raiz == NULL) return;

  set_inserir(C,avl_raiz_item(raiz));

  set_uniao_auxiliar(avl_raiz_esquerda(raiz), C);
  set_uniao_auxiliar(avl_raiz_direita(raiz), C);
  
}

SET *set_uniao(SET *A, SET *B){ // Função principal de união de conjuntos que chama função auxiliar
  SET* C = set_criar(); // Cria o novo conjunto que é a união de A e B

  set_uniao_auxiliar(avl_raiz(A->avl),C); 
  set_uniao_auxiliar(avl_raiz(B->avl), C);

  return C;
  
}

void set_interseccao_aux(NO* raiz, SET* C, AVL* parametro){ // Função auxiliar que remove em C elementos de uma árvore com nó raiz de modo recursivo caso o elemento não esteja no conjunto C nem no conjunto parâmetro
  if(raiz == NULL) return;

  if(avl_busca(parametro, avl_raiz_item(raiz))) // Verifica se o nó já está no parâmetro
    set_inserir(C,avl_raiz_item(raiz));
  
  set_interseccao_aux(avl_raiz_esquerda(raiz), C, parametro);
  set_interseccao_aux(avl_raiz_direita(raiz), C, parametro);
  
}


SET *set_interseccao(SET *A, SET *B){ // Função principal de intersecção que chama função auxiliar
  SET* C = set_criar(); // Cria o novo conjunto que é a intersecção de A e B
  if(A->tamanho >= B->tamanho){ // Faço essa checagem para aumentar eficiência, para percorrer todos elementos do menor e fazer a checagem no maior
    set_interseccao_aux(avl_raiz(B->avl), C, A->avl);
  }else{
    set_interseccao_aux(avl_raiz(A->avl), C, B->avl);
  }

  return C;
}