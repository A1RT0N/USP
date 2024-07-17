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

    }  

    return 0;
}