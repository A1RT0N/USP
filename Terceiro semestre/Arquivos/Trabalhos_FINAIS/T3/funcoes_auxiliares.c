#include "funcoes_auxiliares.h"
/*
Ayrton da Costa Ganem Filho - 14560190
Enzo Tonon Morente - 14568476
*/

// Função que lê um inteiro e muda seu conteúdo a parte de um arquivo
void ler_inteiro(FILE *fp, int *inteiro){
    fread(inteiro, sizeof(int), 1, fp);
}

// Função que lê um char e muda seu conteúdo a parte de um arquivo
void ler_char(FILE *fp, char *c){
    fread(c, sizeof(char), 1, fp);
}

// Função que lê um string de tamanho 'tamanho' e muda seu conteúdo a parte de um arquivo
void ler_string(FILE *fp, char **string, int tamanho){
    fread(*string, sizeof(char), tamanho, fp);
}

// Função que lê um lixo, ou seja, anda com o ponteiro fp uma quantidade de bytes definida em 'tamanho'
void ler_lixo(FILE *fp, int tamanho){
    char lixo[tamanho];

    fread(lixo, tamanho, 1, fp);
}

// Função que lê um long int e muda seu conteúdo a parte de um arquivo
void ler_long_int(FILE *fp, long int *inteiro_longo){
    fread(inteiro_longo, sizeof(long int), 1, fp);
}


void ArquivoToList(FILE *fp, Lista *lista){ 
    /*
    Função auxiliar que lê o arquivo dado uma lista encadeada vazia e retorna a lista encadeada dos registros removidos
    Ela tem como objetivo preencher a lista encadeada de elementos logicamente removidos
    */

    Cabecalho *cabecalho = (Cabecalho*)malloc(sizeof(Cabecalho));
    LerCabecalho(fp, cabecalho); //ler o cabecalho


    if (cabecalho->status == '0') return; //nao fazer nada
    
    long int ByteOffset = cabecalho->topo;

    Registro* registro = CriarRegistro();
    
    while (ByteOffset != -1){ //enquanto ainda tiver registros removidos
        fseek(fp, ByteOffset, SEEK_SET);

        LerRegistro(fp,registro);

        ListaInserir(lista, registro->id, ByteOffset, registro->tamanhoRegistro);

        ByteOffset = registro->Prox; //atualizar o ByteOffset
    }
}
