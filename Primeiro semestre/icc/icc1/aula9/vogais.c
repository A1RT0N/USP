#include <stdio.h>

void fill_str(char str[]);
int count_vowels(char str[]);

void fill_str(char str[]) {
    char c;
    int k = 0;
    while((c = getchar()) != EOF) {
        str[k] = c;
        k++;
    }
    str[k] = '\0';
}

int count_vowels(char str[]) {
    int i = 0;
    int k = 0;
    while(str[i] != '\0') {
        if(str[i] == 'A' || str[i] == 'E' || str[i] == 'I' || str[i] == 'O' || str[i] == 'U' ||
            str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u') {
                k++;
            }
        i++;
    }

    return k;
}

int main() {
    char str[300];
    fill_str(str);
    int num = count_vowels(str);

    if(num == 1) {
        printf("A palavra \"%s\" contem %d vogal.\n", str, num);
    } else if(num > 1) {
        printf("A palavra \"%s\" contem %d vogais.\n", str, num);
    } else {
        printf("A palavra \"%s\" nao contem vogais.\n", str);
    }
    return 0;
}