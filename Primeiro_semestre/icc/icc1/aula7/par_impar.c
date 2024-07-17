#include <stdio.h>

int main() {
    char nome1[10];
    char nome2[10];

    scanf("%s %s", nome1, nome2);

    int par_impar;
    scanf("%d", &par_impar);

    int rodadas;
    scanf("%d", &rodadas);
    for(int i = 0; i < rodadas; i++) {
        int a, b;
        scanf("%d %d", &a, &b);

        if(b == 0 && a == 0) {
            i--;
            printf("Refazendo a rodada\n");
            continue;
        }

        if((a + b) % 2 == par_impar) {
            printf("%s venceu!\n", nome1);
        } else {
            printf("%s venceu!\n", nome2);
        }
    }

    return 0;
}