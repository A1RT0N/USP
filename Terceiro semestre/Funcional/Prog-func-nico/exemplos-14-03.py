import math

def bhaskara(a,b,c):
    delta = b*b - 4*a*c
    if delta < 0:
        return []
    elif delta == 0:
        return [-b/(2*a)]
    else:
        sqrtDelta = math.sqrt(delta)
        x1 = (-b + sqrtDelta)/(2*a)
        x2 = (-b - sqrtDelta)/(2*a)
        return [x1, x2]

def somade1aten(n):
    i = 1
    s = 0
    while i <= n:
        s += i
        i += 1
    return s

def soma_de_1_ate_n_call(n):
    return soma_de_1_ate_n_rec(1, n)

def soma_de_1_ate_n_rec(a, n):
    if a > n:
        return 0
    else:
        return a + soma_de_1_ate_n_rec(a+1, n)

f = soma_de_1_ate_n_call
print(f)