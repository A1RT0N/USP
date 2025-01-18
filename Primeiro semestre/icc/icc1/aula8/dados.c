#include <stdio.h>

int main() {
    int num = 0;
    int q[6] = {0, 0, 0, 0, 0, 0};
    int largest = 0;
    while(scanf("%d", &num) != EOF) {
        switch(num) {
            case 1:
                q[0]++;
                break;
            case 2:
                q[1]++;
                break;
            case 3:
                q[2]++;
                break;
            case 4:
                q[3]++;
                break;
            case 5:
                q[4]++;
                break;
            case 6:
                q[5]++;
                break;
        }
    }

    for(int i = 0; i < 6; i++) {
        if(q[i] > q[largest]) {
            largest = i;
        }
    }
    for(int i = 0; i < 6; i++) {
        /*printf("---\n");
        printf("Dado: %d\nQtd: %d\n", i + 1, q[i]);*/
        if(q[i] == q[largest])
            printf("%d\n", i + 1);
    }
    printf("%d\n", q[largest]);

    
    return 0;
}