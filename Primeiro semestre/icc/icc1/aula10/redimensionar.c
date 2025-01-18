#include <stdio.h>

void resize_graph(int qtt, double factor) {
    for(int i = 0; i < qtt; i++) {
        double current;
        scanf("%lf", &current);
        printf("%.2lf ", current * factor);

        scanf("%lf", &current);
        printf("%.2lf\n", current * factor);
    }
}

int main() {
    int qtt;
    double factor;
    scanf("%d %lf", &qtt, &factor);

    resize_graph(qtt, factor);
    return 0;
}