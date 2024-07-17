# Classe -> subscript dentro do subscript

# variáveis (dentro de uma classe) X atributos (self) -> dá pra acessar de qualquer lugar da classe

from string import ascii_lowercase as alfabeto
from random import choice
from random import randint

# Refazendo atividade do Marcos

class Conta:
    def __init__(self):
        self.data = dict()
        while True:
            qr = input("Logar (1) // Regristrar (2)\n--->")
            if qr == "1":
                self.logar()
                break
            else:
                self.registrar()
                break
    def registrar(self):
        while True:
            name = input("Insira o nome do usuário\n --->")
            if not name in self.data.keys() and name.isalpha():
                senha = input("Insira a senha do usuário\n--->")
                if senha.isalpha() and len(senha) > 5:
                    idd = self._gerador_id()
                    dinheiro = input(f"Insira o valor monetário\n--->")
                    try:
                        float(dinheiro)
                    except ValueError:
                        print("O valor inserido não é inteiro!")
                        continue
                    self.data[name] = [senha, idd, dinheiro]
                    self._atualizar_banco()
                    break
                else:
                    print("Senhas devem conter somente letras e devem ter mais que 5 caracteres!")
    def logar(self):
        name = input("Nome do usuário\n--->")
        global senha
        senha = input("Senha do usuário\n--->")
        if name in self.data.keys():
            if senha == self.data[name][0]:
                print("Você entrou em sua conta!")
                print(f"Informações:\nId = {self.data[name][1]}\nDinheiro:{self.data[name][2]}")
    def _atualizar_banco(self):
        edit = open("contas.txt", "w")
        for key, values in self.data.items():
            juntando = "//".join(values)
            edit.write(f"{key}//{juntando}\n")
            edit.close()
    def _gerador_id(self):
        arquivo = open("contas.txt", "r+")
        contador = arquivo.read().split("\n")
        for elemento in contador:
            data = elemento.split("//")
            self.data[data[0]] = [data[1], data[2], int(data[3])]

Conta()


## HERANÇA:
class Classe1:
    def __init__(self):
        self.a = 123123

class Tempo2(Classe1):
    def __init__(self):
        super().__init__()
        self.a += 1
        print(self.a)

Tempo2()