#include <bits/stdc++.h>
using namespace std;

// Função que mostra quantos peões são atacados na casa i, j
int quantos_peoes_sao_atacados(int k, int l, int i, int j, int tamanho_de_i, int tamanho_de_j, int** vetor_de_peoes) {
    int atacados = 0;

    int movimentos[4][2] = {{-k, l}, {k, -l}, {-k, -l}, {k, l}};
    
    for (auto movimento : movimentos) {
        int novo_i = i + movimento[0];
        int novo_j = j + movimento[1];
        
        if (novo_i >= 0 && novo_i < tamanho_de_i && novo_j >= 0 && novo_j < tamanho_de_j && vetor_de_peoes[novo_i][novo_j] == 1) {
            atacados++;
        }
    }

    return atacados;
}

int main() {
    int n, m, k, l;
    cin >> n >> m >> k >> l;

    int** vetor_pesos = new int*[n];
    for (int i = 0; i < n; i++) {
        vetor_pesos[i] = new int[m];
    }

    char tmp;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> tmp;
            if (tmp == '.') {
                vetor_pesos[i][j] = 0;
            } else {
                vetor_pesos[i][j] = 1;
            }
        }
    }

    int res_1 = -1, res_2 = -1;
    int temporario;
    int maior_de_todos = -1;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (vetor_pesos[i][j] == 1) continue;
            temporario = quantos_peoes_sao_atacados(k, l, i, j, n, m, vetor_pesos) + quantos_peoes_sao_atacados(l, k, i, j, n, m, vetor_pesos);
            if (temporario > maior_de_todos) {
                res_1 = i + 1;
                res_2 = j + 1;
                maior_de_todos = temporario;
            }
        }
    }

    cout << res_1 << " " << res_2 << endl;


    return 0;
}