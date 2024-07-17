import java.util.Scanner;

public class main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        ArvBin unbalance = new ArvBin(1000);
        ArvBin balance = new ArvBal(1000);
        ArvBin avl = new ArvAVL(1000);

        while(sc.hasNext()){
            String operator = sc.next();
            String value = sc.next();

            switch (operator) {
                case "i":

                    unbalance.insert(value);
                    balance.insert(value);
                    avl.insert(value);
                    break;
                
                case "d":

                    unbalance.remove(value);
                    balance.remove(value);
                    avl.remove(value);
                    break;

                default:
                    break;
            }
        }

        sc.close();


        System.out.println(unbalance.toString());

        System.out.println();
        
        System.out.println(balance.toString());

        System.out.println();

        System.out.println(avl.toString());
        
        System.out.println();


    }
}
