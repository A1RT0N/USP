import java.util.Scanner;

public class Main{

    public static void main(String[] args){

        int matriz_entrada [][];

        Scanner scanner = new Scanner(System.in);

        String linhas = scanner.nextLine();

        String[] conj_numeros = linhas.split(" ");

        int tamanho_da_matriz = (int) Math.sqrt(conj_numeros.length);

        matriz_entrada = new int[tamanho_da_matriz][tamanho_da_matriz];


        for(int i = 0, k = 0; i < tamanho_da_matriz; i++){
            for(int j = 0; j < tamanho_da_matriz; j++, k++){
                matriz_entrada[i][j] = Integer.parseInt(conj_numeros[k]);
            }
        }

        Tabuleiro t = new Tabuleiro(tamanho_da_matriz, matriz_entrada);

        t.tamanho_matriz = tamanho_da_matriz;


        for(int i = 0; i < tamanho_da_matriz; i++){
            for(int j = 0; j < tamanho_da_matriz; j++){
                t.matriz[i][j] = matriz_entrada[i][j];
            }
        }



        String comando = scanner.nextLine();

        int iteracoes = comando.length();

        for(int i = 0; i < iteracoes; i++){
            t.print_matrix();
            System.out.printf("\n");
            // System.out.print("Digite um comando (up/down/left/right): ");
            char op = comando.charAt(i);  
            switch (op) {
                case 'u':
                    t.up();
                    break;
                case 'l':
                    t.left();
                    break;
                
                case 'r':
                    t.right();
                    break;

                case 'd':
                    t.down();
                    break;

                default:
                    System.out.println("Comando não encontrado!");
                    break;
            }

        }

        t.print_matrix();

        System.out.println();


        System.out.print("Posicao final: ");
        if(t.end_game()){
            System.out.println("true");
        }else{
            System.out.println("false");
        }
        
        scanner.close();


    }

    
}
