from Tabuleiro import Tabuleiro
                
linhas = input()

# Divide a string em uma lista, usando espaço como separador
conj_numeros = linhas.split(" ")

# Calcula o tamanho da matriz como a raiz quadrada do comprimento da lista
tamanho_da_matriz = int(len(conj_numeros) ** 0.5)

matriz_entrada = [[0 for _ in range(tamanho_da_matriz)] for _ in range(tamanho_da_matriz)]


k = 0
for i in range(tamanho_da_matriz):
    for j in range(tamanho_da_matriz):
        matriz_entrada[i][j] = int(conj_numeros[k])
        k += 1
        
t = Tabuleiro(tamanho_matriz=tamanho_da_matriz, matriz_dada= matriz_entrada)

comando = input()

iteracoes = len(comando)

for i in range(iteracoes):
    t.print_matriz()
    print()
    op = comando[i]
    if op == 'u':
        t.up()
    elif op == 'l':
        t.left()
    elif op == 'r':
        t.right()
    elif op == 'd':
        t.down()
    else:
        print("Comando não encontrado!")
        
t.print_matriz()

print()

print(f"Posicao final: {t.end_game()}", end='')

