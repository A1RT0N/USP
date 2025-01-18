#include <stdio.h>

int main() {
    long a, b, c, x;
    scanf("%ld %ld %ld %ld", &a, &b, &c, &x);

    printf("%ld\n", a * x * x + b * x + c);
    return 0;
}