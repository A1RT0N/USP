#include "funcoes.h"
#include "funcionalidade_5_auxiliar.h"
#include "funcionalidade_3_auxilar.h"
/*
Ayrton da Costa Ganem Filho - 14560190
Enzo Tonon Morente - 14568476
*/
void RemocaoIndexada(FILE *fp, Lista *Removidos, ArquivoIndex *Index, int id){

	/*
	Função auxiliar que recebe um arquivo de dados, uma lista de elementos logicamente removidos, uma struct ArquivoIndex e um id e não retorna nada
	Ela tem como objetivo remover um elemento a partir de index, dado o valor de id
	*/

	int i = BuscaBinaria(Index, id); //bsucar o index no vetor de indeces que contém o id buscado

	if (i == -1) return; // se ele não achou ninguem na busca binária fazer nada
	
	long int ByteOffset = Index->vetor[i].ByteOffset; //pega o ByteOfsset referente a esse registro

	fseek(fp, ByteOffset, SEEK_SET); //ir até o registro

	char removido; ler_char(fp, &removido); //ler se ele está removido ou não
	if (removido == '1') return; //se o registro já está removido não fazer nada

	int tamanho; ler_inteiro(fp, &tamanho); //ler o tamanho do registro

	ListaInserir(Removidos, id, ByteOffset, tamanho); //adicionar o registro na lista de novos removidos
}

void RemocaoLinear(FILE *fp, Lista *Removidos, CamposChecagem *campos_checagem, int QtdRegistros){
	
	/*
	Função auxiliar que recebe um arquivo de dados, uma lista de elementos logicamente removidos, uma struct de entrada e a quantidade de registros total do arquivo
	Ela tem como objetivo remover um elemento buscando o elemento linearmente no arquivo
	*/
	
	//Se está nessa função se sabe que ID não é um dos parametros da remoção, logo não irei utiliza-lo em nenhum momento

	fseek(fp, 25, SEEK_SET); //ir até i primeiro registro do arquivo que está no ByteOffset 25
	int ByteOffset = 25;

	Registro* registro = CriarRegistro();	// Cria um registro

	for (int i = 0; i < QtdRegistros; i++){ //para cada registro

		LerRegistro(fp, registro);	// Lê o registro inteiro

		if (registro->removido == '1'){
			// ler_lixo(fp, tamanho -5 -8 -4); //ler o resto do registro
			ByteOffset += registro->tamanhoRegistro; //atualiza o ByteOffset
			continue; //ir para o proximo registro
		}


		int AdicionaNaLista = 1; //se no final das checagens ainda for 1 deve-se adicionar na lista de novos removidos
		
		if (campos_checagem->checagem[1] == 1){ //se a idade for um campo a ser checado
			if (campos_checagem->idade != registro->idade) AdicionaNaLista = 0;
		}
		
		if ((AdicionaNaLista != 0) && (campos_checagem->checagem[2] == 1)){ //se o nome do jogador for um campo a ser checado
			if (strcmp(campos_checagem->nomeJogador, registro->nomeJogador) != 0) AdicionaNaLista = 0;
		}
		
		if ((AdicionaNaLista != 0) && (campos_checagem->checagem[3] == 1)){ //se a nacionalidade for um campo a ser checado
			if (strcmp(campos_checagem->nacionalidade, registro->nacionalidade) != 0) AdicionaNaLista = 0;
		}
		
		if ((AdicionaNaLista != 0) && (campos_checagem->checagem[4] == 1)){ //se o nome do clube for um campo a ser checado
			if (strcmp(campos_checagem->nomeClube, registro->nomeClube) != 0) AdicionaNaLista = 0;
		}

		if (AdicionaNaLista){ //se chegou aqui significa que ele passou em todos os parametro logo deve ser adicionado na lista de novos removidos
			ListaInserir(Removidos, registro->id, ByteOffset, registro->tamanhoRegistro); //inserir na lista
		}

		ByteOffset += registro->tamanhoRegistro; //atualizar o ByteOffset
	}
}

