#include <stdio.h>
#include <math.h>
int main(){
    float a;
    double x = 10;
    scanf("%2f", &a);
    printf("Numero:%3.0f\n",a);
    printf("%17.2e\n", pow(a, x));
    printf("%13.2lf", sqrt(a));
    
    /*
    %e	Exponential notation (using a lowercase e as in 3.1415e+00)
    http://linguagemc.com.br/a-biblioteca-math-h/
    https://www.w3resource.com/c-programming/c-printf-statement.php#:~:text=The%20printf()%20function%20is,values%20to%20the%20standard%20output.&text=The%20format%20argument%20is%20a%20string%20containing%20C%20language%20conversion%20specifications.
    https://www.cprogressivo.net/2012/12/Buffer--o-que-e-como-limpar-e-as-funcoes-fflush-e-fpurge.html
    */
}