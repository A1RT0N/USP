#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){

    char str[10000];
    
    fgets(str, 10000, stdin);

    char strin[10000];

    scanf(" %s", strin);
    int n =0, cont, resp = 0;
    while (n<(strlen(str)-strlen(strin))){
        cont = 0;
        for (int j =0; j<strlen(strin); j++){
            if (str[n+j] == strin[j]){
                cont++;
            }
        }
        if (cont == strlen(strin)){
            resp++;
            printf("A sub string foi encontrada na posicao = %d\n", n);
        }

        n++;

    }
    if (resp == 0){
        printf("A sub string nao foi encontrada");
    }

    return 0;

}