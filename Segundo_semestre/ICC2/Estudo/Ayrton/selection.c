void selectionsort_aprimorado(int v[], int n){
    int i, j, min, aux;
    for (i=0; i<n-1; i++){
        min=i;
        for (j=i+1; j<n; j++){
            if (v[j]<v[min]){
                min=j;
            }
        }
        aux=v[min] ;
        v[min]=v[i];
        v[i]=aux;    /// Swap entre v[min] e v[i]
    }
}

int main() {
    int vetor[6] = {15, 34, 11, 2, 8000, 17};

    selectionsort_aprimorado(vetor, 6);

    for (int i = 0; i < 6; i++) {
        printf("%d ", vetor[i]);
    }

    return 0;
}
