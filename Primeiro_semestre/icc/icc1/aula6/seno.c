#include <stdio.h>

int main() {
    double x;
    scanf("%lf", &x);
    double seno = x;
    int sinal = -1;
    double op = x;
    for(int i = 2; i <= 100; i+=2) {
        op *= ((x * x) / (i * (i + 1)));
        seno += sinal * op;
        sinal *= -1;
    }
    printf("%.6lf\n", seno);
    return 0;
}