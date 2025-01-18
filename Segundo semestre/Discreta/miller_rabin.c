#include <stdio.h>

unsigned int pot(unsigned int a,unsigned int e,unsigned int d)
{
    unsigned int p=1,tmp;
    int i;
    
    tmp=a;                                           /* tmp é a^1 */
    for(i=0;i<32;i++)
    {
       
   
        if((e >> i) & 1)                              /* i-esimo bit de e */
        {
            
            p=(p*tmp)%d;                              /* multiplica p pela potencia de a que está em tmp */
            
        } 
        else {}
        tmp=tmp*tmp;    tmp=tmp%d;                    /* tmp era a^{2^{i}} será a^{2^{i+1}}  (em Zd)*/
        tmp=tmp%d;
         
    }
    
    return(p);
}


int main(int argc, char *argv[] )
{
    unsigned int b=2,n=129,q,ex,i,tq;
    if((argc==3)) {sscanf(argv[1],"%u",&n);sscanf(argv[2],"%u",&b);}
     else{printf("\ninput errado     nomefile numero base\n");return 0;}
   
    
    for(q=n-1,ex=0;q%2==0;q=q/2,ex++) /*printf ("\n q=%u, ex=%u",q,ex)*/;  printf ("\n n=%u=%u*2^%u+1",n,q,ex);
    
    for(i=0,tq=q;i<=ex;i++,tq=tq*2) printf ("\n %u^%u (mod %u)=%u\n",b,tq,n,pot(b,tq,n));
    
  /*  printf("\n\n %d^%d (mod %d) =%d \n",a,e,d,pot(a,e,d));*/
    
    
    return 0;
}

