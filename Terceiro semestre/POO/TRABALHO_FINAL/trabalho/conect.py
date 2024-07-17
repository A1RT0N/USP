import socket
import threading

class Conect:
    def __init__(self) -> None:
        # Create a socket for the client
        self.client = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

        # Connect the client to the server
        self.client.connect(('127.0.0.1', 55555))

         # Create and start a thread for receiving messages
        receive_thread = threading.Thread(target=self.receive)
        receive_thread.start()

        # Create and start a thread for sending messages
        write_thread = threading.Thread(target=self.write)
        write_thread.start()

    # Function to receive messages from the server
    def receive(self):
        while True:
            try:
                # Receive a message from the server
                message = self.client.recv(1024).decode("ascii")

                print(message)
            except:
                # If an error occurs, print an error message and close the client
                print("An error occurred!")
                self.client.close()
                break

        # Function to send messages to the server
    def write(self):
        while True:
            # Read a message from the user input and send it to the server
            message = input("")
            self.client.send(message.encode("ascii"))

NovaConexao = Conect() #fazer a conexao