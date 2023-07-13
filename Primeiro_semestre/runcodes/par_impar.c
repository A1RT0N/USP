#include <stdio.h>

int main()
{
    int a, b, soma, num_jog1, num_jog2;
    char jog1[10], jog2[10];
    scanf("%s %s", jog1,jog2);
    scanf("%d", &a);
    scanf("%d", &b);
    for (int i = 0; i<b; i++){
        scanf("%d %d", &num_jog1, &num_jog2);
        soma = num_jog2 +num_jog1;
        if (soma == 0){
            printf("Refazendo a rodada\n");
            i--;
        } else{
            if (soma%2 == 0){
                if (a == 0){
                    printf("%s venceu!\n", jog1);
                } else{
                    printf("%s venceu!\n", jog2);
                }
            } else{
                if (a == 0){
                printf("%s venceu!\n", jog2);
            } else{
                printf("%s venceu!\n", jog1);
            }
            }
        
        }
    }
    
    return 0;
}