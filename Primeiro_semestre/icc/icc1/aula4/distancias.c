#include <stdio.h>
#include <math.h>

int main() {
    double a, b;
    double x, y;

    scanf("%lf %lf", &a, &b);
    scanf("%lf %lf", &x, &y);

    double dist_euc = sqrt(powl(x - a, 2) + powl(y - b, 2));
    double dist_man = fabs(x - a) + fabs(y - b);

    printf("Distancia euclidiana: %.3lf\n", dist_euc);
    printf("Distancia Manhattan: %.3lf\n", dist_man);

    return 0;
}