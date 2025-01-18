#include <stdio.h>
#include <stdlib.h>

struct score {
    char pais[4];
    int ouro;
    int prata;
    int bronze;
};

typedef struct score score_t;

void swap_fn(score_t *pais1, score_t *pais2, int *swap) {
    if((*pais1).ouro > (*pais2).ouro) {
        return;
    } else if((*pais1).ouro == (*pais2).ouro) {
        if((*pais1).prata > (*pais2).prata) {
            return;
        } else if((*pais1).prata == (*pais2).prata) {
            if((*pais1).bronze > (*pais2).bronze) {
                return;
            }
        }
           
    }
        
    score_t tmp = *pais1; 
    *pais1 = *pais2;
    *pais2 = tmp;
    (*swap)++;
}

void sort(score_t **list, int size) {
    int swap = 0;
    for(int i = 1; i < size; i++) {
        swap_fn(&((*list)[i - 1]), &((*list)[i]), &swap);
    }
    if(swap == 0) return;
    else sort(list, size);
}

int main() {
    score_t *scores = NULL;
    int num;

    scanf("%d", &num);
    scores = malloc(num * sizeof(score_t));

    for(int i = 0; i < num; i++) {
        score_t score;
        scanf("%s ", score.pais);
        scanf("%d", &score.ouro);
        scanf("%d", &score.prata);
        scanf("%d", &score.bronze);

        scores[i] = score;
    }
    sort(&scores, num);

    for(int i = 0; i < num; i++) {
        printf("%s %d %d %d\n", scores[i].pais, scores[i].ouro, scores[i].prata, scores[i].bronze);
    }

    return 0;
}