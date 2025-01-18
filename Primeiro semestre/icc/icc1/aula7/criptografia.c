/*
Esta eh uma mensagem SUPER SECRETA.
Eh de suma importancia que ela seja encriptada!
*/

#include <stdio.h>

int main() {
    char c, buffer;
    int k_char = 0, k_linha = 1;
    while ((c = getchar()) != EOF) {
        if(c != '\n'){
            k_char++;
            buffer = ((c + k_char) * k_linha) % 26;
            if(c >= 65 && c <= 90) {
                printf("%c", 65 + buffer);
            } else if(c >= 97 && c <= 122) {
                printf("%c", 97 + buffer);
            } else 
                printf("%c", c);
        } else if(c == '\n') {
            k_linha++;
            k_char = 0;
        }
    }
    return 0;
}