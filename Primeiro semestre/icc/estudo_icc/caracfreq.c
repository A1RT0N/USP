#include <stdio.h>
char frequente(char str[]);

char frequente(char str[]){
    int i = 0, j = 0, cont = 0, cont2 = 0;
    char a = ' ';
    while (str[i] != '\0'){
        while (str[j] != '\0'){
            if (str[i] == str[j]){
                cont++;
            }
            j++;
        }
        if (cont > cont2){
            cont2 = cont;
            a = str[i];
            cont = 0;
        }
        i++;
    
    }
    return a;

}


int main(){
    char b;
    char str[100];
    scanf("%s",str);
    b = frequente(str);
    printf("\n%c",b);
    return 0;
}