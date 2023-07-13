#include <stdio.h>

int main()
{
    int n;
    float primeiro_termo, razao, res; 
    scanf("%d", &n);
    scanf("%f %f", &primeiro_termo, &razao);
    printf("PA: ");
    res = primeiro_termo;
    for (int i = 0; i<n; i++){
        printf("%.3f ", res);
        res += razao;
    }
    printf("\nPG: ");
    for (int i = 0; i<n; i++){
        printf("%.3f ", primeiro_termo);
        primeiro_termo *= razao;
    }

    
    
    
    
    return 0;
}