#include <stdio.h>
#include <stdlib.h>

char *read_string();

struct agenda {
    char dia[3];
    char mes[3];
    char ano[5];
    char hora[3];
    char minuto[3];
    char segundo[3];
    char *nome;
};

typedef struct agenda agenda_t;

char *read_string() {
    char c;
    char *string = NULL;
    int size = 0;
    while((c = getchar()) != '\n') {
        size++;
        string = realloc(string, size * sizeof(char));
        string[size - 1] = c;
    }
    string = realloc(string, (size + 1) * sizeof(char));
    string[size] = '\0';

    return string;
}

int main() {
    int num;
    agenda_t *agenda = NULL;
    scanf("%d", &num);

    agenda = malloc(num * sizeof(agenda_t));

    for(int i = 0; i < num; i++) {
        agenda_t evento;
        
        scanf("%s", evento.dia);
        scanf("%s", evento.mes);
        scanf("%s", evento.ano);
        scanf("%s", evento.hora);
        scanf("%s", evento.minuto);
        scanf("%s ", evento.segundo);
        evento.nome = read_string();

        agenda[i] = evento;
    }

    for(int i = 0; i < num; i++) {
        agenda_t evento = agenda[i];

        printf("%s/%s/%s - ", evento.dia, evento.mes, evento.ano);
        printf("%s:%s:%s\n", evento.hora, evento.minuto, evento.segundo);
        printf("%s\n", evento.nome);
        
        free(evento.nome);
        evento.nome = NULL;
    }

    return 0;
}