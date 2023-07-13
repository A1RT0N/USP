#include <stdio.h>

void entrada(int linha, int coluna, char matriz[][coluna]) {
    for (int i = 0; i < linha; i++) {
        for (int j = 0; j < coluna; j++) {
            scanf(" %c", &matriz[i][j]);
        }
    }
}

void modificar(int linha, int coluna, char matriz[][coluna], char resultado[][coluna]) {
    for (int i = 0; i < linha; i++) {
        for (int j = 0; j < coluna; j++) {
            if (matriz[i][j] == 'c') {
                for (int a = 0; a < linha; a++) {
                    resultado[a][j] = 'x';
                }
                for (int b = 0; b < coluna; b++) {
                    resultado[i][b] = 'x';
                }
            } else {
                if (matriz[i][j] == 'f') {
                    resultado[i][j] = 'x';
                }
            }
        }
    }
    int contador = 0;
    for (int i = 0; i < linha; i++) {
        for (int j = 0; j < coluna; j++) {
            if (resultado[i][j] != 'x') {
                resultado[i][j] = 'o';
                contador++;
            }
        }
    }
    if (contador == 0) {
        printf("Eh um dia triste para os mono Yasuo\n");
    } else {
        for (int i = 0; i < linha; i++) {
            for (int j = 0; j < coluna; j++) {
                printf("%c ", resultado[i][j]);
            }
            printf("\n");
        }
    }
}

int main() {
    int linha, coluna;
    scanf("%d %d", &linha, &coluna);
    char matriz[linha][coluna];
    char resultado[linha][coluna];

    entrada(linha, coluna, matriz);

    modificar(linha, coluna, matriz, resultado);

    return 0;
}
