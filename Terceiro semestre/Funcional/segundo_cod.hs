-- fat n
--     n==0 = 1
--     otherwise = n * (fat(n-1))


-- sinal n 
--     n< 0 = -1
--     n ==0 = 0
--     otherwise = 1

main :: IO()

main = do
    l <- getLine
    let x :: Integer
        x = read l
    let f = fat x
    let str = show f
    putStrLn str

fat :: Integer -> Integer

fat n
    | n == 0 = 1
    | otherwise = n * (fat(n-1))


sinal :: Integer -> Integer

sinal x
    |   x< 0 = -1
    |   x == 0 = 0
    |   otherwise = 1

sinal2 x = if x<0
        then -1
        else if x == 0
            then 0
            else 1

tempo :: Integer -> String

tempo t 
    |   t < 0 = "Congelante"
    |   t < 15 = "Ok"
    |   t < 25 = "Agradável"    
    |   t < 35 = "Quente"
    |   t < 45 = "Derretendo"
    |   otherwise = "Já era"

-- TROCAR A ORDEM DISSO DÁ PROBLEMA (exemplo, colocar otherwise de primeira - > otherwise é sempre True)

-- Observação: Integer != int (Integer consegue calcular o fatorial de 100.000, int pode estourar)

baskara :: Float -> Float -> Float - > [Float]
baskara a b c 
    |   delta > 0 = [(-b + sqrdelta), (-b - sqrdelta)/(2*a)]
    |   delta == 0 = [(-b)/(2*a)]
    |   otherwise = []
    where  
        delta = b**2 - 4*a*c
        sqrdelta = delta ** 0.5



bmi :: Float -> Float -> String

-- Guarda:

bmi h w
    |   b < 20 = "Abaixo"
    |   b < 30 = "Normal"
    |   b < 35 = "Sobrepeso"
    |   b < 40 = "Obeso 1"
    |   otherwise = "Muito obeso"
    where
        b = w/(h*h)


-- Haskell é uma linguagem baseada em casamento de padrão: posso definir cláusulas específicas do padrão

-- Fatorial de haskell usando padrão

fat :: Integer -> Integer
fat 0 = 1
fat n = n*(fat(n-1))

-- Só consigo usar casamento de padrão em guarda se


-- Código para calcular a soma de uma lista

soma :: [Integer] -> Integer
soma [] = 0
soma (x:xs) = x + (soma xs)


somapares :: [Integer] -> [Integer]
somapares [] = []
somapares [x] = [x]
somapares (x1:x2:xs) = (x1+x2): (somapares xs)

saltapares :: [Integer] -> [Integer]
saltapares [] = []
saltapares [x] = [x]
saltapares (x1: _: xs) = x1(somapares xs)
saltapares _ =  -- Otherwise -> comportamento exepcional