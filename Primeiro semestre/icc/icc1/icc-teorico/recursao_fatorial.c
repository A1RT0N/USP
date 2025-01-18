#include <stdio.h>
#include <time.h>

long long fatorial_rec(int n) {
    if(n == 0)
        return 1;
    return(fatorial_rec(n - 1) * n);
}

long long fatorial_it(int n) {
    long long r = 1;
    for(int i = n; i > 0; i--) {
        r *= i;
    }
    return r;
}

int main() {
    long long n, r_rec, r_it;
    scanf("%lld", &n);

    clock_t begin_rec = clock();

    r_rec = fatorial_rec(n);

    clock_t end_rec = clock();
    double time_spent_rec = (double)(end_rec - begin_rec) / CLOCKS_PER_SEC;

    clock_t begin_it = clock();

    r_it = fatorial_it(n);

    clock_t end_it = clock();
    double time_spent_it = (double)(end_it - begin_it) / CLOCKS_PER_SEC;

    printf("Rec: %lld, %lf \n It: %lld, %lf\n", r_rec, time_spent_rec, r_it, time_spent_it);
    return 0;
}