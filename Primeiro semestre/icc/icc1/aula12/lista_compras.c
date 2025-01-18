#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void sort(char ***list, int size);
void fill_list(char ***list, int *size);

void sort(char ***list, int size) {
    int swap = 0;
    for(int i = 1; i < size; i++) {
        if(strcmp((*list)[i], (*list)[i - 1]) < 0) {
            char *tmp = malloc((strlen((*list)[i]) + 1) * sizeof(char));
            
            strcpy(tmp, (*list)[i]);
            strcpy((*list)[i], (*list)[i - 1]);
            strcpy((*list)[i - 1], tmp);

            free(tmp);
            tmp = NULL;

            swap++;
        }
    }
    if(swap == 0) return;
    else sort(list, size);
}

void fill_list(char ***list, int *num) {
    char string[100];
    while(1) {
        scanf("%s", string);

        if(strcmp(string, "sair") != 0) {
            (*num)++;
            (*list) = realloc((*list), (*num) * sizeof(char *));

            (*list)[(*num) - 1] = malloc((strlen(string) + 1) * sizeof(char));

            strcpy((*list)[(*num) - 1], string);
        } else {
            break;
        }
    }
}

int main() {
    char **list = NULL;
    int num = 0;

    fill_list(&list, &num);
    sort(&list, num);

    for(int i = 0; i < num; i++) {
        printf("%d) %s\n", i + 1, list[i]);
        free(list[i]);
        list[i] = NULL;
    }

    free(list);
    
    return 0;
}