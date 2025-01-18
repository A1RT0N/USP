import numpy as np
from PIL import Image
import matplotlib.pyplot as plt

# Função para reconstruir a imagem usando apenas os k maiores valores singulares
def reconstruct_image(U, singular_values, V, k):
    Uk = U[:, :k]
    Sk = np.diag(singular_values[:k])
    VTk = V[:, :k].T
    return np.dot(Uk, np.dot(Sk, VTk))

# Carregar a imagem e transformar em escala de cinza
image = Image.open("tuc.jpg").convert("L")
gray_matrix = np.array(image)

gray_matrix = np.array(gray_matrix, dtype = np.float64)

ATA = np.dot(gray_matrix.T, gray_matrix)

eigenvalues, V = np.linalg.eigh(ATA)

# Ordenar os autovalores e autovetores em ordem decrescente
sorted_indices = np.argsort(eigenvalues)[::-1]
eigenvalues = eigenvalues[sorted_indices]
V = V[:, sorted_indices]

eigenvalues[eigenvalues < 0] = 0

# 3. Calcular valores singulares (raízes quadradas dos autovalores)
singular_values = np.sqrt(eigenvalues)

# 4. Calcular U usando A * V = U * Σ
U = np.dot(gray_matrix, V) 

U = U / [s if s!=0 else 1 for s in singular_values]

Vt = V.T

# Testar diferentes valores de k para visualização
k_values = [2, 5, 20, 50, 100]  # Valores de k para compressão

plt.figure(figsize=(12, 8))

# Plot da imagem original para comparação
plt.subplot(1, len(k_values) + 1, 1)
plt.imshow(gray_matrix, cmap='gray')
plt.title("Original")
plt.axis("off")

# Reconstruir e plotar as imagens comprimidas para diferentes valores de k
for i, k in enumerate(k_values, 2):
    Xk = np.linalg.multi_dot([U[:, 0:k], np.diag(singular_values[0:k]), Vt[0:k, :]])
    plt.subplot(1, len(k_values) + 1, i)
    plt.imshow(Xk, cmap='gray')
    plt.title(f"k = {k}")
    plt.axis("off")

plt.show()
