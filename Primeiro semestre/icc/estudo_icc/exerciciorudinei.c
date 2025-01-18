/*Este programa aloca dinamicamente um vetor de doubles de dimensão e elementos determinado
pelo usuário de modo modularizado, a partir do teclado, imprimindo os elementos destes na tela

Autor: Ayrton da Costa Ganem Filho*/

#include <stdio.h>
#include <stdlib.h>

void entrada(int a, double **vetor){ // Função que recebe a dimensão do vetor e o endereço do ponteiro vetor
    *vetor = (double *) malloc(a*sizeof(double)); // a derreferência do endereço do ponteiro do vetor vai ser alocado dinamicamente 
    if (*vetor == NULL){
        printf("Erro de alocação\n"); // Verificação de alocação
        exit(1);
    }
    for(int i=0; i<a; i++){
        scanf("%lf", &(*vetor)[i]); // Entrada dos elementos do vetor por meio do endereço do ponteiro vetor
    }
    
}

void impressao(int a, double *vetor){ // Função que recebe a dimensão do vetor e o endereço do vetor
    for(int i=0; i<a; i++){
        printf("%lf\n", vetor[i]); // Impressão dos elementos do vetor por meio do endereço do vetor
    }
    free(vetor);
}



int main(){
    int a;
    scanf("%d", &a); // Entrada da dimensão do vetor feita pelo usuário
    double *vetor;

    entrada(a,&vetor); // Chamada da função entrada que recebe a cópia da dimensão do vetor e seu endereço de memória
    
    impressao(a,vetor); // Imprime os elementos do vetor

    free(vetor); // Libera o espaço de memória alocado dinamicamente
    vetor = NULL; // O ponteiro vetor aponta para NULL para não haver lixo de memória
    
    return 0;
}



/*
Código de rudinei

#include <stdio.h>
#include <stdlib.h>

aloca(int x);
double *entrada(int *t);
void imprime(double *v, int t);


void imprime(double *v, int t){
    for(int i=0; i<t; i++){
        printf("%lf\n", v[i]);
    }
}


double *aloca(int x){
    double *p;
    
    p = (double*) malloc(x*sizeof(double));

    if(p == NULL){
        printf("Erro de alocação\n");
        exit(1);
    }
    *vetor = (double *) malloc(a*sizeof(double)); // ALoca dinamicamente o 

    return(p);
}

double *entrada(int *t){
    double *v;
    printf("Digite o tamanho do vetor: ");
    scanf("%d", t);

    v = aloca(*t);

    for(int i=0; i<*t; i++){
        printf("Digite o valor %d: ", i+1);
        scanf("%lf", &v[i]);
    }

    return(v);
}

int main(){
    int tam;
    double *vetor;

    vetor = entrada(&tam);

    imprime(vetor, tam);

    free(vetor);

    return 0;
}

*/

// Fazendo agora do mesmo modo de cima só que com void

/*

#include <stdio.h>
#include <stdlib.h>

void aloca(int a, int **vetor){
    *vetor = (int*)malloc(a*sizeof(int));
}

void entrada(int *a, int **vetor){
    scanf("%d", a);
    aloca(*a,vetor);
    
    if(*vetor == NULL){
        printf("Erro de alocação");
        exit(1);
    }

    for (int i =0; i<*a;i++){
        scanf("%d", &(*vetor)[i]);
    }
}

void impressao(int a, int *vetor){
    for(int i=0; i<a; i++){
        printf("%d ", vetor[i]);
    }
}


int main()
{
    int a;
    int *vetor;
    
    entrada(&a,&vetor);
    
    impressao(a,vetor);
    
    free(vetor);
    vetor = NULL;

    return 0;
}

*/