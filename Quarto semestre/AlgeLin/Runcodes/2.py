# A primeira linha contem um inteiro d (1 ≤ d ≤ 100), que e a dimensao do espaço.
# As proximas d linhas descrevem a base B1, onde cada linha contem d numeros reais b1i1, b1i2, . . . , b1id,
# que correspondem aos vetores da base B1.
# As proximas d linhas descrevem a base B2, onde cada linha contem d numeros reais b2i1, b2i2, . . . , b2id,
# que correspondem aos vetores da base B2.
# A ultima linha contem d numeros reais v1, v2, . . . , vd, que sao as coordenadas do vetor v na base B1.
# Saida
# Imprima d numeros reais correspondendo a representacao do vetor v na base B2, com precisao de ate 6
# casas decimais.
    
# []b2 = M (B2->B1) . []b1    
# def matriz_mudanca_base(B1,B2):
    
#     # 
    
#     (1,0) = a1(0,1) + b1(1,0)
#     (0,1) = a2(1,0) + b2(0,1)
    
#     a1.0 + b1.1 = 1             (a1   b1        (0  1    =      ( 1  0
#                                  a2   b2 )       1   0)B2          0   1)B1 
#     a1.1 + b1.0 = 0
    
#     a2.1 + b2.0 = 0
#     a2.0 + b2.1 = 1
    
    
    
    
    

import numpy as np

d = int(input())

B1 = list()
B2 = list()

for _ in range(d):
    B1.append(tuple(map(float, input().split(' '))))

for _ in range(d):
    B2.append(tuple(map(float, input().split(' '))))

B1 = np.array(B1)
B2 = np.array(B2)

v_b1 = np.array(list(map(float, input().split(' '))))   

v_b1 = v_b1.T

B1_inv = np.linalg.inv(B1)
    
v_canonical = B1_inv.dot(v_b1)
    
v_b2 = B2.dot(v_canonical)


for i in range(d):
    print(f"{v_b2[i]:.4f}", end=" ")




    
