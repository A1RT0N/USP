#include "funcoes.h"
#include "funcoes_fornecidas.h"

/*
Ayrton da Costa Ganem Filho - 14560190
Enzo Tonon Morente - 14568476
*/

void ler_inteiro(FILE *fp, int *inteiro){
    fread(inteiro, sizeof(int), 1, fp);
}

void ler_char(FILE *fp, char *c){
    fread(c, sizeof(char), 1, fp);
}

void ler_string(FILE *fp, char **string, int tamanho){
    fread(*string, sizeof(char), tamanho, fp);
}

void ler_lixo(FILE *fp, int tamanho){
    char lixo[tamanho];

    fread(lixo, tamanho, 1, fp);
}