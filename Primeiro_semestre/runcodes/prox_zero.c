#include <stdio.h>
#include <stdlib.h>
#include <limits.h>


int main()
{
    int n, *p, resposta = INT_MAX, v[100], cont = 0;
    scanf("%d", &n);
    
    p = (int*)calloc(n,sizeof(int));
    if (p == NULL){
        exit(1);
    }
    
    for (int i =0; i<n;i++){
        scanf("%d",&p[i]);
        if(abs(p[i]) < abs(resposta)){
            
            resposta = p[i];

        }
    }
    
    for (int i =0; i<n;i++){
        if(abs(p[i]) == abs(resposta)){
            v[cont] = i;
            cont++;
        }
    }
    
    
    free(p);
    p = NULL;
    
    printf("%d\n", resposta);
    for (int j =0; j<cont; j++){
        printf("%d ", v[j]);
    }
    
    return 0;
}
