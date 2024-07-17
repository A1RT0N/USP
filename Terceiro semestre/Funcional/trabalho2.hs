
-- Nome - nUSP dos integrantes:

-- Ayrton da Costa Ganem Filho - 14560190
-- Enzo Tonon Morente - 14568476
-- Letícia Barbosa Neves - 14588659

-- Função que dado um inteiro, retorna um booleano pra dizer se um número é ou não primo
is_prime :: Int -> Bool
is_prime x = is_prime_aux x (x - 1)

-- Função auxiliar para verificar se o número é primo, que recebe dois inteiros e retorna um booleano
is_prime_aux :: Int -> Int -> Bool
is_prime_aux x parametro
    -- Sendo parâmetro o intervalo de valores de 1 a raiz de x
    -- Verificando se x é divisível pelo parâmetro
    | ((parametro > 1) && (x `mod` parametro == 0)) = False
    -- Se o número for divisível por 1 ou ele mesmo, o número é primo
    | (parametro == 1) = True
    -- Continuando a recursão até que parâmetro (raiz de x) chegue em 1
    | otherwise = is_prime_aux x (parametro - 1)
    
-- Função que dado um inteiro primo, retorna um inteiro que é seu próximo primo
proximo_primo :: Int -> Int
proximo_primo x
    -- Percorre de 1 em 1 e checa se os sucessores de x são primos
    -- Se algum sucessor for primo, retorna ele
    | (is_prime(x + 1) == True) = x + 1
    | otherwise = proximo_primo (x + 1)

-- Função auxiliar que dado um intervalo representado por um inteiro de início que sempre é primo
-- e um inteiro de fim, utilizando um inteiro de comparação que é o maior valor, retorna um inteiro 
-- que é o intervalo entre dois primos consecutivos
aux_maior_intervalo :: Int -> Int -> Int -> Int
aux_maior_intervalo inicio fim maior_valor
    -- Quando o próximo primo ultrapassar o limite, retorna o parâmetro maior_valor
    | ((proximo_primo inicio) > fim) = maior_valor
    -- Calcula a maior distância atual e a nova distancia e retorna a maior delas
    | (maior_valor < ((proximo_primo inicio) - inicio)) = aux_maior_intervalo (proximo_primo inicio) fim ((proximo_primo inicio) - inicio)
    | otherwise = aux_maior_intervalo (proximo_primo inicio) fim maior_valor
    
-- Função principal que calcula o maior intervalo entre dois primos consecutivos
maior_intervalo :: Int -> Int -> Int
maior_intervalo inicio fim
    -- Se não existir primos entre início e fim, retorna-se zero
    | (is_prime inicio == True) = aux_maior_intervalo inicio fim 0
    -- Retorna a quantidade de primos no intervalo, considerando o próximo primo de início (que pode ser ele mesmo)
    | otherwise = aux_maior_intervalo (proximo_primo inicio) fim 0

-- Main (função impura de entrada e saída) que vai imprimir os resultados
main:: IO()
main = do
    -- Lê a string passado pelo usuário
    x_string <- getLine
    -- Usa variáveis dentro de funções impuras
    -- Lê a entrada de início
    let x = read x_string :: Int
    -- Lê o fim do programa
    y_string <- getLine
    let y = read y_string :: Int
    
    let resultado = maior_intervalo x y
    -- Mostra o resultado na tela
    let str = show resultado
    putStrLn str
    
    
