public class Tabuleiro{

    public int[][] matriz;  
    public int[] lista_posicao_vazia;
    public int tamanho_matriz;

    public Tabuleiro(int tamanho_matriz, int [][] matriz_dada){

        this.tamanho_matriz = tamanho_matriz;

        matriz = new int [tamanho_matriz][tamanho_matriz];

        lista_posicao_vazia = new int [2];

        for(int i = 0; i < tamanho_matriz; i++){
            for(int j = 0; j < tamanho_matriz; j++){
                this.matriz[i][j] = matriz_dada[i][j];
            }
        }

        for(int i=0; i< tamanho_matriz; i++){
            for(int j=0; j<tamanho_matriz; j++){
                if(matriz[i][j] == 0){
                    lista_posicao_vazia[0] = i;
                    lista_posicao_vazia[1] = j;
                    return;
                }
            }
        }

    }

    public void print_matrix() { 
        for(int p = 0; p<tamanho_matriz; p++){
            System.out.print("+------");
        }
        
        System.out.printf("+");

        for (int i = 0; i < tamanho_matriz; i++) {

            System.out.println();

            for (int j = 0; j < tamanho_matriz; j++) {
                System.out.printf("|  %2d  ", matriz[i][j]);
            }

            System.out.printf("|");

            System.out.println();

            for(int p = 0; p<tamanho_matriz; p++){
                System.out.print("+------");
            }

            System.out.printf("+");

        }

        System.out.println();

    }

    private void swap(int linha1, int coluna1, int linha2, int coluna2){
        int tmp = matriz[linha1][coluna1];
        matriz[linha1][coluna1] = matriz[linha2][coluna2];
        matriz[linha2][coluna2] = tmp;
        
    }


    public void up(){
        if((int)lista_posicao_vazia[0]+1 >= tamanho_matriz){
            // print_matrix();
            return;
        }
        swap(lista_posicao_vazia[0], lista_posicao_vazia[1], lista_posicao_vazia[0]+1, lista_posicao_vazia[1]);

        lista_posicao_vazia[0]++;
        
    }

    public void down(){
        if((int)lista_posicao_vazia[0]-1 < 0 ){
            // print_matrix();
            return;
        }
        swap(lista_posicao_vazia[0], lista_posicao_vazia[1], lista_posicao_vazia[0]-1, lista_posicao_vazia[1]);

        lista_posicao_vazia[0]--;
        
    }

    public void left(){
        if((int)lista_posicao_vazia[1]+1 >= tamanho_matriz){
            // print_matrix();
            return;
        }
        swap(lista_posicao_vazia[0], lista_posicao_vazia[1], lista_posicao_vazia[0], lista_posicao_vazia[1]+1);
        lista_posicao_vazia[1]++;
        
    }

    public void right(){

        if((int)lista_posicao_vazia[1]-1 < 0 ){
            // print_matrix();
            return;
        }

        swap(lista_posicao_vazia[0], lista_posicao_vazia[1], lista_posicao_vazia[0], lista_posicao_vazia[1]-1);

        lista_posicao_vazia[1]--;
        
    }


    public boolean end_game(){
        for(int i =0, k = 0; i< tamanho_matriz; i++){
            for(int j=0; j< tamanho_matriz; j++, k++){
                if(matriz[i][j] != k){
                    return false;
                }
            }
        }
        return true;
    }



}




// +------+------+------+