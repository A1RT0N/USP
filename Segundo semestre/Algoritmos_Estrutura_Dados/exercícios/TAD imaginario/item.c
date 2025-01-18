#include <stdio.h>
#include <stdlib.h>

#include "item.h"

struct complexo
{
    double real;
    double imaginario;
};

Complexo * criar (double real, double imag){
    Complexo* numero = (Complexo*) malloc(sizeof(Complexo));

    if(numero != NULL){
        numero->real = real;
        numero->imaginario = imag;
    }

    return numero;
}

void liberar (Complexo *c){
    free(c);
    c = NULL;
}

void copiar ( Complexo *source, Complexo *target){
    if(source != NULL || target != NULL){
        target->imaginario = source->imaginario;
        target->real = source->real;
    }
}

Complexo *adicao ( Complexo *a, Complexo *b){
    Complexo *c = criar(0,0);
    if(a != NULL || b != NULL){
        c->imaginario = a->imaginario + b->imaginario;
        c->real = a->real + b->real;
    }

    return c;
}

Complexo *subtracao ( Complexo *a, Complexo *b){
    Complexo *c = criar(0,0);
    if(a != NULL || b != NULL){
        c->imaginario = a->imaginario - b->imaginario;
        c->real = a->real - b->real;
    }

    return c;
}


int e_real ( Complexo *c){
    if(c!= NULL){
        if(c->imaginario == 0){
            return 1;
        }else{
            return 0;
        }
    }
    return 0;
}

double real ( Complexo *c){
    return c->real;
}
double imag ( Complexo *c){
    return c->imaginario;
}

void atribuir ( Complexo *c, double real, double imag){
    if(c != NULL){
        c->imaginario = imag;
        c->real = real;
    }
}
void atribuir_real ( Complexo *c, double real){
    if(c != NULL){
        c->real = real;
    }
}
void atribuir_imag ( Complexo *c, double imag){
    if(c != NULL){
        c->imaginario = imag;
    }
}

