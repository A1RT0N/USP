#include <stdio.h>
#include <stdlib.h>

void get_vec_size(int *n);
void allocate_vec(double **vec, int n);
void fill_vec(double *vec, int n);
void printf_vec(double *vec, int n);
void deallocate_vec(double *vec);

void get_vec_size(int *n) {
    scanf("%d", n);
}

void allocate_vec(double **vec, int n) {
    *vec = malloc(n * (sizeof(double)));
}

void fill_vec(double *vec, int n) {
    for(int i = 0; i < n; i++) {
        scanf("%lf", &vec[i]);
    }
}

void printf_vec(double *vec, int n) {
    for(int i = 0; i < n; i++) {
        printf("%.2lf\n", vec[i]);
    }
}

void deallocate_vec(double *vec) {
    free(vec);
    vec = NULL;
}

int main() {
    double *vec = NULL;
    int n;

    get_vec_size(&n);
    allocate_vec(&vec, n);
    
    fill_vec(vec, n);
    printf_vec(vec, n);

    deallocate_vec(vec);

    return 0;
}