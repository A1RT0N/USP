-- Código de fatorial

fat :: Integer -> Integer

{- Funciona, mas não do jeito "haskell"
fat n = if n == 0
        then 1
        else n*(fat (n-1))
-}

{- Definição do jeitinho haskell, bonitinho, mas ainda não é o jeito certo
fat n
    | n == 0 = 1
    | otherwise = n*fat (n-1) --otherwise não é uma palavra reservada, é uma constante que representa true
-}

fat 0 = 1
fat n = n*(fat (n-1))

sign :: Integer -> Integer
sign x
   | x < 0 = -1
   | x == 0 = 0
   | otherwise = 1

sinal2 x = if x < 0
           then -1
           else if x == 0
               then 1 
               else 0

sinal3 0 = 0
sinal3 x
    | x < 0 = -1
    | otherwise = 1

tempo :: Integer -> String
tempo t
    | t < 0 = "Congelante"
    | t < 15 = "Ok"
    | t < 25 = "Agradavel"
    | t < 35 = "Quente"
    | t < 45 = "Derretendo"
    | otherwise = "Ja era"

main :: IO()

main = do
        l <- getLine
        let x :: Integer
            x = read l
        let f = fat x
        let str = show f
        putStrLn str
        {-l <- getLine
        let t :: Integer
            t = read l
        putStrLn (tempo t)-}
