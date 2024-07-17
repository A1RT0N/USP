#include "registro.h"
#include "funcoes_auxiliares.h"

Registro* CriarRegistro(){

    /*
    Função auxiliar do 43tiw54o que criq ele
    Retorna uma struct Registro com as suas strings alocadas com tamanho arbitrário de 1000 unidades
    */

    Registro* registro = (Registro*) malloc(sizeof(Registro));
    registro->nomeJogador = (char*) malloc(sizeof(char)*1000);
    registro->nacionalidade = (char*) malloc(sizeof(char)*1000);
    registro->nomeClube = (char*) malloc(sizeof(char)*1000);
    return registro;
}
    
void LerRegistro(FILE *fp, Registro *registro){
    /*
    Função auxiliar do registro que lê um arquivo do tipo FILE já aberto e escreve os valores na struct registro
    Recebe um arquivo e uma struct registro como parâmetro e não retorna nada
    */

    // Lê as variáveis char e inteiras no arquivo
    ler_char(fp, &(registro->removido));
    ler_inteiro(fp, &(registro->tamanhoRegistro));
    ler_long_int(fp, &(registro->Prox));
    ler_inteiro(fp, &(registro->id));
    ler_inteiro(fp, &(registro->idade));

    // Lê as variáveis de tamanho de string e de string no arquivo 

    registro->tamNomeJog = LerString_arquivo(&(registro->nomeJogador), fp);
    registro->tamNacionalidade = LerString_arquivo(&(registro->nacionalidade), fp);
    registro->tamNomeClube = LerString_arquivo(&(registro->nomeClube), fp);

    //printf("%d %d %d %d", registro->tamanhoRegistro, registro->tamNomeJog, registro->tamNacionalidade, registro->tamNomeClube);

    //verificar se existe lixo dentro do registro. Se existir, ler ele
    int diferenca = registro->tamanhoRegistro - 33 - registro->tamNomeJog - registro->tamNacionalidade - registro->tamNomeClube;

    //printf("Diferença nessa porra %d\n", diferenca);
    if (diferenca != 0) ler_lixo(fp, diferenca);
}

void EscreverRegistro(FILE *fp, Registro* registro){

    /*
    Função auxiliar do registro que escreve um arquivo do tipo FILE já aberto em valores na struct registro
    Recebe um arquivo e uma struct registro como parâmetro e não retorna nada
    */

    fwrite(&(registro->removido), sizeof(char),1 , fp);
    fwrite(&(registro->tamanhoRegistro), sizeof(int),1 , fp);
    fwrite(&(registro->Prox), sizeof(long int),1 , fp);
    fwrite(&(registro->id), sizeof(int), 1 , fp);
    fwrite(&(registro->idade), sizeof(int) ,1 , fp);
    fwrite(&(registro->tamNomeJog), sizeof(int),1 , fp);
    fwrite((registro->nomeJogador), sizeof(char),registro->tamNomeJog , fp);
    fwrite(&(registro->tamNacionalidade), sizeof(int), 1, fp);
    fwrite((registro->nacionalidade), sizeof(char),registro->tamNacionalidade , fp);
    fwrite(&(registro->tamNomeClube), sizeof(int), 1, fp);
    fwrite((registro->nomeClube), sizeof(char),registro->tamNomeClube , fp);

}

void PreencherRegistro(Registro* registro, char removido, int tamanhoRegistro, long int Prox, int id, int idade, char* nomeJogador, char* nacionalidade, char* nomeClube){

    /*
    Função auxiliar do registro que recebe parâmetros que serão transferidos para a struct registros, não retornando nada
    Tem como intuito passar valores para a struct registro, ampliando a legibilidade do código
    */

    // Passa os valores inteiros e char
    registro->removido = removido;
    registro->tamanhoRegistro = tamanhoRegistro;
    registro->Prox = Prox;
    registro->id = id;
    registro->idade = idade;


    // Passa os valores de string, utilizando strlen() para ler o tamanho da string e armazenar e strcpy() para transferir a string passada como parâmetro para a struct
    registro->tamNomeJog = strlen(nomeJogador);
    strcpy(registro->nomeJogador, nomeJogador);

    registro->tamNacionalidade = strlen(nacionalidade);
    strcpy(registro->nacionalidade, nacionalidade);

    registro->tamNomeClube = strlen(nomeClube);
    strcpy(registro->nomeClube, nomeClube);

}

