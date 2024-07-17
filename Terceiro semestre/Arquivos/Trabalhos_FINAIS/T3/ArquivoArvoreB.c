#include "ArquivoArvoreB.h"
#include "ArvoreBAuxiliar.h"
#include "ArvoreB.h"

void EscreveHeader(FILE *fp, ArvoreB *arvore){
    /*
    Dado o pinteiro para o arquivo da árvore e a árvore em si
    Escreve o header
    */
    fseek(fp, 0, SEEK_SET); //ir para o ínicio do arquivo

    fwrite(&(arvore->status), sizeof(char), 1, fp); //escrever o status
    fwrite(&(arvore->noRaiz), sizeof(int), 1, fp);
    fwrite(&(arvore->proxRRN), sizeof(int), 1, fp);
    fwrite(&(arvore->nroChaves), sizeof(int), 1, fp);

    for (int i = 0; i < 47; i++){
        fwrite(&(arvore->lixo), sizeof(char), 1, fp);
    }
    
}

void AtualizarHeader(FILE *fp, ArvoreB *arvore){
    /*
    Dado o pinteiro para o arquivo da árvore e a árvore em si
    Atualiza o header da árvore
    */
    fseek(fp, 1, SEEK_SET); //ir para 1 (local aonde inicial o noRaiz)
    fwrite(&(arvore->noRaiz), sizeof(int), 1, fp); //escrever o novo nó raiz
    fwrite(&(arvore->proxRRN), sizeof(int), 1, fp); //atualizar o rrn
    fwrite(&(arvore->nroChaves), sizeof(int), 1, fp); //atualizar o número de chaves
}

void AtualizaStatusHeader(FILE *fp, char status){
    /*
    Dado o ponteiro para oarquivo da árvore o um status (0 ou 1) atualiza o status do arquivo
    */
    fseek(fp, 0, SEEK_SET);
    fwrite(&status, sizeof(char), 1, fp); //atualizar o status
}

void LerHeader(FILE *fp, ArvoreB *arvore){
    /*
    Dado o pinteiro para o arquivo da árvore e a árvore em si
    Lê o header do arquivo
    */
    fseek(fp, 0, SEEK_SET); //ir para o íncio do arquivo

    ler_char(fp, &(arvore->status)); //ler o status
    ler_inteiro(fp, &(arvore->noRaiz)); //ler o noRaiz
    ler_inteiro(fp, &(arvore->proxRRN)); //ler o proxRRN
    ler_inteiro(fp, &(arvore->nroChaves)); //ler o número de chaves

    fseek(fp, 60, SEEK_SET); //dar fseek para 60 para nao ter que ler os 47 bytes de lixo
}


void EscreveNo(FILE *fp, NoArvoreB *no, int rrn){
    /*
    Dado o pinteiro para o arquivo da árvore, um nó em si e um rrn
    Escreve o nó no seu resectivo rrn (rrn + 1) * 60
    */
    fseek(fp, (rrn + 1) * TamNO, SEEK_SET); //ir até o nó

    fwrite(&(no->alturaNo), sizeof(int), 1, fp); //escrever a altura do nó
    fwrite(&(no->NroChaves), sizeof(int), 1, fp); //escrever o número de chaves

    for (int i = 0; i < 3; i++){ //para as 3 chaves do nó
        fwrite(&(no->chaves[i].id), sizeof(int), 1, fp); //escrever o id
        fwrite(&(no->chaves[i].ByteOffset), sizeof(long int), 1, fp); //escrever o ByteOffset
    }
    
    for (int i = 0; i < 4; i++){ //para os 4 rrns do nó
        fwrite(&(no->RRN[i]), sizeof(int), 1, fp); //escrever o rrn
    }
}

void LerNo(FILE *fp, NoArvoreB *no, int rrn){
    /*
    Dado o pinteiro para o arquivo da árvore, um nó em si e um rrn
    Lê o nó e armazena no nó passado
    */
    fseek(fp, (rrn + 1) * TamNO, SEEK_SET); //ir até o nó

    ler_inteiro(fp, &(no->alturaNo)); //ler a altura do nó
    ler_inteiro(fp, &(no->NroChaves)); //ler o número de chaves

    for (int i = 0; i < 3; i++){ //para os 3 índices do nó
        ler_inteiro(fp, &(no->chaves[i].id)); //ler o id
        ler_long_int(fp, &(no->chaves[i].ByteOffset)); //ler o ByteOffset
    }

    for (int i = 0; i < 4; i++){ //para os 4 rrns do nó
        ler_inteiro(fp, &(no->RRN[i])); //ler o rrn
    }
}