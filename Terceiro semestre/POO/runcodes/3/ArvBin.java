import java.util.LinkedList;
import java.util.Queue;
import java.util.ArrayList;

public class ArvBin{
    protected String[] abb;
    protected int tamanho;

    // Construtor da Árvore binária
    protected ArvBin(int len){
        this.abb = new String[len]; 
        this.tamanho = tamanho;
    }


    // Seta o index i como String v passada como parâmetro  
    protected void setNode(int i, String v){ 
        this.abb[i] = v;
    }


    // Recupera a String que está no index i
    protected String getNode(int i){ 
        return this.abb[i]; 
    }


    // Retorna o nó direito do index i
    protected int nodeRight(int i){ 
        return 2*i+2;
    }

    // Retorna o nó esquerdo do index 
    protected int nodeLeft(int i){ 
        return 2*i+1;
    }


    // Função recursiva que conta a quantidade de nós na árvore com raiz em i
    protected int countNodes(int i){ 

        // Caso base  
        if(abb[i] == null){
            return 0;
        }

        // Recursão para direita e esquerda, armazenando em interios
        int a = countNodes(nodeLeft(i));
        int b = countNodes(nodeRight(i));

        // Retorna a quantidade de nós da subávore esquerda, mais direita, mais o nó pai
        return a+b+1;
        
    }

    // Função que vê se a árvore é balanceada. No caso dessa árvore, sempre retorna true, de acordo com as especificações do código.
    protected boolean isBalance(){
        return true;
    }


    // Busca iterativa que retorna o index do elemento buscado. Se não for achado, retorna -1
    protected int busca_aux(int i, String v){  

        // Caso for passado um index que não existe
        if (i < 0) return -1; 

        int index_retorno = i;

        while(!v.equals(abb[index_retorno])){   // Enquanto o conteúdo do index_retorno de análise não for igual ao valor de String passado como parâmetro

            if(abb[index_retorno] == null){     // Caso não ache o elemento
                return -1;
            }  

            // index vai para direita ou esquerda do nó, seguindo o padrão de uma árvore binária de busca
            if(v.compareTo(abb[index_retorno]) < 0){
                index_retorno = nodeLeft(index_retorno);
            }else{
                index_retorno = nodeRight(index_retorno);
            }

        }

        return index_retorno;

    }


    // Função que retorna se uma String existe ou não numa árvore
    protected boolean find(String v){
        if (busca_aux(0, v) == -1) return false;
        return true;
    }



    
    // Função auxiliar iterativa que insere elemento de String v, a partir do index 'index'
    private void insert_aux(int index, String v){

        int index_retorno = index;

        while(abb[index_retorno] != null){  // Enquanto existir nó

            // Anda para direita ou esquerda de acordo com o valor de String dada
            if(abb[index_retorno].compareTo(v) < 0){
                index_retorno = nodeRight(index_retorno);
            }else{

                index_retorno = nodeLeft(index_retorno);
                
            }
        }

        // Insere elemento no index correto

        abb[index_retorno] = v;


    }

    // Função principal que insere elemento String passada como parâmetro
    protected void insert(T t){

        if(t == null){
            return;
        }

        // Execption caso a árvore esteja cheia
        if (this.tamanho == this.abb.length) {
            throw new ArrayIndexOutOfBoundsException("A árvore está cheia");
        }
        
        // Caso simples onde a árvore é vazia  
        if (this.tamanho == 0) {
            this.abb[0] = t;
            this.tamanho++;
            return;
        }

        // Se já existir o elemento na árvore, ele não insere.
        if(find(t)){
            return;
        }


        // Chama função auxiliar de inserção a partir da raiz 
        insert_aux(0, t);

        this.tamanho++;
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

        String maior = abb[index_maior_filho];

        remove(maior);

        abb[index] = maior;


        



    }

