#ifndef CABECALHO_H
/*
Ayrton da Costa Ganem Filho - 14560190
Enzo Tonon Morente - 14568476
*/
	#define CABECALHO_H
	
    #include "funcoes.h"
    #include "funcoes_auxiliares.h"

    typedef struct cabecalho_{
        char status;
        long int topo;
        long int proxByteOffset;
        int nroRegArq;
        int nroRegRem;
    }Cabecalho;

    Cabecalho* CriarCabecalho();

    void LerCabecalho(FILE *fp, Cabecalho *cabecalho);

    void EscreverCabecalho(FILE *fp, Cabecalho* cabecalho);


#endif