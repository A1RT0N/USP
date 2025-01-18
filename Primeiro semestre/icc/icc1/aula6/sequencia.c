#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    double sum = 0;

    for (int i = 1; i <= n; i++) {
        if (i % 2 == 0) {
            sum -= 1.0 / i;
        } else {
            sum += 1.0 / i;
        }
    }

    printf("%.4lf\n", sum);
    return 0;
}