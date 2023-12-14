#include <stdio.h>

int main() {
    int M, flag = 0;
    scanf("%d", &M);
    char Seq[M + 1];
    char Alfabeto[27] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    scanf("%s", Seq);

    for (int i = 0; i < (M); i++) {
        if (Seq[i] != Alfabeto[i]) {
            flag++;
        }
    }

    if (flag == 2) {
        printf("There are the chance.\n");
    } else {
        printf("There aren't the chance.\n");
    }

    return 0;
}