import os
import shutil #biblioteca para criar o novo arquivo de dados

class Client():
    def __init__(self, socket) -> None:
        self.socket = socket

        self.path = "dadosCliente" #path da pasta referente a este cliente

        shutil.copytree(os.path.join(os.getcwd(), "dados"), "dadosCliente", dirs_exist_ok=True) #criar uma nova pasta chamda dadosid
        #mesmo que a pasta já exista ele copia os arquivos da pasta dados para a nova pasta

    def RepassarProC(self, mensagem) -> str:
        """
        Nessa função dado o input do cliente ele retorna os comandos que devem ser executados no arquivo .c

        CirarBin,arquivo.csv = criar o arquivo binário através do csv
        PrintarBin = printar todos os registros contido no binario
        AlterarDado,id,idade,nomeJogador,nacionalidade,nomeClube = vai remover o cara a ser alterado e depois reinserir com os novos dados
        Busca,id,idade,nomeJogador,nacionalidade,nomeClube = vai fazer uma busca aonde será utilizado os campos que não sejam nulos
        Remover,id = remove o jogador que contem este id
        """

        MensagemSplitada = mensagem.split(",") #fazer o split da mensagem recebida

        if (MensagemSplitada[0] == 'CriarBin'): #criar o arquivo binário através do csv
            #executar a funcionalidade 1 passando o arquivo csv escolhido
            return ["1" + " " + os.path.join(self.path, MensagemSplitada[1]) + " " + os.path.join(self.path, "binario.bin")]
        
        if (MensagemSplitada[0] == 'PrintarBin'): #printar todos os registros
            #executar a funcionalidade 2
            return ["2" + " " + os.path.join(self.path, "binario.bin")]
        
        if (MensagemSplitada[0] == "AlterarDado"):
            #executar a funcionalidade 5 passando como parametro o ID do jogador para remover ele
            #executar a funcionalidade 6 para inserir o registro com os novos dados passados
        
            return ["5" + " " + os.path.join(self.path, "binario.bin") + " " + os.path.join(self.path, "indice.bin") + " 1\n" 
                    + "1 id" + " " + MensagemSplitada[1],
                    "6" + " " + os.path.join(self.path, "binario.bin") + " " + os.path.join(self.path, "indice.bin") + " 1\n"
                    + MensagemSplitada[1] + " " + MensagemSplitada[2] + " \"" + MensagemSplitada[3] + "\" \"" + MensagemSplitada[4] + "\" \"" + MensagemSplitada[5] + "\""] 
        
        if (MensagemSplitada[0] == "Remover"): #remover o registro do jogador passado
            #executar a funcionalidade 5 passando como parametro o ID do jogador para remover ele
            return ["5" + " " + os.path.join(self.path, "binario.bin") + " " + os.path.join(self.path, "indice.bin") + " 1\n" 
                    + "1 id" + " " + MensagemSplitada[1]]
        
        if (MensagemSplitada[0] == "Busca"): #vai fazer uma busca referente aos jogadores que tiverem as especificações passadas
            print(MensagemSplitada)

            comando = "3" + " " + os.path.join(self.path, "binario.bin") + " 1\n" 

            contador = 0 #contador para saber quantos campos não nulos vai ter na busca

            for i in range(1, 6):
                if MensagemSplitada[i] != "nulo":
                    contador += 1 

            comando += str(contador) + " "

            if MensagemSplitada[1] != "nulo":
                comando += "id" + " " + MensagemSplitada[1]

            if MensagemSplitada[2] != "nulo":
                comando += "idade" + " " + MensagemSplitada[2]

            if MensagemSplitada[3] != "nulo":
                comando += "nomeJogador" + " \"" + MensagemSplitada[3] + "\""

            if MensagemSplitada[4] != "nulo":
                comando += "nacionalidade" + " \"" + MensagemSplitada[4] + "\""

            if MensagemSplitada[5] != "nulo":
                comando += "nomeClube" + " \"" + MensagemSplitada[5] + "\""

            return [comando]