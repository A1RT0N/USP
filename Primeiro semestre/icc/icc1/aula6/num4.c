#include <stdio.h>

int main() {
    for(int i = 1000; i < 10000; i++) {
        int final = i % 100;
        int inicial = i / 100;
        int soma = final + inicial;
        if(i == soma * soma) {
            printf("%d\n", i);
        }
    }
    return 0;
}