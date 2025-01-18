#include <stdio.h>

int fibonnaci(int n);
int soma(int k);

int soma(int k){
    if (k == 1 || k == 2 || k == 0){
        return 1;
    }else{
        return (k+soma(fibonnaci(k-1)));
    }
}

int fibonnaci(int n){
    if (n == 1 || n==2){
        return 1;
    }else{
        return(fibonnaci(n-1)+fibonnaci(n-2));
    }

}

int main(){
    int a;
    printf("Enter the number of terms: ");
    scanf("%d", &a);
    printf("The %dth term of the fibbonacci series is %d", a, fibonnaci(a));
    printf("\nThe sum of the first %d terms of the fibbonacci series is %d", a, soma(fibonnaci(a)));
    return 0;
}