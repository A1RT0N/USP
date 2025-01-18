#include <stdio.h>

int main() {
    int n;
    double q, a1;
    scanf("%d", &n);
    scanf("%lf %lf", &a1, &q);
    double pa = a1, pg = a1;
    printf("PA:");
    for(int i = 0; i < n; i++) {
        printf(" %.3lf", pa);
        pa += q;
    }
    printf("\n");
    printf("PG:");

    for(int i = 0; i < n; i++) {
        printf(" %.3lf", pg);
        pg *= q;
    }
    printf("\n");

    return 0;
}