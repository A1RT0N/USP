#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char dia[3], mes[3], ano[5];

}data;

typedef struct{
    char hora[3], min[3], sec[5];

}hora;


typedef struct 
{
    data dat;
    hora hor;
    char palavra[500];
}agenda;






int main(){
    int a;
    scanf("%d", &a);
    agenda dia;
    for (int i =0; i<a;i++){
        scanf(" %[^\n]", (dia.dat.dia));
        scanf(" %[^\n]", (dia.dat.mes));
        scanf(" %[^\n]", (dia.dat.ano));
        scanf(" %[^\n]", (dia.hor.hora));
        scanf(" %[^\n]", (dia.hor.min));
        scanf(" %[^\n]", (dia.hor.sec));
        scanf(" %[^\n]", (dia.palavra));
        printf("%s/%s/%s - %s:%s:%s\n%s\n", dia.dat.dia, dia.dat.mes,dia.dat.ano,dia.hor.hora,dia.hor.min,dia.hor.sec,dia.palavra);

    }
    return 0;
}
