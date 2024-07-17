-- Função  imprime a entrada, mas não imprime o valor total

-- imprimirJogadas :: [Int] -> IO()
-- imprimirJogadas () = return ()

-- -- Caso base em que a última jogada 
-- imprimirJogadas (x:y:[]) = putStr $ show x ++ " " ++ y ++ " | "
    
-- -- Caso base em que ou se deu spare ou foi strike
-- imprimirJogadas (x:y:z) = do
--     |   x == 10 = do
--         |   y == 10 && z == 10 = putStr " X X X | "
--         |   y == 10 && z != 10 = putStr " X X " ++ $ show z ++ " | "  
--         |   y+z == 10 = putStr " X " ++ $ show y ++ " / | "  
--         |   otherwise = putStr " X " ++ $ show y ++ " " ++ show z ++ " | "
    
--     -- Foi um spare, sendo que z pode ser 10 ou nao
--     |   otherwise = do
--         |   z == 10 = putStr $ show x  ++ " /" ++ " X | "
--         |   otherwise = putStr $ show x ++ " /" ++ show z ++ " "

-- imprimirJogadas (x:y:xs)  
--     |   x == 10 = putStr " X _ |": imprimirJogadas (y:xs)   
--     |   x + y == 10 = putStr $ show  x  ++ " / |" : imprimirJogadas (xs)  
--     |   otherwise = putStr $ show x ++ " " ++ show y ++ " |" : imprimirJogadas (xs) 





-- Função calcula_bonus
calculaBonus :: [Int] -> Bool -> Bool -> [Int]
calculaBonus listaBonus spare strike
    | not spare && not strike = if null listaBonus then [] else tail listaBonus
    | spare = [head listaTemp + 1]
    | otherwise = [head listaTemp + 1, 1]
    where
        listaTemp = 
            if null listaBonus || null (tail listaBonus) 
            then [0] 
            else tail listaBonus

-- Função bolichePontuacao
bolichePontuacao :: [Int] -> [Int] -> Int -> Int -> Int -> Int -> Int
bolichePontuacao [] _ _ _ _ valorTotal = valorTotal
bolichePontuacao jogadas bonusLista turnoAtual turnoAnterior pinosJogadaAnterior valorTotal =
    bolichePontuacao (tail jogadas) novaListaBonus novoTurno turnoAtual (head jogadas) novoValorTotal
    where
        novaListaBonus
            | turnoAtual >= 10 = calculaBonus bonusLista False False
            | turnoAtual == turnoAnterior =
                if pinosJogadaAnterior + head jogadas == 10
                    then calculaBonus bonusLista True False
                    else calculaBonus bonusLista False False
            | head jogadas == 10 = calculaBonus bonusLista False True
            | otherwise = calculaBonus bonusLista False False

        novoTurno
            | turnoAtual >= 10 = turnoAtual + 1
            | turnoAtual == turnoAnterior = turnoAtual + 1
            | otherwise =
                if head jogadas == 10
                    then turnoAtual + 1
                    else turnoAtual

        novoValorTotal
            | null bonusLista = valorTotal + head jogadas
            | otherwise = valorTotal + ((head bonusLista + 1) * head jogadas)

-- Função auxiliar calculaValor para calcular o valor total com os

-- Função para ler a entrada do usuário e converter para uma lista de inteiros
lerJogadas :: IO [Int]
lerJogadas = do
    input <- getLine
    let jogadas = map read (words input) :: [Int]
    return jogadas

-- Função  imprime a entrada, mas não imprime o valor total
    
imprimirJogadas :: [Int] -> IO()
imprimirJogadas [] = return ()
imprimirJogadas (x:y:[]) = putStr $ show x ++ " " ++ show y ++ " | "
imprimirJogadas (x:y:z:[]) 
    | x == 10 = do
        if y == 10 && z == 10 then putStr "X X X | "
        else if y == 10 then putStr $ "X X " ++ show z ++ " | "
        else if y + z == 10 then putStr $ "X " ++ show y ++ " / | "
        else putStr $ "X " ++ show y ++ " " ++ show z ++ " | "
    | x + y == 10 = do
        if z == 10 then putStr $ show x ++ " / X | "
        else putStr $ show x ++ " / " ++ show z ++ " | "

imprimirJogadas (x:y:xs)
    | x == 10 = do
        putStr "X _ | "
        imprimirJogadas (y:xs)
    | x + y == 10 = do
        putStr $ show x ++ " / | "
        imprimirJogadas xs
    | otherwise = do
        putStr $ show x ++ " " ++ show y ++ " | "
        imprimirJogadas xs

    

main :: IO ()
main = do
    jogadas <- lerJogadas
    let bonusLista = []
    let valorTotal = bolichePontuacao jogadas bonusLista 1 0 0 0
    imprimirJogadas jogadas
    print valorTotal
    
    
    
-- in: 1 4 4 5 6 4 5 5 10 0 1 7 3 6 4 10 2 8 6
-- 1 4 | 4 5 | 6 / | 5 / | X _ | 0 1 | 7 / | 6 / | X _ | 2 / 6 | 133
    
    
    
    