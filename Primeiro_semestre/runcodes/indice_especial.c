#include <stdio.h>

int ordenar(int arr[], int n){
    int indice = -1;
    for (int k=0; k<n; k++){
        int smd =0, sme = 0;
        for (int j=k+1; j<n; j++){
            smd += arr[j];
        }
        
        for (int p=k-1; p>=0; p--){
            sme += arr[p];
        }
        if (sme == smd){
            indice = k;
        }
    }
    return indice;
}


int main()
{
    int n;
    scanf("%d", &n);
    int v[n];
    for (int i=0; i<n; i++){
        scanf("%d", &v[i]);    
    }
    int a= ordenar(v, n);
    printf("%d", a);

    return 0;
}
