# Primeira aula de Python
# Python - linguagem de alto nível - a gente entende melhor
# 01) Entrada e saída  02) Variáveis  03) Condicionais (if else) 04) Loops (while e o for)
# 05) Listas e manipulação

# 01) Entrada e saída 02) Variáveis 
# 01.1) Entrada/input - padrão (teclado)
# Variável - tudo aquilo que você consegue armazenar no computador e consegue ser mudado.
# int significa inteiro
x = int(input("Digite algum número:")) 
# O usuário vai digitar um número inteiro e esse resultado vai ser armazenado na variável x
# IMPORTANTE: Esse símbolo "=" NÃO significa igual. Em ciência da computação, esse símbolo, para
# a maioria das linguagens significa ATRIBUIÇÃO
raissa = "amor" 
p = "p"
y = x-5
amor = input("Olá, escreva seu nome: ")

# Curiosidade: em outras linguages, como C e C++, para declarar uma constante é só escreve const
# atrás da variável

# variavel =(atribui) operação

# 01.2) Saída/Impressão/Print - quando o computador de devolve um resultado processado 
print("O resultado de y =", y, "\nObrigado!")
print(amor,"ganhou um ponto na média =)\n")


# Adendo: operações aritméticas em programação

# Soma: +; Subtração: -; Multiplicação: *; Divisão (inteira): //; Divisão (inexata): /
# Resto da divisão inteira: %

numero = 123231456%2   # voce sabe que um numero par é par se ele for divisível por 2 - numero / 2 -> resto = 0

y = x*20/3  

print("O resultado de y =", y, "\nObrigado!") # Imprime a última atribuição feita com a variável y

# As aspas servem pra você delimitar uma frase. Quando não tem aspas, você imprime uma variável ou
# constante
# Os parênteses servem para delimitar funções: print(alguma_coisa), input(alguma_coisa), ...
# A vírgula serve para, dentro das aspas do print, separar uma frase de uma variável


# 5%2 = 1
# 5 | 2
# -4  2 -> quociente
# 1 -> resto

numero = 123231456%2 
# Parabéns, você acabou de descobrir seu primeiro algoritmo! O que é algoritmo: sequência de passos/códigos
# para resolver um determinado problema.
# Se o resto da divisão (%) for 0, significa que o número é par. Se for 1, significa que ele é ímpar

# 03) Condicionais

# Se, em inglês: if, é uma condicional que a gente usa para analisar um determinado dado

# Se o resto da divisão (%) for 0, significa que o número é par. Se for 1, significa que ele é ímpar

if (y%2 == 1): # "==" símbolo que compara os dois lados e determina se são equivalente ou não - entendemos ele por igual
    print("O y é ímpar")
else: # else, em inglês, significa senão
    print("O y é par")
    

# Comparadores: 
# ==: compara se duas operações/valores são iguais; >: compara se o lado esquerdo é maior que o direito;
# <: compara se o lado direito é maior que o esquerdo:
# >=: compara se o lado esquerda é maior ouuuu igual ao lado direito
# <=: compara se o lado direito é maior ouuu igual ao ado esquedo

# Operadores:
# and (e): se duas ou mais operações são verdadeiras
# or (ou):se ao menos uma operação é verdadeira

if (y>5 and y%2==0):
    print("SIM")
else:
    print("NÃO")


