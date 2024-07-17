#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *file = NULL;
    char file_path[100];

    scanf("%s ", file_path);
    file = fopen(file_path, "r");

    fseek(file, 0, SEEK_END);
    printf("%ld\n", ftell(file));
    fclose(file);

    return 0;
}