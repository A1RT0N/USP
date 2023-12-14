
#include <stdio.h>

int minprimfac(int n)
{ 
    int i;
    for(i=2;i<=n;i++)
    {
        if(n%i==0) return i;
        
    }
}

void printfactors(int n)
{
    int m;
    m=n;
    do
    {
        printf("\n%d",m=minprimfac(n));
        n=n/m;
    }while(n>1);
}

int main(int argc, char *argv[] )
{   
    int n=64974,p=27644437,c=64974;
     if((argc==2)) {sscanf(argv[1],"%d",&n);}
     else{printf("\ninput errado\n");return 0;}
    
    printf("\nO menor fator primo de %d é %d",n,minprimfac(n));
    printf("\nA fatorização  de %d é:",n);printfactors(n);
    printf("\n");

    return 0;
}
