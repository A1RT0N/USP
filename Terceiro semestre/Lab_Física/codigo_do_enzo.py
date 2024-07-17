import math

n = int(input("Qtd: "))

sum:float = 0

valores:list[float| int] = []

for i in range(n):
    valores.append(float(input().replace(",", ".")))
print()
media:float = 0

for valor in valores:
    media += valor

media = media / n


for i in range(n):
    sum += math.pow(valores[i] - media, 2)

sum = math.sqrt(sum / (n - 1))

print("Desvio Padrão: ", sum)

print("Média: ",media)