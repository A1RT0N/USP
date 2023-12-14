void swap(int *a, int *b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int comparation(int *v, int inicio, int pivo, int fim){
    
    while(inicio != fim){
        if(v[inicio] >= pivo && v[fim] <= pivo){
            swap(&v[inicio], &v[fim]);
        }else{
            if(v[inicio] <= pivo){
                inicio++;
            }else{
                fim--;
            }
        }
    }
    int index;
    for(int i=0; i<fim; i++){
        if(v[i] == pivo){
            index = i;
            return index;
        }
    }

}


void quicksort(int v[], int inicio, int fim){
    if(inicio<fim){
        int pivo = (inicio+fim)/2;

        pivo = comparation(v, inicio, v[pivo], fim);

        quicksort(v, pivo+1, fim);
        quicksort(v, inicio, pivo-1);
        
    }

}


int main(){
    int v[5] = {23, 3, 11, 2, 50};
    quicksort(v,0,4);
    for(int i =0; i<5; i++){
        printf("%d ", v[i]);
    }
    printf("\n");
}


