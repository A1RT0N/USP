#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int main(){
    FILE *fp;
    char nomezin[50];
    scanf("%s",nomezin);
    fp = fopen(nomezin,"r");
    if (fp == NULL){
        printf("Este banco de dados nao existe.\n");
        exit(1);
    }

    int salario;
    scanf("%d", &salario);
    int c;
    char nome[30];
    int idade;
    char funcao[100];
    int salariominimo;
    fscanf(fp,"%d ", &c);
    while(c > 0){
        fscanf(fp,"%s ", nome);
        fscanf(fp,"%d ", &idade);
        fscanf(fp,"%s ", funcao);
        fscanf(fp,"%d ", &salariominimo);

        if(salario < salariominimo){
            printf("%s\n%d\n%s\n%d\n", nome, idade, funcao, salariominimo);
        }        

        c--;
    }
    return 0;
    
}