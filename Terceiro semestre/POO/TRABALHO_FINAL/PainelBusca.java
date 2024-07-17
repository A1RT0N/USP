import java.awt.*;

import javax.swing.*;
import javax.swing.border.TitledBorder;

public class PainelBusca {
    public JPanel PainelCampos; //declara o painel de campos
    public JPanel PainelBotoesEdicao; //declara o painel que contém os botões de edição
    public JPanel PainelResposta; //declarar o painel que irá aparecer as respostas
    public JPanel PainelPrincipal; //declaração do painel principal

    public JTextArea resultArea; //declarar a área aonde irá aparecer a resposta do .c

    public JScrollPane scrollPane; //declarar o scroll

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

    //declara os botões
    public JButton searchButton;
    public JButton searchAllButton;

    public PainelBusca(){
        this.InicializaPainelCampos(); //inicializa o painel de campos

        this.InicializaPainelBotoesEdicao(); //inicializa o painel que contém os botões de edição

        this.InicializaPainelResultado(); //inicializar o painel de resultado

        this.InicializaPainelPrincipal(); //inicializar o painel principal
    }

    private void InicializaPainelPrincipal(){
        this.PainelPrincipal = new JPanel(new BorderLayout(10, 10)); //inicializa o painel principal

        this.PainelPrincipal.add(this.PainelCampos, BorderLayout.NORTH); //adicionar o painel de campos no painel principal
        this.PainelPrincipal.add(this.scrollPane, BorderLayout.CENTER); //adicionar o conjunto de paineis de resposta ao painel principal
    }

    private void InicializaPainelResultado(){
        this.resultArea = new JTextArea(); //criar a área

        //fazer declarações de como será seu visual
        this.resultArea.setEditable(false);
        this.resultArea.setBackground(Color.WHITE);
        this.resultArea.setForeground(Color.BLACK);
        this.resultArea.setBorder(BorderFactory.createTitledBorder("Resultados"));
        
        //atualiza resultArea
        this.resultArea.revalidate();
        this.resultArea.repaint();

        this.PainelResposta = new JPanel(new BorderLayout()); //inicializar o painel
        this.PainelResposta.add(this.resultArea, BorderLayout.CENTER); //adicionar a área de resposta no centro
        this.PainelResposta.add(this.PainelBotoesEdicao, BorderLayout.WEST); //adicionar o pianel de botões a esquerda

        this.scrollPane = new JScrollPane(this.PainelResposta); //criar o scroll no painel de resposta
    }

    private void InicializaPainelBotoesEdicao(){
        this.PainelBotoesEdicao = new JPanel(); //inicializa o painel

        this.PainelBotoesEdicao.setLayout(new BoxLayout(this.PainelBotoesEdicao, BoxLayout.Y_AXIS)); //o declara na posição vertical
    }

    private void InicializaPainelCampos(){
        this.PainelCampos = new JPanel(new GridLayout(6, 2, 10, 10)); //inicializa o painel

        //Criar o título do painel de campos
        this.PainelCampos.setBackground(new Color(193, 224, 255)); // coloca cor no fundo do painel
        TitledBorder searchPanelBorder = BorderFactory.createTitledBorder("Painel de busca de registros"); //título do painel
        searchPanelBorder.setTitleFont(new Font("Arial", Font.BOLD, 18)); //fonto do título do painel
        this.PainelCampos.setBorder(searchPanelBorder); //colocar o título
        
        this.CreateLabelsCampos(); //Criar as labels e campos do painel de campos
        this.CreateButtons(); //Criar os botões do painel de campos
    }

    private void CreateButtons(){
        this.searchButton = new JButton("Procurar"); 
        this.PainelCampos.add(searchButton);

        this.searchAllButton = new JButton("Listar todos");
        this.PainelCampos.add(searchAllButton);
    }

    private void CreateLabelsCampos(){
        //referente ao id
        this.idLabel = new JLabel(" Id:"); //criar a label de id
        this.PainelCampos.add(idLabel); //adicionar a label ao painel

        this.idCampo = new CenteredTextField(); //criar o campo do id
        this.PainelCampos.add(this.idCampo); //adicionar no pianel o campo do id
        
        //referente a idade
        this.idadeLabel = new JLabel(" Idade:"); //criar a label de idade
        this.PainelCampos.add(this.idadeLabel); //adicionar a label ao painel

        this.idadeCampo = new CenteredTextField(); //criar o campo da idade
        this.PainelCampos.add(this.idadeCampo); //adicionar no painel o campo da idade
        
        //referente ao nome do jogador
        this.nomeJogadorLabel = new JLabel(" Nome Jogador:"); //criar a  label do nome do jogador
        this.PainelCampos.add(this.nomeJogadorLabel); //adicionar no painel

        this.nomeJogadorCampo = new CenteredTextField(); //criar o campo
        this.PainelCampos.add(this.nomeJogadorCampo); //adicionar no painel
        
        //referente a nacionalidade
        this.nacionalidadeLabel = new JLabel(" Nacionalidade:"); //criar a label da nacionalidade
        this.PainelCampos.add(this.nacionalidadeLabel); //adicionar no painel

        this.nacionalidadeCampo = new CenteredTextField(); //criar o campo
        this.PainelCampos.add(this.nacionalidadeCampo); //adicionar no painel
        
        //referente ao nome clube
        this.nomeClubeLabel = new JLabel(" Nome Clube:"); //criar a label do nome do clube
        this.PainelCampos.add(this.nomeClubeLabel); //adicionar no painel

        this.nomeClubeCampo = new CenteredTextField(); //criar o campo
        this.PainelCampos.add(this.nomeClubeCampo); //adicionar no painel
    }
}