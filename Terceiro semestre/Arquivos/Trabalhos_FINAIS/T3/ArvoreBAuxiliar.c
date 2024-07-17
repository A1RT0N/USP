#include "ArvoreBAuxiliar.h"
#include "ArquivoArvoreB.h"

int ContemNo(NoArvoreB *no, int id, int *igual){
    /*
    É passado um nó, o id e um inteiro
    A função tem dois propósitos:
    Achou o id:
        Seta o inteiro igual como 1 para dizerq ue foi encontrado
        Retorna a posição no vetor de Chaves aonde a chave com aquele id está
    Não achou o id:
        Retorna a posição no vetor de RRN aonde deve ir para fazer ir pro próximo nó
    */
    for (int i = 0; i < no->NroChaves; i++){ //para cada chave no vetor de chaves
        if (no->chaves[i].id == id) { //se o id é igual
            *igual = 1;
            return i;
        } 

        if (id < no->chaves[i].id) return i; //maior do que o anterior (se existir) e menor que o atual
        
        if (i + 1 >= no->NroChaves) return i + 1; // maior do que o último elemento da lista
    }

    return -1; 
}

RetornoInsercao * CriarRetornoInsercao(){
    /*
    Cria a struct do retorno da inserção e o retorna
    */
    RetornoInsercao *retorno = (RetornoInsercao *) malloc(sizeof(RetornoInsercao));

    retorno->subir = (IndexStruct *) malloc(sizeof(IndexStruct));

    retorno->RRN = -1; // colocar o rrn como -1

    return retorno;
}

NoArvoreB * CreateNoArvoreB(){
    /*
    Cria um nó, o inicia com valores padrões e o retorna
    */
    NoArvoreB *no = (NoArvoreB *) malloc(sizeof(NoArvoreB));

    //colocar todos ids e byteoffstes como -1
    for (int i = 0; i < 4; i++) {
        no->chaves[i].id = -1;
        no->chaves[i].ByteOffset = -1; //acho q n preicsa
    }

    //colocar todos os rrns como -1
    for (int i = 0; i < 5; i++) no->RRN[i] = -1;
    
    //inicializar o número de chaves e altura como 0
    no->NroChaves = 0;
    no->alturaNo = 0;

    return no; //retornar o nó
}

void FreeNoArvoreB(NoArvoreB *no){
    /*
    Da free no nó passado
    */
    free(no);
}

int InserirNo(IndexStruct chave, NoArvoreB *no){
    /*
    Adiciona uma nova chave no nó passado
    Retorna se teve overflow ou não
    */

    no->chaves[no->NroChaves].id = chave.id; //colocar o id
    no->chaves[no->NroChaves].ByteOffset = chave.ByteOffset; //colocar o byteoffset

    no->NroChaves ++; //aumentar o número de chaves

    //ordenar o vetor de chaves
    qsort(no->chaves, no->NroChaves, sizeof(IndexStruct), compare); //a função compare está em index.h

    if (no->NroChaves == 4) return 1; //se teve overflow

    return 0; //não teve overflow
}

void RemoveIndiceNo(NoArvoreB *no){
    /*
    Essa função remove a chave de maior valor do nó
    */

    //como o índice sempre está ordenado é só remover a última chave
    no->chaves[no->NroChaves - 1].id = -1;
    no->chaves[no->NroChaves - 1].ByteOffset = (long int) -1;

    //diminui o número de chaves
    no->NroChaves --;
}

void AtualizarRRNs(NoArvoreB *no, int posicao, int novoEsq, int novoDir){
    /*
    Atualiza o RRNS logo após uma nova inserção
    Posição é o local do vetor de chaves aonde a nova chave foi inserida
    novoEsq é o ponteiro a esquerda da nova chave
    novoDir é o ponteiro a direita da nova chave
    */

    //fazer os deslocamentos dos RRNs necessários a partir da inserção a qual o novo nó foi inserido
    for (int i = no->NroChaves; i >= posicao + 2; i--){
        no->RRN[i] = no->RRN[i - 1];
    }


    //colocar os novos ponteiros da esquerda e direita
    no->RRN[posicao] = novoEsq;
    no->RRN[posicao + 1] = novoDir;
}

int PosicaoIndice(NoArvoreB *no, int id){
    /*
    Retorna a posição no array no->chaves que contem id
    */

    //para cada chave
    for (int i = 0; i < no->NroChaves; i++){
        //retorna a posição se for igual
        if (no->chaves[i].id == id) return i;
    }
}

ArvoreB * CreateArvoreB(){
    /*
    Cria a struct da árvore b, seta seus valores iniciais e a retorna
    */
    ArvoreB *arvore = (ArvoreB *) malloc(sizeof(ArvoreB));

    arvore->noRaiz = -1;
    arvore->proxRRN = 0;
    arvore->nroChaves = 0;
    arvore->status = '0';

    arvore->lixo = '$';

    arvore->alturaRaiz = 0;

    return arvore;
}