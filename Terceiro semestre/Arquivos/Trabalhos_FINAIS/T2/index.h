#ifndef INDEX_
/*
Ayrton da Costa Ganem Filho - 14560190
Enzo Tonon Morente - 14568476
*/
    #define INDEX_

    #include <stdio.h>
    #include "funcoes_auxiliares.h"


    typedef struct index_{
        int id;
        long int ByteOffset;
    }IndexStruct;

    typedef struct arquivoindex{
        int tamanho;
        IndexStruct *vetor;
        char status;
    }ArquivoIndex;

    int compare(const void *a, const void *b);
    void IndexToVec(FILE *fp, ArquivoIndex *Index, int n);
    int BuscaBinaria(ArquivoIndex *Index, int idBuscado);
    
#endif