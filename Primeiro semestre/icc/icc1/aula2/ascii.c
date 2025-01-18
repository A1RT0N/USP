#include <stdio.h>

int main() {
    int n;
    char c;

    // atribuicao de variaveis
    scanf("%d %c", &n, &c);
    
    // imprime o primeiro valor
    printf("Inteiro lido: %d\n", n);
    printf("Codigo hexadecimal: %x\n", n);
    printf("Caractere ASCII: %c\n", n);

    printf("\n");

    // imprime o segundo valor
    printf("Inteiro lido: %d\n", c);
    printf("Codigo hexadecimal: %x\n", c);
    printf("Caractere ASCII: %c\n", c);

    return 0;
}