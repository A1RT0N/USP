#include <stdio.h>

void merge(int *v, int inicio, int meio, int fim){
    int tmp = inicio;

    int n1 = meio-inicio+1;
    int n2 = fim-meio;

    int v1[n1];
    int v2[n2];

    for(int i = 0; i< n1; i++){
        v1[i] = v[tmp];
        tmp++;
    }
    for(int i = 0; i< n2; i++){
        v2[i] = v[tmp];
        tmp++;
    }

    tmp = inicio;

    int i = 0;
    int j = 0;

    while (i < n1 && j < n2)
    {
        if(v1[i] < v2[j]){
            v[tmp] = v1[i];
            i++;
        } else{
            v[tmp] = v2[j];
            j++;
        }

        tmp++;
    }
    

    while(j < n2){
        v[tmp] = v2[j];
        j++;
        tmp++;
    }
    

    while(i < n1){
        v[tmp] = v1[i];
        i++;
        tmp++;
    }

    

}



void mergesort(int *v, int inicio, int fim){
    if(inicio >= fim) return;

    int meio = (inicio + fim)/2;

    mergesort(v,inicio,meio);
    mergesort(v, meio + 1, fim);

    merge(v, inicio, meio, fim);

}


int main(){
    int v[8] = {3,7,1,9,8,0,2,10};

    mergesort(v,0,7);
    for(int i = 0; i< 8; i++){
        printf("%d ", v[i]);
    }
}