#include <stdio.h>

int binario(int x){
    int contador = 0;
    for (int i = x; i>0; i/=2){
        if (i%2 == 1) contador++;
    }
    return contador;
}

int main()
{
    int a,b,c, resposta = 0;
    scanf("%d %d", &a, &b);
    c = a^b;
    resposta = binario(c);
    printf("%d", resposta);
    
    return 0;
}
