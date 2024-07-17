#include <stdio.h>

int main() {
    int times = 0;
    int num;

    scanf("%d", &num);

    for(int factor = 2; factor <= num; factor++) {
        while(num % factor == 0) {
            times++;
            num /= factor;
        }
        if(times != 0){
            printf("%d %d \n", factor, times);
            times = 0;
        }
    }
    return 0;
}
