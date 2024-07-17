#include <iostream>
using namespace std;


int main() {

    int contador = 0;

    int origem[2];
    int destino[2];

    int flag = 1;

    for(int i =0; i<2;i++){
        cin >> origem[i];
    }

    for(int i =0; i<2;i++){
        cin >> destino[i];
    }


    int subtracao[2];

    // O máximo de iteração possível é 2

    while(flag == 0){

        cout << "Oi";

        subtracao[0] = destino[0] - origem[0];
        subtracao[1] = destino[1] - origem[1];

        if(subtracao[0]%subtracao[1] == 0){ // Se tiver na diagonal, achou
            flag = 1;
        }else{
            if(subtracao[0] == 0 || subtracao[1] == 0){ // Se tiver na vertical ou horizontal, achou tbm
                flag = 1;
            }
        }
        contador++;

        origem[0] = destino[0];
        
    }
    
    cout << contador;


	
	return 0;
}
