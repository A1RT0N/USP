#!/bin/python3

import math
import os
import random
import re
import sys
from collections import deque

#
# Complete the 'quickestWayUp' function below.
#
# The function is expected to return an INTEGER.
# The function accepts following parameters:
#  1. 2D_INTEGER_ARRAY ladders
#  2. 2D_INTEGER_ARRAY snakes
#

def quickestWayUp(ladders, snakes):
    # Cria um dicionário para mapear escadas e cobras
    board = {i: i for i in range(1, 101)}
    for start, end in ladders:
        board[start] = end
    for start, end in snakes:
        board[start] = end

    # Inicializa a fila para o BFS (posição inicial e número de jogadas)
    queue = deque([(1, 0)])
    visited = set()

    while queue:
        current, moves = queue.popleft()

        # Se alcançamos a casa 100, retornamos o número de jogadas
        if current == 100:
            return moves

        # Tenta mover de 1 a 6 casas à frente
        for i in range(1, 7):
            next_square = current + i
            if next_square <= 100 and next_square not in visited:
                visited.add(next_square)
                queue.append((board[next_square], moves + 1))

    # Se não for possível alcançar a casa 100, retorna -1
    return -1

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    t = int(input().strip())

    for t_itr in range(t):
        n = int(input().strip())

        ladders = []

        for _ in range(n):
            ladders.append(list(map(int, input().rstrip().split())))

        m = int(input().strip())

        snakes = []

        for _ in range(m):
            snakes.append(list(map(int, input().rstrip().split())))

        result = quickestWayUp(ladders, snakes)

        fptr.write(str(result) + '\n')

    fptr.close()

