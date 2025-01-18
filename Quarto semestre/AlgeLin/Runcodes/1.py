def swap(vetor, i):
    vetor[i+1] = 1
    vetor[i] = 0
    return vetor
        

# dimensoes é a quantidade de elementos por vetor
def base_canonica(dimensoes, numeros_vetores):
    
    matriz = []
    for _ in range(numeros_vetores):
        linha = list(map(int, input().split()))
        matriz.append(linha)
        
    
    vetor_canonico = [0] * dimensoes
    vetor_canonico[0] = 1
        
    
    for i in range(dimensoes):
        flag_loop = False
        for j in range(numeros_vetores):
            if(vetor_canonico == matriz[j]):
                if(vetor_canonico[len(vetor_canonico)-1] == 1):
                    return True
                vetor_canonico = swap(vetor_canonico,i)
                flag_loop = True
                break
        if not flag_loop:
            return False
    
                
                
    
    
d,n = map(int, input().split())

if(base_canonica(d, n) == True):
    print("SimTia")
else:
    print("Não")