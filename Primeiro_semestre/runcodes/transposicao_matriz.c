#include <stdio.h>
#include <stdlib.h>

void entrada(int lin, int col, int **mat){
    for(int i=0; i<lin; i++){
        for(int j=0; j<col; j++){
            scanf("%d", &mat[i][j]);
        }
        
    }

}

void transposta(int lin, int col, int **mat, int **matrizt){
    
    for (int i = 0; i<col; i++){
        for (int j = 0; j<lin; j++){
            matrizt[i][j] = mat[j][i];
            printf("%2d ", matrizt[i][j]);
        }
        printf("\n");
    }

}

void freemat(int **p, int lin){ 
    // Esse for libera cada linha da matriz
    for (int i = 0; i<lin; i++){
        free(p[i]);
    }
    
    
}




int main()
{
    int **p, **t;
    int lin, col;
    scanf("%d %d", &lin, &col);
    
    // Aloca matriz p
    p = (int **)malloc(sizeof(int*)*lin);
    for (int i =0; i<lin; i++){
        p[i] = (int *)malloc(sizeof(int)*col);
        
    }
    
    //Aloca matriz t
    t = (int **)malloc(sizeof(int*)*col);
    for (int i =0; i<col; i++){
        t[i] = (int *)malloc(sizeof(int)*lin);
    }
    
    
    entrada(lin, col, p);
    transposta(lin, col, p, t);
    
    freemat(p,lin);
    freemat(t,col);
    
    return 0;
}
    
