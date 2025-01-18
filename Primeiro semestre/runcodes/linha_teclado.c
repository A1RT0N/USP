#include <stdio.h>
#include <string.h>
#include <ctype.h>

int verificar(char *palavra, char *linha) {
    for (int i = 0; i < strlen(palavra); i++) {
        int flag = 0;
        char lower_palavra = tolower(palavra[i]);
        for (int j = 0; j < strlen(linha); j++) {
            if (lower_palavra == tolower(linha[j])) {
                flag = 1;
                break; 
            }
        }
        if (flag == 0) {
            return 0;  
        }
    }
    return 1; 
}

int main() {
    char v1[11] = "qwertyuiop";  
    char v2[10] = "asdfghjkl";   
    char v3[8] = "zxcvbnm";      

    char palavra[100];
    while (scanf("%s", palavra) != EOF) {
        if (verificar(palavra, v1) || verificar(palavra, v2) || verificar(palavra, v3)) {
            printf("%s\n", palavra);
        }
    }
    return 0;
}
