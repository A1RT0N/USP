#include "funcoes.h"
#include "ArvoreB.h"
#include "ArvoreBAuxiliar.h"
#include "ArquivoArvoreB.h"
#include "funcoes_auxiliares.h"
#include "funcionalidade_5_auxiliar.h" //import de LerEntrada e campos checagem
#include "funcionalidade_8_9_auxiliar.h"

void BuscaLinear(FILE *fp, int QtdRegistros, CamposChecagem *campos_checagem, Registro *registro){
	/*
	Dado um ponteiro para o arquivo de dados, a quantidade de registros presente no arquivo a struct de campos_checagem e a struct registro
	Passa pelo arquivo todo linearmente vendo se cada registro passa nas especificações dados por campos_checagem
	*/
    fseek(fp, 25, SEEK_SET); //ir até i primeiro registro do arquivo que está no ByteOffset 25
	int ByteOffset = 25;

    int AchouAlguem = 0; //variável para verificar se pelo menos uma pessoa foi printada ao longo de todo o arquivo

	for (int i = 0; i < QtdRegistros; i++){ //para cada registro
		LerRegistro(fp, registro);	// Lê o registro inteiro

		if (registro->removido == '1'){ //se o regisitro estiver removido
			ByteOffset += registro->tamanhoRegistro; //atualiza o ByteOffset
			continue; //ir para o proximo registro
		}

		int flag = 1; //flag para verificar se deve printar ou não
		
		if (campos_checagem->checagem[1] == 1){ //se a idade for um campo a ser checado
			if (campos_checagem->idade != registro->idade) flag = 0;
		}
		
		if ((flag != 0) && (campos_checagem->checagem[2] == 1)){ //se o nome do jogador for um campo a ser checado
			if (strcmp(campos_checagem->nomeJogador, registro->nomeJogador) != 0) flag = 0;
		}
		
		if ((flag != 0) && (campos_checagem->checagem[3] == 1)){ //se a nacionalidade for um campo a ser checado
			if (strcmp(campos_checagem->nacionalidade, registro->nacionalidade) != 0) flag = 0;
		}
		
		if ((flag != 0) && (campos_checagem->checagem[4] == 1)){ //se o nome do clube for um campo a ser checado
			if (strcmp(campos_checagem->nomeClube, registro->nomeClube) != 0) flag = 0;
		}

		if (flag){ //se chegou aqui significa que ele passou em todos os parametro logo ele deve ser printado
            AchouAlguem = 1; //marcar que achou pelo menos 1 registro
			PrintarRegistro(registro); //printar o registro
		}

		ByteOffset += registro->tamanhoRegistro; //atualizar o ByteOffset
	}

    if (AchouAlguem == 0){ //se não achou alguem
        printf("Registro inexistente.\n");
    }
}

int BuscaGeral(char *arquivo_dado, char *arquivo_arvore, int n){
	/*
	Dado os arquivos de dados e da árvore e o número de buscas a ser realizadas
	Faz as buscas
	*/
    FILE *fpDados = fopen(arquivo_dado, "rb"); //abre o arquivo e faz tratamento
    if (fpDados == NULL){
        printf("Falha no processamento do arquivo.\n");
        return -1;
    }

    FILE *fpArvore = fopen(arquivo_arvore, "rb"); //abre o arquivo e faz tratamento
    if (fpArvore == NULL){
        printf("Falha no processamento do arquivo.\n");

		fclose(fpDados); //fechar o arquivo de dados
        return -1;
    }

    Cabecalho *cabecalho = (Cabecalho *) malloc(sizeof(Cabecalho)); //Alocar a struct para ler o cabecalho do arquivo de dados
	LerCabecalho(fpDados, cabecalho); //ler o cabecalho do arquivo

	if (cabecalho->status == '0'){ //verifica integridado do arquivo de dados
		printf("Falha no processamento do arquivo.\n");

		//fechar ambos os arquivos
		fclose(fpDados);
    	fclose(fpArvore);

		return -1;
	}

	ArvoreB *arvore = CreateArvoreB(); //criar a árvore
    LerHeader(fpArvore, arvore); //ler o header da árvore

    if (arvore->status == '0'){
        printf("Falha no processamento do arquivo.\n"); //verificar a integridade do arquivo da árvore

		//fechar ambos os arquivos
		fclose(fpDados);
    	fclose(fpArvore);
		
		return -1;
    }

    Registro *registro = CriarRegistro(); //definir a struct registro caso a busca ache o registro

    for (int i = 0; i < n; i++){ //para cada busca que vai ser feita
        int x; scanf("%d", &x); //ler a quantidade de parâmetros da busca

        printf("Busca %d\n\n", i + 1);

        CamposChecagem *campos_checagem = CriarCamposChecagem(); //cria a struct de campos checagem

		//para cada campo a se checar
        for(int j = 0; j < x; j++){ 
			LerEntrada(campos_checagem); //ler quais são os campos a serem checados
		}	

        if (campos_checagem->checagem[0] == 1){ //fazer a busca apartir dos indexes (pois tem ID como parametro da remoção)
			BuscaIndexada(fpDados, fpArvore, arvore, campos_checagem->id, registro);
		}else{ //fazer a busca linearmente
			BuscaLinear(fpDados, cabecalho->nroRegArq + cabecalho->nroRegRem, campos_checagem, registro);
		}
    }

	//fechar ambos os arquivos
    fclose(fpDados);
    fclose(fpArvore);
}