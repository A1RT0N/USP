#include "cabecalho.h"

// Função auxiliar que escreve no FILE* fp o cabeçalho que é passado como parâmetro
// Essa função escreve dados no cabeçalho do arquivo. Ela recebe um arquivo de dados aberto e um struct Cabecalho e não retorna nada

void EscreverCabecalho(FILE *fp, Cabecalho* cabecalho){
    fseek(fp, 0, SEEK_SET);  // Vai para o início do arquivo
    
    fwrite(&cabecalho->status, 1, 1, fp); //escrever o status (1 bytes)
    fwrite(&cabecalho->topo, 8, 1, fp); //escrever o topo (8 bytes)
    fwrite(&cabecalho->proxByteOffset, 8, 1, fp); //escrever o proxByteOffset (8 bytes)
    fwrite(&cabecalho->nroRegArq, 4, 1, fp); //escrever o nroRegArq (4 bytes)
    fwrite(&cabecalho->nroRegRem, 4, 1, fp); //escrever o nroRegRem (4 bytes)
}


// Função auxiliar que lê do FILE* fp e armazena todos os dados na struct Cabecalho
// Essa função lê dados no cabeçalho do arquivo. Ela recebe um arquivo de dados aberto e um struct Cabecalho e não retorna nada
void LerCabecalho(FILE *fp, Cabecalho *cabecalho){
    fseek(fp, 0, SEEK_SET); //ir para o início do arquivo
    
    // No arquivo essa função irá ler do arquivo e armazenar em uma variável local os seguintes elementos

    char status; ler_char(fp, &status); // Lê status como char
    long int topo; ler_long_int(fp, &topo); // Lê campo topo como long int
    long int proxByteOffset; ler_long_int(fp, &proxByteOffset); // Lê Próximo Byte Offset como long int
    int nroRegArq; ler_inteiro(fp, &nroRegArq); // Lê número de registro do arquivo como inteiro
    int nroRegRem; ler_inteiro(fp, &nroRegRem); // Lê Número de registros removidos do arquivo como inteiro

    // A função, após ler valores e armazenar nas variáveis, guarda seus respectivos valores nos dados da struct

    cabecalho->status = status;
    cabecalho->topo = topo;
    cabecalho->proxByteOffset = proxByteOffset;
    cabecalho->nroRegArq = nroRegArq;
    cabecalho->nroRegRem = nroRegRem;
}

// Função auxiliar que aloca dinamicamente uma struct do tipo Cabecalho
// Ela recebe nada e não retorna uma struct Cabecalho alocado dinamicamente
Cabecalho* CriarCabecalho(){
    Cabecalho* cabecalho = (Cabecalho*) malloc(sizeof(Cabecalho));
    return cabecalho;
}