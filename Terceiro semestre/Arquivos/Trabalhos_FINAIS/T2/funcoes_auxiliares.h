#ifndef AUXILIARES_H
/*
Ayrton da Costa Ganem Filho - 14560190
Enzo Tonon Morente - 14568476
*/
	#define AUXILIARES_H

    #include "funcoes.h"
    #include "ListaEncadeada.h"
    #include "cabecalho.h"
    #include "registro.h"


    void ler_inteiro(FILE *fp, int *inteiro);

    void ler_char(FILE *fp, char *c);

    void ler_string(FILE *fp, char **string, int tamanho);

    void ler_lixo(FILE *fp, int tamanho);

    void ArquivoToList(FILE *fp, Lista *lista);

    void ler_long_int(FILE *fp, long int *inteiro_longo);



#endif