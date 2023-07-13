#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


int main() {
    char *p;
    p = (char *) malloc(4096 * sizeof(char));
    
    if (p == NULL) {
        printf("Erro ao alocar memória.\n");
        return 1;
    }
    
    int alfabeto[26] = {0};
    int ch;

    while ((ch = getchar()) != EOF) {
        ch = tolower((unsigned char)ch);
        if (ch >= 'a' && ch <= 'z') {
            alfabeto[ch - 'a']++;
        }
    }

    for (int j = 0; j < 26; j++) {
        if (alfabeto[j] > 0) {
            printf("%c: %d\n", j + 'a', alfabeto[j]);
        }
    }
    
    free(p);

    return 0;
}
