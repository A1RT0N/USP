/*
    Rascunho das operacoes

    ax + by + c = 0 -> y = -(1/b) * ( ax + c )
    ux + vy + w = 0 -> y = -(1/v) * ( ux + w )

    -(1/b) * ax + (-1/b) * c = -(1/v) * ux + (-1/v) * w
    ((-1/b) * a + (1/v) * u) * x = (-1/v) * w + (1/b) * c 
    x = ((-1/v) * w + (1/b) * c ) / ((-1/b) * a + (1/v) * u)
*/

#include <stdio.h> 

int main(void) {

    // coeficientes
    double a, b, c;
    double u, v, w;

    // variavel auxiliar para calculo de res_x
    double quo_x;

    // valor de (x, y) onde as retas se cruzam
    double res_x, res_y;

    printf("Digite os coeficientes a, b, c da 1ª reta com b != 0 \n");
    scanf("%lf %lf %lf", &a, &b, &c);

    printf("Digite os coeficientes a, b, c da 2ª reta com b != 0 \n");
    scanf("%lf %lf %lf", &u, &v, &w);

    if(b == 0 || v == 0)
    {
        printf("Coeficiente(s) inválido(s): (b == 0)\n");
        return 0; 
    }

    // quo_x eh igual a 0 qnd as retas sao paralelas
    quo_x = ((-1/b) * a + (1/v) * u);
    if(quo_x == 0) { 
        printf("As retas são paralelas\n");
        return 0;
    }

    res_x = ((-1/v) * w + (1/b) * c ) / quo_x;
    res_y = -(1/b) * ( a * res_x + c );

    printf("As retas se cruzam em (x, y) = (%.2lf, %.2lf) no(a) ", res_x, res_y);

    /* 
        decide se as retas se cruzam no 1, 2, 3, 4 
        quadrantes ou na origem, eixo x ou eixo y
    */

    if(res_x > 0 && res_y > 0) {
        printf("primeiro quadrante\n");
    } else if(res_x < 0 && res_y > 0) {
        printf("segundo quadrante\n");
    } else if(res_x < 0 && res_y < 0) {
        printf("terceiro quadrante\n");
    } else if(res_x > 0 && res_y < 0) {
        printf("quarto quadrante\n");
    } else if(res_x == 0 && res_y == 0) {
        printf("origem\n");
    } else if(res_x == 0 && res_y != 0) {
        printf("eixo y\n");
    } else if(res_x != 0 && res_y == 0) {
        printf("eixo x\n");
    }

    return 0;
}