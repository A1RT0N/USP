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
    #include "ListaEncadeada.h"
    #include "index.h"


    void select_from(char* arquivoEntrada);

    void select_where(char* arquivoEntrada, int n);

    void createTable(char *arquivo_entrada, char *arquivo_saida);

    int CreateIndex(FILE *FpDados, FILE* FpIndices);

    int remove_registro(char* arquivoEntrada, char* arquivoIndices, int n);

    int inserir(char *arquivoDados, char *arquivoIndeces, int quantidade);

    int CriarArvoreB(FILE *fpDados, FILE *fpArvore);

    int BuscaPorId(char *arquivo_dado, char *arquivo_arvore, int n);

    int BuscaGeral(char *arquivo_dado, char *arquivo_arvore, int n);

    int Inserir(char *arquivoDados, char *arquivoIndeces, int quantidade);
#endif  