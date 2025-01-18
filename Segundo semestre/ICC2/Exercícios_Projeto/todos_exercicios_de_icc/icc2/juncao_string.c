/*exercício 2 (aula 17/08/2023)*/
#include <stdio.h>
#include <string.h>

int main(void){
    char string1[1000];
    char string2[1000];

    scanf("%s", string1);
    scanf("%s", string2);

    int s1, s2;

    s1 = strlen(string1);
    s2 = strlen(string2);

    char n_string[s1 + s2 + 1];

    for (int i = 0; i < s1; i++){
        n_string[i] = string1[i];
    }

    for (int i = 0; i < s2; i++){
        n_string[i + s1] = string2[i];
    }

    n_string[s1 + s2] = '\0';

    printf("String: %s\n", n_string);
    printf("Tamanho: %ld", strlen(n_string));
}