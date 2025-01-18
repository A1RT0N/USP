#include <stdio.h>
#include <math.h>

int main() {
    int number;
    const int POWER = 10;
    const char text[] = "Numero:";

    scanf("%d", &number);
    
    double power_of_ten = pow(number, POWER);
    double square_root = sqrt(number);

    printf("%-8s%d\n%#17.2e\n%#13.2lf\n", text, number, power_of_ten, square_root);

    return 0;
}

