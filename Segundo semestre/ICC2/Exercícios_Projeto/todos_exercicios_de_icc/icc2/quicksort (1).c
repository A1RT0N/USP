#include <stdio.h>
#include <stdlib.h>
/*
Análise de complexidade:

Melhor caso:
O melhor caso é quando o pivo é exatamento o item com o valor médio da lista.
Logo, de N, ele vai divdir em duas listas de tamanho iguais, que somadas darão N - 1.
E se continuarmos sempre escolhendo o melhor pivo, cada lista será dividia em 2 que será divididas em 2 e assim por diante.
O que nos levará para:
        *
    *      *
  *  *    *  *
 * *  * * * * * *
 
 Portanto, estamos, a cada iteração, dividindo por 2.

 Na ultima iteração (x)

 teremos que x = 2^n
 logo, aplicando log

 x = log(n) na base 2

 Mas para cada comparação teremos N operações.

 Portanto, o melhor caso será O(n.log(n)), log na base 2.

Pior caso:
O pior caso é dado quando você sempre escolhe o pior pivo, sendo ele o maior ou o menor item da lista.
Com isso, a lista será subdividade em 0 e n-1. Fazendo isso consecutivamente teremos um somatório de 1 até N, que dará:
N.(n - 1) / 2

Logo, a complexidade será de O(n²)

*/

void swap(int *v, int i, int j){
    int tmp;

    tmp = v[i];

    v[i] = v[j];

    v[j] = tmp;
}

int partition(int *v, int ini, int fim){
    int pivo;

    pivo = (ini + fim) / 2;

    swap(v, pivo, fim);

    pivo = v[fim]; 

    int i = ini - 1;
    
    for (int j = ini; j < fim; j++){
        if (v[j] < pivo){
            i++;

            swap(v, i, j);
        }
    }

    i++;

    swap(v, i, fim);

    return i;
}

void quicksort(int *v, int ini, int fim){
    if (fim <= ini) return; //caso base

    int pivo = partition(v, ini, fim);

    quicksort(v, ini, pivo - 1);
    quicksort(v, pivo + 1, fim);
}