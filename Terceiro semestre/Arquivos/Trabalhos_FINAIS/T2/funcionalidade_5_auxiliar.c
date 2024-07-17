#include "funcionalidade_5_auxiliar.h"
#include "funcionalidade_1_auxiliar.h" //para a função de escrever no cabecalho

void LerEntrada(CamposChecagem *campos_checagem){
	/*
	Dado a struct de CamposChecagem le quais campos devem ser checados e preenche a struct.

	A struct funciona da forma a qual ela tem um vetor checagem com 5 inteiros.
	checagem[i] é 1 se aquele campo for usado na checagem e 0 se nao for
	
	Essa função serve para ler as entradas passada pelo usuário e armazenar em uma struct CamposChecagem
	*/    
	char string_campo[20]; //declara uma string para poder ler

	//ler o campo a ser checado
	scanf("%s", string_campo); 

	//se o campo for id
	if(strcmp(string_campo, "id") == 0){ //referente ao index 0 no vetor de checagem
		int id; scanf("%d", &id); //ler o id

		// Armazena os valores na struct

        campos_checagem->id = id;
        campos_checagem->checagem[0] = 1;

		return;
	}

	//se o campo dor idade
	if(strcmp(string_campo, "idade") == 0){ //referente ao index 1 no vetor de checagem
		int idade; scanf("%d", &idade); //ler a idade

		// Armazena os valores na struct
        
        campos_checagem->idade = idade;
        campos_checagem->checagem[1] = 1;

		return;
	}

	//se o campo for o Nome do Jogador
	if(strcmp(string_campo, "nomeJogador") == 0){ //referente ao index 2 no vetor de checagem
		// Aloca dinamicamente e lê uma variável string e transfere ela para seu respectivo campo em CamposChecagem

		char *nomeJogador = (char*)malloc(500*sizeof(char));
		scan_quote_string(nomeJogador); //ler o nome do jogador
		
        strcpy(campos_checagem->nomeJogador, nomeJogador);
        campos_checagem->checagem[2] = 1;

		free(nomeJogador);
		return;
	}

	//se o campo for nacionalidade
	if(strcmp(string_campo, "nacionalidade") == 0){ //referente ao index 3 no vetor de checagem
		// Aloca dinamicamente e lê uma variável string e transfere ela para seu respectivo campo em CamposChecagem
		
		char *nacionalidade = (char*)malloc(500*sizeof(char));
		scan_quote_string(nacionalidade); //ler o nome do jogador
		
        strcpy(campos_checagem->nacionalidade, nacionalidade);
        campos_checagem->checagem[3] = 1;

		free(nacionalidade);
		return;
	}

	//se o campo for o nome do clube
	if(strcmp(string_campo, "nomeClube") == 0){ //referente ao index 4 no vetor de checagem
		// Aloca dinamicamente e lê uma variável string e transfere ela para seu respectivo campo em CamposChecagem
		
		char *nomeClube = (char*)malloc(500*sizeof(char));
		scan_quote_string(nomeClube); //ler o nome do jogador
		
        strcpy(campos_checagem->nomeClube, nomeClube);
        campos_checagem->checagem[4] = 1;

		free(nomeClube);
		return;
	}
}

CamposChecagem * CriarCamposChecagem(){
	/*
	Essa função não recebe nada como parâmetro e retorna uma struct alocada dinamicamente
	Ela tem como função alocar dinamicamente a struct para ser futuramente preenchida
	Aloca a memória necessária para a struct e para cada campo
	Inicializa o vetor todo com valores 0
	*/
    CamposChecagem *campos_checagem = (CamposChecagem*) malloc(sizeof(CamposChecagem));

    //colocar todos os campos como 0 (não são utilizados na remoção)
    for (int i = 0; i < 5; i++) campos_checagem->checagem[i] = 0;

	campos_checagem->nacionalidade = (char *) malloc(500 * sizeof(char));
	campos_checagem->nomeJogador = (char *) malloc(500 * sizeof(char));
	campos_checagem->nomeClube = (char *) malloc(500 * sizeof(char));

    return campos_checagem;
}

