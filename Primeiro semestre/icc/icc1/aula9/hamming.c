/*
    6 2
    110  010
    1

    5 6 
    101 110 
    2

    5 2
    101 010
    3

*/
#include <stdio.h>

int main() {
    int a, b, c, k = 0;
    scanf("%d %d", &a, &b);
    c = a ^ b;

    while(c > 0) {
        if(c % 2 == 1)
            k++;
        c /= 2;
    } 
    printf("%d\n", k);
    return 0;
}