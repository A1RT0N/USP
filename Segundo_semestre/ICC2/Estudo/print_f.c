#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char* printar_numero(int n){
    int contador = 0;
    if (n==0){
        putc('0', stdout);
        return 0;
    }

    int tmp = n;

    while (tmp > 0){
        contador ++;

        tmp = tmp / 10;
    }

    int lista[contador];
    char c;

    tmp = n;

    for (int i = 0; i < contador; i++){
        lista[i] = tmp % 10;

        tmp /= 10;
    }

    for (int i = (contador - 1); i >= 0; i--){
        c = lista[i] + '0';

        putc(c, stdout);
    }
}

\
void print_f(char *str, ...){
    va_list ap;
    va_start(ap, str);

    for (int i = 0; i < strlen(str); i++){
        if ((str[i] == '%') && (str[i + 1] == 'u')){
            i++;

            int x;

            x = va_arg(ap, unsigned int); // Pega cada argumento que é dado

            printar_numero(x);

            continue;
        } 

        putc(str[i], stdout);
    }
}

int main(void){
    print_f("O ayrton terminou de escover os seus %u dentes que são nota %u. Vc é uma nota %u", 92, 10, 0);
}