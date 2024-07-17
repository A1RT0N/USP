entrada_1_int = int(input()) # converte a entrada 1 e 2 para binario
entrada_2_int = int(input())

xorzinho = bin(entrada_1_int ^ entrada_2_int)[2:]

print(xorzinho.count('1'))