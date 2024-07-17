import javax.swing.SwingUtilities;

public class main {
    public static void main(String[] args) {
        //roda o GUI
        SwingUtilities.invokeLater(() -> {
            GUI_FIFA manager = new GUI_FIFA(); //instancia o objeto do GUI
            manager.setVisible(true);
        });
    }
}