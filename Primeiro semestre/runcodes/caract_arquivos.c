#include <stdio.h>
#include <stdlib.h>


int main(){
    FILE *fp;
    char nomezin[100];
    scanf("%s",nomezin);
    fp = fopen(nomezin,"r");
    if (fp == NULL){
        printf("Este banco de dados nao existe.\n");
        exit(1);
    }
    fseek(fp, 0, SEEK_END);
    long algumacoisa = ftell(fp);

    printf("%ld", algumacoisa);


}