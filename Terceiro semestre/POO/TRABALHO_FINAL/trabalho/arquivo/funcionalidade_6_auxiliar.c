#include "funcionalidade_6_auxiliar.h"

void mudanca_de_status(FILE* fp, char status){

    /*
    Função auxiliar que dado um arquivo FILE e um char, ela muda o status do arquivo para consistente ou inconsistente, conforme passado como parâmetro
    Ela não retorna nada    
    */

    fseek(fp, 0, SEEK_SET);
    fwrite(&status, sizeof(char), 1, fp);
}

NO * BestFit(Lista *lista, int tamanho, long int *ByteOffsetAnterior, long int *ByteOffsetPosterior){
    
    /*
    Função auxiliar importante que, dado uma struct lista encadeada de arquivos removidos e o tamanho do registro de entrada,
    ela retorna uma struct nó da lista encadeada com o nó que gera a menor quantidade de lixo para a substituição do registro logicamente removido
    A função também altera os valores do byteoffset de removido que são passados como parâmetro tanto do registro anterior como do posterior para o novo registro a ser inserido
    Essa função tem como objetico achar o registro logicamente removido que melhor se encaixa, sobrando menos espaço, para o novo registro a ser inserido
    */
    
    NO *p = lista->topo;     // Pega o topo da lista encadeada de removidos

    // Torna os valores do byteoffset dos parâmetros como -1 caso o elemento achado seja o último da lista encadeada dos removidos ou o elemento esteja no fim do arquivo

    *ByteOffsetAnterior = -1;
    *ByteOffsetPosterior = -1;

    if (p == NULL) return NULL; // Caso a lista encadeada esteja vazia, retorna um nó vazio

    if (p->size >= tamanho) { // Verifica se o primeiro nó da lista já é maior que o tamanho dado
        if (p->prox != NULL) *ByteOffsetPosterior = p->prox->ByteOffset;    // Se o próximo não for nulo, o byteoffset do proximo registro está em p->prox

        return p;   // Finaliza a função e retorna o nó
    }

    // Enquanto o nó não for nulo, ou seja, não checar no fim da lista encadeada
    while(p != NULL){
        if (tamanho <= p->size) {    // Se o nó ultrapassar o tamanho dado, retorna p
            if (p->prox != NULL) *ByteOffsetPosterior = p->prox->ByteOffset;    // Se o próximo não for nulo, o byteoffset do proximo registro está em p->prox

            return p;
        }

        *ByteOffsetAnterior = p->ByteOffset;
        p = p->prox;
    }

    return NULL; //não achou ninguem para inserir no lugar
}

CamposInsercao * CriarCamposInsercao(){

    /*
    Função auxiliar que não recebe nada como parâmetro e retorna uma struct de CamposInsercao alocada dinamicamente
    Ela tem como objetivo alocar CamposInsercao
    */

    CamposInsercao *campos_insercao = (CamposInsercao*) malloc(sizeof(CamposInsercao));

    // Aloca os valores das strings como um vetor grande arbritário de tamanho 500

	campos_insercao->nacionalidade = (char *) malloc(500 * sizeof(char));
	campos_insercao->nomeJogador = (char *) malloc(500 * sizeof(char));
	campos_insercao->nomeClube = (char *) malloc(500 * sizeof(char));

    return campos_insercao;
}

void LerCamposInsercao(CamposInsercao *campos_insercao){

    /*
    Função auxiliar que recebe uma struct de CamposInsercao como parâmetro e não retorna nada
    Ela tem como objetivo ler as entradas passadas pelo usuário e preencher na struct CamposInsercao
    */


    //ler id
    scanf("%d", &(campos_insercao->id));

    char *string_temporaria = (char *) malloc(200);
    scan_quote_string(string_temporaria);

    //ler idade
    if (strlen(string_temporaria) == 0){ //se for a string vazia
        campos_insercao->idade = -1;
    }else{
        campos_insercao->idade = atoi(string_temporaria);
    }

    //ler nome
    scan_quote_string(string_temporaria);
    strcpy(campos_insercao->nomeJogador, string_temporaria);

    //ler nacionalidade
    scan_quote_string(string_temporaria);
    strcpy(campos_insercao->nacionalidade, string_temporaria);

    //ler nome clube
    scan_quote_string(string_temporaria);
    strcpy(campos_insercao->nomeClube, string_temporaria);
}

int TamanhoRegistro(CamposInsercao *campos_insercao){

    /*
    Função auxiliar que dado uma struct CamposInsercao preenchida, ela retorna o seu tamanho
    */


    return 33 + strlen(campos_insercao->nacionalidade) + strlen(campos_insercao->nomeClube) + strlen(campos_insercao->nomeJogador);
}