#include <stdio.h>
int i,j;
int MCD(int n, int d)
{ 
    int tM,ti;

    printf("\n estou aqui com n=%d, d=%d,  %d=%d*%d+%d",n,d,n,d,n/d,n%d);
    if(n%d==0) 
    {
        i=0;j=1; 

	printf("\n voltando com n=%d, d=%d, %d=%d*%d+%d, i=%d, j=%d",n,d,n,d,n/d,n%d,i,j);
	printf("; MCD(%d,%d)= %d: (%d)*%d+(%d)*%d=%d",n,d,d,i,n,j,d,d);
	return(d);
    }
    else 
    {
        tM=MCD(d,n%d);ti=i;i=j;j=ti-j*(n/d); 

        printf("\n voltando com n=%d, d=%d, %d=%d*%d+%d, i=%d, j=%d",n,d,n,d,n/d,n%d,i,j);
        printf("; MCD(%d,%d)= %d: (%d)*%d+(%d)*%d=%d",n,d,tM,i,n,j,d,tM);

        return(tM);
    }
}


int main()
{   
    int M,n=1001,d=193;/*d<n*/
    M=MCD(n,d);
    printf("\nMCD(%d,%d)= %d: (%d)*%d+(%d)*%d=%d",n,d,M,i,n,j,d,M);

    return 0;
}



