#include <stdio.h>
#include <math.h>

int main()
{
    float const pi = 3.14;
    char c;
    float lado_raio_base, altura, area;
    scanf(" %c", &c);
    switch(c)
    {
        case 'q':{
            scanf("%f", &lado_raio_base);
            area = lado_raio_base*lado_raio_base;
            printf("%.2f", area);
            break;
        }
        case 'r': {
            scanf("%f %f", &lado_raio_base, &altura);
            area = lado_raio_base*altura;
            printf("%.2f", area);
            break;
        }
        case 't':{
            scanf("%f %f", &lado_raio_base, &altura);
            area = (lado_raio_base*altura)/2;
            printf("%.2f", area);
            break;
        }
        case 'c': {
            scanf("%f", &lado_raio_base);
            area = pi*lado_raio_base*lado_raio_base;
            printf("%.2f", area);
            break;
        }
    }
    
    return 0;
}
