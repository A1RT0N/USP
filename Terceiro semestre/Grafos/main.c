#include "graph.h"

int menu() {
  printf("\n");
  printf("Digite uma opcao:\n");
  printf("0 - Remover o grafo e sair do programa\n");
  printf("1 - Verificar se uma aresta existe\n");
  printf("2 - Vertices adjacentes a determinado vertice\n");
  printf("3 - Remover uma aresta do grafo\n");
  printf("4 - Imprimir vertices e arestas\n");
  printf("5 - Número de vertices no grafo\n");
  printf("6 - Inserir arestas\n");
  printf("7 - Remover aresta de menor peso\n");
  printf("8 - Matriz de adjacencia \n");
}

int main() {
  GRAFO *grafo;
  int N, opcao;

  printf("Numero de vertices do grafo: ");
  scanf("%d", &N);

  grafo = MyGraph(N);

  do {
    //menu();
    scanf("%d", &opcao);

    switch (opcao) {
      case 1:{
        int arestaExiste, v1, v2;
        printf("Digite as coordenadas da aresta (v1 v2): ");
        scanf("%d %d", &v1, &v2);
        arestaExiste = exist_edge(grafo, v1, v2);

        if(arestaExiste) {
          printf("A aresta existe\n");
        } else {
          printf("A aresta nao existe\n");
        }
        break;
      }
      case 2:{
        int vertice, *lista, tam_lista;
        printf("Digite o numero de um vertice: ");
        scanf("%d", &vertice);

        lista = get_adj_vertex(grafo, vertice, &tam_lista);

        printf("Número de vértices: %d\n", tam_lista);
        
        if (tam_lista == 0){
          printf("Sem vértices adjacentes\n");
        } else {
          for(int i=0; i<tam_lista; i++) {
            printf("%d ", lista[i]);
          }
          printf("\n");
        }

        free(lista);
        break;
      }
      case 3:{
        int v1, v2;
        printf("Digite as coordenadas da aresta a ser removida (v1 v2): ");
        scanf("%d %d", &v1, &v2);
        remove_edge(grafo, v1, v2);
        break;
      }
      case 4:
        print_info(grafo);
        break;

      case 5:
        printf("O número de vértices do grafo é: %d \n", number_of_vertexs(grafo));

      case 6:{
        int v1, v2, peso;
        printf("Digite as coordenadas da aresta a ser inserida (v1 v2) e o peso: ");
        scanf("%d %d %d", &v1, &v2, &peso  );
        add_edge(grafo, v1, v2, peso);
        break;
      }

      case 7:{
        remove_less_weight(grafo);
        break;
      }

      case 8:{
        adjacency_matrix(grafo);
        break;
      }

      default:
        remove_graph(grafo);
    }
  } while(opcao != 0);

  scanf("%d", &N);
  grafo = MyGraph(N);

  

  return 0;
}