import java.util.ArrayList;

public class ArvAVL extends ArvBin{

    // Implementa uma árvore de busca perfeitamente balanceada utilizando um heap, alocado na superclasse. 
    // A regra de balanceamento diz que toda subarvore tem, no máximo, 1 como a diferença entre o número de 
    // nós da subárvore esquerda e da subárvore direita.
    
    protected ArvAVL(int len){
        super(len);
    }

    // FUNÇÕES AUXILIARES:

    private int alturaNo(int i) {
        if (i >= tamanho || abb[i] == null) return -1;
        return 1 + Math.max(alturaNo(nodeLeft(i)), alturaNo(nodeRight(i)));
    }


    private void insert_aux_avl(String v, int index){

        if(abb[index] == null){
            this.abb[index] = v;
            this.tamanho++;
        }

        if(abb[index].compareTo(v) < 0){
            insert_aux_avl(v, nodeRight(index));
        }else{
            if(abb[index].compareTo(v) > 0){
                insert_aux_avl(v, nodeLeft(index));
            }
        }



    }



    private void balancearAVL(int index){ 
        if (index < 0 || index >= tamanho || this.abb[index] == null) return;

        ArrayList <String> temp = new ArrayList<>();


        if((alturaNo(nodeLeft(index)) - alturaNo(nodeRight(index))) == -2){
            if((alturaNo(nodeRight(nodeLeft(index)))- alturaNo(nodeRight(nodeRight(index)))) <= 0){
                // Rodar esquerda

                String filho_direito = abb[nodeRight(index)];
                String pai = abb[index];

                temp = bfs(index, true);
                
                abb[index] = filho_direito;
                abb[nodeLeft(index)] = pai;

                for(int i = 0; i< temp.size(); i++){
                    if(temp.get(i) != filho_direito || temp.get(i) != pai){
                        insert_aux_avl(temp.get(i), index);
                    }
                }
                

            }else{

                // Rodar direita esquerda

                // Algoritmo pra rodar direita
                String filho_esquerdo = abb[nodeLeft(nodeRight(index))];
                String pai = abb[nodeRight(index)];

                temp = bfs(nodeRight(index), true);


                abb[nodeRight(index)] = filho_esquerdo;
                abb[nodeRight(nodeRight(index))] = pai;

                for(int i = 0; i< temp.size(); i++){
                    if(temp.get(i) != filho_esquerdo || temp.get(i) != pai){
                        insert_aux_avl(temp.get(i), nodeRight(index));
                    }
                }

                // Algoritmo pra rodar esquerda

                String filho_direito = abb[nodeRight(index)];
                String pai2 = abb[index];

                temp = bfs(index, true);
                
                abb[index] = filho_direito;
                abb[nodeLeft(index)] = pai2;

                for(int i = 0; i< temp.size(); i++){
                    if(temp.get(i) != filho_direito || temp.get(i) != pai2){
                        insert_aux_avl(temp.get(i), index);
                    }
                }

                
            }
        }
        if((alturaNo(nodeLeft(index)) - alturaNo(nodeRight(index))) == 2){
            if((alturaNo(nodeLeft(nodeLeft(index)))- alturaNo(nodeLeft(nodeRight(index)))) > 0){
                // Rodar direita

                String filho_esquerdo = abb[nodeLeft(index)];
                String pai = abb[index];

                temp = bfs(index, true);

                abb[index] = filho_esquerdo;
                abb[nodeRight(index)] = pai;

                for(int i = 0; i< temp.size(); i++){
                    if(temp.get(i) != filho_esquerdo || temp.get(i) != pai){
                        insert_aux_avl(temp.get(i), index);
                    }
                }


            }else{
                
                // Rodar esquerda direita

                // Algoritmo pra rodar esquerda
                
                String filho_direito = abb[nodeRight(nodeLeft(index))];
                String pai = abb[nodeLeft(index)];

                temp = bfs(nodeLeft(index), true);
                
                abb[nodeLeft(index)] = filho_direito;
                abb[nodeLeft(nodeLeft(index))] = pai;

                for(int i = 0; i< temp.size(); i++){
                    if(temp.get(i) != filho_direito || temp.get(i) != pai){
                        insert_aux_avl(temp.get(i), nodeLeft(index));
                    }
                }


                // Algoritmo pra rodar direita
                
                String filho_esquerdo = abb[nodeLeft(index)];
                String pai2 = abb[index];

                temp = bfs(index, true);

                abb[index] = filho_esquerdo;
                abb[nodeRight(index)] = pai2;

                for(int i = 0; i< temp.size(); i++){
                    if(temp.get(i) != filho_esquerdo || temp.get(i) != pai2){
                        insert_aux_avl(temp.get(i), index);
                    }
                }

            }
        }

    }

    

