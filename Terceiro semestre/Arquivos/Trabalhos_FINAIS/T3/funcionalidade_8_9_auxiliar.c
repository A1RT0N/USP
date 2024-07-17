#include "funcionalidade_8_9_auxiliar.h"

void TratarRegistro(Registro *registro){
    if (strlen(registro->nomeJogador) == 0) strcpy(registro->nomeJogador, "SEM DADO");
    if (strlen(registro->nacionalidade) == 0) strcpy(registro->nacionalidade, "SEM DADO");
    if (strlen(registro->nomeClube) == 0) strcpy(registro->nomeClube, "SEM DADO");
}

void PrintarRegistro(Registro *registro){
    /*
    Dado um registro o printa com a formatação correta
    */
    TratarRegistro(registro);

    printf("Nome do Jogador: %s\n", registro->nomeJogador);
    printf("Nacionalidade do Jogador: %s\n", registro->nacionalidade);
    printf("Clube do Jogador: %s\n\n", registro->nomeClube);
}

void BuscaIndexada(FILE *fpDados, FILE *fpArvore, ArvoreB *arvore, int id, Registro *registro){
    /*
    Dado o arquivo de dados e da árvore, um id e uma struct registro
    Realiza uma busca pelo id na árvore, se algo for achado printa na tela o registro
    */
    long int ByteOffset = BuscaArvoreB(arvore, id, fpArvore); //fazer a busca

    if (ByteOffset == -1) { //se não deu certo a busca
        printf("Registro inexistente.\n\n");

        return;
    }

    fseek(fpDados, ByteOffset, SEEK_SET); //ir até o ByteOffset para poder ler o registro
    LerRegistro(fpDados, registro); //ler o registro

    PrintarRegistro(registro); //printar o registro
}