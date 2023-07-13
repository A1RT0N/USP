#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x,y;
    scanf("%d%d", &x, &y);
    
    printf("A and B: %d\nA or B: %d\nA xor B: %d\nnot A: %d\nA right shift 2: %d\nB left shift 1: %d\n", x & y, x | y, x^y, ~x, x>>2, y<<1);


    return 0;
}