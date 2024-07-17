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

    private int len(){ //conta quantos nós tem na árvore inteira
        if (this.abb[0] == null) return 0; //se nao tiver raiz

        return countNodes(0); //count nodes a partir da raiz
    }


    public String toString(){
        StringBuilder tmp = new StringBuilder();

        tmp.append("digraph {\n");

        if (this.len() == 1){ //se só tiver o nó raiz
            tmp.append("\"0 " + this.abb[0] + "\" ");
        } else{
            for (int i = 0; i < this.tamanho; i++){
                if (this.abb[i] == null) continue;
    
                int filho_esq = this.nodeLeft(i);
                int filho_dir = this.nodeRight(i);
    
                if ((filho_esq != -1) && (this.abb[filho_esq] != null)){
                    tmp.append("\"" + i + " " + this.abb[i] + "\" ->\"" + filho_esq + " " + this.abb[filho_esq] + "\"\n");
                }
    
                if ((filho_dir != -1) && (this.abb[filho_dir] != null)){
                    tmp.append("\"" + i + " " + this.abb[i] + "\" ->\"" + filho_dir + " " + this.abb[filho_dir] + "\"\n");
                }
            }
        }
        
        tmp.append("}");

        return tmp.toString();
    }

    //-----------------Funções relacionadas a busca-----------------
    private int busca_aux(String v, int index){ //funcao auxilar para a busca
        if (index == -1) return -1; //se o index não existir

        if (this.abb[index] == null) return -1;

        if (v.equals(this.abb[index])) { //se elas forem iguais
            return index;
        }

        if (v.compareTo(this.abb[index]) < 0){ //if v < abb[index]
            return busca_aux(v, this.nodeLeft(index)); //busca no filho esquerdo
        } else{
            return busca_aux(v, this.nodeRight(index)); //busca no filho direito
        }
    }

    protected int busca(String v){
        //retorna o index de V
        //se nao existe retorna -1

        return busca_aux(v, 0);
    }

    boolean find(String v){
        if (busca(v) == -1) return false;

        return true;
    }

    protected boolean isBalance(){
        return true;
    }

    //-----------------Funções relacionadas a inserção-----------------
    private void insert_aux(int index, String value){
        if (this.abb[index] == null){
            this.abb[index] = value;

            return;
        }

        if (this.abb[index].compareTo(value) > 0){ //this.abb[index] > value
            insert_aux(this.nodeLeft(index), value);
        }else{//this.abb[index] > value
            insert_aux(this.nodeRight(index), value);
        }
    }

    void insert(String value){
        if (value == null) return;

        if (this.find(value)) return; //se ja estiver na abb n fazer nada

        if (this.len() == 0){ //abb vazia
            this.abb[0] = value;

            return;
        }

        insert_aux(0, value); //inserir na árvore

        this.tamanho++;
    }

    //-----------------Funções relacionadas a remoção-----------------
    protected ArrayList<String> SubArvore(int index){ //retorna a SubArvore a partir do index fornecido
        ArrayList<String> SubArvore = new ArrayList<>();

        Queue<Integer> fila = new LinkedList<>();
        fila.offer(index); //adicionar o primeiro nó da SubArvore na fila

        while (!fila.isEmpty()){ //enquanto a fila nao for vazia
            index = fila.poll(); //pegar o próixmo index na fila

            if (index == -1) continue;
            SubArvore.add(this.abb[index]); //adicionar o nó na subabb

            if (this.abb[index] == null) continue;

            //colocar ambos os filhos na fila
            fila.offer(this.nodeLeft(index));
            fila.offer(this.nodeRight(index));
        }

        return SubArvore; //retornar a subarvore

    }

    //remove uma SubArvore da árvore a partir de um index fornecido
    protected void Remove_SubArvore(int index){
        //criar uma fila
        Queue<Integer> fila = new LinkedList<>(); 
        fila.offer(index); //adicionar o index na fila
    
        while (!fila.isEmpty()){ //enquanto a fila nao for vazia
            index = fila.poll(); //pegar o próixmo index na fila

            if (index == -1) continue;
            if (this.abb[index] == null) continue;

            //colocar ambos os filhos na fila
            fila.offer(this.nodeLeft(index));
            fila.offer(this.nodeRight(index));

            this.abb[index] = null; //retirar o nó da árvore
        }
    }

    protected boolean remove(String v){
        if (this.abb[0] == null) return false;

        int index = this.busca(v); //pegar o index do vértice

        ArrayList<String> SubArvore = this.SubArvore(index); //pegar a SubArvore a partir do nó que vai ser removido
        this.Remove_SubArvore(index); //remover toda a SubArvore

        for (int i = 0; i < SubArvore.size(); i++){ //readicionar todo mundo menos o cara que está sendo removido
            if (SubArvore.get(i) == null) continue;

            if (SubArvore.get(i).equals(v)) continue; //nao fazer nada se o cara for quem está sendo removido

            this.insert(SubArvore.get(i)); //adicionar todo o resto da sub-arvore
        }
        return true; 
    }
}