    @Override
    protected void insert(String value) {   // Insere um string na árvore
        super.insert(value);

        balancearAVL(0);
    }






    @Override

    protected boolean remove(String v){ // Remove um elemento da árvore.

        boolean flag;
        flag = super.remove(v);
        if(!flag){
            return false;
        }
        balancearAVL(0);

        return true;

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


    @Override
    protected boolean isBalance() { // Verifica se a árvore está balanceada, de acordo com o critério de cada tipo de árvore. No caso de uma árvore desbalanceada, retorna sempre true pois não existe regra de balanceamento.

        if(isBalance_aux(0) <= -2){
            return false;
        }

        return true;
    }



}














 // private int rodarDireita(int i) {
    //     if (i >= tamanho || abb[i] == null) return -1;
    //     int esquerda = nodeLeft(i); 
    //     if (esquerda >= tamanho || abb[esquerda] == null) return -1; 
        
    //     int direitaEsquerda = nodeRight(esquerda); 
        
    //     // Troca os elementos
    //     String temp = abb[i];
    //     abb[i] = abb[esquerda];
    //     abb[esquerda] = temp;
        
    //     // Atualiza o filho direito do novo nó pai
    //     abb[nodeRight(i)] = abb[direitaEsquerda];
    //     abb[direitaEsquerda] = null; 

    //     return esquerda;
    // }

    // private int rodarEsquerda(int i) {
    //     if (i >= tamanho || abb[i] == null) return -1;
    //     int direita = nodeRight(i); 
    //     if (direita >= tamanho || abb[direita] == null) return -1; 

    //     int esquerdaDireita = nodeLeft(nodeRight(i)); 
        
    //     // Troca os elementos
    //     String temp = abb[i];
    //     abb[i] = abb[direita];
    //     abb[direita] = temp;
        
    //     // Atualiza o filho esquerdo do novo nó pai
    //     abb[nodeLeft(i)] = abb[esquerdaDireita];
    //     abb[esquerdaDireita] = null; 

    //     return direita;
    // }

    // private int rodarEsquerdaDireita(int i){
    //     if (i >= tamanho || abb[i] == null) return-1;
    //     int esquerda = nodeLeft(i);
    //     if (esquerda >= tamanho || abb[esquerda] == null) return-1;

    //     rodarEsquerda(esquerda);
    //     return rodarDireita(i);
    // }

    // private int rodarDireitaEsquerda(int i){
    //     if (i >= tamanho || abb[i] == null) return -1;
    //     int direita = nodeRight(i);
    //     if (direita >= tamanho || abb[direita] == null) return -1;

    //     rodarDireita(direita);
    //     return rodarEsquerda(i);
    // }

