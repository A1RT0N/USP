#include <stdio.h>
#include "item.h"
#include "fila.h"
#include <stdlib.h>
#include <stdbool.h>



bool valid(int i, int j, int n, int m){ return (i >= 0 && j >= 0 && i < n && j < m) ;}

void imprimir_matriz(int n, int m, int matriz[][m]){
    for(int i=0;i<n;i++){
        for(int j =0;j<m;j++){
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }


}

int main(){

    int n_linhas, m_colunas;
    scanf("%d %d", &n_linhas, &m_colunas);
    int matriz[n_linhas][m_colunas];

    FILA *fila = fila_criar();

    for(int i=0;i<n_linhas;i++){
        for(int j =0;j<m_colunas;j++){
            scanf("%d", &matriz[i][j]);
        }
    }

    imprimir_matriz(n_linhas,m_colunas, matriz);


    int dx[4] = {1, 0, -1, 0} ;  
    int dy[4] = {0, -1, 0, 1} ;


    // INSIRO X E DEPOIS Y E RETIRO X E DEPOIS Y


    ITEM* item;
    int vet[2] = {0,0};
    item = item_criar(vet);
    fila_inserir(fila,item);

    bool ok = false;

    while(!fila_vazia(fila)){
        item = fila_frente(fila);
        fila_remover(fila);

        item_imprimir(item);

        if(ok) break;

        for(int i = 0; i<4; i++){
            int atx = item_get_chave(item)[0] + dx[i];
            int aty = item_get_chave(item)[1] + dy[i];
            if(!valid(atx,aty,n_linhas,m_colunas)|| matriz[atx][aty] == 0) continue; 
            if(matriz[atx][aty] == 2){
                ok = true;
            }
            matriz[atx][aty] = 0;
            vet[0] = atx;
            vet[1] = aty;



            item_set_chave(item, vet);
            matriz[atx][aty] = 0;

            fila_inserir(fila,item); 

        }

    }



    return 0;
}


/*
while(!fila.empty()){
        pair<int,int> at = fila.top() ; 
        fila.pop() ;
        cout << at.first << " " << at.second << "\n" ;
        if(ok) 
        break ; 
        for(int i = 0 ; i < 4 ; i++){
            int atx = at.first + dx[i] ; 
            int aty = at.second + dy[i] ;
            if(!v[atx][aty] || !valid(atx, aty, n, m)) 
            continue ; 
            if(v[atx][aty] == 2) 
            ok = 1 ; 
            v[atx][aty] = 0 ; 
            fila.push({atx, aty}) ;
        }
    }

*/