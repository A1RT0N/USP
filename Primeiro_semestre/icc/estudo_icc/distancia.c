#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    int x, y, z;
} Ponto;

int main(int argc, char *argv[]) {
    Ponto p1, p2;

    if (argc != 7) {
        printf("Erro de formatação. O correto é: ./distancia a b c i j k\n");
        exit(1);
    }

    p1.x = atoi(argv[1]);
    p1.y = atoi(argv[2]);
    p1.z = atoi(argv[3]);
    p2.x = atoi(argv[4]);
    p2.y = atoi(argv[5]);
    p2.z = atoi(argv[6]);

    double distancia = sqrt(
        pow(abs(p1.x - p2.x), 2) +
        pow(abs(p1.y - p2.y), 2) +
        pow(abs(p1.z - p2.z), 2)
    );

    printf("Distância relativa: %lf\n", distancia);

    return 0;    
}
