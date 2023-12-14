#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
int hh;
int mm;
int ss;
} horario;

typedef struct {
int prior;

horario chegada;

char descricao[51];

} celula;

int converte_horario(celula cel){
    int t1 = cel.chegada.hh;
    int t2 = cel.chegada.mm;
    int t3 = cel.chegada.ss;

    return t3 + (t2 * 100) + (t1 * 10000);
}

int busca_prio(celula *vet, int tamanho, celula operaocao){
    int inicio = 0;
    int fim = tamanho - 1;

    int index;

    while (fim >= inicio){
        index = (inicio + fim) / 2;

        if (operaocao.prior == vet[index].prior){
            return index;
        }

        if (operaocao.prior > vet[index].prior){
            inicio = index + 1;
        }else{
            fim = index - 1;
        }
    }

    return inicio;
}

int busca_temp(celula *vet, int tamanho, celula operaocao){
    int inicio = 0;
    int fim = tamanho - 1;

    int index;

    while (fim >= inicio){
        index = (inicio + fim) / 2;

        if (converte_horario(operaocao) == converte_horario(vet[index])){
            return index;
        }

        if (converte_horario(operaocao) > converte_horario(vet[index])){
            inicio = index + 1;
        }else{
            fim = index - 1;
        }
    }

    return inicio;
}

void swap(celula *v, int i, int j){
    celula tmp;

    tmp = v[i];

    v[i] = v[j];

    v[j] = tmp;
}

int partition_prio(celula *v, int ini, int fim){
    int pivo;

    pivo = (ini + fim) / 2;

    swap(v, pivo, fim);

    pivo = v[fim].prior; 

    int i = ini - 1;
    
    for (int j = ini; j < fim; j++){
        if (v[j].prior < pivo){
            i++;

            swap(v, i, j);
        }
    }

    i++;

    swap(v, i, fim);

    return i;
}

void quicksort_prio(celula *v, int ini, int fim){
    if (fim <= ini) return; //caso base

    int pivo = partition_prio(v, ini, fim);

    quicksort_prio(v, ini, pivo - 1);
    quicksort_prio(v, pivo + 1, fim);
}

int partition_temp(celula *v, int ini, int fim){
    int pivo;

    pivo = (ini + fim) / 2;

    swap(v, pivo, fim);

    pivo = converte_horario(v[fim]); 

    int i = ini - 1;
    
    for (int j = ini; j < fim; j++){
        if (converte_horario(v[j]) < pivo){
            i++;

            swap(v, i, j);
        }
    }

    i++;

    swap(v, i, fim);

    return i;
}

void quicksort_temp(celula *v, int ini, int fim){
    if (fim <= ini) return; //caso base

    int pivo = partition_temp(v, ini, fim);

    quicksort_temp(v, ini, pivo - 1);
    quicksort_temp(v, pivo + 1, fim);
}

void adicionar(celula *vet, int tamanho){
    celula opera;

    scanf(" %02d", &(opera.prior));

    scanf(" %02d:%02d:%02d", &opera.chegada.hh, &opera.chegada.mm, &opera.chegada.ss);

    scanf(" %s", opera.descricao);

    vet[tamanho] = opera; //adicionar a nova operação
}

void remover(celula *vet, int tamanho){
    for (int i = 0; i < tamanho; i++){
        vet[i] = vet[i + 1];
    }
}

void executar(celula *vet, int *estado, int tamanho){
    char opcao;

    scanf(" -%c", &opcao);

    if (opcao == 'p'){
        if (*estado != 1){
            *estado = 1;

            quicksort_prio(vet, 0, tamanho - 1);
        }

        celula cel = vet[tamanho - 1];

    } else{
        if (*estado != 2){
            *estado = 2;

            quicksort_temp(vet, 0, tamanho - 1);
        }

        celula cel = vet[0];
        
        remover(vet, tamanho);
    }
}

void proximo(celula *vet, int *estado, int tamanho){
    char opcao;

    scanf(" -%c", &opcao);

    if (opcao == 'p'){
        if (*estado != 1){
            *estado = 1;

            quicksort_prio(vet, 0, tamanho - 1);
        }

        celula cel = vet[tamanho - 1];

        printf("%02d %02d:%02d:%02d %s\n\n", cel.prior, cel.chegada.hh, cel.chegada.mm, cel.chegada.ss, cel.descricao);
        
    }else{
        if (*estado != 2){
            *estado = 2;

            quicksort_temp(vet, 0, tamanho - 1);
        }

        celula cel = vet[0];

        printf("%02d %02d:%02d:%02d %s\n\n", cel.prior, cel.chegada.hh, cel.chegada.mm, cel.chegada.ss, cel.descricao);
    }
}

void change(celula *vet, int *estado, int tamanho){
    char opcao;

    scanf(" -%c", &opcao);

    celula tmp;

    if (opcao == 'p'){
        if (*estado != 1){
            *estado = 1;

            quicksort_prio(vet, 0, tamanho - 1);
        }

        int novo;

        scanf(" %02d|%02d", &tmp.prior, &novo);

        int index = busca_prio(vet, tamanho, tmp);

        vet[index].prior = novo;
    }else{
        if (*estado != 2){
            *estado = 2;

            quicksort_temp(vet, 0, tamanho - 1);
        }

        int t1, t2, t3;

        scanf(" %02d:%02d:%02d|%02d:%02d:%02d", &tmp.chegada.hh, &tmp.chegada.mm, &tmp.chegada.ss, &t1, &t2, &t3);

        int index = busca_temp(vet, tamanho, tmp);

        vet[index].chegada.hh = t1;
        vet[index].chegada.mm = t2;
        vet[index].chegada.ss = t3;
    }
}

void printar(celula *vet, int *estado, int tamanho){
    char opcao;

    scanf(" -%c", &opcao);

    if (opcao == 'p'){
        if (*estado != 1){
            *estado = 1;

            quicksort_prio(vet, 0, tamanho - 1);
        }
        
        for (int i = tamanho - 1; i >= 0; i--){
            printf("%02d %02d:%02d:%02d %s\n", vet[i].prior, vet[i].chegada.hh, vet[i].chegada.mm, vet[i].chegada.ss, vet[i].descricao);
        }

        printf("\n");

    } else{
        if (*estado != 2){
            *estado = 2;

            quicksort_temp(vet, 0, tamanho - 1);
        }
        
        for (int i = 0; i < tamanho; i++){
            printf("%02d %02d:%02d:%02d %s\n", vet[i].prior, vet[i].chegada.hh, vet[i].chegada.mm, vet[i].chegada.ss, vet[i].descricao);
        }
    }
}

int main(void){
    celula vet[100]; //pelo caso teste assumismo 100 para o número de operações

    int tamanho = 0;

    char operacao[7];

    int estado = 0; //estado do vetor. 0 para desorganizado, 1 para ordenado por meio da priopridade e 2 ordenado pelo tempo

    while(scanf(" %s", operacao)){
        if (strcmp(operacao, "quit") == 0) break;
        
        if (strcmp(operacao, "add") == 0){
            adicionar(vet, tamanho);

            tamanho ++;

            estado = 0;
            
            continue;
        }

        if (strcmp(operacao, "exec") == 0){
            executar(vet, &estado, tamanho);

            tamanho --;
            
            continue;
        }

        if (strcmp(operacao, "next") == 0){
            proximo(vet, &estado, tamanho);
            
            continue;
        }

        if (strcmp(operacao, "change") == 0){
            change(vet, &estado, tamanho);
            
            continue;
        }

        if (strcmp(operacao, "print") == 0){
            printar(vet, &estado, tamanho);
            
            continue;
        }
    }
}