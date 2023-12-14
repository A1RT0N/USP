#include <stdio.h>

struct sequencia{
    int index_ini;
    int index_fim;
    int valor;
};

typedef struct sequencia seq;

seq sub(int *v, int n, seq melhor, int i, int soma, int index_init){
    if (i == n){
        return melhor;
    }

    soma += v[i];
    
    if (soma > (melhor.valor)){
        seq melhor_atual;
        
        melhor_atual.index_ini = index_init;
        melhor_atual.index_fim = i;
        melhor_atual.valor = soma;

        melhor = melhor_atual;
    }

    return sub(v, n, melhor, i + 1, soma, index_init);
}

int main(void){
    int n;

    scanf("%d", &n);

    int v[n];

    seq melhor;

    melhor.valor = -1000;

    for (int i = 0; i < n; i++){
        scanf("%d", &v[i]);
    }


    for (int i = 0; i < n; i++){
        seq tmp;

        tmp = sub(v, n, melhor, i , 0, i);

        if (tmp.valor > melhor.valor){
            melhor = tmp;
        }
    }

    printf("%d\n", melhor.valor);
    printf("maior sub: ");

    for (int i = melhor.index_ini; i <= melhor.index_fim; i++){
        printf("%d ", v[i]);
    }

    printf("\n");
}   