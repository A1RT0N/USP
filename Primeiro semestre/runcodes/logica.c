
#include <stdio.h>
#include <math.h>
int main()
{
    int a,b;
    scanf("%d %d", &a, &b);
    // bool maior_b = a 
    printf("A > B: %d\n", (a > b));
    printf("A eh par: %d\n", (a%2 == 0));
    printf("B NAO eh multiplo de 3: %d\n", (0 < b%3));
    printf("A > B e A eh par: %d\n", (a > b) && (a%2 == 0));
    printf("A > B ou A eh par: %d\n", (a > b) || (a%2 == 0));
    return 0;
    
}
