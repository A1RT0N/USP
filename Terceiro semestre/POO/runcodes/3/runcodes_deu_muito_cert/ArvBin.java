import java.util.LinkedList;
import java.util.Queue;
import java.util.ArrayList;

public class ArvBin{
    protected String[] abb;
    protected int tamanho;

    protected ArvBin(int len){
        this.abb = new String[len]; 

        this.tamanho = tamanho;
    }

    protected int nodeRight(int i){ 
        return 2*i+2;
    }

    protected int nodeLeft(int i){ 
        return 2*i+1;
    }

    protected void setNode(int i, String v){ 
        this.abb[i] = v;
    }

    protected String getNode(int i){ 
        return this.abb[i]; 
    }

    protected int countNodes(int i){ 
        if(abb[i] == null){
            return 0;
        }

        int a = countNodes(nodeLeft(i));
        int b = countNodes(nodeRight(i));

        return a+b+1;
        
    }


    public String toString(){
        StringBuilder sb = new StringBuilder("digraph {\n");

        if(this.tamanho == 1){
            if(this.abb[0] == null){

            }else{
                sb.append("\"0 " + this.abb[0] + "\" ");
            }

        }else{
        for(int i = 0; i < this.abb.length; i++){
            if(this.abb[i] != null){

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

    protected int busca_aux(int i, String v){  
        if (i == -1) return -1; 

        if (abb[i] == null) return -1;

        if (v.equals(abb[i])) { 
            return i;
        }

        if (v.compareTo(abb[i]) < 0){ 
            return busca_aux(nodeLeft(i), v); 
        } else{
            return busca_aux(nodeRight(i), v);
        }
    }


    protected boolean find(String v){
        if (busca_aux(0, v) == -1) return false;
        return true;
    }

    protected boolean isBalance(){
        return true;
    }

    private void insert_aux(int index, String v){
        if(abb[index] == null){
            this.abb[index] = v;
        }

        if(abb[index].compareTo(v) < 0){
            insert_aux(nodeRight(index), v);
        }else{
            if(abb[index].compareTo(v) > 0){
                insert_aux(nodeLeft(index), v);
            }
        }
    }

    protected void insert(String value){

        if(value == null){
            return;
        }

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

        insert_aux(0, value);

        this.tamanho++;
    }

    protected ArrayList<String> bfs(int index, boolean flag_remover_nos) {
        Queue<Integer> fila_de_index = new LinkedList<>();
        ArrayList<String> retorno = new ArrayList<>();
    
        fila_de_index.offer(index);
    
        while (!fila_de_index.isEmpty()) {
            int currentIndex = fila_de_index.poll(); 
    
            if(currentIndex<0){
                continue;
            }

            if (abb[(currentIndex)] != null) {
                fila_de_index.offer(nodeLeft(currentIndex));
            }
    
            if (abb[(currentIndex)] != null) {
                fila_de_index.offer(nodeRight(currentIndex));
            }
    
            retorno.add(abb[currentIndex]); 
    
            if (flag_remover_nos) {
                abb[currentIndex] = null; 
            }
        }
    
        return retorno;
    }


    protected boolean remove(String v){
        if (this.abb[0] == null) return false;

        int index = this.busca_aux(0, v); 

        ArrayList<String> bfs = bfs(index, true); 

        for (int i = 0; i < bfs.size(); i++){ 
            if (bfs.get(i) == null) continue;

            if (bfs.get(i).equals(v)) continue; 

            this.insert(bfs.get(i)); 
        }
        return true; 
    }
}