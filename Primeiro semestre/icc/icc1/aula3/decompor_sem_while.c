#include <stdio.h>

int main() {
    int valor = 0;
    scanf("%i", &valor);
    int q100 = valor / 100;
    valor -= 100 * q100;

    int q50 = valor / 50;
    valor -= 50 * q50;
    
    int q20 = valor / 20;
    valor -= 20 * q20;

    int q10 = valor / 10;
    valor -= 10 * q10;

    int q5 = valor / 5;
    valor -= 5 * q5;

    int q2 = valor / 2;
    valor -= 2 * q2;

    int q1 = valor / 1;
    valor -= 1 * q1;

    printf("%i nota(s) de R$ 100\n", q100);
    printf("%i nota(s) de R$ 50\n", q50);
    printf("%i nota(s) de R$ 20\n", q20);
    printf("%i nota(s) de R$ 10\n", q10);
    printf("%i nota(s) de R$ 5\n", q5);
    printf("%i nota(s) de R$ 2\n", q2);
    printf("%i moeda(s) de R$ 1\n", q1);

    return 0;
}