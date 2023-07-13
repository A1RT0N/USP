#include <stdio.h>

int main()
{
    int n, contador = 0, atual, maior_n, verdadeiro = 1;
    scanf("%d", &n);
    for (int i = 0; i<n; i++){
        scanf("%d", &atual);
        for (int a = 1; a<=atual; a++){
            if(atual%a == 0){
                contador++;
            }
        }
        maior_n = contador;
        contador = 0;
        // printf("%d\n",maior_n);
        for (int b = atual-1; b>=1; b--){
            for(int c = 1; c<=b; c++){
                if (b%c == 0){
                    contador++;
                }
            }
            if (maior_n <= contador){
                verdadeiro = 0;
            }
            contador = 0;

        }
        if (verdadeiro){
            printf("SIM\n");
        } else{
            printf("NAO\n");
        }
        verdadeiro = 1;
    }
    

    return 0;
}

/*Um número anti-primo (também conhecido como altamente composto) é um número inteiro positivo 
que tem mais divisores do que qualquer outro número inteiro menor que ele. 
Por exemplo, 12 é um número anti-primo porque tem 6 divisores (1, 2, 3, 4, 6 e 12), 
mais do que qualquer número inteiro menor que ele.
Faça um programa em C que recebe um número inteiro positivo N como entrada, 
seguido por N números inteiros positivos. 
O programa deve verificar se cada um dos N números é um número anti-primo e exibir o resultado 
correspondente.
O programa deve imprimir "SIM" se o número for um número anti-primo e "NAO" caso contrário.
*/