#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

char *leitura(char *c) {
    int tamanho = 30;
    int i = 0;
    char *palavra = malloc(tamanho);
    char ch;

    while ((ch = getchar()) != EOF && ch != ' ') {
        palavra[i] = ch;
        i++;

        if (i >= tamanho) {
            tamanho += 30;
            palavra = realloc(palavra, tamanho);
        }
    }
    
    palavra[i] = '\0';
    *c = ch;

    return palavra;
}

char *reduz(char *palavra) {
    int i;
    char *mudar = malloc(strlen(palavra) + 1);

    for (i = 0; i < strlen(palavra); i++) {
        mudar[i] = tolower(palavra[i]);
    }
    mudar[i] = '\0';

    return mudar;
}

int main() {
    int inicial = 650;
    int numerodeinvasoras = 0;
    char *frasefinal = malloc(inicial);
    char uc;
    char *invasora = malloc(inicial);

    scanf("%s", invasora);
    getchar();

    while (1) {
        char *palavra = leitura(&uc);
        if (strcmp(reduz(palavra), reduz(invasora)) != 0) {
            if ((strlen(frasefinal) + strlen(palavra)) >= inicial) {
                inicial += 347;
                frasefinal = realloc(frasefinal, inicial);
            }
            strcat(frasefinal, palavra);
            if (uc == EOF) {
                break;
            }
            char Ultimochar[2] = {uc, '\0'};
            strcat(frasefinal, Ultimochar);
            
        } else {
            numerodeinvasoras++;
        }
        free(palavra);
    }

    printf("[Palavras invasoras: %d]\n\n", numerodeinvasoras);
    printf("%s", frasefinal);

    free(invasora);
    free(frasefinal);

    return 0;
}
