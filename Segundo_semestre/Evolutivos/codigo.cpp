#include <iostream>
#include <chrono>
#include <random>
#include <math.h>

using namespace std;

mt19937 gen(static_cast<unsigned int>(chrono::system_clock::now().time_since_epoch().count()));

typedef struct{
    float gene;
    int ranking_fitness;
}individuo;

int random_numero_int(int a, int b);
float random_numero_float(float a, float b);
void avaliar(individuo *populacao, int tamanho_populacao);
individuo torneio_de_2(int *index_escolhidos, individuo *populacao, int tamanho_populacao, float *probabilidades);
individuo crossover(individuo animal1, individuo animal2);
void mutacao(individuo animal);
void copy(individuo *populacao, individuo *filhos, int tamanho_populacao);
void impressao(individuo *populacao, int tamanho_populacao);

individuo melhor_de_todos;

int random_numero_int(int a, int b){
    uniform_int_distribution<> dis(a,b);

    return dis(gen);
}

float random_numero_float(float a, float b){
    uniform_real_distribution<> dis(a,b);

    return dis(gen);
}

void avaliar(individuo *populacao, int tamanho_populacao){
    // Ordene o ranking da populacao de acordo com o fitness comparando se o gene é mais próximo de 10
     for(int i = 0; i < tamanho_populacao; i++){
         populacao[i].ranking_fitness = 0; // Inicializa o ranking como 0 para todos os indivíduos
     }

    float vetor_genes[tamanho_populacao];
    float vetor_genes_ordenados[tamanho_populacao];
    for (int i =0; i< tamanho_populacao; i++){
        vetor_genes[i]= populacao[i].gene;
    }
    for (int i=0; i<tamanho_populacao;i++){
        int tamanho = tamanho_populacao -1;
        for(int j=0; j<tamanho_populacao;j++){
            if(fabs(10-vetor_genes[j]) > fabs(10-vetor_genes[i])){
                tamanho--;
            }

        }
        vetor_genes_ordenados[tamanho]=vetor_genes[i];
    }

    for(int i =0; i< tamanho_populacao; i++){
        for (int j=0;j<tamanho_populacao; j++){
            if (populacao[i].gene == vetor_genes_ordenados[j]){
                populacao[i].ranking_fitness = j+1;
            }
        }
    }

    // Salva o melhor de todos
    for(int i = 0; i < tamanho_populacao; i++){
        if(populacao[i].ranking_fitness == 1){
            melhor_de_todos = populacao[i];
        }
    }
}

// Comparando dois indivíduos aleatórios e escolhendo o melhor deles

individuo torneio_de_2(individuo pai_mae1, individuo pai_mae_2){
    if(pai_mae1.ranking_fitness < pai_mae_2.ranking_fitness){
        return pai_mae1;
    }else{
        return pai_mae_2;
    }
}


individuo crossover(individuo animal1, individuo animal2){
    individuo filho1;
    filho1.gene = (animal1.gene + animal2.gene)/2;
    return filho1;
}

void mutacao(individuo animal){
    if(animal.ranking_fitness != 1){
        if(random_numero_int(0, 100) < 10){
            if(random_numero_int(0, 100) < 50){
                animal.gene = animal.gene + animal.gene*random_numero_float(0.01, 0.99);
            }else{
                animal.gene = animal.gene - animal.gene*random_numero_float(0.01,0.99);
            }
        }
    }

}


void impressao(individuo *populacao, int tamanho_populacao){
    for(int i=0; i<tamanho_populacao; i++){
        cout << "Gene: " << populacao[i].gene << " Ranking: " << populacao[i].ranking_fitness << endl;
    }
}

int main(){

    //Inicializando uma população
    individuo populacao[10];
    for(int i=0; i<10; i++){
        populacao[i].gene = random_numero_float(0.0, 20.1);
        cout << "Gene inicial: " << populacao[i].gene << endl;
    }

    for(int s = 0; s<100; s++){
        avaliar(populacao, 10);
        individuo filhos[10];
        individuo pai;
        individuo mae;
        // Cruzando os 5 indivíduos escolhidos
        for(int i=0; i<9; i++){
            pai = torneio_de_2(populacao[random_numero_int(0, 10)], populacao[random_numero_int(0, 10)]);
            mae = torneio_de_2(populacao[random_numero_int(0, 10)], populacao[random_numero_int(0, 10)]);
            filhos[i] = crossover(pai, mae);
        }

        // PERMANECENDO O MELHOR DE TODOS
        filhos[9] = melhor_de_todos;

        avaliar(filhos,10);

        // Fazendo mutação nos filhos
        for(int i=0; i<10; i++){
            mutacao(filhos[i]);
        }
        
        // Nova avaliação pós mutação
        avaliar(filhos,10);

        // Copiando os filhos para a população
        for(int i=0; i<10; i++){
            populacao[i] = filhos[i];
        }        
    }
    
    impressao(populacao, 10);
    

    return 0;
}