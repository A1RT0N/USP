#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x;
    scanf("%d", &x);
    printf("%c%c%c%c", x>>24, x>>16, x>>8, x);
    
    


    return 0;
}