#include "funcoes.h"
#include "funcoes_fornecidas.h"
#include "funcionalidade_3_auxilar.h"

/*
Ayrton da Costa Ganem Filho - 14560190
Enzo Tonon Morente - 14568476
*/

void analisar_registro(FILE* fp, int* campos_checagem, int tamanho_campos_checagem, int id_comparar, int idade_comparar, char* nome_jogador_comparar, char* nacionalidade_comparar, char* nome_clube_comparar, int * flag_retorno){
	int id_do_registro;
	int idade_do_registro;
	char* nome_jogador_do_registro;
	char* nacionalidade_do_registro;
	char* nome_clube_do_registro;

	ler_inteiro(fp, &id_do_registro);
	ler_inteiro(fp, &idade_do_registro);

	//ler o nome do jogador
	LerString_arquivo(&nome_jogador_do_registro, fp); 

	//ler a nacionalidade do jogador
	LerString_arquivo(&nacionalidade_do_registro, fp);

	//ler o clube do jogador
	LerString_arquivo(&nome_clube_do_registro, fp);

	int flag = 1; 

	for(int i =0; i< tamanho_campos_checagem; i++){
		switch (campos_checagem[i]) //olhar qual campo deve ser checado
		{
		case 1: //se for 1 (id)
			if(id_do_registro != id_comparar){ //fazer a comparação
				flag = 0; //se for diferente
			}
			break;

		case 2: //se for 2 (idade)
			if(idade_do_registro != idade_comparar){ //fazer a comparação
				flag = 0; //se for diferente
			}
			break;

		case 3: //se for 3 (nome do jogador)
			if(nome_jogador_comparar != NULL && strcmp(nome_jogador_do_registro, nome_jogador_comparar) != 0){ //fazer a comparação
				flag = 0; //se for diferente
			}
			break;

		case 4: //se for 4 (nacionalidade)
			if(nacionalidade_comparar != NULL && strcmp(nacionalidade_do_registro, nacionalidade_comparar) != 0){ //fazer a comparação
				flag = 0; //se for diferente
			}
			break;

		case 5: //se for 5 (nome do clube)
			if(nome_clube_comparar != NULL && strcmp(nome_clube_do_registro, nome_clube_comparar) != 0){ //fazer a comparação
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
		printar_registro(nome_jogador_do_registro, nacionalidade_do_registro, nome_clube_do_registro);

		//colocar a flag de retorno como 1, pois teve pelo menos 1 registro que foi printado
		*flag_retorno = 1; 
	}

	free(nome_jogador_do_registro);
	free(nacionalidade_do_registro);
	free(nome_clube_do_registro);

}

void select_where(char* arquivoEntrada, int n){
    FILE *fp;
	
	//tratamento de arquivo
    if(arquivoEntrada == NULL || !(fp = fopen(arquivoEntrada, "rb"))){
        printf("Falha no processamento do arquivo.");
        return;
    }

	//le os primeiors 17 bytes do cabeçalho (nao necessários para essa função)
	ler_lixo(fp, 17);

	//le quantatiods de registros nao removidos
    int nroRegArq; 
	ler_inteiro(fp, &nroRegArq);

	//le quantidades de registros removidos
    int nroRegRem; 
	ler_inteiro(fp, &nroRegRem);

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

		printf("Busca %d\n\n", i+1);

		//flag para verificar se existe algum registro a ser printado
		int flag = 0;

		//passar por todos os registros existentes
		for(int k = 0; k < (nroRegArq + nroRegRem); k++){
			char removido; ler_char(fp, &removido); //le se está removido
			int tamanho; ler_inteiro(fp, &tamanho); //le o tamanho

			//se for removido
			if (removido == '1'){
				ler_lixo(fp, tamanho-5); //ler o registro todo
				continue; //ir para o proximo registro
			}


			ler_lixo(fp, 8); //ler o prox (não será utilizado)

			//fazer uma analise do reigstro
			analisar_registro(fp, campos_checagem, m, id, idade, nomeJogador, nacionalidade, nomeClube, &flag);
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