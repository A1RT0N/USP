#include <stdio.h>

int main() {
    int q100 = 0;
    int q50 = 0;
    int q20 = 0;
    int q10 = 0;
    int q5 = 0;
    int q2 = 0;
    int q1 = 0;

    int entry;

    scanf("%d", &entry);

    while (entry > 0) {
        if (entry >= 100) {
            entry -= 100;
            q100++;
        } else if (entry >= 50) {
            entry -= 50;
            q50++;
        } else if (entry >= 20) {
            entry -= 20;
            q20++;
        } else if (entry >= 10) {
            entry -= 10;
            q10++;
        } else if (entry >= 5) {
            entry -= 5;
            q5++;
        } else if (entry >= 2) {
            entry -= 2;
            q2++;
        } else if (entry >= 1) {
            entry -= 1;
            q1++;
        }
    }

    printf("%i nota(s) de R$ 100\n", q100);
    printf("%i nota(s) de R$ 50\n", q50);
    printf("%i nota(s) de R$ 20\n", q20);
    printf("%i nota(s) de R$ 10\n", q10);
    printf("%i nota(s) de R$ 5\n", q5);
    printf("%i nota(s) de R$ 2\n", q2);
    printf("%i moeda(s) de R$ 1\n", q1);

    return 0;
}