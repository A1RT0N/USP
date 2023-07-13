#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void troca_palavra_matriz(char* k[], int i, int j);
void ordena(char* k[], int tamanho_vetor);
void imprime_ao_sair(char* k[], int tamanho_vetor);
void free_mat(char** mat, int n);

void troca_palavra_matriz(char* k[], int i, int j) {
    char* aux = k[i];
    k[i] = k[j];
    k[j] = aux;
}

void ordena(char* k[], int tamanho_vetor) {
    int i, j;
    for (i = 0; i < tamanho_vetor; i++) {
        for (j = i + 1; j < tamanho_vetor; j++) {
            if (strcmp(k[i], k[j]) > 0) {
                troca_palavra_matriz(k, i, j);
            }
        }
    }
}

void imprime_ao_sair(char* k[], int tamanho_vetor) {
    int i;
    for (i = 0; i < tamanho_vetor; i++) {
        printf("%d) %s\n", i+1, k[i]);
    }
}

void free_mat(char** mat, int n) {
    int i;
    for (i = 0; i < n; i++) {
        free(mat[i]);
    }
    free(mat);
}

int main() {
    int tamanho_vetor = 0;
    char** vetor_imprime = NULL;
    char vetor_analise[200];

    while (scanf("%s", vetor_analise) != EOF) {
        int tamanho_palavra = strlen(vetor_analise);

        if (tamanho_palavra > 0 && strcmp(vetor_analise, "sair") != 0) {
            tamanho_vetor++;
            vetor_imprime = (char**)realloc(vetor_imprime, tamanho_vetor * sizeof(char*));
            vetor_imprime[tamanho_vetor - 1] = (char*)malloc((tamanho_palavra + 1) * sizeof(char));
            strcpy(vetor_imprime[tamanho_vetor - 1], vetor_analise);
        }
        else {
            if (strcmp(vetor_analise, "sair") == 0) {
                ordena(vetor_imprime, tamanho_vetor);
                imprime_ao_sair(vetor_imprime, tamanho_vetor);
                free_mat(vetor_imprime, tamanho_vetor);
                return 0;
            }
        }
    }

    return 0;
}