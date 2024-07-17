#include <stdio.h>

int main() {
    int n;
    int eh_primo = 1;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        int primo;
        eh_primo = 1;
        scanf("%d", &primo);
        for(int j = 2; j < primo; j++) {
            if(primo % j == 0) {
                eh_primo = 0;
                break;
            }
        }
        if(eh_primo) {
            printf("%d eh primo.\n", primo);
        } else {
            printf("%d nao eh primo, ", primo);
            while(!eh_primo) {
                primo++;
                for(int k = 2; k < primo; k++) {
                    if(primo % k == 0) {
                        eh_primo = 0;
                        break;
                    }
                    if(k == primo - 1){
                        eh_primo = 1;
                    }
                }
            }
            printf("o proximo primo eh %d.\n", primo);
        }
    }

    return 0;
}