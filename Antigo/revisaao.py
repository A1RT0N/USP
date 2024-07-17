# Inputs e outputs - inputs são entradas de dados, e outputs são saídas/impressões (prints) desses dado
x = int(input("Escreva um valor para x: \n"))  # Atribui a x o valor (numero, palavra) digitado pelo usuário
# "int" significa que x é necessariamente um inteiro
# Output
print("O valor de x é:", x) # Printar é imprimir sobre a tela do computado
# Operações condicionais (São os 'if' -> 'se')
# Exemplo: Se x for par, imprima x. Senão (else), não imprima x
# Vimos que um número par, em matemática e computação, é represantado quando o resto da divisão do número por
# (x % 2) é 
# Lembrando: "==" verifica se ambos os lados são equivalentes ou não, e o operador "=" faz atribuição do que
# está  no lado direito para o lado esquerd
if (x % 2 == 0):   # Significa: "Se o resto da divisão de x por 2 for zero, faça:"
    print("X é um número par, tal que x vale: ", x)
else: # Senão, faça:
    print("X não é par")  
# Estruturas de repetição
# for (para todo ...), while (enquanto ..
# Exemplo para o uso do for: Quer-se imprimir todos os números até x \(sem contar o próprio x
for numero in range(0,x): # No for a gente sempre tem que criar uma variável que vai iterando, ou seja, aumentando, geralmente em 1, seu valor
# Isso pode ser traduzido como: Para todo número no intervalo (range) de 0 até x (NÃO CONSIDERANDO X)
    print(numero) # Imprimir o número  
# Exemplo de uso do while (é usado quando você não sabe quantas vezes um critério vai se repetir, vc só sabe quando ele para)
# Você quer printar o "eu te amo" ENQUANTO (while) o número for positivo
while(x> 0):
    print("EU te amo\n") # o "\n" serve pra dar um espaço entre as impressões
    x-= 1  # Em python, "-=" reduz um valor a x, "+=" soma um valor a x, "/=" divide um valor a e "*=" multiplica um valor a x  
 # ATÉ AGR, O QUE FOI VISTO É BASE PRA PROGRAMAÇÃO

# Listas (conhecidas como array's ou vetores): são um conjunto de palavras ou números, em que você pode acessar eles através de seus INDEXs

# Mas o que são index? Index é um número que retrata a posição dos elementos na lista, tal que o primeiro elemento
# sempre começa com o index 0 e o último elemento é sempre o tamanho da lista - 1

listinha_de_compras = list()  # Declaração da lista 
listinha_de_compras = []  # A parte de cima e a de baixo são equivalentes (ambas declaram a lista)

# Operações com listas: ***.append(), ** .sort(), *** .pop(), .del(), .join(), .split(), .remove() ... (Só pesquisar no google que ele te mostra todas)

listinha_de_compras.append("Morango") # Essa função vai adicionar a palavra "Morango" ao fim da lista

print(listinha_de_compras)

listinha_de_compras.append("Cachorro") # Essa função vai adicionar a palavra "Morango", na lista

print(listinha_de_compras)

# Como "Cachorro" foi adicionado por último na nossa lista, basta a gente "popar" (dar .pop()) -> deletar o último elemento

listinha_de_compras.pop()

print(listinha_de_compras)

listinha_de_compras.append("Abacaxi")

listinha_de_compras.append("Limão")

listinha_de_compras.append("Uva")

listinha_de_compras.append("Melancia")

print(listinha_de_compras)

# E se eu quiser deletar um elemento numa posição que eu não sei (não necessariamente no final)

listinha_de_compras.remove("Limão")

print(listinha_de_compras)






    