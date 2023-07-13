#include <stdio.h>
#include <math.h>

int main()
{
    int a,b, c;
    scanf("%d %d %d", &a, &b, &c);
    if (a+b<=c || b+c<=a || a+c<=b){
        printf("INVALIDO");
    } else{
        if (a==b && b==c && a==c){
            printf("EQUILATERO");
        } else{
            if (a==b || b==c || a==c){
                printf("ISOSCELES");
            } else{
                if (a!=b && b!=c && a!=c){
                    printf("ESCALENO");
                }
                }
            }
    }
        
    return 0;
}
