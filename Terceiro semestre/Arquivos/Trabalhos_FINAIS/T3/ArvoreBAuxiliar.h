#ifndef ARVOREBAUXILIAR
/*
Ayrton da Costa Ganem Filho - 14560190
Enzo Tonon Morente - 14568476
*/
    #define ARVOREBAUXILIAR

    #include "ArvoreB.h"

    typedef struct retornoInsercao_{ //struct do retorno da inserção
        int Promotion; //1 para dizer que um nó do nível abaixo foi promovido para o nível a cima
        IndexStruct *subir; //chave a subir pro próximo nível
        int RRN; //rrn da nova página criada caso tenha promotion
    }RetornoInsercao;

    int ContemNo(NoArvoreB *no, int id, int *igual);
    
    NoArvoreB * CreateNoArvoreB();
    RetornoInsercao * CriarRetornoInsercao();

    void RemoveIndiceNo(NoArvoreB *no);
    int InserirNo(IndexStruct chave, NoArvoreB *no);

    void AtualizarRRNs(NoArvoreB *no, int posicao, int novoEsq, int novoDir);

    int PosicaoIndice(NoArvoreB *no, int id);

    ArvoreB * CreateArvoreB();

    void FreeNoArvoreB(NoArvoreB *no);
#endif