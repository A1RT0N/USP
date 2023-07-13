#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
    FILE *fp1, *fp2;
    char c;         
    
    // ./copy teste.dat copy.bin

    if(argc!=3){
        printf("Uso: %s <arquivo1> <arquivo2>\n", argv[0]);
        exit(1);
    }
    if ((fp1 = fopen(argv[1], "r")) == NULL){
        printf("Erro na abertura do arquivo %s\n de leitura", argv[1]);
        exit(1);
    }
    if ((fp2 = fopen(argv[2], "w")) == NULL){
        printf("Erro na abertura do arquivo %s\n de escrita", argv[2]);
        exit(1);
    }
    c = fgetc(fp1); // Esquece o que é caracter. Ele pega de 1 em 1 byte 
    while(!feof(fp1)){ //verifica se chegou no fim do arquivo
        fputc(c, fp2);
        c = fgetc(fp1);
    }
    fclose(fp1);
    fclose(fp2);

    return 0;
}

// Em structs use fwrite ou fread e use arq bin
// Ver códigos Rudinei
