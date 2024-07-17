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

    int flag = inserir(arquivo_dados, arquivo_indices, n); //chamar a funcionalidade 6
    
    if (flag != -1){
        binarioNaTela(arquivo_dados);
        binarioNaTela(arquivo_indices);
    }
}

void opcao_7(){
    char arquivo_dados[100];
    char arquivo_arvore[100];

    scanf("%s %s", arquivo_dados, arquivo_arvore);

    FILE *fpDados = fopen(arquivo_dados, "r+b");
    FILE *fpArvore = fopen(arquivo_arvore, "w+b");
    
    int flag = CriarArvoreB(fpDados, fpArvore); //chamar a funcionalidade 7
    
    if (fpDados != NULL) fclose(fpDados);
    if (fpArvore != NULL) fclose(fpArvore);

    if (flag != -1){
        binarioNaTela(arquivo_arvore);
    }
}

void opcao_8(){
    char arquivo_dados[100];
    char arquivo_arvore[100];

    scanf("%s %s", arquivo_dados, arquivo_arvore);

    int n;
    scanf("%d", &n); //ler a quantidade de buscas a serem realizadas

    BuscaPorId(arquivo_dados, arquivo_arvore, n); //chamar a funcionalidade 8
}

void opcao_9(){
    char arquivo_dados[100];
    char arquivo_arvore[100];

    scanf("%s %s", arquivo_dados, arquivo_arvore);

    int n;
    scanf("%d", &n); //ler a quantidade de buscas a serem realizadas

    BuscaGeral(arquivo_dados, arquivo_arvore, n); //chamar a funcionalidade 9
}

void opcao_10(){
    char arquivo_dados[100];
    char arquivo_indices[100];

    scanf("%s %s", arquivo_dados, arquivo_indices);

    int n;
    scanf("%d", &n); //ler a quantidade de remoções a serem realizadas

    int flag = Inserir(arquivo_dados, arquivo_indices, n); //chamar a funcionalidade 10
    
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

    case 5: opcao_5(); //chama a opção 5
        break;

    case 6: opcao_6(); //chama a opção 6
        break;

    case 7: opcao_7(); //chama a opção 7
        break;

    case 8: opcao_8(); //chama a opção 8
        break;

    case 9: opcao_9(); //chama a opção 9
        break;

    case 10: opcao_10(); //chama a opção 10
        break;
    }
    
    return 0;
}