#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct 
{
    char pais[5];
    int ouro;
    int prata;
    int bronze;
}Pais;

void ordena(Pais *p, int n);
void swap(Pais *pais1, Pais *pais2);


void swap(Pais *pais1, Pais *pais2){
    Pais temp = *pais1;
    *pais1 = *pais2;
    *pais2 = temp;
}


void ordena(Pais *p, int n){
    for (int j = 0; j<n; j++){
        for (int k = 0; k<n-1; k++){
            if (p[k].ouro < p[k+1].ouro || (p[k].ouro == p[k+1].ouro && p[k].prata < p[k+1].prata) || (p[k].ouro == p[k+1].ouro && p[k].prata == p[k+1].prata && p[k].bronze < p[k+1].bronze)){
                swap(&p[k+1], &p[k]);
                
            }
        }
    }
    for(int i=0;i<n;i++){
        printf("%s %d %d %d\n", p[i].pais, p[i].ouro, p[i].prata, p[i].bronze);
    }
}


int main(){
    int n;
    scanf("%d", &n);
    Pais *lista = (Pais *)malloc(sizeof(Pais)*n);
    for(int i=0;i<n;i++){
        scanf("%s", lista[i].pais);
        scanf("%d", &lista[i].ouro);
        scanf("%d", &lista[i].prata);
        scanf("%d", &lista[i].bronze);
    }
    ordena(lista, n);
    free(lista);
    return 0;
}