void AtualizaIndicesVetor(ArquivoIndex *Index, Lista *lista){
	/*
	Função que recebe como parâmetro uma struct ArquivoIndex e uma struct Lista de lista encadeada e retorna nada
	Ela tem como objetivo atualizar os índices da struct ArquivoIndedx
	Se um registro está na lista passada singifca que ele foi removido, logo, deve-se marcar no vetor de inídices que aquele indíce não existe mais.
	*/

	NO *p = lista->topo; //pegar o primeiro registro da lista de removidos

	while(p != NULL){
		int i = BuscaBinaria(Index, p->id); //procura o index do vetor que contém o id p->id

		Index->vetor[i].ByteOffset = -5; //marcar o ByteOffset como -5 para indicar que agora aquele index está removido

		p = p->prox;
	}	
}

void AtualizaArquivoIndices(FILE *fp, ArquivoIndex *Index, Lista *lista){
	/*
	Essa função recebe como parâmetro um FILE de arquivo de índices, uma struct ArquivoIndex e uma Lista do tipo lista encadeada e não retorna nada
	Ela teom como objetivo escrever no arquivo de índice tudo que está na struct ArquivoIndex
	
	Em outras palavras, dado o arquivo de indices, a Struct referente a este arquivo e a lista de registros removidos
	reescreve o arquivo agora contendo somente os indices necessários
	*/

	//Atualiza o vetor de indexs, aonde agora se um index foi removido seu ByteOffset vai estar marcado como -5
	AtualizaIndicesVetor(Index, lista);

	//o fseek para 0 é feito em AtualizaIndicesVetor

	char status = '0'; fwrite(&status, sizeof(char), 1, fp); //escrever o status do arquivo como 0

	for (int i = 0; i < Index->tamanho; i++){ //para cada índice
		//se o indice estiver marcado como removido ir para o próximo
		if (Index->vetor[i].ByteOffset == -5) {
			continue;
		}

		fwrite(&(Index->vetor[i].id), sizeof(int), 1, fp); //escrever o id no arquivo
		fwrite(&(Index->vetor[i].ByteOffset), sizeof(long int), 1, fp); //escrever o ByteOffset no arquivo
	}

	fseek(fp, 0, SEEK_SET); //voltar para o início do arquivo
	status = '1'; fwrite(&status, sizeof(char), 1, fp); //escrever o status do arquivo como 1
}

void AtualizaArquivoDados(FILE *fp, Lista *lista, int nroRegRem, int nroRegArq, long int proxByteOffset){
	/*
	Dado o arquivo de dados no modo escrita e leitura e a lista de todos os registros removidos
	Atualiza o arquivo de tal forma que o topo e todos os prox de cara registro estejam devidamente ajustados para a lista passda
	*/
	fseek(fp, 0, SEEK_SET); //ir para o início do arquivo

	NO *p = lista->topo; //pegar o primeiro elemento da lista
	long int topo = p->ByteOffset; //pegar o o ByteOffset a ser escrito no topo

	Cabecalho* cabecalho = CriarCabecalho();

	cabecalho->status = '0';
	cabecalho->topo = topo;
	cabecalho->proxByteOffset = proxByteOffset;
	cabecalho->nroRegArq = nroRegArq;
	cabecalho->nroRegRem = nroRegRem;

	EscreverCabecalho(fp, cabecalho); //atualizar o cabecario
	
	fseek(fp, p->ByteOffset, SEEK_SET); //ir para o início do primeiro registro logicamente removido
	
	char removido = '1'; //criar a variavel para escrever que aquele registro está removido

	//Para todos os registros removidos menos o último
	while (p->prox != NULL){
		fwrite(&removido, sizeof(char), 1, fp); //escrever que aquele registro está removido

		int a; ler_inteiro(fp, &a); //pular o tamanho do registro (nao vamos sobreescrever)
		
		fwrite(&(p->prox->ByteOffset), sizeof(long int), 1, fp); //escrever o ByteOffset

		fseek(fp, p->prox->ByteOffset, SEEK_SET); //ir para o ByteOffset do próximo registro removido

		p = p->prox; //ir para o próximo registro logicamente removido
	}

	//quando chega aqui todos os registros removidos ja atualizados escritos menos o último

	fwrite(&removido, sizeof(char), 1, fp); //escrever que aquele registro está removido

	ler_lixo(fp, 4); //pular o id (nao vamos sobreescrever)

	long int prox = -1; fwrite(&prox, sizeof(long int), 1, fp); //escrever -1

	cabecalho->status = '1';
	EscreverCabecalho(fp, cabecalho); //atualizar o cabecalho
}