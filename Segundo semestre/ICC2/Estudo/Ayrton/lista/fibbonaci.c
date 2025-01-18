// Fibonnaci para t(0) = 0 e t(1) = 1;
#include <stdio.h>

int fibonacci(int n){
    if(n == 1){
        return 1;
    }else{
        if (n==0){
            return 0;
        }
    }

    return fibonacci(n-1) + fibonacci(n-2);
}


int fibonacci(int n){
    int contador = 0;
    int atual = 0, anterior = 1;
    int tmp;
    if(n == 0){
        return 0;
    }else{
        if(n == 1){
            return 1;
        }else{
            while(n>1){
                contador = atual + anterior;
                tmp = atual;
                atual = anterior;
                anterior = atual;
                n--;
            }
            return contador;
        }
    }

}



int main(){
    int n;
    scanf("%d", &n);
    printf("%d", fibonacci(n));
}