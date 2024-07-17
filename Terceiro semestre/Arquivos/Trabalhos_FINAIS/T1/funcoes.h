#ifndef FORNECIDAS_H
/*
Ayrton da Costa Ganem Filho - 14560190
Enzo Tonon Morente - 14568476
*/
	#define FORNECIDAS_H
	
	#include <stdio.h>
    #include <stdlib.h>
    #include <string.h> 
    #include <ctype.h>
    #include "funcoes_fornecidas.h"

    void ler_inteiro(FILE *fp, int *inteiro);

    void ler_char(FILE *fp, char *c);

    void ler_string(FILE *fp, char **string, int tamanho);

    void ler_lixo(FILE *fp, int tamanho);

    void select_from(char* arquivoEntrada);

    void select_where(char* arquivoEntrada, int n);

    void createTable(char *arquivo_entrada, char *arquivo_saida);



#endif