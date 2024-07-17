# Calcule o valor da seguinte soma:

# X = (1+2)/1 + (2+2)/2 + (3+2)/3 + (4+2)/4 + (5+2)/5 + ... + (296+2)/296

# A) Estrutura de repetição (for/while) B) Somente listas C) Somente input e output
# Resposta: letra A
resultado = 0

for numero in range(1,297):
    resultado += (numero+2)/numero
    
print(resultado)
