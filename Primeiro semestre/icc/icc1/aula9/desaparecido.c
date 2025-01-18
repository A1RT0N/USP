#include <stdio.h>

int acc_vec(int *vec, int n);
int sum_pa(int n);

int sum_pa(int n) {
    int pa = 0;
    for(int i = 1; i <= n; i++) {
        pa += i;
    }
    return pa;
}

int acc_vec(int *vec, int n) {
    int acc = 0;
    for(int i = 0; i < n; i++) {
        acc += vec[i];
    }
    return acc;
}
 
int main() {
    int n;
    scanf("%d", &n);
    int vec[n - 1];

    for(int i = 0; i < n - 1; i++) {
        scanf("%d", &vec[i]);
    }
    int acc_v = acc_vec(vec, n - 1);
    int sum = sum_pa(n);

    printf("Numero desaparecido: %d\n", sum - acc_v);

    return 0;
}