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

# eu acho que aqui a gente só faz 2 condições mesmo para poder realmente generalizar as condições, para que eu possa
# pegar um parâmetro qualquer e colocar uma ordem
def qs(a, pp, test):
    if len(a) <= 1:
        return a
    else:
        pivot = pp(a)
        return (
           qs(select(a, lambda x : test(x, pivot)), lambda x : cabeca(x), test) + 
           select(a, lambda x : x == pivot) + # faz isso para não complicar o caso base, pois teríamos um monte de itens iguais que ficam de fora, e isso seria chato
           qs(select(a, lambda x : not(test(x, pivot)) and x != pivot), lambda x : cabeca(x), test)
        )



print(qs([1,5,4,2,5,7,1,4,67,2,2345,1,3,512,5,12,643,54,564], lambda x : cabeca(x), lambda x,y : x < y))
print(qs([1,5,4,2,5,7,1,4,67,2,2345,1,3,512,5,12,643,54,564], lambda x : cabeca(x), lambda x,y : x > y))