import java.util.ArrayList;
import java.util.Collections;



public class ArvBal<T extends Comparable<T>> extends ArvBin<T>{
    protected ArvBal(int len){
        super(len);
    }


    // Algortmo basico para montar uma árvore perfeitamente balanceada

    // 1. Ordenar num array os registros em ordem
    // crescente das chaves;
    // 2. O registro do meio é inserido na ABB vazia
    // (como raiz);
    // 3. Tome a metade esquerda do array e repita o
    // passo 2 para a sub-árvore esquerda;
    // 4. Idem para a metade direita e sub-árvore
    // direita;
    // 5. Repita o processo até não poder dividir mais.


    // Função que checa se é árvore perfeitamente balanceada
    @Override
    protected boolean isBalance() {
        if (isBalance_aux(0)) return true;
        return false;
    }

    // Função auxiliar recursiva que checa se a quantidade de nós do lado esquerdo difere apenas em 1 nó do lado direito, isso pra cada subárvore com raiz em i
    protected boolean isBalance_aux(int i) {
        if (abb[i] == null) return true;
        if (Math.abs(countNodes(nodeLeft(i)) - countNodes(nodeRight(i))) < 2) {
            return isBalance_aux(nodeLeft(i)) && isBalance_aux(nodeRight(i));
        }
        return false;
    }


    // Função auxiliar que realiza o passo 2
    private void remotar_arvore_aux(int inicio, int fim, ArrayList<T> tree){
        if(inicio > fim){  
            return;
        }
    
        int meio = (inicio + fim) / 2;

        super.insert(tree.get(meio));

        remotar_arvore_aux(inicio, meio-1, tree);  
        remotar_arvore_aux(meio+1, fim, tree);  
    }
    
    // Função que realiza o passo 1, 2, 3,4,5 
    private void remotar_arvore(){
        ArrayList<T> tree = new ArrayList<>();
        for(int i = 0; i<abb.length; i++){
            if(abb[i] != null){
                tree.add(abb[i]);
            }
        }

        // Função que ordena a árvore
        Collections.sort(tree);
        

        // Seta todos os nós da árvore como nulos
        for (int i = 0; i < this.abb.length; i++) {
            abb[i] = null;
        }
        

        remotar_arvore_aux(0, tree.size()-1, tree);  
    }


    @Override

    // Função que insere elemento da mesma forma que uma árvore binária e, se ela não estiver balanceada, remonta a árvore inteira
    protected void insert(T value){

        super.insert(value);

        if(isBalance()){
            return;
        }
        
        remotar_arvore();
    }


    // Função auxiliar privada da ABB que semelhante ao da árvore binária, mas sem trocar os filhos

    protected boolean remove_aux(T v){
        // Caso a árvore esteja vazia
        if (this.abb[0] == null) return false;

        int index = super.busca_aux(0, v); 

        // Algoritmo de bfs para remover elementos filhos de index a partir do index achado (incluindo o próprio pai)
        ArrayList<T> bfs = super.bfs(index, true); 

        // Pega os elementos da bfs e insere se necessário
        for (int i = 0; i < bfs.size(); i++){ 
            if (bfs.get(i) == null){
                continue;
            }

            // Pula o elemento a ser removido (ele não deve ser reenserido na árvore)
            if (bfs.get(i).equals(v)){
                continue;

            }

            this.insert(bfs.get(i)); 
        }
        return true; 
    }
    @Override
    // Função que remove elemento da mesma forma que uma árvore binária e, se ela não estiver balanceada, remonta a árvore inteira
    protected boolean remove(T value){
        boolean flag;
        flag = remove_aux(value);

        if(!flag){
            return false;
        }

        if(!isBalance()){
            remotar_arvore();
        }
        return true;
    }



    
}

