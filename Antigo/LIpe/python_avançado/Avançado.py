class jojou:
    def __init__(self):
        self.memory = {}
        while True:
            self.puchar_dados()
            d = input("mudar valor(1) // ver (2) // sair (3) --> ")
            
            if d == "1":
                self.mudar()
            elif d == "2":
                self.ver_armazem()
            elif d == "3":
                break
    def mudar(self):
        self.ver_armazem()
        while True:
            name = input("nome do item ---> ")
            if not name in self.memory.keys():
                if input("Este item nao existe, gostaria de criar um novo item? (s) / (n) -> ") == "s":
                    try:
                        qnt = int(input(f"Quantos itens {name} serao adicionados -> "))
                        pr = input(f"Preco do item {name} -> ")
                        self.memory[name] = [pr, qnt]
                        self.salvar()
                        break
                    except ValueError:
                        print("O valor inserido nao e numeral!")
                        continue

            else:
                try:
                    qnt = int(input(f"Nova quantidade do item {name} -> "))
                    self.memory[name][1] = qnt
                    self.salvar()
                    break
                    
                except ValueError:
                    print("O valor inserido n e um numeral!")
                    continue


    def ver_armazem(self):
        for i, e in self.memory.items():
            print(f"O item {i} tem {e[1]} exemplares e custa {e[0]}")
            print("-="*30)


    def salvar(self):
        mudar = open("dados.txt", "w")
        for i, e in self.memory.items():
            mudar.write(f"{i}/{e[0]}/{e[1]}\n")
        mudar.close()
        print("Atualizado!")


    def puchar_dados(self):
        ler = open("dados.txt", "r")
        for e in ler.readlines():
            dados = e.split("\n")[0]
            dados = dados.split("/")
            if len(dados) != 0:
                self.memory[dados[0]] = [dados[1], dados[2]]
        
        

jojou()