#ifndef FUNCIONALIDADE_8_9_AUXILIAR
/*
Ayrton da Costa Ganem Filho - 14560190
Enzo Tonon Morente - 14568476
*/
    #define FUNCIONALIDADE_8_9_AUXILIAR

    #include "funcoes.h"
    #include "ArvoreB.h"
    #include "ArvoreBAuxiliar.h"
    #include "ArquivoArvoreB.h"

    void BuscaIndexada(FILE *fpDados, FILE *fpArvore, ArvoreB *arvore, int id, Registro *registro);
    void PrintarRegistro(Registro *registro);
#endif