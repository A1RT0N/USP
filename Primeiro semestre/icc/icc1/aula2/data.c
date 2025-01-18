#include <stdio.h>

int main() {
    int hex_year;
    int decimal_month;
    unsigned int octal_day;
    
    scanf("%*[a-z]");

    scanf("%3x", &hex_year);
    scanf("%2d", &decimal_month);
    scanf("%2o", &octal_day);

    printf("Data: %02d/%02d/%04d\n", octal_day, decimal_month, hex_year);

    return 0;
}