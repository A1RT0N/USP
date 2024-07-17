from threading import Thread
from time import sleep as pausa, time

def função_legal(tempo=(float)):
    while True:
        pausa(tempo)
        print("Oi")
        if ord("s"):
            print("Você é genial!")
            break


pergunta = float(input("Qual o tempo?\n--->"))

# args = argumento em array - vários parâmetros - tem que colocar vírgula porque é mais de um parâmetro
Thread(target=função_legal, args=[pergunta, ]).start()

#o .join delimita até onde o thread vai (impede uma thread)

while True:
    print("Bye")
    pausa(2)
# Duas coisas funcionam ao mesmo tempo, podendo fazer interações