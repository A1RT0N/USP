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

#include <stdio.h>

int main(void) {
    int num, n, c = 1, b_c = 1, b_num;
    scanf("%d", &n);
    for(int k = 0; k < n; k++) {
        scanf("%d", &num);
        b_num = num;

        for(int j = num; j > 0; j--) {
            for(int i = 1; i < j; i++) {
                if(j % i == 0) 
                    c++;
            }
            if(c >= b_c) {
                b_c = c;
                b_num = j;
            }
            c = 1;
        }
        b_c = 1;
        if(b_num != num) {
            printf("%s", "NAO\n");
            
        } else {
            printf("%s", "SIM\n");
        }
    }
    return 0;
}