#include <stdio.h>

void funcao(int n,int aux,int v[]){
    int flag = 0;
    
    for (int j = 0; j<n; j++){
        flag = 0;
        for (int k = 0; k<n-1; k++){
            if (v[k+1]<v[k]){
                aux = v[k];
                v[k] = v[k+1];
                v[k+1] = aux;
                flag = 1;
            }
        }
        if(flag == 0) break;
    }
}

int main()
{
    int n=0, aux = 0;
    scanf("%d", &n);
    int v[n];
    
    for (int i =0; i< n-1; i++){
        scanf("%d", &v[i]);
    }
    
    funcao(n-1,aux,v);

    int atual = 1, resposta;
    for (int a =0; a<n; a++){
        if (atual != v[a]){
            resposta = atual;
            break;
        }
        atual++;
    }
    printf("Numero desaparecido: %d", resposta);

    return 0;
}



