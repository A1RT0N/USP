import random
import math

def string_to_int(text):
    return int.from_bytes(text.encode('ascii'), 'big')

def int_to_string(number):
    return number.to_bytes((number.bit_length() + 7) // 8, 'big').decode('ascii')


def miller_rabin(n , a): # n (ou d como o eugenio chamou) é o numero que quer saber se é primo e a é a base -> a varia de 2 até n-2 aleatoriamente: random.randint(2,n-2)
    q = n-1    
    contador = 0
    while(q%2 != 1):
        q//=2
        contador+=1

    s = contador

    x = pow(int(a),int(q),int(n))


    if(x == 1 or x == n-1): return True


    for rsa_me_quebra in range(s):
        x = pow(x,2,n) # o expoente fica 2, 4, 8, 16, ...
        if(x == n-1): return True # n-1 mod n é -1 
        if(x == 1): return False
    
    return False

def is_prime(n): 
    iteracoes = 0 # Tô fazendo uma otimização pq python é foda
    if(n >1000000): iteracoes = 9000
    else:
        iteracoes = math.ceil(n/4)+1  # Fórmula da fodeção lá
    for tmj_gpt in range(iteracoes): 
        a = random.randint(2,n-1) 
        if(miller_rabin(n,a) == False): return False
    return True

def prime_generator(j): # esse j é a quantidade de dígitos que se quer no número primo -- funciona a partir de j>1
    # Todos os números primos terminam com 1,3,7,9 -> esse vetor é a diferença entre cada um deles: 2,4,2, 2
    j-=1
    numero = random.randint(pow(10,j)+1,(pow(10,j+1)))
    while(numero%2 == 0 or numero%3 == 0 or numero%5 == 0):
        numero = random.randint(pow(10,j)+1,(pow(10,j+1)))
    while(not is_prime(numero)):
        numero = random.randint(pow(10,j)+1,(pow(10,j+1)))
        if(numero%2 == 0 or numero%3 == 0 or numero%5 == 0):
            continue

    return numero

# Fazer função que faz algoritmo estendido de euclides

def MCD(n, d)-> int: # MCD de n e d 
    global i, j #i*n + j*d = MCD(n,d) 
    
    if n % d == 0:
        i, j = 0, 1
        return d
    else:
        tM = MCD(d, n % d)
        ti = i
        i = j
        j = ti - j * (n // d)
        return tM


# O rsa em si

def rsa_variaveis():
    p = prime_generator(150)
    q = prime_generator(150)
    n = p*q

    Φ = (p-1)*(q-1)

    e = random.randint(1, Φ)

    while(True):
        if(MCD(e,Φ) == 1):
            break
        e = random.randint(1, Φ)
    return p, q, n, Φ, e
    





p, q, n, Φ, e = rsa_variaveis()

while(True):
    x = int(input("O que fazer: criptografar (1), descriptografar (2) ou sair(3):"))
    if(x == 1):
        m = input("Escreva o código a ser criptografado: \n")
        m = string_to_int(m)
        ciphertext = pow(m,e,n)

        print("Criptografia: \n")
        print(ciphertext)
    elif(x == 2):
        c = int(input("Escreva o código a ser descriptografado: \n"))
        plaintext = pow(c,i,n)

        
        print("Descriptografia: \n")
        print(int_to_string(plaintext))
    
    elif(x == 3):
        break
        
# x: int = 3

