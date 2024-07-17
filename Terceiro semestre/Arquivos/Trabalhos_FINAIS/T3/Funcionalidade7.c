#include "funcoes.h"
#include "ArvoreB.h"
#include "ArvoreBAuxiliar.h"
#include "ArquivoArvoreB.h"
#include "funcoes_auxiliares.h"

int CriarArvoreB(FILE *fpDados, FILE *fpArvore){
    /*
    Dado o ponteiro de arquivo de dados e o ponteiro de arquivo de árvore (vazios)
    Cria a árvore B no ponteiro do arquivo de árvore passado
    */
    if(fpDados == NULL){ //abertura e tratamento de arquivo
        printf("Falha no processamento do arquivo.\n");
        return -1;
    }

    if(fpArvore == NULL){ //abertura e tratamento de arquivo
        printf("Falha no processamento do arquivo.\n");
        return -1;
    }

    Cabecalho *cabecalho = CriarCabecalho(); //Alocar a struct para ler o cabecalho do arquivo de dados
	LerCabecalho(fpDados, cabecalho); //ler o cabecalho do arquivo

	if (cabecalho->status == '0'){ //verifica integridado do arquivo de dados
		printf("Falha no processamento do arquivo.\n");
		return -1;
	}

    long int ByteOffset = 25; //o ByteOffset vai estar em 25, pois já leu o cabecalho

    Registro *registro = CriarRegistro(); //alocar a struct de registro

    ArvoreB *arvore = CreateArvoreB(); //alocar a struct da árvore

    for (int i = 0; i < cabecalho->nroRegArq + cabecalho->nroRegRem; i++){ //para cada registro presente no arquivo
        LerRegistro(fpDados, registro); //ler o registro

        //se o registro estiver removido
        if (registro->removido == '1') {
            ByteOffset += registro->tamanhoRegistro; //atualizar o ByteOffset

            continue; //não fazer nada se o registro estiver removido
        }

        //criar a struct da chave a ser inserida na árvore
        IndexStruct chave;
        chave.id = registro->id; //colocar o valor do id
        chave.ByteOffset = ByteOffset; //colocar o valor do ByteOffset

        InsercaoArvoreB(fpArvore, chave, arvore); //inserir a chave na árvore

        ByteOffset += registro->tamanhoRegistro; //atualizar o ByteOffset
    }

    AtualizarHeader(fpArvore, arvore); //atualiza o header
    AtualizaStatusHeader(fpArvore, '1'); //coloca o status como 1

    return 1;
}