#include <stdio.h>

int tamanho(char str[]){
    int i = 0;
    while(str[i] != '\0'){
        i++;
    }
    return i;
    
}

int main(){

    char str[100];
    scanf("%s",str);
    int a = tamanho(str);

    printf("%d",a);

    return 0;
}