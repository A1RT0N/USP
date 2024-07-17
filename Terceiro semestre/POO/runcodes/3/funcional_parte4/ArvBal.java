import java.util.ArrayList;
import java.util.Collections;



public class ArvBal extends ArvBin{
    protected ArvBal(int len){
        super(len);
    }


    // 1. Ordenar num array os registros em ordem
    // crescente das chaves;
    // 2. O registro do meio é inserido na ABB vazia
    // (como raiz);
    // 3. Tome a metade esquerda do array e repita o
    // passo 2 para a sub-árvore esquerda;
    // 4. Idem para a metade direita e sub-árvore
    // direita;
    // 5. Repita o processo até não poder dividir mais.


    private void remotar_arvore_aux(int inicio, int fim, ArrayList<String> Subarvore){
        if(inicio > fim){  
            return;
        }
    
        int meio = (inicio + fim) / 2;

        super.insert(Subarvore.get(meio));

        remotar_arvore_aux(inicio, meio-1, Subarvore);  
        remotar_arvore_aux(meio+1, fim, Subarvore);  
    }
    
    private void remotar_arvore(){
        ArrayList<String> SubArvore = new ArrayList<>();
        for(int i = 0; i<abb.length; i++){
            if(abb[i] != null){
                SubArvore.add(abb[i]);
            }
        }

    
        Collections.sort(SubArvore);
        

        for (int i = 0; i < this.abb.length; i++) {
            abb[i] = null;
        }
        

        remotar_arvore_aux(0, SubArvore.size()-1, SubArvore);  
    }


    @Override

    protected void insert(String value){

        super.insert(value);

        if(isBalance()){
            return;
        }
        
        remotar_arvore();
    }

    @Override

    protected boolean remove(String value){
        boolean flag;
        flag = super.remove(value);

        if(!flag){
            return false;
        }

        if(!isBalance()){
            remotar_arvore();
        }
        return true;
    }


    @Override
    protected boolean isBalance() {
        if (isBalance_aux(0)) return true;
        return false;
    }

    protected boolean isBalance_aux(int i) {
        if (abb[i] == null) return true;
        if (Math.abs(countNodes(nodeLeft(i)) - countNodes(nodeRight(i))) < 2) {
            return isBalance_aux(nodeLeft(i)) && isBalance_aux(nodeRight(i));
        }
        return false;
    }


    
}








    // protected ArrayList<String> SubArvore(int index){ //retorna a SubArvore a partir do index fornecido
    //     ArrayList<String> SubArvore = new ArrayList<>();

    //     Queue<Integer> fila = new LinkedList<>();
    //     fila.offer(index); //adicionar o primeiro nó da SubArvore na fila

    //     while (!fila.isEmpty()){ //enquanto a fila nao for vazia
    //         index = fila.poll(); //pegar o próixmo index na fila

    //         if (index == -1) continue;
    //         SubArvore.add(this.arvore[index]); //adicionar o nó na subarvore

    //         if (this.arvore[index] == null) continue;

    //         //colocar ambos os filhos na fila
    //         fila.offer(this.NodeLeft(index));
    //         fila.offer(this.NodeRight(index));
    //     }

    //     return SubArvore; //retornar a subarvore

    // }

    // //remove uma SubArvore da árvore a partir de um index fornecido
    // protected void Remove_SubArvore(int index){
    //     //criar uma fila
    //     Queue<Integer> fila = new LinkedList<>(); 
    //     fila.offer(index); //adicionar o index na fila
    
    //     while (!fila.isEmpty()){ //enquanto a fila nao for vazia
    //         index = fila.poll(); //pegar o próixmo index na fila

    //         if (index == -1) continue;
    //         if (this.arvore[index] == null) continue;

    //         //colocar ambos os filhos na fila
    //         fila.offer(this.NodeLeft(index));
    //         fila.offer(this.NodeRight(index));

    //         this.arvore[index] = null; //retirar o nó da árvore
    //     }
    // }