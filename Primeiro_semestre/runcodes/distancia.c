#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
    float x1,x2,y1,y2,dist_eucl,dist_manh;
    scanf("%f%f%f%f",&x1,&y1,&x2,&y2);
    dist_eucl = sqrt(pow(fabs(x1-x2),2)+ pow(fabs(y1-y2),2));
    dist_manh = fabs(x1-x2)+fabs(y1-y2);
    printf("Distancia euclidiana: %.3f\nDistancia Manhattan: %.3f\n", dist_eucl, dist_manh);
    
    

    return 0;
}