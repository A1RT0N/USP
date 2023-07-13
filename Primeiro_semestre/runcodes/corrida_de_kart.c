
#include <stdio.h>

int main()
{
    int n, tempo;
    float via, vib;
    float distancia_a, distancia_b;
    scanf("%d", &n);
    for (int i = 0; i<n ; i++){
        scanf("%f %f", &via, &vib);
        scanf("%d", &tempo);
        distancia_a = tempo*via;
        distancia_b = tempo*vib;
        if (tempo == 0){
            printf("A corrida ainda nao comecou\n");
        } else{
            if (via == 0 && vib == 0){
                printf("Os dois pilotos nao querem competir\n");
            } else{
                if(via == 0){
                    printf("O piloto A desistiu inesperadamente\n");
                } else{
                if (vib == 0){
                    printf("O piloto B desistiu inesperadamente\n");
                } else{
                    if (tempo<0){
                        printf("De alguma forma os pilotos voltaram no tempo\n");
                    } else{
                        if (via == vib){
                            printf("Os karts empataram, percorrendo cada %.2fkm\n", distancia_b);
                            
                        } else{
                            if (distancia_a > distancia_b){
                                printf("O kart A venceu e percorreu %.2fkm a mais que o kart B\n", distancia_a - distancia_b);
                            } else{
                                if (distancia_b > distancia_a){
                                    printf("O kart B venceu e percorreu %.2fkm a mais que o kart A\n", distancia_b - distancia_a);
                                }
                            } 
                        }
                    }
                }
        
            }   
            
        }
    }
}
    return 0;
}
    






