#ifndef ARVOREB
/*
Ayrton da Costa Ganem Filho - 14560190
Enzo Tonon Morente - 14568476
*/
    #define ARVOREB
    #define TamNO 60

    #include "index.h"
    #include "funcoes_auxiliares.h"

    typedef struct NO_A{ //struct do nó
        int alturaNo; //altura do nó
        int NroChaves; //número de chaves que o nó tem
        IndexStruct chaves[4]; //Contem c1, pr1, c2, pr2, c3, pr3 e pode conter o indice de overflow
        int RRN[5]; //Vetor que irá conter os rrns, p1, p2, p3, p4 e pode conter o ponteiro que foi criado quando teve overflow
    } NoArvoreB;

    typedef struct  ArvoreB_ { //struct referete ao header da árvore (já colocamos como a árvore em si)
        char status; //status do arquivo
        int noRaiz; //rrn do nó raiz
        int proxRRN; //proxRRN disponível
        int nroChaves; //número de chaves na árvore
        char lixo; //para guardar o caracter de lixo
        int alturaRaiz; //altura da raiz
    } ArvoreB;

    void InsercaoArvoreB(FILE *fp, IndexStruct chave, ArvoreB *arvore);
    long int BuscaArvoreB(ArvoreB *ArvoreB, int id, FILE *fp);
#endif