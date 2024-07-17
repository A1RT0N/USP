# Estrutução: while e for

# No for, a gente precisa criar duas coisas: um intervalo() e uma variável que vai aumentar de valor conforme o intervalo

for numero in range(0,101): # range(100) == range(0,101)
    if(numero%2 == 0):
        print(numero) # Numero par que está situado no intervalo de 0 a 100


# ## O CÓDIGO DE CIMA É TOTALMENTE DIFERENTE DO DE BAIXO
# # ADENDO:
# numerozinho = 200
# for ignora in range(200): # range(200) é a mesma coisa que range(0,201)
#     numerozinho+=1
# # numerozinho vai ser 400, porque ele começa com zero e soma-se 1 a numerozinho 200 vezes


