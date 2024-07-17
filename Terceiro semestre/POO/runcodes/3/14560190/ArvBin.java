import java.util.Queue;
import java.util.LinkedList;
import java.util.ArrayList;


public class ArvBin {
    protected String[] abb;
    protected int tamanho;

    protected ArvBin(int len) {
        this.abb = new String[len];
        this.tamanho = 0;
    }

    // Implementa uma árvore de busca não balanceada utilizando um heap. 
    // Ou seja, os elementos são alocados em um array. A raiz da árvore 
    // está sempre na posição 0 do array. Os filhos do nó i estão nas 
    // posições 2 * i + 1 e 2 * i + 2.




    protected boolean remove(String value){ // Remove um elemento da árvore.

        if(this.abb[0] == null) return false;

        boolean flag = true;
        
        ArrayList<String> arvore_nova = new ArrayList<>();

        int index = busca(value);

        if(index == -1){
            return false;
        }
        
        arvore_nova = bfs(index, true);

        for(int i =0; i< arvore_nova.size(); i++){
            if(arvore_nova.get(i) == null){
                continue;
            }
            if(!arvore_nova.get(i).equals(value)){
                insert(arvore_nova.get(i));
            }
        }

        return flag;
        
    }

    private void insert_aux(String v, int index){

        if(abb[index] == null){
            this.abb[index] = v;
            this.tamanho++;
        }

        if(abb[index].compareTo(v) < 0){
            insert_aux(v, nodeRight(index));
        }else{
            if(abb[index].compareTo(v) > 0){
                insert_aux(v, nodeLeft(index));
            }
        }



    }


    protected void insert(String value) {   // Insere um string na árvore
        if (this.tamanho == this.abb.length) {
            throw new ArrayIndexOutOfBoundsException("A árvore está cheia");
        }
        if (this.tamanho == 0) {
            this.abb[0] = value;
            this.tamanho++;
            return;
        }

        if(find(value)){
            return;
        }

        insert_aux(value, 0);


        
    }

    protected boolean find(String v) {
        if (v == null) return false;
    
        int i = 0;
        while (i < this.tamanho && this.abb[i] != null) {
            if (v.equals(this.abb[i])) {
                return true;
            }
            if (v.compareTo(this.abb[i]) < 0) {
                i = nodeLeft(i);
            } else {
                i = nodeRight(i);
            }
            // Adicionar verificação para garantir que i está dentro dos limites
            if (i >= this.abb.length) {
                return false;
            }
        }
        return false;
    }

    private int busca(String v){  // ESSA BUSCA ESTÁ ERRADA
        if (v == null) return -1;
    
        int i = 0;
        while (i < this.tamanho && this.abb[i] != null) {
            if (v.equals(this.abb[i])) {
                return i;
            }
            if (v.compareTo(this.abb[i]) < 0) {
                i = nodeLeft(i);
            } else {
                i = nodeRight(i);
            }
            // Adicionar verificação para garantir que i está dentro dos limites
            if (i >= this.abb.length) {
                return -1;
            }
        }
        return -1;
    }



    protected int len() {  // Retorna o número de elementos presentes na árvore

        return this.tamanho;
    }

    protected int nodeLeft(int i) {
        return 2 * i + 1;
    }

    protected int nodeRight(int i) {
        return 2 * i + 2;
    }

    protected String getNode(int i){
        return abb[i];
    }

    protected void setNode(int i, String v){
        abb[i] = v;
    }


    protected int countNodes(int i){ // Conta o número de nós em um subárvore.
        if(abb[i] == null){
            return 0;
        }

        int a = countNodes(nodeLeft(i));
        int b = countNodes(nodeRight(i));

        return a+b+1;
        
    }



    private String paraString() {
        StringBuilder sb = new StringBuilder("digraph {\n");

        if(this.tamanho == 1){
            sb.append("\"0 " + this.abb[0] + "\" ");
            
        }else{
        for(int i = 0; i < this.abb.length; i++){
            if(this.abb[i] != null){
                
                // System.out.println(i);
                // System.out.println(this.abb[i]);

                int leftIndex = nodeLeft(i);
                int rightIndex = nodeRight(i);

                if(leftIndex < this.abb.length && this.abb[leftIndex] != null){
                    sb.append("\"").append(i + " ").append(abb[i]).append("\" ->\"").append(leftIndex + " ").append(abb[leftIndex]).append("\"\n");
                }
    
                if(rightIndex < this.abb.length && this.abb[rightIndex] != null){
                    sb.append("\"").append(i + " ").append(abb[i]).append("\" ->\"").append(rightIndex + " ").append(abb[rightIndex]).append("\"\n");
                }
            }
        }
        }
        sb.append("}");
        return sb.toString();
    }

    @Override
    public String toString() {
        return this.paraString();
    }




    protected boolean isBalance() { // Verifica se a árvore está balanceada, de acordo com o critério de cada tipo de árvore. No caso de uma árvore desbalanceada, retorna sempre true pois não existe regra de balanceamento.
        return true;
    }

    
    // protected ArrayList<String> bfs(int index, boolean flag_remover_nos){ // Função auxiliar que retornar um vetor de string em ordem a partir do index dado e remove todos os filhos do index dado e o pai

    //     Queue<Integer> fila_de_index = new LinkedList<>();

    //     ArrayList<String> retorno = new ArrayList<>();

    //     fila_de_index.offer(index);

    //     while (!fila_de_index.isEmpty()) {

    //         if(nodeLeft(index) < abb.length && abb[nodeLeft(index)] != null){
    //             fila_de_index.offer(nodeLeft(index));
    //         }

    //         if(nodeRight(index) < abb.length && abb[nodeRight(index)] != null){
    //             fila_de_index.offer(nodeRight(index));
    //         }

    //         retorno.add(abb[fila_de_index.peek()]);

    //         if(flag_remover_nos){
    //             abb[fila_de_index.poll()] = null;
    //         }

    //     }
                
    //     return retorno;

        
    // }

    protected ArrayList<String> bfs(int index, boolean flag_remover_nos) {
        Queue<Integer> fila_de_index = new LinkedList<>();
        ArrayList<String> retorno = new ArrayList<>();
    
        fila_de_index.offer(index);
    
        while (!fila_de_index.isEmpty()) {
            int currentIndex = fila_de_index.poll(); // Sempre remova o elemento no início do loop
    
            if (nodeLeft(currentIndex) < abb.length && abb[nodeLeft(currentIndex)] != null) {
                fila_de_index.offer(nodeLeft(currentIndex));
            }
    
            if (nodeRight(currentIndex) < abb.length && abb[nodeRight(currentIndex)] != null) {
                fila_de_index.offer(nodeRight(currentIndex));
            }
    
            retorno.add(abb[currentIndex]); // Use o currentIndex que você acabou de remover da fila
    
            if (flag_remover_nos) {
                abb[currentIndex] = null; // Remova o nodo após adicionar ao retorno
            }
        }
    
        return retorno;
    }
    


}








