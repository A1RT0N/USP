conc :: [a] -> [a] -> [a]
conc [] l = l
conc (x:xs) l = x:(conc xs l)

main = do
    -- putStrLn (show (conc [2,3] [8,0])) -- Tem muito parênteses
    -- putStrLn $ show $ conc [2,3] $ [8,0] -- Funciona, pois conc [2,3] retorna uma função também
    putStrLn $ show $ conc [2,3] [8,0]