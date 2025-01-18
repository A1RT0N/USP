// Função hash: h(k) = (k+i)%B
// Marcação de espaço de espaço livre(vazia) é -1 e da remocao pra busca é -2

int h(int k, int i, int B){
    return ((k+i)%B);
}

void insercao_hash(int *v, int buckets, int elemento){
    for(int i =0; i< buckets-1; i++){ // rehash
        if(v[h(elemento, i, buckets)] < 0){
            v[h(elemento, i, buckets)] = elemento;
            return;
        }
    }

}


int remocao_hash(int *v, int buckets, int elemento){
    for(int i = h(elemento, 0, buckets); i<buckets; i = h(elemento, i+1, buckets)){
        if(v[i] == elemento){
            v[i] = -2;
            return i;
        }
    }
    return -1;
}

int busca_hash(int *v, int buckets, int elemento){
    
    for(int i = h(elemento, 0, buckets); v[i] != -1 && i<buckets; i = h(elemento, i+1, buckets)){
        if(v[i] == elemento){
            return i;
        }
    }

    return -1;
    
}


int main(){

    int buckets = 10;
    int v[10] = {-1};


}