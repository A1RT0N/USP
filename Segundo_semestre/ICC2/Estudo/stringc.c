#include <stdio.h>
#include <string.h>

int converter(char *palavra, int base){
    int num = 0;
    int basenumerica = 1;
    for (int i= strlen(palavra)-1; i>=0; i--){
        num += (palavra[i]-'0')*basenumerica;
        basenumerica*=base;
    }
    return num;
}

int main(){
    char palavra[100];
    int base;
    
    scanf("%s %d", palavra, &base);

    printf("%d",converter(palavra,base));
    return 0;
}