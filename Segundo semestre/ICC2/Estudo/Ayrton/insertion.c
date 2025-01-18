#include <stdio.h>

void insertion(int *v, int n){
    int valor_atual;
    int j;
    for(int i = 1; i<n; i++){
        valor_atual = v[i];
        j = i-1;
        while(j>=0 && v[j] > valor_atual){
            v[j+1] = v[j];
            j--;

        }
        v[j+1] = valor_atual;

    }
}


int main(){
    int v[8] = {3,7,1,8,2,77,5,0};
    insertion(v,8);
    for(int i =0; i< 8; i++){
        printf("%d ", v[i]);
    }
}