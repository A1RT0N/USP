#ifndef AG_H
#define AG_H

#include <iostream>
#include <chrono>
#include <random>
#include <math.h>
#include <cmath>
#include <vector>

typedef struct{
    double gene;
    int ranking_fitness;
}individuo;

extern individuo melhor_de_todos;
extern int geracao;
extern double taxa_de_mutacao;
extern double media;

int random_numero_int(int a, int b);
double random_numero_double(double a, double b);

void avaliar(individuo *populacao, int tamanho_populacao);

individuo torneio_de_2(individuo pai_mae1, individuo pai_mae_2);

individuo crossover(individuo animal1, individuo animal2);

void mutacao(individuo animal);

void predacao(individuo animal1, individuo animal2);

void copy(individuo *populacao, individuo *filhos, int tamanho_populacao);

void impressao(individuo *populacao, int tamanho_populacao);

double fit(double x);

int main_fitness_melhor_de_todos(int tamanho_populacao);

#endif