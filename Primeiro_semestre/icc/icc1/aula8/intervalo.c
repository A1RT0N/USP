#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    int vec[n];
    int a, b;
    int sum = 0;
    for(int i = 0; i < n; i++) {
        scanf("%d", &vec[i]);
    }
    scanf("%d %d", &a, &b);
    for(int i = a; i <= b; i++) {
        sum += vec[i];
    }
    printf("%d\n", sum);
    return 0;
}