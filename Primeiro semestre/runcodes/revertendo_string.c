#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define inicial 20

void inverter(char** texto, int* contador, int* alocacao);
void realoca(char **p, int n);

char *lerEntrada(void){
    char *string = NULL;
    int alocado = 0, lido = 0;

    int c;
    while((c = getchar()) != EOF){
        if(alocado == lido)
            string = realloc(string, (alocado+=20));

        string[lido] = c;
        lido++;
    }
    string[lido] = 0;

    return string;
}

// void inverter(char** texto, int* contador, int* alocacao){
//     if (((*contador) +1) == ((*alocacao)*inicial)){
//         realoca(texto, (*alocacao)*inicial);
//         (*alocacao)++;
//     }
//     char c;
    
//     while((c = getchar()) != EOF){
//         (*texto)[*contador] = c;
//         (*contador)++;
//     }
        
// }

void realoca(char **p, int n){
    *p = (char *) realloc(*p, n * sizeof(char));
}

void imprime (char *p){
    for (int i = strlen(p)-1; i >= 0; i--){
        printf("%c", p[i]);
    }
}


int main(){
    char *texto = lerEntrada();
    imprime(texto);

    free(texto);
    texto = NULL;

    return 0;
}