#include <stdio.h>

int main(){
    int a;
    int m;
    int d;
    scanf("%*[a-z]%3x%2d%2o",&a,&m,&d);
    printf("Data: %02d/%02d/%04d\n",d,m,a); 
    return 0;
}

/*
vc pode usar o sprintf com a seguinte notação:
int i=12;
char str[MAX];
sprintf (str, "%04d", i);

Isso colocar dentro de str a string "0012" (o número q vc coloca depois do % representa o número de zeros q vc quer).
Isso funciona tb com o printf
*/
