import java.awt.*;

import javax.swing.*;
import javax.swing.border.TitledBorder;

public class JanelaEditarJogador {
    //declarar o frame
    public JFrame editFrame;
    public JPanel PainelEdit;

    //declaração das labels
    public JLabel idLabel;
    public JLabel idadeLabel;
    public JLabel nomeJogadorLabel;
    public JLabel nacionalidadeLabel;
    public JLabel nomeClubeLabel;

    //declaração dos campos
    public CenteredTextField idCampo;
    public CenteredTextField idadeCampo;
    public CenteredTextField nomeJogadorCampo;
    public CenteredTextField nacionalidadeCampo;
    public CenteredTextField nomeClubeCampo;

    //declarar os botões

    public JButton changeData; //botão para alterar dado
    public JButton removePlayer; //botão para remover o jogador

    public JanelaEditarJogador(Player jogador){
        this.editFrame = new JFrame("Editar jogador "); //inicializar o frame

        this.editFrame.setSize(700, 300); // Defina o tamanho da janela conforme necessário
        this.editFrame.setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE); // Feche a janela ao invés de encerrar o programa

        InicializaPainelCampos(jogador); //inicializar o painel de campos

        //criar os botões

        this.changeData = new JButton("Editar jogador"); //criar o botõa
        this.PainelEdit.add(changeData); //colocar o botão no painel

        this.removePlayer = new JButton("Remover jogador"); //criar o botão
        this.PainelEdit.add(removePlayer); //adicionar o botão no painel

        this.editFrame.add(this.PainelEdit); //adicionar o painel no frame
        this.editFrame.setVisible(true); //colocar o frame como visível
    }

    private void InicializaPainelCampos(Player jogador){
        this.PainelEdit = new JPanel(); //inicializar o painel

        //definir caracterísitcas visuais do painel
        this.PainelEdit.setBackground(new Color(193, 224, 255)); // colocar uma cor de fundo
        TitledBorder editPanelBorder = BorderFactory.createTitledBorder("Edição de jogador: " + jogador.getName());
        editPanelBorder.setTitleFont(new Font("Arial", Font.BOLD, 18));
        this.PainelEdit.setBorder(editPanelBorder);
        this.PainelEdit.setLayout(new GridLayout(0, 2, 10, 10));
        
        CreateLabelsCampos(jogador);
    }

    private void CreateLabelsCampos(Player jogador){
        //referente ao id
       // this.idLabel = new JLabel(" Id:"); //criar a label de id
        //this.PainelEdit.add(idLabel); //adicionar a label ao painel

        this.idCampo = new CenteredTextField(); //criar o campo do id
        this.idCampo.setText(String.valueOf(jogador.getId()));
        //this.PainelEdit.add(this.idCampo); //adicionar no pianel o campo do id
        
        //referente a idade
        this.idadeLabel = new JLabel(" Idade:"); //criar a label de idade
        this.PainelEdit.add(this.idadeLabel); //adicionar a label ao painel

        this.idadeCampo = new CenteredTextField(); //criar o campo da idade
        this.idadeCampo.setText(String.valueOf(jogador.getAge()));
        this.PainelEdit.add(this.idadeCampo); //adicionar no painel o campo da idade
        
        //referente ao nome do jogador
        this.nomeJogadorLabel = new JLabel(" Nome Jogador:"); //criar a  label do nome do jogador
        this.PainelEdit.add(this.nomeJogadorLabel); //adicionar no painel

        this.nomeJogadorCampo = new CenteredTextField(); //criar o campo
        this.nomeJogadorCampo.setText(String.valueOf(jogador.getName()));
        this.PainelEdit.add(this.nomeJogadorCampo); //adicionar no painel
        
        //referente a nacionalidade
        this.nacionalidadeLabel = new JLabel(" Nacionalidade:"); //criar a label da nacionalidade
        this.PainelEdit.add(this.nacionalidadeLabel); //adicionar no painel

        this.nacionalidadeCampo = new CenteredTextField(); //criar o campo
        this.nacionalidadeCampo.setText(String.valueOf(jogador.getNationality()));
        this.PainelEdit.add(this.nacionalidadeCampo); //adicionar no painel
        
        //referente ao nome clube
        this.nomeClubeLabel = new JLabel(" Nome Clube:"); //criar a label do nome do clube
        this.PainelEdit.add(this.nomeClubeLabel); //adicionar no painel

        this.nomeClubeCampo = new CenteredTextField(); //criar o campo
        this.nomeClubeCampo.setText(String.valueOf(jogador.getClub()));
        this.PainelEdit.add(this.nomeClubeCampo); //adicionar no painel
    }
}