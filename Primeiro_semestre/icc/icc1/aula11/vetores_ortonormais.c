#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int *read_into_vec(int *vec, int m);
int dot_product(int *vec1, int m, int *vec2);

int *read_into_vec(int *vec, int m) {
    vec = malloc(m * sizeof(int));

    for(int i = 0; i < m; i++) {
        scanf("%d", &vec[i]);
    }

    return vec;
}

int dot_product(int *vec1, int m, int *vec2) {
    int sum = 0;
    for(int i = 0; i < m; i++)
        sum += vec1[i] * vec2[i];

    return sum;
}

int module(int *vec, int m) {
    int sum = 0;
    for(int i = 0; i < m; i++) {
        sum += pow(vec[i], 2);
    }

    sum = sqrt(sum);
    return sum;
}

int main() {
    int *vec1 = NULL;
    int *vec2 = NULL;

    int m;
    scanf("%d", &m);

    vec1 = read_into_vec(vec1, m);
    vec2 = read_into_vec(vec2, m);

    if(dot_product(vec1, m, vec2) == 0 && module(vec1, m) == 1 && module(vec2, m) == 1)
        printf("sao ortonormais\n");
    else
        printf("nao sao ortonormais\n");

    free(vec1);
    vec1 = NULL;

    free(vec2);
    vec2 = NULL;

    return 0;
}