#include <stdio.h>
#include <stdlib.h>

int main() {
    char c;
    char *string = NULL;
    int tamanho = 0;
    while((c = getchar()) != EOF) {
        tamanho++;
        string = realloc(string, tamanho * sizeof(char));
        string[tamanho - 1] = c;
    }
    string = realloc(string, (tamanho + 1) * sizeof(char));
    string[tamanho] = '\0';

    for(int i = tamanho - 1; i >= 0; i--) {
        printf("%c", string[i]);
    }
    printf("\n");

    free(string);
    string = NULL;

    return 0;
}