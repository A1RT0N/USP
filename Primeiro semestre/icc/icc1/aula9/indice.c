#include <stdio.h>

void fillvec(int *new_vec, int n) {
    for(int i = 0; i < n; i++) {
        scanf("%d", &new_vec[i]);
    }
}

int sumup(int *vec, int a, int b) {
    int sum = 0;
    for(int i = a; i < b; i++)
        sum += vec[i];

    return sum;
}

int findindex(int *vec, int n) {
    for(int i = 0; i < n; i++) {
        int first = sumup(vec, 0, i);
        int second = sumup(vec, i + 1, n);
        if(first == second) {
            return i;
        }
    }
    return -1;
}

int main() {
    int n;
    scanf("%d", &n);
    int vec[n];
    fillvec(vec, n);
    printf("%d\n", findindex(vec, n));
    return 0;
}