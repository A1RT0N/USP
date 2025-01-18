#include <stdio.h>
#include <math.h>
int main(){
    double n;
    double resultado = 0;
    scanf("%lf", &n);
    for (double i = 1; i<=n; i+=2){
        resultado += (1/i);
    }
    for (double i = 2; i<=n; i+=2){
        resultado -= (1/i);
    }
    printf("%.4lf", resultado);
}
