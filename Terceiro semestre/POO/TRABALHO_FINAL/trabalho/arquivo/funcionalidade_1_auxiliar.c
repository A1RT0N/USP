#include "funcionalidade_1_auxiliar.h"
#include "funcoes.h"

/*
Ayrton da Costa Ganem Filho - 14560190
Enzo Tonon Morente - 14568476
*/

void checagem_inexistente_inteiro(int *inteiro, char *temp){
    // Se o penúltimo caractere da string for '\n' ou '\r', significa que a string é: "\n\0" ou "\r\0", logo, é um campo sem dado
    if (temp[strlen(temp) - 1] == '\n' || temp[strlen(temp) - 1] == '\r'){
        *inteiro = -1; // Definido como -1
    } else {
        // Senão
        *inteiro = atoi(temp); // Transformar de string para inteiro
    }
}

void checagem_inexistente_string(char **string, char *temp){
    // Alocar memória para a string
    *string = (char *) malloc(strlen(temp) + 1);

    // Se o penúltimo caractere da string for '\n' ou '\r', significa que a string é: "\n\0" ou "\r\0", logo, é um campo sem dado
    if (temp[strlen(temp) - 1] == '\n' || temp[strlen(temp) - 1] == '\r'){
        strcpy(*string, "\0"); // Colocar a string como vazia (string "\0" tem strlen() de 0)
    } else {
        // Senão
        strcpy(*string, temp); // Copiar a string lida para a nossa string
    }
}

