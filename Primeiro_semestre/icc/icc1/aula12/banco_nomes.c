#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WORD_SIZE 20

void append_to_list(char ***list, int *size, char *string);
char **read_names(int num);
void cmp_and_add(char ***bank_list, int *bank_size, char **list, int list_size);
void free_list(char ***list, int list_size);

void append_to_list(char ***list, int *size, char *string) {
    (*size)++;
    *list = realloc(*list, (*size) * sizeof(char *));
    (*list)[(*size) - 1] = string;
}

char **read_names(int num) {
    char **list = NULL;
    int list_size = 0;
    for(int i = 0; i < num; i++) {
        char c;
        char *name = malloc(WORD_SIZE * sizeof(char));
        int size = 0;
        while((c = getchar()) != '#') {
            if(c != '\n' && c != '\r' && c != '\t') {
                size++;
                name[size - 1] = c;
            }
            if(size % WORD_SIZE == 0) {
                name = realloc(name, (size + WORD_SIZE) * sizeof(char));
            }
        }   
        name[size] = '\0';
        append_to_list(&list, &list_size, name);
    }

    return list;
}

void cmp_and_add(char ***bank_list, int *bank_size, char **list, int list_size) {
    for(int i = 0; i < list_size; i++) {
        int should_add = 1;
        for(int j = 0; j < *bank_size; j++) {
            if(strcmp(list[i], (*bank_list)[j]) == 0)
                should_add = 0;
        }
        if(should_add)
            append_to_list(bank_list, bank_size, list[i]);
    }
}

void free_list(char ***list, int list_size) {
    for(int i = 0; i < list_size; i++) {
        if((*list)[i] != NULL) {
            free((*list)[i]);
            (*list)[i] = NULL;
        }
    }
    if(*list != NULL) {
        free(*list);
        *list = NULL;
    }
}

int main() {
    int num1, num2;

    scanf("%d", &num1);
    char **list1 = read_names(num1);
    
    scanf("%d", &num2);
    char **list2 = read_names(num2);

    cmp_and_add(&list1, &num1, list2, num2);

    for(int i = 0; i < num1; i++)
        printf("%s\n", list1[i]);

    free_list(&list1, num1);
    // free_list(&list2, num2);
    return 0;
}