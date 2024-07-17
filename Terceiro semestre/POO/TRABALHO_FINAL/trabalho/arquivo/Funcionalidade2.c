#include "funcoes.h"
#include "funcoes_auxiliares.h"

/*
Ayrton da Costa Ganem Filho - 14560190
Enzo Tonon Morente - 14568476
*/

int contem_barra_n(char *string){
    int n = sizeof(string);

    for (int i = 0; i < n; i++){
        if (string[i] == '\n') return 1;
    }

    return 0;
}

void ler_escrever_string(FILE *fp){
    int tamanho; ler_inteiro(fp, &tamanho);
    char *string = (char *) malloc(1 + (sizeof(char) * tamanho)); ler_string(fp, &string, tamanho);

    if (tamanho == 0){
        printf("SEM DADO\n");
    }else{
        string[tamanho] = '\0';
        
        printf("%s\n", string);
    }

    free(string);
}

void select_from(char* arquivoEntrada){
    FILE *fp;

    if(arquivoEntrada == NULL || !(fp = fopen(arquivoEntrada, "rb"))){
        printf("Falha no processamento do arquivo.");
        return;
    }

    char status;

    fread(&status, 1,1, fp);
    
    if(status == '0'){
        printf("Falha no processamento do arquivo.");
        return;
    }

    ler_lixo(fp, 16); //pula os 16 primeiros bytes do cabecalho (desnecessários para este código)

    int nroRegArq; ler_inteiro(fp, &nroRegArq); //le a quantidade de registros nao removidos
    int nroRegRem; ler_inteiro(fp, &nroRegRem); //le a quantidade de registros removidos

    //se nao tiver nenhum registro disponível
    if (nroRegArq == 0){
        printf("Registro inexistente.\n\n");

        fclose(fp);

        return;
    }

    Registro *registro = CriarRegistro();

    //para cada registro
    for (int i = 0; i < (nroRegArq + nroRegRem); i++){
        LerRegistro(fp, registro); //ler o registro

        if (registro->removido == '1') continue;
        
        if (strlen(registro->nomeJogador) == 0) strcpy(registro->nomeJogador, "nulo");
        if (strlen(registro->nacionalidade) == 0) strcpy(registro->nacionalidade, "nulo");
        if (strlen(registro->nomeClube) == 0) strcpy(registro->nomeClube, "nulo");

        //printar na ordem: id, idade, nomeJogador, nacionalidade, nomeClube
        printf("%d,%d,%s,%s,%s\n", registro->id, registro->idade, registro->nomeJogador, registro->nacionalidade, registro->nomeClube);
    }

    fclose(fp);
}