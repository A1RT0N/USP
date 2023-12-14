#include <stdio.h>

void recursao(int *vet1, int tam1, int *vet2, int tam2, int *res) {
    if (tam2 == 0 && tam1 == 0) {
        return;
    }
    if (tam2 == 0 || (tam2>0 && vet1[tam1 - 1] > vet2[tam2 - 1])) {
        res[tam1+tam2 - 1] = vet1[tam1 - 1];
        recursao(vet1, tam1 - 1, vet2, tam2, res);
    } else {
        res[tam1+tam2 - 1] = vet2[tam2 - 1];
        recursao(vet1, tam1, vet2, tam2 - 1, res);
    }
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    int vet1[n];
    int vet2[m];
    int vet3[n + m];

    for (int i = 0; i < n; i++) {
        scanf("%d", &vet1[i]);
    }
    for (int i = 0; i < m; i++) {
        scanf("%d", &vet2[i]);
    }

    
    recursao(vet1, n, vet2, m, vet3);

    for (int k = 0; k < n + m; k++) {
        printf("%d ", vet3[k]);
    }

    return 0;
}
