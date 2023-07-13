#include <stdio.h>
#include <math.h>
int main(){
    int numero;
    scanf("%d", &numero);
    int resposta = 0;
    int a = numero/1000;
    resposta += a*pow(2,3);
    numero = numero%1000;
    int b = numero/100;
    resposta += b*pow(2,2);
    numero = numero%100;
    int c = numero/10;
    resposta += c*pow(2,1);
    numero = numero%10;
    resposta += numero*pow(2,0);
    printf("%d", resposta);
    return 0;   
}