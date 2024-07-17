import math

# Versao iterativa da funcao para achar o maior intervalo entre primos consecutivos
# def find_biggest_interval_prime_loop(a,b):
#     res = 0
#     prime1 = 0
#     for i in range(a,b+1):
#         if is_prime(i, 2):
#             if prime1 > 0:
#                 res = i-prime1 if i-prime1 > res else res
#             prime1 = i
#     return res

def is_prime(a, itr):
    if itr > math.sqrt(a)+1:
        return True
    if a % itr == 0:
        return False
    return is_prime(a,itr+1)

def find_biggest_interval_prime(a,b):
    return find_biggest_interval_prime_aux(a,b,a+1)
    
# A variavel aux guarda o contador do loop, com o proposito de achar o próximo primo de a
def find_biggest_interval_prime_aux(a,b,aux):
    # Caso base
    if aux > b:
        return 0
    if is_prime(a,2):
        if not(is_prime(aux,2)): # Se aux nao for primo, incrementar aux ate que ele seja primo
            return find_biggest_interval_prime_aux(a,b,aux+1)
        else: # Se a e aux forem primos, calcular sua diferenca e a comparar com a proxima diferenca
            res_alt = find_biggest_interval_prime_aux(aux,b,aux+1)
            return aux-a if aux-a > res_alt else res_alt
    else: # Se a nao for primo, aumentar a e seguir com a iteracao
        return find_biggest_interval_prime_aux(a+1,b,a+2)

m = int(input())
n = int(input())

print(find_biggest_interval_prime(m,n))
