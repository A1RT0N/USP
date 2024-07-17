
# len() -> *tamanho* de uma palavra (quantos caracteres tem em uma palavra) de uma variável
while True: # Vai fazer um repetição infinito até achar o retorno break
    senha = input("Qual é sua senha, meu amor:")
    if len(senha) < 6:# Mostra quantos caracteres tem em uma palavra
        print(f"Ô linda, em {senha} tem {len(senha)} caracteres") # Quando você quer printar (imprimir) algo que
        # o usuário digitou junto com uma frase, você tem que usar o f antes das aspas -- f "frase {variável}"
        continue     # "Vá para o início do while"
    elif len(senha) > 16:
        print(f"Nome grande não meu amor, tire {len(senha) - 16} caracteres")
        continue
    elif "!" in senha or "@" in senha or "." in senha:
        print("Não use caracteres especiais, meu amor!")
        continue
    else:
        print("Tudo certo, gatinha !")
    break
# continue (continuar) e break (parar)são comandos (de retorno) que você usa para parar ou continuar um
# loop (repetição)


# Condição simplificada (boa quando você está muiiittoooo apertado com o quesito linha):

tempo = float(input("Quantos anos seu carro tem?\n--->"))
print("Seu carro está novinho" if tempo <= 3 else "Seu carro tá todo bagaçado, piranha")
a = sorted("amor") # separa uma palavra em uma lista de letras/numeros
print(a)
b = "".join(a) # contrário do sorted, junta uma *lista* de letras/numeros em uma palavra -- junta lista em palavra
print(b)





##################################################################################################################

for i in range(0,100):
    if i<=30:
        continue
    print(i)
    if i == 50:
        break # sai do for (loop)
        print("Não vai imprimir")

# O CÓDIGO RODA SEMPRE DE CIMA PRA BAIXO, EXCETO QUANDO TEM UMA REPETIÇÃO (FOR, WHILE, ETC)
