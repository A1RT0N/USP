"""
Enzo Tonon Morente - 14568476
Ayrton da Costa Ganem Filho - 14560190
"""

import numpy as np
import networkx as nx

def LerMatriz(V, A):
    flag = False

    # Inicializa uma matriz n x n com zeros
    matriz = np.zeros((V, V), dtype=int)

    for _ in range(A):
        entrada = list(map(float, input().split(" ")))

        Vertice1 = int(entrada[0]); Vertice2 = int(entrada[1])
        Peso = entrada[2]

        matriz[Vertice1 -1][Vertice2 -1] = Peso

        if (Peso < 0):
            flag = True

    return matriz, flag

def EhIrredutivel(matriz):
    grafo = nx.from_numpy_array(matriz, create_using=nx.DiGraph)

    return nx.is_strongly_connected(grafo)


entrada = list(map(float, input().split(" ")))

V = int(entrada[0]); A = int(entrada[1])
 
matriz, flag = LerMatriz(V, A)

S = float(input()) #pegar o valor da transformação de escala

matriz = S * matriz #aplicar a transformação na matriz

if flag or not(EhIrredutivel(matriz)) or (S < 0):
    print("Bixo SemVerTonha")

    exit()

autovalores, autovetores = np.linalg.eig(matriz)

# Encontrar o índice do maior autovalor
indice_maior_autovalor = np.argmax(autovalores)

# Autovetor correspondente ao maior autovalor
autovetor_correspondente = autovetores[:, indice_maior_autovalor]

# Encontrar o índice do vértice com a maior magnitude no autovetor
indice_vertice_dominante = np.argmax(autovetor_correspondente)

print(indice_vertice_dominante + 1) #somar 1, pois está pegando o índice