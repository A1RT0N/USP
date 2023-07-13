/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <math.h>
int main()
{
    int n;
    scanf("%d", &n);
    float v[n];
    double a = 0;
    for (int i = 0; i<n; i++){
        scanf("%f", &v[i]);
    }
    for (int j = 0; j<n; j++){
        a=0;
        for (int k = 0; k<n; k++){
            a += v[k]*cos((M_PI/n)*(k+0.5)*j);
        }
        printf("%lf\n", a);
    }
    
    

    return 0;
}
