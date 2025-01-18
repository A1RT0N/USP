#include <stdio.h>

int main(void) {
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);

    if(a < b + c && b < a + c && c < a + b) {
        if(a == b && b == c) {
            printf("EQUILATERO\n");
        } else if(a == b || b == c || a == c) {
            printf("ISOSCELES\n");
        } else {
            printf("ESCALENO\n");
        }
    } else {
        printf("INVALIDO\n");
    }
    return 0;
}