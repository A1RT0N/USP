import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.Arrays;

public class GUI_FIFA extends JFrame {
    private PainelInicial painelInicial;
    private PainelBusca painelBusca;
    private PainelArquivos painelArquivos;

    private JanelaEditarJogador janelaEditar;

    private String address, port; //Variáveis para poder se conectar ao servidor

    private Player[] players; //vetor de jogadores

    //cria o gui
    public GUI_FIFA() {
        //fazer a inicialização das fontes
        Font font = new Font("Arial", Font.BOLD, 16);
        UIManager.put("Label.font", font);
        UIManager.put("TextField.font", font);
        UIManager.put("Button.font", font);
        UIManager.put("TextArea.font", font);
        UIManager.put("Menu.font", font);
        UIManager.put("MenuItem.font", font);

        setTitle("FIFA Player Manager"); //titulo
        setSize(800, 600); //tamanho
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE); //operação para fechar o gui
        initComponents(); //inicializar os componentes
    }

    /**********************************
        Redirecionamento de painel
    *************************************/

    private void returnMenuAction() { //ir para o painel inicial
        getContentPane().removeAll();
        add(this.painelInicial.Painel, BorderLayout.CENTER);
        revalidate();
        repaint();
    }

    private void returnDataAction() { //ir para o painel de escolher arquivo
        getContentPane().removeAll();
        add(this.painelArquivos.Painel, BorderLayout.CENTER);
        revalidate();
        repaint();
    }

    private void showSearchPanel() { //ir para o painel de fazer uma procura
        getContentPane().removeAll();
        add(this.painelBusca.PainelPrincipal, BorderLayout.CENTER);
        revalidate();
        repaint();
    }

    /**********************************
            Inicializações
    *************************************/
    private void initComponents() {
        this.players = new Player[0]; // Inicializar a array de jogadores como vazio

        /**********************************
                 Painel inicial
        *************************************/
        this.painelInicial = new PainelInicial(); //inicializar o painel inicial

        painelInicial.openFileButton.addActionListener(e -> openFileAction()); //ação caso o botão seja clicado
        painelInicial.searchButton.addActionListener(e -> showSearchPanel()); //ação caso o botão seja clicado

        add(this.painelInicial.Painel, BorderLayout.CENTER); //adiciona o PainelInicial na tela centalizado
        
        //fazer a checagem se o botão de Fazer Procura pode estar ativado em tempo real
        //Ele só vai estar estaviado se existir a pasta trabalho/dadosCliente
        //Essa pasta é criada quando um arquivo é carregado (pasta criada pelo python)
        Timer fileCheckTimer;
        fileCheckTimer = new Timer(1000, new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                boolean fileExists = Files.exists(Paths.get("trabalho/dadosCliente"));
                painelInicial.searchButton.setEnabled(fileExists);
            }
        });
        fileCheckTimer.start();

        /**********************************
                 Painel de busca
        *************************************/
        this.painelBusca = new PainelBusca(); //inicializar o painel de busca

        painelBusca.searchButton.addActionListener(e -> searchPlayers()); //ação caso o botão seja clicado
        painelBusca.searchAllButton.addActionListener(e -> searchAllPlayers()); //ação caso o botão seja clicado

         /**********************************
                Painel de abrir arquivos
        *************************************/
        this.painelArquivos = new PainelArquivos(); //inicializar o painel de arquivos

         /**********************************
                        Menu
        *************************************/
        initializeMenu(); //inicializar o menu
    }
    
    private void initializeMenu() { //inicializa o menu
        JMenuBar menuBar = new JMenuBar();
        JMenu fileMenu = new JMenu("Menu");
    
        JMenuItem connectMenuItem = new JMenuItem("Conectar a um servidor");
        connectMenuItem.addActionListener(e -> connectToServer());
        fileMenu.add(connectMenuItem);

        JMenuItem returnMenu = new JMenuItem("Retornar ao menu inicial");
        returnMenu.addActionListener(e -> returnMenuAction());
        fileMenu.add(returnMenu);
    
        menuBar.add(fileMenu);
        setJMenuBar(menuBar);
    }

    /**********************************
         Ações de botões
    *************************************/
    
    private void openFileAction() {// Ação para o botão "Abrir Arquivo"
        returnDataAction();
        
        this.painelArquivos.Atualizar(); //atualizar o painel

        this.painelArquivos.file1Button.addActionListener(e -> { //ação caso o botão seja acionado
            String command = "CriarBin,dado1.csv";
            sendCommandToServer(command);
            
            returnMenuAction(); //voltar ao menu
        });

        this.painelArquivos.file2Button.addActionListener(e -> { //ação caso o botão seja acionado
            String command = "CriarBin,dado2.csv";
            sendCommandToServer(command);
            
            returnMenuAction(); //voltar ao menu
        });

        this.painelArquivos.file3Button.addActionListener(e -> { //ação caso o botão seja acionado
            String command = "CriarBin,dado3.csv";
            sendCommandToServer(command);
            
            returnMenuAction(); //voltar ao menu
        });

    }

    // Ação para o botão "Editar jogador"
    private void editAction(Player jogador) {
        this.janelaEditar = new JanelaEditarJogador(jogador); //criar uma nova janela

        janelaEditar.changeData.addActionListener(e -> sendEditMessage()); //ação se o botão for clicado
        janelaEditar.removePlayer.addActionListener(e -> sendRemoveMessage()); //ação se o botão for clicado
    }
    
    /**********************************
        Ações de editar, remover ou buscar jogadores
    *************************************/

    private void sendEditMessage() { //ação do botão alterar dado
        String id = this.janelaEditar.idCampo.getText().isEmpty() ? "nulo" : this.janelaEditar.idCampo.getText(); //pegar o valor do id do campo id
        String age = this.janelaEditar.idadeCampo.getText().isEmpty() ? "nulo" : this.janelaEditar.idadeCampo.getText(); //pegar o valor da iade do campo idade
        String name = this.janelaEditar.nomeJogadorCampo.getText().isEmpty() ? "nulo" : this.janelaEditar.nomeJogadorCampo.getText(); //pegar o nome do campo nome
        String nationality = this.janelaEditar.nacionalidadeCampo.getText().isEmpty() ? "nulo" : this.janelaEditar.nacionalidadeCampo.getText(); //pegar a nacionalidade do campo nacionalidade
        String club = this.janelaEditar.nomeClubeCampo.getText().isEmpty() ? "nulo" : this.janelaEditar.nomeClubeCampo.getText(); //pegar o clube do campo clube
        
        // Ajustar a formatação para mandar para o servidor (python)
        String command = String.format("AlterarDado,%s,%s,%s,%s,%s", id, age, name, nationality, club);
    
        sendCommandToServer(command); // Mandar o comando para o servidor

        for (int i = 0; i < players.length; i++) {
            if (players[i].getId() == Integer.parseInt(id)) {
                players[i].setAge(Integer.parseInt(age));
                players[i].setName(name);
                players[i].setNationality(nationality);
                players[i].setClub(club);
                break;
            }
        }
    
        janelaEditar.editFrame.setVisible(false); // Fechar a janela de edição após a ação
    
        searchPlayers(); // Atualizar a lista de jogadores imediatamente após a edição
    }
    
    private void sendRemoveMessage() { //ação do botão de remover jogador
        String id = this.janelaEditar.idCampo.getText().isEmpty() ? "nulo" : this.janelaEditar.idCampo.getText(); //pegar o valor do id do campo id   // Talvez dê para remover esse cara
        
        // Ajustar a formatação para mandar para o servidor (python)
        String command = String.format("Remover,%s", id);
    
        sendCommandToServer(command); // Mandar o comando para o servidor
    
        // Remover jogador do vetor players
        players = Arrays.stream(players)
                        .filter(player -> !(player.getId() == Integer.parseInt(id)))
                        .toArray(Player[]::new);
    
        janelaEditar.editFrame.setVisible(false); // Fechar a janela de edição após a ação
    
        searchPlayers(); // Atualizar a lista de jogadores imediatamente após a remoção
    }
    
    private void searchPlayers() { //ação de botão procurar
        // Se nada foi passado no campo colocar seu valor no nulo para passar por python com a formatação correta
        String id = this.painelBusca.idCampo.getText().isEmpty() ? "nulo" : this.painelBusca.idCampo.getText(); //pegar o valor do id do campo id
        String age = this.painelBusca.idadeCampo.getText().isEmpty() ? "nulo" : this.painelBusca.idadeCampo.getText(); //pegar o valor da iade do campo idade
        String name = this.painelBusca.nomeJogadorCampo.getText().isEmpty() ? "nulo" : this.painelBusca.nomeJogadorCampo.getText(); //pegar o nome do campo nome
        String nationality = this.painelBusca.nacionalidadeCampo.getText().isEmpty() ? "nulo" : this.painelBusca.nacionalidadeCampo.getText(); //pegar a nacionalidade do campo nacionalidade
        String club = this.painelBusca.nomeClubeCampo.getText().isEmpty() ? "nulo" : this.painelBusca.nomeClubeCampo.getText(); //pegar o clube do campo clube

        // Ajustar a formatação para mandar para o servidor (python)
        String command = String.format("Busca,%s,%s,%s,%s,%s", id, age, name, nationality, club);
    
        String response = sendCommandToServer(command); // Mandar o comando para o servidor e pegar a resposta

        MostrarResultado(response); //mostrar na tela o resultado do comando
    }    


    private void searchAllPlayers() { //ação do botão de procurar por todos os jogadores
       // String command = String.format("PrintarBin"); //
        
        // Mandar o comando para o servidor e pegar a resposta
        String response = sendCommandToServer("PrintarBin"); 
        
        MostrarResultado(response); //mostrar na tela o resultado do comando
    }
        
    /**********************************
         Funções auxiliares
    *************************************/

    private void MostrarResultado(String response){
        String result;

        //fazer a decomposição da String
        if(!response.equals("Registro inexistente.\n\n\n")){

            String[] parts = response.split("\n");
        
            // Inicializar o array de players com o tamanho apropriado
            players = new Player[parts.length];
        
            String[][] vetor_final = new String[parts.length][];
            
            //fazer o split
            for (int i = 0; i < parts.length; i++) {
                vetor_final[i] = parts[i].split(",");
            }
            
            //criar cada jogador
            for (int i = 0; i < parts.length; i++) {
                players[i] = new Player(Integer.parseInt(vetor_final[i][0]), Integer.parseInt(vetor_final[i][1]), vetor_final[i][2], vetor_final[i][3], vetor_final[i][4]);
            }
            
            //fazer a associação de valores
            for (int i = 0; i < parts.length; i++) {
                vetor_final[i][0] = "ID: " + vetor_final[i][0] + "\n";
                vetor_final[i][1] = "Idade: " + vetor_final[i][1] + "\n";
                vetor_final[i][2] = "Nome jogador: " + vetor_final[i][2] + "\n";
                vetor_final[i][3] = "Nacionalidade: " + vetor_final[i][3] + "\n";
                vetor_final[i][4] = "Clube: " + vetor_final[i][4] + "\n" + "\n";
            }
            
            //remover todos os botões que já existes
            this.painelBusca.PainelBotoesEdicao.removeAll();
            
            //criar a área de botões com as dimensões definidas
            this.painelBusca.PainelBotoesEdicao.add(Box.createRigidArea(new Dimension(20, 50)));
            
            //criar os botões de edição
            for (int iteracao = 0; iteracao < parts.length; iteracao++) {
                JButton editButton = new JButton("Editar " + (iteracao + 1)); //criar o botão
                final int currentIteration = iteracao; // Captura o valor atual de iteracao
        
                editButton.addActionListener(e -> editAction(players[currentIteration])); //ação caso o botão seja clicado

                this.painelBusca.PainelBotoesEdicao.add(editButton); //adicionar o botão no painel
                this.painelBusca.PainelBotoesEdicao.add(Box.createRigidArea(new Dimension(20, 85))); // criar o espaçamento entre os botões
            }
            
            //atualizar o painel
            this.painelBusca.PainelBotoesEdicao.revalidate();
            this.painelBusca.PainelBotoesEdicao.repaint();
            
            //fazer a concatenação das strings para poder printar na tela com a formatação correta
            result = concatenateStringArray(vetor_final); 
        }else{
            result = "Registro inexistente.";
            //remover todos os botões que já existes
            this.painelBusca.PainelBotoesEdicao.removeAll();
        }
    
        SwingUtilities.invokeLater(() -> this.painelBusca.resultArea.setText(result)); // Printar a resposta em resultArea
    }
    
    private static String concatenateStringArray(String[][] array) {
        StringBuilder sb = new StringBuilder();

        for (String[] subArray : array) {
            for (String str : subArray) {
                sb.append(str).append(" "); // Adiciona um espaço entre as strings
            }
        }

        // Remove o último espaço adicionado
        if (sb.length() > 0) {
            sb.setLength(sb.length() - 1);
        }

        return sb.toString();
    }

    /**********************************
         Parte com o servidor
    *************************************/
    private String sendCommandToServer(String command) {
        /*
        Manda um comando para o servidor e retorna o resultado
         */

        ConnectToServer server = new ConnectToServer(this.address, Integer.parseInt(this.port)); //instancia o objeto servidor

        server.startConnection(); //inicia a conexão com o servidor

        String results = server.SendMenssage(command);

        server.closeConnection();
        
        return results;
    }

    private void connectToServer() {
        /*
        Se conecta ao servidor
         */
        String address = JOptionPane.showInputDialog(this, "Enter server address:", "localhost"); //pega o localhost
        String port = JOptionPane.showInputDialog(this, "Enter server port:", "55555"); //pega a porta
        this.address = address;
        this.port = port;

        if ((this.address.equals("localhost")) && (this.port.equals("55555"))) {
            JOptionPane.showMessageDialog(this, "Conecatado ao servidor: " + address + ":" + port); //pop up para falar que se conectou com o servidor
        }   else{
            JOptionPane.showMessageDialog(this, "Não foi possível conectar ao servidor.\nVerifique o host e a porta");
        }
    }   
}