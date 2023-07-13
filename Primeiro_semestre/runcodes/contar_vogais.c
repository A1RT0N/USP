#include <stdio.h>
#include <string.h>

int main(){
    int contador =0;
    char palavra[80];
    scanf(" %s", palavra);
    
    for (int i=0; i< strlen(palavra); i++){
        if (palavra[i] == 'a' || palavra[i] == 'e' || palavra[i] == 'i' || palavra[i] == 'o' || palavra[i] == 'u' || palavra[i] == 'A' || palavra[i] == 'E' || palavra[i] == 'I' || palavra[i] == 'O' || palavra[i] == 'U'){
            contador++;
        }
    }
    if (contador >1){
        printf("A palavra \"%s\" contem %d vogais.", palavra, contador);
    } else {
        if (contador == 1){
            printf("A palavra \"%s\" contem %d vogal.", palavra, contador);
        } else {
            printf("A palavra \"%s\" nao contem vogais.", palavra);
        }
    }




    return 0;
}