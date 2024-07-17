import java.util.ArrayList;

public class ArvAVL extends ArvBin{
    public ArvAVL(int len){
        super(len);
    }

    private int altura(int index){ //retorna a altura de um nó
        if ((index == -1) || (this.abb[index] == null)) return -1;

        int AlturaFilhoEsq = altura(this.nodeLeft(index)); //altura do filho esquerdo
        int AlturaFilhoDir = altura(this.nodeRight(index)); //altura do filho direito

        return Math.max(AlturaFilhoEsq, AlturaFilhoDir) + 1; //retorna a maior altura mais 1
    }

    private void RotacaoEsq(int index){ //realiza a rotação para a esquerda
       // System.out.println("Rotação esquerda " + this.arvore[index]);
        ArrayList<String> SubArvore = this.SubArvore(index); //pegar a subarvore a ser balanceada
        this.Remove_SubArvore(index); //remover toda a SubArvore

        //a ideia é primeiro adicionar o filho direito, depois o pai e ai dps o resto da subarvore

        if (2 <= SubArvore.size() - 1) super.insert(SubArvore.get(2)); //adicionar o filho direito
        super.insert(SubArvore.get(0)); //adicionar o pai
        
        //inserir todo o resto
        super.insert(SubArvore.get(1)); //adiciono o filho esquerdo fora do loop para poder coemçar o loop em 3

        for (int i = 3; i < SubArvore.size(); i++){
            super.insert(SubArvore.get(i));
        }

        //System.out.println(this.toString() + "\n");
    }

    private void RotacaoDir(int index){ //realiza a rotação para a direita
       // System.out.println("Rotação direita " + this.arvore[index]);
        ArrayList<String> SubArvore = this.SubArvore(index); //pegar a subarvore a ser balanceada
        this.Remove_SubArvore(index); //remover toda a SubArvore

        //a ideia é primeiro adicionar o filho esquerdo, depois o pai e ai dps o resto da subarvore

        if (1 <= SubArvore.size() - 1) super.insert(SubArvore.get(1)); //adicionar o filho esquerdo
        super.insert(SubArvore.get(0)); //adicionar o pai
        
        //inserir todo o resto
        for (int i = 2; i < SubArvore.size(); i++){
            super.insert(SubArvore.get(i));
        }

        //System.out.println(this.toString() + "\n");
    }

    private void RotacaoEsqDir(int index){ //realiza a rotação para esquerda e depois direita
        //System.out.println("Rotação esquerda direita " + this.arvore[index]);
        RotacaoEsq(this.nodeLeft(index)); //rotação esquerda no filho a esquerda
        RotacaoDir(index); //rotação a direita no pai
    }

    private void RotacaoDirEsq(int index){ //realiza a rotação para direita e depois esquerda
       // System.out.println("Rotação direto esquerda " + this.arvore[index]);
        RotacaoDir(this.nodeRight(index)); //rotação direita no filho a direita
        RotacaoEsq(index); //rotação a esquerda no pai
    }

    private boolean isBalanceNode(int index){ //verifica se a árvore está balanceada
        int fb = altura(this.nodeLeft(index)) - altura(this.nodeRight(index)); //calcular o fator de balanceamento

        if (Math.abs(fb) == 2){ //se o módulo do fator de balanceamento for maior ou igual a 2 significa que a árvore está desbalanceada
            return false;
        }

        //se chegou até aqui significa que a árvore está balanceada
        return true;
    }

    @Override
    public boolean isBalance(){ //verifica se a árvore está balanceada
        for (int i = 0; i < this.tamanho; i++){
            if (this.abb[i] == null) continue;

            //se este nó não estiver balanceado a árvore não está balanceada
            if (!isBalanceNode(i)) return false;
        }

        //se chegou até aqui signfica que a árvore está balanceada
        return true; 
    }

    private void Balance(int index){ //faz o balanceamneto na árvore
        int fb = altura(this.nodeLeft(index)) - altura(this.nodeRight(index)); //calcular o fator de balanceamento

        if (fb == -2){ 
            if ((altura(this.nodeLeft(this.nodeRight(index))) - altura(this.nodeRight(this.nodeRight(index)))) <= 0){ //if altura(p->dir-esq) - altura(p->dir->dir) <= 0
                RotacaoEsq(index); //faz a rotação para esquerda
            }else{
                RotacaoDirEsq(index); //faz a rotação para direita e depois esquerda
            }
        }

        if (fb == 2){
            if ((altura((this.nodeLeft(this.nodeLeft(index)))) - altura((this.nodeRight(this.nodeLeft(index))))) >=0 ) { //if altura(p->esq->esq) - altura(p->esq->dir)
                RotacaoDir(index); //faz a rotação para a direita
            }else{
                RotacaoEsqDir(index); //faz a rotação para a esquerda depois a direita
            }
        }
    }

    private void BalanceiaSeNecessario(){ //faz o balanceamento só se necessário
        for (int i = this.tamanho - 1; i >= 0; i--){
            if (this.abb[i] == null) continue;

            if (!isBalanceNode(i)){ //se o nó não estiver balanceado
                Balance(i); //balanceia o nó
            }
        }
    }

    @Override
    protected void insert(String value){
        super.insert(value); //insere sem balancear

        this.BalanceiaSeNecessario(); //balanceia a árvore se preciso
    }

    @Override
    public boolean remove(String v){
        boolean result = super.remove(v); //remover sem fazer balanceamento

        this.BalanceiaSeNecessario();//balanceia a árvore se preciso

        return result;
    }
}