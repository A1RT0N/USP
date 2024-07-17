#include <stdio.h>

int fib(int n) {
    if(n == 1)
        return 0;
    else if(n == 2 || n == 3)
        return 1;

    return(fib(n - 1) + fib(n - 2));
}

int main() {
    int n, r;
    scanf("%d", &n);

    for(int i = 1; i <= n; i++) {
        r = fib(i);
        if(i != n)
            printf("%d; ", r);
        else
            printf("%d\n", r);
    }

    return 0;
}