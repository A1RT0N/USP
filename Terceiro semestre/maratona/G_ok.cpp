#include <bits/stdc++.h>
using namespace std;

// Função que dado o index_atual, retorna o máximo index que ele consegue chegar
int maximum(int *distancia, int tabaco_atual, int tamanho_vetor, int index_atual) {
    int index_resultado = index_atual;
    while(index_atual < tamanho_vetor && ((tabaco_atual - (distancia[index_resultado] - distancia[index_atual])) >= 0)) {
        index_resultado++;
    }
    return index_resultado - 1;
}

// Função que retorna qual casa é melhor pra ele ir
int qual_casa_eh_melhor(int *distancia, int *tabaco_casa, int index_atual, int tabaco_atual, int tamanho_vetor) {
    int maximo = maximum(distancia, tabaco_atual, tamanho_vetor, index_atual);

    int qual_casa_esse_index_consegue_chegar = 0;
    int qual_casa_o_melhor_index_consegue_chegar = -1;
    int melhor_casa = -1;
    for(int i = index_atual; i <= maximo; i++) {
        // Quero saber até que index o index_atual consegue chegar.
        // Se for maior que o index do melhor, troca
        int j = i + 1;
        int tabaco_restante = tabaco_casa[i] - (distancia[i] - distancia[j]);
        // cout << i << " " << tabaco_restante << endl;
        while(j < tamanho_vetor && tabaco_restante >= 0) {
            j++;
            if (j < tamanho_vetor) {
                tabaco_restante -= distancia[j];
            }
        }
        qual_casa_esse_index_consegue_chegar = j;

        // cout << "Respostas";
        // cout << i << maximo << endl;
        // cout << qual_casa_esse_index_consegue_chegar << endl;

        if(qual_casa_esse_index_consegue_chegar > qual_casa_o_melhor_index_consegue_chegar) {
            qual_casa_o_melhor_index_consegue_chegar = qual_casa_esse_index_consegue_chegar;
            melhor_casa = i;
        }
    }

    return melhor_casa;
}

int main() {
    int n, tabaco_inicial;
    cin >> n >> tabaco_inicial;
    
    // Inicializando os arrays com o tamanho correto
    int distancia[n];
    int tabaco_casa[n];

    for(int i = 0; i < n; i++) {
        cin >> distancia[i];
    }

    for(int i = 0; i < n; i++) {
        cin >> tabaco_casa[i];
    }

    int resultado = 0;
    int index_atual = 0;
    int tabaco_atual = tabaco_inicial;
    
    while(index_atual < n - 1) {
        int tmp = qual_casa_eh_melhor(distancia, tabaco_casa, index_atual, tabaco_atual, n);
        
        if(tmp == -1 || tmp == index_atual) {
            resultado = -1;
            break;
        }

        tabaco_atual = tabaco_casa[tmp];
        index_atual = tmp;
        resultado++;
    }

    cout << resultado  << endl;


    return 0;
}



