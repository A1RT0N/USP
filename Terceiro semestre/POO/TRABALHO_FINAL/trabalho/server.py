import threading
import socket
import subprocess
import os
import platform
import time

from client import Client

def CompilarPrograma() -> str:
    # Determina o sistema operacional para ajustar o nome do executável
    system = platform.system()
    executable = "./programaTrab" if system != "Windows" else "programaTrab.exe"
    
    # Limpa arquivos de compilação anteriores e compila novamente o programa
    subprocess.run("make clean", shell=True, cwd=os.path.join(os.getcwd(), "arquivo")) #limpar os arquivos .c
    subprocess.run("make all", shell=True, cwd=os.path.join(os.getcwd(), "arquivo")) #compilar os arquivos .c

    
    return os.path.join("arquivo", executable)


class Server:
    def __init__(self, host, port) -> None:
        self.host = host
        self.port = port
        
        # Cria um socket TCP/IP para o servidor
        self.server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

        # Associa o socket ao endereço e porta especificados
        self.server.bind((host, port))
    
    def ExecutarComando(self, comando):
        #executa o comando no program C e retorna o otput gerado pelo comando
        resultado =  subprocess.run([self.executavel], input=comando, capture_output=True, text=True)

        print("Erro: ", resultado.stderr)

        return resultado.stdout

    # Comunicação com um cliente em específico
    def ComunicacaoCliente(self, cliente: Client):
        while True:
            try:
                # pegar uma mensagem do cliente
                mensagem = cliente.socket.recv(1024).decode("ascii")

                print(f"Comando do cliente: {mensagem}") #printar no terminal o comando do cliente

                if (mensagem == "exit"): #se a mensagem do cliente for exit
                    #terminar a comunicação com o cliente
                    cliente.socket.close()
                    break
                
                comandos = cliente.RepassarProC(mensagem) #pegar os comandos que vão ser passados para o C

                for comando in comandos: #para cada comando a ser executado
                    print(f"Comando passado para o arquivo em c: {comando}")

                    otuput = self.ExecutarComando(comando) #executar o comando
                    cliente.socket.send(f"{otuput}\nEND\n".encode("ascii")) #mandar para o cliente o resultado do comando

                    # time.sleep(2.0) #esperar 2 segundos até executar o próximo comando

            except: #se acontecer algum erro
                cliente.socket.close()
                #terminar a comunicação com o cliente
                break

    def Iniciar(self) -> None:
        """
        Inicia o servidor
        """
        #começa a escutar por conexões
        self.server.listen()

        self.executavel = CompilarPrograma() #compilar o programa C

        while True:
            socket, address = self.server.accept() #aceita novas conexões
            print(f"Conectado com {str(address)}") #Mostrar na tela do servidor que foi conectado ao cliente

            cliente = Client(socket) #criar um novo objeto cliente
            
            # Começar uma thread de comunicação cliente-servidor
            thread = threading.Thread(target=self.ComunicacaoCliente, args=(cliente,))
            thread.start()