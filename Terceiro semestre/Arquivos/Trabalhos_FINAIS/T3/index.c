#include "index.h"
#include "funcoes.h"

int compare(const void *a, const void *b) {
    /*
    Função auxiliar usado em qsort que compara dois valores de tipo void
    Dado dois valores do tipo void, retorna um inteiro que é a subtração entre eles levando em conta uma struct IndexStruct
    */

    const IndexStruct *registro1 = (const IndexStruct *)a;
    const IndexStruct *registro2 = (const IndexStruct *)b;
    return (registro1->id - registro2->id);
}
void IndexToVec(FILE *fp, ArquivoIndex *Index, int n){ 
    /*
    Dado o ponteiro para o arquivo de Indeces, a struct sobre o arquivo de indices e a quantidade de indices presentes no arquivo
    esta função vai passar por todos os indícies e ir atualizando a struct sobre o arquivo de indices 
    Essa struct está presente em index.h para mais conhecimento do como é seu funcionamneto

    n é o número de indices presentes no arquivo
    */
    fseek(fp, 0, SEEK_SET); //ir para o início do arquivo

    //ler o status
    char status; ler_char(fp, &status);
    Index->status = status;
    
    if (status == '0') return; //não fazer nada, pois o arquivo não está intacto

    //alocar espaço para o vetor de indices
    Index->vetor = (IndexStruct * ) malloc(sizeof(IndexStruct) * n);

    //declaração de variáveis
    int id; long int ByteOffset;

    for (int i = 0; i < n; i++){ //para cada indice
        ler_inteiro(fp, &id); //ler o id
        ler_long_int(fp, &ByteOffset); //ler o ByteOffset

        //fazer as atribuições
        Index->vetor[i].id = id;
        Index->vetor[i].ByteOffset = ByteOffset;
    }

    Index->tamanho = n;
}

int BuscaBinaria(ArquivoIndex *Index, int idBuscado){ 
    /*
    Realiza a busca binária no arquivo de indeces com o parametro idBuscado.
    Seu retorno será o índice do vetor aonde o parametro de busca foi encontrado
    */
    int inicio = 0;
    int fim = Index->tamanho - 1;

    while (inicio <= fim){
        int meio = inicio + ((fim - inicio) / 2);

        //se achou o id
        if (Index->vetor[meio].id == idBuscado) return meio;

        if (Index->vetor[meio].id < idBuscado) inicio = meio + 1;

        if (Index->vetor[meio].id > idBuscado) fim = meio - 1;
    }

    return -1; //id nao encontrado
}