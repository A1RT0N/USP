#include "funcoes.h"
#include "ArvoreB.h"
#include "ArvoreBAuxiliar.h"
#include "ArquivoArvoreB.h"
#include "funcoes_auxiliares.h"
#include "funcionalidade_8_9_auxiliar.h"

int BuscaPorId(char *arquivo_dado, char *arquivo_arvore, int n){
    /*
    Dado o arquivo de dados, o arquivo que contém a árvore b e o número de buscas a ser realizadas
    Faz as buscas por todos os IDs passados e printa na tela se achou o registro
    */
    FILE *fpDados = fopen(arquivo_dado, "rb"); //abre e faz tratamento do arquivo
    if (fpDados == NULL){
        printf("Falha no processamento do arquivo.\n");
        return -1;
    }

    FILE *fpArvore = fopen(arquivo_arvore, "rb"); //abre e faz tratamento do arquivo
    if (fpArvore == NULL){
        printf("Falha no processamento do arquivo.\n");

        //fechar ambos os arquivos
        return -1;
    }

    Cabecalho *cabecalho = (Cabecalho *) malloc(sizeof(Cabecalho)); //Alocar a struct para ler o cabecalho do arquivo de dados
	LerCabecalho(fpDados, cabecalho); //ler o cabecalho do arquivo

	if (cabecalho->status == '0'){ //verifica integridado do arquivo de dados
		printf("Falha no processamento do arquivo.\n");

        fclose(fpDados);
        fclose(fpArvore);
		return -1;
	}

    ArvoreB *arvore = CreateArvoreB(); //criar a árvore
    LerHeader(fpArvore, arvore); //ler o cabecalho da árvore

    if (arvore->status == '0'){ //verificar integridade da árvore
        printf("Falha no processamento do arquivo.\n");

        //fechar ambos os arquivos
        fclose(fpDados);
        fclose(fpArvore);

		return -1;
    }

    Registro *regitro = CriarRegistro(); //definir a struct registro caso a busca ache o registro

    for (int i = 0; i < n; i++){ //para cada busca que vai ser feita
        char temp[3]; int id; scanf("%s %d", temp,&id); //ler o id

        printf("BUSCA %d\n\n", i + 1);

        BuscaIndexada(fpDados, fpArvore, arvore, id, regitro); //fazer a busca por meio do id
    }

    //fechar ambos os arquivos
    fclose(fpDados);
    fclose(fpArvore);
}