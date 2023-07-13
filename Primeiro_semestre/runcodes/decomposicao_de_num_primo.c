/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>

int main()
{
    int x;
    scanf("%d", &x);
    
    for(int i = 2; x > 1; i++){
        int cont = 0;
        
        while(x%i == 0){
            cont++;
            x = x/i;
        }
        if (cont > 0){
            printf("%d %d\n", i, cont);
        }  
        
    }

    return 0;
}
