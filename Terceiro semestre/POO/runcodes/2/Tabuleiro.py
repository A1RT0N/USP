class Tabuleiro():
    
    def __init__(self,  tamanho_matriz, matriz_dada) -> None:
        
        self.tamanho_matriz = tamanho_matriz   # Toda mudança em matriz vai acontecer em matriz_dada e vice-versa
        self.matriz = matriz_dada
        self.lista_posicao_vazia = list()
        for i in range(tamanho_matriz):
            for j in range(tamanho_matriz):
                if(self.matriz[i][j] == 0):
                    self.lista_posicao_vazia.append(i)
                    self.lista_posicao_vazia.append(j)
                    return
                
    
    def print_matriz(self):
        for p in range(self.tamanho_matriz):
            print("+------", end='')
            
        print("+", end='')
        
        for i in range(self.tamanho_matriz):
            print("")
            
            for j in range(self.tamanho_matriz):
                if self.matriz[i][j] == 0:
                    print("|      ", end='')
                else:
                    # Usa formatação de strings para garantir que outros números ocupem dois espaços, com espaço extra à esquerda se necessário
                    print(f"|  {self.matriz[i][j]: >2}  ", end='')

        
            print("|")
            
            for p in range(self.tamanho_matriz):
                print("+------", end='')
                
            print("+", end='')
        
        print("")
        
        
    def swap(self, linha1, coluna1, linha2, coluna2):
        self.matriz[linha1][coluna1], self.matriz[linha2][coluna2] = self.matriz[linha2][coluna2], self.matriz[linha1][coluna1]
    
    
    def up(self):
        if(self.lista_posicao_vazia[0]+1 >= self.tamanho_matriz):
            return
        self.swap(self.lista_posicao_vazia[0], self.lista_posicao_vazia[1], self.lista_posicao_vazia[0]+1, self.lista_posicao_vazia[1])

        self.lista_posicao_vazia[0] += 1
        

    def down(self):
        if(self.lista_posicao_vazia[0]-1 < 0 ):
            return
        
        self.swap(self.lista_posicao_vazia[0], self.lista_posicao_vazia[1], self.lista_posicao_vazia[0]-1, self.lista_posicao_vazia[1])

        self.lista_posicao_vazia[0] -= 1
        

    def left(self):
        if(self.lista_posicao_vazia[1]+1 >= self.tamanho_matriz):
            return
        
        self.swap(self.lista_posicao_vazia[0], self.lista_posicao_vazia[1], self.lista_posicao_vazia[0], self.lista_posicao_vazia[1]+1)
        self.lista_posicao_vazia[1] += 1
        
    

    def right(self):

        if(self.lista_posicao_vazia[1]-1 < 0 ):
            return
        

        self.swap(self.lista_posicao_vazia[0], self.lista_posicao_vazia[1], self.lista_posicao_vazia[0], self.lista_posicao_vazia[1]-1)

        self.lista_posicao_vazia[1] -= 1
        
    
    def end_game(self):
        k = 0
        for i in range(self.tamanho_matriz):
            for j in range(self.tamanho_matriz):
                if(self.matriz[i][j] != k):
                    return False
                
                k+=1
        
        return True
                
    