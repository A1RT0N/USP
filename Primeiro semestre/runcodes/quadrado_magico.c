#include <stdio.h>
#include <stdlib.h>

void alocarentrada(int ***p, int ***q, int a) {
    *p = (int **)malloc(sizeof(int *) * a);
    for (int i = 0; i < a; i++) {
        (*p)[i] = (int *)malloc(sizeof(int) * a);
    }

    *q = (int **)malloc(sizeof(int *) * a);
    for (int i = 0; i < a; i++) {
        (*q)[i] = (int *)malloc(sizeof(int) * a);
    }

    for (int i = 0; i < a; i++) {
        for (int j = 0; j < a; j++) {
            scanf("%d", &((*p)[i][j]));
        }
    }

    for (int i = 0; i < a; i++) {
        for (int j = 0; j < a; j++) {
            scanf("%d", &((*q)[i][j]));
        }
    }
}

int magico(int **p, int a) {
    int contador = 0;
    int numero;
    int flag = 1;

    for (int i = 0; i < a; i++) {
        contador += p[0][i];
    }
    numero = contador;
    contador = 0;

    for (int i = 0; i < a; i++) {
        for (int j = 0; j < a; j++) {
            contador += p[i][j];
        }
        if (contador != numero) {
            flag = 0;
            break;
        }
        contador = 0;
    }

    for (int i = 0; i < a; i++) {
        contador += p[i][i];
    }

    if (contador != numero) {
        flag = 0;
    }

    return flag;
}

void freemat(int **p, int lin) {
    for (int i = 0; i < lin; i++) {
        free(p[i]);
    }
    free(p);
}

int main() {
    int a;
    int **p, **q;

    scanf("%d", &a);

    alocarentrada(&p, &q, a);

    if (magico(p, a) == 1) {
        printf("SIM\n");
    } else {
        printf("NAO\n");
    }

    freemat(p, a);
    freemat(q, a);

    return 0;
}
