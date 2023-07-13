#include <stdio.h>
#include <math.h>
int hipotenusa(int a, int b);
float diagonal(int a, int b, int c);

int hipotenusa(int a, int b){
    int c = a*a + b*b;
    return c;
}

float diagonal(int a, int b, int c){
    int d = hipotenusa(a,b);
    int e = d + c*c;
    float res = sqrt(e);
    return res;
}


int main()
{
    int a,b,c;
    scanf("%d %d %d", &a, &b, &c);
    printf("%f",diagonal(a,b,c));
    

    return 0;
}