# Aula de hoje é continuação de condicionais (if, elif e else) e loops (for e while) com alguns exercícios
# Se der tempo, falaremos de listas 
# O SEU COMPUTADOR ANDA NO CÓDIGO E EXECUTA DE CIMA PARA BAIXO E NÃAAOOOO DE BAIXO PARA CIMA OU SLA
logar = input("Digite: ") # digitou 'Entrar'

# float significa número decimal: 22.52 cm

# O que é elif (boa prática de programção):
# O elif é um if restritivo. O elif e o else estão atrelados ao if. Ou o if ou o elif são processados.
# O if e o elif não podem ocorrer ao mesmo tempo

if(logar == "Entrar"):
    print("bem vindo")
elif(logar == "Entrar"):
    print("Me passe seus dados")
else: #else significa o resto
    print("Adeus")
 
if (logar == "Entrar"):
    print("Seja educado com o facebook")
    
# Loops: for e while. Loop - repitação

# Vamos supor que eu queria imprimir números de 0 a 23

# while = enquanto

#numero = 0

#while (numero <=23):
    #print(numero)
    #numero += 1 # += somar; -= subtrair; /= dividir ...

# for - para todo. in - dentro. range - intervalo. O range não considera o último número do intervalo
# Ainda mais: o range só considera números inteiros e que partem a partir do primeiro número do intervalo

#for numerozinho in range(0,24): #variavel é uma variável SEMPRE INTEIRA declarada dentro do for. A ',' significa até
    #print(numerozinho)

for numero_par in range(0,101):
    if(numero_par%2 == 0):
        print(numero_par)
    
numero = 0

while(numero <=101):
    if(numero%2 == 0):
        print(numero)
        numero+=1