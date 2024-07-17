import numpy as np

# Definindo uma matriz de exemplo x (features) e vetor y (labels)
# Estes são apenas exemplos e devem ser substituídos por seus dados reais
# x.shape deverá ser (número_de_features, número_de_exemplos)
x = np.array([[0.1, 0.2, 0.3],
              [0.4, 0.5, 0.6]])

# y.shape deverá ser (1, número_de_exemplos)
y = np.array([[1, 0, 1]])

# Inicialização de parâmetros
m = x.shape[1]
w = np.random.randn(x.shape[0], 1)
b = 0

# Taxa de aprendizado
alpha = 0.01

# Propagação para frente
z = np.dot(w.T, x) + b
a = 1 / (1 + np.exp(-z))

# Custo
J = (-1 / m) * np.sum(y * np.log(a) + (1 - y) * np.log(1 - a))

# Propagação para trás
dz = a - y
dw = (1 / m) * np.dot(x, dz.T)
db = (1 / m) * np.sum(dz)

# Atualização dos parâmetros
w = w - alpha * dw
b = b - alpha * db

# Exibindo os resultados da atualização
print("Custo após a propagação:", J)
print("Pesos atualizados (w):", w)
print("Bias atualizado (b):", b)
