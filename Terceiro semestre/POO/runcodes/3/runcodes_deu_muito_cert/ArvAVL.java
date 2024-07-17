import java.util.ArrayList;

public class ArvAVL extends ArvBin{
    public ArvAVL(int len){
        super(len);
    }

    @Override
    protected void insert(String value){
        super.insert(value); 

        for (int i = this.tamanho - 1; i >= 0; i--){
            if (this.abb[i] == null) continue;

            if (isBalance_aux(i) <= -2){ 
                balancearAVL(i); 
            }
        }
    }


    private void troca_max_esquerda(int index){

        int index_maior_filho;

        int temp = nodeLeft(index);

        while(abb[nodeRight(temp)] != null){
            if(temp > abb.length){
                break;
            }
            temp = nodeRight(temp);
        }

        index_maior_filho = temp;

        String maior = abb[index_maior_filho];

        super.remove(maior);

        abb[index] = maior;




    }

    private void troca_min_direita(int index){
        int index_menor_filho;

        int temp = nodeRight(index);

        while(abb[nodeLeft(temp)] != null){
            if(temp > abb.length){
                break;
            }
            temp = nodeLeft(temp);
        }

        index_menor_filho = temp;

        String menor = abb[index_menor_filho];

        super.remove(menor);

        abb[index] = menor;
    }


    @Override 
    protected boolean remove(String v){

        int index_busca = super.busca_aux(0, v);

        if(index_busca == -1){
            return false;
        }

        if(abb[nodeLeft(index_busca)] != null){
            troca_max_esquerda(index_busca);
        }

        else if(abb[nodeRight(index_busca)] != null){
            troca_min_direita(index_busca);
        }

        else super.remove(v);

        for (int i = this.tamanho - 1; i >= 0; i--){
            if (this.abb[i] == null) continue;

            if (isBalance_aux(i) <= -2){ 
                balancearAVL(i); 
            }
        }


        return true;


    }

    // @Override
    // public boolean remove(String v){
    //     boolean result = super.remove(v); 

    //     for (int i = this.tamanho - 1; i >= 0; i--){
    //         if (this.abb[i] == null) continue;

    //         if (isBalance_aux(i) <= -2){ 
    //             balancearAVL(i); 
    //         }
    //     }

    //     return result;
    // }

    @Override
    protected boolean isBalance() { // Verifica se a árvore está balanceada, de acordo com o critério de cada tipo de árvore. No caso de uma árvore desbalanceada, retorna sempre true pois não existe regra de balanceamento.

        if(isBalance_aux(0) <= -2){
            return false;
        }

        return true;
    }


    // Funções auxiliares

    private int alturaNo(int index) {
        if ((index == -1) || (this.abb[index] == null)) return -1;

        int AlturaFilhoEsq = alturaNo(this.nodeLeft(index)); //altura do filho esquerdo
        int AlturaFilhoDir = alturaNo(this.nodeRight(index)); //altura do filho direito

        return Math.max(AlturaFilhoEsq, AlturaFilhoDir) + 1; //retorna a maior altura mais 1
    }

    private void balancearAVL(int i){ 

        if (alturaNo(this.nodeLeft(i)) - alturaNo(this.nodeRight(i)) == -2){ 
            if ((alturaNo(this.nodeLeft(this.nodeRight(i))) - alturaNo(this.nodeRight(this.nodeRight(i)))) <= 0){ 
                rotacaoEsquerda(i); 
            }else{
                rotacaoDireitaEsquerda(i); 
            }
        }

        if (alturaNo(this.nodeLeft(i)) - alturaNo(this.nodeRight(i)) == 2){
            if ((alturaNo((this.nodeLeft(this.nodeLeft(i)))) - alturaNo((this.nodeRight(this.nodeLeft(i))))) >0 ) { 
                rotacaoDireita(i);
            }else{
                rotacaoEsquerdaDireita(i); 
            }
        }
    }




    private void rotacaoEsquerda(int i){ 

        ArrayList<String> bfs = bfs(i, true); 


        if (bfs.size() - 1 >= 2) super.insert(bfs.get(2)); 

        super.insert(bfs.get(0)); 
        
        super.insert(bfs.get(1)); 

        for (int k = 3; k < bfs.size(); k++){
            super.insert(bfs.get(k));
        }

    }

    private void rotacaoDireita(int i){
        ArrayList<String> bfs = bfs(i, true); 

        if (bfs.size() - 1 >= 1) super.insert(bfs.get(1)); 
        super.insert(bfs.get(0)); 
        
        for (int k = 2; k < bfs.size(); k++){
            super.insert(bfs.get(k));
        }

    }

    private void rotacaoEsquerdaDireita(int i){ 
        rotacaoEsquerda(nodeLeft(i)); 
        rotacaoDireita(i); 
    }

    private void rotacaoDireitaEsquerda(int i){ 
        rotacaoDireita(nodeRight(i));
        rotacaoEsquerda(i); 
    }

    private int isBalance_aux(int i){

        if (abb[i] == null) {
            return -1;
        }
        int esquerda = isBalance_aux(nodeLeft(i));
        int direita = isBalance_aux(nodeRight(i));
        
        if(Math.abs(esquerda-direita) > 1){
            return -2;
        }

        return (Math.max(esquerda, direita)+1);

    }




    
}