#include <iostream>
#include <math.h>
using namespace std;
int main(){
    float vetor_genes[10];
    float vetor_genes_ordenados[10];
    float p = 1.9;
    for (int i =0; i< 10; i++){
        vetor_genes[i]= p;
        p += 2.4156;
        cout << vetor_genes[i] << endl;
    }
    cout << endl;
    for (int i=0; i<10;i++){
        int tamanho = 10 -1;
        for(int j=0; j<10;j++){
            if(fabs(10-vetor_genes[j]) > fabs(10-vetor_genes[i])){
                tamanho--;
            }

        }
        vetor_genes_ordenados[tamanho]=vetor_genes[i];
    }
    for(int i=0; i< 10; i++){
        cout << vetor_genes_ordenados[i] << endl;
    }
}