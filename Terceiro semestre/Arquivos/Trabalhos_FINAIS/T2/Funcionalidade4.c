#include "funcoes.h"


int CreateIndex(FILE *FpDados, FILE* FpIndices){
    /*
    Função principal que dado o ponteiro para o arquivo de dados e o ponteiro para o arquivo de índices.
    Le o arquivo de dados e escreve todos os índices no arquivo de índices.
    Seu retorno é o número de indíces ou -1 se algo não deu certo.
    */

    fseek(FpDados, 0, SEEK_SET); //ir para o início do arquivo de dados
    fseek(FpIndices, 0, SEEK_SET); //ir para o início do arquivo de índices

    if ((FpDados == NULL) || (FpIndices == NULL)){ //verificação de arquivo
        printf("Falha no processamento do arquivo.\n");
        return -1;
    }

    Cabecalho *cabecalho = (Cabecalho *) malloc(sizeof(Cabecalho)); //Alocar a struct para ler o cabecalho do arquivo de dados
    LerCabecalho(FpDados, cabecalho); //ler ocabecalho

    if (cabecalho->status == '0'){ //se o arquivo de dados estiver inconsistente
        printf("Falha no processamento do arquivo.\n");
        return -1;
    }

    //variavel que vai guardar o valor do ByteOffset durante a leitura do arquivo de dados
    long int ByteOffset = 25; //o ByteOffset começa em 25, pois o cabeçalho acaba em 24

    //O status do arquivo fica como inconsistente (0) enquanto vc está escrevendo no arquivo
    char temp_char = '0';  fwrite(&temp_char, sizeof(char), 1, FpIndices); 

    //Criar um vetor que irá conter todos os índices
    IndexStruct vetor[cabecalho->nroRegArq]; 

    int contador = 0; //contador para adicionar os índices no vetor

    //como ja leu todo o cabecalho neste momento o ponteiro para o arquivo de dados está exatamente no primeiro registro (ByteOffset 25)

    Registro *registro = CriarRegistro(); //criar a struct de registro

    for (int i = 0; i < cabecalho->nroRegArq + cabecalho->nroRegRem; i++){ //para todos os registros no arquivo de dados
        LerRegistro(FpDados, registro); //ler o registro

        if (registro->removido != '1'){
            // Coloca os valores no vetor de struct
            vetor[contador].id = registro->id;
            vetor[contador].ByteOffset = ByteOffset;
            contador++;
        }

        ByteOffset += registro->tamanhoRegistro; //atualizar o ByteOffset para o próximo IndexStruct
    }

    qsort(vetor, cabecalho->nroRegArq, sizeof(IndexStruct), compare); //ordenar o vetor de indices através do tamanho do registro
    
    // Escreve os indices ordenados no arquivo de índice
    for (int i = 0; i < cabecalho->nroRegArq; i++){
        fwrite(&(vetor[i].id), sizeof(int), 1, FpIndices); //escreve o id
        fwrite(&(vetor[i].ByteOffset), sizeof(long int), 1, FpIndices); //escreve o ByteOffset
    }

    fseek(FpIndices, 0, SEEK_SET); //retorna ao início do arquivo de índices
    temp_char = '1';  fwrite(&temp_char, sizeof(char), 1, FpIndices); //O status do arquivo fica como consistente (1)

    free(cabecalho); //liberar a memória alocada no cabecalho

    return cabecalho->nroRegArq; //retorna a quantidade de índices escrito no arquivo de índices
}