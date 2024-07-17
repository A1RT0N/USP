#include "funcionalidade_3_auxilar.h"
#include "funcoes.h"

/*
Ayrton da Costa Ganem Filho - 14560190
Enzo Tonon Morente - 14568476
*/


void ler_entrada(int *campos_checagem, int *id, int *idade, char **nacionalidade, char **nomeClube, char **nomeJogador, int j){
	char string_campo[20]; 

	//ler o campo a ser checado
	scanf("%s", string_campo); 

	//se o campo for id
	if(strcmp(string_campo, "id") == 0){ //referente a 1
		scanf("%d", id);
		campos_checagem[j] = 1;

		return;
	}

	//se o campo dor idade
	if(strcmp(string_campo, "idade") == 0){ //referente a 2
		scanf("%d", idade);
		campos_checagem[j] = 2;

		return;
	}

	//se o campo for o Nome do Jogador
	if(strcmp(string_campo, "nomeJogador") == 0){ //referente a 3
		*nomeJogador = (char*)malloc(500*sizeof(char));
		scan_quote_string(*nomeJogador);
		campos_checagem[j] = 3;

		return;
	}

	//se o campo for nacionalidade
	if(strcmp(string_campo, "nacionalidade") == 0){ //referente a 4
		*nacionalidade = (char*)malloc(500*sizeof(char));
		scan_quote_string(*nacionalidade);
		campos_checagem[j] = 4;

		return;
	}

	//se o campo for o nome do clube
	if(strcmp(string_campo, "nomeClube") == 0){ //referenate a 5
		*nomeClube = (char*)malloc(500*sizeof(char));
		scan_quote_string(*nomeClube);
		campos_checagem[j] = 5;

		return;
	}  
}


void printar_registro(char* nome_jogador_do_registro, char* nacionalidade_do_registro, char* nome_clube_do_registro){

	printf("Nome do Jogador: %s\n", nome_jogador_do_registro);
    
    printf("Nacionalidade do Jogador: %s\n", nacionalidade_do_registro);

    printf("Clube do Jogador: %s\n", nome_clube_do_registro);
	
    printf("\n");
}


// A função começa com o ponteiro fp no início do campo "id" do registro a ser lido

void LerString_arquivo(char **string, FILE *fp){
	int tamanho_campo; ler_inteiro(fp, &tamanho_campo); //ler o tamanho do campo

    *string = (char *) malloc(10 + (sizeof(char) * tamanho_campo));  //alocar memória
	(*string)[tamanho_campo] = '\0';

	if(tamanho_campo == 0){
		strcpy(*string, "SEM DADO");
	}else{
		ler_string(fp, string, tamanho_campo); //ler a string
	}
}