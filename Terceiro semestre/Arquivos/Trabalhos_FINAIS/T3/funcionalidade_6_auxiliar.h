#ifndef FUNCIONALIDADE_6_AUXILIAR
/*
Ayrton da Costa Ganem Filho - 14560190
Enzo Tonon Morente - 14568476
*/
    #define FUNCIONALIDADE_6_AUXILIAR

    #include "funcoes.h"

    typedef struct CamposInsercao_{
        int id;
        int idade;
        char *nomeClube;
        char *nomeJogador;
        char *nacionalidade;
    }CamposInsercao;

    CamposInsercao * CriarCamposInsercao();
    void LerCamposInsercao(CamposInsercao *campos_insercao);
    int TamanhoRegistro(CamposInsercao *campos_insercao);
    NO * BestFit(Lista *lista, int tamanho, long int *ByteOffsetAnterior, long int *ByteOffsetPosterior);

    void mudanca_de_status(FILE* fp, char status);


#endif