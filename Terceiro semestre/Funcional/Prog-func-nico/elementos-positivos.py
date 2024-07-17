def cabeca(a):
	return a[0]
def cauda(a):
	return a[1:]

# Função para selecionar todos os elementos positivos da cauda
def select(a, test):
    if len(a) == 0:
        return []
    else:
        m = select(cauda(a), test)
        c = cabeca(a)
        if test(c):
            return [c]+m
        else:
            return m


print(select([4,-1,-2,5,-1,-8-10,9,7], lambda x : x % 2 == 0))