    // private int balancearAVL(int index){ // Balanceia avl a partir do index
    //     if (index < 0 || index >= tamanho || this.abb[index] == null) return -1;
    //     int index_retorno = index;
    //     if((alturaNo(nodeLeft(index)) - alturaNo(nodeRight(index))) == -2){
    //         if((alturaNo(nodeRight(nodeLeft(index)))- alturaNo(nodeRight(nodeRight(index)))) <= 0){
    //             index_retorno = rodarEsquerda(index);
    //         }else{
    //             index_retorno = rodarDireitaEsquerda(index);
    //         }
    //     }
    //     if((alturaNo(nodeLeft(index)) - alturaNo(nodeRight(index))) == 2){
    //         if((alturaNo(nodeLeft(nodeLeft(index)))- alturaNo(nodeLeft(nodeRight(index)))) > 0){
    //             index_retorno = rodarDireita(index);
    //         }else{
    //             index_retorno = rodarEsquerdaDireita(index);
    //         }
    //     }

    //     return index_retorno;
    // }


    // private int inserirRecursivamente(int index, String v){
    //     if (index >= this.tamanho || this.abb[index] == null) {
    //         if (index < this.abb.length) {
    //             this.abb[index] = v;
    //             this.tamanho++;
    //             return index;  // Retorna o índice onde o valor foi inserido
    //         } else {
    //             throw new ArrayIndexOutOfBoundsException("A árvore está cheia");
    //         }
    //     }
    
    //     if (v.compareTo(this.abb[index]) < 0) {
    //         int leftIndex = nodeLeft(index);
    //         inserirRecursivamente(leftIndex, v);
    //     } else {
    //         int rightIndex = nodeRight(index);
    //         inserirRecursivamente(rightIndex, v);
    //     }
    
    //     return balancearAVL(index);  // Retorna o índice do nó balanceado
    // }





    // private void trocaMaximoEsquerda(int troca, int indexAtual, int anterior) {
    //     if (nodeRight(troca) < tamanho && abb[nodeRight(troca)] != null) {
    //         trocaMaximoEsquerda(nodeRight(troca), indexAtual, troca);
    //         return;
    //     }

    //     if (indexAtual == anterior) {
    //         abb[nodeLeft(anterior)] = abb[nodeLeft(troca)];
    //     } else {
    //         abb[nodeRight(anterior)] = abb[nodeLeft(troca)];
    //     }

    //     abb[indexAtual] = abb[troca];
    //     abb[troca] = null;
    // }


    // // Conserta a árvore quando um nodo é removido
    // private void consertarFilhos(int index) {
    //     if (abb[nodeLeft(index)] == null || abb[nodeRight(index)] == null) {
    //         if (abb[nodeLeft(index)] == null) 
    //             abb[index] = abb[nodeRight(index)];
    //         else
    //             abb[index] = abb[nodeLeft(index)];
    //         abb[nodeLeft(index)] = null; 
    //         abb[nodeRight(index)] = null; 
    //     } else {
    //         trocaMaximoEsquerda(nodeLeft(index), index, index);
    //     }
    // }





    // protected boolean remove(String v){ // Remove um elemento da árvore.

    //     // Farei de modo não recursivo
    //     Stack<Integer> pilha = new Stack<>();

    //     int i = 0;

    //     pilha.push(i);

    //     int flag = 0;

    //     while (i < this.tamanho) {
    //         if (v.compareTo(this.abb[i]) < 0) {
    //             int left = nodeLeft(i);
    //             if (left < this.abb.length && (v.compareTo(this.abb[left]) == 0)) {
    //                 consertarFilhos(left);
    //                 this.abb[left] = null;
    //                 this.tamanho--;
    //                 flag = 1;
    //             }
    //             i = left;
    //         } else {
    //             int right = nodeRight(i);
    //             if (right < this.abb.length && (v.compareTo(this.abb[right]) == 0)) {
    //                 consertarFilhos(right);
    //                 this.abb[right] = null;
    //                 this.tamanho--;
    //                 flag = 1;
    //             }
    //             i = right;
    //         }

    //         pilha.push(i);
            
    //     }

    //     if(flag == 0){
    //         return false;
    //     }

    //     // Rebalanceando

    //     while(!pilha.isEmpty()){
    //         balancearAVL(pilha.pop());
    //     }

    //     return true;



