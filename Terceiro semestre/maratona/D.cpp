#include <bits/stdc++.h>

using namespace std;

int main(void){
    long long int e; cin >> e;
    long long int v; cin >> v;
    int horas, minutos;

    if(v == 0) {
        int horas = 19;
        int minutos = 0;

    } else {
        long double t;
        t = double(e) /  double(v);
        int a = e/v;

        horas = (19 + int(t)) % 24;

        /*
        int min = (((int((t * 100)) % 100) * 6));

        int minutos = min / 10;
        if(minutos * 10 < min) minutos++;
        */

        long double teste = t - double(a);
        teste = teste * 60;
        teste += 0.5 - (teste < 0);
        minutos = int(teste);
    }


    cout << setfill('0') << setw(2) << horas << ":" <<  setfill('0') << setw(2) << minutos << endl;
}