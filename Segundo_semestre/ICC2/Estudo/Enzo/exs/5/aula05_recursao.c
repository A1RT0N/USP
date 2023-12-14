#include <stdio.h>

void ler(int *v, int n){
    for (int i = 0; i < n; i++){
        scanf("%d", &v[i]);
    }
}

void mostrar(int *v, int n){
    for (int i = 0; i < n; i++){
        printf("%d ", v[i]);
    }

    printf("\n");
}

void concatenar(int *v1, int *v2, int *v3, int n1, int n2){
    if (!n1 && !n2) return;

    if (!n1 && n2){
        v3[n1 + n2 - 1] = v2[n2 - 1];

        concatenar(v1, v2, v3, n1, n2 - 1);
    }
    else if (n1 && !n2){
        v3[n1 + n2 - 1] = v1[n1 - 1];

        concatenar(v1, v2, v3, n1 - 1, n2);
    } else{
        if (v1[n1 - 1] > v2[n2 - 1]){
            v3[n1 + n2 - 1] = v1[n1 - 1];

            concatenar(v1, v2, v3, n1 - 1, n2);
        } else{
            v3[n1 + n2 - 1] = v2[n2 - 1];

            concatenar(v1, v2, v3, n1, n2 - 1);
        }
    }

    
}

int main(void){
    int n1, n2;

    scanf("%d %d", &n1, &n2);

    int v1[n1], v2[n2], v3[n1 + n2];

    ler(v1, n1);
    ler(v2, n2);

    mostrar(v1, n1);
    mostrar(v2, n2);

    concatenar(v1, v2, v3, n1, n2);

    mostrar(v3, n1 + n2);
}