#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void to_lower(char *str) {
    for(; *str; str++) {
        if(*str >= 'A' && *str <= 'Z')
            *str += 'a' - 'A';
    }
}

void remove_non_alphabetical_characters(char *str) {
    for(; *str; str++) {
        if(!(*str >= 'A' && *str <= 'Z') && !(*str >= 'a' && *str <= 'z') && *str != '-')
            *str = '\0';
    }
}

int main() {
    FILE *file = NULL;
    char file_path[100];
    char **word_list = NULL;
    int i = 0;

    scanf("%s", file_path);

    file = fopen(file_path, "r");

    while(1) {
        char *to_add = NULL;
        int should_add = 1;
        i++;
        word_list = realloc(word_list, sizeof(char *) * i);
        to_add = malloc(100 * sizeof(char));
        if(fscanf(file, "%s", to_add) != 1) {
            break;
        }
        remove_non_alphabetical_characters(to_add);
        to_lower(to_add);

        for(int j = 0; j < i - 1; j++) {
            if (strcmp(word_list[j], to_add) == 0) {
                should_add = 0;
                break;
            }
        }

        if(should_add) {
            word_list[i - 1] = to_add;
        } else {
            i--;
            free(to_add);
        }
    }
    fclose(file);
    i--;

    printf("O texto possui %d palavras distintas\n", i);
    for (int j = 0; j < i; j++) {
        printf("%s\n", word_list[j]);
        free(word_list[j]);
    }

    free(word_list);

    return 0;
}