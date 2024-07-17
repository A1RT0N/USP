#include "funcionalidade_1_auxiliar.h"
#include "funcoes.h"

/*
Ayrton da Costa Ganem Filho - 14560190
Enzo Tonon Morente - 14568476
*/

void checagem_inexistente_inteiro(int *inteiro, char *temp){
    //se a o penultimo caracter da string for '\n', significa que a string é: "\n\0", logo, é um campo sem dado
    if (temp[strlen(temp) -1] == '\n'){
        *inteiro = -1; //definido como -1
    } else {
        //senao
        *inteiro = atoi(temp); //transformar de string para inteiro
    }
}

void checagem_inexistente_string(char **string, char *temp){
    //alocar memória para a string
    *string = (char *) malloc(strlen(temp) + 1); 

    //se a o penultimo caracter da string for '\n', significa que a string é: "\n\0", logo, é um campo sem dado
    if (temp[strlen(temp) - 1] == '\n'){
        strcpy(*string, "\0"); //colocar a string como vazia (string "\0" tem strlen() de 0)
    } else {
        //senao
        strcpy(*string, temp); //copiar a string lida para a nossa string
    }
}