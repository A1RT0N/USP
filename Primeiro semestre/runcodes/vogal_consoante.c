#include <stdio.h>

int main()
{
    char c;
    scanf(" %c",&c);
    if (c == 'a' || c== 'e' || c== 'i' || c== 'o' || c== 'u' || c == 'U'){
        printf("Eh uma vogal");
    } else{
        if (((c >=97) && (c <= 122)) || ((c>=65) && (c<= 90))){
            printf("Eh uma consoante");
        } else{
            printf("Nao eh uma letra do alfabeto");
        }
    }

    return 0;
}