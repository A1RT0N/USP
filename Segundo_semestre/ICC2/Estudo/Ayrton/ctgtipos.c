#include <stdio.h>


void contagem_de_tipos(int v[], int n){ // serve para numeros positivos >= 0

    int B[n], max; 
    //determinando maximo
    max = v[0];
    
    for(int i =1; i< n; i++){
        if(v[i]>max){
            max = v[i];
        }

    }

    int x[max+1];

    for (int i = 0; i < max+1; i++)
    {
        x[i] = 0;
    }
    

    for(int i =0; i< n; i++){
        x[v[i]]++;
    }

    for(int i = 0, k=0; i< max+1; i++){
        while(x[i] != 0){
            B[k] = i;
            k++;
            x[i]--;
        }
    }


    for(int i =0; i< n; i++){
        v[i] = B[i];
    }

}



int main(){
    int v[9] = {3,7,1,8,2,77,5,0,2};
    contagem_de_tipos(v,9);

    for (int i = 0; i < 9; i++)
    {
        printf("%d ", v[i]);
    }
    

    return 0;
}