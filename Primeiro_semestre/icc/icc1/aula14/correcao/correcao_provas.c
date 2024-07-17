#include <stdio.h>
#include <stdlib.h>

void ler_notas(char **notas, FILE *arquivo) {
    char c;
    int i = 0;
    while((c = fgetc(arquivo)) != EOF)
    {
        (*notas)[i] = c;
        i++;
    }

    (*notas)[i] = '\0';
}

int main() {
    int nota = 0;

    char notas_caminho[100];
    char gabarito_caminho[100];

    char *notas = malloc(10 * sizeof(char));
    char *gabarito = malloc(10 * sizeof(char));

    FILE *notas_txt = NULL;
    FILE *gabarito_txt = NULL;

    scanf("%s %s", notas_caminho, gabarito_caminho);

    notas_txt = fopen(notas_caminho, "r");
    gabarito_txt = fopen(gabarito_caminho, "r");

    ler_notas(&notas, notas_txt);
    ler_notas(&gabarito, gabarito_txt);

    for(int i = 0; i < 10; i++)
        if(notas[i] == gabarito[i])
            nota++;

    if(nota < 3)
        printf("%d REPROVADO\n", nota);
    else if(nota >= 3 && nota < 5)
        printf("%d RECUPERACAO\n", nota);
    else
        printf("%d APROVADO\n", nota);
    
    free(notas);
    notas = NULL;

    free(gabarito);
    gabarito = NULL;

    return 0;
}