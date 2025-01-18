#include <stdio.h>
#include <math.h>

int main() {
    int N;
    scanf("%d", &N);
    float sum = 0;
    float vec[N];

    for(int i = 0; i < N; i++) {
        scanf("%f", &vec[i]);
    }

    for(int k = 0; k < N; k++) {
        for(int n = 0; n < N; n++) {
            double cos_var = cos( (M_PI / N) * (n + (1.0/2.0)) * k );
            sum += vec[n] * cos_var;
            //printf("%f %f %d %d \n", vec[n], c, n, k);
        }
        printf("%.4f\n", sum);
        sum = 0;
    }

    return 0;
}