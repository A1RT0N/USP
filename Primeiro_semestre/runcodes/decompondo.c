
#include <stdio.h>
#include <math.h>

int main()
{
    int numero; 
    int cem, cinq, vint, dez, cinc, dois, um;
    scanf("%d", &numero);
    cem = numero/100;
    numero = numero%100;
    cinq = numero/50;
    numero -= 50*cinq;
    vint = numero/20;
    numero -= 20*vint;
    dez = numero/10;
    numero -= 10*dez;
    cinc = numero/5;
    numero -= cinc*5;
    dois = numero/2;
    numero -= dois*2;
    um = numero;
    printf("%d nota(s) de R$ 100\n%d nota(s) de R$ 50\n%d nota(s) de R$ 20\n%d nota(s) de R$ 10\n%d nota(s) de R$ 5\n%d nota(s) de R$ 2\n%d moeda(s) de R$ 1\n", cem, cinq, vint, dez, cinc, dois, um);
    
    
    
    return 0;
}
