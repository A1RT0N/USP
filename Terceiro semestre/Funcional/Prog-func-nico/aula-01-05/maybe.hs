maximo :: (Ord a, Show a) => [a] -> Maybe a
maximo [] = Nothing
maximo [x] = Just x
maximo (x:xs) = case maximo xs of
    Nothing -> Just x
    Just y -> Just $ if x > y then x else y

x = x+1 -- Isso aqui é recursivo, assim isso gera infinito

maximoRadical [] = undefined -- isso aqui para o programa
maximoRadical [x] = x
maximoRadical (x:xs) = if x > y then x else y
    where
        y = maximoRadical xs

main = do
    putStrLn $ show $ maximo [1,8,4,6,0,199,6]
    putStrLn $ show $ maximo ([]::[Integer]) -- Garantir que o tipo da lista é Ord e Show