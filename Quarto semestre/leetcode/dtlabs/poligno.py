import math 

# Melhoras: podia usar Numpy

# Passo 2: Calcular os ângulos (polares) para cada ponto em relação ao centro (0,0)
    
def calculador_angulo_polar(ponto, centro_x, centro_y):
    x, y = ponto[0] - centro_x, ponto[1] - centro_y
    
    return math.atan2(y,x)
    

def ordenar_pontos(pontos):

    # Passo 1: Transladar os pontos para a origem, fazendo a média dos pontos.

    centro_x = sum(p[0] for p in pontos)/len(pontos)
    centro_y = sum(p[1] for p in pontos)/len(pontos)
    
    pontos_transladados = [(p[0] - centro_x, p[1] - centro_y) for p in pontos]
    
    # Passo 3: Ordenar os pontos no sentido horário 
    
    pontos_ordenados = sorted(pontos, key = lambda p: -calculador_angulo_polar(p, centro_x=centro_x, centro_y=centro_y))
    
    return pontos_ordenados


pontos = [(1, 0), (0, 1), (0, 0), (1, 1)]

pontos_ordenados = ordenar_pontos(pontos=pontos)
print("Pontos ordenados no sentido horário: ", pontos_ordenados)

