-- Vamos ver funções que podemos definir no "meio" - infixo (como $, +, -, :, ...)

concatInfix :: [a] -> [a] -> [a]
[] `concatInfix` l = l -- temos que colocar este aspas inverso
(x:xs) `concatInfix` l = x:(xs `concatInfix` l)

pertence :: (Eq a) => a -> [a] -> Bool
_ `pertence` [] = False
x `pertence` (y:ys)
    | x == y = True
    | otherwise = x `pertence` ys

{- Transformar algo infix para prefix:  
    x * x vira (*) x x
-}

main = do
    putStrLn $ show $ [1,2,3] `concatInfix` [4,5,6]
    print (1 `pertence` [1,2,3])