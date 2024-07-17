#include <iostream>

using namespace std;

int main() {
    long long int e; 
    cin >> e;
    long long int v; 
    cin >> v;
    int horas, minutos;

    if (v == 0) {
        horas = 19;
        minutos = 0;
    } else {
        double t = static_cast<double>(e) / v;
        
        horas = (19 + static_cast<int>(t)) % 24;

        double frac = t - static_cast<int>(t);
        minutos = static_cast<int>(frac * 60 + 0.5); 
    }

    if (horas < 10) {
        cout << '0';
    }
    cout << horas << ":";

    if (minutos < 10) {
        cout << '0';
    }
    cout << minutos << endl;
    
    return 0;
}