// Aqui vai meu primeiro algoritmo de busca em profundidade usando pilhas

// Na implementação que eu fiz, na hora de empilhar uma coordenada eu empilhava duas coisas na pilha (o x e o y)

/*
Ele empilha nessa ordem

pra baixo
pra esquerda
pra cima
pra direita

já que ele empilha a direita por ultimo, ele prioriza essa direção
quando não tiver como ir pra direita, ele prioriza ir pra cima
quando não tiver cima, vai pra esquerda
quando n tiver esquerda, vai pra baixo
*/

#include <stdio.h>
#include "item.h"
#include "Pilha.h"
#include <stdlib.h>
#include <stdbool.h>

int main(){

    int n_linhas, m_colunas;
    scanf("%d %d", &n_linhas, &m_colunas);
    int matriz[n_linhas][m_colunas];

    PILHA *p = pilha_criar();

    for(int i=0;i<n_linhas;i++){
        for(int j =0;j<m_colunas;j++){
            scanf("%d", &matriz[i][j]);
        }
    }

    // Toda vez que eu desempilhar um elemento eu tenho que printá-lo7

    ITEM *inicialx = item_criar(0);
    ITEM *incialy = item_criar(0);

    // EMPILHAR X E DEPOIS Y. DESEMPILHAR Y E DEPOIS X

    // Só falta colocar o zero agora

    pilha_empilhar(p,inicialx);
    pilha_empilhar(p,incialy);

    while(!pilha_vazia(p)){

        ITEM *itemy = pilha_desempilhar(p);  
        ITEM *itemx = pilha_desempilhar(p);

        if(matriz[item_get_chave(itemx)][item_get_chave(itemy)] == 2){
            printf("(%d, %d)\n", item_get_chave(itemx), item_get_chave(itemy));
            return 0;
        }

        if(matriz[item_get_chave(itemx)][item_get_chave(itemy)] == 0) continue ;

        matriz[item_get_chave(itemx)][item_get_chave(itemy)] = 0;

        printf("(%d, %d)\n", item_get_chave(itemx), item_get_chave(itemy));

        if(((item_get_chave(itemx))+1 != n_linhas) && (matriz[item_get_chave(itemx)+1][item_get_chave(itemy)] != 0)){
            ITEM *tmpx, *tmpy;
            tmpx = item_criar(item_get_chave(itemx) + 1);
            tmpy = item_criar(item_get_chave(itemy));
            pilha_empilhar(p,tmpx);
            pilha_empilhar(p,tmpy);
        }
            
        if((item_get_chave(itemy)>0) && (matriz[item_get_chave(itemx)][item_get_chave(itemy)-1] != 0)){
                ITEM *tmpx, *tmpy;
                tmpx = item_criar(item_get_chave(itemx));
                tmpy = item_criar(item_get_chave(itemy)-1);
                pilha_empilhar(p,tmpx);
                pilha_empilhar(p,tmpy);
        }


        if((item_get_chave(itemx)>0) && (matriz[item_get_chave(itemx)-1][item_get_chave(itemy)] != 0)){
            ITEM *tmpx, *tmpy;
            tmpx = item_criar(item_get_chave(itemx) - 1);
            tmpy = item_criar(item_get_chave(itemy));
            pilha_empilhar(p,tmpx);
            pilha_empilhar(p,tmpy);

        }

        if((item_get_chave(itemy)+1 != m_colunas) && (matriz[item_get_chave(itemx)][item_get_chave(itemy)+1] != 0)){
                ITEM *tmpx, *tmpy;
                tmpx = item_criar(item_get_chave(itemx));
                tmpy = item_criar(item_get_chave(itemy)+1);
                pilha_empilhar(p,tmpx);
                pilha_empilhar(p,tmpy);

            }

    }
    printf("Saída não encontrada.");

    return 0;
}




/*
PASSO A PASSO:

01- OLHAR PRA TODOS OS LADOS E EMPILHAR NA ORDEM (DIREITA É O ÚLTIMO)

02 - Desempilhar o último e armazenar esse desempilhado na variável

2.1 - Analisar se a pilha está vazia


04 - Agora a matriz está na posição da nova variável

05 - Voltar no loop


/*

#include<bits/stdc++.h>
using namespace std ; 
 
// baixo esq cima dir 
 
const int maxn = 505 ; 
 
int v[maxn][maxn] ;
 
int dx[4] = {1, 0, -1, 0} ;
int dy[4] = {0, -1, 0, 1} ;
 
bool valid(int i, int j, int n, int m){ return (i >= 0 && j >= 0 && i < n && j < m) ; }
 
int main(){
 
    int n, m ; cin >> n >> m ; 
 
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++) 
        cin >> v[i][j] ;
    }
 
    stack<pair<int,int>> fila ; 
 
    fila.push({0, 0}) ; 
    v[0][0] = 0 ; 
 
    bool ok = 0 ; 
 
    while(!fila.empty()){
        pair<int,int> at = fila.top() ; 
        fila.pop();
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
 
}
*/



