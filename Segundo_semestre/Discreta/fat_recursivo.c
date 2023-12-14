#include <stdio.h>

int recfac(int n)
{
    

    if(n==1) {printf("1="); return(1);}
    else  {printf("%d*",n);return(n*recfac(n-1));}
    
}


int main()
{ int n=12;
    printf("%d!=%d",n,recfac(n));

    return 0;
}
