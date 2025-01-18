#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *lerEntrada(void){
    char *string = NULL;
    int alocado = 0, lido = 0;

    int c;
    while((c = getchar()) != '#'){
        if(alocado - lido < 2)
            string = realloc(string, (alocado+=20));

        string[lido] = c;
        lido++;
    }
    string[lido] = 0;
    scanf(" ");

    return string;
}


void freeMatriz(char** nomes, int linhas){
    for(int i=0; i<linhas; i++){
        free(nomes[i]);
    }
    free(nomes);
}


int main(){

    char **nomes;
    int quantidade;
    scanf("%d ", &quantidade);
    nomes = (char **)malloc(quantidade*sizeof(char *));

    for(int i = 0; i < quantidade; i++){
        nomes[i] = lerEntrada();
    }

    int qtd2;
    scanf("%d ", &qtd2);

    for(int i =0; i < qtd2; i++){
        char *nome = lerEntrada();

        int j;
        for(j = 0; j < quantidade; j++){
            if(strcmp(nome, nomes[j]) == 0) break;
        }

        if(j == quantidade){
            nomes = realloc(nomes, (quantidade+1) * sizeof(char*));
            nomes[quantidade] = nome;
            quantidade++;
        } else {
            free(nome);
        }
    }
    for(int i =0;i<quantidade;i++){
        printf("%s\n", nomes[i]);
    }

    freeMatriz(nomes, quantidade);

    return 0;
}