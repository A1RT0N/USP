#include <stdio.h>

int main() {
    int layers;
    scanf("%d", &layers);

    for(int i = 0; i < layers; i++) {
        for(int j = 0; j < layers - i - 1; j++) {
            printf("%c", ' ');
        }
        for(int j = 0; j < i + 1; j++) {
            printf("%c%c", '*', '*');
        }
        printf("\n");
    }
    return 0;
}