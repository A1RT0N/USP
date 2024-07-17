#include <stdio.h>
#include <math.h>

int main() {
    double a, b, c;
    scanf("%lf %lf %lf", &a, &b, &c);
    
    printf("Media aritimetica: %.4lf\n", (a + b + c) / 3);
    printf("Media harmonica: %.4lf\n", 3 / (1/a + 1/b + 1/c));
    printf("Media geometrica: %.4lf\n", cbrt(a * b * c));

    return 0;
}