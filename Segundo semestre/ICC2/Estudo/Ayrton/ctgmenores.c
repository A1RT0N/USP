void contagem_por_menores(int v[], int n){
    int X[n], B[n], i, j;

    for (i=0; i<n; i++)  //inicializando arranjo auxiliar
        X[i]=0;

    for (i=1; i<n; i++) //contando menores
        for (j=i-1; j>=0; j--)
            if (v[i]<v[j])
                X[j]++;
            else X[i]++;

    for (i=0; i<n; i++) //montando arranjo final
        B[X[i]]=v[i];

    for (i=0; i<n; i++) //copiando arranjo final para original
        v[i]=B[i];
}

int main(){
    int v[9] = {3,7,1,8,2,77,5,0,2};
    contagem_por_menores(v,9);
    for(int i =0; i< 9; i++){
        printf("%d ", v[i]);
    }
}