#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int m, n;
    scanf("%d %d", &m, &n);
    clock_t begin = clock();
    int count = 0;

    while(count < 100000) {
        int **mat;
        int *lin;
        mat = malloc(m * sizeof(int *));
        lin = malloc(m * n * sizeof(int));

        for(int i = 0; i < m; i++)
            mat[i] = &lin[i * n];
        
        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
                mat[i][j] = i + j;

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++)
                printf("%d ", mat[i][j]);
            printf("\n");
        }

        free(lin);
        lin = NULL;
        free(mat);
        mat = NULL;
        count++;
    }
    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("execution time: %lf\n", time_spent);
    return 0;
}