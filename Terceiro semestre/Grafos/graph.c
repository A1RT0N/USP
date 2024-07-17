#include "graph.h"


// PARA ESSE TRABALHO ESTAMOS SUPONDO QUE O GRAFO PODE SER ORIENTADO E VALORADO COM INTUITO DE ABRANGER TODOS
// OS POSSÍVEIS GRAFOS
// Caso as linhas da matriz de adjacência seja igual às suas respectivas colunas, o grafo seria não orientado

// Um elemento da linha i está ligado a coluna j


struct grafo_{
    int** matriz_adjacencia;
    int tamanho;
};

GRAFO * MyGraph(int N){
    GRAFO * grafo = (GRAFO *) malloc(sizeof(GRAFO)); //aloca a memória

    if (grafo == NULL){ //verifica se a memória foi devidamente alocada
        free(grafo);
        return NULL;
    }

    /*
    grafo->tamanho = (int) malloc(sizeof(int));

    if(grafo->tamanho == NULL){
        free(grafo);
        free(grafo->tamanho);
        return NULL;
    }*/

    grafo->tamanho = N;

    grafo->matriz_adjacencia = (int **)malloc(sizeof(int*)); //aloca memória para as colunas da matriz

    for(int i = 0; i < grafo->tamanho; i++){
        grafo->matriz_adjacencia[i] = (int*) malloc(sizeof(int)); //aloca memória para as linhas da matriz
    }


    if(grafo->matriz_adjacencia == NULL){ //verifica se a memória foi devidamente alocada
        free(grafo);
        //free(grafo->tamanho);
        free(grafo->matriz_adjacencia);
        return NULL;
    }
    
    for(int i =0; i< N; i++){
        for (int j = 0; j < N; j++){
            (grafo->matriz_adjacencia)[i][j] = -1;
        }
        
    }

    return grafo;
}
    
int exist_edge(GRAFO* grafo, int v1, int v2){

    if(grafo == NULL){ //verifica a existencia do grafo
        printf("Erro: grafo inexistente");
        return ERRO;
    }

    if((v1 < grafo->tamanho) && (v2 < grafo->tamanho)){ //verifica se os vértices existem
        if(grafo->matriz_adjacencia[v1][v2] != -1){ //-1 é o valor que implica não ter aresta
            return 1;
        }

        return 0;
    }

    return 0;
    

}
int * get_adj_vertex(GRAFO* grafo, int vertice, int *tam_lista){
    int contador = 0;

    for(int i=0; i<grafo->tamanho; i++) {
        if(grafo->matriz_adjacencia[vertice][i] != -1) {
            contador++;
        }
    }

    int *lista = (int *) malloc(sizeof(int) * contador);
    contador = 0;

    for(int i=0; i<grafo->tamanho; i++) {
        if(grafo->matriz_adjacencia[vertice][i] != -1) {
            lista[contador] = i;
            contador++;
        }
    }

    *tam_lista = contador;

    return lista;


    // if(grafo == NULL){
    //     printf("Erro: grafo inexistente");
    //     return NULL;
    // }

    // int n = 0;

    // for (int i = 0; i < grafo->tamanho; i++){
    //     if (grafo->matriz_adjacencia[vertice][i] != -1) {
    //         printf("vertice: %d, i: %d, valor: %d\n", vertice, i, grafo->matriz_adjacencia[vertice][i]);
    //         n ++;
    //     }
    // }

    // if (n == 0) return NULL;

    // int *lista = (int *) malloc(sizeof(int) * n);
    // int contador = 0;

    // for (int i = 0; i < grafo->tamanho; i++){
    //     if (grafo->matriz_adjacencia[vertice][i] != -1){
    //         lista[contador] = i;

    //         contador++;
    //     }
    // }    
    // printf("n: %d\n", n);
    // *tam_lista = n;

    // return lista;

}

int remove_edge(GRAFO* grafo, int v1, int v2) {
    grafo->matriz_adjacencia[v1][v2] = -1;

    return 1;
}

void print_info(GRAFO * grafo) {
  printf("Grafos: ");

  for (int i = 0; i < grafo->tamanho; i++){
    printf("%d ", i);
  }

  printf("\nArestas: ");

  for (int i = 0; i < grafo->tamanho; i++){
    for (int j = 0; j < grafo->tamanho; j++){
        if (grafo->matriz_adjacencia[i][j] != -1) printf("(%d, %d) ", i, j);
    }
  }

  printf("\n");
}

int number_of_vertexs(GRAFO * grafo) {
    return grafo->tamanho;
}

int remove_graph(GRAFO* grafo) {
    for(int i = 0; i< grafo->tamanho; i++) {
        free(grafo->matriz_adjacencia[i]);
    }

    free(grafo->matriz_adjacencia);
    free(grafo);

    return 1;
}

int add_edge(GRAFO* grafo, int v1, int v2, int peso) {
    grafo->matriz_adjacencia[v1][v2] = peso;

    return 1;
}

int remove_less_weight(GRAFO* grafo) {
    int menorI = 0, menorJ = 0;

    int menor = 9999999;

    for(int i=0; i < grafo->tamanho; i++) {
        for(int j=0; j < grafo->tamanho; j++) {
            if (grafo->matriz_adjacencia[i][j] == -1) continue;

            if (grafo->matriz_adjacencia[i][j] < menor) {
                menorI = i;
                menorJ = j;

                menor = grafo->matriz_adjacencia[i][j];
            }
        }
    }

    grafo->matriz_adjacencia[menorI][menorJ] = -1;

    return 1;
}

int ** adjacency_matrix(GRAFO* grafo) {
    for (int i = 0; i < grafo->tamanho; i++){
        for (int j = 0; j < grafo->tamanho; j++){
            printf("%d ", grafo->matriz_adjacencia[i][j]);
        }
        printf("\n");
    }

    printf("\n");
    return grafo->matriz_adjacencia;
}
