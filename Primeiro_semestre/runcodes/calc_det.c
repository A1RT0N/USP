#include <stdio.h>

int mudar(int a, int matriz[][a]){
    if (a ==2){
        return ((matriz[0][0]*matriz[1][1])-(matriz[0][1]*matriz[1][0]));
    } else{
        if (a==1){
            return matriz[0][0];
        } else{
            return(matriz[0][0]*matriz[1][1]*matriz[2][2] + matriz[0][1]*matriz[1][2]*matriz[2][0]+ matriz[0][2]*matriz[1][0]*matriz[2][1]-(matriz[2][0]*matriz[1][1]*matriz[0][2]+matriz[2][1]*matriz[1][2]*matriz[0][0]+matriz[2][2]*matriz[1][0]*matriz[0][1]));

        }
    }
    
    
}
void entrada(int a, int matriz[][a]){
    for (int i = 0; i<a;i++){
        for (int j=0;j<a;j++){
            scanf("%d", &matriz[i][j]);
        }
    }
}


int main()
{
    int a;
    scanf("%d", &a);
    int matriz[a][a];
    entrada(a, matriz);
    int determinante = mudar(a, matriz);
    printf("%d", determinante);
    return 0;
}
