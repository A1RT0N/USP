#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *to_lower(char *string) {
    for(; *string; string++) {
        if(*string >= 'A' && *string <= 'Z')
            *string += 'a' - 'A';
    }
    return string;
}

int main() {
    char invasora[20];
    char atual[1000];
    char c;
    char **list = NULL;
    int count = 0;
    int i = 0;
    int word_count = 0;
    scanf("%s", invasora);
    to_lower(invasora);

    while(1) {
        c = getchar();

        if(c != ' ' && c != EOF) {
            atual[i] = c;
            i++;
        } else if(c == ' ' || c == EOF) {
            char *print = malloc(i * sizeof(char));
            
            atual[i] = '\0';
            i = 0;
            strcpy(print, atual);
            to_lower(atual);
            if(strcmp(atual, invasora) != 0) {
                word_count++;
                list = realloc(list, word_count * sizeof(char *));
                list[word_count - 1] = print;
            } else {
                count++;
                free(print);
                print = NULL;   
            }
        }
        if(c == EOF)
            break;
    }

    printf("[Palavras invasoras: %d]\n", count);

    for(int j = 0; j < word_count; j++) {
        printf("%s ", list[j]);
        free(list[j]);
        list[j] = NULL;
    }
    free(list);
    list = NULL;

    printf("\n");

    return 0;
}