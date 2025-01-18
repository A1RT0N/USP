#include <stdio.h>

void swap(int *p, int *v){
    int aux;
    aux = *p;
    *p = *v;
    *v = aux;
}

int main(){
    int a,b;
    scanf("%d %d", &a, &b);
    swap(&a,&b);
    printf("%d %d\n", a,b);
    return 0;
}