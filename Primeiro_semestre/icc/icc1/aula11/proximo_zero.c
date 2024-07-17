#include <stdio.h>
#include <stdlib.h>

int *read_into_vec(int *vec, int m);

int *read_into_vec(int *vec, int m) {
    vec = malloc(m * sizeof(int));

    for(int i = 0; i < m; i++) {
        scanf("%d", &vec[i]);
    }

    return vec;
}

void print_closest_to_zero(int *vec, int m, int closest) {
    for(int i = 0; i < m; i++) {
        if(vec[i] * vec[i] < closest * closest)
            closest = vec[i];
    }

    printf("%d\n", closest);

    for(int i = 0; i < m; i++) {
        if(vec[i] == closest)
            printf("%d ", i);
    }

    printf("\n");
}

int main() {
    int *vec = NULL;
    int m;
    int closest;

    scanf("%d", &m);

    vec = read_into_vec(vec, m);

    closest = vec[0];

    print_closest_to_zero(vec, m, closest);
    
    free(vec);
    vec = NULL;

    return 0;
}