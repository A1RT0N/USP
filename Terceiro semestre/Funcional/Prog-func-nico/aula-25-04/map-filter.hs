-- essa função é o map, ou seja aplico uma função a cada elemento de um vetor
mapa :: (a -> b) -> [a] -> [b]
mapa _ [] = []
mapa f (x:xs) = f x : mapa f xs

-- essa função é um filter reverso, ou seja, se ele cumprir o critério, ele vai ignorar o elemento
filtro :: (a -> Bool) -> [a] -> [a]
filtro _ [] = []
filtro t (x:xs)
    | t x = x:c -- t x tem que ser bool porque guardas só usam bool
    | otherwise = c
    where
        c = filtro t xs

f :: (Num a) => [a] -> [a]
f = mapa (*10)

main = do
    putStrLn $ show $ mapa (\x -> x*x) [1..10]
    putStrLn $ show $ mapa (`mod` 5) [1..10] -- Usando infixo, consigo fazer aplicação parcial
    putStrLn $ show $ mapa (5 `mod`) [1..10] -- Consigo fazer na ordem contrária da aplicação parcial também
    putStrLn $ show $ mapa (*2) [1..10] -- * é infix por natureza, então sem necessidade de colocar parênteses
    putStrLn $ show $ filtro (\x -> x `mod` 3 == 0) [1..50]
    -- putStrLn $ show $ filtro (\x -> mod x 3 == 0) [1..50] -- Com as `` consigo usar funções como prefixo e infixo
    -- Como fazer a linha de cima sem lambda?
    putStrLn $ show $ filtro ((== 0).(`mod` 3)) [1..50] -- O '.' é uma composição de funções