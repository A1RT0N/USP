#ifndef FUNCIONALIDADE_5_AUXILIAR
/*
Ayrton da Costa Ganem Filho - 14560190
Enzo Tonon Morente - 14568476
*/
    #define FUNCIONALIDADE_5_AUXILIAR

    #include "funcoes_auxiliares.h"


    typedef struct CamposChecagem_{
        int id;
        int idade;
        char *nomeClube;
        char *nomeJogador;
        char *nacionalidade;

        int checagem[5]; //cada index representa um campo, se checagem[i] for 0 esse campo não importa, se for 1 importa
    }CamposChecagem;

    CamposChecagem * CriarCamposChecagem();
    void LerEntrada(CamposChecagem *campos_checagem);
    void AtualizaArquivoIndices(FILE *fp, ArquivoIndex *Index, Lista *lista);
    void AtualizaArquivoDados(FILE *fp, Lista *lista, int nroRegRem, int nroRegArq, long int proxByteOffset);
    
#endif      