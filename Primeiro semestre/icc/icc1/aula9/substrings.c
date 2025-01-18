#include <stdio.h>
#include <string.h>

void count_substring(char frase[], char palavra[]);

void count_substring(char frase[], char palavra[]) {
    char *res;
    int found = 0;
    while((res = strstr(frase, palavra)) != NULL) {
        found = 1;
        int rs = res - frase;
        frase[rs] = '\a';
        printf("A sub string foi encontrada na posicao = %d\n", rs);
    }

    if(!found)
        printf("A sub string nao foi encontrada\n");
}

int main() {
    char frase[1000];
    char palavra[1000];
    scanf("%[^\n]", frase);
    scanf(" %[^\n]", palavra);

    count_substring(frase, palavra);
    
    return 0;
}