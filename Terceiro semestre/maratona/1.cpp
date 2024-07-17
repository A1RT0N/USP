#include <bits/stdc++.h>
using namespace std;

// Função que dado o index_atual, retorna o maximo index que ele consegue chegar
int maximum(int *distancia, int tabaco_atual, int tamanho_vetor, int index_atual){

    while(index_atual < tamanho_vetor && ((tabaco_atual - distancia[index_atual]) >= 0)){
        index_atual++;
    }
    return index_atual;
}

// index maximo conta o index que ele pode ir. Mas a partir dele nao da pra ir mais
int qual_casa_eh_melhor(int *distancia, int *tabaco_casa, int index_atual, int tabaco_atual, int tamanho_vetor){ 
    // funcao que retorna qual casa eh melhor pra ele ir

    int maximo = maximum(distancia, tabaco_atual, tamanho_vetor, index_atual);
    
    int qual_casa_esse_index_consegue_chegar = 0;
    int qual_casa_o_melhor_index_consegue_chegar = -1;
    int melhor_casa = -1;
    for(int i = index_atual; i <= maximo; i++){
        // Quero saber qual em que index o index_atual consegue chegar.
        // Se for maior que o index do melhor, troca
        int j = i+1;
        while(j < tamanho_vetor && tabaco_casa[i] - distancia[j] >=0){
            j++;
        }
        qual_casa_esse_index_consegue_chegar = j;

        if(qual_casa_esse_index_consegue_chegar > qual_casa_o_melhor_index_consegue_chegar){
            qual_casa_esse_index_consegue_chegar = qual_casa_o_melhor_index_consegue_chegar;
            melhor_casa = i;
        }

    }

    return melhor_casa;


}

int main(){

    int n, tabaco_inicial;
    int distancia[n];
    int tabaco_casa[n];

    cin >> n >> tabaco_inicial;
    for(int i =0; i< n; i++){
        cin >> distancia[i];
    }

    for(int i =0; i< n; i++){
        cin >> tabaco_casa[i];
    }

    cout << qual_casa_eh_melhor(distancia,tabaco_casa, 0, tabaco_inicial, n);

    // if(tabaco_inicial > distancia[n-1]){
    //     cout << 0 << endl;
    //     return 0;
    // }

    // int index_onde_esta = 0;

    // int resultado = -1;

    // while(index_onde_esta != n){




    //     index_onde_esta++;

    // }




    return 0;
}