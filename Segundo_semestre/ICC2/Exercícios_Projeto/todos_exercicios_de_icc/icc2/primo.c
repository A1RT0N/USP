#include <stdio.h>

void primo(int n){
    int divisores = 0;
    int flag = 1;

    for (int i = 2; i < (n / 2); i++){
        if (!(n % i)){
            divisores ++;
        }

        if (divisores != 0){
            flag = 0;
            break;
        }
    }

    if (flag){
        printf("%d e um numero primo\n", n);
    } else printf("%d nao e um numero primo\n", n);
}

int main(void){
    int n1;

    scanf("%d", &n1);

    primo(n1);
}