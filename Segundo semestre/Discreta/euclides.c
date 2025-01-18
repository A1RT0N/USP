
#include <stdio.h>

int MCD(int n, int d)
{
    printf("\n estou aqui com n=%d, d=%d, n(mod d)=%d",n,d,n%d);
    if(n%d==0) return(d);
    else return(MCD(d,n%d));
}


int main()
{   
    int n=64876554,d=2876446;/*d<n*/
    printf("\nMCD(%d,%d)= %d",n,d,MCD(n,d));

    return 0;
}