    // Função privada que, na remoção, se não houver filho de index na esquerda, pega o menor nó esquerdo do filho direito de index
    private void troca_min_direita(int index){
        int index_menor_filho;

        int temp = nodeRight(index);

        while(abb[nodeLeft(temp)] != null){
            if(temp > abb.length){
                break;
            }
            temp = nodeLeft(temp);
        }


        // Swap no elemento achado e remove ele

        index_menor_filho = temp;

        String maior = abb[index_menor_filho];

        remove(maior);

        abb[index] = maior;

        
    }

    // Função que remove elemento de string v
    protected boolean remove(String v){
        // Caso a árvore esteja vazia
        if (this.abb[0] == null) return false;

        int index_busca = busca_aux(0, v); 

        // Caso o index não seja achado

        if(index_busca == -1){
            return false;
        }

        // Fazer a troca dos elementos

        if(abb[nodeLeft(index_busca)] != null){
            troca_max_esquerda(index_busca);
        }

        else if(abb[nodeRight(index_busca)] != null){
            troca_min_direita(index_busca);
        }

        // Algoritmo de bfs para remover elementos filhos de index a partir do index achado (incluindo o próprio pai)
        ArrayList<String> bfs = bfs(index_busca, true); 


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

   // Bfs iterativo que usa fila de index para percorrer uma árvore cuja raiz está em index, adicionando em um array de string. É passado como parâmetro um booleano para saber se quer remover os nós percorridos pela bfs ou não 
    protected ArrayList<String> bfs(int index, boolean flag_remover_nos) {
        Queue<Integer> fila_de_index = new LinkedList<>();
        ArrayList<String> retorno = new ArrayList<>();
    
        fila_de_index.offer(index);
    
        while (!fila_de_index.isEmpty()) {
            int currentIndex = fila_de_index.poll(); // Remove início da fila
            
            // Caso em que o index não exista
            if(currentIndex<0){
                continue;
            }


            // Adiciona elementos na fila
            if (abb[(currentIndex)] != null) {
                fila_de_index.offer(nodeLeft(currentIndex));
            }
    
            if (abb[(currentIndex)] != null) {
                fila_de_index.offer(nodeRight(currentIndex));
            }
            
            // Adiciona o elemento removido no array de retorno.
            retorno.add(abb[currentIndex]); 
            
            // Caso em que deseja-se remover os nós depois de percorridos
            if (flag_remover_nos) {
                abb[currentIndex] = null; 
            }
        }
    
        return retorno;
    }




    // Função toString() do graphiz
    public String toString(){
        // Instancia um construtor de string
        StringBuilder sb = new StringBuilder("digraph {\n");

        // Exceção, caso o tamanho da árvore seja 1
        if(this.tamanho == 1){
            if(this.abb[0] == null){
                // Não imprime nada se a árvore for vazia
            }else{
                // Imprime o único elemento da árvore
                sb.append("\"0 " + this.abb[0] + "\" ");
            }

        }else{

        // Laço que percorre o vetor adicionando os elementos à esquerda e à direita, nessa ordem, de i
        for(int i = 0; i < this.abb.length; i++){
            if(this.abb[i] != null){

                int leftIndex = nodeLeft(i);
                int rightIndex = nodeRight(i);


                // Coloca filho esquerdo do nó de index i
                if(leftIndex < this.abb.length && this.abb[leftIndex] != null){
                    sb.append("\"").append(i + " ").append(abb[i]).append("\" ->\"").append(leftIndex + " ").append(abb[leftIndex]).append("\"\n");
                }
    
                // Coloca filho direito do nó do index i
                if(rightIndex < this.abb.length && this.abb[rightIndex] != null){
                    sb.append("\"").append(i + " ").append(abb[i]).append("\" ->\"").append(rightIndex + " ").append(abb[rightIndex]).append("\"\n");
                }
            }
        }
        }
        sb.append("}");

        // Retorna a função em String, convertendo de StringBuilder para String
        return sb.toString();
    }


}