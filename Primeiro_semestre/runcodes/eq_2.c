
#include <stdio.h>
#include <math.h>
int main()
{
    long long int a, b,c,x;
    scanf("%lld %lld %lld %lld", &a, &b, &c, &x);
    long long int ax2 = a*pow(x,2);
    long long int bx = b*x;
    long long int soma = ax2+bx+c;
    printf("%lld", soma);
    
}
