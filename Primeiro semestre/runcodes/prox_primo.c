#include <stdio.h>

int primo(int k){
    int contador = 0;
    for(int a = 2; a<k; a++){
        if (k%a == 0){
            contador++;
        }
    }
    if (contador > 0){
        return 1;
        
    } else{
        return 0;
    }
    
    
    
}



int main()
{
    int a, analise;
    scanf("%d", &a);
    int v[a];
    for (int i = 0; i<a; i++){
        scanf("%d", &v[i]);
    }
    for (int i = 0; i<a; i++){
        if (primo(v[i]) == 0){
            printf("%d eh primo.\n", v[i]);
        } else{
            analise = v[i];
            while (primo(analise) != 0){
                analise++;
            }
            printf("%d nao eh primo, o proximo primo eh %d.\n", v[i], analise);
        }
        
    }
    

    return 0;
}
