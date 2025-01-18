import numpy as np

d = int(input())

B1 = list()

for _ in range(d):
    B1.append(tuple(map(float, input().split(' '))))

B1 = np.array(B1)

if(np.linalg.det(B1) == 0):
    print("Não")
else:
    print("SimTia, o Retorno")
