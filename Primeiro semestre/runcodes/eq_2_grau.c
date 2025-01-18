#include <stdio.h>
#include <math.h>

int main()
{
    float a,b,c,det, x1, x2;
    scanf("%f %f %f", &a, &b, &c);
    det = (b)*(b) - 4*(a)*(c);
    if (det < 0){
        printf("NAO EXISTE RAIZ REAL");
    } else{
        if (det ==0){
            x1 = (-b)/(2*a);
            printf("%.3f", x1);
        } else{
            x1 = (-b+sqrt(det))/(2*a);
            x2 = (-b-sqrt(det))/(2*a);
            if (x1 > x2){
                printf("%.3f %.3f", x2, x1);
            } else{
                printf("%.3f %.3f", x1, x2);
            }
        }
    }
    
    

    return 0;
}
