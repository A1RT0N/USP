#include <stdio.h>

unsigned int pot(unsigned int a,unsigned int e,unsigned int d)
{
    unsigned int p=1,tmp;
    int i;
    
    tmp=a;                                           /* tmp é a^1 */
    for(i=0;i<32;i++)
    {
        printf("\n p=%d  \n %d^(2^%d)=%d  ",p,a,i,tmp);
   
        if((e >> i) & 1)                              /* i-esimo bit de e */
        {
            printf("p=p*%d (mod %d)",tmp,d);
            p=(p*tmp)%d;                              /* multiplica p pela potencia de a que está em tmp */
            
        } 
        else {printf("p=p*1");}
        tmp=tmp*tmp;    tmp=tmp%d;                    /* tmp era a^{2^{i}} será a^{2^{i+1}}  (em Zd)*/
        printf("=%d  ",p);
    }
    
    return(p);
}


int main()
{
    unsigned int a=2,e=127,d=10000;
     
    
    printf("\n\n %d^%d (mod %d) =%d \n",a,e,d,pot(a,e,d));
    
    
    return 0;
}