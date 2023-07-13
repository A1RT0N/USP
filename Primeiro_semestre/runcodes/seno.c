#include <stdio.h>

double fatorial(double b){
    double fat = 1;
    for(fat = 1; b > 1; b = b - 1){
        fat = fat * b;
    }

    return fat;
}
double elevado(double a, double b){
    double resposta = 1;
    for (int i =0; i<b; i++){
        resposta *= a;
    }
    return resposta;
}

int main()
{
    double n, resposta = 0;
    scanf("%lf", &n);
    for (int i = 1; i < 500; i+=4){
        resposta += elevado(n,i)/fatorial(i);
    }
    for (int i = 3; i<300; i+=4){
        resposta -= (double) elevado(n,i)/fatorial(i);
    }
    
    printf("%.6lf", resposta);


    return 0;
}
