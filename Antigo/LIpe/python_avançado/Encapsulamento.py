class pato:
    def _init_ (self, tora_de_madeira):
        self._pato = tora_de_madeira
    
    @property
    def _pato(self): # getter
          return self.resposta
    
    @_pato.setter
    def _pato(self, madeira):
        if madeira > 0:
               self.resposta = madeira
        else:
               self.resposta = 0

# Lembra que o primeiro self.pato é uma criança que ganhou uma tora de madeira, 
# dps de ganhar uma tora de madeira o getter (a função com o property) que na histórinha é o pai, 
# pegou a tora de madeira antes de chegar na mão do filho e deu essa tora pra função setter, 
# para ela manipular o valor da tora de madeira e retorna um dado polido e seguro


    