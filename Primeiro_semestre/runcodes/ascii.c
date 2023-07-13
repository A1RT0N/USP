#include <stdio.h> 


int main()
{
    // ler os 2 valores: inteiro e um caracter
    int numero; // 
    char c;
    scanf(" %d %c", &numero, &c); // % = conversor -- o %i faz a mesma coisa para int -- * = ponteiro
    // printf("O valor inteiro é = %d e o caracter é = %c \n", numero, c); // o print é uma string e cada % vai transformar um int, por exemplo, em string. 
    printf("Inteiro lido: %d \nCodigo hexadecimal: %x\nCaractere ASCII: %c\n", numero, numero, numero);
    printf("\n");
    printf("Inteiro lido: %d \nCodigo hexadecimal: %x\nCaractere ASCII: %c\n", c, c, c);
    return 0;
}
