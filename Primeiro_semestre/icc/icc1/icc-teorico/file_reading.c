#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *to_write = NULL;
    FILE *to_read = NULL;
    char c;

    to_write = fopen("to_read", "wb");

    for(int i = 0; i < 26; i++)
        fputc('a' + i, to_write);

    fclose(to_write);

    to_read = fopen("to_read", "rb");
    to_write = fopen("to_write", "wb");
    
    while((c = fgetc(to_read)) != EOF)
        fputc(c, to_write);

    fclose(to_write);
    fclose(to_read);

    to_read = fopen("to_write", "rb");
    while((c = fgetc(to_read)) != EOF)
        printf("%c ", c);
    
    printf("\n");

    fclose(to_read);

    return 0;
}