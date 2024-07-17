// 1) Implemente uma classe Par, que representa um par de dados qualquer. Os tipos desses dados, que não precisam ser os mesmos, devem ser definidos no instante da instanciação do objeto. Não esqueça de implementar os getters para essa classe.

// 2) Implemente uma lista ligada (classe ListaLigada), em que cada item, colocado dentro de um nó seja de um tipo genérico, que deve ser definido na hora da instanciação da lista. Note que será necessário definir, também, uma classe NoLista, que representa um nó da lista. A sua lista ligada deve implementar, pelo menos, as seguintes operações:
//    a) inserir um elemento no início da lista;
//    b) inserir um elemento no fim da lista;
//    c) remover o primeiro elemento da lista;
//    d) remover o último elemento da lista;
//    e) toString()

// 3) Teste a sua lista ligada com elementos das são um par formado por um número inteiro e um double.


public class linkedlist<T>{

    private Node<T> cabeca;


    public linkedlist(){
        cabeca = null;
    }


    private Node<T> last(){

        Node<T> temp =  cabeca;
        while(temp.get_elemento() != null){
            temp = temp.get_ponteiro();
        }

        return temp;

    }



    public void insert(T adicionar){
        Node<T> no = new Node(adicionar);

        set_ponteiro(no) = cabeca;

        cabeca = no;

    }

    public void pop(){
        if(cabeca == null){
            return;
        }else{
            Node<T> final = last();
            final.get_ponteiro = no;
        }
    }

    public void pool(){

        if(cabeca == null){
            return;
        }else{
            cabeca= cabeca.get_ponteiro();
        }

    }


}


class Node<T>{  
     T elemento;
     Node<T> proximo;  

    public Node(T elemento){
       elemento = elemento;
       proximo = null;
    }

    public T get_elemento(){
        return elemento;
    }

    public Node<T> get_ponteiro(){
        return proximo;
    }

    public void set_ponteiro(Node<T> ponteiro){
        this.proximo = ponteiro;
    }

    
}

class par<T1, T2>{

    private T1 parte1;
    private T2 parte2;
    
    public par(T1 coisa1, T2 coisa2){
        this.parte1 = coisa1;
        this.parte2 = coisa2;
    }

    public T1 get_primeiro(){
        return this.parte1;
    }

    public T2 get_secundo(){
        return this.parte2;
    }

}
