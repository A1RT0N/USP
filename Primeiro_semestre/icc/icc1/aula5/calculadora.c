#include <stdio.h>

int main(void) {
    const double PI = 3.14;
    
    char shape;
    scanf("%c", &shape);
    
    switch (shape)
    {
        double l1, l2;
    case 'q':
        scanf("%lf", &l1);
        l2 = l1;
        printf("%.2lf\n", l1 * l2);
        break;
    case 'r':
        scanf("%lf %lf", &l1, &l2);
        printf("%.2lf\n", l1 * l2);
        break;
    case 't':
        scanf("%lf %lf", &l1, &l2);
        printf("%.2lf\n", l1 * l2 * 1/2);
        break;    
    case 'c':
        scanf("%lf", &l1);
        l2 = l1;
        printf("%.2lf\n", l1 * l2 * PI);
        break;
    
    default:
        break;
    }

    return 0;
}