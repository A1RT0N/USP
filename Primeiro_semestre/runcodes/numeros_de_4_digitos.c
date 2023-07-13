#include <stdio.h>
#include <math.h>
int main(){
    int a, b;
    for(int i = 1000; i<=9999; i++){
        a= i/100;
        b = i%(100);
        if (sqrt(i)== a+b){
            printf("%d\n", i);
        }
    }
}
