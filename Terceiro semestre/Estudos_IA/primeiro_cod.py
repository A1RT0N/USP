import numpy as np
import math 
import random

# IA para determinar se você é gay ou não é:

# Dado dois inputs x1 e x2 para m exemplos, queremos determinar os pesos w1, w2 e b (não agr o b) para achar ŷ (que busca prever y)
# Mas quem é y? Y é um valor ou zero ou um que nosso modelo quer prever. Já ŷ é a previsão do nosso modelo
# Z[i] = x1[i].w1[i] + x2[i].w2[i] + b. Quanto maior z[i], mais ŷ fica próximo de 1 (é gay). O contrário se aproxima de 0 (não é gay).

def sigmoid(z): # Função para funções logísticas de regressão (funções binárias com dois possíveis resultados: 0 (homem), 1 (gay))
    return 1 / (1 + np.exp(-z))

# Inicialização

j = 0 # Essa é a função MÉDIA de loss que é composta por diversas funções escondidas (layers de neurônios).
# J= 1/m ​∑i=1,m [​L(a(i),y(i))]
dw1 = 0
dw2 = 0
db = 0
b = 0

w1 = random.random(0,5)
w2 = random.random(0,5)

m = int(input("Quantidade de modelos: "))

taxa_de_aprendizagem = float(input("Taxa de aprendizagem: "))

x = list()

y = np.random.randint(2, size=m) # Cria matriz de resultado de m elementos com valores ou 0 ou 1 qu

for i in range(m):
    x.append(int(input("X(i): ")))

z = np.zeros(m)
a = np.zeros(m)
dz = np.zeros(m)

w = np.random.rand(m) # Lista aleatória

wt = w.T # Gera a transposta de T

for i in range(m):
    
    z[i] = wt[i]*x[i] + b
    a[i] = sigmoid(z[i])
    
    j += -(y[i]*math.log(a[i]) + (1-y[i])*(math.log(1-a[i])))
    
    dz[i] = a[i] - z[i]
    # Aqui poderia ter um for da quantidade de elementos do vetor de características(X(i)). Nesse caso x(i) é uma vetor de 2 elementos
    # Não precisou implementar pq o código é pequeno (quantidade de características - n - é 2) => inclusive é bom se livre do for (vectorization)
    dw1 += x[i][0]*dz[i] # O valor de dw é cumulativo
    dw2 += x[i][1]*dz[i]
    db += dz[i]
    
j /= m; dw1 /= m; dw2 /= m; db /= m

# Atualizando os bias e os pesos

w1 = w1 - taxa_de_aprendizagem*dw1 # w1 -= taxa_de_aprendizagem*dw1
w2 = w2 - taxa_de_aprendizagem*dw2
b = b - taxa_de_aprendizagem*b
    
    
    
    
    
    

# import numpy as np

# def sigmoid(z):
#     return 1 / (1 + np.exp(-z))

# # Inicialização
# m = # número de exemplos
# n = # número de características
# X = np.zeros((m, n)) # substitua por seus dados de entrada (m x n)
# Y = np.zeros(m) # substitua por seus rótulos de saída (m x 1)
# w = np.zeros(n) # pesos iniciais (n x 1)
# b = 0 # viés inicial

# J = 0
# dw = np.zeros(n)
# db = 0

# # Algoritmo
# for i in range(m):
#     # Forward pass
#     z_i = np.dot(w, X[i]) + b
#     a_i = sigmoid(z_i)
    
#     # Cálculo da função de custo (será completado mais tarde)
#     # J += - (Y[i] * np.log(a_i) + (1 - Y[i]) * np.log(1 - a_i)) # descomente esta linha quando for calcular J
    
#     # Backward pass (gradiente)
#     dz_i = a_i - Y[i]
#     dw += X[i] * dz_i
#     db += dz_i

# # Dividindo pelos exemplos para obter a média
# dw /= m
# db /= m
# J /= m

# # Atualize aqui w e b usando dw e db com sua taxa de aprendizagem
# # w = w - learning_rate * dw
# # b = b - learning_rate * db





# Atençao: c = a*b (elemento por elemento) diferente de c = np.dot(a,b) (multiplicação de matrizes que se vê no EM)




# Vectorization: do not use for

# Z = np.dot(w,x) :=
# for i in range(nx): z+= w[i]*x[i]; z+=b (muiiitooo mais demorado)

# u = np.exp(v); log, abs, maximum, v**2,i/v

# Como dividir uma matriz 3x4 por uma 1x4? Ex: 100*A/cal (divide elementos por elemento)

# Broadcasting: copia os elementos da matriz pra fazer a conta na direção vertical ou horizontal

# A.sum(axis = 0) => soma verticalmente

# DO NOT USE RANK 1 ARRAYS: np.random.rand(5); a.shape = (5,) (esse igual é de igualdade e não de atribuição)

# USE: np.random.rand(5,1)



# SHIFT + ENTER executa código no júpiter


# What you need to remember:
# np.exp(x) works for any np.array x and applies the exponential function to every coordinate
# the sigmoid function and its gradient
# image2vector is commonly used in deep learning
# np.reshape is widely used. In the future, you'll see that keeping your matrix/vector dimensions straight will go toward eliminating a lot of bugs.
# numpy has efficient built-in functions
# broadcasting is extremely useful

# Note that np.dot() performs a matrix-matrix or matrix-vector multiplication. This is different from np.multiply() and the * operator (which is equivalent to .* in Matlab/Octave), which performs an element-wise multiplication.

# L1 loss: np.sum(abs(y - yhat))
# L2 loss: np.sum((y-yhat)**2)