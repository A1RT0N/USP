
#include <stdio.h>

int main()
{
    int i,j,conta=0,n=100;
    
    
   for(i=1;i<=n;i++)
      {
          for(j=i+1;j<=n;j++)
            {
                conta++;
            }
      }
      
      printf("\n conta=%d",conta);
    return 0;
}


/*
#include <stdio.h>

int main()
{
    int i,j,k,conta=0,n=10;
    
    
   for(i=1;i<=n;i++)
         for(j=i+1;j<=n;j++)
            for(k=j+1;k<=n;k++)
            {
                conta++;
            }
      
      
      printf("\n conta=%d",conta);
    return 0;
}


*/