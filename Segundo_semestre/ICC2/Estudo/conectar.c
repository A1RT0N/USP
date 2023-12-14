#include <stdio.h>
#include <stdlib.h>

struct conect
{
    int num;
    struct conect *prox;
    
    
};
typedef struct conect conectar;


void criar (conectar **tcabeca, conectar ** tcauda, int tam){
    conectar *anterior = (conectar *)malloc(sizeof(conectar));
    anterior = (*tcabeca);
    for(int i=1; i<tam; i++){
        conectar * nova;
        nova = (conectar *)malloc(sizeof(conectar)); // Tá na heap, por isso não apaga
        (anterior)->prox = nova;
        nova->prox = (*tcauda);
        scanf("%d", &nova->num);
        anterior = nova;
    }
}


int main(){
    int tam1, tam2;
    conectar *t1cabeca;
    conectar *t1cauda;
    conectar *t2cabeca;
    conectar *t2cauda;
    conectar *terc;
    scanf("%d", &tam1);
    t1cauda = NULL;
    t1cabeca->prox = t1cauda;
    scanf("%d", &t1cabeca->num);
    criar(&t1cabeca, &t1cauda, tam1);
    
    scanf("%d", &tam2);
    t2cauda = NULL;
    t2cabeca->prox = t2cauda;
    scanf("%d", &t2cabeca->num);
    criar(&t2cabeca, &t2cauda, tam2);

    conectar *i = t1cabeca;
    conectar *j = t2cabeca;
    conectar *l = terc->prox;
    while (1)
    {
        if(i == NULL){
            for(conectar *k = j; k!= NULL; k=k->prox){
                l->num = k->num;
                l=l->num;
            }
        }
        if(j == NULL){
            for(conectar *k = i; k!= NULL; k=k->prox){
                l->num = k->num;
                l=l->num;
            }
        }
        if(j->num > i->num){
            l->num = i->num;
            i = i->prox; // i++
            l= l->prox;
            
        } else{
            l->num = j->num;
            j = j->prox;
            l= l->prox;
        }
    }
    
    
    
    return 0;

}
