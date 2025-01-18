#include <stdio.h>
#include <stdlib.h>

#define NUM 26

int main() {
    int *count = NULL;
    count = calloc(NUM, sizeof(int));
    char c;
    while((c = getchar()) != EOF) {
        if(c >= 'A' && c <= 'Z')
            c += 32;
        count[c - 'a']++;
    }

    for(int i = 0; i < NUM; i++) {
        if(count[i])
            printf("%c: %d\n", i + 'a', count[i]);
    }
    free(count);
    count = NULL;

    return 0;
}