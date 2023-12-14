#include <iostream>
#include <queue>
#include <vector>


using namespace std;

int digitos(int z){
    int contador = 0;
    float n = float(z);
    while(n>=1){
        n /= 10;
        contador++;
    }

    return contador;
}

int numero_do_digito(int n, int k){ // k é a posição do dígito que se quer, sendo 1 a da unidade. Ex: n = 35162 e k = 2 -> return 6
    int res = 0;
    for(int i = 0; i<k; i++){
        res = n%10;
        n /= 10;
    }
    return res;
}

int maior_quantidade_digito_no_vetor(int *v, int n){
    int resultado = 1;
    for(int i=0; i<n;i++){
        if(resultado < digitos(v[i])) resultado = digitos(v[i]);
    }
    return resultado;
}

void radix(int *v, int n){
    vector<queue<int>> vetorDeFilas(10);

    int casa_decimal_do_MSD =  maior_quantidade_digito_no_vetor(v,n);

    for(int i = 1; i<= casa_decimal_do_MSD; i++){  // Evidente o O(n.k)
        for(int j=0; j< n; j++){
            vetorDeFilas[numero_do_digito(v[j],i)].push(v[j]);
        }

        for(int j=0, index = 0; j< 10; j++){
            while(!vetorDeFilas[j].empty()){
                v[index] = vetorDeFilas[j].front();
                vetorDeFilas[j].pop();
                index++;
            }
        }

    }


}

int main(){
    
    int v[] = {8,22,77,33,965,121, 33, 19, 22};

    radix(v,9);

    for(int i =0; i< 9; i++){
        cout << v[i] << endl;
    }


    return 0;
}