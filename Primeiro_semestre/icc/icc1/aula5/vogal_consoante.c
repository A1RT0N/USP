#include <stdio.h>

int main(void) {
    char c;
    scanf("%c", &c);

    if(c == 'a' || c == 'A' || c == 'e' || c == 'E' || c == 'i' || c == 'I' || c == 'o' || c == 'O' || c == 'u' || c == 'U') {
        printf("Eh uma vogal\n");
    } else if((c >= 65 && c <= 90) || (c >= 97 && c <= 122)) {
        printf("Eh uma consoante\n");
    } else {
        printf("Nao eh uma letra do alfabeto\n");
    }
    return 0;
}