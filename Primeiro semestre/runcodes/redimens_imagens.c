#include <stdio.h>

void entrada(int a, float matriz[][2]){
    for (int i = 0; i<a; i++){
        for (int j = 0; j<2; j++){
            scanf("%f", &matriz[i][j]);
        }
    }
}

void novo(int a, float b, float matriz[][2]){
    
    for (int i = 0; i<a; i++){
        for (int j = 0; j<2; j++){
            printf("%.2lf ", (b*(matriz[i][j])));
        }
        printf("\n");
        
    }
    
}


int main()
{
    int a;
    float b;
    scanf("%d %f", &a, &b);
    float matriz[a][2];
    entrada(a, matriz);
    
    novo(a,b,matriz);
    
    
    

    return 0;
}
