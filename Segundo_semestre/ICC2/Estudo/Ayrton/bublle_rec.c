#include <stdio.h>


void recursao2(int *v, int n, int i, int contador){
    if(i < n - contador -1){
        if (v[i] > v[i + 1]) {
            int temp = v[i];
            v[i] = v[i + 1];
            v[i + 1] = temp;
                    
        }

        recursao2(v, n, i+1, contador);
    }
}


void recursao(int *v, int n, int contador){
    if(contador < n-1){
        // for (int i = 0; i < n - contador - 1; ++i) {
        //         if (v[i] > v[i + 1]) {
        //             int temp = v[i];
        //             v[i] = v[i + 1];
        //             v[i + 1] = temp;
                    
        //         }
        // }
        recursao2(v,n,0,contador);

        recursao(v,n,contador+1);
    }
}


void bublesort(int *v, int n){

    recursao(v,n,0);

    for(int i =0; i<n; i++){
        printf("%d ", v[i]);
    }
}


int main(){
    int v[] = {2,6,1,8,9};
    bublesort(v,5);
    return 0;
}