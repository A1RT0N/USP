import java.awt.*;

import javax.swing.*;

public class PainelInicial {
    public JPanel Painel; //declara o painel

    //declara ambos os bo~toes
    public JButton openFileButton;
    public JButton searchButton;

    public PainelInicial(){
        Painel = new JPanel(new BorderLayout(10, 10)); //inicializa o painel

        // Cria o rótulo de mensagem introdutória

        JLabel introLabel = new JLabel("<html><h1 style='text-align: center;'>Bem-vindo ao Aplicativo de Gestão de Jogadores</h1><br><h3 style='text-align: center;'>Lembre-se de se conectar ao servidor antes de fazer qualquer procedimento</h3></html>");
        introLabel.setHorizontalAlignment(SwingConstants.CENTER); // centraliza o texto

        //Botões

        this.openFileButton = new JButton("Abrir Arquivo"); //botão de abrir o arquivo

        this.searchButton = new JButton("Fazer procura"); //botão de fazer preocura
        searchButton.setEnabled(false); // Desativado inicialmente (até que exista a pasta DadosCliente)

        // Painel para os botões

        JPanel buttonPanel = new JPanel(new GridLayout(2, 1, 10, 10)); //criar o painel
        buttonPanel.add(openFileButton); //adicionar o botão de abrir arquivo
        buttonPanel.add(searchButton); //adicionar o botão de porcura
    
        // Adiciona o rótulo e os botões ao painel inicial
        
        this.Painel.add(introLabel, BorderLayout.NORTH); //adicionar o rótulo
        this.Painel.add(buttonPanel, BorderLayout.CENTER); //adicionar o painel de botão
    }
}
