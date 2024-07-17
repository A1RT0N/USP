#include "funcoes.h"
#include "funcoes_auxiliares.h"

/*
Ayrton da Costa Ganem Filho - 14560190
Enzo Tonon Morente - 14568476
*/

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

    //para cada registro
    for (int i = 0; i < (nroRegArq + nroRegRem); i++){
        char removido; ler_char(fp, &removido); //ler se foi removido
        int tamanho; ler_inteiro(fp, &tamanho); //ler o tamanho

        if (removido == '1'){ //se fi removido
            ler_lixo(fp, tamanho-5); //pular o registro

            continue;
        }

        ler_lixo(fp, 16); //ler os próximos 16 bytes do registro (nao vao ser utilizados)

        //printar o nome, nacionalidade e clube
        printf("Nome do Jogador: ");
        ler_escrever_string(fp);

        printf("Nacionalidade do Jogador: ");
        ler_escrever_string(fp);

        printf("Clube do Jogador: ");
        ler_escrever_string(fp);

        printf("\n");
    }
    

    fclose(fp);
}