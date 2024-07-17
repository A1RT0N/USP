def fatorial(x):  # função que dado um inteiro x, retorna x!
    if(x == 0):
        return 1
    else:
        return x*fatorial(x-1)


N = int(input())

lista_de_n = list()

for _ in range(N):
    lista_de_n.append(int(input()))

contador = 0

for i in range(N):
    contador += fatorial(lista_de_n[i])
    
print(contador)