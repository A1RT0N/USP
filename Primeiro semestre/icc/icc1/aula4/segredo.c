#include <stdio.h>

int main() {
    int input;

    scanf("%d", &input);
    char a, b, c, d;

    a = input >> 24;
    b = (input >> 16) ^ (a << 8);
    c = (input >> 8) ^ (b << 8);
    d = input ^ (c << 8);

    printf("%c%c%c%c\n", a, b, c, d);

    return 0;
}