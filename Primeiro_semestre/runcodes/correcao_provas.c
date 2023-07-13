#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    FILE *fp, *fpg;
    char nomezin[100], gabarito[100];
    scanf("%s",nomezin);
    scanf("%s",gabarito);
    fp = fopen(nomezin,"r");
    fpg = fopen(gabarito,"r");
    if (fp == NULL || fpg == NULL){
        printf("Este banco de dados nao existe.\n");
        exit(1);
    }
    char gabaritoaluno[100], gabaritooficial[100];
    fscanf(fp, "%s ", gabaritoaluno);
    fscanf(fpg, "%s", gabaritooficial);
    int i = 0;
    int contador = 0;
    while(gabaritoaluno[i] != '\0'){
        if(gabaritooficial[i] == gabaritoaluno[i]){
            contador++;
        }
        i++;
    }
    if(contador >= 5){
        printf("%d APROVADO", contador);
    }
    if(contador < 5 && contador >=3){
        printf("%d RECUPERACAO", contador);
    }
    if(contador < 3){
        printf("%d REPROVADO", contador);
    }
    fclose(fp);
    fclose(fpg);
    return 0;


}