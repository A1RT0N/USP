#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b){
    int tmp;
    tmp = *b;
    *b=*a;
    *a =tmp;
}

int sort(int v[], int inicio, int fim){
    int pivo = (inicio + fim)/2;
    swap(&v[pivo], &v[fim]);
    
    int i = inicio-1;
    int j = inicio;
    pivo = fim;

    while(v[j] != v[pivo]){
        if(v[j]<v[pivo]){
            i++;
            swap(&v[j], &v[i]);
        }
        j++;
    }

    swap(&v[j], &v[i+1]);

    return pivo;

}

void quicksort(int v[], int inicio, int fim){
    if(inicio < fim){
        int pivo = sort(v,inicio, fim);
        quicksort(v,pivo+1,fim);
        quicksort(v,inicio,pivo-1);
    }
}


int main(){
    int v[8] = {3,7,1,9,8,0,2,10};
    quicksort(v,0,7);
    for(int i = 0; i< 8; i++){
        printf("%d ", v[i]);
    }
}