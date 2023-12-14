#include <stdio.h>

int main(void){
    int n;

    scanf("%d", &n);

    char sequencia[n + 1];

    scanf(" %s", sequencia);

    int contador = 0;

    for (int i = 0; i < n; i++){
        if (sequencia[i] != 65 + i){
            contador ++;
        }
    }

    if (contador > 2){
        printf("There aren’t the chance.\n");
    }else{
        printf("There are the chance.\n");
    }
}