/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>

int main()
{
    int n, a, b, soma = 0;
    scanf("%d", &n);
    int v[n];
    for (int i = 0; i< n; i++){
        scanf("%d", &v[i]);
    }
    scanf("%d %d", &a, &b);
    
    for (int j =a; j<= b; j++){
        soma += v[j]; 
    }
    printf("%d", soma);
    

    return 0;
}
