import java.util.ArrayList;

public class ArvAVL<T extends Comparable<T>> extends ArvBin<T>{
    public ArvAVL(int len){
        super(len);
    }


    // Função que remove elemento da AVL, chamando funções auxiliares que trocam elementos conforme a quantidade de filhos do nó removido
    @Override 
    protected boolean remove(T v){

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

        // Caso não tenha nó filho
        else super.remove(v);

        // Verificar se cada nó está balanceado e balanceia se não estiver
        for (int i = this.tamanho - 1; i >= 0; i--){
            if (this.abb[i] == null) continue;

            if (isBalance_aux(i) <= -2){ 
                balancearAVL(i); 
            }
        }


        return true;


    }

    @Override

    // Função que insere elemento na árvore, igual árvove binária, e rebalanceia a partir do index desvalanceado i
    protected void insert(T value){
        super.insert(value); 

        for (int i = this.tamanho - 1; i >= 0; i--){
            if (this.abb[i] == null) continue;

            if (isBalance_aux(i) <= -2){ 
                balancearAVL(i); 
            }
        }
    }

    // Função privada que, na remoção, quando o filho tem dois nós, troca com o maior nó direito do filho esquerdo do nó em index
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

        T maior = abb[index_maior_filho];

        super.remove(maior);

        abb[index] = maior;




    }

    // Função auxiliar que, se não houver filho de index na esquerda, pega o menor nó esquerdo do filho direito de index
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

        T menor = abb[index_menor_filho];

        super.remove(menor);

        abb[index] = menor;
    }




    // Função recursiva que calcula a altura do nó de um index
    private int alturaNo(int index) {
        // Caso base
        if ((index < 0) || (this.abb[index] == null)) return -1;

        int AlturaFilhoEsq = alturaNo(this.nodeLeft(index)); 
        int AlturaFilhoDir = alturaNo(this.nodeRight(index)); 

        // Retorna o mairo altura + 1 (nó index)
        return Math.max(AlturaFilhoEsq, AlturaFilhoDir) + 1;
    }

    // Função auxiliar que balanceia a AVL que está desbalanceada no index i
    private void balancearAVL(int i){ 

        // Caso fator de desbalanceamento seja -2
        if (alturaNo(this.nodeLeft(i)) - alturaNo(this.nodeRight(i)) == -2){ 
            if ((alturaNo(this.nodeLeft(this.nodeRight(i))) - alturaNo(this.nodeRight(this.nodeRight(i)))) <= 0){ 
                rotacaoEsquerda(i); 
            }else{
                rotacaoDireitaEsquerda(i); 
            }
        }

        // Caso fator de desbalanceamento seja 2
        if (alturaNo(this.nodeLeft(i)) - alturaNo(this.nodeRight(i)) == 2){
            if ((alturaNo((this.nodeLeft(this.nodeLeft(i)))) - alturaNo((this.nodeRight(this.nodeLeft(i))))) > 0 ) { 
                rotacaoDireita(i);
            }else{
                rotacaoEsquerdaDireita(i); 
            }
        }
    }


    // Função auxiliar que rotaciona o index i para a esquerda 
    private void rotacaoDireita(int i){

        T pai = abb[i];

        T filho_esquerdo = abb[nodeLeft(i)];

        // Remove todos os nós a partir do index i e guarda em ordem numa array
        ArrayList<T> bfs = bfs(i, true); 

        // Depois insere pai à direita do filho esquerdo
        super.insert(filho_esquerdo); 

        // Depois insere pai à direita do filho esquerda
        super.insert(pai); 
        
        // Insere o resto dos nós
        for (int k = 2; k < bfs.size(); k++){
            super.insert(bfs.get(k));
        }

    }


    // Função auxiliar que rotaciona o index i para a esquerda  
    private void rotacaoEsquerda(int i){ 
        T pai = abb[i];

        T filho_direito = abb[nodeRight(i)];
        
        ArrayList<T> bfs = bfs(i, true); 
        // Remove todos os nós a partir do index i e guarda em ordem numa array
    
        // Insere primeiro filho direito
        super.insert(filho_direito); 

        // Depois insere pai à esquerda do filho direito
        super.insert(pai); 
        
        // Insere o resto dos nós
        for (int k = 1; k < bfs.size(); k++){
            super.insert(bfs.get(k));
        }

    }


    // Função de rotação dupla
    private void rotacaoDireitaEsquerda(int i){ 
        rotacaoDireita(nodeRight(i));
        rotacaoEsquerda(i); 
    }

    // Função de rotaçao dupla
    private void rotacaoEsquerdaDireita(int i){ 
        rotacaoEsquerda(nodeLeft(i)); 
        rotacaoDireita(i); 
    }

    

    // Função que checa se árvore avl está balanceda
    @Override  
    protected boolean isBalance() { // Verifica se a árvore está balanceada, de acordo com o critério de cada tipo de árvore. No caso de uma árvore desbalanceada, retorna sempre true pois não existe regra de balanceamento.

        if(isBalance_aux(0) <= -2){
            return false;
        }

        return true;
    }    

    // Função auxiliar recursiva que checa se árvore está balanceada levando em consideração a altura dos nós da esquerda e direita difere em 1
    private int isBalance_aux(int i){
        
        // Caso base  
        if (abb[i] == null) {
            return -1;

        }


        int esquerda = isBalance_aux(nodeLeft(i));
        int direita = isBalance_aux(nodeRight(i));
        
        // Condição de propagação caso uma subárvore não obdeça a condição de balanceamento
        if(Math.abs(esquerda-direita) > 1){
            return -2;
        }

        return (Math.max(esquerda, direita)+1);

    }


}