#include <stdio.h>

int main()
{
    char c;
    int caracter = 1, linha = 1;

    while ((c = getchar()) != EOF) {
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
            if (c >= 'a' && c <= 'z') {
                c = 'a' + (((c + caracter) * linha) % 26);
            } else if (c >= 'A' && c <= 'Z') {
                c = 'A' + (((c + caracter) * linha) % 26);
            }
        }
        caracter++;
        if (c == '\n') {
            caracter = 1;
            linha++;
        }
        
        putchar(c);
    }

    return 0;
}