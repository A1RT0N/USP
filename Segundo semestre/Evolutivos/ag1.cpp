#include "ag1.h"

#define pi 3.14159265

using namespace std;

mt19937 gen(static_cast<unsigned int>(chrono::system_clock::now().time_since_epoch().count()));

// IMPLEMENTAR O GENOCÍDIO - ver svg
// USar a função rand na função fit pra gerar ruído


individuo melhor_de_todos;
int geracao = 0;
double taxa_de_mutacao = 0.001;
double media = 0;

// Hereditariedade aumenta o tempo de avaliação sema aumentar o tempo -> Quando eu for escolher o melhor para 
// para transar eu escolho o cara com melhor média de hereditariedade (isso evita o azar de um cara bom piorar e não ter filhos bons)
// Isso pode estagnar a população - não dropa nem sobe
// Solução do simões: o cara que eu escolho pra transar que tem a melhor média nas ultimas 5 gerações.
// Ele vai transar com todo mundo menos com quem tiver pontuação na geração atual melhor do que a dele
// Guardar os 5 últimos valores de hereditariedade de cada indivíduo -> vetor de 5 posições



int random_numero_int(int a, int b){
    uniform_int_distribution<> dis(a,b);

    return dis(gen);
}

double random_numero_double(double a, double b){
    uniform_real_distribution<> dis(a,b);

    return dis(gen);
}


double fit(double x){
    return 5 * (2*cos(0.039*x) + 5*sin(0.05*x) + 0.5*cos(0.01*x) + 10*sin(0.07*x) + 5*sin(0.1*x) + 5*sin(0.035*x))*10+500;
}


void avaliar(individuo *populacao, int tamanho_populacao){
    for(int i = 0; i < tamanho_populacao; i++){
        populacao[i].ranking_fitness = tamanho_populacao; // Inicializa o ranking como 0 para todos os indivíduos
    }

    
    for(int i = 0; i < tamanho_populacao; i++){
        for(int j = 0; j < tamanho_populacao; j++){
            if(populacao[i].gene > populacao[j].gene){
                populacao[i].ranking_fitness--;
            }
        }
    }

    // Salva o melhor de todos (ARRUMAR)
    for(int i = 0; i < tamanho_populacao; i++){
        if(populacao[i].ranking_fitness == 1 || populacao[i].ranking_fitness == 2){
            if(melhor_de_todos.gene < populacao[i].gene){
                melhor_de_todos = populacao[i];
            }
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
        switch (geracao)
        {
        case 10:
            taxa_de_mutacao/=10;
            break;
        case 20:
            taxa_de_mutacao/=10;
            break;
        case 30:
            taxa_de_mutacao*=1000;
            break;
        case 40: 
            taxa_de_mutacao*=10;
            break;
        case 50: 
            taxa_de_mutacao*= 10;
            break;
        case 60:
            taxa_de_mutacao*= 10;
            break;
        case 70:
            taxa_de_mutacao/= 10000;
            break;
        default:
            break;
        }
        if(random_numero_double(0, 1) < taxa_de_mutacao){
            if(random_numero_int(0, 100) < 50){
                animal.gene = animal.gene + animal.gene*taxa_de_mutacao*random_numero_double(0.001, 0.09999);
            }else{
                animal.gene = animal.gene - animal.gene*taxa_de_mutacao*random_numero_double(0.001, 0.09999);
            }
        }
    }


}


void predacao(individuo animal1, individuo animal2){   // Predação Randomica
    if(animal1.ranking_fitness < animal2.ranking_fitness){
        animal2.gene = fit(random_numero_double(-20*pi, 20*pi));
    } else{
        if(animal1.ranking_fitness > animal2.ranking_fitness){
            animal1.gene = fit(random_numero_double(-20*pi, 20*pi));
        }else{
            return;
        }
    }
}


void impressao(individuo *populacao, int tamanho_populacao){
    for(int i=0; i<tamanho_populacao; i++){
        cout << "Gene: " << populacao[i].gene << " Ranking: " << populacao[i].ranking_fitness << endl;
    }
}

int main_fitness_melhor_de_todos(int tamanho_populacao){

    //Inicializando uma população

    // int tamanho_populacao  = 150;

    individuo populacao[tamanho_populacao];
    for(int i=0; i<tamanho_populacao; i++){
        populacao[i].gene = fit(random_numero_double(-20*pi, 20*pi));
        cout << "Gene inicial: " << populacao[i].gene << endl;
    }

    for(; geracao<300; geracao++){
        avaliar(populacao, tamanho_populacao);
        individuo filhos[tamanho_populacao];
        individuo pai;
        individuo mae;
        // Cruzando os 5 indivíduos escolhidos
        for(int i=0; i<tamanho_populacao-1; i++){
            pai = torneio_de_2(populacao[random_numero_int(0, tamanho_populacao)], populacao[random_numero_int(0, tamanho_populacao)]);
            mae = torneio_de_2(populacao[random_numero_int(0, tamanho_populacao)], populacao[random_numero_int(0, tamanho_populacao)]);
            filhos[i] = crossover(pai, mae);
        }

        // PERMANECENDO O MELHOR DE TODOS -- MUDAR (PERMANECENDO O MELHOR DE TODOS A CADA GERAÇÃO PAR)
        if(geracao%2 == 0){  
            filhos[tamanho_populacao-1] = melhor_de_todos;
        }else{
            pai = torneio_de_2(populacao[random_numero_int(0, tamanho_populacao)], populacao[random_numero_int(0, tamanho_populacao)]);
            mae = torneio_de_2(populacao[random_numero_int(0, tamanho_populacao)], populacao[random_numero_int(0, tamanho_populacao)]);
            filhos[tamanho_populacao-1] = crossover(pai, mae);
        }

        avaliar(filhos,tamanho_populacao);

        // Fazendo mutação nos filhos
        for(int i=0; i<tamanho_populacao; i++){
            mutacao(filhos[i]);
        }
        
        // Nova avaliação pós mutação
        avaliar(filhos,tamanho_populacao);

        // Predando (randômica para gerar diversidade)
        for(int i = random_numero_int(1,tamanho_populacao); i < tamanho_populacao; i++){
            predacao(populacao[random_numero_int(0,tamanho_populacao-1)], populacao[random_numero_int(0,tamanho_populacao-1)]);
        } // Pode ser randomica ou por síntese (substitui pela média da população - aumenta a convergencia e diminui a diversidade)                        )

        avaliar(populacao, tamanho_populacao);

        // Copiando os filhos para a população
        for(int i=0; i<tamanho_populacao; i++){
            populacao[i] = filhos[i];
        }        
    }
    
    // impressao(populacao, tamanho_populacao);


    return melhor_de_todos.gene;
}





// APERTAR F6 PRA COMPILAR E RODAR


// Problemas - Não está aparecendo o melhor de todos (ou ele tá igual a outro cara)