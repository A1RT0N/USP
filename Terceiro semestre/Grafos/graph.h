#ifndef grafo_header
    #define grafo_TAD
    #include <stdio.h>
    #include <stdlib.h>
    #define ERRO -9999999

    typedef struct grafo_ GRAFO;

    

    GRAFO * MyGraph(int N);

    int exist_edge(GRAFO* grafo, int v1, int v2);

    int * get_adj_vertex(GRAFO* grafo, int posicao, int *tam_lista);

    int remove_edge(GRAFO* grafo, int v1, int v2);

    void print_info(GRAFO * grafo);

    int number_of_vertexs(GRAFO * grafo);

    int remove_graph(GRAFO* grafo);

    int add_edge(GRAFO* grafo, int v1, int v2, int peso);

    int remove_less_weight(GRAFO* grafo);

    int ** adjacency_matrix(GRAFO* grafo);


#endif