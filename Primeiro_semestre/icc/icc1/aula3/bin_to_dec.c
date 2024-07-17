#include <stdio.h>

int main() {
    int bin = 0;
    scanf("%d", &bin);
    int dig1 = bin % 2;
    int dig2 = (bin / 10) % 2;
    int dig3 = (bin / 100) % 2;
    int dig4 = (bin / 1000) % 2;

    //printf("%d\n%d\n%d\n%d\n", dig1, dig2, dig3, dig4);

    double res = dig1 + dig2 * 2 + dig3 * 4 + dig4 * 8;

    printf("%d\n", (int)res);
    return 0;
}