#include <stdio.h>
#include <stdlib.h>

typedef struct 
{
    int numerador;
    int denominador;
}fracao;

void soma(int a, int b, int c, int d, fracao resultado){
    resultado.denominador = b *d;
    resultado.numerador = a*d +b*c;
    printf("%d/%d", resultado.numerador, resultado.denominador);
}

int main(int argc, char *argv[]){
    if (argc != 4){
        printf("Errada formatação. Certo:./fracao a/b + c/d");
        exit(1);
    }
    
    int a = argv[1][0] - '0';
    int b = argv[1][2] - '0';
    int c = argv[3][0] - '0';
    int d = argv[3][2] - '0';
    fracao resultado;

    soma(a,b,c,d, resultado);
    return 0;
}