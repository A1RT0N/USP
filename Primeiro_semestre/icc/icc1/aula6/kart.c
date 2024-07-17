#include <stdio.h>

int main() {
    int n;

    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        double a, b, t;
        scanf("%lf %lf %lf", &a, &b, &t);
        double d_a, d_b;
        d_a = a * t;
        d_b = b * t;

        if(t == 0) {
            printf("A corrida ainda nao comecou\n");
            continue;
        }
        if(a == 0 && b != 0) {
            printf("O piloto A desistiu inesperadamente\n");
            continue;
        } else if(a != 0 && b == 0) {
            printf("O piloto B desistiu inesperadamente\n");
            continue;
        } else if(b == 0 && a == 0) {
            printf("Os dois pilotos nao querem competir\n");
            continue;
        }
        if (t < 0) {
            printf("De alguma forma os pilotos voltaram no tempo\n");
            continue;
        }
        if(d_a > d_b) {
            printf("O kart A venceu e percorreu %.2lfkm a mais que o kart B\n", d_a - d_b);
            continue;
        } else if(d_a < d_b) {
            printf("O kart B venceu e percorreu %.2lfkm a mais que o kart A\n", d_b - d_a);
            continue;
        } else {
            printf("Os karts empataram, percorrendo cada %.2lfkm\n", d_a);
            continue;
        }

    }
    
    return 0;
}