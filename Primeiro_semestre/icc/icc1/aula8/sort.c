#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    int vec[n];
    for(int i = 0; i < n; i++) {
        scanf("%d", &vec[i]);
    }
    for(int i = 0; i < n; i++) {
        int temp;
        for(int j = i + 1; j < n; j++) {
            if(vec[i] > vec[j]) {
                temp = vec[j];
                vec[j] = vec[i];
                vec[i] = temp;
            }
        }
    }
    for(int i = 0; i < n; i++) {
        printf("%d ", vec[i]);
    }
    printf("\n");
    return 0;
}