#include "funcoes.h"
#include "funcoes_fornecidas.h"

/*
Ayrton da Costa Ganem Filho - 14560190
Enzo Tonon Morente - 14568476
*/

void opcao_1(){
    char arquivo_entrada[100]; //string para arquivo de entrada
    char arquivo_saida[100]; //string para arquivo de saida

    scanf("%s %s", arquivo_entrada, arquivo_saida); //ler ambos os arquivos
    
    createTable(arquivo_entrada, arquivo_saida); //chamar a função que cria o binário (funcionalidade 1)
}

void opcao_2(){
    char arquivo_entrada[100]; //string para arquivo de etnrada

    scanf("%s", arquivo_entrada); //ler o arquivo

    select_from(arquivo_entrada); //chamar a funcionalidade 2
}

void opcao_3(){
    char arquivo_entrada[100]; //string para arquivo de entrada

    scanf("%s", arquivo_entrada); //ler o arquivo de entrada

    int n;
    scanf("%d", &n); //ler a quantidade de buscas a ser realizada

    select_where(arquivo_entrada, n); //chamar a funcionalidade 3
}

void opcao_4(){
    char arquivo_dados[100];
    char arquivo_indices[100];

    scanf("%s %s", arquivo_dados, arquivo_indices); //le os arquivos

    FILE *arqDados = fopen(arquivo_dados, "rb"); //abre o arquivo de dados
    FILE *arqIndices = fopen(arquivo_indices, "wb"); //abre o arquivo de indices

    int flag = CreateIndex(arqDados, arqIndices); //cria o índice

    fclose(arqDados); //fecha o arquivo de dados
    fclose(arqIndices); //fecha o arquivo de índices

    if (flag != -1) binarioNaTela(arquivo_indices); //se nao teve falha durante o processo
}

void opcao_5(){
    char arquivo_dados[100];
    char arquivo_indices[100];

    scanf("%s %s", arquivo_dados, arquivo_indices);

    int n;
    scanf("%d", &n); //ler a quantidade de remoções a serem realizadas

    int flag = remove_registro(arquivo_dados, arquivo_indices, n); //chamar a funcionalidade 5
    
    if (flag != -1){
        binarioNaTela(arquivo_dados);
        binarioNaTela(arquivo_indices);
    }
}

void opcao_6(){
    char arquivo_dados[100];
    char arquivo_indices[100];

    scanf("%s %s", arquivo_dados, arquivo_indices);

    int n;
    scanf("%d", &n); //ler a quantidade de remoções a serem realizadas

    int flag = inserir(arquivo_dados, arquivo_indices, n); //chamar a funcionalidade 5
    
    if (flag != -1){
        binarioNaTela(arquivo_dados);
        binarioNaTela(arquivo_indices);
    }
}

int main(){
    int opcao;

    scanf("%d", &opcao); //ler a opção

    switch (opcao)
    {
    case 1: opcao_1(); //chamar a opção 1
        break;

    case 2: opcao_2(); //chamar a opção 2
        break;

    case 3: opcao_3(); //chamar a opção 3
        break;

    case 4: opcao_4(); //chama a opção 4
        break;

    case 5: opcao_5();
        break;

    case 6: opcao_6();
        break;
    }
    return 0;
}