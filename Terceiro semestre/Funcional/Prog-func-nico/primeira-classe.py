def cabeca(a):
	return a[0]
def cauda(a):
	return a[1:]

def processavec(a, comb):
	if len(a) == 1:
		return cabeca(a)
	else:
		m = processavec(cauda(a),comb)
		c = cabeca(a)
		return comb(c,m)

def mincomb(a, b):
	return a if a < b else b

def maxcomb(a, b):
	return a if a < b else b

def sumvec(x,y):
    return x+y

def concat2(x,y):
    return str(x)+str(y)

# Função anônima (com lambda), pois eles tratam isso como função sem nome, mas não
# como um objeto (a funcional trata isso como objeto)
print(processavec([9,1,5,4,5,0,2], lambda x,y : x if x < y else y))
print(processavec([9,1,5,4,5,0,2], mincomb))
print(processavec([9,1,5,4,5,0,2], sumvec))
print(processavec([9,1,5,4,5,0,2], concat2))