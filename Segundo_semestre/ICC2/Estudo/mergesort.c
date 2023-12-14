#include <stdio.h>
void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n){
    int i=nums1Size-m-1, j=n-1;
        while(nums1Size!=0){
            if(nums1[i]>=nums2[j]){
                nums1[nums1Size-1] = nums1[i];
                i--;
            } else{
                nums1[nums1Size-1] = nums2[j];
                j--;
            }
            nums1Size--;
        }
}

int main(){
    int nums1[6] = {1,2,3,0,0,0};
    int nums2[3] = {2,5,6};
    merge(nums1, 6, 3, nums2, 3, 3);
    for(int i=0; i<6; i++){
        printf("%d ", nums1[i]);
    }
    return 0;
}



/*

#include <stdio.h>

void InsertionSort(int vetor[], int ini, int fim) {
    int i, chave, j;

    for (i = ini; i <= fim; i++) {
        chave = vetor[i];
        j = i - 1;

        while (j >= ini && vetor[j] > chave) {
            vetor[j + 1] = vetor[j];
            j--;
        }
        vetor[j + 1] = chave;
    }

    for (int i = ini; i <= fim; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");
}

void Merge(int vetor[], int ini, int meio, int fim) {
    int n1 = meio - ini + 1;
    int n2 = fim - meio;

    int L[n1], R[n2];

    for (int i = 0; i < n1; i++) {
        L[i] = vetor[ini + i];
    }
    for (int j = 0; j < n2; j++) {
        R[j] = vetor[meio + 1 + j];
    }

    int i = 0, j = 0, k = ini;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            vetor[k] = L[i];
            i++;
        } else {
            vetor[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        vetor[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        vetor[k] = R[j];
        j++;
        k++;
    }
}

void MergeSort(int vetor[], int ini, int fim, int k) {
    if ((fim - ini) <= k) {
        InsertionSort(vetor, ini, fim);
    } else {
        int meio = ini + (fim - ini) / 2;

        MergeSort(vetor, ini, meio, k);
        MergeSort(vetor, meio + 1, fim, k);

        Merge(vetor, ini, meio, fim);
    }
}

int main() {
    int vetor[10] = {1, 9, 3, 4, 5, 7, 2, 10, 12, 13};
    for (int i = 0; i < 10; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n\n");

    MergeSort(vetor, 0, 9, 5);
    
    for (int i = 0; i < 10; i++) {
        printf("%d ", vetor[i]);
    }
    
    return 0;
}

*/