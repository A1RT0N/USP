#include <stdio.h>
#include <math.h>

int main(void){
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);

    double delta = (pow(b, 2)) - (4 * a * c);
    if(delta < 0){
        printf("NAO EXISTE RAIZ REAL\n");
        return 0;
    }
    double x1, x2;
    x1 = (-b + sqrt(delta)) / (2 * a);
    x2 = (-b - sqrt(delta)) / (2 * a);
    if(delta == 0){
        printf("%.3lf\n", x1);
    } else {
        if(x1 < x2)
            printf("%.3lf %.3lf\n", x1, x2);
        else
            printf("%.3lf %.3lf\n", x2, x1);
    }

    return 0;
}
