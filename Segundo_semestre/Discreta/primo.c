
#include <stdio.h>

int minprimfac(unsigned int n)
{ 
   unsigned  int i;
    for(i=2;i<=n;i++)
    {
        if(n%i==0) return i;
        
    }
}

int main()
{   
    unsigned int n=55555,tmp;/*2^32=4'294'967'296*/
    
    do
    {
       printf("\nO menor fator primo de %u é %u",n,tmp=minprimfac(n));
       n++;
    }while(tmp!=n-1);


    printf("\nO primeiro primo encontrado é %u",n-1);
     
    return 0;
}
