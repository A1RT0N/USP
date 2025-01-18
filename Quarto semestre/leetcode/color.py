def soma_string(string):
    acumulador = 1
    for char in string:
        num = int(char)
        acumulador = acumulador*num
    return acumulador


# Função que retorna se o uma subsequência de um número é única 

def is_color(number):
    string = str(number)
    tamanho = len(string)
    lista = list()
    
    for i in range(1, tamanho+1):
        inicio = 0
        fim = i
        while True:
            if(fim > tamanho):
                break
            slice_ = string[inicio:fim]
            lista.append(slice_)
            inicio += 1
            fim += 1
            
    lista_soma = list(map(soma_string, lista))
    tamanho_lista = len(lista_soma)
    conjunto = set(lista_soma)
    if (len(conjunto) == tamanho_lista):
        return True
    else:
        return False
    
        

            
print(is_color(int(input)))
            
            
    
        