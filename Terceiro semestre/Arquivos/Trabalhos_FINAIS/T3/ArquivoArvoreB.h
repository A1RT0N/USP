#ifndef ARQUIVOARVOREB
/*
Ayrton da Costa Ganem Filho - 14560190
Enzo Tonon Morente - 14568476
*/
    #define ARQUIVOARVOREB 

    #include "ArvoreB.h"
    
    void EscreveHeader(FILE *fp, ArvoreB *arvore);
    void EscreveNo(FILE *fp, NoArvoreB *no, int rrn);
    void LerNo(FILE *fp, NoArvoreB *no, int rrn);
    void AtualizarHeader(FILE *fp, ArvoreB *arvore);
    void AtualizaStatusHeader(FILE *fp, char status);
    void LerHeader(FILE *fp, ArvoreB *arvore);
    
#endif