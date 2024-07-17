#include "funcoes.h"
#include "funcoes_fornecidas.h"
#include "funcionalidade_1_auxiliar.h"

/*
Ayrton da Costa Ganem Filho - 14560190
Enzo Tonon Morente - 14568476
*/

FILE * escrever_cabecario(char *arquivo, char status, long int topo, long int proxByteOffset, int nroRegArq, int nroRegRem){
    FILE *arquivo_bin;

    arquivo_bin = fopen(arquivo, "r+b"); //abrir o arquivo no modo de leitura e escrita

    if (arquivo_bin == NULL) {
        arquivo_bin = fopen(arquivo, "wb"); //se o arquivo nao existe abrir no modo de escrita (cria o arquivo)

        if (arquivo_bin == NULL) printf("Não foi possível abrir o arquivo");
    }

    fwrite(&status, 1, 1, arquivo_bin); //escrever o status (1 bytes)
    fwrite(&topo, 8, 1, arquivo_bin); //escrever o topo (8 bytes)
    fwrite(&proxByteOffset, 8, 1, arquivo_bin); //escrever o proxByteOffset (8 bytes)
    fwrite(&nroRegArq, 4, 1, arquivo_bin); //escrever o nroRegArq (4 bytes)
    fwrite(&nroRegRem, 4, 1, arquivo_bin); //escrever o nroRegRem (4 bytes)
    
    return arquivo_bin; //retornar o ponteiro para o arquivo
}

int ler_arquivo(char *arquivo_entrada, FILE *arquivo_bin, int *prox_byte_offset){
    /*Essa função le os registros do arquivo de entrada (csv) e coloca eles no arquivo de saida(bin)
    Ela retorna o número de registros que foram lidos
    */
    FILE *arquivo_csv;

    char linha[1024];

    arquivo_csv = fopen(arquivo_entrada, "r"); //abrir o arquivo csv em modo de leitura
    if (arquivo_csv == NULL) printf("Não foi possível abrir o arquivo");

    fgets(linha, 1024, arquivo_csv); //ler a primeira linha e ignora-la (cabecalho)

    int qtd_registros = 0;

    //declarar as variaveis necessárias para cada registro
    int id;
    int idade;
    char *nomeJogador;
    char *nacionalidade;
    char *nomeClube;

    *prox_byte_offset = 25; //o próximo byte offset vai começar em 25 (logo após o cabeçalho)

    while (fgets(linha, 1024, arquivo_csv)){ //ler todas as linhas restantes do arquivo
        qtd_registros ++; //aumentar a quantidade de registros
        
        char *linha_pre_processada = (char *) malloc(sizeof(char) * 1024);
        int contador = 0; //contador da linha pre processada

        //fazer o pré processamento da linha
        for (int i = 0; i < strlen(linha); i++){
            //\n será o caracter para dizer que o campus nao existe, logo, se tem algum \n na string original eu não irei passar ele para a nova
            if (linha[i] == '\n') continue; 

            if (linha[i] != ','){
                //copiar o caracter
                linha_pre_processada[contador] = linha[i];
                contador ++;
                
                continue;
            }

            //se chegou aqui significa que é uma virgula ','

            //copiar a virgula
            linha_pre_processada[contador] = linha[i];
            contador ++;

            //se o proximo caracter for virgula ou \n siginfica que o campo nao existe
            if ((linha[i + 1] == ',') || (linha[i + 1] == '\n')){
                linha_pre_processada[contador ] = '\n'; //colocar o caracter que implica a inexistencia de um campo
                contador ++;
            }
        }
        linha_pre_processada[contador] = '\0';

        
        char *temp = strtok(linha_pre_processada, ","); //ler o campo
        checagem_inexistente_inteiro(&id, temp); //chega se o id existe ou se era um campo sem dado

        temp = strtok(NULL, ","); //ler o campo
        checagem_inexistente_inteiro(&idade, temp); //checa se a idade existe ou se era um campo sem dado

        temp = strtok(NULL, ",");  //ler o campo
        checagem_inexistente_string(&nomeJogador, temp); //chega se o nome do jogador existe ou se era um campo sem dado

        temp = strtok(NULL, ",");  //ler o campo
        checagem_inexistente_string(&nacionalidade, temp); //chega se a nacionalidade eixste ou se era um campo sem dado
        
        temp = strtok(NULL, ","); //ler o campo
        checagem_inexistente_string(&nomeClube, temp); //checa se o clube existe ou se era um campo sem dado


        //printf("%c", nomeClube[strlen(nomeClube)]);
        char temp_char[2] = "0";  fwrite(&temp_char, 1, 1, arquivo_bin); //se está removido ou nao (1 byte)

        //contem o tamanho do registro
        int tamanho_registro = 1 + 4 +  8 + 4 + 4 + 4 +(strlen(nomeJogador) ) + 4 + (strlen(nacionalidade) ) + 4 + (strlen(nomeClube));
        fwrite(&tamanho_registro, sizeof(int), 1, arquivo_bin); //tamanho do registro (4 bytes)

        long int temp_LongInt = -1; fwrite(&temp_LongInt, 8, 1, arquivo_bin); //proximo byte offset (8 bytes)

        fwrite(&id, sizeof(int), 1, arquivo_bin); //escrever o id (4 bytes)

        fwrite(&idade, sizeof(int), 1, arquivo_bin); //escrever a idade (4 bytes)

        int temp_int = (int) strlen(nomeJogador); fwrite(&temp_int, 4, 1, arquivo_bin); //tamNomeJog (4 bytes)
        fwrite(nomeJogador, sizeof(char), strlen(nomeJogador), arquivo_bin); //escrever o nome do jogador (n bytes)

        temp_int = (int) strlen(nacionalidade); fwrite(&temp_int, 4, 1, arquivo_bin); //tamNacionalidade (4 bytes)
        fwrite(nacionalidade, sizeof(char), strlen(nacionalidade), arquivo_bin); //escrever a nacionalidade (n bytes)

        temp_int = (int) strlen(nomeClube); fwrite(&temp_int, 4, 1, arquivo_bin); //tamNomeClube
        fwrite(nomeClube, sizeof(char), strlen(nomeClube), arquivo_bin); //escrever o nome do clube (n bytes)

        *prox_byte_offset += tamanho_registro;
        
        free(linha_pre_processada);
        free(nomeJogador);
        free(nomeClube);
        free(nacionalidade);
    }

    //fechar o arquivo csv
    fclose(arquivo_csv);

    return qtd_registros;
}

void createTable(char *arquivo_entrada, char *arquivo_saida){
    FILE *arquivo_bin = escrever_cabecario(arquivo_saida, '0', -1, 0, 0, 0); //escreve o cabecalho

    int proxByteOffset;
    int qtd_registros = ler_arquivo(arquivo_entrada, arquivo_bin, &proxByteOffset); //ler o arquivo

    fclose(arquivo_bin); //fecha o arquivo binário que foi aberto na função escrever_cabecario

    fclose(escrever_cabecario(arquivo_saida, '1', -1, proxByteOffset, qtd_registros, 0));
    /*Ao ler o arquivo csv sabemos que todos os registros lidos nele não foram removidos
    Logo, a quantidade de registros removidos é 0.*/

    binarioNaTela(arquivo_saida);
}   