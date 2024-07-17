"""
Nome - nUSP dos integrantes:

Ayrton da Costa Ganem Filho - 14560190
Enzo Tonon Morente - 14568476
Letícia Barbosa Neves - 14588659
"""

#funcao auxiliar para verificar se um numero eh primo
def is_prime_aux(x, parametro):
    #verifica se x eh divisivel pelo parametro
    if(parametro>1 and x%parametro == 0):
        return False
    else:
        #se o parametro chegar a 1 e x so for divisivel por 1 e ele mesmo, ele eh primo
        if(parametro == 1):
            return True
        #continua a recursao usando outro valor para o parametro enquanto ele nao chegar a 1
        else:
            return is_prime_aux(x,parametro-1)
        
#funcao para verificar se um numero eh primo
def is_prime(x):
    return is_prime_aux(x, int((x)**(0.5)))

#tendo um x primo, procura o proximo primo
def proximo_primo(x):
    if(is_prime(x+1) == True):
        return x+1
    else:
        return proximo_primo(x+1)

#calcula o maior intervalo entre dois primos consecutivos
def aux_maior_intervalo(inicio, fim, maior_valor): #considera-se que inicio sempre é primo nesse auxiliar

    #quando acabar os primos menores que "fim", retorna a maior distancia
    if(proximo_primo(inicio) > fim):
        return maior_valor
    else:
        #compara a maior distancia atual com a nova distancia calculada e utiliza a maior entre elas
        if(maior_valor < proximo_primo(inicio) - inicio):
            return aux_maior_intervalo(proximo_primo(inicio), fim, proximo_primo(inicio) - inicio)
        else:
            return aux_maior_intervalo(proximo_primo(inicio), fim, maior_valor)
            
#calcula o maior intervalo entre dois primos consecutivos
def maior_intervalo(inicio, fim):
    if(is_prime(inicio)):
        print(aux_maior_intervalo(inicio, fim, 0)) #se nao existir primos entre inicio e fim, ira imprimir 0
    else:
        print(aux_maior_intervalo(proximo_primo(inicio), fim, 0)) #imprime a maior distancia
    
    
inicio = int(input())
fim = int(input())

maior_intervalo(inicio,fim)
    