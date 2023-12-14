/*exercício 1 (aula 17/08/2023)*/
#include <stdio.h>
#include <string.h>

int strtoint(char *string, int base) {
    int num = 0;
    int basenumerica = 1;

    for (int i = (strlen(string)-1); i >= 0; i--) {
        num += (string[i] - '0') * basenumerica;
        basenumerica *= base; 
    }

    return num;
}

int main() {

    char numerodigitado[100];
    int base;
    
    scanf("%s", numerodigitado);
    scanf("%d", &base);


    int n;

    n = strtoint(numerodigitado, base);

    printf("%d\n", n);

    return 0;
}