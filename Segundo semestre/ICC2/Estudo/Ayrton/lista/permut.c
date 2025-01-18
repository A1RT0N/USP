#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define A 65

int contido(int *fixos, int n_fixos, int caractere){
    for (int i = 0; i < n_fixos; i++){
        if (caractere == fixos[i]) return 1;
    }
    return 0;
}

void recursivo(int *fixos, int n_fixos, int n){
    if (n_fixos == n){
        for (int i = 0; i < n; i++){
            printf("%c", fixos[i]);
        }
        printf("\n");
        // return;
    }

    for (int i = 0; i < n; i++){
        int caractere_novo = A + i;
        if (contido(fixos, n_fixos, caractere_novo)) continue;
        
        fixos[n_fixos] = caractere_novo;
        recursivo(fixos, n_fixos + 1, n);
    }
}
//(B,C,D), (C,D), (D)
// ABDC

void alfabeto(int n){
    for (int i = 0; i < n; i++){
        int fixos[n];
        
        fixos[0] = A + i;
        recursivo(fixos, 1, n);
    }
}

int main(){
    alfabeto(4);
}


