import java.io.*;
import java.net.*;

public class ConnectToServer {
    private Socket clientSocket;
    private BufferedReader reader;
    private BufferedWriter writer;

    private String serverAddress;
    private int serverPort;

    public ConnectToServer(String serverAddress, int serverPort) {
        this.serverAddress = serverAddress;
        this.serverPort = serverPort;
    }   

    public void startConnection() { //incia uma conexão
        try {
            clientSocket = new Socket(this.serverAddress, this.serverPort); // Conectar ao servidor
            reader = new BufferedReader(new InputStreamReader(clientSocket.getInputStream())); //cria o buffer para ler uma mensagem
            writer = new BufferedWriter(new OutputStreamWriter(clientSocket.getOutputStream())); //cria o buffer para mandar uma mensagem

        } catch (IOException e) {
            e.printStackTrace(); // Aqui você pode querer lidar de outra forma com a exceção
        }
    }

    public void closeConnection() { //fecha uma conexao
        try {
            if (reader != null) {
                reader.close();
            }
            if (writer != null) {
                writer.close();
            }
            if (clientSocket != null) {
                clientSocket.close();
            }
        } catch (IOException e) {
            e.printStackTrace(); // Aqui você pode querer lidar de outra forma com a exceção
        }
    }

    public String SendMenssage(String mensagem){
        try {
            writer.write(mensagem); //manda a mensagem
            writer.flush(); // Garante que a mensagem seja enviada imediatamente

            return this.receiveMessage();
        } catch (IOException e) {
            e.printStackTrace();

            return "Erro";
        }
    }

    private String receiveMessage() {
        StringBuilder builder = new StringBuilder();

        try {
            String line;

            while ((line = reader.readLine()) != null && !line.equals("END")) {
                builder.append(line + "\n");
            }
        } catch (IOException e) {
            e.printStackTrace();
            return null;
        }
        return builder.toString();
    }   
}