#include <stdio.h>

void antecessor(int n) {
    if(n < 0) {
        return;
    }

    antecessor(n - 1);
    printf("%d\n", n);
}

int main() {
    int n;
    scanf("%d", &n);

    antecessor(n);
    return 0;
}