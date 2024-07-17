import javax.swing.*;
import java.awt.*;

public class PainelArquivos {
    public JPanel Painel;

    //definir os botões
    public JButton file1Button;
    public JButton file2Button;
    public JButton file3Button;

    public PainelArquivos(){
        this.Painel = new JPanel(new GridLayout(3, 1, 10, 10)); //inicializar o painel
    }

    public void Atualizar(){
        //reinicia o painel
        this.Painel.removeAll();
        this.Painel.setLayout(new GridLayout(3, 1, 10, 10));

        //setar os botões
        this.file1Button = new JButton("Arquivo 1.csv"); //criar o botão
        this.Painel.add(this.file1Button); //colocar no painel

        this.file2Button = new JButton("Arquivo 2.csv"); //criar o botão
        this.Painel.add(this.file2Button); //colocar no painel
        
        this.file3Button = new JButton("Arquivo 3.csv"); //criar o botão
        this.Painel.add(this.file3Button); //colocar no painel

        //atualiza o painel
        this.Painel.revalidate();
        this.Painel.repaint();
    }
}
