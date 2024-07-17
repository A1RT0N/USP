#include <bits/stdc++.h>
using namespace std;

bool is_prime(int x) {
    if (x < 2) {
        return false;
    }
    for (int i = 2; i <= sqrt(x); ++i) {
        if (x % i == 0) {
            return false;
        }
    }
    return true;
}

int maior(int numero_floor_divido_por_2, int parametro){
    
    while(numero_floor_divido_por_2 >=1){
        if(!is_prime(numero_floor_divido_por_2) && !is_prime(parametro - numero_floor_divido_por_2)){
            return numero_floor_divido_por_2;
        }
        numero_floor_divido_por_2--;
    }

    return -1;
}


int main(){
    int n;
    cin >> n;
    int v[n];

    int resposta;

    for(int i =0; i< n ; i++){
        cin >> v[i];
    }
    for(int i =0; i< n; i++){
        resposta = maior(v[i]/2, v[i]);
        if(resposta == -1){
            cout << -1 << endl;
        }else{
            cout << resposta << " " << v[i] - resposta << endl;
        }

    }

    return 0;

}