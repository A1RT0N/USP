#include <stdio.h>

int esta_na_linha(char *linha,  char *nome) {
    int encontrado = 0;
    for(int i = 0; nome[i] != '\0'; i++) {
        for(int j = 0; linha[j] != '\0'; j++) {
            if(nome[i] == linha[j] || nome[i] == (linha[j] - 32)) {

                encontrado = 1;
                break;
            }
        }
        if(!encontrado) {
            return 0;
        }
        encontrado = 0;
    }
    return 1;
}

int main() {
    char qwe[] = "qwertyuiop";
    char asd[] = "asdfghjkl";
    char zxc[] = "zxcvbnm";
    char nome[20];
    char c;
    int i = 0;
    while((c = getchar()) != EOF) {
        if(c != '\n') {
            nome[i] = c;
            i++;
        } else {
            nome[i] = '\0';
            i = 0;
            if(esta_na_linha(qwe, nome) || esta_na_linha(asd, nome) || esta_na_linha(zxc, nome)) {
                printf("%s\n", nome);
            }
        }  
    }
    nome[i] = '\0';
    if(esta_na_linha(qwe, nome) || esta_na_linha(asd, nome) || esta_na_linha(zxc, nome)) {
        printf("%s\n", nome);
    }

    return 0;
}