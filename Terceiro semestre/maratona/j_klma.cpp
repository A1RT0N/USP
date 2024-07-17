#include <bits/stdc++.h>
using namespace std;

// Função que mostra quantos peões são atacados na casa i, j
int quantos_peoes_sao_atacados(int k, int l, int i, int j, int tamanho_de_i, int tamanho_de_j, int** vetor_de_peoes) {
    int atacados = 0;

    int movimentos[8][2] = {
        {-k, l}, {-k, -l}, {k, l}, {k, -l},
        {-l, k}, {-l, -k}, {l, k}, {l, -k}
    };

    for(int m = 0; m < 8; m++) {
        int ni = i + movimentos[m][0];
        int nj = j + movimentos[m][1];

        if (ni >= 0 && ni < tamanho_de_i && nj >= 0 && nj < tamanho_de_j && vetor_de_peoes[ni][nj] == 1) {
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
    int maior_de_todos = -1;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (vetor_pesos[i][j] == 0) { 
                int temporario = quantos_peoes_sao_atacados(k, l, i, j, n, m, vetor_pesos);
                if (temporario > maior_de_todos || (temporario == maior_de_todos && (res_1 > i || (res_1 == i && res_2 > j)))) {
                    res_1 = i;
                    res_2 = j;
                    maior_de_todos = temporario;
                }
            }
        }
    }

    cout << res_1 + 1 << " " << res_2 + 1 << endl;

    for (int i = 0; i < n; i++) {
        delete[] vetor_pesos[i];
    }
    delete[] vetor_pesos;

    return 0;
}