int remove_registro(char* arquivoDados, char *arquivoIndeces, int n){
	/*
	Função principal que dado um arquivo de entrada, o arquivo de índices e a quantidade de query de remoções a serem realizadas esta função realiza as remoções tanto no arquivo de dados quanto no arquivo de inídices
	*/
	Lista *Removidos = ListaCriar(); //cria a lista dos registros removidos

    FILE *arqDados; //cria o ponteiro para o arquivo de dados
	
    if(arquivoDados == NULL || !(arqDados = fopen(arquivoDados, "r+b"))){ //abertura e tratamento de arquivo
        printf("Falha no processamento do arquivo.");
        return -1;
    }

	Cabecalho *cabecalho = (Cabecalho *) malloc(sizeof(Cabecalho)); //Alocar a struct para ler o cabecalho do arquivo de dados
	LerCabecalho(arqDados, cabecalho); //ler o cabecalho do arquivo

	if (cabecalho->status == '0'){ //verifica integridado do arquivo de dados
		printf("Falha no processamento do arquivo.");
		return -1;
	}

	FILE *arqIndices; //abrir o arquivo de indices
	if(arquivoIndeces == NULL || !(arqIndices = fopen(arquivoIndeces, "w+b"))){ //abertura e tratamento de arquivo
        printf("Falha no processamento do arquivo.");
        return -1;
    }
	
	CreateIndex(arqDados, arqIndices); //cria o arquivo de index
	
	ArquivoIndex *Index = (ArquivoIndex *) malloc(sizeof(ArquivoIndex)); //declarar a struct relacionada ao arquivo de indeces
	IndexToVec(arqIndices, Index, cabecalho->nroRegArq); //Ler o arquivo de indices e o carrega na struct

	//para cada query de remoção
	for (int i = 0; i < n; i++){
		int x; scanf("%d", &x); //ler a quantidade de parâmetros da remoção

		//cria a struct de campos checagem
		CamposChecagem *campos_checagem = CriarCamposChecagem();
		
		//para cada campo a se checar
        for(int j = 0; j< x; j++){ 
			LerEntrada(campos_checagem); //ler quais são os campos a serem checados
		}	

		//A próxima parte do código não chega a remover no arquivo em si
		//Ela somente adiciona os registros removidos na lista de removidos
		
		if (campos_checagem->checagem[0] == 1){ //fazer a remoção apartir dos indexes (pois tem ID como parametro da remoção)
			RemocaoIndexada(arqDados, Removidos, Index, campos_checagem->id);
		}else{ //fazer a remoção linearmente
			RemocaoLinear(arqDados, Removidos, campos_checagem, cabecalho->nroRegArq + cabecalho->nroRegRem);
		}
	}
	
    //neste mometo a lista de removidos contém todos os novos registros a ser removidos

	fclose(arqIndices); //tem que fechar o arquivo de indices para poder abrir ele posteiromente na forma de escrita
	//eu fecho o arquivo, pois na hora de abrir novamente todo seu conteudo será apagado

	arqIndices = fopen(arquivoIndeces, "wb"); //abrir o arquivo de indices como escrita (arquivo agora está vazio)
	AtualizaArquivoIndices(arqIndices, Index, Removidos); //atualiza o arquivo de índice baseado nos novos registros removidos
	fclose(arqIndices); //fechar o arquivo de indices

	//calcular a nova quantidade de registros não removidos
	int QtdRegistrosNaoRemovidos = cabecalho->nroRegArq - Removidos->tamanho; 

	//para realizar a atualização do arquivo de dados é necessário ter os aquivos que já estavam previamente removidos

	ArquivoToList(arqDados, Removidos); //adicionar na lista de removidos os arquivos que estavam previamente removidos

	int QtdRegistrosRemovidos = Removidos->tamanho; //calcular a nova quantidade de registros removidos

	//atualiza o arquivo de dados
	AtualizaArquivoDados(arqDados, Removidos, QtdRegistrosRemovidos, QtdRegistrosNaoRemovidos, cabecalho->proxByteOffset);

	fclose(arqDados); //fechar o arquivo de dados

	free(cabecalho); //liberar a memória alocado para o cabecalho

	return 1;
}