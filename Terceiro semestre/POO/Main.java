import java.util.Scanner;

public class Main{

    public static void main(String[] args){
        Tabuleiro t = new Tabuleiro(2);
        Scanner scanner = new Scanner(System.in);

        while(!t.end_game()){
            t.print_matrix();
            System.out.print("Digite um comando (up/down/left/right): ");
            String comando = scanner.nextLine().toLowerCase();
            
            switch (comando) {
                case "up":
                    t.up();
                    break;
                case "u":
                    t.up();
                    break;
                case "down":
                    t.down();
                    break;
                case "left":
                    t.left();
                    break;
                case "l":
                    t.left();
                    break;
                
                case "right":
                    t.right();
                    break;
                case "r":
                    t.right();
                    break;

                default:
                    System.out.println("Comando não encontrado.");
                    break;
            }

        }

        System.out.println("Fim de jogo!");
        scanner.close();


    }

    




}
