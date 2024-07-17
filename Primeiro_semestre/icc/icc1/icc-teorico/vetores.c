#include <stdio.h>

int main() {
    int s_x, s_y;
    scanf("%d %d", &s_x, &s_y);
    int x[s_x], y[s_y];
    if(s_x != 0) {
        for(int i = 0; i < s_x; i++) {
            scanf("%d", &x[i]);
        }
    }
    if(s_y != 0) {
        for(int i = 0; i < s_y; i++) {
            scanf("%d", &y[i]);
        }
    }
    if(s_x > s_y) {
        for(int i = 0; i < s_y; i++) {
            printf("%d ", x[i]);
            printf("%d ", y[i]);
        }
        for(int i = s_y; i < s_x; i++) {
            printf("%d ", x[i]);
        }
    } else if (s_x < s_y) {
        for(int i = 0; i < s_x; i++) {
            printf("%d ", x[i]);
            printf("%d ", y[i]);
        }
        for(int i = s_x; i < s_y; i++) {
            printf("%d ", y[i]);
        }
    } else {
        for(int i = 0; i < s_y; i++) {
            printf("%d ", x[i]);
            printf("%d ", y[i]);
        }
    }
    return 0;
}