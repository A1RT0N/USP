#include "funcoes.h"
#include "funcoes_fornecidas.h"
#include "funcionalidade_3_auxilar.h"

/*
Ayrton da Costa Ganem Filho - 14560190
Enzo Tonon Morente - 14568476
*/

void analisar_registro(Registro *registro, FILE* fp, int* campos_checagem, int tamanho_campos_checagem, int id_comparar, int idade_comparar, char* nome_jogador_comparar, char* nacionalidade_comparar, char* nome_clube_comparar, int * flag_retorno){	
	LerRegistro(fp, registro);

	if (registro->removido == '1') return;

	
	int flag = 1; 

	for(int i = 0; i< tamanho_campos_checagem; i++){
		switch (campos_checagem[i]) //olhar qual campo deve ser checado
		{
		case 1: //se for 1 (id)
			if(registro->id != id_comparar){ //fazer a comparação
				flag = 0; //se for diferente
			}
			break;

		case 2: //se for 2 (idade)
			if(registro->idade != idade_comparar){ //fazer a comparação
				flag = 0; //se for diferente
			}
			break;

		case 3: //se for 3 (nome do jogador)
			if(registro->nomeJogador != NULL && strcmp(registro->nomeJogador, nome_jogador_comparar) != 0){ //fazer a comparação
				flag = 0; //se for diferente
			}
			break;

		case 4: //se for 4 (nacionalidade)
			if(registro->nacionalidade != NULL && strcmp(registro->nacionalidade, nacionalidade_comparar) != 0){ //fazer a comparação
				flag = 0; //se for diferente
			}
			break;

		case 5: //se for 5 (nome do clube)
			if(registro->nomeClube != NULL && strcmp(registro->nomeClube, nome_clube_comparar) != 0){ //fazer a comparação
				flag = 0; //se for diferente
			}
			break;

		default:
			break;
		}

		//se a flag for 0 pode sair do for, pois ele já não passou em algum caso
		if(flag == 0){
			break;
		}
	}
	
	//se a flag for 1, signfica que ele passou em todos os casos e pode ser printado
	if(flag){
		if (strlen(registro->nomeJogador) == 0) strcpy(registro->nomeJogador, "nulo");
        if (strlen(registro->nacionalidade) == 0) strcpy(registro->nacionalidade, "nulo");
        if (strlen(registro->nomeClube) == 0) strcpy(registro->nomeClube, "nulo");
		
		//printar na ordem: id, idade, nomeJogador, nacionalidade, nomeClube
        printf("%d,%d,%s,%s,%s\n", registro->id, registro->idade, registro->nomeJogador, registro->nacionalidade, registro->nomeClube);

		//colocar a flag de retorno como 1, pois teve pelo menos 1 registro que foi printado
		*flag_retorno = 1; 
	}

}

void select_where(char* arquivoEntrada, int n){
    FILE *fp;
	
	//tratamento de arquivo
    if(arquivoEntrada == NULL || !(fp = fopen(arquivoEntrada, "rb"))){
        printf("Falha no processamento do arquivo.");
        return;
    }

	char status;

	Cabecalho *cabecalho = CriarCabecalho();
	LerCabecalho(fp, cabecalho);

	if(cabecalho->status == '0'){
        printf("Falha no processamento do arquivo.");
        return;
    }

	//incialização das variáveis
	int id; int idade; char *nacionalidade = NULL; char *nomeClube = NULL; char *nomeJogador = NULL;

    int m;
	
	//para cada busca
    for(int i =0; i< n; i++){
		//ler m
        scanf("%d", &m); //quantidade de parametros na busca
		
		//vetor de campos a serem checados
		int campos_checagem[m];

		//para cada campo a se checar
        for(int j = 0; j< m; j++){ 
			ler_entrada(campos_checagem, &id, &idade, &nacionalidade, &nomeClube, &nomeJogador, j);
		}
		
		//vetor de campos pronto

		//flag para verificar se existe algum registro a ser printado
		int flag = 0;

		Registro *registro = CriarRegistro(); //criar o registro

		//passar por todos os registros existentes
		for(int k = 0; k < (cabecalho->nroRegArq + cabecalho->nroRegRem); k++){
			//fazer uma analise do reigstro
			analisar_registro(registro, fp, campos_checagem, m, id, idade, nomeJogador, nacionalidade, nomeClube, &flag);
		}
		
		
		//se flag continuar como 0
		if (flag == 0){
			//nao registro com os requistos foi encontrado
			printf("Registro inexistente.\n\n");
		}

		// voltar ao primeiro registro do arquivo
		fseek(fp, 25, SEEK_SET);

		// for para dar free no que foi mallocado nessa iteração
		for(int i =0; i< m; i++){
			switch(campos_checagem[i]){
				case 3:
					free(nomeJogador);
					break;
				case 4:
					free(nacionalidade);
					break;
				case 5:
					free(nomeClube);
					break;
				default:
					break;
			}
		}
	}

	fclose(fp); //fechar o arquivo
}