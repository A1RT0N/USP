/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>

int main()
{
    int n=0, aux = 0;
    scanf("%d", &n);
    int v[n];
    for (int i =0; i< n; i++){
        scanf("%d", &v[i]);
    }
    for (int j = 0; j<n; j++){
        for (int k = 0; k<n-1; k++){
            if (v[k+1]<v[k]){
                aux = v[k];
                v[k] = v[k+1];
                v[k+1] = aux;
                
            }
        }
        
    }
    for (int k = 0; k< n; k++){
        printf("%d ", v[k]);
    }

    return 0;
}
